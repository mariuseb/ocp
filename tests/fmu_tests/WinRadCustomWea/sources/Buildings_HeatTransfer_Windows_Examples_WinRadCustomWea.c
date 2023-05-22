#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustomWea/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea.c"
#endif
/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  (data->localData[0]->realVars[36] /* uSha variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[37] /* uSta variable */) = data->simulationInfo->inputVars[1];
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[36].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[37].attribute.start;
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[36].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[37].attribute.start = data->simulationInfo->inputVars[1];
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[36].info.name;
  names[1] = (char *) data->modelData->realVarsData[37].info.name;
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[32] /* QAbsExtSha_flow variable */);
  data->simulationInfo->outputVars[1] = (data->localData[0]->realVars[33] /* QAbsGlaSha_flow variable */);
  data->simulationInfo->outputVars[2] = (data->localData[0]->realVars[34] /* QAbsGlaUns_flow variable */);
  data->simulationInfo->outputVars[3] = (data->localData[0]->realVars[35] /* QAbsIntSha_flow variable */);
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 230
type: SIMPLE_ASSIGN
weaBus.cloTim = time
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
#line 9 "/home/marius/modelica-buildings/Buildings/Utilities/Time/ModelTime.mo"
  (data->localData[0]->realVars[47] /* weaBus.cloTim variable */) = data->localData[0]->timeValue;
#line 131 OMC_FILE
  TRACE_POP
}
/*
equation index: 231
type: SIMPLE_ASSIGN
$whenCondition2 = weaDat.conTim.canRepeatWeatherFile and weaBus.cloTim > pre(weaDat.conTim.tNext)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  modelica_boolean tmp0;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[47] /* weaBus.cloTim variable */), (data->simulationInfo->realVarsPre[139] /* weaDat.conTim.tNext DISCRETE */), 0, Greater, GreaterZC);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) && tmp0);
#line 148 OMC_FILE
  TRACE_POP
}
/*
equation index: 232
type: SIMPLE_ASSIGN
$cse4 = cos((weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  (data->localData[0]->realVars[13] /* $cse4 variable */) = cos((DIVISION_SIM((data->localData[0]->realVars[47] /* weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848));
  TRACE_POP
}
/*
equation index: 233
type: SIMPLE_ASSIGN
weaBus.solDec = asin((-0.3979486313076103) * $cse4)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  modelica_real tmp1;
  tmp1 = (-0.3979486313076103) * ((data->localData[0]->realVars[13] /* $cse4 variable */));
  if(!(tmp1 >= -1.0 && tmp1 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * $cse4) outside the domain -1.0 <= %g <= 1.0", tmp1);
    }
  }
  (data->localData[0]->realVars[52] /* weaBus.solDec variable */) = asin(tmp1);
  TRACE_POP
}
/*
equation index: 234
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.dec_c = cos(weaBus.solDec)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  (data->localData[0]->realVars[24] /* HDirTil.incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[52] /* weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 235
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.dec_s = sin(weaBus.solDec)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  (data->localData[0]->realVars[25] /* HDirTil.incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[52] /* weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 236
type: SIMPLE_ASSIGN
$cse9 = sin(weaBus.solDec)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
  (data->localData[0]->realVars[16] /* $cse9 variable */) = sin((data->localData[0]->realVars[52] /* weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 237
type: SIMPLE_ASSIGN
$cse6 = cos(weaBus.solDec)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  (data->localData[0]->realVars[14] /* $cse6 variable */) = cos((data->localData[0]->realVars[52] /* weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 238
type: SIMPLE_ASSIGN
HDirTil.incAng.decAng.decAng = weaBus.solDec
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  (data->localData[0]->realVars[23] /* HDirTil.incAng.decAng.decAng variable */) = (data->localData[0]->realVars[52] /* weaBus.solDec variable */);
  TRACE_POP
}
/*
equation index: 239
type: SIMPLE_ASSIGN
weaDat.add30Min.y = 1800.0 + weaBus.cloTim
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */) = 1800.0 + (data->localData[0]->realVars[47] /* weaBus.cloTim variable */);
#line 260 OMC_FILE
  TRACE_POP
}
/*
equation index: 240
type: SIMPLE_ASSIGN
$whenCondition1 = weaDat.conTimMin.canRepeatWeatherFile and weaDat.add30Min.y > pre(weaDat.conTimMin.tNext)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  modelica_boolean tmp2;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  relationhysteresis(data, &tmp2, (data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */), (data->simulationInfo->realVarsPre[140] /* weaDat.conTimMin.tNext DISCRETE */), 1, Greater, GreaterZC);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) && tmp2);
#line 277 OMC_FILE
  TRACE_POP
}
/*
equation index: 241
type: WHEN

when {$whenCondition1} then
  weaDat.conTimMin.tNext = if weaDat.conTimMin.canRepeatWeatherFile then weaDat.conTimMin.lenWea * (1.0 + (*Real*)(integer(weaDat.add30Min.y / weaDat.conTimMin.lenWea))) else time;
end when;
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  if(((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    (data->localData[0]->realVars[140] /* weaDat.conTimMin.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[96] /* weaDat.conTimMin.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */),(data->simulationInfo->realParameter[96] /* weaDat.conTimMin.lenWea PARAM */),"weaDat.conTimMin.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 296 OMC_FILE
  }
  TRACE_POP
}
/*
equation index: 242
type: SIMPLE_ASSIGN
weaDat.conTimMin.calTim = if weaDat.conTimMin.canRepeatWeatherFile then weaDat.add30Min.y - weaDat.conTimMin.tNext + weaDat.conTimMin.lenWea else weaDat.add30Min.y
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
#line 38 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[64] /* weaDat.conTimMin.calTim variable */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */)?(data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */) - (data->localData[0]->realVars[140] /* weaDat.conTimMin.tNext DISCRETE */) + (data->simulationInfo->realParameter[96] /* weaDat.conTimMin.lenWea PARAM */):(data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */));
#line 311 OMC_FILE
  TRACE_POP
}
/*
equation index: 243
type: SIMPLE_ASSIGN
weaDat.datRea30Min.y[1] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea30Min.tableID, 1, weaDat.conTimMin.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  (data->localData[0]->realVars[92] /* weaDat.datRea30Min.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 1), (data->localData[0]->realVars[64] /* weaDat.conTimMin.calTim variable */));
  TRACE_POP
}
/*
equation index: 244
type: SIMPLE_ASSIGN
weaBus.HGloHor = max(0.0, weaDat.datRea30Min.y[1])
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  (data->localData[0]->realVars[40] /* weaBus.HGloHor variable */) = fmax(0.0,(data->localData[0]->realVars[92] /* weaDat.datRea30Min.y[1] variable */));
  TRACE_POP
}
/*
equation index: 245
type: SIMPLE_ASSIGN
HDifTilIso.add.u2 = 0.1000000000000004 * weaBus.HGloHor
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
#line 29 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffuseIsotropic.mo"
  (data->localData[0]->realVars[20] /* HDifTilIso.add.u2 variable */) = (0.1000000000000004) * ((data->localData[0]->realVars[40] /* weaBus.HGloHor variable */));
#line 349 OMC_FILE
  TRACE_POP
}
/*
equation index: 246
type: SIMPLE_ASSIGN
weaDat.datRea30Min.y[2] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea30Min.tableID, 2, weaDat.conTimMin.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  (data->localData[0]->realVars[93] /* weaDat.datRea30Min.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 2), (data->localData[0]->realVars[64] /* weaDat.conTimMin.calTim variable */));
  TRACE_POP
}
/*
equation index: 247
type: SIMPLE_ASSIGN
weaBus.HDirNor = max(0.0, weaDat.datRea30Min.y[2])
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  (data->localData[0]->realVars[39] /* weaBus.HDirNor variable */) = fmax(0.0,(data->localData[0]->realVars[93] /* weaDat.datRea30Min.y[2] variable */));
  TRACE_POP
}
/*
equation index: 248
type: SIMPLE_ASSIGN
weaDat.datRea30Min.y[3] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea30Min.tableID, 3, weaDat.conTimMin.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
  (data->localData[0]->realVars[94] /* weaDat.datRea30Min.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 3), (data->localData[0]->realVars[64] /* weaDat.conTimMin.calTim variable */));
  TRACE_POP
}
/*
equation index: 249
type: SIMPLE_ASSIGN
weaBus.HDifHor = max(0.0, weaDat.datRea30Min.y[3])
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
  (data->localData[0]->realVars[38] /* weaBus.HDifHor variable */) = fmax(0.0,(data->localData[0]->realVars[94] /* weaDat.datRea30Min.y[3] variable */));
  TRACE_POP
}
/*
equation index: 250
type: SIMPLE_ASSIGN
HDifTilIso.add.u1 = 0.4999999999999983 * weaBus.HDifHor
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
#line 28 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffuseIsotropic.mo"
  (data->localData[0]->realVars[19] /* HDifTilIso.add.u1 variable */) = (0.4999999999999983) * ((data->localData[0]->realVars[38] /* weaBus.HDifHor variable */));
#line 411 OMC_FILE
  TRACE_POP
}
/*
equation index: 251
type: SIMPLE_ASSIGN
HDifTilIso.H = HDifTilIso.add.u1 + HDifTilIso.add.u2
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[17] /* HDifTilIso.H variable */) = (data->localData[0]->realVars[19] /* HDifTilIso.add.u1 variable */) + (data->localData[0]->realVars[20] /* HDifTilIso.add.u2 variable */);
#line 425 OMC_FILE
  TRACE_POP
}
/*
equation index: 252
type: SIMPLE_ASSIGN
winRad.tra.QTraDifSha_flow[1] = HDifTilIso.H * uSha * winRad.tra.coeTraWinExtIrr[2,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
#line 90 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[133] /* winRad.tra.QTraDifSha_flow[1] variable */) = ((data->localData[0]->realVars[17] /* HDifTilIso.H variable */)) * (((data->localData[0]->realVars[36] /* uSha variable */)) * ((data->simulationInfo->realParameter[959] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */)));
#line 439 OMC_FILE
  TRACE_POP
}
/*
equation index: 253
type: SIMPLE_ASSIGN
winRad.tra.QTraDifUns_flow[1] = HDifTilIso.H * (1.0 - uSha) * winRad.tra.coeTraWinExtIrr[1,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
#line 82 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[134] /* winRad.tra.QTraDifUns_flow[1] variable */) = ((data->localData[0]->realVars[17] /* HDifTilIso.H variable */)) * ((1.0 - (data->localData[0]->realVars[36] /* uSha variable */)) * ((data->simulationInfo->realParameter[946] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */)));
#line 453 OMC_FILE
  TRACE_POP
}
/*
equation index: 254
type: SIMPLE_ASSIGN
winRad.QTraDif_flow = winRad.tra.QTraDifUns_flow[1] + winRad.tra.QTraDifSha_flow[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
#line 97 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[107] /* winRad.QTraDif_flow variable */) = (data->localData[0]->realVars[134] /* winRad.tra.QTraDifUns_flow[1] variable */) + (data->localData[0]->realVars[133] /* winRad.tra.QTraDifSha_flow[1] variable */);
#line 467 OMC_FILE
  TRACE_POP
}
/*
equation index: 255
type: SIMPLE_ASSIGN
HRoo.y = 0.1 * winRad.QTraDif_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[31] /* HRoo.y variable */) = (0.1) * ((data->localData[0]->realVars[107] /* winRad.QTraDif_flow variable */));
#line 481 OMC_FILE
  TRACE_POP
}
/*
equation index: 256
type: SIMPLE_ASSIGN
weaDat.locTim.locTim = weaBus.cloTim + weaDat.locTim.diff
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LocalCivilTime.mo"
  (data->localData[0]->realVars[97] /* weaDat.locTim.locTim variable */) = (data->localData[0]->realVars[47] /* weaBus.cloTim variable */) + (data->simulationInfo->realParameter[108] /* weaDat.locTim.diff PARAM */);
#line 495 OMC_FILE
  TRACE_POP
}
/*
equation index: 257
type: SIMPLE_ASSIGN
weaDat.eqnTim.Bt = 0.01726149809664721 * (-80.0 + 1.157407407407407e-05 * weaBus.cloTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
#line 17 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/EquationOfTime.mo"
  (data->localData[0]->realVars[95] /* weaDat.eqnTim.Bt variable */) = (0.01726149809664721) * (-80.0 + (1.157407407407407e-05) * ((data->localData[0]->realVars[47] /* weaBus.cloTim variable */)));
#line 509 OMC_FILE
  TRACE_POP
}
/*
equation index: 258
type: SIMPLE_ASSIGN
$cse12 = sin(weaDat.eqnTim.Bt)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  (data->localData[0]->realVars[2] /* $cse12 variable */) = sin((data->localData[0]->realVars[95] /* weaDat.eqnTim.Bt variable */));
  TRACE_POP
}
/*
equation index: 259
type: SIMPLE_ASSIGN
$cse11 = cos(weaDat.eqnTim.Bt)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  (data->localData[0]->realVars[1] /* $cse11 variable */) = cos((data->localData[0]->realVars[95] /* weaDat.eqnTim.Bt variable */));
  TRACE_POP
}
/*
equation index: 260
type: SIMPLE_ASSIGN
$cse10 = sin(2.0 * weaDat.eqnTim.Bt)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  (data->localData[0]->realVars[0] /* $cse10 variable */) = sin((2.0) * ((data->localData[0]->realVars[95] /* weaDat.eqnTim.Bt variable */)));
  TRACE_POP
}
/*
equation index: 261
type: SIMPLE_ASSIGN
weaDat.eqnTim.eqnTim = 60.0 * (9.869999999999999 * $cse10 + (-7.53) * $cse11 + (-1.5) * $cse12)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/EquationOfTime.mo"
  (data->localData[0]->realVars[96] /* weaDat.eqnTim.eqnTim variable */) = (60.0) * ((9.869999999999999) * ((data->localData[0]->realVars[0] /* $cse10 variable */)) + (-7.53) * ((data->localData[0]->realVars[1] /* $cse11 variable */)) + (-1.5) * ((data->localData[0]->realVars[2] /* $cse12 variable */)));
#line 559 OMC_FILE
  TRACE_POP
}
/*
equation index: 262
type: SIMPLE_ASSIGN
weaBus.solTim = weaDat.locTim.locTim + weaDat.eqnTim.eqnTim
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,262};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SolarTime.mo"
  (data->localData[0]->realVars[54] /* weaBus.solTim variable */) = (data->localData[0]->realVars[97] /* weaDat.locTim.locTim variable */) + (data->localData[0]->realVars[96] /* weaDat.eqnTim.eqnTim variable */);
#line 573 OMC_FILE
  TRACE_POP
}
/*
equation index: 263
type: SIMPLE_ASSIGN
HDirTil.incAng.solHouAng.solHouAng = 0.2617993877991494 * (-12.0 + 0.0002777777777777778 * weaBus.solTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,263};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/SolarHourAngle.mo"
  (data->localData[0]->realVars[30] /* HDirTil.incAng.solHouAng.solHouAng variable */) = (0.2617993877991494) * (-12.0 + (0.0002777777777777778) * ((data->localData[0]->realVars[54] /* weaBus.solTim variable */)));
#line 587 OMC_FILE
  TRACE_POP
}
/*
equation index: 264
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.sol_c = cos(HDirTil.incAng.solHouAng.solHouAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,264};
  (data->localData[0]->realVars[28] /* HDirTil.incAng.incAng.sol_c variable */) = cos((data->localData[0]->realVars[30] /* HDirTil.incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 265
type: SIMPLE_ASSIGN
HDirTil.inc = acos((-3.491481338843133e-15) * (HDirTil.incAng.incAng.dec_c * HDirTil.incAng.incAng.sol_c * HDirTil.incAng.incAng.lat_c + HDirTil.incAng.incAng.dec_s * HDirTil.incAng.incAng.lat_s) + HDirTil.incAng.incAng.dec_c * HDirTil.incAng.incAng.sol_c * HDirTil.incAng.incAng.lat_s - HDirTil.incAng.incAng.dec_s * HDirTil.incAng.incAng.lat_c)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,265};
  modelica_real tmp3;
  tmp3 = (-3.491481338843133e-15) * ((((data->localData[0]->realVars[24] /* HDirTil.incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[28] /* HDirTil.incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[26] /* HDirTil.incAng.incAng.lat_c variable */)) + ((data->localData[0]->realVars[25] /* HDirTil.incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[27] /* HDirTil.incAng.incAng.lat_s variable */))) + (((data->localData[0]->realVars[24] /* HDirTil.incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[28] /* HDirTil.incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[27] /* HDirTil.incAng.incAng.lat_s variable */)) - (((data->localData[0]->realVars[25] /* HDirTil.incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[26] /* HDirTil.incAng.incAng.lat_c variable */)));
  if(!(tmp3 >= -1.0 && tmp3 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos((-3.491481338843133e-15) * (HDirTil.incAng.incAng.dec_c * HDirTil.incAng.incAng.sol_c * HDirTil.incAng.incAng.lat_c + HDirTil.incAng.incAng.dec_s * HDirTil.incAng.incAng.lat_s) + HDirTil.incAng.incAng.dec_c * HDirTil.incAng.incAng.sol_c * HDirTil.incAng.incAng.lat_s - HDirTil.incAng.incAng.dec_s * HDirTil.incAng.incAng.lat_c) outside the domain -1.0 <= %g <= 1.0", tmp3);
    }
  }
  (data->localData[0]->realVars[22] /* HDirTil.inc variable */) = acos(tmp3);
  TRACE_POP
}
/*
equation index: 266
type: SIMPLE_ASSIGN
winRad.tra.incAng2 = min(HDirTil.inc, 1.570796326794897)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_266(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,266};
  (data->localData[0]->realVars[137] /* winRad.tra.incAng2 variable */) = fmin((data->localData[0]->realVars[22] /* HDirTil.inc variable */),1.570796326794897);
  TRACE_POP
}
/*
equation index: 267
type: SIMPLE_ASSIGN
winRad.tra.x = 2.0 + 5.729577951308232 * abs(winRad.tra.incAng2)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
#line 77 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[138] /* winRad.tra.x variable */) = 2.0 + (5.729577951308232) * (fabs((data->localData[0]->realVars[137] /* winRad.tra.incAng2 variable */)));
#line 651 OMC_FILE
  TRACE_POP
}
/*
equation index: 268
type: SIMPLE_ASSIGN
$cse20 = Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.tra.coeTraWinExtIrr[1,1,1], winRad.tra.coeTraWinExtIrr[1,2,1], winRad.tra.coeTraWinExtIrr[1,3,1], winRad.tra.coeTraWinExtIrr[1,4,1], winRad.tra.coeTraWinExtIrr[1,5,1], winRad.tra.coeTraWinExtIrr[1,6,1], winRad.tra.coeTraWinExtIrr[1,7,1], winRad.tra.coeTraWinExtIrr[1,8,1], winRad.tra.coeTraWinExtIrr[1,9,1], winRad.tra.coeTraWinExtIrr[1,10,1], winRad.tra.coeTraWinExtIrr[1,11,1], winRad.tra.coeTraWinExtIrr[1,12,1], winRad.tra.coeTraWinExtIrr[1,13,1]}, winRad.tra.x)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
  real_array tmp4;
  array_alloc_scalar_real_array(&tmp4, 13, (modelica_real)(data->simulationInfo->realParameter[935] /* winRad.tra.coeTraWinExtIrr[1,1,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[936] /* winRad.tra.coeTraWinExtIrr[1,2,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[937] /* winRad.tra.coeTraWinExtIrr[1,3,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[938] /* winRad.tra.coeTraWinExtIrr[1,4,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[939] /* winRad.tra.coeTraWinExtIrr[1,5,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[940] /* winRad.tra.coeTraWinExtIrr[1,6,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[941] /* winRad.tra.coeTraWinExtIrr[1,7,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[942] /* winRad.tra.coeTraWinExtIrr[1,8,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[943] /* winRad.tra.coeTraWinExtIrr[1,9,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[944] /* winRad.tra.coeTraWinExtIrr[1,10,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[945] /* winRad.tra.coeTraWinExtIrr[1,11,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[946] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[947] /* winRad.tra.coeTraWinExtIrr[1,13,1] PARAM */));
  (data->localData[0]->realVars[11] /* $cse20 variable */) = omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp4, (data->localData[0]->realVars[138] /* winRad.tra.x variable */));
  TRACE_POP
}
/*
equation index: 269
type: SIMPLE_ASSIGN
$cse19 = Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.tra.coeTraWinExtIrr[2,1,1], winRad.tra.coeTraWinExtIrr[2,2,1], winRad.tra.coeTraWinExtIrr[2,3,1], winRad.tra.coeTraWinExtIrr[2,4,1], winRad.tra.coeTraWinExtIrr[2,5,1], winRad.tra.coeTraWinExtIrr[2,6,1], winRad.tra.coeTraWinExtIrr[2,7,1], winRad.tra.coeTraWinExtIrr[2,8,1], winRad.tra.coeTraWinExtIrr[2,9,1], winRad.tra.coeTraWinExtIrr[2,10,1], winRad.tra.coeTraWinExtIrr[2,11,1], winRad.tra.coeTraWinExtIrr[2,12,1], winRad.tra.coeTraWinExtIrr[2,13,1]}, winRad.tra.x)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp5, 13, (modelica_real)(data->simulationInfo->realParameter[948] /* winRad.tra.coeTraWinExtIrr[2,1,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[949] /* winRad.tra.coeTraWinExtIrr[2,2,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[950] /* winRad.tra.coeTraWinExtIrr[2,3,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[951] /* winRad.tra.coeTraWinExtIrr[2,4,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[952] /* winRad.tra.coeTraWinExtIrr[2,5,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[953] /* winRad.tra.coeTraWinExtIrr[2,6,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[954] /* winRad.tra.coeTraWinExtIrr[2,7,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[955] /* winRad.tra.coeTraWinExtIrr[2,8,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[956] /* winRad.tra.coeTraWinExtIrr[2,9,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[957] /* winRad.tra.coeTraWinExtIrr[2,10,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[958] /* winRad.tra.coeTraWinExtIrr[2,11,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[959] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[960] /* winRad.tra.coeTraWinExtIrr[2,13,1] PARAM */));
  (data->localData[0]->realVars[9] /* $cse19 variable */) = omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp5, (data->localData[0]->realVars[138] /* winRad.tra.x variable */));
  TRACE_POP
}
/*
equation index: 270
type: SIMPLE_ASSIGN
$cse18 = cos(HDirTil.inc)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  (data->localData[0]->realVars[8] /* $cse18 variable */) = cos((data->localData[0]->realVars[22] /* HDirTil.inc variable */));
  TRACE_POP
}
/*
equation index: 271
type: SIMPLE_ASSIGN
HDirTil.H = max(0.0, $cse18 * weaBus.HDirNor)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
  (data->localData[0]->realVars[21] /* HDirTil.H variable */) = fmax(0.0,((data->localData[0]->realVars[8] /* $cse18 variable */)) * ((data->localData[0]->realVars[39] /* weaBus.HDirNor variable */)));
  TRACE_POP
}
/*
equation index: 272
type: SIMPLE_ASSIGN
winRad.tra.QTraDirSha_flow[1] = HDirTil.H * uSha * $cse19
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
#line 91 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[135] /* winRad.tra.QTraDirSha_flow[1] variable */) = ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[36] /* uSha variable */)) * ((data->localData[0]->realVars[9] /* $cse19 variable */)));
#line 717 OMC_FILE
  TRACE_POP
}
/*
equation index: 273
type: SIMPLE_ASSIGN
winRad.tra.QTraDirUns_flow[1] = HDirTil.H * (1.0 - uSha) * $cse20
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
#line 83 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[136] /* winRad.tra.QTraDirUns_flow[1] variable */) = ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * ((1.0 - (data->localData[0]->realVars[36] /* uSha variable */)) * ((data->localData[0]->realVars[11] /* $cse20 variable */)));
#line 731 OMC_FILE
  TRACE_POP
}
/*
equation index: 274
type: SIMPLE_ASSIGN
winRad.QTraDir_flow = winRad.tra.QTraDirUns_flow[1] + winRad.tra.QTraDirSha_flow[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
#line 98 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[108] /* winRad.QTraDir_flow variable */) = (data->localData[0]->realVars[136] /* winRad.tra.QTraDirUns_flow[1] variable */) + (data->localData[0]->realVars[135] /* winRad.tra.QTraDirSha_flow[1] variable */);
#line 745 OMC_FILE
  TRACE_POP
}
/*
equation index: 275
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
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
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
  real_array tmp21;
  index_spec_t tmp22;
  real_array tmp23;
  modelica_integer tmp24;
  modelica_integer tmp25;
  modelica_integer tmp26;
  modelica_integer tmp27;
  modelica_integer tmp28;
  modelica_integer tmp29;
  real_array tmp30;
  real_array tmp31;
  modelica_integer tmp32;
  modelica_integer tmp33;
  modelica_integer tmp34;
  modelica_integer tmp35;
  modelica_integer tmp36;
  modelica_integer tmp37;
  real_array tmp38;
  modelica_integer tmp39;
  modelica_integer tmp40;
  modelica_integer tmp41;
  real_array tmp42;
  real_array tmp43;
  index_spec_t tmp44;
  index_spec_t tmp45;
  real_array tmp46;
  real_array tmp47;
  real_array tmp48;
  index_spec_t tmp49;
  index_spec_t tmp50;
  real_array tmp51;
  real_array tmp52;
  real_array tmp53;
  integer_array tmp54;
  modelica_integer tmp55;
  index_spec_t tmp56;
  index_spec_t tmp57;
  real_array tmp58;
  real_array tmp59;
  real_array tmp60;
  integer_array tmp61;
  modelica_integer tmp62;
  index_spec_t tmp63;
  index_spec_t tmp64;
  real_array tmp65;
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
  array_alloc_scalar_real_array(&tmp6, 1, (modelica_real)0.0);
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp7, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp8, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp6, &tmp8, &tmp7);
#line 899 OMC_FILE

#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp9, 1, (modelica_real)0.0);
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp10, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp11, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp9, &tmp11, &tmp10);
#line 909 OMC_FILE

#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp12, 1, (modelica_real)0.0);
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp13, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp14, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp12, &tmp14, &tmp13);
#line 919 OMC_FILE

#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp15, 1, (modelica_real)0.0);
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp16, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp17, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp15, &tmp17, &tmp16);
#line 929 OMC_FILE

#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp24 = ((modelica_integer) 1); tmp25 = 1; tmp26 = ((modelica_integer) 2);
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp25 > 0) && (tmp24 > tmp26)) || ((tmp25 < 0) && (tmp24 < tmp26))))
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer i;
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(i = ((modelica_integer) 1); in_range_integer(i, tmp24, tmp26); i += tmp25)
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp18, 1, (modelica_real)(1.0 - (data->localData[0]->realVars[36] /* uSha variable */)) * (((data->localData[0]->realVars[17] /* HDifTilIso.H variable */)) * ((&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (((modelica_integer) 1)-1)]) + ((data->localData[0]->realVars[31] /* HRoo.y variable */)) * ((&data->simulationInfo->realParameter[203] /* winRad.abs.coeAbsIn[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 2 + (i-1)) * 1 + (((modelica_integer) 1)-1)])));
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      create_index_spec(&tmp19, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) i + ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      real_array_create(&tmp20, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      indexed_assign_real_array(tmp18, &tmp20, &tmp19);
#line 951 OMC_FILE

#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp21, 1, (modelica_real)((data->localData[0]->realVars[36] /* uSha variable */)) * (((data->localData[0]->realVars[17] /* HDifTilIso.H variable */)) * ((&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (((modelica_integer) 1)-1)]) + ((data->localData[0]->realVars[31] /* HRoo.y variable */)) * ((&data->simulationInfo->realParameter[203] /* winRad.abs.coeAbsIn[1,1,1] PARAM */)[((((modelica_integer) 2) - 1) * 2 + (i-1)) * 1 + (((modelica_integer) 1)-1)])));
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      create_index_spec(&tmp22, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) i + ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      real_array_create(&tmp23, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      indexed_assign_real_array(tmp21, &tmp23, &tmp22);
#line 961 OMC_FILE
    }
  }

#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp27 = ((modelica_integer) 1); tmp28 = 1; tmp29 = ((modelica_integer) 1);
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp28 > 0) && (tmp27 > tmp29)) || ((tmp28 < 0) && (tmp27 < tmp29))))
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer iSta;
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp27, tmp29); iSta += tmp28)
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 151 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      (&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] = ((data->localData[0]->realVars[36] /* uSha variable */)) * ((0.3052322754811356) * ((data->localData[0]->realVars[17] /* HDifTilIso.H variable */)) + (0.5282960143941167) * ((data->localData[0]->realVars[31] /* HRoo.y variable */)));
#line 979 OMC_FILE
    }
  }

#line 160 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->localData[0]->realVars[123] /* winRad.abs.incAng2 variable */) = fmin((data->localData[0]->realVars[22] /* HDirTil.inc variable */),1.570796326794897);
#line 985 OMC_FILE

#line 162 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->localData[0]->realVars[124] /* winRad.abs.x variable */) = (5.729577951308232) * (fabs((data->localData[0]->realVars[123] /* winRad.abs.incAng2 variable */))) + 2.0;
#line 989 OMC_FILE

#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp35 = ((modelica_integer) 1); tmp36 = 1; tmp37 = ((modelica_integer) 2);
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp36 > 0) && (tmp35 > tmp37)) || ((tmp36 < 0) && (tmp35 < tmp37))))
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer i;
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(i = ((modelica_integer) 1); in_range_integer(i, tmp35, tmp37); i += tmp36)
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      tmp32 = ((modelica_integer) 1); tmp33 = 1; tmp34 = ((modelica_integer) 1);
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      if(!(((tmp33 > 0) && (tmp32 > tmp34)) || ((tmp33 < 0) && (tmp32 < tmp34))))
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      {
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        modelica_integer iSta;
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp32, tmp34); iSta += tmp33)
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        {
#line 168 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          array_alloc_scalar_real_array(&tmp30, 13, (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 1)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 2)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 3)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 5)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 6)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 7)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 8)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 9)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 10)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 11)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 13)-1)) * 1 + (iSta-1)]);
#line 168 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          (&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 1) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 1) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * ((1.0 - (data->localData[0]->realVars[36] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp30, (data->localData[0]->realVars[124] /* winRad.abs.x variable */))));
#line 1019 OMC_FILE

#line 174 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          array_alloc_scalar_real_array(&tmp31, 13, (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 1)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 2)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 3)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 5)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 6)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 7)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 8)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 9)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 10)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 11)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 13)-1)) * 1 + (iSta-1)]);
#line 174 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          (&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 2) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[36] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp31, (data->localData[0]->realVars[124] /* winRad.abs.x variable */))));
#line 1025 OMC_FILE
        }
      }
    }
  }

#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp39 = ((modelica_integer) 1); tmp40 = 1; tmp41 = ((modelica_integer) 1);
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp40 > 0) && (tmp39 > tmp41)) || ((tmp40 < 0) && (tmp39 < tmp41))))
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer iSta;
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp39, tmp41); iSta += tmp40)
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 184 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp38, 13, (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 2) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 3) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 4) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 5) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 6) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 7) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 8) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 9) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 10) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 11) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 12) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 13) - 1) * 1 + (iSta-1)]);
#line 184 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      (&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[36] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp38, (data->localData[0]->realVars[124] /* winRad.abs.x variable */))));
#line 1047 OMC_FILE
    }
  }

#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp42, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp44, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp42, &tmp44, &tmp43);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp45, 1, (modelica_integer)(1), (int*)0, 'W');
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp46, (modelica_real*)&(data->localData[0]->realVars[109] /* winRad.abs.QAbsExtSha_flow[1] variable */), 1, (_index_t)1);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp43, &tmp46, &tmp45);
#line 1063 OMC_FILE

#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp47, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp49, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp47, &tmp49, &tmp48);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp50, 1, (modelica_integer)(1), (int*)0, 'W');
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp51, (modelica_real*)&(data->localData[0]->realVars[114] /* winRad.abs.QAbsIntSha_flow[1] variable */), 1, (_index_t)1);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp48, &tmp51, &tmp50);
#line 1077 OMC_FILE

#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp52, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_integer_array_from_range(&tmp54, ((modelica_integer) 2), 1, ((modelica_integer) 3));
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp55 = size_of_dimension_base_array(tmp54, 1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp56, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', tmp55, integer_array_make_index_array(tmp54), 'A', (modelica_integer)(1), (int*)0, 'W');
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp52, &tmp56, &tmp53);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp57, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W');
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp58, (modelica_real*)&(data->localData[0]->realVars[112] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */), 2, (_index_t)2, (_index_t)1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp53, &tmp58, &tmp57);
#line 1095 OMC_FILE

#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp59, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_integer_array_from_range(&tmp61, ((modelica_integer) 2), 1, ((modelica_integer) 3));
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp62 = size_of_dimension_base_array(tmp61, 1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp63, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', tmp62, integer_array_make_index_array(tmp61), 'A', (modelica_integer)(1), (int*)0, 'W');
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp59, &tmp63, &tmp60);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp64, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W');
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp65, (modelica_real*)&(data->localData[0]->realVars[110] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */), 2, (_index_t)2, (_index_t)1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp60, &tmp65, &tmp64);
#line 1113 OMC_FILE
  TRACE_POP
}
/*
equation index: 276
type: SIMPLE_ASSIGN
QAbsGlaSha_flow = winRad.abs.QAbsGlaSha_flow[1,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,276};
#line 159 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/WindowRadiation.mo"
  (data->localData[0]->realVars[33] /* QAbsGlaSha_flow variable */) = (data->localData[0]->realVars[110] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */);
#line 1127 OMC_FILE
  TRACE_POP
}
/*
equation index: 277
type: SIMPLE_ASSIGN
QAbsIntSha_flow = winRad.abs.QAbsIntSha_flow[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,277};
#line 163 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/WindowRadiation.mo"
  (data->localData[0]->realVars[35] /* QAbsIntSha_flow variable */) = (data->localData[0]->realVars[114] /* winRad.abs.QAbsIntSha_flow[1] variable */);
#line 1141 OMC_FILE
  TRACE_POP
}
/*
equation index: 278
type: SIMPLE_ASSIGN
QAbsExtSha_flow = winRad.abs.QAbsExtSha_flow[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
#line 150 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/WindowRadiation.mo"
  (data->localData[0]->realVars[32] /* QAbsExtSha_flow variable */) = (data->localData[0]->realVars[109] /* winRad.abs.QAbsExtSha_flow[1] variable */);
#line 1155 OMC_FILE
  TRACE_POP
}
/*
equation index: 279
type: SIMPLE_ASSIGN
QAbsGlaUns_flow = winRad.abs.QAbsGlaUns_flow[1,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,279};
#line 155 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/WindowRadiation.mo"
  (data->localData[0]->realVars[34] /* QAbsGlaUns_flow variable */) = (data->localData[0]->realVars[112] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */);
#line 1169 OMC_FILE
  TRACE_POP
}
/*
equation index: 280
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.sol_s = sin(HDirTil.incAng.solHouAng.solHouAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  (data->localData[0]->realVars[29] /* HDirTil.incAng.incAng.sol_s variable */) = sin((data->localData[0]->realVars[30] /* HDirTil.incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 281
type: SIMPLE_ASSIGN
weaBus.solHouAng = 0.2617993877991494 * (-12.0 + 0.0002777777777777778 * weaBus.solTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/SolarHourAngle.mo"
  (data->localData[0]->realVars[53] /* weaBus.solHouAng variable */) = (0.2617993877991494) * (-12.0 + (0.0002777777777777778) * ((data->localData[0]->realVars[54] /* weaBus.solTim variable */)));
#line 1195 OMC_FILE
  TRACE_POP
}
/*
equation index: 282
type: SIMPLE_ASSIGN
$cse7 = cos(weaBus.solHouAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
  (data->localData[0]->realVars[15] /* $cse7 variable */) = cos((data->localData[0]->realVars[53] /* weaBus.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 283
type: SIMPLE_ASSIGN
weaBus.solZen = acos($cse5 * $cse6 * $cse7 + $cse8 * $cse9)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  modelica_real tmp66;
  tmp66 = (((data->simulationInfo->realParameter[0] /* $cse5 PARAM */)) * ((data->localData[0]->realVars[14] /* $cse6 variable */))) * ((data->localData[0]->realVars[15] /* $cse7 variable */)) + ((data->simulationInfo->realParameter[1] /* $cse8 PARAM */)) * ((data->localData[0]->realVars[16] /* $cse9 variable */));
  if(!(tmp66 >= -1.0 && tmp66 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos($cse5 * $cse6 * $cse7 + $cse8 * $cse9) outside the domain -1.0 <= %g <= 1.0", tmp66);
    }
  }
  (data->localData[0]->realVars[55] /* weaBus.solZen variable */) = acos(tmp66);
  TRACE_POP
}
/*
equation index: 284
type: SIMPLE_ASSIGN
weaBus.solAlt = 1.570796326794897 - weaBus.solZen
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/AltitudeAngle.mo"
  (data->localData[0]->realVars[51] /* weaBus.solAlt variable */) = 1.570796326794897 - (data->localData[0]->realVars[55] /* weaBus.solZen variable */);
#line 1247 OMC_FILE
  TRACE_POP
}
/*
equation index: 285
type: WHEN

when {$whenCondition2} then
  weaDat.conTim.tNext = if weaDat.conTim.canRepeatWeatherFile then weaDat.conTim.lenWea * (1.0 + (*Real*)(integer(weaBus.cloTim / weaDat.conTim.lenWea))) else time;
end when;
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  if(((data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */) /* edge */))
  {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    (data->localData[0]->realVars[139] /* weaDat.conTim.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[93] /* weaDat.conTim.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[47] /* weaBus.cloTim variable */),(data->simulationInfo->realParameter[93] /* weaDat.conTim.lenWea PARAM */),"weaDat.conTim.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 1266 OMC_FILE
  }
  TRACE_POP
}
/*
equation index: 286
type: SIMPLE_ASSIGN
weaDat.conTim.calTim = if weaDat.conTim.canRepeatWeatherFile then weaBus.cloTim - weaDat.conTim.tNext + weaDat.conTim.lenWea else weaBus.cloTim
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
#line 38 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */)?(data->localData[0]->realVars[47] /* weaBus.cloTim variable */) - (data->localData[0]->realVars[139] /* weaDat.conTim.tNext DISCRETE */) + (data->simulationInfo->realParameter[93] /* weaDat.conTim.lenWea PARAM */):(data->localData[0]->realVars[47] /* weaBus.cloTim variable */));
#line 1281 OMC_FILE
  TRACE_POP
}
/*
equation index: 287
type: SIMPLE_ASSIGN
weaDat.datRea.y[1] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 1, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  (data->localData[0]->realVars[66] /* weaDat.datRea.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 1), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 288
type: SIMPLE_ASSIGN
weaBus.TDryBul = 273.15 + weaDat.datRea.y[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
#line 37 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[44] /* weaBus.TDryBul variable */) = 273.15 + (data->localData[0]->realVars[66] /* weaDat.datRea.y[1] variable */);
#line 1307 OMC_FILE
  TRACE_POP
}
/*
equation index: 289
type: SIMPLE_ASSIGN
$cse2 = exp(4102.99 / (weaBus.TDryBul - 35.719) - 17.2799)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  (data->localData[0]->realVars[10] /* $cse2 variable */) = exp(DIVISION_SIM(4102.99,(data->localData[0]->realVars[44] /* weaBus.TDryBul variable */) - 35.719,"weaBus.TDryBul - 35.719",equationIndexes) - 17.2799);
  TRACE_POP
}
/*
equation index: 290
type: SIMPLE_ASSIGN
weaDat.datRea.y[2] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 2, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  (data->localData[0]->realVars[67] /* weaDat.datRea.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 2), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 291
type: SIMPLE_ASSIGN
weaBus.TDewPoi = 273.15 + weaDat.datRea.y[2]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
#line 37 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */) = 273.15 + (data->localData[0]->realVars[67] /* weaDat.datRea.y[2] variable */);
#line 1345 OMC_FILE
  TRACE_POP
}
/*
equation index: 292
type: SIMPLE_ASSIGN
weaDat.TBlaSkyCom.TDewPoiK = smooth(1, if noEvent(weaBus.TDewPoi - weaBus.TDryBul > 0.1) then weaBus.TDryBul else if noEvent(weaBus.TDewPoi - weaBus.TDryBul < -0.1) then weaBus.TDewPoi else 0.25 * 10.0 * (weaBus.TDewPoi - weaBus.TDryBul) * ((10.0 * (weaBus.TDewPoi - weaBus.TDryBul)) ^ 2.0 - 3.0) * (weaBus.TDewPoi - weaBus.TDryBul) + 0.5 * (weaBus.TDryBul + weaBus.TDewPoi))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
  modelica_boolean tmp67;
  modelica_boolean tmp68;
  modelica_real tmp69;
  modelica_boolean tmp70;
  modelica_real tmp71;
  modelica_boolean tmp72;
  modelica_real tmp73;
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp67 = Greater((data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */) - (data->localData[0]->realVars[44] /* weaBus.TDryBul variable */),0.1);
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp72 = (modelica_boolean)tmp67;
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  if(tmp72)
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp73 = (data->localData[0]->realVars[44] /* weaBus.TDryBul variable */);
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  else
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp68 = Less((data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */) - (data->localData[0]->realVars[44] /* weaBus.TDryBul variable */),-0.1);
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp70 = (modelica_boolean)tmp68;
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    if(tmp70)
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp71 = (data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */);
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    else
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp69 = (10.0) * ((data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */) - (data->localData[0]->realVars[44] /* weaBus.TDryBul variable */));
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp71 = (0.25) * ((((10.0) * ((data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */) - (data->localData[0]->realVars[44] /* weaBus.TDryBul variable */))) * ((tmp69 * tmp69) - 3.0)) * ((data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */) - (data->localData[0]->realVars[44] /* weaBus.TDryBul variable */))) + (0.5) * ((data->localData[0]->realVars[44] /* weaBus.TDryBul variable */) + (data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */));
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp73 = tmp71;
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 39 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  (data->localData[0]->realVars[58] /* weaDat.TBlaSkyCom.TDewPoiK variable */) = tmp73;
#line 1408 OMC_FILE
  TRACE_POP
}
/*
equation index: 293
type: SIMPLE_ASSIGN
$cse13 = log((-weaDat.TBlaSkyCom.TDewPoiK) / (-273.15))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
  modelica_real tmp74;
  tmp74 = DIVISION_SIM((-(data->localData[0]->realVars[58] /* weaDat.TBlaSkyCom.TDewPoiK variable */)),-273.15,"-273.15",equationIndexes);
  if(!(tmp74 > 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of log((-weaDat.TBlaSkyCom.TDewPoiK) / (-273.15)) was %g should be > 0", tmp74);
    }
  }
  (data->localData[0]->realVars[3] /* $cse13 variable */) = log(tmp74);
  TRACE_POP
}
/*
equation index: 294
type: SIMPLE_ASSIGN
weaDat.datRea.y[3] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 3, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
  (data->localData[0]->realVars[68] /* weaDat.datRea.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 3), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 295
type: SIMPLE_ASSIGN
weaDat.relHumSel.uFil = 0.01 * weaDat.datRea.y[3]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[100] /* weaDat.relHumSel.uFil variable */) = (0.01) * ((data->localData[0]->realVars[68] /* weaDat.datRea.y[3] variable */));
#line 1460 OMC_FILE
  TRACE_POP
}
/*
equation index: 296
type: SIMPLE_ASSIGN
$cse17 = max(0.0, weaDat.relHumSel.uFil)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
  (data->localData[0]->realVars[7] /* $cse17 variable */) = fmax(0.0,(data->localData[0]->realVars[100] /* weaDat.relHumSel.uFil variable */));
  TRACE_POP
}
/*
equation index: 297
type: SIMPLE_ASSIGN
weaBus.relHum = min(1.0, $cse17)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  (data->localData[0]->realVars[50] /* weaBus.relHum variable */) = fmin(1.0,(data->localData[0]->realVars[7] /* $cse17 variable */));
  TRACE_POP
}
/*
equation index: 298
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiDryBul = 0.621964713077499 * weaBus.relHum / ((-0.378035286922501) * weaBus.relHum + 165.6565689594004 * $cse2)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
#line 63 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  (data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */) = (0.621964713077499) * (DIVISION_SIM((data->localData[0]->realVars[50] /* weaBus.relHum variable */),(-0.378035286922501) * ((data->localData[0]->realVars[50] /* weaBus.relHum variable */)) + (165.6565689594004) * ((data->localData[0]->realVars[10] /* $cse2 variable */)),"(-0.378035286922501) * weaBus.relHum + 165.6565689594004 * $cse2",equationIndexes));
#line 1498 OMC_FILE
  TRACE_POP
}
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_299(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_300(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_301(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_302(DATA*, threadData_t*);
/*
equation index: 308
indexNonlinear: 1
type: NONLINEAR

vars: {weaBus.TWetBul}
eqns: {299, 300, 301, 302}
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,308};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 308 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = (data->localData[0]->realVars[45] /* weaBus.TWetBul variable */);
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,308};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 308 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[45] /* weaBus.TWetBul variable */) = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  TRACE_POP
}
/*
equation index: 309
type: SIMPLE_ASSIGN
weaDat.datRea.y[4] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 4, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
  (data->localData[0]->realVars[69] /* weaDat.datRea.y[4] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 4), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 310
type: SIMPLE_ASSIGN
weaDat.datRea.y[5] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 5, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
  (data->localData[0]->realVars[70] /* weaDat.datRea.y[5] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 5), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 311
type: SIMPLE_ASSIGN
weaDat.datRea.y[6] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 6, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
  (data->localData[0]->realVars[71] /* weaDat.datRea.y[6] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 6), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 312
type: SIMPLE_ASSIGN
weaDat.datRea.y[7] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 7, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,312};
  (data->localData[0]->realVars[72] /* weaDat.datRea.y[7] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 7), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 313
type: SIMPLE_ASSIGN
weaDat.datRea.y[8] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 8, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,313};
  (data->localData[0]->realVars[73] /* weaDat.datRea.y[8] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 8), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 314
type: SIMPLE_ASSIGN
weaDat.datRea.y[9] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 9, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
  (data->localData[0]->realVars[74] /* weaDat.datRea.y[9] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 9), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 315
type: SIMPLE_ASSIGN
weaDat.datRea.y[10] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 10, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,315};
  (data->localData[0]->realVars[75] /* weaDat.datRea.y[10] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 10), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 316
type: SIMPLE_ASSIGN
weaDat.datRea.y[11] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 11, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  (data->localData[0]->realVars[76] /* weaDat.datRea.y[11] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 11), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 317
type: SIMPLE_ASSIGN
weaDat.conWinDir.y = 0.0174532925199433 * weaDat.datRea.y[11]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
#line 145 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[65] /* weaDat.conWinDir.y variable */) = (0.0174532925199433) * ((data->localData[0]->realVars[76] /* weaDat.datRea.y[11] variable */));
#line 1642 OMC_FILE
  TRACE_POP
}
/*
equation index: 318
type: SIMPLE_ASSIGN
$cse14 = max(0.0, weaDat.conWinDir.y)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  (data->localData[0]->realVars[4] /* $cse14 variable */) = fmax(0.0,(data->localData[0]->realVars[65] /* weaDat.conWinDir.y variable */));
  TRACE_POP
}
/*
equation index: 319
type: SIMPLE_ASSIGN
weaBus.winDir = min(6.283185307179586, $cse14)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,319};
  (data->localData[0]->realVars[56] /* weaBus.winDir variable */) = fmin(6.283185307179586,(data->localData[0]->realVars[4] /* $cse14 variable */));
  TRACE_POP
}
/*
equation index: 320
type: SIMPLE_ASSIGN
weaDat.datRea.y[12] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 12, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,320};
  (data->localData[0]->realVars[77] /* weaDat.datRea.y[12] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 12), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 321
type: SIMPLE_ASSIGN
weaBus.winSpe = max(0.0, weaDat.datRea.y[12])
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_321(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,321};
  (data->localData[0]->realVars[57] /* weaBus.winSpe variable */) = fmax(0.0,(data->localData[0]->realVars[77] /* weaDat.datRea.y[12] variable */));
  TRACE_POP
}
/*
equation index: 322
type: SIMPLE_ASSIGN
weaDat.datRea.y[13] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 13, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_322(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,322};
  (data->localData[0]->realVars[78] /* weaDat.datRea.y[13] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 13), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 323
type: SIMPLE_ASSIGN
weaDat.totSkyCovSel.y = 0.1 * weaDat.datRea.y[13]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_323(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,323};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[106] /* weaDat.totSkyCovSel.y variable */) = (0.1) * ((data->localData[0]->realVars[78] /* weaDat.datRea.y[13] variable */));
#line 1716 OMC_FILE
  TRACE_POP
}
/*
equation index: 324
type: SIMPLE_ASSIGN
$cse16 = max(0.0, weaDat.totSkyCovSel.y)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,324};
  (data->localData[0]->realVars[6] /* $cse16 variable */) = fmax(0.0,(data->localData[0]->realVars[106] /* weaDat.totSkyCovSel.y variable */));
  TRACE_POP
}
/*
equation index: 325
type: SIMPLE_ASSIGN
weaBus.nTot = min(1.0, $cse16)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_325(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,325};
  (data->localData[0]->realVars[49] /* weaBus.nTot variable */) = fmin(1.0,(data->localData[0]->realVars[6] /* $cse16 variable */));
  TRACE_POP
}
/*
equation index: 326
type: SIMPLE_ASSIGN
weaDat.datRea.y[14] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 14, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_326(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,326};
  (data->localData[0]->realVars[79] /* weaDat.datRea.y[14] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 14), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 327
type: SIMPLE_ASSIGN
weaDat.opaSkyCovSel.y = 0.1 * weaDat.datRea.y[14]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_327(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,327};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[98] /* weaDat.opaSkyCovSel.y variable */) = (0.1) * ((data->localData[0]->realVars[79] /* weaDat.datRea.y[14] variable */));
#line 1766 OMC_FILE
  TRACE_POP
}
/*
equation index: 328
type: SIMPLE_ASSIGN
$cse15 = max(0.0, weaDat.opaSkyCovSel.y)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,328};
  (data->localData[0]->realVars[5] /* $cse15 variable */) = fmax(0.0,(data->localData[0]->realVars[98] /* weaDat.opaSkyCovSel.y variable */));
  TRACE_POP
}
/*
equation index: 329
type: SIMPLE_ASSIGN
weaBus.nOpa = min(1.0, $cse15)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,329};
  (data->localData[0]->realVars[48] /* weaBus.nOpa variable */) = fmin(1.0,(data->localData[0]->realVars[5] /* $cse15 variable */));
  TRACE_POP
}
/*
equation index: 330
type: SIMPLE_ASSIGN
weaDat.TBlaSkyCom.nOpa10 = 10.0 * weaBus.nOpa
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,330};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  (data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */) = (10.0) * ((data->localData[0]->realVars[48] /* weaBus.nOpa variable */));
#line 1804 OMC_FILE
  TRACE_POP
}
/*
equation index: 331
type: SIMPLE_ASSIGN
weaDat.TBlaSkyCom.epsSky = (0.787 + 0.764 * $cse13) * (1.0 + 0.0224 * weaDat.TBlaSkyCom.nOpa10 + (-0.0035) * weaDat.TBlaSkyCom.nOpa10 ^ 2.0 + 0.00028 * weaDat.TBlaSkyCom.nOpa10 ^ 3.0)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,331};
  modelica_real tmp0;
  modelica_real tmp1;
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp0 = (data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */);
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp1 = (data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */);
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  (data->localData[0]->realVars[59] /* weaDat.TBlaSkyCom.epsSky variable */) = (0.787 + (0.764) * ((data->localData[0]->realVars[3] /* $cse13 variable */))) * (1.0 + (0.0224) * ((data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */)) + (-0.0035) * ((tmp0 * tmp0)) + (0.00028) * ((tmp1 * tmp1 * tmp1)));
#line 1824 OMC_FILE
  TRACE_POP
}
/*
equation index: 332
type: SIMPLE_ASSIGN
weaBus.TBlaSky = weaBus.TDryBul * weaDat.TBlaSkyCom.epsSky ^ 0.25
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,332};
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp2 = (data->localData[0]->realVars[59] /* weaDat.TBlaSkyCom.epsSky variable */);
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp3 = 0.25;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  if(tmp2 < 0.0 && tmp3 != 0.0)
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp5 = modf(tmp3, &tmp6);
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    if(tmp5 > 0.5)
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp5 -= 1.0;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp6 += 1.0;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    else if(tmp5 < -0.5)
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp5 += 1.0;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp6 -= 1.0;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    if(fabs(tmp5) < 1e-10)
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp4 = pow(tmp2, tmp6);
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    else
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp8 = modf(1.0/tmp3, &tmp7);
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      if(tmp8 > 0.5)
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp8 -= 1.0;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp7 += 1.0;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      else if(tmp8 < -0.5)
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp8 += 1.0;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp7 -= 1.0;
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      if(fabs(tmp8) < 1e-10 && ((unsigned long)tmp7 & 1))
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp4 = -pow(-tmp2, tmp5)*pow(tmp2, tmp6);
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      else
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp2, tmp3);
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  else
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp4 = pow(tmp2, tmp3);
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  if(isnan(tmp4) || isinf(tmp4))
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp2, tmp3);
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 43 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  (data->localData[0]->realVars[42] /* weaBus.TBlaSky variable */) = ((data->localData[0]->realVars[44] /* weaBus.TDryBul variable */)) * (tmp4);
#line 1945 OMC_FILE
  TRACE_POP
}
/*
equation index: 333
type: SIMPLE_ASSIGN
weaDat.datRea.y[15] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 15, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_333(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,333};
  (data->localData[0]->realVars[80] /* weaDat.datRea.y[15] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 15), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 334
type: SIMPLE_ASSIGN
weaDat.datRea.y[16] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 16, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  (data->localData[0]->realVars[81] /* weaDat.datRea.y[16] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 16), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 335
type: SIMPLE_ASSIGN
weaBus.ceiHei = max(0.0, weaDat.datRea.y[16])
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  (data->localData[0]->realVars[46] /* weaBus.ceiHei variable */) = fmax(0.0,(data->localData[0]->realVars[81] /* weaDat.datRea.y[16] variable */));
  TRACE_POP
}
/*
equation index: 336
type: SIMPLE_ASSIGN
weaDat.datRea.y[17] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 17, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  (data->localData[0]->realVars[82] /* weaDat.datRea.y[17] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 17), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 337
type: SIMPLE_ASSIGN
weaDat.datRea.y[18] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 18, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,337};
  (data->localData[0]->realVars[83] /* weaDat.datRea.y[18] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 18), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 338
type: SIMPLE_ASSIGN
weaDat.datRea.y[19] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 19, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,338};
  (data->localData[0]->realVars[84] /* weaDat.datRea.y[19] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 19), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 339
type: SIMPLE_ASSIGN
weaDat.datRea.y[20] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 20, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_339(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,339};
  (data->localData[0]->realVars[85] /* weaDat.datRea.y[20] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 20), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 340
type: SIMPLE_ASSIGN
weaDat.datRea.y[21] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 21, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_340(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,340};
  (data->localData[0]->realVars[86] /* weaDat.datRea.y[21] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 21), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 341
type: SIMPLE_ASSIGN
weaDat.datRea.y[22] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 22, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_341(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,341};
  (data->localData[0]->realVars[87] /* weaDat.datRea.y[22] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 22), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 342
type: SIMPLE_ASSIGN
weaDat.datRea.y[23] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 23, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_342(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,342};
  (data->localData[0]->realVars[88] /* weaDat.datRea.y[23] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 23), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 343
type: SIMPLE_ASSIGN
weaDat.datRea.y[24] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 24, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_343(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,343};
  (data->localData[0]->realVars[89] /* weaDat.datRea.y[24] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 24), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 344
type: SIMPLE_ASSIGN
weaDat.datRea.y[25] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 25, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_344(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,344};
  (data->localData[0]->realVars[90] /* weaDat.datRea.y[25] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 25), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 345
type: SIMPLE_ASSIGN
weaDat.datRea.y[26] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 26, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,345};
  (data->localData[0]->realVars[91] /* weaDat.datRea.y[26] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 26), (data->localData[0]->realVars[63] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 346
type: SIMPLE_ASSIGN
weaBus.HHorIR = max(0.0, weaDat.datRea.y[26])
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,346};
  (data->localData[0]->realVars[41] /* weaBus.HHorIR variable */) = fmax(0.0,(data->localData[0]->realVars[91] /* weaDat.datRea.y[26] variable */));
  TRACE_POP
}
/*
equation index: 353
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim), "In WinRadCustomWea.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTim.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
  modelica_boolean tmp9;
  static const MMC_DEFSTRINGLIT(tmp10,128,"In WinRadCustomWea.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp11;
  modelica_metatype tmpMeta12;
  static const MMC_DEFSTRINGLIT(tmp13,29," is less than the start time ");
  modelica_metatype tmpMeta14;
  modelica_string tmp15;
  modelica_metatype tmpMeta16;
  static const MMC_DEFSTRINGLIT(tmp17,26," of the weather data file.");
  modelica_metatype tmpMeta18;
  static int tmp19 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp9 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[95] /* weaDat.conTim.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp9))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp11 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta12 = stringAppend(MMC_REFSTRINGLIT(tmp10),tmp11);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta14 = stringAppend(tmpMeta12,MMC_REFSTRINGLIT(tmp13));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp15 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[95] /* weaDat.conTim.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta16 = stringAppend(tmpMeta14,tmp15);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta18 = stringAppend(tmpMeta16,MMC_REFSTRINGLIT(tmp17));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta18));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta18));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2184 OMC_FILE
  TRACE_POP
}
/*
equation index: 352
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0), "In WinRadCustomWea.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTim.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,352};
  modelica_boolean tmp20;
  static const MMC_DEFSTRINGLIT(tmp21,128,"In WinRadCustomWea.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp22;
  modelica_metatype tmpMeta23;
  static const MMC_DEFSTRINGLIT(tmp24,22," exceeds the end time ");
  modelica_metatype tmpMeta25;
  modelica_string tmp26;
  modelica_metatype tmpMeta27;
  static const MMC_DEFSTRINGLIT(tmp28,26," of the weather data file.");
  modelica_metatype tmpMeta29;
  static int tmp30 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp20 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[94] /* weaDat.conTim.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp20))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp22 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta23 = stringAppend(MMC_REFSTRINGLIT(tmp21),tmp22);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta25 = stringAppend(tmpMeta23,MMC_REFSTRINGLIT(tmp24));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp26 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[94] /* weaDat.conTim.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta27 = stringAppend(tmpMeta25,tmp26);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta29 = stringAppend(tmpMeta27,MMC_REFSTRINGLIT(tmp28));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta29));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta29));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2255 OMC_FILE
  TRACE_POP
}
/*
equation index: 351
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim), "In WinRadCustomWea.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTimMin.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,131,"In WinRadCustomWea.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp33;
  modelica_metatype tmpMeta34;
  static const MMC_DEFSTRINGLIT(tmp35,29," is less than the start time ");
  modelica_metatype tmpMeta36;
  modelica_string tmp37;
  modelica_metatype tmpMeta38;
  static const MMC_DEFSTRINGLIT(tmp39,26," of the weather data file.");
  modelica_metatype tmpMeta40;
  static int tmp41 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp31 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[98] /* weaDat.conTimMin.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp31))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp33 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta34 = stringAppend(MMC_REFSTRINGLIT(tmp32),tmp33);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta36 = stringAppend(tmpMeta34,MMC_REFSTRINGLIT(tmp35));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp37 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[98] /* weaDat.conTimMin.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta38 = stringAppend(tmpMeta36,tmp37);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta40 = stringAppend(tmpMeta38,MMC_REFSTRINGLIT(tmp39));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta40));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta40));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2326 OMC_FILE
  TRACE_POP
}
/*
equation index: 350
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0), "In WinRadCustomWea.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTimMin.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,350};
  modelica_boolean tmp42;
  static const MMC_DEFSTRINGLIT(tmp43,131,"In WinRadCustomWea.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp44;
  modelica_metatype tmpMeta45;
  static const MMC_DEFSTRINGLIT(tmp46,22," exceeds the end time ");
  modelica_metatype tmpMeta47;
  modelica_string tmp48;
  modelica_metatype tmpMeta49;
  static const MMC_DEFSTRINGLIT(tmp50,26," of the weather data file.");
  modelica_metatype tmpMeta51;
  static int tmp52 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp42 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[97] /* weaDat.conTimMin.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp42))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp44 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta45 = stringAppend(MMC_REFSTRINGLIT(tmp43),tmp44);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta47 = stringAppend(tmpMeta45,MMC_REFSTRINGLIT(tmp46));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp48 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[97] /* weaDat.conTimMin.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta49 = stringAppend(tmpMeta47,tmp48);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta51 = stringAppend(tmpMeta49,MMC_REFSTRINGLIT(tmp50));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta51));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta51));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2397 OMC_FILE
  TRACE_POP
}
/*
equation index: 349
type: ALGORITHM

  assert(noEvent(weaBus.TBlaSky > 0.0) and noEvent(weaBus.TBlaSky < 343.15), "In WinRadCustomWea.weaDat.cheTemBlaSky: Weather data black-body sky temperature out of bounds.
   TIn = " + String(weaBus.TBlaSky, 6, 0, true));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,349};
  modelica_boolean tmp53;
  modelica_boolean tmp54;
  static const MMC_DEFSTRINGLIT(tmp55,104,"In WinRadCustomWea.weaDat.cheTemBlaSky: Weather data black-body sky temperature out of bounds.\n   TIn = ");
  modelica_string tmp56;
  modelica_metatype tmpMeta57;
  static int tmp58 = 0;
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp53 = Greater((data->localData[0]->realVars[42] /* weaBus.TBlaSky variable */),0.0);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp54 = Less((data->localData[0]->realVars[42] /* weaBus.TBlaSky variable */),343.15);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    if(!(tmp53 && tmp54))
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp56 = modelica_real_to_modelica_string((data->localData[0]->realVars[42] /* weaBus.TBlaSky variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmpMeta57 = stringAppend(MMC_REFSTRINGLIT(tmp55),tmp56);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        const char* assert_cond = "(noEvent(weaBus.TBlaSky > 0.0) and noEvent(weaBus.TBlaSky < 343.15))";
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",25,3,27,18,0};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta57));
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        } else {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",25,3,27,18,0};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta57));
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  }
#line 2457 OMC_FILE
  TRACE_POP
}
/*
equation index: 348
type: ALGORITHM

  assert(noEvent(weaBus.TDewPoi > 203.15) and noEvent(weaBus.TDewPoi < 343.15), "In WinRadCustomWea.weaDat.cheTemDewPoi: Weather data dew point temperature out of bounds.
   TIn = " + String(weaBus.TDewPoi, 6, 0, true));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_348(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,348};
  modelica_boolean tmp59;
  modelica_boolean tmp60;
  static const MMC_DEFSTRINGLIT(tmp61,99,"In WinRadCustomWea.weaDat.cheTemDewPoi: Weather data dew point temperature out of bounds.\n   TIn = ");
  modelica_string tmp62;
  modelica_metatype tmpMeta63;
  static int tmp64 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp59 = Greater((data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */),203.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp60 = Less((data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */),343.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    if(!(tmp59 && tmp60))
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp62 = modelica_real_to_modelica_string((data->localData[0]->realVars[43] /* weaBus.TDewPoi variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmpMeta63 = stringAppend(MMC_REFSTRINGLIT(tmp61),tmp62);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        const char* assert_cond = "(noEvent(weaBus.TDewPoi > 203.15) and noEvent(weaBus.TDewPoi < 343.15))";
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  }
#line 2517 OMC_FILE
  TRACE_POP
}
/*
equation index: 347
type: ALGORITHM

  assert(noEvent(weaBus.TDryBul > 203.15) and noEvent(weaBus.TDryBul < 343.15), "In WinRadCustomWea.weaDat.cheTemDryBul: Weather data dry bulb temperature out of bounds.
   TIn = " + String(weaBus.TDryBul, 6, 0, true));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,347};
  modelica_boolean tmp65;
  modelica_boolean tmp66;
  static const MMC_DEFSTRINGLIT(tmp67,98,"In WinRadCustomWea.weaDat.cheTemDryBul: Weather data dry bulb temperature out of bounds.\n   TIn = ");
  modelica_string tmp68;
  modelica_metatype tmpMeta69;
  static int tmp70 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp65 = Greater((data->localData[0]->realVars[44] /* weaBus.TDryBul variable */),203.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp66 = Less((data->localData[0]->realVars[44] /* weaBus.TDryBul variable */),343.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    if(!(tmp65 && tmp66))
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp68 = modelica_real_to_modelica_string((data->localData[0]->realVars[44] /* weaBus.TDryBul variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmpMeta69 = stringAppend(MMC_REFSTRINGLIT(tmp67),tmp68);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        const char* assert_cond = "(noEvent(weaBus.TDryBul > 203.15) and noEvent(weaBus.TDryBul < 343.15))";
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta69));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta69));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  }
#line 2577 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionLocalKnownVars(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_230(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_231(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_232(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_233(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_234(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_235(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_236(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_237(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_238(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_239(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_240(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_241(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_242(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_243(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_244(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_245(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_246(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_247(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_248(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_249(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_250(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_251(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_252(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_253(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_254(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_255(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_256(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_257(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_258(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_259(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_260(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_261(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_262(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_263(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_264(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_265(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_266(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_267(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_268(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_269(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_270(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_271(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_272(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_273(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_274(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_275(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_276(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_277(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_278(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_279(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_280(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_281(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_282(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_283(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_284(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_285(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_286(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_287(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_288(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_289(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_290(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_291(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_292(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_293(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_294(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_295(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_296(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_297(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_298(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_308(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_309(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_310(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_311(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_312(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_313(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_314(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_315(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_316(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_317(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_318(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_319(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_320(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_321(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_322(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_323(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_324(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_325(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_326(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_327(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_328(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_329(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_330(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_331(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_332(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_333(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_334(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_335(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_336(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_337(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_338(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_339(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_340(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_341(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_342(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_343(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_344(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_345(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_346(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_353(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_352(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_351(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_350(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_349(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_348(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_347(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_12jac.h"
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialNonLinearSystem,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initializeDAEmodeData,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionODE,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionAlgebraics,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionDAE,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionLocalKnownVars,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_input_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_input_function_init,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_input_function_updateStartValues,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_data_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_output_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_setc_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_setb_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_storeDelayed,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_storeSpatialDistribution,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_initSpatialDistribution,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_updateBoundVariableAttributes,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionRemovedInitialEquations,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_updateBoundParameters,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_checkForAsserts,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_ZeroCrossingsEquations,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_ZeroCrossings,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_updateRelations,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_zeroCrossingDescription,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_relationDescription,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_initSample,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_A,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_B,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_C,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_D,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_F,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_H,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianA,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianB,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianC,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianD,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianF,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianH,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacA_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacB_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacC_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacD_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacF_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacH_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_linear_model_frame,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_linear_model_datarecovery_frame,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_mayer,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_lagrange,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_pickUpBoundsForInputsInOptimization,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_setInputData,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_getTimeGrid,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_symbolicInlineSystem,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_initSynchronous,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_updateSynchronous,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_equationsSynchronous,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_inputNames,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_dataReconciliationInputNames,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_dataReconciliationUnmeasuredVariables,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_read_input_fmu,
   NULL,
   NULL,
   -1,
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
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Buildings.HeatTransfer.Windows.Examples.WinRadCustomWea";
  data->modelData->modelFilePrefix = "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Examples";
  data->modelData->modelGUID = "{76a1fd96-cac4-4f94-b565-72523801a3fa}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 141;
  data->modelData->nDiscreteReal = 2;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 2;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 1318;
  data->modelData->nParametersInteger = 91;
  data->modelData->nParametersBoolean = 27;
  data->modelData->nParametersString = 5;
  data->modelData->nInputVars = 2;
  data->modelData->nOutputVars = 4;
  
  data->modelData->nAliasReal = 235;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 2;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 2;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 2;
  
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_info.json", data->modelData->resourcesDir);
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 24;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 1775;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 2;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 8;
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

