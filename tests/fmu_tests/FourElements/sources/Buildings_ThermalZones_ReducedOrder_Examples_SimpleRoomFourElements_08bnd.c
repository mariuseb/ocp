#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_08bnd.c"
#endif
/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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

void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 791
type: SIMPLE_ASSIGN
weaDat.lat = Buildings.BoundaryConditions.WeatherData.BaseClasses.getLatitudeTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos"))
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_791(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,791};
#line 228 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[428] /* weaDat.lat PARAM */) = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLatitudeTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT47));
#line 53 OMC_FILE
  TRACE_POP
}

/*
equation index: 792
type: SIMPLE_ASSIGN
weaDat.latitude.latitude = weaDat.lat
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_792(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,792};
#line 436 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */) = (data->simulationInfo->realParameter[428] /* weaDat.lat PARAM */);
#line 69 OMC_FILE
  TRACE_POP
}

/*
equation index: 793
type: SIMPLE_ASSIGN
$cse8 = cos(weaDat.latitude.latitude)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_793(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,793};
  (data->simulationInfo->realParameter[2] /* $cse8 PARAM */) = cos((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
  TRACE_POP
}

/*
equation index: 794
type: SIMPLE_ASSIGN
$cse11 = sin(weaDat.latitude.latitude)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_794(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,794};
  (data->simulationInfo->realParameter[0] /* $cse11 PARAM */) = sin((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
  TRACE_POP
}

/*
equation index: 795
type: SIMPLE_ASSIGN
weaDat.alt = Buildings.BoundaryConditions.WeatherData.BaseClasses.getAltitudeLocationTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos"))
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_795(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,795};
#line 234 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[402] /* weaDat.alt PARAM */) = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getAltitudeLocationTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT47));
#line 113 OMC_FILE
  TRACE_POP
}

/*
equation index: 796
type: SIMPLE_ASSIGN
weaDat.altitude.Altitude = weaDat.alt
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_796(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,796};
#line 524 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */) = (data->simulationInfo->realParameter[402] /* weaDat.alt PARAM */);
#line 129 OMC_FILE
  TRACE_POP
}

/*
equation index: 797
type: SIMPLE_ASSIGN
$cse14 = exp((-0.0001184) * weaDat.altitude.Altitude)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_797(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,797};
  (data->simulationInfo->realParameter[1] /* $cse14 PARAM */) = exp((-0.0001184) * ((data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */)));
  TRACE_POP
}

/*
equation index: 798
type: SIMPLE_ASSIGN
weaDat.datRea.tableID = Modelica.Blocks.Types.ExternalCombiTable1D.constructor("tab1", if OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos") <> "NoName" and not Modelica.Utilities.Strings.isEmpty(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos")) then OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos") else "NoName", {}, {2, 3, 4, 5, 6, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 8}, Modelica.Blocks.Types.Smoothness.ContinuousDerivative, Modelica.Blocks.Types.Extrapolation.LastTwoPoints, false)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_798(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,798};
#line 43 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->extObjs[1]) = omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData, _OMC_LIT48, (((!stringEqual(OpenModelica__fmuLoadResource(_OMC_LIT47), _OMC_LIT49)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, OpenModelica__fmuLoadResource(_OMC_LIT47))))?OpenModelica__fmuLoadResource(_OMC_LIT47):_OMC_LIT49), _OMC_LIT50, _OMC_LIT51, 2, 2, 0);
#line 159 OMC_FILE
  TRACE_POP
}

/*
equation index: 799
type: SIMPLE_ASSIGN
weaDat.datRea30Min.tableID = Modelica.Blocks.Types.ExternalCombiTable1D.constructor("tab1", if OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos") <> "NoName" and not Modelica.Utilities.Strings.isEmpty(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos")) then OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos") else "NoName", {}, {9, 10, 11}, Modelica.Blocks.Types.Smoothness.ContinuousDerivative, Modelica.Blocks.Types.Extrapolation.LastTwoPoints, false)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_799(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,799};
#line 43 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->extObjs[2]) = omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData, _OMC_LIT48, (((!stringEqual(OpenModelica__fmuLoadResource(_OMC_LIT47), _OMC_LIT49)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, OpenModelica__fmuLoadResource(_OMC_LIT47))))?OpenModelica__fmuLoadResource(_OMC_LIT47):_OMC_LIT49), _OMC_LIT50, _OMC_LIT52, 2, 2, 0);
#line 175 OMC_FILE
  TRACE_POP
}

/*
equation index: 800
type: SIMPLE_ASSIGN
intGai.tableID = Modelica.Blocks.Types.ExternalCombiTimeTable.constructor("NoName", "NoName", {{0.0, 0.0, 0.0, 0.0}, {3600.0, 0.0, 0.0, 0.0}, {7200.0, 0.0, 0.0, 0.0}, {10800.0, 0.0, 0.0, 0.0}, {14400.0, 0.0, 0.0, 0.0}, {18000.0, 0.0, 0.0, 0.0}, {21600.0, 0.0, 0.0, 0.0}, {25200.0, 0.0, 0.0, 0.0}, {25200.0, 80.0, 80.0, 200.0}, {28800.0, 80.0, 80.0, 200.0}, {32400.0, 80.0, 80.0, 200.0}, {36000.0, 80.0, 80.0, 200.0}, {39600.0, 80.0, 80.0, 200.0}, {43200.0, 80.0, 80.0, 200.0}, {46800.0, 80.0, 80.0, 200.0}, {50400.0, 80.0, 80.0, 200.0}, {54000.0, 80.0, 80.0, 200.0}, {57600.0, 80.0, 80.0, 200.0}, {61200.0, 80.0, 80.0, 200.0}, {61200.0, 0.0, 0.0, 0.0}, {64800.0, 0.0, 0.0, 0.0}, {72000.0, 0.0, 0.0, 0.0}, {75600.0, 0.0, 0.0, 0.0}, {79200.0, 0.0, 0.0, 0.0}, {82800.0, 0.0, 0.0, 0.0}, {86400.0, 0.0, 0.0, 0.0}}, 0.0, {2, 3, 4}, Modelica.Blocks.Types.Smoothness.LinearSegments, Modelica.Blocks.Types.Extrapolation.Periodic, 0.0, Modelica.Blocks.Types.TimeEvents.Always, false)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_800(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,800};
#line 1617 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->simulationInfo->extObjs[0]) = omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData, _OMC_LIT49, _OMC_LIT49, _OMC_LIT53, 0.0, _OMC_LIT54, 1, 3, 0.0, 1, 0);
#line 191 OMC_FILE
  TRACE_POP
}

/*
equation index: 801
type: SIMPLE_ASSIGN
weaDat.lon = Buildings.BoundaryConditions.WeatherData.BaseClasses.getLongitudeTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos"))
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_801(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,801};
#line 225 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[434] /* weaDat.lon PARAM */) = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLongitudeTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT47));
#line 207 OMC_FILE
  TRACE_POP
}

/*
equation index: 802
type: SIMPLE_ASSIGN
weaDat.longitude.longitude = weaDat.lon
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_802(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,802};
#line 480 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */) = (data->simulationInfo->realParameter[434] /* weaDat.lon PARAM */);
#line 223 OMC_FILE
  TRACE_POP
}

/*
equation index: 803
type: SIMPLE_ASSIGN
HDirTil[2].incAng.weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_803(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,803};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[58] /* HDirTil[2].incAng.weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 239 OMC_FILE
  TRACE_POP
}

/*
equation index: 804
type: SIMPLE_ASSIGN
HDirTil[2].weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_804(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,804};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[66] /* HDirTil[2].weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 255 OMC_FILE
  TRACE_POP
}

/*
equation index: 805
type: SIMPLE_ASSIGN
HDirTil[1].incAng.weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_805(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,805};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[57] /* HDirTil[1].incAng.weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 271 OMC_FILE
  TRACE_POP
}

/*
equation index: 806
type: SIMPLE_ASSIGN
HDirTil[1].weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_806(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,806};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[65] /* HDirTil[1].weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 287 OMC_FILE
  TRACE_POP
}

/*
equation index: 807
type: SIMPLE_ASSIGN
HDifTil[2].incAng.weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_807(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,807};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[28] /* HDifTil[2].incAng.weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 303 OMC_FILE
  TRACE_POP
}

/*
equation index: 808
type: SIMPLE_ASSIGN
HDifTil[2].weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_808(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,808};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[40] /* HDifTil[2].weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 319 OMC_FILE
  TRACE_POP
}

/*
equation index: 809
type: SIMPLE_ASSIGN
HDifTil[1].incAng.weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_809(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,809};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[27] /* HDifTil[1].incAng.weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 335 OMC_FILE
  TRACE_POP
}

/*
equation index: 810
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_810(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,810};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[39] /* HDifTil[1].weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 351 OMC_FILE
  TRACE_POP
}

/*
equation index: 811
type: SIMPLE_ASSIGN
weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_811(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,811};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[392] /* weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 367 OMC_FILE
  TRACE_POP
}

/*
equation index: 812
type: SIMPLE_ASSIGN
weaDat.weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_812(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,812};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[450] /* weaDat.weaBus.lon PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 383 OMC_FILE
  TRACE_POP
}

/*
equation index: 813
type: SIMPLE_ASSIGN
weaDat.longitude.y = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_813(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,813};
#line 482 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[436] /* weaDat.longitude.y PARAM */) = (data->simulationInfo->realParameter[435] /* weaDat.longitude.longitude PARAM */);
#line 399 OMC_FILE
  TRACE_POP
}

/*
equation index: 814
type: SIMPLE_ASSIGN
HDirTil[2].incAng.incAng.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_814(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,814};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->simulationInfo->realParameter[48] /* HDirTil[2].incAng.incAng.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 415 OMC_FILE
  TRACE_POP
}

/*
equation index: 815
type: SIMPLE_ASSIGN
HDirTil[2].incAng.weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_815(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,815};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[56] /* HDirTil[2].incAng.weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 431 OMC_FILE
  TRACE_POP
}

/*
equation index: 816
type: SIMPLE_ASSIGN
HDirTil[2].weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_816(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,816};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[64] /* HDirTil[2].weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 447 OMC_FILE
  TRACE_POP
}

/*
equation index: 817
type: SIMPLE_ASSIGN
HDirTil[1].incAng.incAng.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_817(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,817};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->simulationInfo->realParameter[47] /* HDirTil[1].incAng.incAng.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 463 OMC_FILE
  TRACE_POP
}

/*
equation index: 818
type: SIMPLE_ASSIGN
HDirTil[1].incAng.weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_818(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,818};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[55] /* HDirTil[1].incAng.weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 479 OMC_FILE
  TRACE_POP
}

/*
equation index: 819
type: SIMPLE_ASSIGN
HDirTil[1].weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_819(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,819};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[63] /* HDirTil[1].weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 495 OMC_FILE
  TRACE_POP
}

/*
equation index: 820
type: SIMPLE_ASSIGN
HDifTil[2].incAng.incAng.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_820(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,820};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->simulationInfo->realParameter[18] /* HDifTil[2].incAng.incAng.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 511 OMC_FILE
  TRACE_POP
}

/*
equation index: 821
type: SIMPLE_ASSIGN
HDifTil[2].incAng.weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_821(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,821};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[26] /* HDifTil[2].incAng.weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 527 OMC_FILE
  TRACE_POP
}

/*
equation index: 822
type: SIMPLE_ASSIGN
HDifTil[2].weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_822(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,822};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[38] /* HDifTil[2].weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 543 OMC_FILE
  TRACE_POP
}

/*
equation index: 823
type: SIMPLE_ASSIGN
HDifTil[1].incAng.incAng.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_823(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,823};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->simulationInfo->realParameter[17] /* HDifTil[1].incAng.incAng.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 559 OMC_FILE
  TRACE_POP
}

/*
equation index: 824
type: SIMPLE_ASSIGN
HDifTil[1].incAng.weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_824(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,824};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[25] /* HDifTil[1].incAng.weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 575 OMC_FILE
  TRACE_POP
}

/*
equation index: 825
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_825(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,825};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[37] /* HDifTil[1].weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 591 OMC_FILE
  TRACE_POP
}

/*
equation index: 826
type: SIMPLE_ASSIGN
weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_826(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,826};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[391] /* weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 607 OMC_FILE
  TRACE_POP
}

/*
equation index: 827
type: SIMPLE_ASSIGN
weaDat.weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_827(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,827};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[449] /* weaDat.weaBus.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 623 OMC_FILE
  TRACE_POP
}

/*
equation index: 828
type: SIMPLE_ASSIGN
weaDat.zenAng.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_828(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,828};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  (data->simulationInfo->realParameter[455] /* weaDat.zenAng.lat PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 639 OMC_FILE
  TRACE_POP
}

/*
equation index: 829
type: SIMPLE_ASSIGN
weaDat.latitude.y = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_829(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,829};
#line 438 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[430] /* weaDat.latitude.y PARAM */) = (data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */);
#line 655 OMC_FILE
  TRACE_POP
}

/*
equation index: 830
type: SIMPLE_ASSIGN
HDirTil[2].incAng.weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_830(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,830};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[54] /* HDirTil[2].incAng.weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 671 OMC_FILE
  TRACE_POP
}

/*
equation index: 831
type: SIMPLE_ASSIGN
HDirTil[2].weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_831(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,831};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[62] /* HDirTil[2].weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 687 OMC_FILE
  TRACE_POP
}

/*
equation index: 832
type: SIMPLE_ASSIGN
HDirTil[1].incAng.weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_832(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,832};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[53] /* HDirTil[1].incAng.weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 703 OMC_FILE
  TRACE_POP
}

/*
equation index: 833
type: SIMPLE_ASSIGN
HDirTil[1].weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_833(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,833};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[61] /* HDirTil[1].weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 719 OMC_FILE
  TRACE_POP
}

/*
equation index: 834
type: SIMPLE_ASSIGN
HDifTil[2].incAng.weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_834(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,834};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[24] /* HDifTil[2].incAng.weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 735 OMC_FILE
  TRACE_POP
}

/*
equation index: 835
type: SIMPLE_ASSIGN
HDifTil[2].relAirMas.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_835(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,835};
#line 4 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->simulationInfo->realParameter[30] /* HDifTil[2].relAirMas.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 751 OMC_FILE
  TRACE_POP
}

/*
equation index: 836
type: SIMPLE_ASSIGN
HDifTil[2].weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_836(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,836};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[36] /* HDifTil[2].weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 767 OMC_FILE
  TRACE_POP
}

/*
equation index: 837
type: SIMPLE_ASSIGN
HDifTil[1].incAng.weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_837(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,837};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[23] /* HDifTil[1].incAng.weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 783 OMC_FILE
  TRACE_POP
}

/*
equation index: 838
type: SIMPLE_ASSIGN
HDifTil[1].relAirMas.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_838(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,838};
#line 4 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->simulationInfo->realParameter[29] /* HDifTil[1].relAirMas.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 799 OMC_FILE
  TRACE_POP
}

/*
equation index: 839
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_839(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,839};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[35] /* HDifTil[1].weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 815 OMC_FILE
  TRACE_POP
}

/*
equation index: 840
type: SIMPLE_ASSIGN
weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_840(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,840};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[390] /* weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 831 OMC_FILE
  TRACE_POP
}

/*
equation index: 841
type: SIMPLE_ASSIGN
weaDat.weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_841(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,841};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[448] /* weaDat.weaBus.alt PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 847 OMC_FILE
  TRACE_POP
}

/*
equation index: 842
type: SIMPLE_ASSIGN
weaDat.altitude.y = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_842(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,842};
#line 527 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[404] /* weaDat.altitude.y PARAM */) = (data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */);
#line 863 OMC_FILE
  TRACE_POP
}

/*
equation index: 864
type: SIMPLE_ASSIGN
intGai.t_maxScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmax(intGai.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_864(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,864};
#line 1612 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->simulationInfo->realParameter[121] /* intGai.t_maxScaled PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData, (data->simulationInfo->extObjs[0]));
#line 879 OMC_FILE
  TRACE_POP
}

/*
equation index: 865
type: SIMPLE_ASSIGN
intGai.t_minScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmin(intGai.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_865(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,865};
#line 1610 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->simulationInfo->realParameter[123] /* intGai.t_minScaled PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData, (data->simulationInfo->extObjs[0]));
#line 895 OMC_FILE
  TRACE_POP
}

/*
equation index: 866
type: SIMPLE_ASSIGN
intGai.t_max = intGai.t_maxScaled
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_866(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,866};
#line 1608 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->simulationInfo->realParameter[120] /* intGai.t_max PARAM */) = (data->simulationInfo->realParameter[121] /* intGai.t_maxScaled PARAM */);
#line 911 OMC_FILE
  TRACE_POP
}

/*
equation index: 867
type: SIMPLE_ASSIGN
intGai.t_min = intGai.t_minScaled
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_867(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,867};
#line 1606 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->simulationInfo->realParameter[122] /* intGai.t_min PARAM */) = (data->simulationInfo->realParameter[123] /* intGai.t_minScaled PARAM */);
#line 927 OMC_FILE
  TRACE_POP
}

/*
equation index: 880
type: SIMPLE_ASSIGN
intGai.fileName = "NoName"
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_880(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,880};
#line 1570 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->simulationInfo->stringParameter[0] /* intGai.fileName PARAM */) = _OMC_LIT49;
#line 943 OMC_FILE
  TRACE_POP
}

/*
equation index: 881
type: SIMPLE_ASSIGN
intGai.tableName = "NoName"
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_881(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,881};
#line 1567 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->simulationInfo->stringParameter[1] /* intGai.tableName PARAM */) = _OMC_LIT49;
#line 959 OMC_FILE
  TRACE_POP
}

/*
equation index: 1275
type: SIMPLE_ASSIGN
weaDat.timeSpan[1] = Buildings.BoundaryConditions.WeatherData.BaseClasses.getTimeSpanTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos"), "tab1")[1]
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1275};
#line 239 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[444] /* weaDat.timeSpan[1] PARAM */) = real_get(omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeSpanTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT47), _OMC_LIT48), 0);
#line 975 OMC_FILE
  TRACE_POP
}

/*
equation index: 1276
type: SIMPLE_ASSIGN
weaDat.conTim.weaDatStaTim = weaDat.timeSpan[1]
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1276};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[418] /* weaDat.conTim.weaDatStaTim PARAM */) = (data->simulationInfo->realParameter[444] /* weaDat.timeSpan[1] PARAM */);
#line 991 OMC_FILE
  TRACE_POP
}

/*
equation index: 1277
type: SIMPLE_ASSIGN
weaDat.timeSpan[2] = Buildings.BoundaryConditions.WeatherData.BaseClasses.getTimeSpanTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos"), "tab1")[2]
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1277};
#line 239 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[445] /* weaDat.timeSpan[2] PARAM */) = real_get(omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeSpanTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT47), _OMC_LIT48), 1);
#line 1007 OMC_FILE
  TRACE_POP
}

/*
equation index: 1278
type: SIMPLE_ASSIGN
weaDat.conTim.weaDatEndTim = weaDat.timeSpan[2]
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1278};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[417] /* weaDat.conTim.weaDatEndTim PARAM */) = (data->simulationInfo->realParameter[445] /* weaDat.timeSpan[2] PARAM */);
#line 1023 OMC_FILE
  TRACE_POP
}

/*
equation index: 1279
type: SIMPLE_ASSIGN
weaDat.conTim.lenWea = weaDat.conTim.weaDatEndTim - weaDat.conTim.weaDatStaTim
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1279};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[416] /* weaDat.conTim.lenWea PARAM */) = (data->simulationInfo->realParameter[417] /* weaDat.conTim.weaDatEndTim PARAM */) - (data->simulationInfo->realParameter[418] /* weaDat.conTim.weaDatStaTim PARAM */);
#line 1039 OMC_FILE
  TRACE_POP
}

/*
equation index: 1280
type: SIMPLE_ASSIGN
weaDat.conTim.canRepeatWeatherFile = abs(mod(weaDat.conTim.lenWea, 31536000.0)) < 0.01
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1280};
  modelica_real tmp2;
  modelica_boolean tmp3;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp2 = 31536000.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(weaDat.conTim.lenWea, 31536000.0)");}
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp3 = Less(fabs(modelica_real_mod((data->simulationInfo->realParameter[416] /* weaDat.conTim.lenWea PARAM */), tmp2)),0.01);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */) = tmp3;
#line 1063 OMC_FILE
  TRACE_POP
}

/*
equation index: 1281
type: SIMPLE_ASSIGN
weaDat.conTimMin.weaDatStaTim = weaDat.timeSpan[1]
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1281};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[421] /* weaDat.conTimMin.weaDatStaTim PARAM */) = (data->simulationInfo->realParameter[444] /* weaDat.timeSpan[1] PARAM */);
#line 1079 OMC_FILE
  TRACE_POP
}

/*
equation index: 1282
type: SIMPLE_ASSIGN
weaDat.conTimMin.weaDatEndTim = weaDat.timeSpan[2]
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1282};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[420] /* weaDat.conTimMin.weaDatEndTim PARAM */) = (data->simulationInfo->realParameter[445] /* weaDat.timeSpan[2] PARAM */);
#line 1095 OMC_FILE
  TRACE_POP
}

/*
equation index: 1283
type: SIMPLE_ASSIGN
weaDat.conTimMin.lenWea = weaDat.conTimMin.weaDatEndTim - weaDat.conTimMin.weaDatStaTim
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1283};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[419] /* weaDat.conTimMin.lenWea PARAM */) = (data->simulationInfo->realParameter[420] /* weaDat.conTimMin.weaDatEndTim PARAM */) - (data->simulationInfo->realParameter[421] /* weaDat.conTimMin.weaDatStaTim PARAM */);
#line 1111 OMC_FILE
  TRACE_POP
}

/*
equation index: 1284
type: SIMPLE_ASSIGN
weaDat.conTimMin.canRepeatWeatherFile = abs(mod(weaDat.conTimMin.lenWea, 31536000.0)) < 0.01
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1284};
  modelica_real tmp4;
  modelica_boolean tmp5;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp4 = 31536000.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(weaDat.conTimMin.lenWea, 31536000.0)");}
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp5 = Less(fabs(modelica_real_mod((data->simulationInfo->realParameter[419] /* weaDat.conTimMin.lenWea PARAM */), tmp4)),0.01);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) = tmp5;
#line 1135 OMC_FILE
  TRACE_POP
}

/*
equation index: 1285
type: SIMPLE_ASSIGN
weaDat.datRea30Min.u_max = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmax(weaDat.datRea30Min.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1285};
#line 40 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->realParameter[425] /* weaDat.datRea30Min.u_max PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData, (data->simulationInfo->extObjs[2]));
#line 1151 OMC_FILE
  TRACE_POP
}

/*
equation index: 1286
type: SIMPLE_ASSIGN
weaDat.datRea30Min.u_min = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmin(weaDat.datRea30Min.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1286};
#line 38 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->realParameter[426] /* weaDat.datRea30Min.u_min PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData, (data->simulationInfo->extObjs[2]));
#line 1167 OMC_FILE
  TRACE_POP
}

/*
equation index: 1294
type: SIMPLE_ASSIGN
weaDat.datRea30Min.fileName = OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos")
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1294};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->stringParameter[4] /* weaDat.datRea30Min.fileName PARAM */) = OpenModelica__fmuLoadResource(_OMC_LIT47);
#line 1183 OMC_FILE
  TRACE_POP
}

/*
equation index: 1295
type: SIMPLE_ASSIGN
weaDat.datRea30Min.tableName = "tab1"
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1295};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->stringParameter[5] /* weaDat.datRea30Min.tableName PARAM */) = _OMC_LIT48;
#line 1199 OMC_FILE
  TRACE_POP
}

/*
equation index: 1298
type: SIMPLE_ASSIGN
weaDat.timZon = Buildings.BoundaryConditions.WeatherData.BaseClasses.getTimeZoneTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos"))
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1298};
#line 231 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[443] /* weaDat.timZon PARAM */) = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeZoneTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT47));
#line 1215 OMC_FILE
  TRACE_POP
}

/*
equation index: 1299
type: SIMPLE_ASSIGN
weaDat.locTim.timZon = weaDat.timZon
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1299};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LocalCivilTime.mo"
  (data->simulationInfo->realParameter[433] /* weaDat.locTim.timZon PARAM */) = (data->simulationInfo->realParameter[443] /* weaDat.timZon PARAM */);
#line 1231 OMC_FILE
  TRACE_POP
}

/*
equation index: 1300
type: SIMPLE_ASSIGN
weaDat.locTim.lon = weaDat.lon
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1300};
#line 9 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LocalCivilTime.mo"
  (data->simulationInfo->realParameter[432] /* weaDat.locTim.lon PARAM */) = (data->simulationInfo->realParameter[434] /* weaDat.lon PARAM */);
#line 1247 OMC_FILE
  TRACE_POP
}

/*
equation index: 1301
type: SIMPLE_ASSIGN
weaDat.locTim.diff = 13750.98708313976 * weaDat.locTim.lon - weaDat.locTim.timZon
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1301};
#line 15 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LocalCivilTime.mo"
  (data->simulationInfo->realParameter[431] /* weaDat.locTim.diff PARAM */) = (13750.98708313976) * ((data->simulationInfo->realParameter[432] /* weaDat.locTim.lon PARAM */)) - (data->simulationInfo->realParameter[433] /* weaDat.locTim.timZon PARAM */);
#line 1263 OMC_FILE
  TRACE_POP
}

/*
equation index: 1334
type: SIMPLE_ASSIGN
weaDat.datRea.u_max = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmax(weaDat.datRea.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1334};
#line 40 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->realParameter[423] /* weaDat.datRea.u_max PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData, (data->simulationInfo->extObjs[1]));
#line 1279 OMC_FILE
  TRACE_POP
}

/*
equation index: 1335
type: SIMPLE_ASSIGN
weaDat.datRea.u_min = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmin(weaDat.datRea.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1335};
#line 38 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->realParameter[424] /* weaDat.datRea.u_min PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData, (data->simulationInfo->extObjs[1]));
#line 1295 OMC_FILE
  TRACE_POP
}

/*
equation index: 1366
type: SIMPLE_ASSIGN
weaDat.datRea.fileName = OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos")
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1366(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1366};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->stringParameter[2] /* weaDat.datRea.fileName PARAM */) = OpenModelica__fmuLoadResource(_OMC_LIT47);
#line 1311 OMC_FILE
  TRACE_POP
}

/*
equation index: 1367
type: SIMPLE_ASSIGN
weaDat.datRea.tableName = "tab1"
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1367(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1367};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->stringParameter[3] /* weaDat.datRea.tableName PARAM */) = _OMC_LIT48;
#line 1327 OMC_FILE
  TRACE_POP
}

/*
equation index: 1395
type: SIMPLE_ASSIGN
weaDat.filNam = OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_CA_San.Francisco.Intl.AP.724940_TMY3.mos")
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1395};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->stringParameter[6] /* weaDat.filNam PARAM */) = OpenModelica__fmuLoadResource(_OMC_LIT47);
#line 1343 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_402(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_401(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_400(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_399(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_398(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_397(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_396(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_395(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_394(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_393(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_392(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_391(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_390(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_389(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_388(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_387(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_386(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_385(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_384(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_383(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_382(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_381(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_14(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_13(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_12(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_11(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_10(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_9(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_8(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_7(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_6(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_5(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_4(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_3(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1(DATA *data, threadData_t *threadData);


/*
equation index: 1432
type: ALGORITHM

  assert(eqAirTempVDI.TGro >= 0.0, "Variable violating min constraint: 0.0 <= eqAirTempVDI.TGro, has value: " + String(eqAirTempVDI.TGro, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1432};
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,72,"Variable violating min constraint: 0.0 <= eqAirTempVDI.TGro, has value: ");
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static int tmp10 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  if(!tmp10)
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    tmp6 = GreaterEq((data->simulationInfo->realParameter[104] /* eqAirTempVDI.TGro PARAM */),0.0);
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    if(!tmp6)
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp8 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[104] /* eqAirTempVDI.TGro PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmpMeta9 = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        const char* assert_cond = "(eqAirTempVDI.TGro >= 0.0)";
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",12,3,13,60,0};
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",12,3,13,60,0};
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp10 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  }
#line 1475 OMC_FILE
  TRACE_POP
}

/*
equation index: 1433
type: ALGORITHM

  assert(macConv.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= macConv.T_ref, has value: " + String(macConv.T_ref, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1433};
  modelica_boolean tmp11;
  static const MMC_DEFSTRINGLIT(tmp12,68,"Variable violating min constraint: 0.0 <= macConv.T_ref, has value: ");
  modelica_string tmp13;
  modelica_metatype tmpMeta14;
  static int tmp15 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  if(!tmp15)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    tmp11 = GreaterEq((data->simulationInfo->realParameter[229] /* macConv.T_ref PARAM */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    if(!tmp11)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp13 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[229] /* macConv.T_ref PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmpMeta14 = stringAppend(MMC_REFSTRINGLIT(tmp12),tmp13);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        const char* assert_cond = "(macConv.T_ref >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp15 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  }
#line 1535 OMC_FILE
  TRACE_POP
}

/*
equation index: 1434
type: ALGORITHM

  assert(intGai.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and intGai.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, "Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= intGai.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: " + String(intGai.timeEvents, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1434};
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  static const MMC_DEFSTRINGLIT(tmp18,161,"Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= intGai.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: ");
  modelica_string tmp19;
  modelica_metatype tmpMeta20;
  static int tmp21 = 0;
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  if(!tmp21)
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  {
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp16 = GreaterEq((data->simulationInfo->integerParameter[9] /* intGai.timeEvents PARAM */),1);
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp17 = LessEq((data->simulationInfo->integerParameter[9] /* intGai.timeEvents PARAM */),3);
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    if(!(tmp16 && tmp17))
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    {
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp19 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[9] /* intGai.timeEvents PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmpMeta20 = stringAppend(MMC_REFSTRINGLIT(tmp18),tmp19);
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      {
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        const char* assert_cond = "(intGai.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and intGai.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents)";
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1600,5,1602,131,0};
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta20));
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        } else {
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1600,5,1602,131,0};
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta20));
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        }
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      }
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp21 = 1;
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    }
#line 1600 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  }
#line 1598 OMC_FILE
  TRACE_POP
}

/*
equation index: 1435
type: ALGORITHM

  assert(intGai.timeScale >= 1e-15, "Variable violating min constraint: 1e-15 <= intGai.timeScale, has value: " + String(intGai.timeScale, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1435};
  modelica_boolean tmp22;
  static const MMC_DEFSTRINGLIT(tmp23,73,"Variable violating min constraint: 1e-15 <= intGai.timeScale, has value: ");
  modelica_string tmp24;
  modelica_metatype tmpMeta25;
  static int tmp26 = 0;
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  if(!tmp26)
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  {
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp22 = GreaterEq((data->simulationInfo->realParameter[228] /* intGai.timeScale PARAM */),1e-15);
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    if(!tmp22)
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    {
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp24 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[228] /* intGai.timeScale PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmpMeta25 = stringAppend(MMC_REFSTRINGLIT(tmp23),tmp24);
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      {
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        const char* assert_cond = "(intGai.timeScale >= 1e-15)";
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1589,5,1591,76,0};
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta25));
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        } else {
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1589,5,1591,76,0};
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta25));
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        }
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      }
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp26 = 1;
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    }
#line 1589 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  }
#line 1658 OMC_FILE
  TRACE_POP
}

/*
equation index: 1436
type: ALGORITHM

  assert(intGai.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and intGai.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= intGai.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(intGai.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1436(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1436};
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  static const MMC_DEFSTRINGLIT(tmp29,180,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= intGai.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp30;
  modelica_metatype tmpMeta31;
  static int tmp32 = 0;
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  if(!tmp32)
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  {
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp27 = GreaterEq((data->simulationInfo->integerParameter[6] /* intGai.extrapolation PARAM */),1);
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp28 = LessEq((data->simulationInfo->integerParameter[6] /* intGai.extrapolation PARAM */),4);
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    if(!(tmp27 && tmp28))
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    {
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp30 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[6] /* intGai.extrapolation PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmpMeta31 = stringAppend(MMC_REFSTRINGLIT(tmp29),tmp30);
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      {
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        const char* assert_cond = "(intGai.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and intGai.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation)";
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1586,5,1588,61,0};
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta31));
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        } else {
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1586,5,1588,61,0};
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta31));
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        }
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      }
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp32 = 1;
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    }
#line 1586 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  }
#line 1721 OMC_FILE
  TRACE_POP
}

/*
equation index: 1437
type: ALGORITHM

  assert(intGai.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and intGai.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= intGai.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: " + String(intGai.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1437(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1437};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  static const MMC_DEFSTRINGLIT(tmp35,185,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= intGai.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: ");
  modelica_string tmp36;
  modelica_metatype tmpMeta37;
  static int tmp38 = 0;
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  if(!tmp38)
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  {
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp33 = GreaterEq((data->simulationInfo->integerParameter[8] /* intGai.smoothness PARAM */),1);
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp34 = LessEq((data->simulationInfo->integerParameter[8] /* intGai.smoothness PARAM */),6);
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    if(!(tmp33 && tmp34))
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    {
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp36 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[8] /* intGai.smoothness PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmpMeta37 = stringAppend(MMC_REFSTRINGLIT(tmp35),tmp36);
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      {
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        const char* assert_cond = "(intGai.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and intGai.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative)";
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1583,5,1585,61,0};
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta37));
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        } else {
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1583,5,1585,61,0};
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta37));
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        }
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      }
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp38 = 1;
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    }
#line 1583 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  }
#line 1784 OMC_FILE
  TRACE_POP
}

/*
equation index: 1438
type: ALGORITHM

  assert(intGai.nout >= 1, "Variable violating min constraint: 1 <= intGai.nout, has value: " + String(intGai.nout, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1438(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1438};
  modelica_boolean tmp39;
  static const MMC_DEFSTRINGLIT(tmp40,64,"Variable violating min constraint: 1 <= intGai.nout, has value: ");
  modelica_string tmp41;
  modelica_metatype tmpMeta42;
  static int tmp43 = 0;
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  if(!tmp43)
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  {
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    tmp39 = GreaterEq((data->simulationInfo->integerParameter[7] /* intGai.nout PARAM */),((modelica_integer) 1));
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    if(!tmp39)
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    {
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmp41 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[7] /* intGai.nout PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmpMeta42 = stringAppend(MMC_REFSTRINGLIT(tmp40),tmp41);
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      {
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        const char* assert_cond = "(intGai.nout >= 1)";
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo",313,5,313,58,0};
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta42));
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        } else {
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo",313,5,313,58,0};
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta42));
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        }
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      }
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmp43 = 1;
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    }
#line 313 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  }
#line 1844 OMC_FILE
  TRACE_POP
}

/*
equation index: 1439
type: ALGORITHM

  assert(perCon.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= perCon.T_ref, has value: " + String(perCon.T_ref, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1439(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1439};
  modelica_boolean tmp44;
  static const MMC_DEFSTRINGLIT(tmp45,67,"Variable violating min constraint: 0.0 <= perCon.T_ref, has value: ");
  modelica_string tmp46;
  modelica_metatype tmpMeta47;
  static int tmp48 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  if(!tmp48)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    tmp44 = GreaterEq((data->simulationInfo->realParameter[231] /* perCon.T_ref PARAM */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    if(!tmp44)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp46 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[231] /* perCon.T_ref PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmpMeta47 = stringAppend(MMC_REFSTRINGLIT(tmp45),tmp46);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        const char* assert_cond = "(perCon.T_ref >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta47));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta47));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp48 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  }
#line 1904 OMC_FILE
  TRACE_POP
}

/*
equation index: 1440
type: ALGORITHM

  assert(perRad.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= perRad.T_ref, has value: " + String(perRad.T_ref, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1440(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1440};
  modelica_boolean tmp49;
  static const MMC_DEFSTRINGLIT(tmp50,67,"Variable violating min constraint: 0.0 <= perRad.T_ref, has value: ");
  modelica_string tmp51;
  modelica_metatype tmpMeta52;
  static int tmp53 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  if(!tmp53)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    tmp49 = GreaterEq((data->simulationInfo->realParameter[233] /* perRad.T_ref PARAM */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    if(!tmp49)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp51 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[233] /* perRad.T_ref PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmpMeta52 = stringAppend(MMC_REFSTRINGLIT(tmp50),tmp51);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        const char* assert_cond = "(perRad.T_ref >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp53 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  }
#line 1964 OMC_FILE
  TRACE_POP
}

/*
equation index: 1441
type: ALGORITHM

  assert(eqAirTemp.TGro >= 0.0, "Variable violating min constraint: 0.0 <= eqAirTemp.TGro, has value: " + String(eqAirTemp.TGro, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1441(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1441};
  modelica_boolean tmp54;
  static const MMC_DEFSTRINGLIT(tmp55,69,"Variable violating min constraint: 0.0 <= eqAirTemp.TGro, has value: ");
  modelica_string tmp56;
  modelica_metatype tmpMeta57;
  static int tmp58 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  if(!tmp58)
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    tmp54 = GreaterEq((data->simulationInfo->realParameter[94] /* eqAirTemp.TGro PARAM */),0.0);
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    if(!tmp54)
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp56 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[94] /* eqAirTemp.TGro PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmpMeta57 = stringAppend(MMC_REFSTRINGLIT(tmp55),tmp56);
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        const char* assert_cond = "(eqAirTemp.TGro >= 0.0)";
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",12,3,13,60,0};
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta57));
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",12,3,13,60,0};
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta57));
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp58 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  }
#line 2024 OMC_FILE
  TRACE_POP
}

/*
equation index: 1442
type: ALGORITHM

  assert(thermalZoneFourElements.roofRC.T_start >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.roofRC.T_start, has value: " + String(thermalZoneFourElements.roofRC.T_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1442(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1442};
  modelica_boolean tmp59;
  static const MMC_DEFSTRINGLIT(tmp60,93,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.roofRC.T_start, has value: ");
  modelica_string tmp61;
  modelica_metatype tmpMeta62;
  static int tmp63 = 0;
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp63)
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp59 = GreaterEq((data->simulationInfo->realParameter[329] /* thermalZoneFourElements.roofRC.T_start PARAM */),0.0);
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp59)
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp61 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[329] /* thermalZoneFourElements.roofRC.T_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta62 = stringAppend(MMC_REFSTRINGLIT(tmp60),tmp61);
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.roofRC.T_start >= 0.0)";
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",14,3,16,46,0};
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta62));
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",14,3,16,46,0};
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta62));
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp63 = 1;
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2084 OMC_FILE
  TRACE_POP
}

/*
equation index: 1443
type: ALGORITHM

  assert(thermalZoneFourElements.roofRC.CExt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.roofRC.CExt[1], has value: " + String(thermalZoneFourElements.roofRC.CExt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1443(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1443};
  modelica_boolean tmp64;
  static const MMC_DEFSTRINGLIT(tmp65,95,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.roofRC.CExt[1], has value: ");
  modelica_string tmp66;
  modelica_metatype tmpMeta67;
  static int tmp68 = 0;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp68)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp64 = GreaterEq((data->simulationInfo->realParameter[326] /* thermalZoneFourElements.roofRC.CExt[1] PARAM */),1e-60);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp64)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp66 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[326] /* thermalZoneFourElements.roofRC.CExt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta67 = stringAppend(MMC_REFSTRINGLIT(tmp65),tmp66);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.roofRC.CExt[1] >= 1e-60)";
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",11,3,13,46,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta67));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",11,3,13,46,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta67));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp68 = 1;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2144 OMC_FILE
  TRACE_POP
}

/*
equation index: 1444
type: ALGORITHM

  assert(thermalZoneFourElements.roofRC.RExtRem >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.roofRC.RExtRem, has value: " + String(thermalZoneFourElements.roofRC.RExtRem, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1444(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1444};
  modelica_boolean tmp69;
  static const MMC_DEFSTRINGLIT(tmp70,95,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.roofRC.RExtRem, has value: ");
  modelica_string tmp71;
  modelica_metatype tmpMeta72;
  static int tmp73 = 0;
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp73)
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp69 = GreaterEq((data->simulationInfo->realParameter[328] /* thermalZoneFourElements.roofRC.RExtRem PARAM */),1e-60);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp69)
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp71 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[328] /* thermalZoneFourElements.roofRC.RExtRem PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta72 = stringAppend(MMC_REFSTRINGLIT(tmp70),tmp71);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.roofRC.RExtRem >= 1e-60)";
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",8,3,10,46,0};
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta72));
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",8,3,10,46,0};
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta72));
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp73 = 1;
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2204 OMC_FILE
  TRACE_POP
}

/*
equation index: 1445
type: ALGORITHM

  assert(thermalZoneFourElements.roofRC.RExt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.roofRC.RExt[1], has value: " + String(thermalZoneFourElements.roofRC.RExt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1445(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1445};
  modelica_boolean tmp74;
  static const MMC_DEFSTRINGLIT(tmp75,95,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.roofRC.RExt[1], has value: ");
  modelica_string tmp76;
  modelica_metatype tmpMeta77;
  static int tmp78 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp78)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp74 = GreaterEq((data->simulationInfo->realParameter[327] /* thermalZoneFourElements.roofRC.RExt[1] PARAM */),1e-60);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp74)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp76 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[327] /* thermalZoneFourElements.roofRC.RExt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta77 = stringAppend(MMC_REFSTRINGLIT(tmp75),tmp76);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.roofRC.RExt[1] >= 1e-60)";
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",5,3,7,46,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta77));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",5,3,7,46,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta77));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp78 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2264 OMC_FILE
  TRACE_POP
}

/*
equation index: 1446
type: ALGORITHM

  assert(thermalZoneFourElements.roofRC.n >= 1, "Variable violating min constraint: 1 <= thermalZoneFourElements.roofRC.n, has value: " + String(thermalZoneFourElements.roofRC.n, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1446(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1446};
  modelica_boolean tmp79;
  static const MMC_DEFSTRINGLIT(tmp80,85,"Variable violating min constraint: 1 <= thermalZoneFourElements.roofRC.n, has value: ");
  modelica_string tmp81;
  modelica_metatype tmpMeta82;
  static int tmp83 = 0;
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp83)
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp79 = GreaterEq((data->simulationInfo->integerParameter[22] /* thermalZoneFourElements.roofRC.n PARAM */),((modelica_integer) 1));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp79)
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp81 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[22] /* thermalZoneFourElements.roofRC.n PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta82 = stringAppend(MMC_REFSTRINGLIT(tmp80),tmp81);
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.roofRC.n >= 1)";
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",4,3,4,55,0};
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta82));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",4,3,4,55,0};
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta82));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp83 = 1;
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2324 OMC_FILE
  TRACE_POP
}

/*
equation index: 1447
type: ALGORITHM

  assert(thermalZoneFourElements.CRoof[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.CRoof[1], has value: " + String(thermalZoneFourElements.CRoof[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1447(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1447};
  modelica_boolean tmp84;
  static const MMC_DEFSTRINGLIT(tmp85,89,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.CRoof[1], has value: ");
  modelica_string tmp86;
  modelica_metatype tmpMeta87;
  static int tmp88 = 0;
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  if(!tmp88)
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  {
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    tmp84 = GreaterEq((data->simulationInfo->realParameter[259] /* thermalZoneFourElements.CRoof[1] PARAM */),1e-60);
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    if(!tmp84)
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    {
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmp86 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[259] /* thermalZoneFourElements.CRoof[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmpMeta87 = stringAppend(MMC_REFSTRINGLIT(tmp85),tmp86);
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      {
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.CRoof[1] >= 1e-60)";
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo",19,3,21,38,0};
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta87));
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        } else {
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo",19,3,21,38,0};
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta87));
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        }
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      }
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmp88 = 1;
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    }
#line 19 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  }
#line 2384 OMC_FILE
  TRACE_POP
}

/*
equation index: 1448
type: ALGORITHM

  assert(thermalZoneFourElements.RRoofRem >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RRoofRem, has value: " + String(thermalZoneFourElements.RRoofRem, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1448(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1448};
  modelica_boolean tmp89;
  static const MMC_DEFSTRINGLIT(tmp90,89,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RRoofRem, has value: ");
  modelica_string tmp91;
  modelica_metatype tmpMeta92;
  static int tmp93 = 0;
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  if(!tmp93)
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    tmp89 = GreaterEq((data->simulationInfo->realParameter[266] /* thermalZoneFourElements.RRoofRem PARAM */),1e-60);
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    if(!tmp89)
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmp91 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[266] /* thermalZoneFourElements.RRoofRem PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmpMeta92 = stringAppend(MMC_REFSTRINGLIT(tmp90),tmp91);
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.RRoofRem >= 1e-60)";
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo",16,3,18,38,0};
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta92));
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        } else {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo",16,3,18,38,0};
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta92));
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        }
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      }
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmp93 = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  }
#line 2444 OMC_FILE
  TRACE_POP
}

/*
equation index: 1449
type: ALGORITHM

  assert(thermalZoneFourElements.RRoof[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RRoof[1], has value: " + String(thermalZoneFourElements.RRoof[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1449(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1449};
  modelica_boolean tmp94;
  static const MMC_DEFSTRINGLIT(tmp95,89,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RRoof[1], has value: ");
  modelica_string tmp96;
  modelica_metatype tmpMeta97;
  static int tmp98 = 0;
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  if(!tmp98)
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    tmp94 = GreaterEq((data->simulationInfo->realParameter[265] /* thermalZoneFourElements.RRoof[1] PARAM */),1e-60);
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    if(!tmp94)
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmp96 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[265] /* thermalZoneFourElements.RRoof[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmpMeta97 = stringAppend(MMC_REFSTRINGLIT(tmp95),tmp96);
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.RRoof[1] >= 1e-60)";
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo",13,3,15,38,0};
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta97));
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        } else {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo",13,3,15,38,0};
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta97));
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        }
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      }
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmp98 = 1;
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    }
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  }
#line 2504 OMC_FILE
  TRACE_POP
}

/*
equation index: 1450
type: ALGORITHM

  assert(thermalZoneFourElements.nRoof >= 1, "Variable violating min constraint: 1 <= thermalZoneFourElements.nRoof, has value: " + String(thermalZoneFourElements.nRoof, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1450(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1450};
  modelica_boolean tmp99;
  static const MMC_DEFSTRINGLIT(tmp100,82,"Variable violating min constraint: 1 <= thermalZoneFourElements.nRoof, has value: ");
  modelica_string tmp101;
  modelica_metatype tmpMeta102;
  static int tmp103 = 0;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  if(!tmp103)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    tmp99 = GreaterEq((data->simulationInfo->integerParameter[21] /* thermalZoneFourElements.nRoof PARAM */),((modelica_integer) 1));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    if(!tmp99)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmp101 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[21] /* thermalZoneFourElements.nRoof PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmpMeta102 = stringAppend(MMC_REFSTRINGLIT(tmp100),tmp101);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.nRoof >= 1)";
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo",11,3,12,37,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta102));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        } else {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo",11,3,12,37,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta102));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
        }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
      tmp103 = 1;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
    }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/FourElements.mo"
  }
#line 2564 OMC_FILE
  TRACE_POP
}

/*
equation index: 1451
type: ALGORITHM

  assert(thermalZoneFourElements.floorRC.T_start >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.floorRC.T_start, has value: " + String(thermalZoneFourElements.floorRC.T_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1451(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1451};
  modelica_boolean tmp104;
  static const MMC_DEFSTRINGLIT(tmp105,94,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.floorRC.T_start, has value: ");
  modelica_string tmp106;
  modelica_metatype tmpMeta107;
  static int tmp108 = 0;
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp108)
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp104 = GreaterEq((data->simulationInfo->realParameter[287] /* thermalZoneFourElements.floorRC.T_start PARAM */),0.0);
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp104)
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp106 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[287] /* thermalZoneFourElements.floorRC.T_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta107 = stringAppend(MMC_REFSTRINGLIT(tmp105),tmp106);
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.floorRC.T_start >= 0.0)";
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",14,3,16,46,0};
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta107));
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",14,3,16,46,0};
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta107));
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp108 = 1;
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2624 OMC_FILE
  TRACE_POP
}

/*
equation index: 1452
type: ALGORITHM

  assert(thermalZoneFourElements.floorRC.CExt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.floorRC.CExt[1], has value: " + String(thermalZoneFourElements.floorRC.CExt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1452(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1452};
  modelica_boolean tmp109;
  static const MMC_DEFSTRINGLIT(tmp110,96,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.floorRC.CExt[1], has value: ");
  modelica_string tmp111;
  modelica_metatype tmpMeta112;
  static int tmp113 = 0;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp113)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp109 = GreaterEq((data->simulationInfo->realParameter[284] /* thermalZoneFourElements.floorRC.CExt[1] PARAM */),1e-60);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp109)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp111 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[284] /* thermalZoneFourElements.floorRC.CExt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta112 = stringAppend(MMC_REFSTRINGLIT(tmp110),tmp111);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.floorRC.CExt[1] >= 1e-60)";
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",11,3,13,46,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta112));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",11,3,13,46,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta112));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp113 = 1;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2684 OMC_FILE
  TRACE_POP
}

/*
equation index: 1453
type: ALGORITHM

  assert(thermalZoneFourElements.floorRC.RExtRem >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.floorRC.RExtRem, has value: " + String(thermalZoneFourElements.floorRC.RExtRem, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1453(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1453};
  modelica_boolean tmp114;
  static const MMC_DEFSTRINGLIT(tmp115,96,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.floorRC.RExtRem, has value: ");
  modelica_string tmp116;
  modelica_metatype tmpMeta117;
  static int tmp118 = 0;
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp118)
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp114 = GreaterEq((data->simulationInfo->realParameter[286] /* thermalZoneFourElements.floorRC.RExtRem PARAM */),1e-60);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp114)
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp116 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[286] /* thermalZoneFourElements.floorRC.RExtRem PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta117 = stringAppend(MMC_REFSTRINGLIT(tmp115),tmp116);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.floorRC.RExtRem >= 1e-60)";
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",8,3,10,46,0};
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta117));
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",8,3,10,46,0};
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta117));
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp118 = 1;
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2744 OMC_FILE
  TRACE_POP
}

/*
equation index: 1454
type: ALGORITHM

  assert(thermalZoneFourElements.floorRC.RExt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.floorRC.RExt[1], has value: " + String(thermalZoneFourElements.floorRC.RExt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1454(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1454};
  modelica_boolean tmp119;
  static const MMC_DEFSTRINGLIT(tmp120,96,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.floorRC.RExt[1], has value: ");
  modelica_string tmp121;
  modelica_metatype tmpMeta122;
  static int tmp123 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp123)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp119 = GreaterEq((data->simulationInfo->realParameter[285] /* thermalZoneFourElements.floorRC.RExt[1] PARAM */),1e-60);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp119)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp121 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[285] /* thermalZoneFourElements.floorRC.RExt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta122 = stringAppend(MMC_REFSTRINGLIT(tmp120),tmp121);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.floorRC.RExt[1] >= 1e-60)";
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",5,3,7,46,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta122));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",5,3,7,46,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta122));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp123 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2804 OMC_FILE
  TRACE_POP
}

/*
equation index: 1455
type: ALGORITHM

  assert(thermalZoneFourElements.floorRC.n >= 1, "Variable violating min constraint: 1 <= thermalZoneFourElements.floorRC.n, has value: " + String(thermalZoneFourElements.floorRC.n, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1455(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1455};
  modelica_boolean tmp124;
  static const MMC_DEFSTRINGLIT(tmp125,86,"Variable violating min constraint: 1 <= thermalZoneFourElements.floorRC.n, has value: ");
  modelica_string tmp126;
  modelica_metatype tmpMeta127;
  static int tmp128 = 0;
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp128)
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp124 = GreaterEq((data->simulationInfo->integerParameter[13] /* thermalZoneFourElements.floorRC.n PARAM */),((modelica_integer) 1));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp124)
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp126 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[13] /* thermalZoneFourElements.floorRC.n PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta127 = stringAppend(MMC_REFSTRINGLIT(tmp125),tmp126);
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.floorRC.n >= 1)";
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",4,3,4,55,0};
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta127));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",4,3,4,55,0};
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta127));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp128 = 1;
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 2864 OMC_FILE
  TRACE_POP
}

/*
equation index: 1456
type: ALGORITHM

  assert(thermalZoneFourElements.CFloor[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.CFloor[1], has value: " + String(thermalZoneFourElements.CFloor[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1456(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1456};
  modelica_boolean tmp129;
  static const MMC_DEFSTRINGLIT(tmp130,90,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.CFloor[1], has value: ");
  modelica_string tmp131;
  modelica_metatype tmpMeta132;
  static int tmp133 = 0;
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  if(!tmp133)
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  {
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    tmp129 = GreaterEq((data->simulationInfo->realParameter[257] /* thermalZoneFourElements.CFloor[1] PARAM */),1e-60);
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    if(!tmp129)
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    {
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmp131 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[257] /* thermalZoneFourElements.CFloor[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmpMeta132 = stringAppend(MMC_REFSTRINGLIT(tmp130),tmp131);
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      {
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.CFloor[1] >= 1e-60)";
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo",20,3,22,45,0};
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta132));
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        } else {
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo",20,3,22,45,0};
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta132));
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        }
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      }
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmp133 = 1;
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    }
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  }
#line 2924 OMC_FILE
  TRACE_POP
}

/*
equation index: 1457
type: ALGORITHM

  assert(thermalZoneFourElements.RFloorRem >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RFloorRem, has value: " + String(thermalZoneFourElements.RFloorRem, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1457(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1457};
  modelica_boolean tmp134;
  static const MMC_DEFSTRINGLIT(tmp135,90,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RFloorRem, has value: ");
  modelica_string tmp136;
  modelica_metatype tmpMeta137;
  static int tmp138 = 0;
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  if(!tmp138)
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  {
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    tmp134 = GreaterEq((data->simulationInfo->realParameter[263] /* thermalZoneFourElements.RFloorRem PARAM */),1e-60);
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    if(!tmp134)
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    {
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmp136 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[263] /* thermalZoneFourElements.RFloorRem PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmpMeta137 = stringAppend(MMC_REFSTRINGLIT(tmp135),tmp136);
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      {
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.RFloorRem >= 1e-60)";
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo",17,3,19,45,0};
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta137));
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        } else {
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo",17,3,19,45,0};
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta137));
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        }
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      }
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmp138 = 1;
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    }
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  }
#line 2984 OMC_FILE
  TRACE_POP
}

/*
equation index: 1458
type: ALGORITHM

  assert(thermalZoneFourElements.RFloor[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RFloor[1], has value: " + String(thermalZoneFourElements.RFloor[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1458(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1458};
  modelica_boolean tmp139;
  static const MMC_DEFSTRINGLIT(tmp140,90,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RFloor[1], has value: ");
  modelica_string tmp141;
  modelica_metatype tmpMeta142;
  static int tmp143 = 0;
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  if(!tmp143)
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    tmp139 = GreaterEq((data->simulationInfo->realParameter[262] /* thermalZoneFourElements.RFloor[1] PARAM */),1e-60);
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    if(!tmp139)
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmp141 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[262] /* thermalZoneFourElements.RFloor[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmpMeta142 = stringAppend(MMC_REFSTRINGLIT(tmp140),tmp141);
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.RFloor[1] >= 1e-60)";
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo",13,3,16,45,0};
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta142));
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        } else {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo",13,3,16,45,0};
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta142));
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        }
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      }
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmp143 = 1;
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    }
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  }
#line 3044 OMC_FILE
  TRACE_POP
}

/*
equation index: 1459
type: ALGORITHM

  assert(thermalZoneFourElements.nFloor >= 1, "Variable violating min constraint: 1 <= thermalZoneFourElements.nFloor, has value: " + String(thermalZoneFourElements.nFloor, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1459(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1459};
  modelica_boolean tmp144;
  static const MMC_DEFSTRINGLIT(tmp145,83,"Variable violating min constraint: 1 <= thermalZoneFourElements.nFloor, has value: ");
  modelica_string tmp146;
  modelica_metatype tmpMeta147;
  static int tmp148 = 0;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  if(!tmp148)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    tmp144 = GreaterEq((data->simulationInfo->integerParameter[17] /* thermalZoneFourElements.nFloor PARAM */),((modelica_integer) 1));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    if(!tmp144)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmp146 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[17] /* thermalZoneFourElements.nFloor PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmpMeta147 = stringAppend(MMC_REFSTRINGLIT(tmp145),tmp146);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.nFloor >= 1)";
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo",11,3,12,44,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta147));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        } else {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo",11,3,12,44,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta147));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
        }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
      tmp148 = 1;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
    }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/ThreeElements.mo"
  }
#line 3104 OMC_FILE
  TRACE_POP
}

/*
equation index: 1460
type: ALGORITHM

  assert(thermalZoneFourElements.intWallRC.T_start >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.intWallRC.T_start, has value: " + String(thermalZoneFourElements.intWallRC.T_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1460(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1460};
  modelica_boolean tmp149;
  static const MMC_DEFSTRINGLIT(tmp150,96,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.intWallRC.T_start, has value: ");
  modelica_string tmp151;
  modelica_metatype tmpMeta152;
  static int tmp153 = 0;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  if(!tmp153)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    tmp149 = GreaterEq((data->simulationInfo->realParameter[305] /* thermalZoneFourElements.intWallRC.T_start PARAM */),0.0);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    if(!tmp149)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmp151 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[305] /* thermalZoneFourElements.intWallRC.T_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmpMeta152 = stringAppend(MMC_REFSTRINGLIT(tmp150),tmp151);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.intWallRC.T_start >= 0.0)";
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo",11,3,13,46,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta152));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        } else {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo",11,3,13,46,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta152));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmp153 = 1;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  }
#line 3164 OMC_FILE
  TRACE_POP
}

/*
equation index: 1461
type: ALGORITHM

  assert(thermalZoneFourElements.intWallRC.CInt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.intWallRC.CInt[1], has value: " + String(thermalZoneFourElements.intWallRC.CInt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1461(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1461};
  modelica_boolean tmp154;
  static const MMC_DEFSTRINGLIT(tmp155,98,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.intWallRC.CInt[1], has value: ");
  modelica_string tmp156;
  modelica_metatype tmpMeta157;
  static int tmp158 = 0;
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  if(!tmp158)
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    tmp154 = GreaterEq((data->simulationInfo->realParameter[303] /* thermalZoneFourElements.intWallRC.CInt[1] PARAM */),1e-60);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    if(!tmp154)
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmp156 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[303] /* thermalZoneFourElements.intWallRC.CInt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmpMeta157 = stringAppend(MMC_REFSTRINGLIT(tmp155),tmp156);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.intWallRC.CInt[1] >= 1e-60)";
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo",8,3,10,46,0};
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta157));
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        } else {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo",8,3,10,46,0};
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta157));
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmp158 = 1;
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  }
#line 3224 OMC_FILE
  TRACE_POP
}

/*
equation index: 1462
type: ALGORITHM

  assert(thermalZoneFourElements.intWallRC.RInt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.intWallRC.RInt[1], has value: " + String(thermalZoneFourElements.intWallRC.RInt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1462(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1462};
  modelica_boolean tmp159;
  static const MMC_DEFSTRINGLIT(tmp160,98,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.intWallRC.RInt[1], has value: ");
  modelica_string tmp161;
  modelica_metatype tmpMeta162;
  static int tmp163 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  if(!tmp163)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    tmp159 = GreaterEq((data->simulationInfo->realParameter[304] /* thermalZoneFourElements.intWallRC.RInt[1] PARAM */),1e-60);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    if(!tmp159)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmp161 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[304] /* thermalZoneFourElements.intWallRC.RInt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmpMeta162 = stringAppend(MMC_REFSTRINGLIT(tmp160),tmp161);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.intWallRC.RInt[1] >= 1e-60)";
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo",5,3,7,46,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta162));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo",5,3,7,46,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta162));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmp163 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  }
#line 3284 OMC_FILE
  TRACE_POP
}

/*
equation index: 1463
type: ALGORITHM

  assert(thermalZoneFourElements.intWallRC.n >= 1, "Variable violating min constraint: 1 <= thermalZoneFourElements.intWallRC.n, has value: " + String(thermalZoneFourElements.intWallRC.n, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1463(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1463};
  modelica_boolean tmp164;
  static const MMC_DEFSTRINGLIT(tmp165,88,"Variable violating min constraint: 1 <= thermalZoneFourElements.intWallRC.n, has value: ");
  modelica_string tmp166;
  modelica_metatype tmpMeta167;
  static int tmp168 = 0;
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  if(!tmp168)
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    tmp164 = GreaterEq((data->simulationInfo->integerParameter[14] /* thermalZoneFourElements.intWallRC.n PARAM */),((modelica_integer) 1));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    if(!tmp164)
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmp166 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[14] /* thermalZoneFourElements.intWallRC.n PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmpMeta167 = stringAppend(MMC_REFSTRINGLIT(tmp165),tmp166);
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.intWallRC.n >= 1)";
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo",4,3,4,55,0};
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta167));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        } else {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo",4,3,4,55,0};
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta167));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
        }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
      tmp168 = 1;
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
    }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/InteriorWall.mo"
  }
#line 3344 OMC_FILE
  TRACE_POP
}

/*
equation index: 1464
type: ALGORITHM

  assert(thermalZoneFourElements.CInt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.CInt[1], has value: " + String(thermalZoneFourElements.CInt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1464(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1464};
  modelica_boolean tmp169;
  static const MMC_DEFSTRINGLIT(tmp170,88,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.CInt[1], has value: ");
  modelica_string tmp171;
  modelica_metatype tmpMeta172;
  static int tmp173 = 0;
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
  if(!tmp173)
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    tmp169 = GreaterEq((data->simulationInfo->realParameter[258] /* thermalZoneFourElements.CInt[1] PARAM */),1e-60);
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    if(!tmp169)
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      tmp171 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[258] /* thermalZoneFourElements.CInt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      tmpMeta172 = stringAppend(MMC_REFSTRINGLIT(tmp170),tmp171);
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.CInt[1] >= 1e-60)";
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo",16,3,18,48,0};
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta172));
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        } else {
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo",16,3,18,48,0};
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta172));
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        }
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      }
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      tmp173 = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
  }
#line 3404 OMC_FILE
  TRACE_POP
}

/*
equation index: 1465
type: ALGORITHM

  assert(thermalZoneFourElements.RInt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RInt[1], has value: " + String(thermalZoneFourElements.RInt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1465(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1465};
  modelica_boolean tmp174;
  static const MMC_DEFSTRINGLIT(tmp175,88,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RInt[1], has value: ");
  modelica_string tmp176;
  modelica_metatype tmpMeta177;
  static int tmp178 = 0;
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
  if(!tmp178)
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
  {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    tmp174 = GreaterEq((data->simulationInfo->realParameter[264] /* thermalZoneFourElements.RInt[1] PARAM */),1e-60);
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    if(!tmp174)
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      tmp176 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[264] /* thermalZoneFourElements.RInt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      tmpMeta177 = stringAppend(MMC_REFSTRINGLIT(tmp175),tmp176);
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.RInt[1] >= 1e-60)";
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo",13,3,15,48,0};
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta177));
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        } else {
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo",13,3,15,48,0};
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta177));
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        }
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      }
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      tmp178 = 1;
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    }
#line 13 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
  }
#line 3464 OMC_FILE
  TRACE_POP
}

/*
equation index: 1466
type: ALGORITHM

  assert(thermalZoneFourElements.nInt >= 1, "Variable violating min constraint: 1 <= thermalZoneFourElements.nInt, has value: " + String(thermalZoneFourElements.nInt, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1466(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1466};
  modelica_boolean tmp179;
  static const MMC_DEFSTRINGLIT(tmp180,81,"Variable violating min constraint: 1 <= thermalZoneFourElements.nInt, has value: ");
  modelica_string tmp181;
  modelica_metatype tmpMeta182;
  static int tmp183 = 0;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
  if(!tmp183)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
  {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    tmp179 = GreaterEq((data->simulationInfo->integerParameter[18] /* thermalZoneFourElements.nInt PARAM */),((modelica_integer) 1));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    if(!tmp179)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      tmp181 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[18] /* thermalZoneFourElements.nInt PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      tmpMeta182 = stringAppend(MMC_REFSTRINGLIT(tmp180),tmp181);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        const char* assert_cond = "(thermalZoneFourElements.nInt >= 1)";
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo",11,3,12,47,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta182));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        } else {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo",11,3,12,47,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta182));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
        }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
      tmp183 = 1;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
    }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/TwoElements.mo"
  }
#line 3524 OMC_FILE
  TRACE_POP
}

/*
equation index: 1467
type: ALGORITHM

  assert(thermalZoneFourElements.extWallRC.T_start >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.extWallRC.T_start, has value: " + String(thermalZoneFourElements.extWallRC.T_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1467(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1467};
  modelica_boolean tmp184;
  static const MMC_DEFSTRINGLIT(tmp185,96,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.extWallRC.T_start, has value: ");
  modelica_string tmp186;
  modelica_metatype tmpMeta187;
  static int tmp188 = 0;
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp188)
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp184 = GreaterEq((data->simulationInfo->realParameter[280] /* thermalZoneFourElements.extWallRC.T_start PARAM */),0.0);
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp184)
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp186 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[280] /* thermalZoneFourElements.extWallRC.T_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta187 = stringAppend(MMC_REFSTRINGLIT(tmp185),tmp186);
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.extWallRC.T_start >= 0.0)";
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",14,3,16,46,0};
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta187));
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",14,3,16,46,0};
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta187));
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp188 = 1;
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 3584 OMC_FILE
  TRACE_POP
}

/*
equation index: 1468
type: ALGORITHM

  assert(thermalZoneFourElements.extWallRC.CExt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.extWallRC.CExt[1], has value: " + String(thermalZoneFourElements.extWallRC.CExt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1468(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1468};
  modelica_boolean tmp189;
  static const MMC_DEFSTRINGLIT(tmp190,98,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.extWallRC.CExt[1], has value: ");
  modelica_string tmp191;
  modelica_metatype tmpMeta192;
  static int tmp193 = 0;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp193)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp189 = GreaterEq((data->simulationInfo->realParameter[277] /* thermalZoneFourElements.extWallRC.CExt[1] PARAM */),1e-60);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp189)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp191 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[277] /* thermalZoneFourElements.extWallRC.CExt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta192 = stringAppend(MMC_REFSTRINGLIT(tmp190),tmp191);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.extWallRC.CExt[1] >= 1e-60)";
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",11,3,13,46,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta192));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",11,3,13,46,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta192));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp193 = 1;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 3644 OMC_FILE
  TRACE_POP
}

/*
equation index: 1469
type: ALGORITHM

  assert(thermalZoneFourElements.extWallRC.RExtRem >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.extWallRC.RExtRem, has value: " + String(thermalZoneFourElements.extWallRC.RExtRem, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1469(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1469};
  modelica_boolean tmp194;
  static const MMC_DEFSTRINGLIT(tmp195,98,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.extWallRC.RExtRem, has value: ");
  modelica_string tmp196;
  modelica_metatype tmpMeta197;
  static int tmp198 = 0;
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp198)
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp194 = GreaterEq((data->simulationInfo->realParameter[279] /* thermalZoneFourElements.extWallRC.RExtRem PARAM */),1e-60);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp194)
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp196 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[279] /* thermalZoneFourElements.extWallRC.RExtRem PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta197 = stringAppend(MMC_REFSTRINGLIT(tmp195),tmp196);
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.extWallRC.RExtRem >= 1e-60)";
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",8,3,10,46,0};
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta197));
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",8,3,10,46,0};
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta197));
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp198 = 1;
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 8 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 3704 OMC_FILE
  TRACE_POP
}

/*
equation index: 1470
type: ALGORITHM

  assert(thermalZoneFourElements.extWallRC.RExt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.extWallRC.RExt[1], has value: " + String(thermalZoneFourElements.extWallRC.RExt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1470(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1470};
  modelica_boolean tmp199;
  static const MMC_DEFSTRINGLIT(tmp200,98,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.extWallRC.RExt[1], has value: ");
  modelica_string tmp201;
  modelica_metatype tmpMeta202;
  static int tmp203 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp203)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp199 = GreaterEq((data->simulationInfo->realParameter[278] /* thermalZoneFourElements.extWallRC.RExt[1] PARAM */),1e-60);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp199)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp201 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[278] /* thermalZoneFourElements.extWallRC.RExt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta202 = stringAppend(MMC_REFSTRINGLIT(tmp200),tmp201);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.extWallRC.RExt[1] >= 1e-60)";
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",5,3,7,46,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta202));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",5,3,7,46,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta202));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp203 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 3764 OMC_FILE
  TRACE_POP
}

/*
equation index: 1471
type: ALGORITHM

  assert(thermalZoneFourElements.extWallRC.n >= 1, "Variable violating min constraint: 1 <= thermalZoneFourElements.extWallRC.n, has value: " + String(thermalZoneFourElements.extWallRC.n, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1471(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1471};
  modelica_boolean tmp204;
  static const MMC_DEFSTRINGLIT(tmp205,88,"Variable violating min constraint: 1 <= thermalZoneFourElements.extWallRC.n, has value: ");
  modelica_string tmp206;
  modelica_metatype tmpMeta207;
  static int tmp208 = 0;
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  if(!tmp208)
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    tmp204 = GreaterEq((data->simulationInfo->integerParameter[12] /* thermalZoneFourElements.extWallRC.n PARAM */),((modelica_integer) 1));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    if(!tmp204)
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp206 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[12] /* thermalZoneFourElements.extWallRC.n PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmpMeta207 = stringAppend(MMC_REFSTRINGLIT(tmp205),tmp206);
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        const char* assert_cond = "(thermalZoneFourElements.extWallRC.n >= 1)";
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",4,3,4,55,0};
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta207));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        } else {
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo",4,3,4,55,0};
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta207));
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
        }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
      tmp208 = 1;
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
    }
#line 4 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ExteriorWall.mo"
  }
#line 3824 OMC_FILE
  TRACE_POP
}

/*
equation index: 1472
type: ALGORITHM

  assert(thermalZoneFourElements.radHeatSol[2].T_ref >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.radHeatSol[2].T_ref, has value: " + String(thermalZoneFourElements.radHeatSol[2].T_ref, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1472(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1472};
  modelica_boolean tmp209;
  static const MMC_DEFSTRINGLIT(tmp210,98,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.radHeatSol[2].T_ref, has value: ");
  modelica_string tmp211;
  modelica_metatype tmpMeta212;
  static int tmp213 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  if(!tmp213)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    tmp209 = GreaterEq((data->simulationInfo->realParameter[311] /* thermalZoneFourElements.radHeatSol[2].T_ref PARAM */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    if(!tmp209)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp211 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[311] /* thermalZoneFourElements.radHeatSol[2].T_ref PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmpMeta212 = stringAppend(MMC_REFSTRINGLIT(tmp210),tmp211);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        const char* assert_cond = "(thermalZoneFourElements.radHeatSol[2].T_ref >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta212));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta212));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp213 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  }
#line 3884 OMC_FILE
  TRACE_POP
}

/*
equation index: 1473
type: ALGORITHM

  assert(thermalZoneFourElements.radHeatSol[1].T_ref >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.radHeatSol[1].T_ref, has value: " + String(thermalZoneFourElements.radHeatSol[1].T_ref, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1473(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1473};
  modelica_boolean tmp214;
  static const MMC_DEFSTRINGLIT(tmp215,98,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.radHeatSol[1].T_ref, has value: ");
  modelica_string tmp216;
  modelica_metatype tmpMeta217;
  static int tmp218 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  if(!tmp218)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    tmp214 = GreaterEq((data->simulationInfo->realParameter[310] /* thermalZoneFourElements.radHeatSol[1].T_ref PARAM */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    if(!tmp214)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp216 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[310] /* thermalZoneFourElements.radHeatSol[1].T_ref PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmpMeta217 = stringAppend(MMC_REFSTRINGLIT(tmp215),tmp216);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        const char* assert_cond = "(thermalZoneFourElements.radHeatSol[1].T_ref >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta217));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta217));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp218 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  }
#line 3944 OMC_FILE
  TRACE_POP
}

/*
equation index: 1474
type: ALGORITHM

  assert(thermalZoneFourElements.convHeatSol.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.convHeatSol.T_ref, has value: " + String(thermalZoneFourElements.convHeatSol.T_ref, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1474(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1474};
  modelica_boolean tmp219;
  static const MMC_DEFSTRINGLIT(tmp220,96,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.convHeatSol.T_ref, has value: ");
  modelica_string tmp221;
  modelica_metatype tmpMeta222;
  static int tmp223 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  if(!tmp223)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    tmp219 = GreaterEq((data->simulationInfo->realParameter[271] /* thermalZoneFourElements.convHeatSol.T_ref PARAM */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    if(!tmp219)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp221 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[271] /* thermalZoneFourElements.convHeatSol.T_ref PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmpMeta222 = stringAppend(MMC_REFSTRINGLIT(tmp220),tmp221);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        const char* assert_cond = "(thermalZoneFourElements.convHeatSol.T_ref >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta222));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo",3,3,4,28,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta222));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
      tmp223 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Sources/PrescribedHeatFlow.mo"
  }
#line 4004 OMC_FILE
  TRACE_POP
}

/*
equation index: 1475
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.state_start.T >= 273.15 and thermalZoneFourElements.volAir.state_start.T <= 373.15, "Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.state_start.T <= 373.15, has value: " + String(thermalZoneFourElements.volAir.state_start.T, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1475(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1475};
  modelica_boolean tmp224;
  modelica_boolean tmp225;
  static const MMC_DEFSTRINGLIT(tmp226,116,"Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.state_start.T <= 373.15, has value: ");
  modelica_string tmp227;
  modelica_metatype tmpMeta228;
  static int tmp229 = 0;
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp229)
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp224 = GreaterEq((data->simulationInfo->realParameter[388] /* thermalZoneFourElements.volAir.state_start.T PARAM */),273.15);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp225 = LessEq((data->simulationInfo->realParameter[388] /* thermalZoneFourElements.volAir.state_start.T PARAM */),373.15);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp224 && tmp225))
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp227 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[388] /* thermalZoneFourElements.volAir.state_start.T PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta228 = stringAppend(MMC_REFSTRINGLIT(tmp226),tmp227);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.state_start.T >= 273.15 and thermalZoneFourElements.volAir.state_start.T <= 373.15)";
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6169,7,6169,44,0};
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta228));
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6169,7,6169,44,0};
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta228));
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp229 = 1;
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 4067 OMC_FILE
  TRACE_POP
}

/*
equation index: 1476
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.state_start.p >= 0.0 and thermalZoneFourElements.volAir.state_start.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.state_start.p <= 100000000.0, has value: " + String(thermalZoneFourElements.volAir.state_start.p, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1476(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1476};
  modelica_boolean tmp230;
  modelica_boolean tmp231;
  static const MMC_DEFSTRINGLIT(tmp232,118,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.state_start.p <= 100000000.0, has value: ");
  modelica_string tmp233;
  modelica_metatype tmpMeta234;
  static int tmp235 = 0;
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp235)
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp230 = GreaterEq((data->simulationInfo->realParameter[389] /* thermalZoneFourElements.volAir.state_start.p PARAM */),0.0);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp231 = LessEq((data->simulationInfo->realParameter[389] /* thermalZoneFourElements.volAir.state_start.p PARAM */),100000000.0);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp230 && tmp231))
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp233 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[389] /* thermalZoneFourElements.volAir.state_start.p PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta234 = stringAppend(MMC_REFSTRINGLIT(tmp232),tmp233);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.state_start.p >= 0.0 and thermalZoneFourElements.volAir.state_start.p <= 100000000.0)";
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6168,7,6168,55,0};
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta234));
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6168,7,6168,55,0};
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta234));
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp235 = 1;
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 4130 OMC_FILE
  TRACE_POP
}

/*
equation index: 1477
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.rho_default >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.rho_default, has value: " + String(thermalZoneFourElements.volAir.rho_default, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1477(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1477};
  modelica_boolean tmp236;
  static const MMC_DEFSTRINGLIT(tmp237,97,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.rho_default, has value: ");
  modelica_string tmp238;
  modelica_metatype tmpMeta239;
  static int tmp240 = 0;
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  if(!tmp240)
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    tmp236 = GreaterEq((data->simulationInfo->realParameter[384] /* thermalZoneFourElements.volAir.rho_default PARAM */),0.0);
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    if(!tmp236)
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp238 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[384] /* thermalZoneFourElements.volAir.rho_default PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmpMeta239 = stringAppend(MMC_REFSTRINGLIT(tmp237),tmp238);
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.rho_default >= 0.0)";
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",96,3,97,63,0};
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta239));
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        } else {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",96,3,97,63,0};
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta239));
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        }
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      }
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp240 = 1;
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    }
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  }
#line 4190 OMC_FILE
  TRACE_POP
}

/*
equation index: 1478
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.state_default.T >= 273.15 and thermalZoneFourElements.volAir.state_default.T <= 373.15, "Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.state_default.T <= 373.15, has value: " + String(thermalZoneFourElements.volAir.state_default.T, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1478(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1478};
  modelica_boolean tmp241;
  modelica_boolean tmp242;
  static const MMC_DEFSTRINGLIT(tmp243,118,"Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.state_default.T <= 373.15, has value: ");
  modelica_string tmp244;
  modelica_metatype tmpMeta245;
  static int tmp246 = 0;
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp246)
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp241 = GreaterEq((data->simulationInfo->realParameter[386] /* thermalZoneFourElements.volAir.state_default.T PARAM */),273.15);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp242 = LessEq((data->simulationInfo->realParameter[386] /* thermalZoneFourElements.volAir.state_default.T PARAM */),373.15);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp241 && tmp242))
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp244 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[386] /* thermalZoneFourElements.volAir.state_default.T PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta245 = stringAppend(MMC_REFSTRINGLIT(tmp243),tmp244);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.state_default.T >= 273.15 and thermalZoneFourElements.volAir.state_default.T <= 373.15)";
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6169,7,6169,44,0};
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta245));
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6169,7,6169,44,0};
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta245));
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp246 = 1;
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 4253 OMC_FILE
  TRACE_POP
}

/*
equation index: 1479
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.state_default.p >= 0.0 and thermalZoneFourElements.volAir.state_default.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.state_default.p <= 100000000.0, has value: " + String(thermalZoneFourElements.volAir.state_default.p, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1479(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1479};
  modelica_boolean tmp247;
  modelica_boolean tmp248;
  static const MMC_DEFSTRINGLIT(tmp249,120,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.state_default.p <= 100000000.0, has value: ");
  modelica_string tmp250;
  modelica_metatype tmpMeta251;
  static int tmp252 = 0;
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp252)
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp247 = GreaterEq((data->simulationInfo->realParameter[387] /* thermalZoneFourElements.volAir.state_default.p PARAM */),0.0);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp248 = LessEq((data->simulationInfo->realParameter[387] /* thermalZoneFourElements.volAir.state_default.p PARAM */),100000000.0);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp247 && tmp248))
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp250 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[387] /* thermalZoneFourElements.volAir.state_default.p PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta251 = stringAppend(MMC_REFSTRINGLIT(tmp249),tmp250);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.state_default.p >= 0.0 and thermalZoneFourElements.volAir.state_default.p <= 100000000.0)";
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6168,7,6168,55,0};
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta251));
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6168,7,6168,55,0};
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta251));
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp252 = 1;
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 4316 OMC_FILE
  TRACE_POP
}

/*
equation index: 1480
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.rho_start >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.rho_start, has value: " + String(thermalZoneFourElements.volAir.rho_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1480(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1480};
  modelica_boolean tmp253;
  static const MMC_DEFSTRINGLIT(tmp254,95,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.rho_start, has value: ");
  modelica_string tmp255;
  modelica_metatype tmpMeta256;
  static int tmp257 = 0;
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  if(!tmp257)
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  {
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    tmp253 = GreaterEq((data->simulationInfo->realParameter[385] /* thermalZoneFourElements.volAir.rho_start PARAM */),0.0);
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    if(!tmp253)
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    {
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp255 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[385] /* thermalZoneFourElements.volAir.rho_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmpMeta256 = stringAppend(MMC_REFSTRINGLIT(tmp254),tmp255);
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      {
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.rho_start >= 0.0)";
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",89,3,90,73,0};
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta256));
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        } else {
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",89,3,90,73,0};
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta256));
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        }
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      }
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp257 = 1;
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    }
#line 89 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  }
#line 4376 OMC_FILE
  TRACE_POP
}

/*
equation index: 1481
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.rho_default >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.rho_default, has value: " + String(thermalZoneFourElements.volAir.dynBal.rho_default, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1481(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1481};
  modelica_boolean tmp258;
  static const MMC_DEFSTRINGLIT(tmp259,104,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.rho_default, has value: ");
  modelica_string tmp260;
  modelica_metatype tmpMeta261;
  static int tmp262 = 0;
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  if(!tmp262)
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  {
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    tmp258 = GreaterEq((data->simulationInfo->realParameter[376] /* thermalZoneFourElements.volAir.dynBal.rho_default PARAM */),0.0);
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    if(!tmp258)
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    {
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      tmp260 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[376] /* thermalZoneFourElements.volAir.dynBal.rho_default PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      tmpMeta261 = stringAppend(MMC_REFSTRINGLIT(tmp259),tmp260);
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      {
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.rho_default >= 0.0)";
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo",145,3,146,59,0};
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta261));
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        } else {
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo",145,3,146,59,0};
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta261));
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        }
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      }
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      tmp262 = 1;
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    }
#line 145 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  }
#line 4436 OMC_FILE
  TRACE_POP
}

/*
equation index: 1482
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.state_default.T >= 273.15 and thermalZoneFourElements.volAir.dynBal.state_default.T <= 373.15, "Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.dynBal.state_default.T <= 373.15, has value: " + String(thermalZoneFourElements.volAir.dynBal.state_default.T, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1482(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1482};
  modelica_boolean tmp263;
  modelica_boolean tmp264;
  static const MMC_DEFSTRINGLIT(tmp265,125,"Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.dynBal.state_default.T <= 373.15, has value: ");
  modelica_string tmp266;
  modelica_metatype tmpMeta267;
  static int tmp268 = 0;
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp268)
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp263 = GreaterEq((data->simulationInfo->realParameter[378] /* thermalZoneFourElements.volAir.dynBal.state_default.T PARAM */),273.15);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp264 = LessEq((data->simulationInfo->realParameter[378] /* thermalZoneFourElements.volAir.dynBal.state_default.T PARAM */),373.15);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp263 && tmp264))
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp266 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[378] /* thermalZoneFourElements.volAir.dynBal.state_default.T PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta267 = stringAppend(MMC_REFSTRINGLIT(tmp265),tmp266);
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.state_default.T >= 273.15 and thermalZoneFourElements.volAir.dynBal.state_default.T <= 373.15)";
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6169,7,6169,44,0};
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta267));
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6169,7,6169,44,0};
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta267));
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp268 = 1;
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 6169 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 4499 OMC_FILE
  TRACE_POP
}

/*
equation index: 1483
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.state_default.p >= 0.0 and thermalZoneFourElements.volAir.dynBal.state_default.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.state_default.p <= 100000000.0, has value: " + String(thermalZoneFourElements.volAir.dynBal.state_default.p, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1483(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1483};
  modelica_boolean tmp269;
  modelica_boolean tmp270;
  static const MMC_DEFSTRINGLIT(tmp271,127,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.state_default.p <= 100000000.0, has value: ");
  modelica_string tmp272;
  modelica_metatype tmpMeta273;
  static int tmp274 = 0;
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp274)
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp269 = GreaterEq((data->simulationInfo->realParameter[379] /* thermalZoneFourElements.volAir.dynBal.state_default.p PARAM */),0.0);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp270 = LessEq((data->simulationInfo->realParameter[379] /* thermalZoneFourElements.volAir.dynBal.state_default.p PARAM */),100000000.0);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp269 && tmp270))
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp272 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[379] /* thermalZoneFourElements.volAir.dynBal.state_default.p PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta273 = stringAppend(MMC_REFSTRINGLIT(tmp271),tmp272);
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.state_default.p >= 0.0 and thermalZoneFourElements.volAir.dynBal.state_default.p <= 100000000.0)";
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6168,7,6168,55,0};
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta273));
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6168,7,6168,55,0};
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta273));
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp274 = 1;
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 6168 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 4562 OMC_FILE
  TRACE_POP
}

/*
equation index: 1484
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.rho_start >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.rho_start, has value: " + String(thermalZoneFourElements.volAir.dynBal.rho_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1484(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1484};
  modelica_boolean tmp275;
  static const MMC_DEFSTRINGLIT(tmp276,102,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.rho_start, has value: ");
  modelica_string tmp277;
  modelica_metatype tmpMeta278;
  static int tmp279 = 0;
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  if(!tmp279)
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  {
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    tmp275 = GreaterEq((data->simulationInfo->realParameter[377] /* thermalZoneFourElements.volAir.dynBal.rho_start PARAM */),0.0);
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    if(!tmp275)
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    {
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      tmp277 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[377] /* thermalZoneFourElements.volAir.dynBal.rho_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      tmpMeta278 = stringAppend(MMC_REFSTRINGLIT(tmp276),tmp277);
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      {
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.rho_start >= 0.0)";
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo",131,3,135,70,0};
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta278));
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        } else {
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo",131,3,135,70,0};
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta278));
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        }
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      }
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      tmp279 = 1;
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    }
#line 131 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  }
#line 4622 OMC_FILE
  TRACE_POP
}

/*
equation index: 1485
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.mSenFac >= 1.0, "Variable violating min constraint: 1.0 <= thermalZoneFourElements.volAir.dynBal.mSenFac, has value: " + String(thermalZoneFourElements.volAir.dynBal.mSenFac, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1485(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1485};
  modelica_boolean tmp280;
  static const MMC_DEFSTRINGLIT(tmp281,100,"Variable violating min constraint: 1.0 <= thermalZoneFourElements.volAir.dynBal.mSenFac, has value: ");
  modelica_string tmp282;
  modelica_metatype tmpMeta283;
  static int tmp284 = 0;
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp284)
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp280 = GreaterEq((data->simulationInfo->realParameter[374] /* thermalZoneFourElements.volAir.dynBal.mSenFac PARAM */),1.0);
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!tmp280)
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp282 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[374] /* thermalZoneFourElements.volAir.dynBal.mSenFac PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta283 = stringAppend(MMC_REFSTRINGLIT(tmp281),tmp282);
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.mSenFac >= 1.0)";
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",47,3,49,39,0};
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta283));
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",47,3,49,39,0};
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta283));
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp284 = 1;
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 4682 OMC_FILE
  TRACE_POP
}

/*
equation index: 1486
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.X_start[1] >= 0.0 and thermalZoneFourElements.volAir.dynBal.X_start[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.X_start[1] <= 1.0, has value: " + String(thermalZoneFourElements.volAir.dynBal.X_start[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1486(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1486};
  modelica_boolean tmp285;
  modelica_boolean tmp286;
  static const MMC_DEFSTRINGLIT(tmp287,114,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.X_start[1] <= 1.0, has value: ");
  modelica_string tmp288;
  modelica_metatype tmpMeta289;
  static int tmp290 = 0;
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp290)
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp285 = GreaterEq((data->simulationInfo->realParameter[370] /* thermalZoneFourElements.volAir.dynBal.X_start[1] PARAM */),0.0);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp286 = LessEq((data->simulationInfo->realParameter[370] /* thermalZoneFourElements.volAir.dynBal.X_start[1] PARAM */),1.0);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp285 && tmp286))
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp288 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[370] /* thermalZoneFourElements.volAir.dynBal.X_start[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta289 = stringAppend(MMC_REFSTRINGLIT(tmp287),tmp288);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.X_start[1] >= 0.0 and thermalZoneFourElements.volAir.dynBal.X_start[1] <= 1.0)";
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",35,3,38,69,0};
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta289));
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",35,3,38,69,0};
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta289));
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp290 = 1;
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 4745 OMC_FILE
  TRACE_POP
}

/*
equation index: 1487
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.T_start >= 273.15 and thermalZoneFourElements.volAir.dynBal.T_start <= 373.15, "Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.dynBal.T_start <= 373.15, has value: " + String(thermalZoneFourElements.volAir.dynBal.T_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1487(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1487};
  modelica_boolean tmp291;
  modelica_boolean tmp292;
  static const MMC_DEFSTRINGLIT(tmp293,117,"Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.dynBal.T_start <= 373.15, has value: ");
  modelica_string tmp294;
  modelica_metatype tmpMeta295;
  static int tmp296 = 0;
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp296)
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp291 = GreaterEq((data->simulationInfo->realParameter[369] /* thermalZoneFourElements.volAir.dynBal.T_start PARAM */),273.15);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp292 = LessEq((data->simulationInfo->realParameter[369] /* thermalZoneFourElements.volAir.dynBal.T_start PARAM */),373.15);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp291 && tmp292))
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp294 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[369] /* thermalZoneFourElements.volAir.dynBal.T_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta295 = stringAppend(MMC_REFSTRINGLIT(tmp293),tmp294);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.T_start >= 273.15 and thermalZoneFourElements.volAir.dynBal.T_start <= 373.15)";
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",32,3,34,47,0};
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta295));
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",32,3,34,47,0};
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta295));
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp296 = 1;
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 4808 OMC_FILE
  TRACE_POP
}

/*
equation index: 1488
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.p_start >= 0.0 and thermalZoneFourElements.volAir.dynBal.p_start <= 100000000.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.p_start <= 100000000.0, has value: " + String(thermalZoneFourElements.volAir.dynBal.p_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1488(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1488};
  modelica_boolean tmp297;
  modelica_boolean tmp298;
  static const MMC_DEFSTRINGLIT(tmp299,119,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.p_start <= 100000000.0, has value: ");
  modelica_string tmp300;
  modelica_metatype tmpMeta301;
  static int tmp302 = 0;
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp302)
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp297 = GreaterEq((data->simulationInfo->realParameter[375] /* thermalZoneFourElements.volAir.dynBal.p_start PARAM */),0.0);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp298 = LessEq((data->simulationInfo->realParameter[375] /* thermalZoneFourElements.volAir.dynBal.p_start PARAM */),100000000.0);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp297 && tmp298))
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp300 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[375] /* thermalZoneFourElements.volAir.dynBal.p_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta301 = stringAppend(MMC_REFSTRINGLIT(tmp299),tmp300);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.p_start >= 0.0 and thermalZoneFourElements.volAir.dynBal.p_start <= 100000000.0)";
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",29,3,31,47,0};
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta301));
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",29,3,31,47,0};
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta301));
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp302 = 1;
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 4871 OMC_FILE
  TRACE_POP
}

/*
equation index: 1489
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.dynBal.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.dynBal.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.volAir.dynBal.traceDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1489(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1489};
  modelica_boolean tmp303;
  modelica_boolean tmp304;
  static const MMC_DEFSTRINGLIT(tmp305,200,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.dynBal.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp306;
  modelica_metatype tmpMeta307;
  static int tmp308 = 0;
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp308)
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp303 = GreaterEq((data->simulationInfo->integerParameter[34] /* thermalZoneFourElements.volAir.dynBal.traceDynamics PARAM */),1);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp304 = LessEq((data->simulationInfo->integerParameter[34] /* thermalZoneFourElements.volAir.dynBal.traceDynamics PARAM */),4);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp303 && tmp304))
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp306 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[34] /* thermalZoneFourElements.volAir.dynBal.traceDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta307 = stringAppend(MMC_REFSTRINGLIT(tmp305),tmp306);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.dynBal.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",24,3,26,88,0};
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta307));
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",24,3,26,88,0};
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta307));
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp308 = 1;
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 4934 OMC_FILE
  TRACE_POP
}

/*
equation index: 1490
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.dynBal.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.dynBal.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.volAir.dynBal.substanceDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1490(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1490};
  modelica_boolean tmp309;
  modelica_boolean tmp310;
  static const MMC_DEFSTRINGLIT(tmp311,204,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.dynBal.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp312;
  modelica_metatype tmpMeta313;
  static int tmp314 = 0;
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp314)
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp309 = GreaterEq((data->simulationInfo->integerParameter[33] /* thermalZoneFourElements.volAir.dynBal.substanceDynamics PARAM */),1);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp310 = LessEq((data->simulationInfo->integerParameter[33] /* thermalZoneFourElements.volAir.dynBal.substanceDynamics PARAM */),4);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp309 && tmp310))
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp312 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[33] /* thermalZoneFourElements.volAir.dynBal.substanceDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta313 = stringAppend(MMC_REFSTRINGLIT(tmp311),tmp312);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.dynBal.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",21,3,23,88,0};
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta313));
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",21,3,23,88,0};
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta313));
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp314 = 1;
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 4997 OMC_FILE
  TRACE_POP
}

/*
equation index: 1491
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.dynBal.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.dynBal.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.volAir.dynBal.massDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1491(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1491};
  modelica_boolean tmp315;
  modelica_boolean tmp316;
  static const MMC_DEFSTRINGLIT(tmp317,199,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.dynBal.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp318;
  modelica_metatype tmpMeta319;
  static int tmp320 = 0;
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp320)
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp315 = GreaterEq((data->simulationInfo->integerParameter[31] /* thermalZoneFourElements.volAir.dynBal.massDynamics PARAM */),1);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp316 = LessEq((data->simulationInfo->integerParameter[31] /* thermalZoneFourElements.volAir.dynBal.massDynamics PARAM */),4);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp315 && tmp316))
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp318 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[31] /* thermalZoneFourElements.volAir.dynBal.massDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta319 = stringAppend(MMC_REFSTRINGLIT(tmp317),tmp318);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.dynBal.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",18,3,20,74,0};
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta319));
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",18,3,20,74,0};
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta319));
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp320 = 1;
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5060 OMC_FILE
  TRACE_POP
}

/*
equation index: 1492
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.dynBal.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.dynBal.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.volAir.dynBal.energyDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1492(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1492};
  modelica_boolean tmp321;
  modelica_boolean tmp322;
  static const MMC_DEFSTRINGLIT(tmp323,201,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.dynBal.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp324;
  modelica_metatype tmpMeta325;
  static int tmp326 = 0;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp326)
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp321 = GreaterEq((data->simulationInfo->integerParameter[30] /* thermalZoneFourElements.volAir.dynBal.energyDynamics PARAM */),1);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp322 = LessEq((data->simulationInfo->integerParameter[30] /* thermalZoneFourElements.volAir.dynBal.energyDynamics PARAM */),4);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp321 && tmp322))
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp324 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[30] /* thermalZoneFourElements.volAir.dynBal.energyDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta325 = stringAppend(MMC_REFSTRINGLIT(tmp323),tmp324);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.dynBal.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",15,3,17,88,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta325));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",15,3,17,88,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta325));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp326 = 1;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5123 OMC_FILE
  TRACE_POP
}

/*
equation index: 1493
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.m_flow_small >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.m_flow_small, has value: " + String(thermalZoneFourElements.volAir.m_flow_small, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1493(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1493};
  modelica_boolean tmp327;
  static const MMC_DEFSTRINGLIT(tmp328,98,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.m_flow_small, has value: ");
  modelica_string tmp329;
  modelica_metatype tmpMeta330;
  static int tmp331 = 0;
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  if(!tmp331)
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  {
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    tmp327 = GreaterEq((data->simulationInfo->realParameter[382] /* thermalZoneFourElements.volAir.m_flow_small PARAM */),0.0);
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    if(!tmp327)
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    {
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp329 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[382] /* thermalZoneFourElements.volAir.m_flow_small PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmpMeta330 = stringAppend(MMC_REFSTRINGLIT(tmp328),tmp329);
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      {
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.m_flow_small >= 0.0)";
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",25,3,27,40,0};
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta330));
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        } else {
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",25,3,27,40,0};
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta330));
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        }
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      }
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp331 = 1;
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    }
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  }
#line 5183 OMC_FILE
  TRACE_POP
}

/*
equation index: 1494
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.m_flow_nominal >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.m_flow_nominal, has value: " + String(thermalZoneFourElements.volAir.m_flow_nominal, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1494(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1494};
  modelica_boolean tmp332;
  static const MMC_DEFSTRINGLIT(tmp333,100,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.m_flow_nominal, has value: ");
  modelica_string tmp334;
  modelica_metatype tmpMeta335;
  static int tmp336 = 0;
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  if(!tmp336)
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  {
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    tmp332 = GreaterEq((data->simulationInfo->realParameter[381] /* thermalZoneFourElements.volAir.m_flow_nominal PARAM */),0.0);
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    if(!tmp332)
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    {
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp334 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[381] /* thermalZoneFourElements.volAir.m_flow_nominal PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmpMeta335 = stringAppend(MMC_REFSTRINGLIT(tmp333),tmp334);
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      {
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.m_flow_nominal >= 0.0)";
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",20,3,21,76,0};
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta335));
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        } else {
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",20,3,21,76,0};
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta335));
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        }
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      }
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp336 = 1;
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    }
#line 20 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  }
#line 5243 OMC_FILE
  TRACE_POP
}

/*
equation index: 1495
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.mSenFac >= 1.0, "Variable violating min constraint: 1.0 <= thermalZoneFourElements.volAir.mSenFac, has value: " + String(thermalZoneFourElements.volAir.mSenFac, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1495(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1495};
  modelica_boolean tmp337;
  static const MMC_DEFSTRINGLIT(tmp338,93,"Variable violating min constraint: 1.0 <= thermalZoneFourElements.volAir.mSenFac, has value: ");
  modelica_string tmp339;
  modelica_metatype tmpMeta340;
  static int tmp341 = 0;
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp341)
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp337 = GreaterEq((data->simulationInfo->realParameter[380] /* thermalZoneFourElements.volAir.mSenFac PARAM */),1.0);
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!tmp337)
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp339 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[380] /* thermalZoneFourElements.volAir.mSenFac PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta340 = stringAppend(MMC_REFSTRINGLIT(tmp338),tmp339);
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.mSenFac >= 1.0)";
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",47,3,49,39,0};
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta340));
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",47,3,49,39,0};
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta340));
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp341 = 1;
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5303 OMC_FILE
  TRACE_POP
}

/*
equation index: 1496
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.X_start[1] >= 0.0 and thermalZoneFourElements.volAir.X_start[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.X_start[1] <= 1.0, has value: " + String(thermalZoneFourElements.volAir.X_start[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1496(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1496};
  modelica_boolean tmp342;
  modelica_boolean tmp343;
  static const MMC_DEFSTRINGLIT(tmp344,107,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.X_start[1] <= 1.0, has value: ");
  modelica_string tmp345;
  modelica_metatype tmpMeta346;
  static int tmp347 = 0;
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp347)
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp342 = GreaterEq((data->simulationInfo->realParameter[367] /* thermalZoneFourElements.volAir.X_start[1] PARAM */),0.0);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp343 = LessEq((data->simulationInfo->realParameter[367] /* thermalZoneFourElements.volAir.X_start[1] PARAM */),1.0);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp342 && tmp343))
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp345 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[367] /* thermalZoneFourElements.volAir.X_start[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta346 = stringAppend(MMC_REFSTRINGLIT(tmp344),tmp345);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.X_start[1] >= 0.0 and thermalZoneFourElements.volAir.X_start[1] <= 1.0)";
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",35,3,38,69,0};
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta346));
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",35,3,38,69,0};
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta346));
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp347 = 1;
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5366 OMC_FILE
  TRACE_POP
}

/*
equation index: 1497
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.T_start >= 273.15 and thermalZoneFourElements.volAir.T_start <= 373.15, "Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.T_start <= 373.15, has value: " + String(thermalZoneFourElements.volAir.T_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1497(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1497};
  modelica_boolean tmp348;
  modelica_boolean tmp349;
  static const MMC_DEFSTRINGLIT(tmp350,110,"Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.T_start <= 373.15, has value: ");
  modelica_string tmp351;
  modelica_metatype tmpMeta352;
  static int tmp353 = 0;
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp353)
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp348 = GreaterEq((data->simulationInfo->realParameter[365] /* thermalZoneFourElements.volAir.T_start PARAM */),273.15);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp349 = LessEq((data->simulationInfo->realParameter[365] /* thermalZoneFourElements.volAir.T_start PARAM */),373.15);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp348 && tmp349))
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp351 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[365] /* thermalZoneFourElements.volAir.T_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta352 = stringAppend(MMC_REFSTRINGLIT(tmp350),tmp351);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.T_start >= 273.15 and thermalZoneFourElements.volAir.T_start <= 373.15)";
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",32,3,34,47,0};
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta352));
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",32,3,34,47,0};
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta352));
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp353 = 1;
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5429 OMC_FILE
  TRACE_POP
}

/*
equation index: 1498
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.p_start >= 0.0 and thermalZoneFourElements.volAir.p_start <= 100000000.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.p_start <= 100000000.0, has value: " + String(thermalZoneFourElements.volAir.p_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1498(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1498};
  modelica_boolean tmp354;
  modelica_boolean tmp355;
  static const MMC_DEFSTRINGLIT(tmp356,112,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.p_start <= 100000000.0, has value: ");
  modelica_string tmp357;
  modelica_metatype tmpMeta358;
  static int tmp359 = 0;
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp359)
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp354 = GreaterEq((data->simulationInfo->realParameter[383] /* thermalZoneFourElements.volAir.p_start PARAM */),0.0);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp355 = LessEq((data->simulationInfo->realParameter[383] /* thermalZoneFourElements.volAir.p_start PARAM */),100000000.0);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp354 && tmp355))
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp357 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[383] /* thermalZoneFourElements.volAir.p_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta358 = stringAppend(MMC_REFSTRINGLIT(tmp356),tmp357);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.p_start >= 0.0 and thermalZoneFourElements.volAir.p_start <= 100000000.0)";
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",29,3,31,47,0};
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta358));
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",29,3,31,47,0};
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta358));
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp359 = 1;
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5492 OMC_FILE
  TRACE_POP
}

/*
equation index: 1499
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.volAir.traceDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1499(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1499};
  modelica_boolean tmp360;
  modelica_boolean tmp361;
  static const MMC_DEFSTRINGLIT(tmp362,193,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp363;
  modelica_metatype tmpMeta364;
  static int tmp365 = 0;
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp365)
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp360 = GreaterEq((data->simulationInfo->integerParameter[39] /* thermalZoneFourElements.volAir.traceDynamics PARAM */),1);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp361 = LessEq((data->simulationInfo->integerParameter[39] /* thermalZoneFourElements.volAir.traceDynamics PARAM */),4);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp360 && tmp361))
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp363 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[39] /* thermalZoneFourElements.volAir.traceDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta364 = stringAppend(MMC_REFSTRINGLIT(tmp362),tmp363);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",24,3,26,88,0};
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta364));
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",24,3,26,88,0};
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta364));
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp365 = 1;
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5555 OMC_FILE
  TRACE_POP
}

/*
equation index: 1500
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.volAir.substanceDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1500(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1500};
  modelica_boolean tmp366;
  modelica_boolean tmp367;
  static const MMC_DEFSTRINGLIT(tmp368,197,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp369;
  modelica_metatype tmpMeta370;
  static int tmp371 = 0;
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp371)
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp366 = GreaterEq((data->simulationInfo->integerParameter[38] /* thermalZoneFourElements.volAir.substanceDynamics PARAM */),1);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp367 = LessEq((data->simulationInfo->integerParameter[38] /* thermalZoneFourElements.volAir.substanceDynamics PARAM */),4);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp366 && tmp367))
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp369 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[38] /* thermalZoneFourElements.volAir.substanceDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta370 = stringAppend(MMC_REFSTRINGLIT(tmp368),tmp369);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",21,3,23,88,0};
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta370));
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",21,3,23,88,0};
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta370));
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp371 = 1;
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5618 OMC_FILE
  TRACE_POP
}

/*
equation index: 1501
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.volAir.massDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1501(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1501};
  modelica_boolean tmp372;
  modelica_boolean tmp373;
  static const MMC_DEFSTRINGLIT(tmp374,192,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp375;
  modelica_metatype tmpMeta376;
  static int tmp377 = 0;
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp377)
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp372 = GreaterEq((data->simulationInfo->integerParameter[36] /* thermalZoneFourElements.volAir.massDynamics PARAM */),1);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp373 = LessEq((data->simulationInfo->integerParameter[36] /* thermalZoneFourElements.volAir.massDynamics PARAM */),4);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp372 && tmp373))
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp375 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[36] /* thermalZoneFourElements.volAir.massDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta376 = stringAppend(MMC_REFSTRINGLIT(tmp374),tmp375);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",18,3,20,74,0};
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta376));
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",18,3,20,74,0};
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta376));
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp377 = 1;
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5681 OMC_FILE
  TRACE_POP
}

/*
equation index: 1502
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.volAir.energyDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1502(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1502};
  modelica_boolean tmp378;
  modelica_boolean tmp379;
  static const MMC_DEFSTRINGLIT(tmp380,194,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.volAir.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp381;
  modelica_metatype tmpMeta382;
  static int tmp383 = 0;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp383)
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp378 = GreaterEq((data->simulationInfo->integerParameter[35] /* thermalZoneFourElements.volAir.energyDynamics PARAM */),1);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp379 = LessEq((data->simulationInfo->integerParameter[35] /* thermalZoneFourElements.volAir.energyDynamics PARAM */),4);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp378 && tmp379))
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp381 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[35] /* thermalZoneFourElements.volAir.energyDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta382 = stringAppend(MMC_REFSTRINGLIT(tmp380),tmp381);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.volAir.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",15,3,17,88,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta382));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",15,3,17,88,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta382));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp383 = 1;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 5744 OMC_FILE
  TRACE_POP
}

/*
equation index: 1503
type: ALGORITHM

  assert(thermalZoneFourElements.CExt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.CExt[1], has value: " + String(thermalZoneFourElements.CExt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1503(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1503};
  modelica_boolean tmp384;
  static const MMC_DEFSTRINGLIT(tmp385,88,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.CExt[1], has value: ");
  modelica_string tmp386;
  modelica_metatype tmpMeta387;
  static int tmp388 = 0;
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  if(!tmp388)
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  {
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    tmp384 = GreaterEq((data->simulationInfo->realParameter[256] /* thermalZoneFourElements.CExt[1] PARAM */),1e-60);
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    if(!tmp384)
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    {
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp386 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[256] /* thermalZoneFourElements.CExt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmpMeta387 = stringAppend(MMC_REFSTRINGLIT(tmp385),tmp386);
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      {
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        const char* assert_cond = "(thermalZoneFourElements.CExt[1] >= 1e-60)";
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",48,3,50,48,0};
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta387));
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        } else {
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",48,3,50,48,0};
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta387));
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        }
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      }
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp388 = 1;
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    }
#line 48 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  }
#line 5804 OMC_FILE
  TRACE_POP
}

/*
equation index: 1504
type: ALGORITHM

  assert(thermalZoneFourElements.RExtRem >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RExtRem, has value: " + String(thermalZoneFourElements.RExtRem, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1504(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1504};
  modelica_boolean tmp389;
  static const MMC_DEFSTRINGLIT(tmp390,88,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RExtRem, has value: ");
  modelica_string tmp391;
  modelica_metatype tmpMeta392;
  static int tmp393 = 0;
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  if(!tmp393)
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  {
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    tmp389 = GreaterEq((data->simulationInfo->realParameter[261] /* thermalZoneFourElements.RExtRem PARAM */),1e-60);
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    if(!tmp389)
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    {
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp391 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[261] /* thermalZoneFourElements.RExtRem PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmpMeta392 = stringAppend(MMC_REFSTRINGLIT(tmp390),tmp391);
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      {
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        const char* assert_cond = "(thermalZoneFourElements.RExtRem >= 1e-60)";
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",45,3,47,48,0};
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta392));
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        } else {
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",45,3,47,48,0};
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta392));
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        }
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      }
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp393 = 1;
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    }
#line 45 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  }
#line 5864 OMC_FILE
  TRACE_POP
}

/*
equation index: 1505
type: ALGORITHM

  assert(thermalZoneFourElements.RExt[1] >= 1e-60, "Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RExt[1], has value: " + String(thermalZoneFourElements.RExt[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1505(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1505};
  modelica_boolean tmp394;
  static const MMC_DEFSTRINGLIT(tmp395,88,"Variable violating min constraint: 1e-60 <= thermalZoneFourElements.RExt[1], has value: ");
  modelica_string tmp396;
  modelica_metatype tmpMeta397;
  static int tmp398 = 0;
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  if(!tmp398)
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  {
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    tmp394 = GreaterEq((data->simulationInfo->realParameter[260] /* thermalZoneFourElements.RExt[1] PARAM */),1e-60);
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    if(!tmp394)
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    {
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp396 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[260] /* thermalZoneFourElements.RExt[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmpMeta397 = stringAppend(MMC_REFSTRINGLIT(tmp395),tmp396);
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      {
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        const char* assert_cond = "(thermalZoneFourElements.RExt[1] >= 1e-60)";
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",42,3,44,48,0};
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta397));
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        } else {
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",42,3,44,48,0};
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta397));
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        }
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      }
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp398 = 1;
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    }
#line 42 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  }
#line 5924 OMC_FILE
  TRACE_POP
}

/*
equation index: 1506
type: ALGORITHM

  assert(thermalZoneFourElements.nExt >= 1, "Variable violating min constraint: 1 <= thermalZoneFourElements.nExt, has value: " + String(thermalZoneFourElements.nExt, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1506};
  modelica_boolean tmp399;
  static const MMC_DEFSTRINGLIT(tmp400,81,"Variable violating min constraint: 1 <= thermalZoneFourElements.nExt, has value: ");
  modelica_string tmp401;
  modelica_metatype tmpMeta402;
  static int tmp403 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  if(!tmp403)
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    tmp399 = GreaterEq((data->simulationInfo->integerParameter[16] /* thermalZoneFourElements.nExt PARAM */),((modelica_integer) 1));
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    if(!tmp399)
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp401 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[16] /* thermalZoneFourElements.nExt PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmpMeta402 = stringAppend(MMC_REFSTRINGLIT(tmp400),tmp401);
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        const char* assert_cond = "(thermalZoneFourElements.nExt >= 1)";
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",40,3,41,47,0};
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta402));
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",40,3,41,47,0};
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta402));
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp403 = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  }
#line 5984 OMC_FILE
  TRACE_POP
}

/*
equation index: 1507
type: ALGORITHM

  assert(thermalZoneFourElements.nOrientations >= 1, "Variable violating min constraint: 1 <= thermalZoneFourElements.nOrientations, has value: " + String(thermalZoneFourElements.nOrientations, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1507(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1507};
  modelica_boolean tmp404;
  static const MMC_DEFSTRINGLIT(tmp405,90,"Variable violating min constraint: 1 <= thermalZoneFourElements.nOrientations, has value: ");
  modelica_string tmp406;
  modelica_metatype tmpMeta407;
  static int tmp408 = 0;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  if(!tmp408)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    tmp404 = GreaterEq((data->simulationInfo->integerParameter[19] /* thermalZoneFourElements.nOrientations PARAM */),((modelica_integer) 1));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    if(!tmp404)
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp406 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[19] /* thermalZoneFourElements.nOrientations PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmpMeta407 = stringAppend(MMC_REFSTRINGLIT(tmp405),tmp406);
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        const char* assert_cond = "(thermalZoneFourElements.nOrientations >= 1)";
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",11,3,12,45,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta407));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        } else {
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",11,3,12,45,0};
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta407));
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp408 = 1;
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    }
#line 11 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  }
#line 6044 OMC_FILE
  TRACE_POP
}

/*
equation index: 1508
type: ALGORITHM

  assert(thermalZoneFourElements.mSenFac >= 1.0, "Variable violating min constraint: 1.0 <= thermalZoneFourElements.mSenFac, has value: " + String(thermalZoneFourElements.mSenFac, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1508(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1508};
  modelica_boolean tmp409;
  static const MMC_DEFSTRINGLIT(tmp410,86,"Variable violating min constraint: 1.0 <= thermalZoneFourElements.mSenFac, has value: ");
  modelica_string tmp411;
  modelica_metatype tmpMeta412;
  static int tmp413 = 0;
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp413)
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp409 = GreaterEq((data->simulationInfo->realParameter[308] /* thermalZoneFourElements.mSenFac PARAM */),1.0);
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!tmp409)
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp411 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[308] /* thermalZoneFourElements.mSenFac PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta412 = stringAppend(MMC_REFSTRINGLIT(tmp410),tmp411);
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.mSenFac >= 1.0)";
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",47,3,49,39,0};
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta412));
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",47,3,49,39,0};
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta412));
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp413 = 1;
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 6104 OMC_FILE
  TRACE_POP
}

/*
equation index: 1509
type: ALGORITHM

  assert(thermalZoneFourElements.X_start[1] >= 0.0 and thermalZoneFourElements.X_start[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.X_start[1] <= 1.0, has value: " + String(thermalZoneFourElements.X_start[1], "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1509(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1509};
  modelica_boolean tmp414;
  modelica_boolean tmp415;
  static const MMC_DEFSTRINGLIT(tmp416,100,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.X_start[1] <= 1.0, has value: ");
  modelica_string tmp417;
  modelica_metatype tmpMeta418;
  static int tmp419 = 0;
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp419)
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp414 = GreaterEq((data->simulationInfo->realParameter[270] /* thermalZoneFourElements.X_start[1] PARAM */),0.0);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp415 = LessEq((data->simulationInfo->realParameter[270] /* thermalZoneFourElements.X_start[1] PARAM */),1.0);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp414 && tmp415))
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp417 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[270] /* thermalZoneFourElements.X_start[1] PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta418 = stringAppend(MMC_REFSTRINGLIT(tmp416),tmp417);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.X_start[1] >= 0.0 and thermalZoneFourElements.X_start[1] <= 1.0)";
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",35,3,38,69,0};
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta418));
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",35,3,38,69,0};
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta418));
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp419 = 1;
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 6167 OMC_FILE
  TRACE_POP
}

/*
equation index: 1510
type: ALGORITHM

  assert(thermalZoneFourElements.T_start >= 273.15 and thermalZoneFourElements.T_start <= 373.15, "Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.T_start <= 373.15, has value: " + String(thermalZoneFourElements.T_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1510(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1510};
  modelica_boolean tmp420;
  modelica_boolean tmp421;
  static const MMC_DEFSTRINGLIT(tmp422,103,"Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.T_start <= 373.15, has value: ");
  modelica_string tmp423;
  modelica_metatype tmpMeta424;
  static int tmp425 = 0;
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp425)
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp420 = GreaterEq((data->simulationInfo->realParameter[268] /* thermalZoneFourElements.T_start PARAM */),273.15);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp421 = LessEq((data->simulationInfo->realParameter[268] /* thermalZoneFourElements.T_start PARAM */),373.15);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp420 && tmp421))
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp423 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[268] /* thermalZoneFourElements.T_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta424 = stringAppend(MMC_REFSTRINGLIT(tmp422),tmp423);
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.T_start >= 273.15 and thermalZoneFourElements.T_start <= 373.15)";
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",32,3,34,47,0};
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta424));
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",32,3,34,47,0};
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta424));
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp425 = 1;
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 6230 OMC_FILE
  TRACE_POP
}

/*
equation index: 1511
type: ALGORITHM

  assert(thermalZoneFourElements.p_start >= 0.0 and thermalZoneFourElements.p_start <= 100000000.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.p_start <= 100000000.0, has value: " + String(thermalZoneFourElements.p_start, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1511(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1511};
  modelica_boolean tmp426;
  modelica_boolean tmp427;
  static const MMC_DEFSTRINGLIT(tmp428,105,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.p_start <= 100000000.0, has value: ");
  modelica_string tmp429;
  modelica_metatype tmpMeta430;
  static int tmp431 = 0;
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp431)
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp426 = GreaterEq((data->simulationInfo->realParameter[309] /* thermalZoneFourElements.p_start PARAM */),0.0);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp427 = LessEq((data->simulationInfo->realParameter[309] /* thermalZoneFourElements.p_start PARAM */),100000000.0);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp426 && tmp427))
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp429 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[309] /* thermalZoneFourElements.p_start PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta430 = stringAppend(MMC_REFSTRINGLIT(tmp428),tmp429);
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.p_start >= 0.0 and thermalZoneFourElements.p_start <= 100000000.0)";
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",29,3,31,47,0};
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta430));
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",29,3,31,47,0};
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta430));
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp431 = 1;
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 29 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 6293 OMC_FILE
  TRACE_POP
}

/*
equation index: 1512
type: ALGORITHM

  assert(thermalZoneFourElements.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.traceDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1512(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1512};
  modelica_boolean tmp432;
  modelica_boolean tmp433;
  static const MMC_DEFSTRINGLIT(tmp434,186,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp435;
  modelica_metatype tmpMeta436;
  static int tmp437 = 0;
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp437)
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp432 = GreaterEq((data->simulationInfo->integerParameter[29] /* thermalZoneFourElements.traceDynamics PARAM */),1);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp433 = LessEq((data->simulationInfo->integerParameter[29] /* thermalZoneFourElements.traceDynamics PARAM */),4);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp432 && tmp433))
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp435 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[29] /* thermalZoneFourElements.traceDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta436 = stringAppend(MMC_REFSTRINGLIT(tmp434),tmp435);
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.traceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.traceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",24,3,26,88,0};
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta436));
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",24,3,26,88,0};
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta436));
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp437 = 1;
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 24 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 6356 OMC_FILE
  TRACE_POP
}

/*
equation index: 1513
type: ALGORITHM

  assert(thermalZoneFourElements.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.substanceDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1513(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1513};
  modelica_boolean tmp438;
  modelica_boolean tmp439;
  static const MMC_DEFSTRINGLIT(tmp440,190,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp441;
  modelica_metatype tmpMeta442;
  static int tmp443 = 0;
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp443)
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp438 = GreaterEq((data->simulationInfo->integerParameter[23] /* thermalZoneFourElements.substanceDynamics PARAM */),1);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp439 = LessEq((data->simulationInfo->integerParameter[23] /* thermalZoneFourElements.substanceDynamics PARAM */),4);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp438 && tmp439))
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp441 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[23] /* thermalZoneFourElements.substanceDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta442 = stringAppend(MMC_REFSTRINGLIT(tmp440),tmp441);
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.substanceDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.substanceDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",21,3,23,88,0};
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta442));
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",21,3,23,88,0};
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta442));
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp443 = 1;
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 6419 OMC_FILE
  TRACE_POP
}

/*
equation index: 1514
type: ALGORITHM

  assert(thermalZoneFourElements.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.massDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1514(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1514};
  modelica_boolean tmp444;
  modelica_boolean tmp445;
  static const MMC_DEFSTRINGLIT(tmp446,185,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp447;
  modelica_metatype tmpMeta448;
  static int tmp449 = 0;
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp449)
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp444 = GreaterEq((data->simulationInfo->integerParameter[15] /* thermalZoneFourElements.massDynamics PARAM */),1);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp445 = LessEq((data->simulationInfo->integerParameter[15] /* thermalZoneFourElements.massDynamics PARAM */),4);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp444 && tmp445))
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp447 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[15] /* thermalZoneFourElements.massDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta448 = stringAppend(MMC_REFSTRINGLIT(tmp446),tmp447);
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.massDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.massDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",18,3,20,74,0};
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta448));
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",18,3,20,74,0};
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta448));
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp449 = 1;
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 18 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 6482 OMC_FILE
  TRACE_POP
}

/*
equation index: 1515
type: ALGORITHM

  assert(thermalZoneFourElements.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, "Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: " + String(thermalZoneFourElements.energyDynamics, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1515(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1515};
  modelica_boolean tmp450;
  modelica_boolean tmp451;
  static const MMC_DEFSTRINGLIT(tmp452,187,"Variable violating min/max constraint: Modelica.Fluid.Types.Dynamics.DynamicFreeInitial <= thermalZoneFourElements.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState, has value: ");
  modelica_string tmp453;
  modelica_metatype tmpMeta454;
  static int tmp455 = 0;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  if(!tmp455)
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp450 = GreaterEq((data->simulationInfo->integerParameter[11] /* thermalZoneFourElements.energyDynamics PARAM */),1);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    tmp451 = LessEq((data->simulationInfo->integerParameter[11] /* thermalZoneFourElements.energyDynamics PARAM */),4);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    if(!(tmp450 && tmp451))
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp453 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[11] /* thermalZoneFourElements.energyDynamics PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmpMeta454 = stringAppend(MMC_REFSTRINGLIT(tmp452),tmp453);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        const char* assert_cond = "(thermalZoneFourElements.energyDynamics >= Modelica.Fluid.Types.Dynamics.DynamicFreeInitial and thermalZoneFourElements.energyDynamics <= Modelica.Fluid.Types.Dynamics.SteadyState)";
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",15,3,17,88,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta454));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        } else {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo",15,3,17,88,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta454));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
        }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
      tmp455 = 1;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
    }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/LumpedVolumeDeclarations.mo"
  }
#line 6545 OMC_FILE
  TRACE_POP
}

/*
equation index: 1516
type: ALGORITHM

  assert(corGDouPan.n >= 1, "Variable violating min constraint: 1 <= corGDouPan.n, has value: " + String(corGDouPan.n, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1516(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1516};
  modelica_boolean tmp456;
  static const MMC_DEFSTRINGLIT(tmp457,65,"Variable violating min constraint: 1 <= corGDouPan.n, has value: ");
  modelica_string tmp458;
  modelica_metatype tmpMeta459;
  static int tmp460 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
  if(!tmp460)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
    tmp456 = GreaterEq((data->simulationInfo->integerParameter[0] /* corGDouPan.n PARAM */),((modelica_integer) 1));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
    if(!tmp456)
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
      tmp458 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* corGDouPan.n PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
      tmpMeta459 = stringAppend(MMC_REFSTRINGLIT(tmp457),tmp458);
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
        const char* assert_cond = "(corGDouPan.n >= 1)";
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo",5,3,5,66,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta459));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo",5,3,5,66,0};
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta459));
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
      tmp460 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/BaseClasses/PartialCorrectionG.mo"
  }
#line 6605 OMC_FILE
  TRACE_POP
}

/*
equation index: 1517
type: ALGORITHM

  assert(HDifTil[2].rho >= 0.0 and HDifTil[2].rho <= 1.0, "Variable violating min/max constraint: 0.0 <= HDifTil[2].rho <= 1.0, has value: " + String(HDifTil[2].rho, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1517(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1517};
  modelica_boolean tmp461;
  modelica_boolean tmp462;
  static const MMC_DEFSTRINGLIT(tmp463,80,"Variable violating min/max constraint: 0.0 <= HDifTil[2].rho <= 1.0, has value: ");
  modelica_string tmp464;
  modelica_metatype tmpMeta465;
  static int tmp466 = 0;
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
  if(!tmp466)
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
  {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    tmp461 = GreaterEq((data->simulationInfo->realParameter[32] /* HDifTil[2].rho PARAM */),0.0);
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    tmp462 = LessEq((data->simulationInfo->realParameter[32] /* HDifTil[2].rho PARAM */),1.0);
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    if(!(tmp461 && tmp462))
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      tmp464 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[32] /* HDifTil[2].rho PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      tmpMeta465 = stringAppend(MMC_REFSTRINGLIT(tmp463),tmp464);
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
        const char* assert_cond = "(HDifTil[2].rho >= 0.0 and HDifTil[2].rho <= 1.0)";
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo",7,3,7,76,0};
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta465));
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
        } else {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo",7,3,7,76,0};
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta465));
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
        }
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      }
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      tmp466 = 1;
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    }
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
  }
#line 6668 OMC_FILE
  TRACE_POP
}

/*
equation index: 1518
type: ALGORITHM

  assert(HDifTil[1].rho >= 0.0 and HDifTil[1].rho <= 1.0, "Variable violating min/max constraint: 0.0 <= HDifTil[1].rho <= 1.0, has value: " + String(HDifTil[1].rho, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1518};
  modelica_boolean tmp467;
  modelica_boolean tmp468;
  static const MMC_DEFSTRINGLIT(tmp469,80,"Variable violating min/max constraint: 0.0 <= HDifTil[1].rho <= 1.0, has value: ");
  modelica_string tmp470;
  modelica_metatype tmpMeta471;
  static int tmp472 = 0;
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
  if(!tmp472)
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
  {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    tmp467 = GreaterEq((data->simulationInfo->realParameter[31] /* HDifTil[1].rho PARAM */),0.0);
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    tmp468 = LessEq((data->simulationInfo->realParameter[31] /* HDifTil[1].rho PARAM */),1.0);
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    if(!(tmp467 && tmp468))
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      tmp470 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[31] /* HDifTil[1].rho PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      tmpMeta471 = stringAppend(MMC_REFSTRINGLIT(tmp469),tmp470);
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
        const char* assert_cond = "(HDifTil[1].rho >= 0.0 and HDifTil[1].rho <= 1.0)";
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo",7,3,7,76,0};
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta471));
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
        } else {
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo",7,3,7,76,0};
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta471));
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
        }
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      }
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
      tmp472 = 1;
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
    }
#line 7 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffusePerez.mo"
  }
#line 6731 OMC_FILE
  TRACE_POP
}

/*
equation index: 1519
type: ALGORITHM

  assert(weaDat.cheTemBlaSky.TMax >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemBlaSky.TMax, has value: " + String(weaDat.cheTemBlaSky.TMax, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1519(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1519};
  modelica_boolean tmp473;
  static const MMC_DEFSTRINGLIT(tmp474,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemBlaSky.TMax, has value: ");
  modelica_string tmp475;
  modelica_metatype tmpMeta476;
  static int tmp477 = 0;
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  if(!tmp477)
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp473 = GreaterEq((data->simulationInfo->realParameter[407] /* weaDat.cheTemBlaSky.TMax PARAM */),0.0);
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    if(!tmp473)
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp475 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[407] /* weaDat.cheTemBlaSky.TMax PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmpMeta476 = stringAppend(MMC_REFSTRINGLIT(tmp474),tmp475);
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemBlaSky.TMax >= 0.0)";
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",8,3,9,34,0};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta476));
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        } else {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",8,3,9,34,0};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta476));
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        }
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      }
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp477 = 1;
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    }
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  }
#line 6791 OMC_FILE
  TRACE_POP
}

/*
equation index: 1520
type: ALGORITHM

  assert(weaDat.cheTemBlaSky.TMin >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemBlaSky.TMin, has value: " + String(weaDat.cheTemBlaSky.TMin, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1520(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1520};
  modelica_boolean tmp478;
  static const MMC_DEFSTRINGLIT(tmp479,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemBlaSky.TMin, has value: ");
  modelica_string tmp480;
  modelica_metatype tmpMeta481;
  static int tmp482 = 0;
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  if(!tmp482)
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp478 = GreaterEq((data->simulationInfo->realParameter[408] /* weaDat.cheTemBlaSky.TMin PARAM */),0.0);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    if(!tmp478)
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp480 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[408] /* weaDat.cheTemBlaSky.TMin PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmpMeta481 = stringAppend(MMC_REFSTRINGLIT(tmp479),tmp480);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemBlaSky.TMin >= 0.0)";
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",6,3,7,34,0};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta481));
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        } else {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",6,3,7,34,0};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta481));
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        }
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      }
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp482 = 1;
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    }
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  }
#line 6851 OMC_FILE
  TRACE_POP
}

/*
equation index: 1521
type: ALGORITHM

  assert(weaDat.datRea30Min.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and weaDat.datRea30Min.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= weaDat.datRea30Min.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(weaDat.datRea30Min.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1521(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1521};
  modelica_boolean tmp483;
  modelica_boolean tmp484;
  static const MMC_DEFSTRINGLIT(tmp485,192,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= weaDat.datRea30Min.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp486;
  modelica_metatype tmpMeta487;
  static int tmp488 = 0;
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  if(!tmp488)
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp483 = GreaterEq((data->simulationInfo->integerParameter[84] /* weaDat.datRea30Min.extrapolation PARAM */),1);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp484 = LessEq((data->simulationInfo->integerParameter[84] /* weaDat.datRea30Min.extrapolation PARAM */),4);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    if(!(tmp483 && tmp484))
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp486 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[84] /* weaDat.datRea30Min.extrapolation PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmpMeta487 = stringAppend(MMC_REFSTRINGLIT(tmp485),tmp486);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        const char* assert_cond = "(weaDat.datRea30Min.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and weaDat.datRea30Min.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation)";
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",32,5,34,61,0};
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta487));
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        } else {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",32,5,34,61,0};
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta487));
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp488 = 1;
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  }
#line 6914 OMC_FILE
  TRACE_POP
}

/*
equation index: 1522
type: ALGORITHM

  assert(weaDat.datRea30Min.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and weaDat.datRea30Min.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= weaDat.datRea30Min.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: " + String(weaDat.datRea30Min.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1522(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1522};
  modelica_boolean tmp489;
  modelica_boolean tmp490;
  static const MMC_DEFSTRINGLIT(tmp491,197,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= weaDat.datRea30Min.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: ");
  modelica_string tmp492;
  modelica_metatype tmpMeta493;
  static int tmp494 = 0;
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  if(!tmp494)
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp489 = GreaterEq((data->simulationInfo->integerParameter[86] /* weaDat.datRea30Min.smoothness PARAM */),1);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp490 = LessEq((data->simulationInfo->integerParameter[86] /* weaDat.datRea30Min.smoothness PARAM */),6);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    if(!(tmp489 && tmp490))
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp492 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[86] /* weaDat.datRea30Min.smoothness PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmpMeta493 = stringAppend(MMC_REFSTRINGLIT(tmp491),tmp492);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        const char* assert_cond = "(weaDat.datRea30Min.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and weaDat.datRea30Min.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative)";
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",29,5,31,61,0};
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta493));
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        } else {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",29,5,31,61,0};
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta493));
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp494 = 1;
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  }
#line 6977 OMC_FILE
  TRACE_POP
}

/*
equation index: 1523
type: ALGORITHM

  assert(weaDat.TBlaSkyCom.calTSky >= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation and weaDat.TBlaSkyCom.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation <= weaDat.TBlaSkyCom.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover, has value: " + String(weaDat.TBlaSkyCom.calTSky, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1523(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1523};
  modelica_boolean tmp495;
  modelica_boolean tmp496;
  static const MMC_DEFSTRINGLIT(tmp497,249,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation <= weaDat.TBlaSkyCom.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover, has value: ");
  modelica_string tmp498;
  modelica_metatype tmpMeta499;
  static int tmp500 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  if(!tmp500)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp495 = GreaterEq((data->simulationInfo->integerParameter[42] /* weaDat.TBlaSkyCom.calTSky PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp496 = LessEq((data->simulationInfo->integerParameter[42] /* weaDat.TBlaSkyCom.calTSky PARAM */),2);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    if(!(tmp495 && tmp496))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp498 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[42] /* weaDat.TBlaSkyCom.calTSky PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmpMeta499 = stringAppend(MMC_REFSTRINGLIT(tmp497),tmp498);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        const char* assert_cond = "(weaDat.TBlaSkyCom.calTSky >= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation and weaDat.TBlaSkyCom.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo",5,3,9,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta499));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo",5,3,9,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta499));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp500 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 7040 OMC_FILE
  TRACE_POP
}

/*
equation index: 1524
type: ALGORITHM

  assert(weaDat.cheTemDewPoi.TMax >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemDewPoi.TMax, has value: " + String(weaDat.cheTemDewPoi.TMax, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1524(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1524};
  modelica_boolean tmp501;
  static const MMC_DEFSTRINGLIT(tmp502,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemDewPoi.TMax, has value: ");
  modelica_string tmp503;
  modelica_metatype tmpMeta504;
  static int tmp505 = 0;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  if(!tmp505)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp501 = GreaterEq((data->simulationInfo->realParameter[409] /* weaDat.cheTemDewPoi.TMax PARAM */),0.0);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    if(!tmp501)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp503 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[409] /* weaDat.cheTemDewPoi.TMax PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmpMeta504 = stringAppend(MMC_REFSTRINGLIT(tmp502),tmp503);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemDewPoi.TMax >= 0.0)";
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",18,3,19,34,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta504));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        } else {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",18,3,19,34,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta504));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp505 = 1;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  }
#line 7100 OMC_FILE
  TRACE_POP
}

/*
equation index: 1525
type: ALGORITHM

  assert(weaDat.cheTemDewPoi.TMin >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemDewPoi.TMin, has value: " + String(weaDat.cheTemDewPoi.TMin, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1525(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1525};
  modelica_boolean tmp506;
  static const MMC_DEFSTRINGLIT(tmp507,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemDewPoi.TMin, has value: ");
  modelica_string tmp508;
  modelica_metatype tmpMeta509;
  static int tmp510 = 0;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  if(!tmp510)
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp506 = GreaterEq((data->simulationInfo->realParameter[410] /* weaDat.cheTemDewPoi.TMin PARAM */),0.0);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    if(!tmp506)
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp508 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[410] /* weaDat.cheTemDewPoi.TMin PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmpMeta509 = stringAppend(MMC_REFSTRINGLIT(tmp507),tmp508);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemDewPoi.TMin >= 0.0)";
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",16,3,17,34,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta509));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        } else {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",16,3,17,34,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta509));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp510 = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  }
#line 7160 OMC_FILE
  TRACE_POP
}

/*
equation index: 1526
type: ALGORITHM

  assert(weaDat.cheTemDryBul.TMax >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemDryBul.TMax, has value: " + String(weaDat.cheTemDryBul.TMax, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1526(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1526};
  modelica_boolean tmp511;
  static const MMC_DEFSTRINGLIT(tmp512,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemDryBul.TMax, has value: ");
  modelica_string tmp513;
  modelica_metatype tmpMeta514;
  static int tmp515 = 0;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  if(!tmp515)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp511 = GreaterEq((data->simulationInfo->realParameter[411] /* weaDat.cheTemDryBul.TMax PARAM */),0.0);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    if(!tmp511)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp513 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[411] /* weaDat.cheTemDryBul.TMax PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmpMeta514 = stringAppend(MMC_REFSTRINGLIT(tmp512),tmp513);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemDryBul.TMax >= 0.0)";
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",18,3,19,34,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta514));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        } else {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",18,3,19,34,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta514));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp515 = 1;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  }
#line 7220 OMC_FILE
  TRACE_POP
}

/*
equation index: 1527
type: ALGORITHM

  assert(weaDat.cheTemDryBul.TMin >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemDryBul.TMin, has value: " + String(weaDat.cheTemDryBul.TMin, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1527(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1527};
  modelica_boolean tmp516;
  static const MMC_DEFSTRINGLIT(tmp517,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemDryBul.TMin, has value: ");
  modelica_string tmp518;
  modelica_metatype tmpMeta519;
  static int tmp520 = 0;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  if(!tmp520)
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp516 = GreaterEq((data->simulationInfo->realParameter[412] /* weaDat.cheTemDryBul.TMin PARAM */),0.0);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    if(!tmp516)
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp518 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[412] /* weaDat.cheTemDryBul.TMin PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmpMeta519 = stringAppend(MMC_REFSTRINGLIT(tmp517),tmp518);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemDryBul.TMin >= 0.0)";
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",16,3,17,34,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta519));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        } else {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",16,3,17,34,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta519));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp520 = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  }
#line 7280 OMC_FILE
  TRACE_POP
}

/*
equation index: 1528
type: ALGORITHM

  assert(weaDat.souSelRad.datSou >= Buildings.BoundaryConditions.Types.RadiationDataSource.File and weaDat.souSelRad.datSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.RadiationDataSource.File <= weaDat.souSelRad.datSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, has value: " + String(weaDat.souSelRad.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1528(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1528};
  modelica_boolean tmp521;
  modelica_boolean tmp522;
  static const MMC_DEFSTRINGLIT(tmp523,218,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.RadiationDataSource.File <= weaDat.souSelRad.datSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, has value: ");
  modelica_string tmp524;
  modelica_metatype tmpMeta525;
  static int tmp526 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
  if(!tmp526)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    tmp521 = GreaterEq((data->simulationInfo->integerParameter[94] /* weaDat.souSelRad.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    tmp522 = LessEq((data->simulationInfo->integerParameter[94] /* weaDat.souSelRad.datSou PARAM */),4);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    if(!(tmp521 && tmp522))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      tmp524 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[94] /* weaDat.souSelRad.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      tmpMeta525 = stringAppend(MMC_REFSTRINGLIT(tmp523),tmp524);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
        const char* assert_cond = "(weaDat.souSelRad.datSou >= Buildings.BoundaryConditions.Types.RadiationDataSource.File and weaDat.souSelRad.datSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta525));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta525));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      tmp526 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
  }
#line 7343 OMC_FILE
  TRACE_POP
}

/*
equation index: 1529
type: ALGORITHM

  assert(weaDat.horInfRadSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.horInfRadSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.horInfRadSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.horInfRadSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1529(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1529};
  modelica_boolean tmp527;
  modelica_boolean tmp528;
  static const MMC_DEFSTRINGLIT(tmp529,187,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.horInfRadSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp530;
  modelica_metatype tmpMeta531;
  static int tmp532 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp532)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp527 = GreaterEq((data->simulationInfo->integerParameter[87] /* weaDat.horInfRadSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp528 = LessEq((data->simulationInfo->integerParameter[87] /* weaDat.horInfRadSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp527 && tmp528))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp530 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[87] /* weaDat.horInfRadSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta531 = stringAppend(MMC_REFSTRINGLIT(tmp529),tmp530);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.horInfRadSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.horInfRadSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta531));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta531));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp532 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7406 OMC_FILE
  TRACE_POP
}

/*
equation index: 1530
type: ALGORITHM

  assert(weaDat.winDirSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winDirSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winDirSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.winDirSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1530(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1530};
  modelica_boolean tmp533;
  modelica_boolean tmp534;
  static const MMC_DEFSTRINGLIT(tmp535,184,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winDirSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp536;
  modelica_metatype tmpMeta537;
  static int tmp538 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp538)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp533 = GreaterEq((data->simulationInfo->integerParameter[97] /* weaDat.winDirSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp534 = LessEq((data->simulationInfo->integerParameter[97] /* weaDat.winDirSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp533 && tmp534))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp536 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[97] /* weaDat.winDirSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta537 = stringAppend(MMC_REFSTRINGLIT(tmp535),tmp536);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.winDirSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winDirSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta537));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta537));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp538 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7469 OMC_FILE
  TRACE_POP
}

/*
equation index: 1531
type: ALGORITHM

  assert(weaDat.winSpeSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winSpeSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winSpeSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.winSpeSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1531(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1531};
  modelica_boolean tmp539;
  modelica_boolean tmp540;
  static const MMC_DEFSTRINGLIT(tmp541,184,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winSpeSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp542;
  modelica_metatype tmpMeta543;
  static int tmp544 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp544)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp539 = GreaterEq((data->simulationInfo->integerParameter[99] /* weaDat.winSpeSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp540 = LessEq((data->simulationInfo->integerParameter[99] /* weaDat.winSpeSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp539 && tmp540))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp542 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[99] /* weaDat.winSpeSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta543 = stringAppend(MMC_REFSTRINGLIT(tmp541),tmp542);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.winSpeSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winSpeSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta543));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta543));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp544 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7532 OMC_FILE
  TRACE_POP
}

/*
equation index: 1532
type: ALGORITHM

  assert(weaDat.totSkyCovSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.totSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.totSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.totSkyCovSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1532(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1532};
  modelica_boolean tmp545;
  modelica_boolean tmp546;
  static const MMC_DEFSTRINGLIT(tmp547,187,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.totSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp548;
  modelica_metatype tmpMeta549;
  static int tmp550 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp550)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp545 = GreaterEq((data->simulationInfo->integerParameter[95] /* weaDat.totSkyCovSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp546 = LessEq((data->simulationInfo->integerParameter[95] /* weaDat.totSkyCovSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp545 && tmp546))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp548 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[95] /* weaDat.totSkyCovSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta549 = stringAppend(MMC_REFSTRINGLIT(tmp547),tmp548);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.totSkyCovSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.totSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta549));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta549));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp550 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7595 OMC_FILE
  TRACE_POP
}

/*
equation index: 1533
type: ALGORITHM

  assert(weaDat.ceiHeiSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.ceiHeiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.ceiHeiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.ceiHeiSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1533(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1533};
  modelica_boolean tmp551;
  modelica_boolean tmp552;
  static const MMC_DEFSTRINGLIT(tmp553,184,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.ceiHeiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp554;
  modelica_metatype tmpMeta555;
  static int tmp556 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp556)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp551 = GreaterEq((data->simulationInfo->integerParameter[50] /* weaDat.ceiHeiSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp552 = LessEq((data->simulationInfo->integerParameter[50] /* weaDat.ceiHeiSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp551 && tmp552))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp554 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[50] /* weaDat.ceiHeiSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta555 = stringAppend(MMC_REFSTRINGLIT(tmp553),tmp554);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.ceiHeiSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.ceiHeiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta555));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta555));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp556 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7658 OMC_FILE
  TRACE_POP
}

/*
equation index: 1534
type: ALGORITHM

  assert(weaDat.opaSkyCovSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.opaSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.opaSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.opaSkyCovSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1534(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1534};
  modelica_boolean tmp557;
  modelica_boolean tmp558;
  static const MMC_DEFSTRINGLIT(tmp559,187,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.opaSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp560;
  modelica_metatype tmpMeta561;
  static int tmp562 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp562)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp557 = GreaterEq((data->simulationInfo->integerParameter[88] /* weaDat.opaSkyCovSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp558 = LessEq((data->simulationInfo->integerParameter[88] /* weaDat.opaSkyCovSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp557 && tmp558))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp560 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[88] /* weaDat.opaSkyCovSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta561 = stringAppend(MMC_REFSTRINGLIT(tmp559),tmp560);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.opaSkyCovSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.opaSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta561));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta561));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp562 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7721 OMC_FILE
  TRACE_POP
}

/*
equation index: 1535
type: ALGORITHM

  assert(weaDat.relHumSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.relHumSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.relHumSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.relHumSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1535(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1535};
  modelica_boolean tmp563;
  modelica_boolean tmp564;
  static const MMC_DEFSTRINGLIT(tmp565,184,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.relHumSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp566;
  modelica_metatype tmpMeta567;
  static int tmp568 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp568)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp563 = GreaterEq((data->simulationInfo->integerParameter[92] /* weaDat.relHumSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp564 = LessEq((data->simulationInfo->integerParameter[92] /* weaDat.relHumSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp563 && tmp564))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp566 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[92] /* weaDat.relHumSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta567 = stringAppend(MMC_REFSTRINGLIT(tmp565),tmp566);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.relHumSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.relHumSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta567));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta567));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp568 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7784 OMC_FILE
  TRACE_POP
}

/*
equation index: 1536
type: ALGORITHM

  assert(weaDat.TBlaSkySel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TBlaSkySel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TBlaSkySel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TBlaSkySel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1536(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1536};
  modelica_boolean tmp569;
  modelica_boolean tmp570;
  static const MMC_DEFSTRINGLIT(tmp571,185,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TBlaSkySel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp572;
  modelica_metatype tmpMeta573;
  static int tmp574 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp574)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp569 = GreaterEq((data->simulationInfo->integerParameter[43] /* weaDat.TBlaSkySel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp570 = LessEq((data->simulationInfo->integerParameter[43] /* weaDat.TBlaSkySel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp569 && tmp570))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp572 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[43] /* weaDat.TBlaSkySel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta573 = stringAppend(MMC_REFSTRINGLIT(tmp571),tmp572);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.TBlaSkySel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TBlaSkySel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta573));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta573));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp574 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7847 OMC_FILE
  TRACE_POP
}

/*
equation index: 1537
type: ALGORITHM

  assert(weaDat.TDryBulSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDryBulSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDryBulSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TDryBulSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1537(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1537};
  modelica_boolean tmp575;
  modelica_boolean tmp576;
  static const MMC_DEFSTRINGLIT(tmp577,185,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDryBulSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp578;
  modelica_metatype tmpMeta579;
  static int tmp580 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp580)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp575 = GreaterEq((data->simulationInfo->integerParameter[47] /* weaDat.TDryBulSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp576 = LessEq((data->simulationInfo->integerParameter[47] /* weaDat.TDryBulSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp575 && tmp576))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp578 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[47] /* weaDat.TDryBulSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta579 = stringAppend(MMC_REFSTRINGLIT(tmp577),tmp578);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.TDryBulSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDryBulSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta579));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta579));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp580 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7910 OMC_FILE
  TRACE_POP
}

/*
equation index: 1538
type: ALGORITHM

  assert(weaDat.TDewPoiSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDewPoiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDewPoiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TDewPoiSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1538(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1538};
  modelica_boolean tmp581;
  modelica_boolean tmp582;
  static const MMC_DEFSTRINGLIT(tmp583,185,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDewPoiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp584;
  modelica_metatype tmpMeta585;
  static int tmp586 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp586)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp581 = GreaterEq((data->simulationInfo->integerParameter[45] /* weaDat.TDewPoiSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp582 = LessEq((data->simulationInfo->integerParameter[45] /* weaDat.TDewPoiSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp581 && tmp582))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp584 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[45] /* weaDat.TDewPoiSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta585 = stringAppend(MMC_REFSTRINGLIT(tmp583),tmp584);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.TDewPoiSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDewPoiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta585));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta585));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp586 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 7973 OMC_FILE
  TRACE_POP
}

/*
equation index: 1539
type: ALGORITHM

  assert(weaDat.pAtmSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.pAtmSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.pAtmSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.pAtmSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1539(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1539};
  modelica_boolean tmp587;
  modelica_boolean tmp588;
  static const MMC_DEFSTRINGLIT(tmp589,182,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.pAtmSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp590;
  modelica_metatype tmpMeta591;
  static int tmp592 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp592)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp587 = GreaterEq((data->simulationInfo->integerParameter[90] /* weaDat.pAtmSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp588 = LessEq((data->simulationInfo->integerParameter[90] /* weaDat.pAtmSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp587 && tmp588))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp590 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[90] /* weaDat.pAtmSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta591 = stringAppend(MMC_REFSTRINGLIT(tmp589),tmp590);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.pAtmSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.pAtmSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta591));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta591));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp592 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 8036 OMC_FILE
  TRACE_POP
}

/*
equation index: 1540
type: ALGORITHM

  assert(weaDat.datRea.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and weaDat.datRea.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= weaDat.datRea.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(weaDat.datRea.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1540(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1540};
  modelica_boolean tmp593;
  modelica_boolean tmp594;
  static const MMC_DEFSTRINGLIT(tmp595,187,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= weaDat.datRea.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp596;
  modelica_metatype tmpMeta597;
  static int tmp598 = 0;
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  if(!tmp598)
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp593 = GreaterEq((data->simulationInfo->integerParameter[78] /* weaDat.datRea.extrapolation PARAM */),1);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp594 = LessEq((data->simulationInfo->integerParameter[78] /* weaDat.datRea.extrapolation PARAM */),4);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    if(!(tmp593 && tmp594))
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp596 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[78] /* weaDat.datRea.extrapolation PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmpMeta597 = stringAppend(MMC_REFSTRINGLIT(tmp595),tmp596);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        const char* assert_cond = "(weaDat.datRea.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and weaDat.datRea.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation)";
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",32,5,34,61,0};
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta597));
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        } else {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",32,5,34,61,0};
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta597));
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp598 = 1;
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  }
#line 8099 OMC_FILE
  TRACE_POP
}

/*
equation index: 1541
type: ALGORITHM

  assert(weaDat.datRea.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and weaDat.datRea.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= weaDat.datRea.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: " + String(weaDat.datRea.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1541(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1541};
  modelica_boolean tmp599;
  modelica_boolean tmp600;
  static const MMC_DEFSTRINGLIT(tmp601,192,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= weaDat.datRea.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: ");
  modelica_string tmp602;
  modelica_metatype tmpMeta603;
  static int tmp604 = 0;
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  if(!tmp604)
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp599 = GreaterEq((data->simulationInfo->integerParameter[80] /* weaDat.datRea.smoothness PARAM */),1);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp600 = LessEq((data->simulationInfo->integerParameter[80] /* weaDat.datRea.smoothness PARAM */),6);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    if(!(tmp599 && tmp600))
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp602 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[80] /* weaDat.datRea.smoothness PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmpMeta603 = stringAppend(MMC_REFSTRINGLIT(tmp601),tmp602);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        const char* assert_cond = "(weaDat.datRea.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and weaDat.datRea.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative)";
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",29,5,31,61,0};
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta603));
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        } else {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",29,5,31,61,0};
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta603));
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp604 = 1;
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  }
#line 8162 OMC_FILE
  TRACE_POP
}

/*
equation index: 1542
type: ALGORITHM

  assert(weaDat.calTSky >= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation and weaDat.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation <= weaDat.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover, has value: " + String(weaDat.calTSky, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1542(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1542};
  modelica_boolean tmp605;
  modelica_boolean tmp606;
  static const MMC_DEFSTRINGLIT(tmp607,238,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation <= weaDat.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover, has value: ");
  modelica_string tmp608;
  modelica_metatype tmpMeta609;
  static int tmp610 = 0;
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp610)
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp605 = GreaterEq((data->simulationInfo->integerParameter[49] /* weaDat.calTSky PARAM */),1);
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp606 = LessEq((data->simulationInfo->integerParameter[49] /* weaDat.calTSky PARAM */),2);
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp605 && tmp606))
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp608 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[49] /* weaDat.calTSky PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta609 = stringAppend(MMC_REFSTRINGLIT(tmp607),tmp608);
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.calTSky >= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation and weaDat.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover)";
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",218,3,223,53,0};
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta609));
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",218,3,223,53,0};
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta609));
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp610 = 1;
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8225 OMC_FILE
  TRACE_POP
}

/*
equation index: 1543
type: ALGORITHM

  assert(weaDat.opaSkyCov >= 0.0 and weaDat.opaSkyCov <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.opaSkyCov <= 1.0, has value: " + String(weaDat.opaSkyCov, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1543(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1543};
  modelica_boolean tmp611;
  modelica_boolean tmp612;
  static const MMC_DEFSTRINGLIT(tmp613,82,"Variable violating min/max constraint: 0.0 <= weaDat.opaSkyCov <= 1.0, has value: ");
  modelica_string tmp614;
  modelica_metatype tmpMeta615;
  static int tmp616 = 0;
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp616)
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp611 = GreaterEq((data->simulationInfo->realParameter[437] /* weaDat.opaSkyCov PARAM */),0.0);
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp612 = LessEq((data->simulationInfo->realParameter[437] /* weaDat.opaSkyCov PARAM */),1.0);
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp611 && tmp612))
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp614 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[437] /* weaDat.opaSkyCov PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta615 = stringAppend(MMC_REFSTRINGLIT(tmp613),tmp614);
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.opaSkyCov >= 0.0 and weaDat.opaSkyCov <= 1.0)";
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",204,3,209,43,0};
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta615));
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",204,3,209,43,0};
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta615));
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp616 = 1;
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8288 OMC_FILE
  TRACE_POP
}

/*
equation index: 1544
type: ALGORITHM

  assert(weaDat.opaSkyCovSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.opaSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.opaSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.opaSkyCovSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1544(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1544};
  modelica_boolean tmp617;
  modelica_boolean tmp618;
  static const MMC_DEFSTRINGLIT(tmp619,180,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.opaSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp620;
  modelica_metatype tmpMeta621;
  static int tmp622 = 0;
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp622)
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp617 = GreaterEq((data->simulationInfo->integerParameter[89] /* weaDat.opaSkyCovSou PARAM */),1);
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp618 = LessEq((data->simulationInfo->integerParameter[89] /* weaDat.opaSkyCovSou PARAM */),3);
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp617 && tmp618))
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp620 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[89] /* weaDat.opaSkyCovSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta621 = stringAppend(MMC_REFSTRINGLIT(tmp619),tmp620);
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.opaSkyCovSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.opaSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",202,3,203,94,0};
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta621));
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",202,3,203,94,0};
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta621));
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp622 = 1;
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8351 OMC_FILE
  TRACE_POP
}

/*
equation index: 1545
type: ALGORITHM

  assert(weaDat.totSkyCov >= 0.0 and weaDat.totSkyCov <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.totSkyCov <= 1.0, has value: " + String(weaDat.totSkyCov, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1545(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1545};
  modelica_boolean tmp623;
  modelica_boolean tmp624;
  static const MMC_DEFSTRINGLIT(tmp625,82,"Variable violating min/max constraint: 0.0 <= weaDat.totSkyCov <= 1.0, has value: ");
  modelica_string tmp626;
  modelica_metatype tmpMeta627;
  static int tmp628 = 0;
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp628)
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp623 = GreaterEq((data->simulationInfo->realParameter[446] /* weaDat.totSkyCov PARAM */),0.0);
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp624 = LessEq((data->simulationInfo->realParameter[446] /* weaDat.totSkyCov PARAM */),1.0);
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp623 && tmp624))
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp626 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[446] /* weaDat.totSkyCov PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta627 = stringAppend(MMC_REFSTRINGLIT(tmp625),tmp626);
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.totSkyCov >= 0.0 and weaDat.totSkyCov <= 1.0)";
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",188,3,193,43,0};
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta627));
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",188,3,193,43,0};
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta627));
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp628 = 1;
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8414 OMC_FILE
  TRACE_POP
}

/*
equation index: 1546
type: ALGORITHM

  assert(weaDat.totSkyCovSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.totSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.totSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.totSkyCovSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1546(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1546};
  modelica_boolean tmp629;
  modelica_boolean tmp630;
  static const MMC_DEFSTRINGLIT(tmp631,180,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.totSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp632;
  modelica_metatype tmpMeta633;
  static int tmp634 = 0;
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp634)
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp629 = GreaterEq((data->simulationInfo->integerParameter[96] /* weaDat.totSkyCovSou PARAM */),1);
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp630 = LessEq((data->simulationInfo->integerParameter[96] /* weaDat.totSkyCovSou PARAM */),3);
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp629 && tmp630))
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp632 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[96] /* weaDat.totSkyCovSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta633 = stringAppend(MMC_REFSTRINGLIT(tmp631),tmp632);
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.totSkyCovSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.totSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",186,3,187,93,0};
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta633));
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",186,3,187,93,0};
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta633));
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp634 = 1;
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8477 OMC_FILE
  TRACE_POP
}

/*
equation index: 1547
type: ALGORITHM

  assert(weaDat.ceiHeiSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.ceiHeiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.ceiHeiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.ceiHeiSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1547(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1547};
  modelica_boolean tmp635;
  modelica_boolean tmp636;
  static const MMC_DEFSTRINGLIT(tmp637,177,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.ceiHeiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp638;
  modelica_metatype tmpMeta639;
  static int tmp640 = 0;
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp640)
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp635 = GreaterEq((data->simulationInfo->integerParameter[51] /* weaDat.ceiHeiSou PARAM */),1);
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp636 = LessEq((data->simulationInfo->integerParameter[51] /* weaDat.ceiHeiSou PARAM */),3);
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp635 && tmp636))
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp638 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[51] /* weaDat.ceiHeiSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta639 = stringAppend(MMC_REFSTRINGLIT(tmp637),tmp638);
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.ceiHeiSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.ceiHeiSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",170,3,171,92,0};
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta639));
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",170,3,171,92,0};
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta639));
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp640 = 1;
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8540 OMC_FILE
  TRACE_POP
}

/*
equation index: 1548
type: ALGORITHM

  assert(weaDat.HSou >= Buildings.BoundaryConditions.Types.RadiationDataSource.File and weaDat.HSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.RadiationDataSource.File <= weaDat.HSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, has value: " + String(weaDat.HSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1548(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1548};
  modelica_boolean tmp641;
  modelica_boolean tmp642;
  static const MMC_DEFSTRINGLIT(tmp643,206,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.RadiationDataSource.File <= weaDat.HSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, has value: ");
  modelica_string tmp644;
  modelica_metatype tmpMeta645;
  static int tmp646 = 0;
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp646)
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp641 = GreaterEq((data->simulationInfo->integerParameter[41] /* weaDat.HSou PARAM */),1);
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp642 = LessEq((data->simulationInfo->integerParameter[41] /* weaDat.HSou PARAM */),4);
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp641 && tmp642))
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp644 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[41] /* weaDat.HSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta645 = stringAppend(MMC_REFSTRINGLIT(tmp643),tmp644);
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.HSou >= Buildings.BoundaryConditions.Types.RadiationDataSource.File and weaDat.HSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor)";
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",135,4,137,76,0};
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta645));
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",135,4,137,76,0};
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta645));
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp646 = 1;
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8603 OMC_FILE
  TRACE_POP
}

/*
equation index: 1549
type: ALGORITHM

  assert(weaDat.HInfHorSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.HInfHorSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.HInfHorSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.HInfHorSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1549(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1549};
  modelica_boolean tmp647;
  modelica_boolean tmp648;
  static const MMC_DEFSTRINGLIT(tmp649,178,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.HInfHorSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp650;
  modelica_metatype tmpMeta651;
  static int tmp652 = 0;
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp652)
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp647 = GreaterEq((data->simulationInfo->integerParameter[40] /* weaDat.HInfHorSou PARAM */),1);
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp648 = LessEq((data->simulationInfo->integerParameter[40] /* weaDat.HInfHorSou PARAM */),3);
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp647 && tmp648))
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp650 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[40] /* weaDat.HInfHorSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta651 = stringAppend(MMC_REFSTRINGLIT(tmp649),tmp650);
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.HInfHorSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.HInfHorSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",123,3,124,107,0};
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta651));
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",123,3,124,107,0};
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta651));
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp652 = 1;
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8666 OMC_FILE
  TRACE_POP
}

/*
equation index: 1550
type: ALGORITHM

  assert(weaDat.winDirSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winDirSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winDirSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.winDirSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1550(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1550};
  modelica_boolean tmp653;
  modelica_boolean tmp654;
  static const MMC_DEFSTRINGLIT(tmp655,177,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winDirSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp656;
  modelica_metatype tmpMeta657;
  static int tmp658 = 0;
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp658)
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp653 = GreaterEq((data->simulationInfo->integerParameter[98] /* weaDat.winDirSou PARAM */),1);
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp654 = LessEq((data->simulationInfo->integerParameter[98] /* weaDat.winDirSou PARAM */),3);
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp653 && tmp654))
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp656 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[98] /* weaDat.winDirSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta657 = stringAppend(MMC_REFSTRINGLIT(tmp655),tmp656);
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.winDirSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winDirSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",109,3,110,92,0};
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta657));
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",109,3,110,92,0};
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta657));
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp658 = 1;
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8729 OMC_FILE
  TRACE_POP
}

/*
equation index: 1551
type: ALGORITHM

  assert(weaDat.winSpe >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.winSpe, has value: " + String(weaDat.winSpe, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1551(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1551};
  modelica_boolean tmp659;
  static const MMC_DEFSTRINGLIT(tmp660,68,"Variable violating min constraint: 0.0 <= weaDat.winSpe, has value: ");
  modelica_string tmp661;
  modelica_metatype tmpMeta662;
  static int tmp663 = 0;
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp663)
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp659 = GreaterEq((data->simulationInfo->realParameter[453] /* weaDat.winSpe PARAM */),0.0);
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp659)
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp661 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[453] /* weaDat.winSpe PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta662 = stringAppend(MMC_REFSTRINGLIT(tmp660),tmp661);
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.winSpe >= 0.0)";
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",97,3,99,43,0};
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta662));
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",97,3,99,43,0};
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta662));
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp663 = 1;
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8789 OMC_FILE
  TRACE_POP
}

/*
equation index: 1552
type: ALGORITHM

  assert(weaDat.winSpeSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winSpeSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winSpeSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.winSpeSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1552(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1552};
  modelica_boolean tmp664;
  modelica_boolean tmp665;
  static const MMC_DEFSTRINGLIT(tmp666,177,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winSpeSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp667;
  modelica_metatype tmpMeta668;
  static int tmp669 = 0;
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp669)
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp664 = GreaterEq((data->simulationInfo->integerParameter[100] /* weaDat.winSpeSou PARAM */),1);
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp665 = LessEq((data->simulationInfo->integerParameter[100] /* weaDat.winSpeSou PARAM */),3);
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp664 && tmp665))
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp667 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[100] /* weaDat.winSpeSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta668 = stringAppend(MMC_REFSTRINGLIT(tmp666),tmp667);
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.winSpeSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winSpeSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",95,3,96,88,0};
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta668));
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",95,3,96,88,0};
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta668));
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp669 = 1;
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8852 OMC_FILE
  TRACE_POP
}

/*
equation index: 1553
type: ALGORITHM

  assert(weaDat.relHum >= 0.0 and weaDat.relHum <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.relHum <= 1.0, has value: " + String(weaDat.relHum, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1553(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1553};
  modelica_boolean tmp670;
  modelica_boolean tmp671;
  static const MMC_DEFSTRINGLIT(tmp672,79,"Variable violating min/max constraint: 0.0 <= weaDat.relHum <= 1.0, has value: ");
  modelica_string tmp673;
  modelica_metatype tmpMeta674;
  static int tmp675 = 0;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp675)
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp670 = GreaterEq((data->simulationInfo->realParameter[441] /* weaDat.relHum PARAM */),0.0);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp671 = LessEq((data->simulationInfo->realParameter[441] /* weaDat.relHum PARAM */),1.0);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp670 && tmp671))
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp673 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[441] /* weaDat.relHum PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta674 = stringAppend(MMC_REFSTRINGLIT(tmp672),tmp673);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.relHum >= 0.0 and weaDat.relHum <= 1.0)";
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",81,3,85,43,0};
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta674));
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",81,3,85,43,0};
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta674));
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp675 = 1;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8915 OMC_FILE
  TRACE_POP
}

/*
equation index: 1554
type: ALGORITHM

  assert(weaDat.relHumSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.relHumSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.relHumSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.relHumSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1554(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1554};
  modelica_boolean tmp676;
  modelica_boolean tmp677;
  static const MMC_DEFSTRINGLIT(tmp678,177,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.relHumSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp679;
  modelica_metatype tmpMeta680;
  static int tmp681 = 0;
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp681)
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp676 = GreaterEq((data->simulationInfo->integerParameter[93] /* weaDat.relHumSou PARAM */),1);
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp677 = LessEq((data->simulationInfo->integerParameter[93] /* weaDat.relHumSou PARAM */),3);
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp676 && tmp677))
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp679 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[93] /* weaDat.relHumSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta680 = stringAppend(MMC_REFSTRINGLIT(tmp678),tmp679);
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.relHumSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.relHumSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",79,3,80,95,0};
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta680));
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",79,3,80,95,0};
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta680));
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp681 = 1;
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 8978 OMC_FILE
  TRACE_POP
}

/*
equation index: 1555
type: ALGORITHM

  assert(weaDat.TBlaSky >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.TBlaSky, has value: " + String(weaDat.TBlaSky, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1555(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1555};
  modelica_boolean tmp682;
  static const MMC_DEFSTRINGLIT(tmp683,69,"Variable violating min constraint: 0.0 <= weaDat.TBlaSky, has value: ");
  modelica_string tmp684;
  modelica_metatype tmpMeta685;
  static int tmp686 = 0;
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp686)
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp682 = GreaterEq((data->simulationInfo->realParameter[394] /* weaDat.TBlaSky PARAM */),0.0);
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp682)
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp684 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[394] /* weaDat.TBlaSky PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta685 = stringAppend(MMC_REFSTRINGLIT(tmp683),tmp684);
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TBlaSky >= 0.0)";
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",66,3,68,43,0};
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta685));
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",66,3,68,43,0};
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta685));
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp686 = 1;
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 9038 OMC_FILE
  TRACE_POP
}

/*
equation index: 1556
type: ALGORITHM

  assert(weaDat.TBlaSkySou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TBlaSkySou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TBlaSkySou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TBlaSkySou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1556(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1556};
  modelica_boolean tmp687;
  modelica_boolean tmp688;
  static const MMC_DEFSTRINGLIT(tmp689,178,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TBlaSkySou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp690;
  modelica_metatype tmpMeta691;
  static int tmp692 = 0;
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp692)
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp687 = GreaterEq((data->simulationInfo->integerParameter[44] /* weaDat.TBlaSkySou PARAM */),1);
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp688 = LessEq((data->simulationInfo->integerParameter[44] /* weaDat.TBlaSkySou PARAM */),3);
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp687 && tmp688))
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp690 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[44] /* weaDat.TBlaSkySou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta691 = stringAppend(MMC_REFSTRINGLIT(tmp689),tmp690);
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TBlaSkySou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TBlaSkySou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",64,3,65,104,0};
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta691));
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",64,3,65,104,0};
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta691));
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp692 = 1;
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 9101 OMC_FILE
  TRACE_POP
}

/*
equation index: 1557
type: ALGORITHM

  assert(weaDat.TDewPoi >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.TDewPoi, has value: " + String(weaDat.TDewPoi, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1557(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1557};
  modelica_boolean tmp693;
  static const MMC_DEFSTRINGLIT(tmp694,69,"Variable violating min constraint: 0.0 <= weaDat.TDewPoi, has value: ");
  modelica_string tmp695;
  modelica_metatype tmpMeta696;
  static int tmp697 = 0;
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp697)
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp693 = GreaterEq((data->simulationInfo->realParameter[396] /* weaDat.TDewPoi PARAM */),0.0);
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp693)
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp695 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[396] /* weaDat.TDewPoi PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta696 = stringAppend(MMC_REFSTRINGLIT(tmp694),tmp695);
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TDewPoi >= 0.0)";
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",52,3,54,43,0};
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta696));
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",52,3,54,43,0};
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta696));
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp697 = 1;
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 9161 OMC_FILE
  TRACE_POP
}

/*
equation index: 1558
type: ALGORITHM

  assert(weaDat.TDewPoiSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDewPoiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDewPoiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TDewPoiSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1558(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1558};
  modelica_boolean tmp698;
  modelica_boolean tmp699;
  static const MMC_DEFSTRINGLIT(tmp700,178,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDewPoiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp701;
  modelica_metatype tmpMeta702;
  static int tmp703 = 0;
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp703)
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp698 = GreaterEq((data->simulationInfo->integerParameter[46] /* weaDat.TDewPoiSou PARAM */),1);
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp699 = LessEq((data->simulationInfo->integerParameter[46] /* weaDat.TDewPoiSou PARAM */),3);
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp698 && tmp699))
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp701 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[46] /* weaDat.TDewPoiSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta702 = stringAppend(MMC_REFSTRINGLIT(tmp700),tmp701);
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TDewPoiSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDewPoiSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",49,3,51,75,0};
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta702));
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",49,3,51,75,0};
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta702));
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp703 = 1;
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 9224 OMC_FILE
  TRACE_POP
}

/*
equation index: 1559
type: ALGORITHM

  assert(weaDat.TDryBul >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.TDryBul, has value: " + String(weaDat.TDryBul, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1559(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1559};
  modelica_boolean tmp704;
  static const MMC_DEFSTRINGLIT(tmp705,69,"Variable violating min constraint: 0.0 <= weaDat.TDryBul, has value: ");
  modelica_string tmp706;
  modelica_metatype tmpMeta707;
  static int tmp708 = 0;
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp708)
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp704 = GreaterEq((data->simulationInfo->realParameter[398] /* weaDat.TDryBul PARAM */),0.0);
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp704)
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp706 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[398] /* weaDat.TDryBul PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta707 = stringAppend(MMC_REFSTRINGLIT(tmp705),tmp706);
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TDryBul >= 0.0)";
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",37,3,39,43,0};
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta707));
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",37,3,39,43,0};
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta707));
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp708 = 1;
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 9284 OMC_FILE
  TRACE_POP
}

/*
equation index: 1560
type: ALGORITHM

  assert(weaDat.TDryBulSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDryBulSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDryBulSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TDryBulSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1560(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1560};
  modelica_boolean tmp709;
  modelica_boolean tmp710;
  static const MMC_DEFSTRINGLIT(tmp711,178,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDryBulSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp712;
  modelica_metatype tmpMeta713;
  static int tmp714 = 0;
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp714)
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp709 = GreaterEq((data->simulationInfo->integerParameter[48] /* weaDat.TDryBulSou PARAM */),1);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp710 = LessEq((data->simulationInfo->integerParameter[48] /* weaDat.TDryBulSou PARAM */),3);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp709 && tmp710))
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp712 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[48] /* weaDat.TDryBulSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta713 = stringAppend(MMC_REFSTRINGLIT(tmp711),tmp712);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TDryBulSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDryBulSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",34,3,36,75,0};
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta713));
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",34,3,36,75,0};
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta713));
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp714 = 1;
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 9347 OMC_FILE
  TRACE_POP
}

/*
equation index: 1561
type: ALGORITHM

  assert(weaDat.pAtmSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.pAtmSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.pAtmSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.pAtmSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1561(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1561};
  modelica_boolean tmp715;
  modelica_boolean tmp716;
  static const MMC_DEFSTRINGLIT(tmp717,175,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.pAtmSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp718;
  modelica_metatype tmpMeta719;
  static int tmp720 = 0;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp720)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp715 = GreaterEq((data->simulationInfo->integerParameter[91] /* weaDat.pAtmSou PARAM */),1);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp716 = LessEq((data->simulationInfo->integerParameter[91] /* weaDat.pAtmSou PARAM */),3);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp715 && tmp716))
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp718 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[91] /* weaDat.pAtmSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta719 = stringAppend(MMC_REFSTRINGLIT(tmp717),tmp718);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.pAtmSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.pAtmSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",18,3,20,75,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta719));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",18,3,20,75,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta719));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp720 = 1;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 9410 OMC_FILE
  TRACE_POP
}
OMC_DISABLE_OPT
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_791(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_792(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_793(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_794(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_795(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_796(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_797(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_798(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_799(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_800(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_801(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_802(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_803(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_804(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_805(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_806(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_807(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_808(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_809(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_810(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_811(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_812(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_813(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_814(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_815(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_816(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_817(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_818(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_819(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_820(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_821(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_822(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_823(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_824(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_825(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_826(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_827(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_828(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_829(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_830(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_831(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_832(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_833(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_834(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_835(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_836(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_837(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_838(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_839(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_840(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_841(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_842(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_864(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_865(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_866(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_867(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_880(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_881(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1275(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1276(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1277(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1278(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1279(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1280(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1281(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1282(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1283(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1284(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1285(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1286(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1294(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1295(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1298(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1299(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1300(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1301(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1334(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1335(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1366(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1367(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1395(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_402(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_401(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_400(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_399(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_398(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_397(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_396(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_395(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_394(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_393(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_392(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_391(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_390(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_389(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_388(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_387(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_386(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_385(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_384(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_383(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_382(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_381(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_14(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_13(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_12(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_11(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_10(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_9(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_8(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_7(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_6(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_5(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_4(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_3(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1432(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1433(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1434(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1435(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1436(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1437(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1438(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1439(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1440(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1441(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1442(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1443(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1444(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1445(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1446(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1447(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1448(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1449(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1450(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1451(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1452(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1453(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1454(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1455(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1456(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1457(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1458(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1459(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1460(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1461(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1462(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1463(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1464(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1465(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1466(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1467(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1468(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1469(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1470(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1471(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1472(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1473(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1474(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1475(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1476(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1477(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1478(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1479(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1480(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1481(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1482(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1483(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1484(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1485(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1486(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1487(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1488(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1489(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1490(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1491(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1492(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1493(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1494(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1495(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1496(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1497(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1498(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1499(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1500(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1501(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1502(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1503(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1504(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1505(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1506(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1507(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1508(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1509(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1510(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1511(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1512(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1513(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1514(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1515(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1516(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1517(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1518(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1519(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1520(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1521(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1522(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1523(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1524(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1525(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1526(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1527(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1528(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1529(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1530(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1531(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1532(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1533(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1534(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1535(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1536(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1537(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1538(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1539(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1540(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1541(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1542(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1543(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1544(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1545(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1546(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1547(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1548(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1549(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1550(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1551(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1552(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1553(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1554(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1555(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1556(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1557(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1558(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1559(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1560(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1561(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->integerParameter[0] /* corGDouPan.n PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[1] /* eqAirTemp.n PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[1].time_unvarying = 1;
  (data->simulationInfo->integerParameter[2] /* eqAirTempVDI.n PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[2].time_unvarying = 1;
  (data->simulationInfo->integerParameter[3] /* intGai.columns[1] PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[3].time_unvarying = 1;
  (data->simulationInfo->integerParameter[4] /* intGai.columns[2] PARAM */) = ((modelica_integer) 3);
  data->modelData->integerParameterData[4].time_unvarying = 1;
  (data->simulationInfo->integerParameter[5] /* intGai.columns[3] PARAM */) = ((modelica_integer) 4);
  data->modelData->integerParameterData[5].time_unvarying = 1;
  (data->simulationInfo->integerParameter[7] /* intGai.nout PARAM */) = ((modelica_integer) 3);
  data->modelData->integerParameterData[7].time_unvarying = 1;
  (data->simulationInfo->integerParameter[10] /* thermalZoneFourElements.dimension PARAM */) = ((modelica_integer) 5);
  data->modelData->integerParameterData[10].time_unvarying = 1;
  (data->simulationInfo->integerParameter[12] /* thermalZoneFourElements.extWallRC.n PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[12].time_unvarying = 1;
  (data->simulationInfo->integerParameter[13] /* thermalZoneFourElements.floorRC.n PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[13].time_unvarying = 1;
  (data->simulationInfo->integerParameter[14] /* thermalZoneFourElements.intWallRC.n PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[14].time_unvarying = 1;
  (data->simulationInfo->integerParameter[16] /* thermalZoneFourElements.nExt PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[16].time_unvarying = 1;
  (data->simulationInfo->integerParameter[17] /* thermalZoneFourElements.nFloor PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[17].time_unvarying = 1;
  (data->simulationInfo->integerParameter[18] /* thermalZoneFourElements.nInt PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[18].time_unvarying = 1;
  (data->simulationInfo->integerParameter[19] /* thermalZoneFourElements.nOrientations PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[19].time_unvarying = 1;
  (data->simulationInfo->integerParameter[20] /* thermalZoneFourElements.nPorts PARAM */) = ((modelica_integer) 0);
  data->modelData->integerParameterData[20].time_unvarying = 1;
  (data->simulationInfo->integerParameter[21] /* thermalZoneFourElements.nRoof PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[21].time_unvarying = 1;
  (data->simulationInfo->integerParameter[22] /* thermalZoneFourElements.roofRC.n PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[22].time_unvarying = 1;
  (data->simulationInfo->integerParameter[24] /* thermalZoneFourElements.sumSolRad.nin PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[24].time_unvarying = 1;
  (data->simulationInfo->integerParameter[25] /* thermalZoneFourElements.thermSplitterIntGains.nIn PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[25].time_unvarying = 1;
  (data->simulationInfo->integerParameter[26] /* thermalZoneFourElements.thermSplitterIntGains.nOut PARAM */) = ((modelica_integer) 5);
  data->modelData->integerParameterData[26].time_unvarying = 1;
  (data->simulationInfo->integerParameter[27] /* thermalZoneFourElements.thermSplitterSolRad.nIn PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[27].time_unvarying = 1;
  (data->simulationInfo->integerParameter[28] /* thermalZoneFourElements.thermSplitterSolRad.nOut PARAM */) = ((modelica_integer) 5);
  data->modelData->integerParameterData[28].time_unvarying = 1;
  (data->simulationInfo->integerParameter[32] /* thermalZoneFourElements.volAir.dynBal.nPorts PARAM */) = ((modelica_integer) 0);
  data->modelData->integerParameterData[32].time_unvarying = 1;
  (data->simulationInfo->integerParameter[37] /* thermalZoneFourElements.volAir.nPorts PARAM */) = ((modelica_integer) 0);
  data->modelData->integerParameterData[37].time_unvarying = 1;
  (data->simulationInfo->integerParameter[52] /* weaDat.datRea.columns[1] PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[52].time_unvarying = 1;
  (data->simulationInfo->integerParameter[53] /* weaDat.datRea.columns[2] PARAM */) = ((modelica_integer) 3);
  data->modelData->integerParameterData[53].time_unvarying = 1;
  (data->simulationInfo->integerParameter[54] /* weaDat.datRea.columns[3] PARAM */) = ((modelica_integer) 4);
  data->modelData->integerParameterData[54].time_unvarying = 1;
  (data->simulationInfo->integerParameter[55] /* weaDat.datRea.columns[4] PARAM */) = ((modelica_integer) 5);
  data->modelData->integerParameterData[55].time_unvarying = 1;
  (data->simulationInfo->integerParameter[56] /* weaDat.datRea.columns[5] PARAM */) = ((modelica_integer) 6);
  data->modelData->integerParameterData[56].time_unvarying = 1;
  (data->simulationInfo->integerParameter[57] /* weaDat.datRea.columns[6] PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[57].time_unvarying = 1;
  (data->simulationInfo->integerParameter[58] /* weaDat.datRea.columns[7] PARAM */) = ((modelica_integer) 12);
  data->modelData->integerParameterData[58].time_unvarying = 1;
  (data->simulationInfo->integerParameter[59] /* weaDat.datRea.columns[8] PARAM */) = ((modelica_integer) 13);
  data->modelData->integerParameterData[59].time_unvarying = 1;
  (data->simulationInfo->integerParameter[60] /* weaDat.datRea.columns[9] PARAM */) = ((modelica_integer) 14);
  data->modelData->integerParameterData[60].time_unvarying = 1;
  (data->simulationInfo->integerParameter[61] /* weaDat.datRea.columns[10] PARAM */) = ((modelica_integer) 15);
  data->modelData->integerParameterData[61].time_unvarying = 1;
  (data->simulationInfo->integerParameter[62] /* weaDat.datRea.columns[11] PARAM */) = ((modelica_integer) 16);
  data->modelData->integerParameterData[62].time_unvarying = 1;
  (data->simulationInfo->integerParameter[63] /* weaDat.datRea.columns[12] PARAM */) = ((modelica_integer) 17);
  data->modelData->integerParameterData[63].time_unvarying = 1;
  (data->simulationInfo->integerParameter[64] /* weaDat.datRea.columns[13] PARAM */) = ((modelica_integer) 18);
  data->modelData->integerParameterData[64].time_unvarying = 1;
  (data->simulationInfo->integerParameter[65] /* weaDat.datRea.columns[14] PARAM */) = ((modelica_integer) 19);
  data->modelData->integerParameterData[65].time_unvarying = 1;
  (data->simulationInfo->integerParameter[66] /* weaDat.datRea.columns[15] PARAM */) = ((modelica_integer) 20);
  data->modelData->integerParameterData[66].time_unvarying = 1;
  (data->simulationInfo->integerParameter[67] /* weaDat.datRea.columns[16] PARAM */) = ((modelica_integer) 21);
  data->modelData->integerParameterData[67].time_unvarying = 1;
  (data->simulationInfo->integerParameter[68] /* weaDat.datRea.columns[17] PARAM */) = ((modelica_integer) 22);
  data->modelData->integerParameterData[68].time_unvarying = 1;
  (data->simulationInfo->integerParameter[69] /* weaDat.datRea.columns[18] PARAM */) = ((modelica_integer) 23);
  data->modelData->integerParameterData[69].time_unvarying = 1;
  (data->simulationInfo->integerParameter[70] /* weaDat.datRea.columns[19] PARAM */) = ((modelica_integer) 24);
  data->modelData->integerParameterData[70].time_unvarying = 1;
  (data->simulationInfo->integerParameter[71] /* weaDat.datRea.columns[20] PARAM */) = ((modelica_integer) 25);
  data->modelData->integerParameterData[71].time_unvarying = 1;
  (data->simulationInfo->integerParameter[72] /* weaDat.datRea.columns[21] PARAM */) = ((modelica_integer) 26);
  data->modelData->integerParameterData[72].time_unvarying = 1;
  (data->simulationInfo->integerParameter[73] /* weaDat.datRea.columns[22] PARAM */) = ((modelica_integer) 27);
  data->modelData->integerParameterData[73].time_unvarying = 1;
  (data->simulationInfo->integerParameter[74] /* weaDat.datRea.columns[23] PARAM */) = ((modelica_integer) 28);
  data->modelData->integerParameterData[74].time_unvarying = 1;
  (data->simulationInfo->integerParameter[75] /* weaDat.datRea.columns[24] PARAM */) = ((modelica_integer) 29);
  data->modelData->integerParameterData[75].time_unvarying = 1;
  (data->simulationInfo->integerParameter[76] /* weaDat.datRea.columns[25] PARAM */) = ((modelica_integer) 30);
  data->modelData->integerParameterData[76].time_unvarying = 1;
  (data->simulationInfo->integerParameter[77] /* weaDat.datRea.columns[26] PARAM */) = ((modelica_integer) 8);
  data->modelData->integerParameterData[77].time_unvarying = 1;
  (data->simulationInfo->integerParameter[79] /* weaDat.datRea.nout PARAM */) = ((modelica_integer) 26);
  data->modelData->integerParameterData[79].time_unvarying = 1;
  (data->simulationInfo->integerParameter[81] /* weaDat.datRea30Min.columns[1] PARAM */) = ((modelica_integer) 9);
  data->modelData->integerParameterData[81].time_unvarying = 1;
  (data->simulationInfo->integerParameter[82] /* weaDat.datRea30Min.columns[2] PARAM */) = ((modelica_integer) 10);
  data->modelData->integerParameterData[82].time_unvarying = 1;
  (data->simulationInfo->integerParameter[83] /* weaDat.datRea30Min.columns[3] PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[83].time_unvarying = 1;
  (data->simulationInfo->integerParameter[85] /* weaDat.datRea30Min.nout PARAM */) = ((modelica_integer) 3);
  data->modelData->integerParameterData[85].time_unvarying = 1;
  (data->simulationInfo->realParameter[3] /* HDifTil[1].HDifTil.rho PARAM */) = 0.2;
  data->modelData->realParameterData[3].time_unvarying = 1;
  (data->simulationInfo->realParameter[4] /* HDifTil[2].HDifTil.rho PARAM */) = 0.2;
  data->modelData->realParameterData[4].time_unvarying = 1;
  (data->simulationInfo->realParameter[5] /* HDifTil[1].HDifTil.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[5].time_unvarying = 1;
  (data->simulationInfo->realParameter[6] /* HDifTil[2].HDifTil.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[6].time_unvarying = 1;
  (data->simulationInfo->realParameter[7] /* HDifTil[1].add.k1 PARAM */) = 1.0;
  data->modelData->realParameterData[7].time_unvarying = 1;
  (data->simulationInfo->realParameter[8] /* HDifTil[2].add.k1 PARAM */) = 1.0;
  data->modelData->realParameterData[8].time_unvarying = 1;
  (data->simulationInfo->realParameter[9] /* HDifTil[1].add.k2 PARAM */) = 1.0;
  data->modelData->realParameterData[9].time_unvarying = 1;
  (data->simulationInfo->realParameter[10] /* HDifTil[2].add.k2 PARAM */) = 1.0;
  data->modelData->realParameterData[10].time_unvarying = 1;
  (data->simulationInfo->realParameter[11] /* HDifTil[1].azi PARAM */) = 3.1415926535898;
  data->modelData->realParameterData[11].time_unvarying = 1;
  (data->simulationInfo->realParameter[12] /* HDifTil[2].azi PARAM */) = 4.7123889803847;
  data->modelData->realParameterData[12].time_unvarying = 1;
  (data->simulationInfo->realParameter[13] /* HDifTil[1].incAng.azi PARAM */) = 3.1415926535898;
  data->modelData->realParameterData[13].time_unvarying = 1;
  (data->simulationInfo->realParameter[14] /* HDifTil[2].incAng.azi PARAM */) = 4.7123889803847;
  data->modelData->realParameterData[14].time_unvarying = 1;
  (data->simulationInfo->realParameter[15] /* HDifTil[1].incAng.incAng.azi PARAM */) = 3.1415926535898;
  data->modelData->realParameterData[15].time_unvarying = 1;
  (data->simulationInfo->realParameter[16] /* HDifTil[2].incAng.incAng.azi PARAM */) = 4.7123889803847;
  data->modelData->realParameterData[16].time_unvarying = 1;
  (data->simulationInfo->realParameter[19] /* HDifTil[1].incAng.incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[19].time_unvarying = 1;
  (data->simulationInfo->realParameter[20] /* HDifTil[2].incAng.incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[20].time_unvarying = 1;
  (data->simulationInfo->realParameter[21] /* HDifTil[1].incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[21].time_unvarying = 1;
  (data->simulationInfo->realParameter[22] /* HDifTil[2].incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[22].time_unvarying = 1;
  (data->simulationInfo->realParameter[31] /* HDifTil[1].rho PARAM */) = 0.2;
  data->modelData->realParameterData[31].time_unvarying = 1;
  (data->simulationInfo->realParameter[32] /* HDifTil[2].rho PARAM */) = 0.2;
  data->modelData->realParameterData[32].time_unvarying = 1;
  (data->simulationInfo->realParameter[33] /* HDifTil[1].til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[33].time_unvarying = 1;
  (data->simulationInfo->realParameter[34] /* HDifTil[2].til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[34].time_unvarying = 1;
  (data->simulationInfo->realParameter[41] /* HDirTil[1].azi PARAM */) = 3.1415926535898;
  data->modelData->realParameterData[41].time_unvarying = 1;
  (data->simulationInfo->realParameter[42] /* HDirTil[2].azi PARAM */) = 4.7123889803847;
  data->modelData->realParameterData[42].time_unvarying = 1;
  (data->simulationInfo->realParameter[43] /* HDirTil[1].incAng.azi PARAM */) = 3.1415926535898;
  data->modelData->realParameterData[43].time_unvarying = 1;
  (data->simulationInfo->realParameter[44] /* HDirTil[2].incAng.azi PARAM */) = 4.7123889803847;
  data->modelData->realParameterData[44].time_unvarying = 1;
  (data->simulationInfo->realParameter[45] /* HDirTil[1].incAng.incAng.azi PARAM */) = 3.1415926535898;
  data->modelData->realParameterData[45].time_unvarying = 1;
  (data->simulationInfo->realParameter[46] /* HDirTil[2].incAng.incAng.azi PARAM */) = 4.7123889803847;
  data->modelData->realParameterData[46].time_unvarying = 1;
  (data->simulationInfo->realParameter[49] /* HDirTil[1].incAng.incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[49].time_unvarying = 1;
  (data->simulationInfo->realParameter[50] /* HDirTil[2].incAng.incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[50].time_unvarying = 1;
  (data->simulationInfo->realParameter[51] /* HDirTil[1].incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[51].time_unvarying = 1;
  (data->simulationInfo->realParameter[52] /* HDirTil[2].incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[52].time_unvarying = 1;
  (data->simulationInfo->realParameter[59] /* HDirTil[1].til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[59].time_unvarying = 1;
  (data->simulationInfo->realParameter[60] /* HDirTil[2].til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[60].time_unvarying = 1;
  (data->simulationInfo->realParameter[67] /* TSoil.k PARAM */) = 283.15;
  data->modelData->realParameterData[67].time_unvarying = 1;
  (data->simulationInfo->realParameter[68] /* const[1].k PARAM */) = 0.0;
  data->modelData->realParameterData[68].time_unvarying = 1;
  (data->simulationInfo->realParameter[69] /* const[2].k PARAM */) = 0.0;
  data->modelData->realParameterData[69].time_unvarying = 1;
  (data->simulationInfo->realParameter[70] /* const1.k PARAM */) = 0.0;
  data->modelData->realParameterData[70].time_unvarying = 1;
  (data->simulationInfo->realParameter[71] /* corGDouPan.A0 PARAM */) = 0.918;
  data->modelData->realParameterData[71].time_unvarying = 1;
  (data->simulationInfo->realParameter[72] /* corGDouPan.A1 PARAM */) = 0.000221;
  data->modelData->realParameterData[72].time_unvarying = 1;
  (data->simulationInfo->realParameter[73] /* corGDouPan.A2 PARAM */) = -2.75e-05;
  data->modelData->realParameterData[73].time_unvarying = 1;
  (data->simulationInfo->realParameter[74] /* corGDouPan.A3 PARAM */) = -3.82e-07;
  data->modelData->realParameterData[74].time_unvarying = 1;
  (data->simulationInfo->realParameter[75] /* corGDouPan.A4 PARAM */) = 5.83e-08;
  data->modelData->realParameterData[75].time_unvarying = 1;
  (data->simulationInfo->realParameter[76] /* corGDouPan.A5 PARAM */) = -1.15e-09;
  data->modelData->realParameterData[76].time_unvarying = 1;
  (data->simulationInfo->realParameter[77] /* corGDouPan.A6 PARAM */) = 4.74e-12;
  data->modelData->realParameterData[77].time_unvarying = 1;
  (data->simulationInfo->realParameter[78] /* corGDouPan.CorG_diff PARAM */) = 0.8629849850504174;
  data->modelData->realParameterData[78].time_unvarying = 1;
  (data->simulationInfo->realParameter[79] /* corGDouPan.CorG_gr PARAM */) = 0.8629849850504174;
  data->modelData->realParameterData[79].time_unvarying = 1;
  (data->simulationInfo->realParameter[80] /* corGDouPan.Q21_diff PARAM */) = 0.008890159918415507;
  data->modelData->realParameterData[80].time_unvarying = 1;
  (data->simulationInfo->realParameter[81] /* corGDouPan.Q22_diff PARAM */) = 0.05358159593041274;
  data->modelData->realParameterData[81].time_unvarying = 1;
  (data->simulationInfo->realParameter[82] /* corGDouPan.Qsek2_diff PARAM */) = 0.06247175584882825;
  data->modelData->realParameterData[82].time_unvarying = 1;
  (data->simulationInfo->realParameter[83] /* corGDouPan.Ta1_diff PARAM */) = 0.75852;
  data->modelData->realParameterData[83].time_unvarying = 1;
  (data->simulationInfo->realParameter[84] /* corGDouPan.Ta2_diff PARAM */) = 0.5879600273836714;
  data->modelData->realParameterData[84].time_unvarying = 1;
  (data->simulationInfo->realParameter[85] /* corGDouPan.Ta_diff PARAM */) = 0.84;
  data->modelData->realParameterData[85].time_unvarying = 1;
  (data->simulationInfo->realParameter[86] /* corGDouPan.Tai_diff PARAM */) = 0.903;
  data->modelData->realParameterData[86].time_unvarying = 1;
  (data->simulationInfo->realParameter[87] /* corGDouPan.UWin PARAM */) = 2.1;
  data->modelData->realParameterData[87].time_unvarying = 1;
  (data->simulationInfo->realParameter[88] /* corGDouPan.XN2_diff PARAM */) = 0.9785573229531053;
  data->modelData->realParameterData[88].time_unvarying = 1;
  (data->simulationInfo->realParameter[89] /* corGDouPan.a1_diff PARAM */) = 0.0950468171250291;
  data->modelData->realParameterData[89].time_unvarying = 1;
  (data->simulationInfo->realParameter[90] /* corGDouPan.g_dir0 PARAM */) = 0.7537;
  data->modelData->realParameterData[90].time_unvarying = 1;
  (data->simulationInfo->realParameter[91] /* corGDouPan.rho_11_diff PARAM */) = 0.08695652173913046;
  data->modelData->realParameterData[91].time_unvarying = 1;
  (data->simulationInfo->realParameter[92] /* corGDouPan.rho_1_diff PARAM */) = 0.1464331828749709;
  data->modelData->realParameterData[92].time_unvarying = 1;
  (data->simulationInfo->realParameter[93] /* corGDouPan.rho_T1_diff PARAM */) = 0.16;
  data->modelData->realParameterData[93].time_unvarying = 1;
  (data->simulationInfo->realParameter[94] /* eqAirTemp.TGro PARAM */) = 285.15;
  data->modelData->realParameterData[94].time_unvarying = 1;
  (data->simulationInfo->realParameter[95] /* eqAirTemp.aExt PARAM */) = 0.7;
  data->modelData->realParameterData[95].time_unvarying = 1;
  (data->simulationInfo->realParameter[96] /* eqAirTemp.hConWallOut PARAM */) = 20.0;
  data->modelData->realParameterData[96].time_unvarying = 1;
  (data->simulationInfo->realParameter[97] /* eqAirTemp.hConWinOut PARAM */) = 20.0;
  data->modelData->realParameterData[97].time_unvarying = 1;
  (data->simulationInfo->realParameter[98] /* eqAirTemp.hRad PARAM */) = 5.0;
  data->modelData->realParameterData[98].time_unvarying = 1;
  (data->simulationInfo->realParameter[99] /* eqAirTemp.wfGro PARAM */) = 0.0;
  data->modelData->realParameterData[99].time_unvarying = 1;
  (data->simulationInfo->realParameter[100] /* eqAirTemp.wfWall[1] PARAM */) = 0.3043478260869566;
  data->modelData->realParameterData[100].time_unvarying = 1;
  (data->simulationInfo->realParameter[101] /* eqAirTemp.wfWall[2] PARAM */) = 0.6956521739130435;
  data->modelData->realParameterData[101].time_unvarying = 1;
  (data->simulationInfo->realParameter[102] /* eqAirTemp.wfWin[1] PARAM */) = 0.5;
  data->modelData->realParameterData[102].time_unvarying = 1;
  (data->simulationInfo->realParameter[103] /* eqAirTemp.wfWin[2] PARAM */) = 0.5;
  data->modelData->realParameterData[103].time_unvarying = 1;
  (data->simulationInfo->realParameter[104] /* eqAirTempVDI.TGro PARAM */) = 285.15;
  data->modelData->realParameterData[104].time_unvarying = 1;
  (data->simulationInfo->realParameter[105] /* eqAirTempVDI.aExt PARAM */) = 0.7;
  data->modelData->realParameterData[105].time_unvarying = 1;
  (data->simulationInfo->realParameter[106] /* eqAirTempVDI.hConWallOut PARAM */) = 20.0;
  data->modelData->realParameterData[106].time_unvarying = 1;
  (data->simulationInfo->realParameter[107] /* eqAirTempVDI.hRad PARAM */) = 5.0;
  data->modelData->realParameterData[107].time_unvarying = 1;
  (data->simulationInfo->realParameter[108] /* eqAirTempVDI.wfGro PARAM */) = 0.0;
  data->modelData->realParameterData[108].time_unvarying = 1;
  (data->simulationInfo->realParameter[109] /* eqAirTempVDI.wfWall[1] PARAM */) = 1.0;
  data->modelData->realParameterData[109].time_unvarying = 1;
  (data->simulationInfo->realParameter[110] /* eqAirTempVDI.wfWin[1] PARAM */) = 0.0;
  data->modelData->realParameterData[110].time_unvarying = 1;
  (data->simulationInfo->realParameter[111] /* hConRoof.k PARAM */) = 287.5;
  data->modelData->realParameterData[111].time_unvarying = 1;
  (data->simulationInfo->realParameter[112] /* hConWall.k PARAM */) = 287.5;
  data->modelData->realParameterData[112].time_unvarying = 1;
  (data->simulationInfo->realParameter[113] /* hConWin.k PARAM */) = 280.0;
  data->modelData->realParameterData[113].time_unvarying = 1;
  (data->simulationInfo->realParameter[114] /* intGai.offset[1] PARAM */) = 0.0;
  data->modelData->realParameterData[114].time_unvarying = 1;
  (data->simulationInfo->realParameter[115] /* intGai.p_offset[1] PARAM */) = 0.0;
  data->modelData->realParameterData[115].time_unvarying = 1;
  (data->simulationInfo->realParameter[116] /* intGai.p_offset[2] PARAM */) = 0.0;
  data->modelData->realParameterData[116].time_unvarying = 1;
  (data->simulationInfo->realParameter[117] /* intGai.p_offset[3] PARAM */) = 0.0;
  data->modelData->realParameterData[117].time_unvarying = 1;
  (data->simulationInfo->realParameter[118] /* intGai.shiftTime PARAM */) = 0.0;
  data->modelData->realParameterData[118].time_unvarying = 1;
  (data->simulationInfo->realParameter[119] /* intGai.startTime PARAM */) = 0.0;
  data->modelData->realParameterData[119].time_unvarying = 1;
  (data->simulationInfo->realParameter[124] /* intGai.table[1,1] PARAM */) = 0.0;
  data->modelData->realParameterData[124].time_unvarying = 1;
  (data->simulationInfo->realParameter[125] /* intGai.table[1,2] PARAM */) = 0.0;
  data->modelData->realParameterData[125].time_unvarying = 1;
  (data->simulationInfo->realParameter[126] /* intGai.table[1,3] PARAM */) = 0.0;
  data->modelData->realParameterData[126].time_unvarying = 1;
  (data->simulationInfo->realParameter[127] /* intGai.table[1,4] PARAM */) = 0.0;
  data->modelData->realParameterData[127].time_unvarying = 1;
  (data->simulationInfo->realParameter[128] /* intGai.table[2,1] PARAM */) = 3600.0;
  data->modelData->realParameterData[128].time_unvarying = 1;
  (data->simulationInfo->realParameter[129] /* intGai.table[2,2] PARAM */) = 0.0;
  data->modelData->realParameterData[129].time_unvarying = 1;
  (data->simulationInfo->realParameter[130] /* intGai.table[2,3] PARAM */) = 0.0;
  data->modelData->realParameterData[130].time_unvarying = 1;
  (data->simulationInfo->realParameter[131] /* intGai.table[2,4] PARAM */) = 0.0;
  data->modelData->realParameterData[131].time_unvarying = 1;
  (data->simulationInfo->realParameter[132] /* intGai.table[3,1] PARAM */) = 7200.0;
  data->modelData->realParameterData[132].time_unvarying = 1;
  (data->simulationInfo->realParameter[133] /* intGai.table[3,2] PARAM */) = 0.0;
  data->modelData->realParameterData[133].time_unvarying = 1;
  (data->simulationInfo->realParameter[134] /* intGai.table[3,3] PARAM */) = 0.0;
  data->modelData->realParameterData[134].time_unvarying = 1;
  (data->simulationInfo->realParameter[135] /* intGai.table[3,4] PARAM */) = 0.0;
  data->modelData->realParameterData[135].time_unvarying = 1;
  (data->simulationInfo->realParameter[136] /* intGai.table[4,1] PARAM */) = 10800.0;
  data->modelData->realParameterData[136].time_unvarying = 1;
  (data->simulationInfo->realParameter[137] /* intGai.table[4,2] PARAM */) = 0.0;
  data->modelData->realParameterData[137].time_unvarying = 1;
  (data->simulationInfo->realParameter[138] /* intGai.table[4,3] PARAM */) = 0.0;
  data->modelData->realParameterData[138].time_unvarying = 1;
  (data->simulationInfo->realParameter[139] /* intGai.table[4,4] PARAM */) = 0.0;
  data->modelData->realParameterData[139].time_unvarying = 1;
  (data->simulationInfo->realParameter[140] /* intGai.table[5,1] PARAM */) = 14400.0;
  data->modelData->realParameterData[140].time_unvarying = 1;
  (data->simulationInfo->realParameter[141] /* intGai.table[5,2] PARAM */) = 0.0;
  data->modelData->realParameterData[141].time_unvarying = 1;
  (data->simulationInfo->realParameter[142] /* intGai.table[5,3] PARAM */) = 0.0;
  data->modelData->realParameterData[142].time_unvarying = 1;
  (data->simulationInfo->realParameter[143] /* intGai.table[5,4] PARAM */) = 0.0;
  data->modelData->realParameterData[143].time_unvarying = 1;
  (data->simulationInfo->realParameter[144] /* intGai.table[6,1] PARAM */) = 18000.0;
  data->modelData->realParameterData[144].time_unvarying = 1;
  (data->simulationInfo->realParameter[145] /* intGai.table[6,2] PARAM */) = 0.0;
  data->modelData->realParameterData[145].time_unvarying = 1;
  (data->simulationInfo->realParameter[146] /* intGai.table[6,3] PARAM */) = 0.0;
  data->modelData->realParameterData[146].time_unvarying = 1;
  (data->simulationInfo->realParameter[147] /* intGai.table[6,4] PARAM */) = 0.0;
  data->modelData->realParameterData[147].time_unvarying = 1;
  (data->simulationInfo->realParameter[148] /* intGai.table[7,1] PARAM */) = 21600.0;
  data->modelData->realParameterData[148].time_unvarying = 1;
  (data->simulationInfo->realParameter[149] /* intGai.table[7,2] PARAM */) = 0.0;
  data->modelData->realParameterData[149].time_unvarying = 1;
  (data->simulationInfo->realParameter[150] /* intGai.table[7,3] PARAM */) = 0.0;
  data->modelData->realParameterData[150].time_unvarying = 1;
  (data->simulationInfo->realParameter[151] /* intGai.table[7,4] PARAM */) = 0.0;
  data->modelData->realParameterData[151].time_unvarying = 1;
  (data->simulationInfo->realParameter[152] /* intGai.table[8,1] PARAM */) = 25200.0;
  data->modelData->realParameterData[152].time_unvarying = 1;
  (data->simulationInfo->realParameter[153] /* intGai.table[8,2] PARAM */) = 0.0;
  data->modelData->realParameterData[153].time_unvarying = 1;
  (data->simulationInfo->realParameter[154] /* intGai.table[8,3] PARAM */) = 0.0;
  data->modelData->realParameterData[154].time_unvarying = 1;
  (data->simulationInfo->realParameter[155] /* intGai.table[8,4] PARAM */) = 0.0;
  data->modelData->realParameterData[155].time_unvarying = 1;
  (data->simulationInfo->realParameter[156] /* intGai.table[9,1] PARAM */) = 25200.0;
  data->modelData->realParameterData[156].time_unvarying = 1;
  (data->simulationInfo->realParameter[157] /* intGai.table[9,2] PARAM */) = 80.0;
  data->modelData->realParameterData[157].time_unvarying = 1;
  (data->simulationInfo->realParameter[158] /* intGai.table[9,3] PARAM */) = 80.0;
  data->modelData->realParameterData[158].time_unvarying = 1;
  (data->simulationInfo->realParameter[159] /* intGai.table[9,4] PARAM */) = 200.0;
  data->modelData->realParameterData[159].time_unvarying = 1;
  (data->simulationInfo->realParameter[160] /* intGai.table[10,1] PARAM */) = 28800.0;
  data->modelData->realParameterData[160].time_unvarying = 1;
  (data->simulationInfo->realParameter[161] /* intGai.table[10,2] PARAM */) = 80.0;
  data->modelData->realParameterData[161].time_unvarying = 1;
  (data->simulationInfo->realParameter[162] /* intGai.table[10,3] PARAM */) = 80.0;
  data->modelData->realParameterData[162].time_unvarying = 1;
  (data->simulationInfo->realParameter[163] /* intGai.table[10,4] PARAM */) = 200.0;
  data->modelData->realParameterData[163].time_unvarying = 1;
  (data->simulationInfo->realParameter[164] /* intGai.table[11,1] PARAM */) = 32400.0;
  data->modelData->realParameterData[164].time_unvarying = 1;
  (data->simulationInfo->realParameter[165] /* intGai.table[11,2] PARAM */) = 80.0;
  data->modelData->realParameterData[165].time_unvarying = 1;
  (data->simulationInfo->realParameter[166] /* intGai.table[11,3] PARAM */) = 80.0;
  data->modelData->realParameterData[166].time_unvarying = 1;
  (data->simulationInfo->realParameter[167] /* intGai.table[11,4] PARAM */) = 200.0;
  data->modelData->realParameterData[167].time_unvarying = 1;
  (data->simulationInfo->realParameter[168] /* intGai.table[12,1] PARAM */) = 36000.0;
  data->modelData->realParameterData[168].time_unvarying = 1;
  (data->simulationInfo->realParameter[169] /* intGai.table[12,2] PARAM */) = 80.0;
  data->modelData->realParameterData[169].time_unvarying = 1;
  (data->simulationInfo->realParameter[170] /* intGai.table[12,3] PARAM */) = 80.0;
  data->modelData->realParameterData[170].time_unvarying = 1;
  (data->simulationInfo->realParameter[171] /* intGai.table[12,4] PARAM */) = 200.0;
  data->modelData->realParameterData[171].time_unvarying = 1;
  (data->simulationInfo->realParameter[172] /* intGai.table[13,1] PARAM */) = 39600.0;
  data->modelData->realParameterData[172].time_unvarying = 1;
  (data->simulationInfo->realParameter[173] /* intGai.table[13,2] PARAM */) = 80.0;
  data->modelData->realParameterData[173].time_unvarying = 1;
  (data->simulationInfo->realParameter[174] /* intGai.table[13,3] PARAM */) = 80.0;
  data->modelData->realParameterData[174].time_unvarying = 1;
  (data->simulationInfo->realParameter[175] /* intGai.table[13,4] PARAM */) = 200.0;
  data->modelData->realParameterData[175].time_unvarying = 1;
  (data->simulationInfo->realParameter[176] /* intGai.table[14,1] PARAM */) = 43200.0;
  data->modelData->realParameterData[176].time_unvarying = 1;
  (data->simulationInfo->realParameter[177] /* intGai.table[14,2] PARAM */) = 80.0;
  data->modelData->realParameterData[177].time_unvarying = 1;
  (data->simulationInfo->realParameter[178] /* intGai.table[14,3] PARAM */) = 80.0;
  data->modelData->realParameterData[178].time_unvarying = 1;
  (data->simulationInfo->realParameter[179] /* intGai.table[14,4] PARAM */) = 200.0;
  data->modelData->realParameterData[179].time_unvarying = 1;
  (data->simulationInfo->realParameter[180] /* intGai.table[15,1] PARAM */) = 46800.0;
  data->modelData->realParameterData[180].time_unvarying = 1;
  (data->simulationInfo->realParameter[181] /* intGai.table[15,2] PARAM */) = 80.0;
  data->modelData->realParameterData[181].time_unvarying = 1;
  (data->simulationInfo->realParameter[182] /* intGai.table[15,3] PARAM */) = 80.0;
  data->modelData->realParameterData[182].time_unvarying = 1;
  (data->simulationInfo->realParameter[183] /* intGai.table[15,4] PARAM */) = 200.0;
  data->modelData->realParameterData[183].time_unvarying = 1;
  (data->simulationInfo->realParameter[184] /* intGai.table[16,1] PARAM */) = 50400.0;
  data->modelData->realParameterData[184].time_unvarying = 1;
  (data->simulationInfo->realParameter[185] /* intGai.table[16,2] PARAM */) = 80.0;
  data->modelData->realParameterData[185].time_unvarying = 1;
  (data->simulationInfo->realParameter[186] /* intGai.table[16,3] PARAM */) = 80.0;
  data->modelData->realParameterData[186].time_unvarying = 1;
  (data->simulationInfo->realParameter[187] /* intGai.table[16,4] PARAM */) = 200.0;
  data->modelData->realParameterData[187].time_unvarying = 1;
  (data->simulationInfo->realParameter[188] /* intGai.table[17,1] PARAM */) = 54000.0;
  data->modelData->realParameterData[188].time_unvarying = 1;
  (data->simulationInfo->realParameter[189] /* intGai.table[17,2] PARAM */) = 80.0;
  data->modelData->realParameterData[189].time_unvarying = 1;
  (data->simulationInfo->realParameter[190] /* intGai.table[17,3] PARAM */) = 80.0;
  data->modelData->realParameterData[190].time_unvarying = 1;
  (data->simulationInfo->realParameter[191] /* intGai.table[17,4] PARAM */) = 200.0;
  data->modelData->realParameterData[191].time_unvarying = 1;
  (data->simulationInfo->realParameter[192] /* intGai.table[18,1] PARAM */) = 57600.0;
  data->modelData->realParameterData[192].time_unvarying = 1;
  (data->simulationInfo->realParameter[193] /* intGai.table[18,2] PARAM */) = 80.0;
  data->modelData->realParameterData[193].time_unvarying = 1;
  (data->simulationInfo->realParameter[194] /* intGai.table[18,3] PARAM */) = 80.0;
  data->modelData->realParameterData[194].time_unvarying = 1;
  (data->simulationInfo->realParameter[195] /* intGai.table[18,4] PARAM */) = 200.0;
  data->modelData->realParameterData[195].time_unvarying = 1;
  (data->simulationInfo->realParameter[196] /* intGai.table[19,1] PARAM */) = 61200.0;
  data->modelData->realParameterData[196].time_unvarying = 1;
  (data->simulationInfo->realParameter[197] /* intGai.table[19,2] PARAM */) = 80.0;
  data->modelData->realParameterData[197].time_unvarying = 1;
  (data->simulationInfo->realParameter[198] /* intGai.table[19,3] PARAM */) = 80.0;
  data->modelData->realParameterData[198].time_unvarying = 1;
  (data->simulationInfo->realParameter[199] /* intGai.table[19,4] PARAM */) = 200.0;
  data->modelData->realParameterData[199].time_unvarying = 1;
  (data->simulationInfo->realParameter[200] /* intGai.table[20,1] PARAM */) = 61200.0;
  data->modelData->realParameterData[200].time_unvarying = 1;
  (data->simulationInfo->realParameter[201] /* intGai.table[20,2] PARAM */) = 0.0;
  data->modelData->realParameterData[201].time_unvarying = 1;
  (data->simulationInfo->realParameter[202] /* intGai.table[20,3] PARAM */) = 0.0;
  data->modelData->realParameterData[202].time_unvarying = 1;
  (data->simulationInfo->realParameter[203] /* intGai.table[20,4] PARAM */) = 0.0;
  data->modelData->realParameterData[203].time_unvarying = 1;
  (data->simulationInfo->realParameter[204] /* intGai.table[21,1] PARAM */) = 64800.0;
  data->modelData->realParameterData[204].time_unvarying = 1;
  (data->simulationInfo->realParameter[205] /* intGai.table[21,2] PARAM */) = 0.0;
  data->modelData->realParameterData[205].time_unvarying = 1;
  (data->simulationInfo->realParameter[206] /* intGai.table[21,3] PARAM */) = 0.0;
  data->modelData->realParameterData[206].time_unvarying = 1;
  (data->simulationInfo->realParameter[207] /* intGai.table[21,4] PARAM */) = 0.0;
  data->modelData->realParameterData[207].time_unvarying = 1;
  (data->simulationInfo->realParameter[208] /* intGai.table[22,1] PARAM */) = 72000.0;
  data->modelData->realParameterData[208].time_unvarying = 1;
  (data->simulationInfo->realParameter[209] /* intGai.table[22,2] PARAM */) = 0.0;
  data->modelData->realParameterData[209].time_unvarying = 1;
  (data->simulationInfo->realParameter[210] /* intGai.table[22,3] PARAM */) = 0.0;
  data->modelData->realParameterData[210].time_unvarying = 1;
  (data->simulationInfo->realParameter[211] /* intGai.table[22,4] PARAM */) = 0.0;
  data->modelData->realParameterData[211].time_unvarying = 1;
  (data->simulationInfo->realParameter[212] /* intGai.table[23,1] PARAM */) = 75600.0;
  data->modelData->realParameterData[212].time_unvarying = 1;
  (data->simulationInfo->realParameter[213] /* intGai.table[23,2] PARAM */) = 0.0;
  data->modelData->realParameterData[213].time_unvarying = 1;
  (data->simulationInfo->realParameter[214] /* intGai.table[23,3] PARAM */) = 0.0;
  data->modelData->realParameterData[214].time_unvarying = 1;
  (data->simulationInfo->realParameter[215] /* intGai.table[23,4] PARAM */) = 0.0;
  data->modelData->realParameterData[215].time_unvarying = 1;
  (data->simulationInfo->realParameter[216] /* intGai.table[24,1] PARAM */) = 79200.0;
  data->modelData->realParameterData[216].time_unvarying = 1;
  (data->simulationInfo->realParameter[217] /* intGai.table[24,2] PARAM */) = 0.0;
  data->modelData->realParameterData[217].time_unvarying = 1;
  (data->simulationInfo->realParameter[218] /* intGai.table[24,3] PARAM */) = 0.0;
  data->modelData->realParameterData[218].time_unvarying = 1;
  (data->simulationInfo->realParameter[219] /* intGai.table[24,4] PARAM */) = 0.0;
  data->modelData->realParameterData[219].time_unvarying = 1;
  (data->simulationInfo->realParameter[220] /* intGai.table[25,1] PARAM */) = 82800.0;
  data->modelData->realParameterData[220].time_unvarying = 1;
  (data->simulationInfo->realParameter[221] /* intGai.table[25,2] PARAM */) = 0.0;
  data->modelData->realParameterData[221].time_unvarying = 1;
  (data->simulationInfo->realParameter[222] /* intGai.table[25,3] PARAM */) = 0.0;
  data->modelData->realParameterData[222].time_unvarying = 1;
  (data->simulationInfo->realParameter[223] /* intGai.table[25,4] PARAM */) = 0.0;
  data->modelData->realParameterData[223].time_unvarying = 1;
  (data->simulationInfo->realParameter[224] /* intGai.table[26,1] PARAM */) = 86400.0;
  data->modelData->realParameterData[224].time_unvarying = 1;
  (data->simulationInfo->realParameter[225] /* intGai.table[26,2] PARAM */) = 0.0;
  data->modelData->realParameterData[225].time_unvarying = 1;
  (data->simulationInfo->realParameter[226] /* intGai.table[26,3] PARAM */) = 0.0;
  data->modelData->realParameterData[226].time_unvarying = 1;
  (data->simulationInfo->realParameter[227] /* intGai.table[26,4] PARAM */) = 0.0;
  data->modelData->realParameterData[227].time_unvarying = 1;
  (data->simulationInfo->realParameter[228] /* intGai.timeScale PARAM */) = 1.0;
  data->modelData->realParameterData[228].time_unvarying = 1;
  (data->simulationInfo->realParameter[229] /* macConv.T_ref PARAM */) = 293.15;
  data->modelData->realParameterData[229].time_unvarying = 1;
  (data->simulationInfo->realParameter[230] /* macConv.alpha PARAM */) = 0.0;
  data->modelData->realParameterData[230].time_unvarying = 1;
  (data->simulationInfo->realParameter[231] /* perCon.T_ref PARAM */) = 293.15;
  data->modelData->realParameterData[231].time_unvarying = 1;
  (data->simulationInfo->realParameter[232] /* perCon.alpha PARAM */) = 0.0;
  data->modelData->realParameterData[232].time_unvarying = 1;
  (data->simulationInfo->realParameter[233] /* perRad.T_ref PARAM */) = 293.15;
  data->modelData->realParameterData[233].time_unvarying = 1;
  (data->simulationInfo->realParameter[234] /* perRad.alpha PARAM */) = 0.0;
  data->modelData->realParameterData[234].time_unvarying = 1;
  (data->simulationInfo->realParameter[235] /* solRad[1].k1 PARAM */) = 1.0;
  data->modelData->realParameterData[235].time_unvarying = 1;
  (data->simulationInfo->realParameter[236] /* solRad[2].k1 PARAM */) = 1.0;
  data->modelData->realParameterData[236].time_unvarying = 1;
  (data->simulationInfo->realParameter[237] /* solRad[1].k2 PARAM */) = 1.0;
  data->modelData->realParameterData[237].time_unvarying = 1;
  (data->simulationInfo->realParameter[238] /* solRad[2].k2 PARAM */) = 1.0;
  data->modelData->realParameterData[238].time_unvarying = 1;
  (data->simulationInfo->realParameter[239] /* thermalZoneFourElements.AArray[1] PARAM */) = 11.5;
  data->modelData->realParameterData[239].time_unvarying = 1;
  (data->simulationInfo->realParameter[240] /* thermalZoneFourElements.AArray[2] PARAM */) = 14.0;
  data->modelData->realParameterData[240].time_unvarying = 1;
  (data->simulationInfo->realParameter[241] /* thermalZoneFourElements.AArray[3] PARAM */) = 60.5;
  data->modelData->realParameterData[241].time_unvarying = 1;
  (data->simulationInfo->realParameter[242] /* thermalZoneFourElements.AArray[4] PARAM */) = 11.5;
  data->modelData->realParameterData[242].time_unvarying = 1;
  (data->simulationInfo->realParameter[243] /* thermalZoneFourElements.AArray[5] PARAM */) = 11.5;
  data->modelData->realParameterData[243].time_unvarying = 1;
  (data->simulationInfo->realParameter[244] /* thermalZoneFourElements.AExt[1] PARAM */) = 3.5;
  data->modelData->realParameterData[244].time_unvarying = 1;
  (data->simulationInfo->realParameter[245] /* thermalZoneFourElements.AExt[2] PARAM */) = 8.0;
  data->modelData->realParameterData[245].time_unvarying = 1;
  (data->simulationInfo->realParameter[246] /* thermalZoneFourElements.AFloor PARAM */) = 11.5;
  data->modelData->realParameterData[246].time_unvarying = 1;
  (data->simulationInfo->realParameter[247] /* thermalZoneFourElements.AInt PARAM */) = 60.5;
  data->modelData->realParameterData[247].time_unvarying = 1;
  (data->simulationInfo->realParameter[248] /* thermalZoneFourElements.ARoof PARAM */) = 11.5;
  data->modelData->realParameterData[248].time_unvarying = 1;
  (data->simulationInfo->realParameter[249] /* thermalZoneFourElements.ATot PARAM */) = 109.0;
  data->modelData->realParameterData[249].time_unvarying = 1;
  (data->simulationInfo->realParameter[250] /* thermalZoneFourElements.ATotExt PARAM */) = 11.5;
  data->modelData->realParameterData[250].time_unvarying = 1;
  (data->simulationInfo->realParameter[251] /* thermalZoneFourElements.ATotWin PARAM */) = 14.0;
  data->modelData->realParameterData[251].time_unvarying = 1;
  (data->simulationInfo->realParameter[252] /* thermalZoneFourElements.ATransparent[1] PARAM */) = 7.0;
  data->modelData->realParameterData[252].time_unvarying = 1;
  (data->simulationInfo->realParameter[253] /* thermalZoneFourElements.ATransparent[2] PARAM */) = 7.0;
  data->modelData->realParameterData[253].time_unvarying = 1;
  (data->simulationInfo->realParameter[254] /* thermalZoneFourElements.AWin[1] PARAM */) = 7.0;
  data->modelData->realParameterData[254].time_unvarying = 1;
  (data->simulationInfo->realParameter[255] /* thermalZoneFourElements.AWin[2] PARAM */) = 7.0;
  data->modelData->realParameterData[255].time_unvarying = 1;
  (data->simulationInfo->realParameter[256] /* thermalZoneFourElements.CExt[1] PARAM */) = 5259932.23;
  data->modelData->realParameterData[256].time_unvarying = 1;
  (data->simulationInfo->realParameter[257] /* thermalZoneFourElements.CFloor[1] PARAM */) = 5259932.23;
  data->modelData->realParameterData[257].time_unvarying = 1;
  (data->simulationInfo->realParameter[258] /* thermalZoneFourElements.CInt[1] PARAM */) = 12391363.86;
  data->modelData->realParameterData[258].time_unvarying = 1;
  (data->simulationInfo->realParameter[259] /* thermalZoneFourElements.CRoof[1] PARAM */) = 5259932.23;
  data->modelData->realParameterData[259].time_unvarying = 1;
  (data->simulationInfo->realParameter[260] /* thermalZoneFourElements.RExt[1] PARAM */) = 0.00331421908725;
  data->modelData->realParameterData[260].time_unvarying = 1;
  (data->simulationInfo->realParameter[261] /* thermalZoneFourElements.RExtRem PARAM */) = 0.1265217391;
  data->modelData->realParameterData[261].time_unvarying = 1;
  (data->simulationInfo->realParameter[262] /* thermalZoneFourElements.RFloor[1] PARAM */) = 0.00331421908725;
  data->modelData->realParameterData[262].time_unvarying = 1;
  (data->simulationInfo->realParameter[263] /* thermalZoneFourElements.RFloorRem PARAM */) = 0.1265217391;
  data->modelData->realParameterData[263].time_unvarying = 1;
  (data->simulationInfo->realParameter[264] /* thermalZoneFourElements.RInt[1] PARAM */) = 0.000668895639141;
  data->modelData->realParameterData[264].time_unvarying = 1;
  (data->simulationInfo->realParameter[265] /* thermalZoneFourElements.RRoof[1] PARAM */) = 0.00331421908725;
  data->modelData->realParameterData[265].time_unvarying = 1;
  (data->simulationInfo->realParameter[266] /* thermalZoneFourElements.RRoofRem PARAM */) = 0.1265217391;
  data->modelData->realParameterData[266].time_unvarying = 1;
  (data->simulationInfo->realParameter[267] /* thermalZoneFourElements.RWin PARAM */) = 0.01642857143;
  data->modelData->realParameterData[267].time_unvarying = 1;
  (data->simulationInfo->realParameter[268] /* thermalZoneFourElements.T_start PARAM */) = 295.15;
  data->modelData->realParameterData[268].time_unvarying = 1;
  (data->simulationInfo->realParameter[269] /* thermalZoneFourElements.VAir PARAM */) = 52.5;
  data->modelData->realParameterData[269].time_unvarying = 1;
  (data->simulationInfo->realParameter[270] /* thermalZoneFourElements.X_start[1] PARAM */) = 1.0;
  data->modelData->realParameterData[270].time_unvarying = 1;
  (data->simulationInfo->realParameter[271] /* thermalZoneFourElements.convHeatSol.T_ref PARAM */) = 293.15;
  data->modelData->realParameterData[271].time_unvarying = 1;
  (data->simulationInfo->realParameter[272] /* thermalZoneFourElements.convHeatSol.alpha PARAM */) = 0.0;
  data->modelData->realParameterData[272].time_unvarying = 1;
  (data->simulationInfo->realParameter[273] /* thermalZoneFourElements.eConvSol[1].k PARAM */) = 0.63;
  data->modelData->realParameterData[273].time_unvarying = 1;
  (data->simulationInfo->realParameter[274] /* thermalZoneFourElements.eConvSol[2].k PARAM */) = 0.63;
  data->modelData->realParameterData[274].time_unvarying = 1;
  (data->simulationInfo->realParameter[275] /* thermalZoneFourElements.eRadSol[1].k PARAM */) = 6.37;
  data->modelData->realParameterData[275].time_unvarying = 1;
  (data->simulationInfo->realParameter[276] /* thermalZoneFourElements.eRadSol[2].k PARAM */) = 6.37;
  data->modelData->realParameterData[276].time_unvarying = 1;
  (data->simulationInfo->realParameter[277] /* thermalZoneFourElements.extWallRC.CExt[1] PARAM */) = 5259932.23;
  data->modelData->realParameterData[277].time_unvarying = 1;
  (data->simulationInfo->realParameter[278] /* thermalZoneFourElements.extWallRC.RExt[1] PARAM */) = 0.00331421908725;
  data->modelData->realParameterData[278].time_unvarying = 1;
  (data->simulationInfo->realParameter[279] /* thermalZoneFourElements.extWallRC.RExtRem PARAM */) = 0.1265217391;
  data->modelData->realParameterData[279].time_unvarying = 1;
  (data->simulationInfo->realParameter[280] /* thermalZoneFourElements.extWallRC.T_start PARAM */) = 295.15;
  data->modelData->realParameterData[280].time_unvarying = 1;
  (data->simulationInfo->realParameter[281] /* thermalZoneFourElements.extWallRC.thermCapExt[1].C PARAM */) = 5259932.23;
  data->modelData->realParameterData[281].time_unvarying = 1;
  (data->simulationInfo->realParameter[282] /* thermalZoneFourElements.extWallRC.thermResExt[1].R PARAM */) = 0.00331421908725;
  data->modelData->realParameterData[282].time_unvarying = 1;
  (data->simulationInfo->realParameter[283] /* thermalZoneFourElements.extWallRC.thermResExtRem.R PARAM */) = 0.1265217391;
  data->modelData->realParameterData[283].time_unvarying = 1;
  (data->simulationInfo->realParameter[284] /* thermalZoneFourElements.floorRC.CExt[1] PARAM */) = 5259932.23;
  data->modelData->realParameterData[284].time_unvarying = 1;
  (data->simulationInfo->realParameter[285] /* thermalZoneFourElements.floorRC.RExt[1] PARAM */) = 0.00331421908725;
  data->modelData->realParameterData[285].time_unvarying = 1;
  (data->simulationInfo->realParameter[286] /* thermalZoneFourElements.floorRC.RExtRem PARAM */) = 0.1265217391;
  data->modelData->realParameterData[286].time_unvarying = 1;
  (data->simulationInfo->realParameter[287] /* thermalZoneFourElements.floorRC.T_start PARAM */) = 295.15;
  data->modelData->realParameterData[287].time_unvarying = 1;
  (data->simulationInfo->realParameter[288] /* thermalZoneFourElements.floorRC.thermCapExt[1].C PARAM */) = 5259932.23;
  data->modelData->realParameterData[288].time_unvarying = 1;
  (data->simulationInfo->realParameter[289] /* thermalZoneFourElements.floorRC.thermResExt[1].R PARAM */) = 0.00331421908725;
  data->modelData->realParameterData[289].time_unvarying = 1;
  (data->simulationInfo->realParameter[290] /* thermalZoneFourElements.floorRC.thermResExtRem.R PARAM */) = 0.1265217391;
  data->modelData->realParameterData[290].time_unvarying = 1;
  (data->simulationInfo->realParameter[291] /* thermalZoneFourElements.gWin PARAM */) = 1.0;
  data->modelData->realParameterData[291].time_unvarying = 1;
  (data->simulationInfo->realParameter[292] /* thermalZoneFourElements.hConExt PARAM */) = 2.7;
  data->modelData->realParameterData[292].time_unvarying = 1;
  (data->simulationInfo->realParameter[293] /* thermalZoneFourElements.hConExtWall_const.k PARAM */) = 31.05;
  data->modelData->realParameterData[293].time_unvarying = 1;
  (data->simulationInfo->realParameter[294] /* thermalZoneFourElements.hConFloor PARAM */) = 2.7;
  data->modelData->realParameterData[294].time_unvarying = 1;
  (data->simulationInfo->realParameter[295] /* thermalZoneFourElements.hConFloor_const.k PARAM */) = 31.05;
  data->modelData->realParameterData[295].time_unvarying = 1;
  (data->simulationInfo->realParameter[296] /* thermalZoneFourElements.hConInt PARAM */) = 2.12;
  data->modelData->realParameterData[296].time_unvarying = 1;
  (data->simulationInfo->realParameter[297] /* thermalZoneFourElements.hConIntWall.k PARAM */) = 128.26;
  data->modelData->realParameterData[297].time_unvarying = 1;
  (data->simulationInfo->realParameter[298] /* thermalZoneFourElements.hConRoof PARAM */) = 2.7;
  data->modelData->realParameterData[298].time_unvarying = 1;
  (data->simulationInfo->realParameter[299] /* thermalZoneFourElements.hConRoof_const.k PARAM */) = 31.05;
  data->modelData->realParameterData[299].time_unvarying = 1;
  (data->simulationInfo->realParameter[300] /* thermalZoneFourElements.hConWin PARAM */) = 2.7;
  data->modelData->realParameterData[300].time_unvarying = 1;
  (data->simulationInfo->realParameter[301] /* thermalZoneFourElements.hConWin_const.k PARAM */) = 37.8;
  data->modelData->realParameterData[301].time_unvarying = 1;
  (data->simulationInfo->realParameter[302] /* thermalZoneFourElements.hRad PARAM */) = 5.0;
  data->modelData->realParameterData[302].time_unvarying = 1;
  (data->simulationInfo->realParameter[303] /* thermalZoneFourElements.intWallRC.CInt[1] PARAM */) = 12391363.86;
  data->modelData->realParameterData[303].time_unvarying = 1;
  (data->simulationInfo->realParameter[304] /* thermalZoneFourElements.intWallRC.RInt[1] PARAM */) = 0.000668895639141;
  data->modelData->realParameterData[304].time_unvarying = 1;
  (data->simulationInfo->realParameter[305] /* thermalZoneFourElements.intWallRC.T_start PARAM */) = 295.15;
  data->modelData->realParameterData[305].time_unvarying = 1;
  (data->simulationInfo->realParameter[306] /* thermalZoneFourElements.intWallRC.thermCapInt[1].C PARAM */) = 12391363.86;
  data->modelData->realParameterData[306].time_unvarying = 1;
  (data->simulationInfo->realParameter[307] /* thermalZoneFourElements.intWallRC.thermResInt[1].R PARAM */) = 0.000668895639141;
  data->modelData->realParameterData[307].time_unvarying = 1;
  (data->simulationInfo->realParameter[308] /* thermalZoneFourElements.mSenFac PARAM */) = 1.0;
  data->modelData->realParameterData[308].time_unvarying = 1;
  (data->simulationInfo->realParameter[309] /* thermalZoneFourElements.p_start PARAM */) = 101325.0;
  data->modelData->realParameterData[309].time_unvarying = 1;
  (data->simulationInfo->realParameter[310] /* thermalZoneFourElements.radHeatSol[1].T_ref PARAM */) = 293.15;
  data->modelData->realParameterData[310].time_unvarying = 1;
  (data->simulationInfo->realParameter[311] /* thermalZoneFourElements.radHeatSol[2].T_ref PARAM */) = 293.15;
  data->modelData->realParameterData[311].time_unvarying = 1;
  (data->simulationInfo->realParameter[312] /* thermalZoneFourElements.radHeatSol[1].alpha PARAM */) = 0.0;
  data->modelData->realParameterData[312].time_unvarying = 1;
  (data->simulationInfo->realParameter[313] /* thermalZoneFourElements.radHeatSol[2].alpha PARAM */) = 0.0;
  data->modelData->realParameterData[313].time_unvarying = 1;
  (data->simulationInfo->realParameter[314] /* thermalZoneFourElements.ratioWinConRad PARAM */) = 0.09;
  data->modelData->realParameterData[314].time_unvarying = 1;
  (data->simulationInfo->realParameter[315] /* thermalZoneFourElements.resExtWallFloor.G PARAM */) = 57.5;
  data->modelData->realParameterData[315].time_unvarying = 1;
  (data->simulationInfo->realParameter[316] /* thermalZoneFourElements.resExtWallIntWall.G PARAM */) = 57.5;
  data->modelData->realParameterData[316].time_unvarying = 1;
  (data->simulationInfo->realParameter[317] /* thermalZoneFourElements.resExtWallRoof.G PARAM */) = 57.5;
  data->modelData->realParameterData[317].time_unvarying = 1;
  (data->simulationInfo->realParameter[318] /* thermalZoneFourElements.resExtWallWin.G PARAM */) = 57.5;
  data->modelData->realParameterData[318].time_unvarying = 1;
  (data->simulationInfo->realParameter[319] /* thermalZoneFourElements.resFloorWin.G PARAM */) = 57.5;
  data->modelData->realParameterData[319].time_unvarying = 1;
  (data->simulationInfo->realParameter[320] /* thermalZoneFourElements.resIntRoof.G PARAM */) = 57.5;
  data->modelData->realParameterData[320].time_unvarying = 1;
  (data->simulationInfo->realParameter[321] /* thermalZoneFourElements.resIntWallFloor.G PARAM */) = 57.5;
  data->modelData->realParameterData[321].time_unvarying = 1;
  (data->simulationInfo->realParameter[322] /* thermalZoneFourElements.resIntWallWin.G PARAM */) = 70.0;
  data->modelData->realParameterData[322].time_unvarying = 1;
  (data->simulationInfo->realParameter[323] /* thermalZoneFourElements.resRoofFloor.G PARAM */) = 57.5;
  data->modelData->realParameterData[323].time_unvarying = 1;
  (data->simulationInfo->realParameter[324] /* thermalZoneFourElements.resRoofWin.G PARAM */) = 57.5;
  data->modelData->realParameterData[324].time_unvarying = 1;
  (data->simulationInfo->realParameter[325] /* thermalZoneFourElements.resWin.R PARAM */) = 0.01642857143;
  data->modelData->realParameterData[325].time_unvarying = 1;
  (data->simulationInfo->realParameter[326] /* thermalZoneFourElements.roofRC.CExt[1] PARAM */) = 5259932.23;
  data->modelData->realParameterData[326].time_unvarying = 1;
  (data->simulationInfo->realParameter[327] /* thermalZoneFourElements.roofRC.RExt[1] PARAM */) = 0.00331421908725;
  data->modelData->realParameterData[327].time_unvarying = 1;
  (data->simulationInfo->realParameter[328] /* thermalZoneFourElements.roofRC.RExtRem PARAM */) = 0.1265217391;
  data->modelData->realParameterData[328].time_unvarying = 1;
  (data->simulationInfo->realParameter[329] /* thermalZoneFourElements.roofRC.T_start PARAM */) = 295.15;
  data->modelData->realParameterData[329].time_unvarying = 1;
  (data->simulationInfo->realParameter[330] /* thermalZoneFourElements.roofRC.thermCapExt[1].C PARAM */) = 5259932.23;
  data->modelData->realParameterData[330].time_unvarying = 1;
  (data->simulationInfo->realParameter[331] /* thermalZoneFourElements.roofRC.thermResExt[1].R PARAM */) = 0.00331421908725;
  data->modelData->realParameterData[331].time_unvarying = 1;
  (data->simulationInfo->realParameter[332] /* thermalZoneFourElements.roofRC.thermResExtRem.R PARAM */) = 0.1265217391;
  data->modelData->realParameterData[332].time_unvarying = 1;
  (data->simulationInfo->realParameter[333] /* thermalZoneFourElements.splitFactor[1,1] PARAM */) = 0.1055045871559633;
  data->modelData->realParameterData[333].time_unvarying = 1;
  (data->simulationInfo->realParameter[334] /* thermalZoneFourElements.splitFactor[2,1] PARAM */) = 0.1284403669724771;
  data->modelData->realParameterData[334].time_unvarying = 1;
  (data->simulationInfo->realParameter[335] /* thermalZoneFourElements.splitFactor[3,1] PARAM */) = 0.555045871559633;
  data->modelData->realParameterData[335].time_unvarying = 1;
  (data->simulationInfo->realParameter[336] /* thermalZoneFourElements.splitFactor[4,1] PARAM */) = 0.1055045871559633;
  data->modelData->realParameterData[336].time_unvarying = 1;
  (data->simulationInfo->realParameter[337] /* thermalZoneFourElements.splitFactor[5,1] PARAM */) = 0.1055045871559633;
  data->modelData->realParameterData[337].time_unvarying = 1;
  (data->simulationInfo->realParameter[338] /* thermalZoneFourElements.splitFactorSolRad[1,1] PARAM */) = 0.08121827411167512;
  data->modelData->realParameterData[338].time_unvarying = 1;
  (data->simulationInfo->realParameter[339] /* thermalZoneFourElements.splitFactorSolRad[1,2] PARAM */) = 0.03723404255319149;
  data->modelData->realParameterData[339].time_unvarying = 1;
  (data->simulationInfo->realParameter[340] /* thermalZoneFourElements.splitFactorSolRad[2,1] PARAM */) = 0.07106598984771574;
  data->modelData->realParameterData[340].time_unvarying = 1;
  (data->simulationInfo->realParameter[341] /* thermalZoneFourElements.splitFactorSolRad[2,2] PARAM */) = 0.07446808510638298;
  data->modelData->realParameterData[341].time_unvarying = 1;
  (data->simulationInfo->realParameter[342] /* thermalZoneFourElements.splitFactorSolRad[3,1] PARAM */) = 0.6142131979695431;
  data->modelData->realParameterData[342].time_unvarying = 1;
  (data->simulationInfo->realParameter[343] /* thermalZoneFourElements.splitFactorSolRad[3,2] PARAM */) = 0.6436170212765957;
  data->modelData->realParameterData[343].time_unvarying = 1;
  (data->simulationInfo->realParameter[344] /* thermalZoneFourElements.splitFactorSolRad[4,1] PARAM */) = 0.116751269035533;
  data->modelData->realParameterData[344].time_unvarying = 1;
  (data->simulationInfo->realParameter[345] /* thermalZoneFourElements.splitFactorSolRad[4,2] PARAM */) = 0.1223404255319149;
  data->modelData->realParameterData[345].time_unvarying = 1;
  (data->simulationInfo->realParameter[346] /* thermalZoneFourElements.splitFactorSolRad[5,1] PARAM */) = 0.116751269035533;
  data->modelData->realParameterData[346].time_unvarying = 1;
  (data->simulationInfo->realParameter[347] /* thermalZoneFourElements.splitFactorSolRad[5,2] PARAM */) = 0.1223404255319149;
  data->modelData->realParameterData[347].time_unvarying = 1;
  (data->simulationInfo->realParameter[348] /* thermalZoneFourElements.sumSolRad.k[1] PARAM */) = 1.0;
  data->modelData->realParameterData[348].time_unvarying = 1;
  (data->simulationInfo->realParameter[349] /* thermalZoneFourElements.sumSolRad.k[2] PARAM */) = 1.0;
  data->modelData->realParameterData[349].time_unvarying = 1;
  (data->simulationInfo->realParameter[350] /* thermalZoneFourElements.thermSplitterIntGains.splitFactor[1,1] PARAM */) = 0.1055045871559633;
  data->modelData->realParameterData[350].time_unvarying = 1;
  (data->simulationInfo->realParameter[351] /* thermalZoneFourElements.thermSplitterIntGains.splitFactor[2,1] PARAM */) = 0.1284403669724771;
  data->modelData->realParameterData[351].time_unvarying = 1;
  (data->simulationInfo->realParameter[352] /* thermalZoneFourElements.thermSplitterIntGains.splitFactor[3,1] PARAM */) = 0.555045871559633;
  data->modelData->realParameterData[352].time_unvarying = 1;
  (data->simulationInfo->realParameter[353] /* thermalZoneFourElements.thermSplitterIntGains.splitFactor[4,1] PARAM */) = 0.1055045871559633;
  data->modelData->realParameterData[353].time_unvarying = 1;
  (data->simulationInfo->realParameter[354] /* thermalZoneFourElements.thermSplitterIntGains.splitFactor[5,1] PARAM */) = 0.1055045871559633;
  data->modelData->realParameterData[354].time_unvarying = 1;
  (data->simulationInfo->realParameter[355] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[1,1] PARAM */) = 0.08121827411167512;
  data->modelData->realParameterData[355].time_unvarying = 1;
  (data->simulationInfo->realParameter[356] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[1,2] PARAM */) = 0.03723404255319149;
  data->modelData->realParameterData[356].time_unvarying = 1;
  (data->simulationInfo->realParameter[357] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[2,1] PARAM */) = 0.07106598984771574;
  data->modelData->realParameterData[357].time_unvarying = 1;
  (data->simulationInfo->realParameter[358] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[2,2] PARAM */) = 0.07446808510638298;
  data->modelData->realParameterData[358].time_unvarying = 1;
  (data->simulationInfo->realParameter[359] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[3,1] PARAM */) = 0.6142131979695431;
  data->modelData->realParameterData[359].time_unvarying = 1;
  (data->simulationInfo->realParameter[360] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[3,2] PARAM */) = 0.6436170212765957;
  data->modelData->realParameterData[360].time_unvarying = 1;
  (data->simulationInfo->realParameter[361] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[4,1] PARAM */) = 0.116751269035533;
  data->modelData->realParameterData[361].time_unvarying = 1;
  (data->simulationInfo->realParameter[362] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[4,2] PARAM */) = 0.1223404255319149;
  data->modelData->realParameterData[362].time_unvarying = 1;
  (data->simulationInfo->realParameter[363] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[5,1] PARAM */) = 0.116751269035533;
  data->modelData->realParameterData[363].time_unvarying = 1;
  (data->simulationInfo->realParameter[364] /* thermalZoneFourElements.thermSplitterSolRad.splitFactor[5,2] PARAM */) = 0.1223404255319149;
  data->modelData->realParameterData[364].time_unvarying = 1;
  (data->simulationInfo->realParameter[365] /* thermalZoneFourElements.volAir.T_start PARAM */) = 295.15;
  data->modelData->realParameterData[365].time_unvarying = 1;
  (data->simulationInfo->realParameter[366] /* thermalZoneFourElements.volAir.V PARAM */) = 52.5;
  data->modelData->realParameterData[366].time_unvarying = 1;
  (data->simulationInfo->realParameter[367] /* thermalZoneFourElements.volAir.X_start[1] PARAM */) = 1.0;
  data->modelData->realParameterData[367].time_unvarying = 1;
  (data->simulationInfo->realParameter[368] /* thermalZoneFourElements.volAir.dynBal.CSen PARAM */) = 0.0;
  data->modelData->realParameterData[368].time_unvarying = 1;
  (data->simulationInfo->realParameter[369] /* thermalZoneFourElements.volAir.dynBal.T_start PARAM */) = 295.15;
  data->modelData->realParameterData[369].time_unvarying = 1;
  (data->simulationInfo->realParameter[370] /* thermalZoneFourElements.volAir.dynBal.X_start[1] PARAM */) = 1.0;
  data->modelData->realParameterData[370].time_unvarying = 1;
  (data->simulationInfo->realParameter[371] /* thermalZoneFourElements.volAir.dynBal.cp_default PARAM */) = 1005.45;
  data->modelData->realParameterData[371].time_unvarying = 1;
  (data->simulationInfo->realParameter[372] /* thermalZoneFourElements.volAir.dynBal.fluidVolume PARAM */) = 52.5;
  data->modelData->realParameterData[372].time_unvarying = 1;
  (data->simulationInfo->realParameter[373] /* thermalZoneFourElements.volAir.dynBal.hStart PARAM */) = -3016.35;
  data->modelData->realParameterData[373].time_unvarying = 1;
  (data->simulationInfo->realParameter[374] /* thermalZoneFourElements.volAir.dynBal.mSenFac PARAM */) = 1.0;
  data->modelData->realParameterData[374].time_unvarying = 1;
  (data->simulationInfo->realParameter[375] /* thermalZoneFourElements.volAir.dynBal.p_start PARAM */) = 101325.0;
  data->modelData->realParameterData[375].time_unvarying = 1;
  (data->simulationInfo->realParameter[376] /* thermalZoneFourElements.volAir.dynBal.rho_default PARAM */) = 1.204114536653002;
  data->modelData->realParameterData[376].time_unvarying = 1;
  (data->simulationInfo->realParameter[377] /* thermalZoneFourElements.volAir.dynBal.rho_start PARAM */) = 1.195955197085643;
  data->modelData->realParameterData[377].time_unvarying = 1;
  (data->simulationInfo->realParameter[378] /* thermalZoneFourElements.volAir.dynBal.state_default.T PARAM */) = 293.15;
  data->modelData->realParameterData[378].time_unvarying = 1;
  (data->simulationInfo->realParameter[379] /* thermalZoneFourElements.volAir.dynBal.state_default.p PARAM */) = 101325.0;
  data->modelData->realParameterData[379].time_unvarying = 1;
  (data->simulationInfo->realParameter[380] /* thermalZoneFourElements.volAir.mSenFac PARAM */) = 1.0;
  data->modelData->realParameterData[380].time_unvarying = 1;
  (data->simulationInfo->realParameter[381] /* thermalZoneFourElements.volAir.m_flow_nominal PARAM */) = 0.105;
  data->modelData->realParameterData[381].time_unvarying = 1;
  (data->simulationInfo->realParameter[382] /* thermalZoneFourElements.volAir.m_flow_small PARAM */) = 1.05e-05;
  data->modelData->realParameterData[382].time_unvarying = 1;
  (data->simulationInfo->realParameter[383] /* thermalZoneFourElements.volAir.p_start PARAM */) = 101325.0;
  data->modelData->realParameterData[383].time_unvarying = 1;
  (data->simulationInfo->realParameter[384] /* thermalZoneFourElements.volAir.rho_default PARAM */) = 1.204114536653002;
  data->modelData->realParameterData[384].time_unvarying = 1;
  (data->simulationInfo->realParameter[385] /* thermalZoneFourElements.volAir.rho_start PARAM */) = 1.195955197085643;
  data->modelData->realParameterData[385].time_unvarying = 1;
  (data->simulationInfo->realParameter[386] /* thermalZoneFourElements.volAir.state_default.T PARAM */) = 293.15;
  data->modelData->realParameterData[386].time_unvarying = 1;
  (data->simulationInfo->realParameter[387] /* thermalZoneFourElements.volAir.state_default.p PARAM */) = 101325.0;
  data->modelData->realParameterData[387].time_unvarying = 1;
  (data->simulationInfo->realParameter[388] /* thermalZoneFourElements.volAir.state_start.T PARAM */) = 295.15;
  data->modelData->realParameterData[388].time_unvarying = 1;
  (data->simulationInfo->realParameter[389] /* thermalZoneFourElements.volAir.state_start.p PARAM */) = 101325.0;
  data->modelData->realParameterData[389].time_unvarying = 1;
  (data->simulationInfo->realParameter[393] /* weaDat.HInfHor PARAM */) = 0.0;
  data->modelData->realParameterData[393].time_unvarying = 1;
  (data->simulationInfo->realParameter[394] /* weaDat.TBlaSky PARAM */) = 273.15;
  data->modelData->realParameterData[394].time_unvarying = 1;
  (data->simulationInfo->realParameter[395] /* weaDat.TBlaSkySel.p PARAM */) = 273.15;
  data->modelData->realParameterData[395].time_unvarying = 1;
  (data->simulationInfo->realParameter[396] /* weaDat.TDewPoi PARAM */) = 283.15;
  data->modelData->realParameterData[396].time_unvarying = 1;
  (data->simulationInfo->realParameter[397] /* weaDat.TDewPoiSel.p PARAM */) = 283.15;
  data->modelData->realParameterData[397].time_unvarying = 1;
  (data->simulationInfo->realParameter[398] /* weaDat.TDryBul PARAM */) = 293.15;
  data->modelData->realParameterData[398].time_unvarying = 1;
  (data->simulationInfo->realParameter[399] /* weaDat.TDryBulSel.p PARAM */) = 293.15;
  data->modelData->realParameterData[399].time_unvarying = 1;
  (data->simulationInfo->realParameter[400] /* weaDat.add30Min.k1 PARAM */) = 1.0;
  data->modelData->realParameterData[400].time_unvarying = 1;
  (data->simulationInfo->realParameter[401] /* weaDat.add30Min.k2 PARAM */) = 1.0;
  data->modelData->realParameterData[401].time_unvarying = 1;
  (data->simulationInfo->realParameter[405] /* weaDat.ceiHei PARAM */) = 20000.0;
  data->modelData->realParameterData[405].time_unvarying = 1;
  (data->simulationInfo->realParameter[406] /* weaDat.ceiHeiSel.p PARAM */) = 20000.0;
  data->modelData->realParameterData[406].time_unvarying = 1;
  (data->simulationInfo->realParameter[407] /* weaDat.cheTemBlaSky.TMax PARAM */) = 343.15;
  data->modelData->realParameterData[407].time_unvarying = 1;
  (data->simulationInfo->realParameter[408] /* weaDat.cheTemBlaSky.TMin PARAM */) = 0.0;
  data->modelData->realParameterData[408].time_unvarying = 1;
  (data->simulationInfo->realParameter[409] /* weaDat.cheTemDewPoi.TMax PARAM */) = 343.15;
  data->modelData->realParameterData[409].time_unvarying = 1;
  (data->simulationInfo->realParameter[410] /* weaDat.cheTemDewPoi.TMin PARAM */) = 203.15;
  data->modelData->realParameterData[410].time_unvarying = 1;
  (data->simulationInfo->realParameter[411] /* weaDat.cheTemDryBul.TMax PARAM */) = 343.15;
  data->modelData->realParameterData[411].time_unvarying = 1;
  (data->simulationInfo->realParameter[412] /* weaDat.cheTemDryBul.TMin PARAM */) = 203.15;
  data->modelData->realParameterData[412].time_unvarying = 1;
  (data->simulationInfo->realParameter[413] /* weaDat.con30Min.k PARAM */) = 1800.0;
  data->modelData->realParameterData[413].time_unvarying = 1;
  (data->simulationInfo->realParameter[414] /* weaDat.conOpaSkyCov.k PARAM */) = 0.1;
  data->modelData->realParameterData[414].time_unvarying = 1;
  (data->simulationInfo->realParameter[415] /* weaDat.conRelHum.k PARAM */) = 0.01;
  data->modelData->realParameterData[415].time_unvarying = 1;
  (data->simulationInfo->realParameter[422] /* weaDat.conTotSkyCov.k PARAM */) = 0.1;
  data->modelData->realParameterData[422].time_unvarying = 1;
  (data->simulationInfo->realParameter[427] /* weaDat.horInfRadSel.p PARAM */) = 0.0;
  data->modelData->realParameterData[427].time_unvarying = 1;
  (data->simulationInfo->realParameter[437] /* weaDat.opaSkyCov PARAM */) = 0.5;
  data->modelData->realParameterData[437].time_unvarying = 1;
  (data->simulationInfo->realParameter[438] /* weaDat.opaSkyCovSel.p PARAM */) = 0.5;
  data->modelData->realParameterData[438].time_unvarying = 1;
  (data->simulationInfo->realParameter[439] /* weaDat.pAtm PARAM */) = 101325.0;
  data->modelData->realParameterData[439].time_unvarying = 1;
  (data->simulationInfo->realParameter[440] /* weaDat.pAtmSel.p PARAM */) = 101325.0;
  data->modelData->realParameterData[440].time_unvarying = 1;
  (data->simulationInfo->realParameter[441] /* weaDat.relHum PARAM */) = 0.5;
  data->modelData->realParameterData[441].time_unvarying = 1;
  (data->simulationInfo->realParameter[442] /* weaDat.relHumSel.p PARAM */) = 0.5;
  data->modelData->realParameterData[442].time_unvarying = 1;
  (data->simulationInfo->realParameter[446] /* weaDat.totSkyCov PARAM */) = 0.5;
  data->modelData->realParameterData[446].time_unvarying = 1;
  (data->simulationInfo->realParameter[447] /* weaDat.totSkyCovSel.p PARAM */) = 0.5;
  data->modelData->realParameterData[447].time_unvarying = 1;
  (data->simulationInfo->realParameter[451] /* weaDat.winDir PARAM */) = 1.0;
  data->modelData->realParameterData[451].time_unvarying = 1;
  (data->simulationInfo->realParameter[452] /* weaDat.winDirSel.p PARAM */) = 1.0;
  data->modelData->realParameterData[452].time_unvarying = 1;
  (data->simulationInfo->realParameter[453] /* weaDat.winSpe PARAM */) = 1.0;
  data->modelData->realParameterData[453].time_unvarying = 1;
  (data->simulationInfo->realParameter[454] /* weaDat.winSpeSel.p PARAM */) = 1.0;
  data->modelData->realParameterData[454].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[0] /* HDifTil[1].outGroCon PARAM */) = 1;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[1] /* HDifTil[2].outGroCon PARAM */) = 1;
  data->modelData->booleanParameterData[1].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[2] /* HDifTil[1].outSkyCon PARAM */) = 1;
  data->modelData->booleanParameterData[2].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[3] /* HDifTil[2].outSkyCon PARAM */) = 1;
  data->modelData->booleanParameterData[3].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[4] /* eqAirTemp.withLongwave PARAM */) = 1;
  data->modelData->booleanParameterData[4].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[5] /* eqAirTempVDI.withLongwave PARAM */) = 1;
  data->modelData->booleanParameterData[5].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[6] /* intGai.tableOnFile PARAM */) = 0;
  data->modelData->booleanParameterData[6].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[7] /* intGai.verboseExtrapolation PARAM */) = 0;
  data->modelData->booleanParameterData[7].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[8] /* intGai.verboseRead PARAM */) = 1;
  data->modelData->booleanParameterData[8].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[9] /* thermalZoneFourElements.indoorPortExtWalls PARAM */) = 0;
  data->modelData->booleanParameterData[9].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[10] /* thermalZoneFourElements.indoorPortFloor PARAM */) = 0;
  data->modelData->booleanParameterData[10].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[11] /* thermalZoneFourElements.indoorPortIntWalls PARAM */) = 0;
  data->modelData->booleanParameterData[11].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[12] /* thermalZoneFourElements.indoorPortRoof PARAM */) = 0;
  data->modelData->booleanParameterData[12].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[13] /* thermalZoneFourElements.indoorPortWin PARAM */) = 0;
  data->modelData->booleanParameterData[13].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[14] /* thermalZoneFourElements.use_C_flow PARAM */) = 0;
  data->modelData->booleanParameterData[14].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[15] /* thermalZoneFourElements.use_moisture_balance PARAM */) = 0;
  data->modelData->booleanParameterData[15].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[16] /* thermalZoneFourElements.volAir.allowFlowReversal PARAM */) = 1;
  data->modelData->booleanParameterData[16].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[17] /* thermalZoneFourElements.volAir.dynBal.computeCSen PARAM */) = 0;
  data->modelData->booleanParameterData[17].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[18] /* thermalZoneFourElements.volAir.dynBal.initialize_p PARAM */) = 1;
  data->modelData->booleanParameterData[18].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[19] /* thermalZoneFourElements.volAir.dynBal.medium.preferredMediumStates PARAM */) = 0;
  data->modelData->booleanParameterData[19].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[20] /* thermalZoneFourElements.volAir.dynBal.medium.standardOrderComponents PARAM */) = 1;
  data->modelData->booleanParameterData[20].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[21] /* thermalZoneFourElements.volAir.dynBal.use_C_flow PARAM */) = 0;
  data->modelData->booleanParameterData[21].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[22] /* thermalZoneFourElements.volAir.dynBal.use_mWat_flow PARAM */) = 0;
  data->modelData->booleanParameterData[22].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[23] /* thermalZoneFourElements.volAir.dynBal.wrongEnergyMassBalanceConfiguration PARAM */) = 0;
  data->modelData->booleanParameterData[23].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[24] /* thermalZoneFourElements.volAir.initialize_p PARAM */) = 1;
  data->modelData->booleanParameterData[24].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[25] /* thermalZoneFourElements.volAir.useSteadyStateTwoPort PARAM */) = 0;
  data->modelData->booleanParameterData[25].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[26] /* thermalZoneFourElements.volAir.use_C_flow PARAM */) = 0;
  data->modelData->booleanParameterData[26].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[27] /* thermalZoneFourElements.volAir.wrongEnergyMassBalanceConfiguration PARAM */) = 0;
  data->modelData->booleanParameterData[27].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[28] /* thermalZoneFourElements.wrongEnergyMassBalanceConfiguration PARAM */) = 0;
  data->modelData->booleanParameterData[28].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[29] /* weaDat.computeWetBulbTemperature PARAM */) = 0;
  data->modelData->booleanParameterData[29].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[32] /* weaDat.datRea.tableOnFile PARAM */) = 1;
  data->modelData->booleanParameterData[32].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[33] /* weaDat.datRea.verboseExtrapolation PARAM */) = 0;
  data->modelData->booleanParameterData[33].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[34] /* weaDat.datRea.verboseRead PARAM */) = 0;
  data->modelData->booleanParameterData[34].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[35] /* weaDat.datRea30Min.tableOnFile PARAM */) = 1;
  data->modelData->booleanParameterData[35].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[36] /* weaDat.datRea30Min.verboseExtrapolation PARAM */) = 0;
  data->modelData->booleanParameterData[36].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[37] /* weaDat.datRea30Min.verboseRead PARAM */) = 0;
  data->modelData->booleanParameterData[37].time_unvarying = 1;
  (data->simulationInfo->integerParameter[6] /* intGai.extrapolation PARAM */) = 3;
  data->modelData->integerParameterData[6].time_unvarying = 1;
  (data->simulationInfo->integerParameter[8] /* intGai.smoothness PARAM */) = 1;
  data->modelData->integerParameterData[8].time_unvarying = 1;
  (data->simulationInfo->integerParameter[9] /* intGai.timeEvents PARAM */) = 1;
  data->modelData->integerParameterData[9].time_unvarying = 1;
  (data->simulationInfo->integerParameter[11] /* thermalZoneFourElements.energyDynamics PARAM */) = 2;
  data->modelData->integerParameterData[11].time_unvarying = 1;
  (data->simulationInfo->integerParameter[15] /* thermalZoneFourElements.massDynamics PARAM */) = 2;
  data->modelData->integerParameterData[15].time_unvarying = 1;
  (data->simulationInfo->integerParameter[23] /* thermalZoneFourElements.substanceDynamics PARAM */) = 2;
  data->modelData->integerParameterData[23].time_unvarying = 1;
  (data->simulationInfo->integerParameter[29] /* thermalZoneFourElements.traceDynamics PARAM */) = 2;
  data->modelData->integerParameterData[29].time_unvarying = 1;
  (data->simulationInfo->integerParameter[30] /* thermalZoneFourElements.volAir.dynBal.energyDynamics PARAM */) = 2;
  data->modelData->integerParameterData[30].time_unvarying = 1;
  (data->simulationInfo->integerParameter[31] /* thermalZoneFourElements.volAir.dynBal.massDynamics PARAM */) = 2;
  data->modelData->integerParameterData[31].time_unvarying = 1;
  (data->simulationInfo->integerParameter[33] /* thermalZoneFourElements.volAir.dynBal.substanceDynamics PARAM */) = 2;
  data->modelData->integerParameterData[33].time_unvarying = 1;
  (data->simulationInfo->integerParameter[34] /* thermalZoneFourElements.volAir.dynBal.traceDynamics PARAM */) = 2;
  data->modelData->integerParameterData[34].time_unvarying = 1;
  (data->simulationInfo->integerParameter[35] /* thermalZoneFourElements.volAir.energyDynamics PARAM */) = 2;
  data->modelData->integerParameterData[35].time_unvarying = 1;
  (data->simulationInfo->integerParameter[36] /* thermalZoneFourElements.volAir.massDynamics PARAM */) = 2;
  data->modelData->integerParameterData[36].time_unvarying = 1;
  (data->simulationInfo->integerParameter[38] /* thermalZoneFourElements.volAir.substanceDynamics PARAM */) = 2;
  data->modelData->integerParameterData[38].time_unvarying = 1;
  (data->simulationInfo->integerParameter[39] /* thermalZoneFourElements.volAir.traceDynamics PARAM */) = 2;
  data->modelData->integerParameterData[39].time_unvarying = 1;
  (data->simulationInfo->integerParameter[40] /* weaDat.HInfHorSou PARAM */) = 1;
  data->modelData->integerParameterData[40].time_unvarying = 1;
  (data->simulationInfo->integerParameter[41] /* weaDat.HSou PARAM */) = 1;
  data->modelData->integerParameterData[41].time_unvarying = 1;
  (data->simulationInfo->integerParameter[42] /* weaDat.TBlaSkyCom.calTSky PARAM */) = 1;
  data->modelData->integerParameterData[42].time_unvarying = 1;
  (data->simulationInfo->integerParameter[43] /* weaDat.TBlaSkySel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[43].time_unvarying = 1;
  (data->simulationInfo->integerParameter[44] /* weaDat.TBlaSkySou PARAM */) = 1;
  data->modelData->integerParameterData[44].time_unvarying = 1;
  (data->simulationInfo->integerParameter[45] /* weaDat.TDewPoiSel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[45].time_unvarying = 1;
  (data->simulationInfo->integerParameter[46] /* weaDat.TDewPoiSou PARAM */) = 1;
  data->modelData->integerParameterData[46].time_unvarying = 1;
  (data->simulationInfo->integerParameter[47] /* weaDat.TDryBulSel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[47].time_unvarying = 1;
  (data->simulationInfo->integerParameter[48] /* weaDat.TDryBulSou PARAM */) = 1;
  data->modelData->integerParameterData[48].time_unvarying = 1;
  (data->simulationInfo->integerParameter[49] /* weaDat.calTSky PARAM */) = 1;
  data->modelData->integerParameterData[49].time_unvarying = 1;
  (data->simulationInfo->integerParameter[50] /* weaDat.ceiHeiSel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[50].time_unvarying = 1;
  (data->simulationInfo->integerParameter[51] /* weaDat.ceiHeiSou PARAM */) = 1;
  data->modelData->integerParameterData[51].time_unvarying = 1;
  (data->simulationInfo->integerParameter[78] /* weaDat.datRea.extrapolation PARAM */) = 2;
  data->modelData->integerParameterData[78].time_unvarying = 1;
  (data->simulationInfo->integerParameter[80] /* weaDat.datRea.smoothness PARAM */) = 2;
  data->modelData->integerParameterData[80].time_unvarying = 1;
  (data->simulationInfo->integerParameter[84] /* weaDat.datRea30Min.extrapolation PARAM */) = 2;
  data->modelData->integerParameterData[84].time_unvarying = 1;
  (data->simulationInfo->integerParameter[86] /* weaDat.datRea30Min.smoothness PARAM */) = 2;
  data->modelData->integerParameterData[86].time_unvarying = 1;
  (data->simulationInfo->integerParameter[87] /* weaDat.horInfRadSel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[87].time_unvarying = 1;
  (data->simulationInfo->integerParameter[88] /* weaDat.opaSkyCovSel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[88].time_unvarying = 1;
  (data->simulationInfo->integerParameter[89] /* weaDat.opaSkyCovSou PARAM */) = 1;
  data->modelData->integerParameterData[89].time_unvarying = 1;
  (data->simulationInfo->integerParameter[90] /* weaDat.pAtmSel.datSou PARAM */) = 2;
  data->modelData->integerParameterData[90].time_unvarying = 1;
  (data->simulationInfo->integerParameter[91] /* weaDat.pAtmSou PARAM */) = 2;
  data->modelData->integerParameterData[91].time_unvarying = 1;
  (data->simulationInfo->integerParameter[92] /* weaDat.relHumSel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[92].time_unvarying = 1;
  (data->simulationInfo->integerParameter[93] /* weaDat.relHumSou PARAM */) = 1;
  data->modelData->integerParameterData[93].time_unvarying = 1;
  (data->simulationInfo->integerParameter[94] /* weaDat.souSelRad.datSou PARAM */) = 1;
  data->modelData->integerParameterData[94].time_unvarying = 1;
  (data->simulationInfo->integerParameter[95] /* weaDat.totSkyCovSel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[95].time_unvarying = 1;
  (data->simulationInfo->integerParameter[96] /* weaDat.totSkyCovSou PARAM */) = 1;
  data->modelData->integerParameterData[96].time_unvarying = 1;
  (data->simulationInfo->integerParameter[97] /* weaDat.winDirSel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[97].time_unvarying = 1;
  (data->simulationInfo->integerParameter[98] /* weaDat.winDirSou PARAM */) = 1;
  data->modelData->integerParameterData[98].time_unvarying = 1;
  (data->simulationInfo->integerParameter[99] /* weaDat.winSpeSel.datSou PARAM */) = 1;
  data->modelData->integerParameterData[99].time_unvarying = 1;
  (data->simulationInfo->integerParameter[100] /* weaDat.winSpeSou PARAM */) = 1;
  data->modelData->integerParameterData[100].time_unvarying = 1;
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

