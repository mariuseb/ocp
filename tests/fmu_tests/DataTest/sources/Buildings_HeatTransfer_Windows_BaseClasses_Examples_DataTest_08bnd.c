#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/Desktop/XML_dump/Buildings.HeatTransfer.Windows.BaseClasses.Examples.DataTest/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest.fmutmp/sources/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_08bnd.c"
#endif
/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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

void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 45
type: SIMPLE_ASSIGN
radDat.tauShaSol_a = glaSys.shade.tauSol_a
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
#line 25 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  (data->simulationInfo->realParameter[150] /* radDat.tauShaSol_a PARAM */) = (data->simulationInfo->realParameter[49] /* glaSys.shade.tauSol_a PARAM */);
#line 50 OMC_FILE
  TRACE_POP
}

/*
equation index: 46
type: SIMPLE_ASSIGN
radDat.traRefShaDev[1,1] = radDat.tauShaSol_a
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */) = (data->simulationInfo->realParameter[150] /* radDat.tauShaSol_a PARAM */);
#line 66 OMC_FILE
  TRACE_POP
}

/*
equation index: 47
type: SIMPLE_ASSIGN
radDat.tauShaSol_b = glaSys.shade.tauSol_b
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
#line 28 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  (data->simulationInfo->realParameter[151] /* radDat.tauShaSol_b PARAM */) = (data->simulationInfo->realParameter[50] /* glaSys.shade.tauSol_b PARAM */);
#line 82 OMC_FILE
  TRACE_POP
}

/*
equation index: 48
type: SIMPLE_ASSIGN
radDat.traRefShaDev[1,2] = radDat.tauShaSol_b
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[186] /* radDat.traRefShaDev[1,2] PARAM */) = (data->simulationInfo->realParameter[151] /* radDat.tauShaSol_b PARAM */);
#line 98 OMC_FILE
  TRACE_POP
}

/*
equation index: 49
type: SIMPLE_ASSIGN
radDat.rhoShaSol_a = glaSys.shade.rhoSol_a
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
#line 31 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  (data->simulationInfo->realParameter[147] /* radDat.rhoShaSol_a PARAM */) = (data->simulationInfo->realParameter[45] /* glaSys.shade.rhoSol_a PARAM */);
#line 114 OMC_FILE
  TRACE_POP
}

/*
equation index: 50
type: SIMPLE_ASSIGN
radDat.traRefShaDev[2,1] = radDat.rhoShaSol_a
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[187] /* radDat.traRefShaDev[2,1] PARAM */) = (data->simulationInfo->realParameter[147] /* radDat.rhoShaSol_a PARAM */);
#line 130 OMC_FILE
  TRACE_POP
}

/*
equation index: 51
type: SIMPLE_ASSIGN
radDat.rhoShaSol_b = glaSys.shade.rhoSol_b
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
#line 34 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  (data->simulationInfo->realParameter[148] /* radDat.rhoShaSol_b PARAM */) = (data->simulationInfo->realParameter[46] /* glaSys.shade.rhoSol_b PARAM */);
#line 146 OMC_FILE
  TRACE_POP
}

/*
equation index: 52
type: SIMPLE_ASSIGN
radDat.traRefShaDev[2,2] = radDat.rhoShaSol_b
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[188] /* radDat.traRefShaDev[2,2] PARAM */) = (data->simulationInfo->realParameter[148] /* radDat.rhoShaSol_b PARAM */);
#line 162 OMC_FILE
  TRACE_POP
}

/*
equation index: 53
type: SIMPLE_ASSIGN
radDat.xGla[1] = glaSys.glass[1].x
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  (data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */) = (data->simulationInfo->realParameter[42] /* glaSys.glass[1].x PARAM */);
#line 178 OMC_FILE
  TRACE_POP
}

/*
equation index: 54
type: SIMPLE_ASSIGN
radDat.tauGlaSol[1,1] = glaSys.glass[1].tauSol[1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
#line 16 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  (data->simulationInfo->realParameter[149] /* radDat.tauGlaSol[1,1] PARAM */) = (data->simulationInfo->realParameter[41] /* glaSys.glass[1].tauSol[1] PARAM */);
#line 194 OMC_FILE
  TRACE_POP
}

/*
equation index: 55
type: SIMPLE_ASSIGN
radDat.glass[1,1,1] = radDat.tauGlaSol[1,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
#line 5 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */) = (data->simulationInfo->realParameter[149] /* radDat.tauGlaSol[1,1] PARAM */);
#line 210 OMC_FILE
  TRACE_POP
}

/*
equation index: 56
type: SIMPLE_ASSIGN
radDat.rhoGlaSol_a[1,1] = glaSys.glass[1].rhoSol_a[1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
#line 18 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  (data->simulationInfo->realParameter[145] /* radDat.rhoGlaSol_a[1,1] PARAM */) = (data->simulationInfo->realParameter[38] /* glaSys.glass[1].rhoSol_a[1] PARAM */);
#line 226 OMC_FILE
  TRACE_POP
}

/*
equation index: 57
type: SIMPLE_ASSIGN
radDat.glass[2,1,1] = radDat.rhoGlaSol_a[1,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
#line 5 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[100] /* radDat.glass[2,1,1] PARAM */) = (data->simulationInfo->realParameter[145] /* radDat.rhoGlaSol_a[1,1] PARAM */);
#line 242 OMC_FILE
  TRACE_POP
}

/*
equation index: 58
type: SIMPLE_ASSIGN
radDat.rhoGlaSol_b[1,1] = glaSys.glass[1].rhoSol_b[1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  (data->simulationInfo->realParameter[146] /* radDat.rhoGlaSol_b[1,1] PARAM */) = (data->simulationInfo->realParameter[39] /* glaSys.glass[1].rhoSol_b[1] PARAM */);
#line 258 OMC_FILE
  TRACE_POP
}

/*
equation index: 59
type: SIMPLE_ASSIGN
radDat.glass[3,1,1] = radDat.rhoGlaSol_b[1,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
#line 5 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[101] /* radDat.glass[3,1,1] PARAM */) = (data->simulationInfo->realParameter[146] /* radDat.rhoGlaSol_b[1,1] PARAM */);
#line 274 OMC_FILE
  TRACE_POP
}

/*
equation index: 60
type: SIMPLE_ASSIGN
radDat.layer[1,1,1,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  real_array tmp0;
  real_array tmp1;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp0, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp1, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp0, tmp1, _OMC_LIT15), 0, 0, 0, 0);
#line 296 OMC_FILE
  TRACE_POP
}

/*
equation index: 61
type: SIMPLE_ASSIGN
radDat.layer[1,1,2,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  real_array tmp2;
  real_array tmp3;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp2, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp3, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[103] /* radDat.layer[1,1,2,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp2, tmp3, _OMC_LIT15), 0, 0, 1, 0);
#line 318 OMC_FILE
  TRACE_POP
}

/*
equation index: 62
type: SIMPLE_ASSIGN
radDat.layer[1,1,3,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  real_array tmp4;
  real_array tmp5;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp4, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp5, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[104] /* radDat.layer[1,1,3,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp4, tmp5, _OMC_LIT15), 0, 0, 2, 0);
#line 340 OMC_FILE
  TRACE_POP
}

/*
equation index: 63
type: SIMPLE_ASSIGN
radDat.layer[1,1,4,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  real_array tmp6;
  real_array tmp7;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp6, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp7, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[105] /* radDat.layer[1,1,4,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp6, tmp7, _OMC_LIT15), 0, 0, 3, 0);
#line 362 OMC_FILE
  TRACE_POP
}

/*
equation index: 64
type: SIMPLE_ASSIGN
radDat.layer[1,1,5,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  real_array tmp8;
  real_array tmp9;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp8, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp9, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[106] /* radDat.layer[1,1,5,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp8, tmp9, _OMC_LIT15), 0, 0, 4, 0);
#line 384 OMC_FILE
  TRACE_POP
}

/*
equation index: 65
type: SIMPLE_ASSIGN
radDat.layer[1,1,6,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  real_array tmp10;
  real_array tmp11;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp10, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp11, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[107] /* radDat.layer[1,1,6,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp10, tmp11, _OMC_LIT15), 0, 0, 5, 0);
#line 406 OMC_FILE
  TRACE_POP
}

/*
equation index: 66
type: SIMPLE_ASSIGN
radDat.layer[1,1,7,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  real_array tmp12;
  real_array tmp13;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp12, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp13, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[108] /* radDat.layer[1,1,7,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp12, tmp13, _OMC_LIT15), 0, 0, 6, 0);
#line 428 OMC_FILE
  TRACE_POP
}

/*
equation index: 67
type: SIMPLE_ASSIGN
radDat.layer[1,1,8,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
  real_array tmp14;
  real_array tmp15;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp14, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp15, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[109] /* radDat.layer[1,1,8,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp14, tmp15, _OMC_LIT15), 0, 0, 7, 0);
#line 450 OMC_FILE
  TRACE_POP
}

/*
equation index: 68
type: SIMPLE_ASSIGN
radDat.layer[1,1,9,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  real_array tmp16;
  real_array tmp17;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp16, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp17, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[110] /* radDat.layer[1,1,9,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp16, tmp17, _OMC_LIT15), 0, 0, 8, 0);
#line 472 OMC_FILE
  TRACE_POP
}

/*
equation index: 69
type: SIMPLE_ASSIGN
radDat.layer[1,1,10,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  real_array tmp18;
  real_array tmp19;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp18, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp19, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[111] /* radDat.layer[1,1,10,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp18, tmp19, _OMC_LIT15), 0, 0, 9, 0);
#line 494 OMC_FILE
  TRACE_POP
}

/*
equation index: 70
type: SIMPLE_ASSIGN
radDat.layer[1,1,11,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[1, 1, 11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
  real_array tmp20;
  real_array tmp21;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp20, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp21, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[112] /* radDat.layer[1,1,11,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp20, tmp21, _OMC_LIT15), 0, 0, 10, 0);
#line 516 OMC_FILE
  TRACE_POP
}

/*
equation index: 71
type: SIMPLE_ASSIGN
radDat.layer[2,1,1,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  real_array tmp22;
  real_array tmp23;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp22, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp23, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[113] /* radDat.layer[2,1,1,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp22, tmp23, _OMC_LIT15), 1, 0, 0, 0);
#line 538 OMC_FILE
  TRACE_POP
}

/*
equation index: 72
type: SIMPLE_ASSIGN
radDat.layer[2,1,2,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_72(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,72};
  real_array tmp24;
  real_array tmp25;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp24, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp25, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[114] /* radDat.layer[2,1,2,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp24, tmp25, _OMC_LIT15), 1, 0, 1, 0);
#line 560 OMC_FILE
  TRACE_POP
}

/*
equation index: 73
type: SIMPLE_ASSIGN
radDat.layer[2,1,3,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  real_array tmp26;
  real_array tmp27;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp26, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp27, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[115] /* radDat.layer[2,1,3,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp26, tmp27, _OMC_LIT15), 1, 0, 2, 0);
#line 582 OMC_FILE
  TRACE_POP
}

/*
equation index: 74
type: SIMPLE_ASSIGN
radDat.layer[2,1,4,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_74(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,74};
  real_array tmp28;
  real_array tmp29;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp28, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp29, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[116] /* radDat.layer[2,1,4,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp28, tmp29, _OMC_LIT15), 1, 0, 3, 0);
#line 604 OMC_FILE
  TRACE_POP
}

/*
equation index: 75
type: SIMPLE_ASSIGN
radDat.layer[2,1,5,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_75(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  real_array tmp30;
  real_array tmp31;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp30, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp31, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[117] /* radDat.layer[2,1,5,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp30, tmp31, _OMC_LIT15), 1, 0, 4, 0);
#line 626 OMC_FILE
  TRACE_POP
}

/*
equation index: 76
type: SIMPLE_ASSIGN
radDat.layer[2,1,6,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_76(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
  real_array tmp32;
  real_array tmp33;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp32, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp33, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[118] /* radDat.layer[2,1,6,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp32, tmp33, _OMC_LIT15), 1, 0, 5, 0);
#line 648 OMC_FILE
  TRACE_POP
}

/*
equation index: 77
type: SIMPLE_ASSIGN
radDat.layer[2,1,7,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_77(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
  real_array tmp34;
  real_array tmp35;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp34, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp35, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[119] /* radDat.layer[2,1,7,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp34, tmp35, _OMC_LIT15), 1, 0, 6, 0);
#line 670 OMC_FILE
  TRACE_POP
}

/*
equation index: 78
type: SIMPLE_ASSIGN
radDat.layer[2,1,8,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_78(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  real_array tmp36;
  real_array tmp37;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp36, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp37, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[120] /* radDat.layer[2,1,8,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp36, tmp37, _OMC_LIT15), 1, 0, 7, 0);
#line 692 OMC_FILE
  TRACE_POP
}

/*
equation index: 79
type: SIMPLE_ASSIGN
radDat.layer[2,1,9,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  real_array tmp38;
  real_array tmp39;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp38, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp39, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[121] /* radDat.layer[2,1,9,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp38, tmp39, _OMC_LIT15), 1, 0, 8, 0);
#line 714 OMC_FILE
  TRACE_POP
}

/*
equation index: 80
type: SIMPLE_ASSIGN
radDat.layer[2,1,10,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_80(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  real_array tmp40;
  real_array tmp41;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp40, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp41, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[122] /* radDat.layer[2,1,10,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp40, tmp41, _OMC_LIT15), 1, 0, 9, 0);
#line 736 OMC_FILE
  TRACE_POP
}

/*
equation index: 81
type: SIMPLE_ASSIGN
radDat.layer[2,1,11,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[2, 1, 11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  real_array tmp42;
  real_array tmp43;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp42, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp43, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[123] /* radDat.layer[2,1,11,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp42, tmp43, _OMC_LIT15), 1, 0, 10, 0);
#line 758 OMC_FILE
  TRACE_POP
}

/*
equation index: 82
type: SIMPLE_ASSIGN
radDat.layer[3,1,1,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_82(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
  real_array tmp44;
  real_array tmp45;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp44, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp45, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[124] /* radDat.layer[3,1,1,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp44, tmp45, _OMC_LIT15), 2, 0, 0, 0);
#line 780 OMC_FILE
  TRACE_POP
}

/*
equation index: 83
type: SIMPLE_ASSIGN
radDat.layer[3,1,2,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  real_array tmp46;
  real_array tmp47;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp46, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp47, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[125] /* radDat.layer[3,1,2,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp46, tmp47, _OMC_LIT15), 2, 0, 1, 0);
#line 802 OMC_FILE
  TRACE_POP
}

/*
equation index: 84
type: SIMPLE_ASSIGN
radDat.layer[3,1,3,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  real_array tmp48;
  real_array tmp49;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp48, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp49, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[126] /* radDat.layer[3,1,3,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp48, tmp49, _OMC_LIT15), 2, 0, 2, 0);
#line 824 OMC_FILE
  TRACE_POP
}

/*
equation index: 85
type: SIMPLE_ASSIGN
radDat.layer[3,1,4,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_85(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
  real_array tmp50;
  real_array tmp51;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp50, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp51, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[127] /* radDat.layer[3,1,4,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp50, tmp51, _OMC_LIT15), 2, 0, 3, 0);
#line 846 OMC_FILE
  TRACE_POP
}

/*
equation index: 86
type: SIMPLE_ASSIGN
radDat.layer[3,1,5,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_86(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,86};
  real_array tmp52;
  real_array tmp53;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp52, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp53, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[128] /* radDat.layer[3,1,5,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp52, tmp53, _OMC_LIT15), 2, 0, 4, 0);
#line 868 OMC_FILE
  TRACE_POP
}

/*
equation index: 87
type: SIMPLE_ASSIGN
radDat.layer[3,1,6,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_87(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
  real_array tmp54;
  real_array tmp55;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp54, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp55, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[129] /* radDat.layer[3,1,6,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp54, tmp55, _OMC_LIT15), 2, 0, 5, 0);
#line 890 OMC_FILE
  TRACE_POP
}

/*
equation index: 88
type: SIMPLE_ASSIGN
radDat.layer[3,1,7,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  real_array tmp56;
  real_array tmp57;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp56, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp57, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[130] /* radDat.layer[3,1,7,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp56, tmp57, _OMC_LIT15), 2, 0, 6, 0);
#line 912 OMC_FILE
  TRACE_POP
}

/*
equation index: 89
type: SIMPLE_ASSIGN
radDat.layer[3,1,8,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  real_array tmp58;
  real_array tmp59;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp58, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp59, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[131] /* radDat.layer[3,1,8,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp58, tmp59, _OMC_LIT15), 2, 0, 7, 0);
#line 934 OMC_FILE
  TRACE_POP
}

/*
equation index: 90
type: SIMPLE_ASSIGN
radDat.layer[3,1,9,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  real_array tmp60;
  real_array tmp61;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp60, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp61, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[132] /* radDat.layer[3,1,9,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp60, tmp61, _OMC_LIT15), 2, 0, 8, 0);
#line 956 OMC_FILE
  TRACE_POP
}

/*
equation index: 91
type: SIMPLE_ASSIGN
radDat.layer[3,1,10,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_91(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
  real_array tmp62;
  real_array tmp63;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp62, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp63, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[133] /* radDat.layer[3,1,10,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp62, tmp63, _OMC_LIT15), 2, 0, 9, 0);
#line 978 OMC_FILE
  TRACE_POP
}

/*
equation index: 92
type: SIMPLE_ASSIGN
radDat.layer[3,1,11,1] = Buildings.HeatTransfer.Windows.Functions.glassProperty(1, 1, 11, radDat.glass, radDat.xGla, {0.0, 0.1745329251994329, 0.3490658503988659, 0.5235987755982988, 0.6981317007977318, 0.8726646259971648, 1.047197551196598, 1.221730476396031, 1.396263401595464, 1.570796326794897})[3, 1, 11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  real_array tmp64;
  real_array tmp65;
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp64, ((modelica_real*)&((&data->simulationInfo->realParameter[99] /* radDat.glass[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)3, (_index_t)1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp65, ((modelica_real*)&((&data->simulationInfo->realParameter[217] /* radDat.xGla[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 14 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[134] /* radDat.layer[3,1,11,1] PARAM */) = real_get_4D(omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp64, tmp65, _OMC_LIT15), 2, 0, 10, 0);
#line 1000 OMC_FILE
  TRACE_POP
}

/*
equation index: 93
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,1,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
  real_array tmp66;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp66, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp66), 0, 0, 0, 0, 0);
#line 1019 OMC_FILE
  TRACE_POP
}

/*
equation index: 94
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,2,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
  real_array tmp67;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp67, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[153] /* radDat.traRef[1,1,1,2,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp67), 0, 0, 0, 1, 0);
#line 1038 OMC_FILE
  TRACE_POP
}

/*
equation index: 95
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,3,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,95};
  real_array tmp68;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp68, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[154] /* radDat.traRef[1,1,1,3,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp68), 0, 0, 0, 2, 0);
#line 1057 OMC_FILE
  TRACE_POP
}

/*
equation index: 96
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,4,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
  real_array tmp69;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp69, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[155] /* radDat.traRef[1,1,1,4,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp69), 0, 0, 0, 3, 0);
#line 1076 OMC_FILE
  TRACE_POP
}

/*
equation index: 97
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,5,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_97(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,97};
  real_array tmp70;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp70, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[156] /* radDat.traRef[1,1,1,5,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp70), 0, 0, 0, 4, 0);
#line 1095 OMC_FILE
  TRACE_POP
}

/*
equation index: 98
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,6,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
  real_array tmp71;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp71, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[157] /* radDat.traRef[1,1,1,6,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp71), 0, 0, 0, 5, 0);
#line 1114 OMC_FILE
  TRACE_POP
}

/*
equation index: 99
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,7,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
  real_array tmp72;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp72, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[158] /* radDat.traRef[1,1,1,7,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp72), 0, 0, 0, 6, 0);
#line 1133 OMC_FILE
  TRACE_POP
}

/*
equation index: 100
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,8,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  real_array tmp73;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp73, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[159] /* radDat.traRef[1,1,1,8,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp73), 0, 0, 0, 7, 0);
#line 1152 OMC_FILE
  TRACE_POP
}

/*
equation index: 101
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,9,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  real_array tmp74;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp74, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[160] /* radDat.traRef[1,1,1,9,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp74), 0, 0, 0, 8, 0);
#line 1171 OMC_FILE
  TRACE_POP
}

/*
equation index: 102
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,10,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  real_array tmp75;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp75, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[161] /* radDat.traRef[1,1,1,10,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp75), 0, 0, 0, 9, 0);
#line 1190 OMC_FILE
  TRACE_POP
}

/*
equation index: 103
type: SIMPLE_ASSIGN
radDat.traRef[1,1,1,11,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[1, 1, 1, 11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
  real_array tmp76;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp76, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[162] /* radDat.traRef[1,1,1,11,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp76), 0, 0, 0, 10, 0);
#line 1209 OMC_FILE
  TRACE_POP
}

/*
equation index: 104
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,1,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,104};
  real_array tmp77;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp77, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[163] /* radDat.traRef[2,1,1,1,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp77), 1, 0, 0, 0, 0);
#line 1228 OMC_FILE
  TRACE_POP
}

/*
equation index: 105
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,2,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
  real_array tmp78;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp78, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[164] /* radDat.traRef[2,1,1,2,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp78), 1, 0, 0, 1, 0);
#line 1247 OMC_FILE
  TRACE_POP
}

/*
equation index: 106
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,3,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  real_array tmp79;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp79, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[165] /* radDat.traRef[2,1,1,3,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp79), 1, 0, 0, 2, 0);
#line 1266 OMC_FILE
  TRACE_POP
}

/*
equation index: 107
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,4,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
  real_array tmp80;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp80, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[166] /* radDat.traRef[2,1,1,4,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp80), 1, 0, 0, 3, 0);
#line 1285 OMC_FILE
  TRACE_POP
}

/*
equation index: 108
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,5,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
  real_array tmp81;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp81, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[167] /* radDat.traRef[2,1,1,5,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp81), 1, 0, 0, 4, 0);
#line 1304 OMC_FILE
  TRACE_POP
}

/*
equation index: 109
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,6,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
  real_array tmp82;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp82, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[168] /* radDat.traRef[2,1,1,6,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp82), 1, 0, 0, 5, 0);
#line 1323 OMC_FILE
  TRACE_POP
}

/*
equation index: 110
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,7,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
  real_array tmp83;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp83, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[169] /* radDat.traRef[2,1,1,7,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp83), 1, 0, 0, 6, 0);
#line 1342 OMC_FILE
  TRACE_POP
}

/*
equation index: 111
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,8,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  real_array tmp84;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp84, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[170] /* radDat.traRef[2,1,1,8,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp84), 1, 0, 0, 7, 0);
#line 1361 OMC_FILE
  TRACE_POP
}

/*
equation index: 112
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,9,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
  real_array tmp85;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp85, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[171] /* radDat.traRef[2,1,1,9,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp85), 1, 0, 0, 8, 0);
#line 1380 OMC_FILE
  TRACE_POP
}

/*
equation index: 113
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,10,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
  real_array tmp86;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp86, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[172] /* radDat.traRef[2,1,1,10,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp86), 1, 0, 0, 9, 0);
#line 1399 OMC_FILE
  TRACE_POP
}

/*
equation index: 114
type: SIMPLE_ASSIGN
radDat.traRef[2,1,1,11,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[2, 1, 1, 11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
  real_array tmp87;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp87, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[173] /* radDat.traRef[2,1,1,11,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp87), 1, 0, 0, 10, 0);
#line 1418 OMC_FILE
  TRACE_POP
}

/*
equation index: 115
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,1,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  real_array tmp88;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp88, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[174] /* radDat.traRef[3,1,1,1,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp88), 2, 0, 0, 0, 0);
#line 1437 OMC_FILE
  TRACE_POP
}

/*
equation index: 116
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,2,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
  real_array tmp89;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp89, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[175] /* radDat.traRef[3,1,1,2,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp89), 2, 0, 0, 1, 0);
#line 1456 OMC_FILE
  TRACE_POP
}

/*
equation index: 117
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,3,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
  real_array tmp90;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp90, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[176] /* radDat.traRef[3,1,1,3,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp90), 2, 0, 0, 2, 0);
#line 1475 OMC_FILE
  TRACE_POP
}

/*
equation index: 118
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,4,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
  real_array tmp91;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp91, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[177] /* radDat.traRef[3,1,1,4,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp91), 2, 0, 0, 3, 0);
#line 1494 OMC_FILE
  TRACE_POP
}

/*
equation index: 119
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,5,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
  real_array tmp92;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp92, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[178] /* radDat.traRef[3,1,1,5,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp92), 2, 0, 0, 4, 0);
#line 1513 OMC_FILE
  TRACE_POP
}

/*
equation index: 120
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,6,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  real_array tmp93;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp93, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[179] /* radDat.traRef[3,1,1,6,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp93), 2, 0, 0, 5, 0);
#line 1532 OMC_FILE
  TRACE_POP
}

/*
equation index: 121
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,7,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
  real_array tmp94;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp94, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[180] /* radDat.traRef[3,1,1,7,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp94), 2, 0, 0, 6, 0);
#line 1551 OMC_FILE
  TRACE_POP
}

/*
equation index: 122
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,8,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  real_array tmp95;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp95, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[181] /* radDat.traRef[3,1,1,8,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp95), 2, 0, 0, 7, 0);
#line 1570 OMC_FILE
  TRACE_POP
}

/*
equation index: 123
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,9,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  real_array tmp96;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp96, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[182] /* radDat.traRef[3,1,1,9,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp96), 2, 0, 0, 8, 0);
#line 1589 OMC_FILE
  TRACE_POP
}

/*
equation index: 124
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,10,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  real_array tmp97;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp97, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[183] /* radDat.traRef[3,1,1,10,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp97), 2, 0, 0, 9, 0);
#line 1608 OMC_FILE
  TRACE_POP
}

/*
equation index: 125
type: SIMPLE_ASSIGN
radDat.traRef[3,1,1,11,1] = Buildings.HeatTransfer.Windows.Functions.getGlassTR(1, 1, 11, radDat.layer)[3, 1, 1, 11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
  real_array tmp98;
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp98, ((modelica_real*)&((&data->simulationInfo->realParameter[102] /* radDat.layer[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 4, (_index_t)3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 23 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[184] /* radDat.traRef[3,1,1,11,1] PARAM */) = real_get_5D(omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11), tmp98), 2, 0, 0, 10, 0);
#line 1627 OMC_FILE
  TRACE_POP
}

/*
equation index: 126
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,1,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
  real_array tmp99;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp99, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp99, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0, 0);
#line 1646 OMC_FILE
  TRACE_POP
}

/*
equation index: 127
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,2,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
  real_array tmp100;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp100, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[74] /* radDat.absExtIrrNoSha[1,2,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp100, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 1, 0);
#line 1665 OMC_FILE
  TRACE_POP
}

/*
equation index: 128
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,3,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
  real_array tmp101;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp101, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[75] /* radDat.absExtIrrNoSha[1,3,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp101, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 2, 0);
#line 1684 OMC_FILE
  TRACE_POP
}

/*
equation index: 129
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,4,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,129};
  real_array tmp102;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp102, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[76] /* radDat.absExtIrrNoSha[1,4,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp102, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 3, 0);
#line 1703 OMC_FILE
  TRACE_POP
}

/*
equation index: 130
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,5,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
  real_array tmp103;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp103, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[77] /* radDat.absExtIrrNoSha[1,5,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp103, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 4, 0);
#line 1722 OMC_FILE
  TRACE_POP
}

/*
equation index: 131
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,6,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
  real_array tmp104;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp104, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[78] /* radDat.absExtIrrNoSha[1,6,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp104, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 5, 0);
#line 1741 OMC_FILE
  TRACE_POP
}

/*
equation index: 132
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,7,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
  real_array tmp105;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp105, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[79] /* radDat.absExtIrrNoSha[1,7,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp105, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 6, 0);
#line 1760 OMC_FILE
  TRACE_POP
}

/*
equation index: 133
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,8,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,133};
  real_array tmp106;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp106, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[80] /* radDat.absExtIrrNoSha[1,8,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp106, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 7, 0);
#line 1779 OMC_FILE
  TRACE_POP
}

/*
equation index: 134
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,9,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
  real_array tmp107;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp107, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[81] /* radDat.absExtIrrNoSha[1,9,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp107, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 8, 0);
#line 1798 OMC_FILE
  TRACE_POP
}

/*
equation index: 135
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,10,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,135};
  real_array tmp108;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp108, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[82] /* radDat.absExtIrrNoSha[1,10,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp108, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 9, 0);
#line 1817 OMC_FILE
  TRACE_POP
}

/*
equation index: 136
type: SIMPLE_ASSIGN
radDat.absExtIrrNoSha[1,11,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
  real_array tmp109;
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp109, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 30 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[83] /* radDat.absExtIrrNoSha[1,11,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, tmp109, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 10, 0);
#line 1836 OMC_FILE
  TRACE_POP
}

/*
equation index: 137
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,1,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
  real_array tmp110;
  real_array tmp111;
  real_array tmp112;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp110, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp111, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp112, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[51] /* radDat.absExtIrrExtSha[1,1,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp110, tmp111, tmp112, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0, 0);
#line 1861 OMC_FILE
  TRACE_POP
}

/*
equation index: 138
type: SIMPLE_ASSIGN
$outputAlias_y[1,1,1] = radDat.absExtIrrExtSha[1,1,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[11] /* $outputAlias_y[1,1,1] PARAM */) = (data->simulationInfo->realParameter[51] /* radDat.absExtIrrExtSha[1,1,1] PARAM */);
#line 1877 OMC_FILE
  TRACE_POP
}

/*
equation index: 139
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,1,1] = radDat.absExtIrrExtSha[1,1,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[0] /* $outputAlias_recordTest[1,1,1] PARAM */) = (data->simulationInfo->realParameter[51] /* radDat.absExtIrrExtSha[1,1,1] PARAM */);
#line 1893 OMC_FILE
  TRACE_POP
}

/*
equation index: 140
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,2,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  real_array tmp113;
  real_array tmp114;
  real_array tmp115;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp113, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp114, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp115, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[52] /* radDat.absExtIrrExtSha[1,2,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp113, tmp114, tmp115, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 1, 0);
#line 1918 OMC_FILE
  TRACE_POP
}

/*
equation index: 141
type: SIMPLE_ASSIGN
$outputAlias_y[1,2,1] = radDat.absExtIrrExtSha[1,2,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[12] /* $outputAlias_y[1,2,1] PARAM */) = (data->simulationInfo->realParameter[52] /* radDat.absExtIrrExtSha[1,2,1] PARAM */);
#line 1934 OMC_FILE
  TRACE_POP
}

/*
equation index: 142
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,2,1] = radDat.absExtIrrExtSha[1,2,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[1] /* $outputAlias_recordTest[1,2,1] PARAM */) = (data->simulationInfo->realParameter[52] /* radDat.absExtIrrExtSha[1,2,1] PARAM */);
#line 1950 OMC_FILE
  TRACE_POP
}

/*
equation index: 143
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,3,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
  real_array tmp116;
  real_array tmp117;
  real_array tmp118;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp116, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp117, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp118, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[53] /* radDat.absExtIrrExtSha[1,3,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp116, tmp117, tmp118, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 2, 0);
#line 1975 OMC_FILE
  TRACE_POP
}

/*
equation index: 144
type: SIMPLE_ASSIGN
$outputAlias_y[1,3,1] = radDat.absExtIrrExtSha[1,3,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[13] /* $outputAlias_y[1,3,1] PARAM */) = (data->simulationInfo->realParameter[53] /* radDat.absExtIrrExtSha[1,3,1] PARAM */);
#line 1991 OMC_FILE
  TRACE_POP
}

/*
equation index: 145
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,3,1] = radDat.absExtIrrExtSha[1,3,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[2] /* $outputAlias_recordTest[1,3,1] PARAM */) = (data->simulationInfo->realParameter[53] /* radDat.absExtIrrExtSha[1,3,1] PARAM */);
#line 2007 OMC_FILE
  TRACE_POP
}

/*
equation index: 146
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,4,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
  real_array tmp119;
  real_array tmp120;
  real_array tmp121;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp119, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp120, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp121, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[54] /* radDat.absExtIrrExtSha[1,4,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp119, tmp120, tmp121, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 3, 0);
#line 2032 OMC_FILE
  TRACE_POP
}

/*
equation index: 147
type: SIMPLE_ASSIGN
$outputAlias_y[1,4,1] = radDat.absExtIrrExtSha[1,4,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[14] /* $outputAlias_y[1,4,1] PARAM */) = (data->simulationInfo->realParameter[54] /* radDat.absExtIrrExtSha[1,4,1] PARAM */);
#line 2048 OMC_FILE
  TRACE_POP
}

/*
equation index: 148
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,4,1] = radDat.absExtIrrExtSha[1,4,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,148};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[3] /* $outputAlias_recordTest[1,4,1] PARAM */) = (data->simulationInfo->realParameter[54] /* radDat.absExtIrrExtSha[1,4,1] PARAM */);
#line 2064 OMC_FILE
  TRACE_POP
}

/*
equation index: 149
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,5,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
  real_array tmp122;
  real_array tmp123;
  real_array tmp124;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp122, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp123, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp124, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[55] /* radDat.absExtIrrExtSha[1,5,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp122, tmp123, tmp124, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 4, 0);
#line 2089 OMC_FILE
  TRACE_POP
}

/*
equation index: 150
type: SIMPLE_ASSIGN
$outputAlias_y[1,5,1] = radDat.absExtIrrExtSha[1,5,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[15] /* $outputAlias_y[1,5,1] PARAM */) = (data->simulationInfo->realParameter[55] /* radDat.absExtIrrExtSha[1,5,1] PARAM */);
#line 2105 OMC_FILE
  TRACE_POP
}

/*
equation index: 151
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,5,1] = radDat.absExtIrrExtSha[1,5,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[4] /* $outputAlias_recordTest[1,5,1] PARAM */) = (data->simulationInfo->realParameter[55] /* radDat.absExtIrrExtSha[1,5,1] PARAM */);
#line 2121 OMC_FILE
  TRACE_POP
}

/*
equation index: 152
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,6,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
  real_array tmp125;
  real_array tmp126;
  real_array tmp127;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp125, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp126, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp127, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[56] /* radDat.absExtIrrExtSha[1,6,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp125, tmp126, tmp127, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 5, 0);
#line 2146 OMC_FILE
  TRACE_POP
}

/*
equation index: 153
type: SIMPLE_ASSIGN
$outputAlias_y[1,6,1] = radDat.absExtIrrExtSha[1,6,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[16] /* $outputAlias_y[1,6,1] PARAM */) = (data->simulationInfo->realParameter[56] /* radDat.absExtIrrExtSha[1,6,1] PARAM */);
#line 2162 OMC_FILE
  TRACE_POP
}

/*
equation index: 154
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,6,1] = radDat.absExtIrrExtSha[1,6,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[5] /* $outputAlias_recordTest[1,6,1] PARAM */) = (data->simulationInfo->realParameter[56] /* radDat.absExtIrrExtSha[1,6,1] PARAM */);
#line 2178 OMC_FILE
  TRACE_POP
}

/*
equation index: 155
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,7,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
  real_array tmp128;
  real_array tmp129;
  real_array tmp130;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp128, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp129, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp130, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[57] /* radDat.absExtIrrExtSha[1,7,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp128, tmp129, tmp130, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 6, 0);
#line 2203 OMC_FILE
  TRACE_POP
}

/*
equation index: 156
type: SIMPLE_ASSIGN
$outputAlias_y[1,7,1] = radDat.absExtIrrExtSha[1,7,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,156};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[17] /* $outputAlias_y[1,7,1] PARAM */) = (data->simulationInfo->realParameter[57] /* radDat.absExtIrrExtSha[1,7,1] PARAM */);
#line 2219 OMC_FILE
  TRACE_POP
}

/*
equation index: 157
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,7,1] = radDat.absExtIrrExtSha[1,7,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,157};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[6] /* $outputAlias_recordTest[1,7,1] PARAM */) = (data->simulationInfo->realParameter[57] /* radDat.absExtIrrExtSha[1,7,1] PARAM */);
#line 2235 OMC_FILE
  TRACE_POP
}

/*
equation index: 158
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,8,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
  real_array tmp131;
  real_array tmp132;
  real_array tmp133;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp131, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp132, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp133, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[58] /* radDat.absExtIrrExtSha[1,8,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp131, tmp132, tmp133, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 7, 0);
#line 2260 OMC_FILE
  TRACE_POP
}

/*
equation index: 159
type: SIMPLE_ASSIGN
$outputAlias_y[1,8,1] = radDat.absExtIrrExtSha[1,8,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,159};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[18] /* $outputAlias_y[1,8,1] PARAM */) = (data->simulationInfo->realParameter[58] /* radDat.absExtIrrExtSha[1,8,1] PARAM */);
#line 2276 OMC_FILE
  TRACE_POP
}

/*
equation index: 160
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,8,1] = radDat.absExtIrrExtSha[1,8,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[7] /* $outputAlias_recordTest[1,8,1] PARAM */) = (data->simulationInfo->realParameter[58] /* radDat.absExtIrrExtSha[1,8,1] PARAM */);
#line 2292 OMC_FILE
  TRACE_POP
}

/*
equation index: 161
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,9,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,161};
  real_array tmp134;
  real_array tmp135;
  real_array tmp136;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp134, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp135, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp136, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[59] /* radDat.absExtIrrExtSha[1,9,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp134, tmp135, tmp136, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 8, 0);
#line 2317 OMC_FILE
  TRACE_POP
}

/*
equation index: 162
type: SIMPLE_ASSIGN
$outputAlias_y[1,9,1] = radDat.absExtIrrExtSha[1,9,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[19] /* $outputAlias_y[1,9,1] PARAM */) = (data->simulationInfo->realParameter[59] /* radDat.absExtIrrExtSha[1,9,1] PARAM */);
#line 2333 OMC_FILE
  TRACE_POP
}

/*
equation index: 163
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,9,1] = radDat.absExtIrrExtSha[1,9,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,163};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[8] /* $outputAlias_recordTest[1,9,1] PARAM */) = (data->simulationInfo->realParameter[59] /* radDat.absExtIrrExtSha[1,9,1] PARAM */);
#line 2349 OMC_FILE
  TRACE_POP
}

/*
equation index: 164
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,10,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
  real_array tmp137;
  real_array tmp138;
  real_array tmp139;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp137, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp138, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp139, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[60] /* radDat.absExtIrrExtSha[1,10,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp137, tmp138, tmp139, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 9, 0);
#line 2374 OMC_FILE
  TRACE_POP
}

/*
equation index: 165
type: SIMPLE_ASSIGN
$outputAlias_y[1,10,1] = radDat.absExtIrrExtSha[1,10,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[20] /* $outputAlias_y[1,10,1] PARAM */) = (data->simulationInfo->realParameter[60] /* radDat.absExtIrrExtSha[1,10,1] PARAM */);
#line 2390 OMC_FILE
  TRACE_POP
}

/*
equation index: 166
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,10,1] = radDat.absExtIrrExtSha[1,10,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[9] /* $outputAlias_recordTest[1,10,1] PARAM */) = (data->simulationInfo->realParameter[60] /* radDat.absExtIrrExtSha[1,10,1] PARAM */);
#line 2406 OMC_FILE
  TRACE_POP
}

/*
equation index: 167
type: SIMPLE_ASSIGN
radDat.absExtIrrExtSha[1,11,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationExteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
  real_array tmp140;
  real_array tmp141;
  real_array tmp142;
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp140, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp141, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp142, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 52 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[61] /* radDat.absExtIrrExtSha[1,11,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, tmp140, tmp141, tmp142, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 10, 0);
#line 2431 OMC_FILE
  TRACE_POP
}

/*
equation index: 168
type: SIMPLE_ASSIGN
$outputAlias_y[1,11,1] = radDat.absExtIrrExtSha[1,11,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
#line 22 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[21] /* $outputAlias_y[1,11,1] PARAM */) = (data->simulationInfo->realParameter[61] /* radDat.absExtIrrExtSha[1,11,1] PARAM */);
#line 2447 OMC_FILE
  TRACE_POP
}

/*
equation index: 169
type: SIMPLE_ASSIGN
$outputAlias_recordTest[1,11,1] = radDat.absExtIrrExtSha[1,11,1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
#line 6 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples/DataTest.mo"
  (data->simulationInfo->realParameter[10] /* $outputAlias_recordTest[1,11,1] PARAM */) = (data->simulationInfo->realParameter[61] /* radDat.absExtIrrExtSha[1,11,1] PARAM */);
#line 2463 OMC_FILE
  TRACE_POP
}

/*
equation index: 170
type: SIMPLE_ASSIGN
radDat.devAbsIntIrrIntSha[1] = Buildings.HeatTransfer.Windows.Functions.devAbsInteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
  real_array tmp143;
  real_array tmp144;
#line 121 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp143, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 121 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp144, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 121 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[98] /* radDat.devAbsIntIrrIntSha[1] PARAM */) = real_get(omc_Buildings_HeatTransfer_Windows_Functions_devAbsInteriorIrradiationInteriorShading(threadData, tmp143, tmp144, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0);
#line 2485 OMC_FILE
  TRACE_POP
}

/*
equation index: 171
type: SIMPLE_ASSIGN
radDat.winTraRefIntIrrIntSha[3,1] = Buildings.HeatTransfer.Windows.Functions.winTRInteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,171};
  real_array tmp145;
  real_array tmp146;
#line 113 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp145, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 113 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp146, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 113 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[216] /* radDat.winTraRefIntIrrIntSha[3,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationInteriorShading(threadData, tmp145, tmp146, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 2, 0);
#line 2507 OMC_FILE
  TRACE_POP
}

/*
equation index: 172
type: SIMPLE_ASSIGN
radDat.winTraRefIntIrrIntSha[2,1] = Buildings.HeatTransfer.Windows.Functions.winTRInteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
  real_array tmp147;
  real_array tmp148;
#line 113 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp147, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 113 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp148, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 113 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[215] /* radDat.winTraRefIntIrrIntSha[2,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationInteriorShading(threadData, tmp147, tmp148, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 1, 0);
#line 2529 OMC_FILE
  TRACE_POP
}

/*
equation index: 173
type: SIMPLE_ASSIGN
radDat.winTraRefIntIrrIntSha[1,1] = Buildings.HeatTransfer.Windows.Functions.winTRInteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_173(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,173};
  real_array tmp149;
  real_array tmp150;
#line 113 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp149, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 113 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp150, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 113 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[214] /* radDat.winTraRefIntIrrIntSha[1,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationInteriorShading(threadData, tmp149, tmp150, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0);
#line 2551 OMC_FILE
  TRACE_POP
}

/*
equation index: 174
type: SIMPLE_ASSIGN
radDat.absIntIrrNoSha[1,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsInteriorIrradiationNoShading(radDat.traRef, 1, 1, 11)[1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,174};
  real_array tmp151;
#line 37 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp151, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 37 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[86] /* radDat.absIntIrrNoSha[1,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationNoShading(threadData, tmp151, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0);
#line 2570 OMC_FILE
  TRACE_POP
}

/*
equation index: 175
type: SIMPLE_ASSIGN
radDat.absIntIrrIntSha[1,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsInteriorIrradiationInteriorShading(radDat.absIntIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_175(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,175};
  real_array tmp152;
  real_array tmp153;
  real_array tmp154;
#line 104 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp152, ((modelica_real*)&((&data->simulationInfo->realParameter[86] /* radDat.absIntIrrNoSha[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)])), 2, (_index_t)1, (_index_t)1);
#line 104 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp153, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 104 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp154, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 104 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[85] /* radDat.absIntIrrIntSha[1,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationInteriorShading(threadData, tmp152, tmp153, tmp154, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0);
#line 2595 OMC_FILE
  TRACE_POP
}

/*
equation index: 176
type: SIMPLE_ASSIGN
radDat.absIntIrrExtSha[1,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsInteriorIrradiationExteriorShading(radDat.absIntIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_176(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,176};
  real_array tmp155;
  real_array tmp156;
  real_array tmp157;
#line 95 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp155, ((modelica_real*)&((&data->simulationInfo->realParameter[86] /* radDat.absIntIrrNoSha[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)])), 2, (_index_t)1, (_index_t)1);
#line 95 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp156, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 95 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp157, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 95 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[84] /* radDat.absIntIrrExtSha[1,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationExteriorShading(threadData, tmp155, tmp156, tmp157, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0);
#line 2620 OMC_FILE
  TRACE_POP
}

/*
equation index: 177
type: SIMPLE_ASSIGN
radDat.winTraRefIntIrrExtSha[3,1] = Buildings.HeatTransfer.Windows.Functions.winTRInteriorIrradiationExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_177(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,177};
  real_array tmp158;
  real_array tmp159;
#line 86 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp158, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 86 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp159, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 86 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[213] /* radDat.winTraRefIntIrrExtSha[3,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationExteriorShading(threadData, tmp158, tmp159, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 2, 0);
#line 2642 OMC_FILE
  TRACE_POP
}

/*
equation index: 178
type: SIMPLE_ASSIGN
radDat.winTraRefIntIrrExtSha[2,1] = Buildings.HeatTransfer.Windows.Functions.winTRInteriorIrradiationExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_178(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,178};
  real_array tmp160;
  real_array tmp161;
#line 86 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp160, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 86 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp161, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 86 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[212] /* radDat.winTraRefIntIrrExtSha[2,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationExteriorShading(threadData, tmp160, tmp161, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 1, 0);
#line 2664 OMC_FILE
  TRACE_POP
}

/*
equation index: 179
type: SIMPLE_ASSIGN
radDat.winTraRefIntIrrExtSha[1,1] = Buildings.HeatTransfer.Windows.Functions.winTRInteriorIrradiationExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_179(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,179};
  real_array tmp162;
  real_array tmp163;
#line 86 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp162, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 86 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp163, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 86 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[211] /* radDat.winTraRefIntIrrExtSha[1,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationExteriorShading(threadData, tmp162, tmp163, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0);
#line 2686 OMC_FILE
  TRACE_POP
}

/*
equation index: 180
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[11,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_180(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,180};
  real_array tmp164;
  real_array tmp165;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp164, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp165, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[97] /* radDat.devAbsExtIrrIntShaDev[11,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp164, tmp165, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 10, 0);
#line 2708 OMC_FILE
  TRACE_POP
}

/*
equation index: 181
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[10,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,181};
  real_array tmp166;
  real_array tmp167;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp166, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp167, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[96] /* radDat.devAbsExtIrrIntShaDev[10,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp166, tmp167, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 9, 0);
#line 2730 OMC_FILE
  TRACE_POP
}

/*
equation index: 182
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[9,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_182(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,182};
  real_array tmp168;
  real_array tmp169;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp168, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp169, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[95] /* radDat.devAbsExtIrrIntShaDev[9,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp168, tmp169, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 8, 0);
#line 2752 OMC_FILE
  TRACE_POP
}

/*
equation index: 183
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[8,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,183};
  real_array tmp170;
  real_array tmp171;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp170, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp171, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[94] /* radDat.devAbsExtIrrIntShaDev[8,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp170, tmp171, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 7, 0);
#line 2774 OMC_FILE
  TRACE_POP
}

/*
equation index: 184
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[7,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
  real_array tmp172;
  real_array tmp173;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp172, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp173, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[93] /* radDat.devAbsExtIrrIntShaDev[7,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp172, tmp173, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 6, 0);
#line 2796 OMC_FILE
  TRACE_POP
}

/*
equation index: 185
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[6,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,185};
  real_array tmp174;
  real_array tmp175;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp174, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp175, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[92] /* radDat.devAbsExtIrrIntShaDev[6,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp174, tmp175, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 5, 0);
#line 2818 OMC_FILE
  TRACE_POP
}

/*
equation index: 186
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[5,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,186};
  real_array tmp176;
  real_array tmp177;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp176, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp177, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[91] /* radDat.devAbsExtIrrIntShaDev[5,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp176, tmp177, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 4, 0);
#line 2840 OMC_FILE
  TRACE_POP
}

/*
equation index: 187
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[4,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,187};
  real_array tmp178;
  real_array tmp179;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp178, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp179, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[90] /* radDat.devAbsExtIrrIntShaDev[4,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp178, tmp179, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 3, 0);
#line 2862 OMC_FILE
  TRACE_POP
}

/*
equation index: 188
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[3,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,188};
  real_array tmp180;
  real_array tmp181;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp180, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp181, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[89] /* radDat.devAbsExtIrrIntShaDev[3,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp180, tmp181, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 2, 0);
#line 2884 OMC_FILE
  TRACE_POP
}

/*
equation index: 189
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[2,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,189};
  real_array tmp182;
  real_array tmp183;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp182, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp183, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[88] /* radDat.devAbsExtIrrIntShaDev[2,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp182, tmp183, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 1, 0);
#line 2906 OMC_FILE
  TRACE_POP
}

/*
equation index: 190
type: SIMPLE_ASSIGN
radDat.devAbsExtIrrIntShaDev[1,1] = Buildings.HeatTransfer.Windows.Functions.devAbsExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,190};
  real_array tmp184;
  real_array tmp185;
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp184, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp185, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 78 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[87] /* radDat.devAbsExtIrrIntShaDev[1,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, tmp184, tmp185, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0);
#line 2928 OMC_FILE
  TRACE_POP
}

/*
equation index: 191
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,11,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_191(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,191};
  real_array tmp186;
  real_array tmp187;
  real_array tmp188;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp186, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp187, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp188, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[72] /* radDat.absExtIrrIntSha[1,11,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp186, tmp187, tmp188, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 10, 0);
#line 2953 OMC_FILE
  TRACE_POP
}

/*
equation index: 192
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,10,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
  real_array tmp189;
  real_array tmp190;
  real_array tmp191;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp189, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp190, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp191, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[71] /* radDat.absExtIrrIntSha[1,10,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp189, tmp190, tmp191, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 9, 0);
#line 2978 OMC_FILE
  TRACE_POP
}

/*
equation index: 193
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,9,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,193};
  real_array tmp192;
  real_array tmp193;
  real_array tmp194;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp192, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp193, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp194, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[70] /* radDat.absExtIrrIntSha[1,9,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp192, tmp193, tmp194, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 8, 0);
#line 3003 OMC_FILE
  TRACE_POP
}

/*
equation index: 194
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,8,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,194};
  real_array tmp195;
  real_array tmp196;
  real_array tmp197;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp195, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp196, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp197, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[69] /* radDat.absExtIrrIntSha[1,8,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp195, tmp196, tmp197, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 7, 0);
#line 3028 OMC_FILE
  TRACE_POP
}

/*
equation index: 195
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,7,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_195(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,195};
  real_array tmp198;
  real_array tmp199;
  real_array tmp200;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp198, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp199, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp200, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[68] /* radDat.absExtIrrIntSha[1,7,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp198, tmp199, tmp200, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 6, 0);
#line 3053 OMC_FILE
  TRACE_POP
}

/*
equation index: 196
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,6,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,196};
  real_array tmp201;
  real_array tmp202;
  real_array tmp203;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp201, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp202, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp203, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[67] /* radDat.absExtIrrIntSha[1,6,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp201, tmp202, tmp203, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 5, 0);
#line 3078 OMC_FILE
  TRACE_POP
}

/*
equation index: 197
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,5,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,197};
  real_array tmp204;
  real_array tmp205;
  real_array tmp206;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp204, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp205, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp206, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[66] /* radDat.absExtIrrIntSha[1,5,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp204, tmp205, tmp206, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 4, 0);
#line 3103 OMC_FILE
  TRACE_POP
}

/*
equation index: 198
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,4,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
  real_array tmp207;
  real_array tmp208;
  real_array tmp209;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp207, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp208, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp209, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[65] /* radDat.absExtIrrIntSha[1,4,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp207, tmp208, tmp209, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 3, 0);
#line 3128 OMC_FILE
  TRACE_POP
}

/*
equation index: 199
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,3,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_199(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,199};
  real_array tmp210;
  real_array tmp211;
  real_array tmp212;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp210, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp211, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp212, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[64] /* radDat.absExtIrrIntSha[1,3,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp210, tmp211, tmp212, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 2, 0);
#line 3153 OMC_FILE
  TRACE_POP
}

/*
equation index: 200
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,2,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
  real_array tmp213;
  real_array tmp214;
  real_array tmp215;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp213, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp214, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp215, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[63] /* radDat.absExtIrrIntSha[1,2,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp213, tmp214, tmp215, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 1, 0);
#line 3178 OMC_FILE
  TRACE_POP
}

/*
equation index: 201
type: SIMPLE_ASSIGN
radDat.absExtIrrIntSha[1,1,1] = Buildings.HeatTransfer.Windows.Functions.glassAbsExteriorIrradiationInteriorShading(radDat.absExtIrrNoSha, radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,201};
  real_array tmp216;
  real_array tmp217;
  real_array tmp218;
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp216, ((modelica_real*)&((&data->simulationInfo->realParameter[73] /* radDat.absExtIrrNoSha[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 3, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp217, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp218, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 69 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[62] /* radDat.absExtIrrIntSha[1,1,1] PARAM */) = real_get_3D(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, tmp216, tmp217, tmp218, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0, 0);
#line 3203 OMC_FILE
  TRACE_POP
}

/*
equation index: 202
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[11,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
  real_array tmp219;
  real_array tmp220;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp219, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp220, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[210] /* radDat.winTraExtIrrIntSha[11,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp219, tmp220, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 10, 0);
#line 3225 OMC_FILE
  TRACE_POP
}

/*
equation index: 203
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[10,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,203};
  real_array tmp221;
  real_array tmp222;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp221, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp222, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[209] /* radDat.winTraExtIrrIntSha[10,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp221, tmp222, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 9, 0);
#line 3247 OMC_FILE
  TRACE_POP
}

/*
equation index: 204
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[9,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
  real_array tmp223;
  real_array tmp224;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp223, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp224, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[208] /* radDat.winTraExtIrrIntSha[9,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp223, tmp224, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 8, 0);
#line 3269 OMC_FILE
  TRACE_POP
}

/*
equation index: 205
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[8,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
  real_array tmp225;
  real_array tmp226;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp225, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp226, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[207] /* radDat.winTraExtIrrIntSha[8,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp225, tmp226, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 7, 0);
#line 3291 OMC_FILE
  TRACE_POP
}

/*
equation index: 206
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[7,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
  real_array tmp227;
  real_array tmp228;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp227, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp228, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[206] /* radDat.winTraExtIrrIntSha[7,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp227, tmp228, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 6, 0);
#line 3313 OMC_FILE
  TRACE_POP
}

/*
equation index: 207
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[6,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  real_array tmp229;
  real_array tmp230;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp229, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp230, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[205] /* radDat.winTraExtIrrIntSha[6,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp229, tmp230, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 5, 0);
#line 3335 OMC_FILE
  TRACE_POP
}

/*
equation index: 208
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[5,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
  real_array tmp231;
  real_array tmp232;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp231, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp232, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[204] /* radDat.winTraExtIrrIntSha[5,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp231, tmp232, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 4, 0);
#line 3357 OMC_FILE
  TRACE_POP
}

/*
equation index: 209
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[4,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  real_array tmp233;
  real_array tmp234;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp233, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp234, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[203] /* radDat.winTraExtIrrIntSha[4,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp233, tmp234, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 3, 0);
#line 3379 OMC_FILE
  TRACE_POP
}

/*
equation index: 210
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[3,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
  real_array tmp235;
  real_array tmp236;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp235, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp236, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[202] /* radDat.winTraExtIrrIntSha[3,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp235, tmp236, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 2, 0);
#line 3401 OMC_FILE
  TRACE_POP
}

/*
equation index: 211
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[2,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
  real_array tmp237;
  real_array tmp238;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp237, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp238, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[201] /* radDat.winTraExtIrrIntSha[2,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp237, tmp238, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 1, 0);
#line 3423 OMC_FILE
  TRACE_POP
}

/*
equation index: 212
type: SIMPLE_ASSIGN
radDat.winTraExtIrrIntSha[1,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiationInteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
  real_array tmp239;
  real_array tmp240;
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp239, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp240, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 61 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[200] /* radDat.winTraExtIrrIntSha[1,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, tmp239, tmp240, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0);
#line 3445 OMC_FILE
  TRACE_POP
}

/*
equation index: 213
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[11,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[11, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  real_array tmp241;
  real_array tmp242;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp241, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp242, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[199] /* radDat.winTraExtIrrExtSha[11,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp241, tmp242, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 10, 0);
#line 3467 OMC_FILE
  TRACE_POP
}

/*
equation index: 214
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[10,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[10, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  real_array tmp243;
  real_array tmp244;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp243, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp244, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[198] /* radDat.winTraExtIrrExtSha[10,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp243, tmp244, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 9, 0);
#line 3489 OMC_FILE
  TRACE_POP
}

/*
equation index: 215
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[9,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[9, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
  real_array tmp245;
  real_array tmp246;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp245, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp246, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[197] /* radDat.winTraExtIrrExtSha[9,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp245, tmp246, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 8, 0);
#line 3511 OMC_FILE
  TRACE_POP
}

/*
equation index: 216
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[8,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[8, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  real_array tmp247;
  real_array tmp248;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp247, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp248, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[196] /* radDat.winTraExtIrrExtSha[8,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp247, tmp248, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 7, 0);
#line 3533 OMC_FILE
  TRACE_POP
}

/*
equation index: 217
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[7,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[7, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
  real_array tmp249;
  real_array tmp250;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp249, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp250, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[195] /* radDat.winTraExtIrrExtSha[7,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp249, tmp250, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 6, 0);
#line 3555 OMC_FILE
  TRACE_POP
}

/*
equation index: 218
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[6,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[6, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
  real_array tmp251;
  real_array tmp252;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp251, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp252, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[194] /* radDat.winTraExtIrrExtSha[6,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp251, tmp252, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 5, 0);
#line 3577 OMC_FILE
  TRACE_POP
}

/*
equation index: 219
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[5,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[5, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
  real_array tmp253;
  real_array tmp254;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp253, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp254, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[193] /* radDat.winTraExtIrrExtSha[5,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp253, tmp254, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 4, 0);
#line 3599 OMC_FILE
  TRACE_POP
}

/*
equation index: 220
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[4,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[4, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  real_array tmp255;
  real_array tmp256;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp255, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp256, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[192] /* radDat.winTraExtIrrExtSha[4,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp255, tmp256, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 3, 0);
#line 3621 OMC_FILE
  TRACE_POP
}

/*
equation index: 221
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[3,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[3, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  real_array tmp257;
  real_array tmp258;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp257, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp258, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[191] /* radDat.winTraExtIrrExtSha[3,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp257, tmp258, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 2, 0);
#line 3643 OMC_FILE
  TRACE_POP
}

/*
equation index: 222
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[2,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[2, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  real_array tmp259;
  real_array tmp260;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp259, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp260, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[190] /* radDat.winTraExtIrrExtSha[2,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp259, tmp260, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 1, 0);
#line 3665 OMC_FILE
  TRACE_POP
}

/*
equation index: 223
type: SIMPLE_ASSIGN
radDat.winTraExtIrrExtSha[1,1] = Buildings.HeatTransfer.Windows.Functions.winTExteriorIrradiatrionExteriorShading(radDat.traRef, radDat.traRefShaDev, 1, 1, 11)[1, 1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,223};
  real_array tmp261;
  real_array tmp262;
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp261, ((modelica_real*)&((&data->simulationInfo->realParameter[152] /* radDat.traRef[1,1,1,1,1] PARAM */)[((((((modelica_integer) 1) - 1) * 1 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)) * 11 + (((modelica_integer) 1)-1)) * 1 + (((modelica_integer) 1)-1)])), 5, (_index_t)3, (_index_t)1, (_index_t)1, (_index_t)11, (_index_t)1);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  real_array_create(&tmp262, ((modelica_real*)&((&data->simulationInfo->realParameter[185] /* radDat.traRefShaDev[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 2 + (((modelica_integer) 1)-1)])), 2, (_index_t)2, (_index_t)2);
#line 44 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationData.mo"
  (data->simulationInfo->realParameter[189] /* radDat.winTraExtIrrExtSha[1,1] PARAM */) = real_get_2D(omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, tmp261, tmp262, ((modelica_integer) 1), ((modelica_integer) 1), ((modelica_integer) 11)), 0, 0);
#line 3687 OMC_FILE
  TRACE_POP
}

/*
equation index: 242
type: ALGORITHM

  assert(radDat.NSta >= 1, "Variable violating min constraint: 1 <= radDat.NSta, has value: " + String(radDat.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  modelica_boolean tmp263;
  static const MMC_DEFSTRINGLIT(tmp264,64,"Variable violating min constraint: 1 <= radDat.NSta, has value: ");
  modelica_string tmp265;
  modelica_metatype tmpMeta266;
  static int tmp267 = 0;
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp267)
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp263 = GreaterEq((data->simulationInfo->integerParameter[3] /* radDat.NSta PARAM */),((modelica_integer) 1));
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp263)
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp265 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[3] /* radDat.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta266 = stringAppend(MMC_REFSTRINGLIT(tmp264),tmp265);
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(radDat.NSta >= 1)";
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta266));
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta266));
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp267 = 1;
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 10 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 3747 OMC_FILE
  TRACE_POP
}

/*
equation index: 243
type: ALGORITHM

  assert(radDat.N >= 1, "Variable violating min constraint: 1 <= radDat.N, has value: " + String(radDat.N, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  modelica_boolean tmp268;
  static const MMC_DEFSTRINGLIT(tmp269,61,"Variable violating min constraint: 1 <= radDat.N, has value: ");
  modelica_string tmp270;
  modelica_metatype tmpMeta271;
  static int tmp272 = 0;
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp272)
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp268 = GreaterEq((data->simulationInfo->integerParameter[1] /* radDat.N PARAM */),((modelica_integer) 1));
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp268)
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp270 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[1] /* radDat.N PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta271 = stringAppend(MMC_REFSTRINGLIT(tmp269),tmp270);
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(radDat.N >= 1)";
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta271));
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta271));
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp272 = 1;
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 7 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 3807 OMC_FILE
  TRACE_POP
}

/*
equation index: 244
type: ALGORITHM

  assert(glaSys.gas[1].MM >= 0.0, "Variable violating min constraint: 0.0 <= glaSys.gas[1].MM, has value: " + String(glaSys.gas[1].MM, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  modelica_boolean tmp273;
  static const MMC_DEFSTRINGLIT(tmp274,71,"Variable violating min constraint: 0.0 <= glaSys.gas[1].MM, has value: ");
  modelica_string tmp275;
  modelica_metatype tmpMeta276;
  static int tmp277 = 0;
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp277)
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp273 = GreaterEq((data->simulationInfo->realParameter[26] /* glaSys.gas[1].MM PARAM */),0.0);
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp273)
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp275 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[26] /* glaSys.gas[1].MM PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta276 = stringAppend(MMC_REFSTRINGLIT(tmp274),tmp275);
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(glaSys.gas[1].MM >= 0.0)";
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta276));
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta276));
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp277 = 1;
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 21 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 3867 OMC_FILE
  TRACE_POP
}

/*
equation index: 245
type: ALGORITHM

  assert(glaSys.gas[1].a_mu >= 0.0, "Variable violating min constraint: 0.0 <= glaSys.gas[1].a_mu, has value: " + String(glaSys.gas[1].a_mu, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  modelica_boolean tmp278;
  static const MMC_DEFSTRINGLIT(tmp279,73,"Variable violating min constraint: 0.0 <= glaSys.gas[1].a_mu, has value: ");
  modelica_string tmp280;
  modelica_metatype tmpMeta281;
  static int tmp282 = 0;
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp282)
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp278 = GreaterEq((data->simulationInfo->realParameter[30] /* glaSys.gas[1].a_mu PARAM */),0.0);
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp278)
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp280 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[30] /* glaSys.gas[1].a_mu PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta281 = stringAppend(MMC_REFSTRINGLIT(tmp279),tmp280);
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(glaSys.gas[1].a_mu >= 0.0)";
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta281));
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta281));
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp282 = 1;
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 12 "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 3927 OMC_FILE
  TRACE_POP
}
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_45(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_46(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_47(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_48(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_49(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_50(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_51(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_52(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_53(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_54(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_55(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_56(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_57(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_58(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_59(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_60(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_61(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_62(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_63(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_64(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_65(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_66(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_67(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_68(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_69(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_70(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_71(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_72(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_73(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_74(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_75(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_76(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_77(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_78(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_79(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_80(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_81(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_82(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_83(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_84(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_85(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_86(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_87(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_88(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_89(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_90(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_91(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_92(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_93(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_94(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_95(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_96(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_97(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_98(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_99(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_100(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_101(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_102(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_103(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_104(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_105(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_106(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_107(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_108(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_109(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_110(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_111(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_112(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_113(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_114(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_115(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_116(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_117(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_118(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_119(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_120(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_121(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_122(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_123(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_124(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_125(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_126(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_127(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_128(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_129(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_130(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_131(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_132(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_133(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_134(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_135(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_136(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_137(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_138(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_139(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_140(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_141(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_142(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_143(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_144(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_145(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_146(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_147(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_148(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_149(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_150(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_151(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_152(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_153(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_154(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_155(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_156(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_157(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_158(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_159(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_160(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_161(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_162(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_163(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_164(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_165(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_166(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_167(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_168(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_169(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_170(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_171(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_172(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_173(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_174(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_175(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_176(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_177(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_178(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_179(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_180(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_181(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_182(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_183(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_184(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_185(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_186(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_187(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_188(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_189(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_190(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_191(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_192(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_193(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_194(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_195(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_196(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_197(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_198(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_199(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_200(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_201(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_202(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_203(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_204(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_205(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_206(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_207(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_208(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_209(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_210(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_211(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_212(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_213(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_214(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_215(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_216(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_217(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_218(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_219(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_220(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_221(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_222(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_223(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_242(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_243(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_244(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_245(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->integerParameter[0] /* radDat.HEM PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[1] /* radDat.N PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[1].time_unvarying = 1;
  (data->simulationInfo->integerParameter[2] /* radDat.NDIR PARAM */) = ((modelica_integer) 10);
  data->modelData->integerParameterData[2].time_unvarying = 1;
  (data->simulationInfo->integerParameter[3] /* radDat.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[3].time_unvarying = 1;
  (data->simulationInfo->realParameter[135] /* radDat.psi[1] PARAM */) = 0.0;
  data->modelData->realParameterData[135].time_unvarying = 1;
  (data->simulationInfo->realParameter[136] /* radDat.psi[2] PARAM */) = 0.1745329251994329;
  data->modelData->realParameterData[136].time_unvarying = 1;
  (data->simulationInfo->realParameter[137] /* radDat.psi[3] PARAM */) = 0.3490658503988659;
  data->modelData->realParameterData[137].time_unvarying = 1;
  (data->simulationInfo->realParameter[138] /* radDat.psi[4] PARAM */) = 0.5235987755982988;
  data->modelData->realParameterData[138].time_unvarying = 1;
  (data->simulationInfo->realParameter[139] /* radDat.psi[5] PARAM */) = 0.6981317007977318;
  data->modelData->realParameterData[139].time_unvarying = 1;
  (data->simulationInfo->realParameter[140] /* radDat.psi[6] PARAM */) = 0.8726646259971648;
  data->modelData->realParameterData[140].time_unvarying = 1;
  (data->simulationInfo->realParameter[141] /* radDat.psi[7] PARAM */) = 1.047197551196598;
  data->modelData->realParameterData[141].time_unvarying = 1;
  (data->simulationInfo->realParameter[142] /* radDat.psi[8] PARAM */) = 1.221730476396031;
  data->modelData->realParameterData[142].time_unvarying = 1;
  (data->simulationInfo->realParameter[143] /* radDat.psi[9] PARAM */) = 1.396263401595464;
  data->modelData->realParameterData[143].time_unvarying = 1;
  (data->simulationInfo->realParameter[144] /* radDat.psi[10] PARAM */) = 1.570796326794897;
  data->modelData->realParameterData[144].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[0] /* glaSys.haveControllableWindow PARAM */) = 0;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[1] /* glaSys.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[1].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[2] /* glaSys.haveInteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[2].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[3] /* glaSys.haveShade PARAM */) = 0;
  data->modelData->booleanParameterData[3].time_unvarying = 1;
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

