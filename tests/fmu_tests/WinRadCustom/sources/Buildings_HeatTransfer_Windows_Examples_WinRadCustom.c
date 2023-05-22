#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustom/Buildings_HeatTransfer_Windows_Examples_WinRadCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustom.c"
#endif
/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  (data->localData[0]->realVars[17] /* HDifHor_in variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[22] /* HDirNor_in variable */) = data->simulationInfo->inputVars[1];
  (data->localData[0]->realVars[33] /* HGloHor_in variable */) = data->simulationInfo->inputVars[2];
  (data->localData[0]->realVars[34] /* HInfHor_in variable */) = data->simulationInfo->inputVars[3];
  (data->localData[0]->realVars[36] /* HRoo_in variable */) = data->simulationInfo->inputVars[4];
  (data->localData[0]->realVars[43] /* TBlaSky_in variable */) = data->simulationInfo->inputVars[5];
  (data->localData[0]->realVars[44] /* TDewPoi_in variable */) = data->simulationInfo->inputVars[6];
  (data->localData[0]->realVars[45] /* TDryBul_in variable */) = data->simulationInfo->inputVars[7];
  (data->localData[0]->realVars[46] /* ceiHei_in variable */) = data->simulationInfo->inputVars[8];
  (data->localData[0]->realVars[47] /* opaSkyCov_in variable */) = data->simulationInfo->inputVars[9];
  (data->localData[0]->realVars[48] /* relHum_in variable */) = data->simulationInfo->inputVars[10];
  (data->localData[0]->realVars[49] /* totSkyCov_in variable */) = data->simulationInfo->inputVars[11];
  (data->localData[0]->realVars[50] /* uSha variable */) = data->simulationInfo->inputVars[12];
  (data->localData[0]->realVars[51] /* uSta variable */) = data->simulationInfo->inputVars[13];
  (data->localData[0]->realVars[115] /* winDir_in variable */) = data->simulationInfo->inputVars[14];
  (data->localData[0]->realVars[146] /* winSpe_in variable */) = data->simulationInfo->inputVars[15];
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[17].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[22].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->realVarsData[33].attribute.start;
  data->simulationInfo->inputVars[3] = data->modelData->realVarsData[34].attribute.start;
  data->simulationInfo->inputVars[4] = data->modelData->realVarsData[36].attribute.start;
  data->simulationInfo->inputVars[5] = data->modelData->realVarsData[43].attribute.start;
  data->simulationInfo->inputVars[6] = data->modelData->realVarsData[44].attribute.start;
  data->simulationInfo->inputVars[7] = data->modelData->realVarsData[45].attribute.start;
  data->simulationInfo->inputVars[8] = data->modelData->realVarsData[46].attribute.start;
  data->simulationInfo->inputVars[9] = data->modelData->realVarsData[47].attribute.start;
  data->simulationInfo->inputVars[10] = data->modelData->realVarsData[48].attribute.start;
  data->simulationInfo->inputVars[11] = data->modelData->realVarsData[49].attribute.start;
  data->simulationInfo->inputVars[12] = data->modelData->realVarsData[50].attribute.start;
  data->simulationInfo->inputVars[13] = data->modelData->realVarsData[51].attribute.start;
  data->simulationInfo->inputVars[14] = data->modelData->realVarsData[115].attribute.start;
  data->simulationInfo->inputVars[15] = data->modelData->realVarsData[146].attribute.start;
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[17].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[22].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->realVarsData[33].attribute.start = data->simulationInfo->inputVars[2];
  data->modelData->realVarsData[34].attribute.start = data->simulationInfo->inputVars[3];
  data->modelData->realVarsData[36].attribute.start = data->simulationInfo->inputVars[4];
  data->modelData->realVarsData[43].attribute.start = data->simulationInfo->inputVars[5];
  data->modelData->realVarsData[44].attribute.start = data->simulationInfo->inputVars[6];
  data->modelData->realVarsData[45].attribute.start = data->simulationInfo->inputVars[7];
  data->modelData->realVarsData[46].attribute.start = data->simulationInfo->inputVars[8];
  data->modelData->realVarsData[47].attribute.start = data->simulationInfo->inputVars[9];
  data->modelData->realVarsData[48].attribute.start = data->simulationInfo->inputVars[10];
  data->modelData->realVarsData[49].attribute.start = data->simulationInfo->inputVars[11];
  data->modelData->realVarsData[50].attribute.start = data->simulationInfo->inputVars[12];
  data->modelData->realVarsData[51].attribute.start = data->simulationInfo->inputVars[13];
  data->modelData->realVarsData[115].attribute.start = data->simulationInfo->inputVars[14];
  data->modelData->realVarsData[146].attribute.start = data->simulationInfo->inputVars[15];
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[17].info.name;
  names[1] = (char *) data->modelData->realVarsData[22].info.name;
  names[2] = (char *) data->modelData->realVarsData[33].info.name;
  names[3] = (char *) data->modelData->realVarsData[34].info.name;
  names[4] = (char *) data->modelData->realVarsData[36].info.name;
  names[5] = (char *) data->modelData->realVarsData[43].info.name;
  names[6] = (char *) data->modelData->realVarsData[44].info.name;
  names[7] = (char *) data->modelData->realVarsData[45].info.name;
  names[8] = (char *) data->modelData->realVarsData[46].info.name;
  names[9] = (char *) data->modelData->realVarsData[47].info.name;
  names[10] = (char *) data->modelData->realVarsData[48].info.name;
  names[11] = (char *) data->modelData->realVarsData[49].info.name;
  names[12] = (char *) data->modelData->realVarsData[50].info.name;
  names[13] = (char *) data->modelData->realVarsData[51].info.name;
  names[14] = (char *) data->modelData->realVarsData[115].info.name;
  names[15] = (char *) data->modelData->realVarsData[146].info.name;
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[37] /* QAbsExtSha_flow variable */);
  data->simulationInfo->outputVars[1] = (data->localData[0]->realVars[38] /* QAbsGlaSha_flow variable */);
  data->simulationInfo->outputVars[2] = (data->localData[0]->realVars[39] /* QAbsGlaUns_flow variable */);
  data->simulationInfo->outputVars[3] = (data->localData[0]->realVars[40] /* QAbsIntSha_flow variable */);
  data->simulationInfo->outputVars[4] = (data->localData[0]->realVars[41] /* QTraDif_flow variable */);
  data->simulationInfo->outputVars[5] = (data->localData[0]->realVars[42] /* QTraDir_flow variable */);
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 227
type: SIMPLE_ASSIGN
weaBus.cloTim = time
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
#line 9 "/home/marius/modelica-buildings/Buildings/Utilities/Time/ModelTime.mo"
  (data->localData[0]->realVars[58] /* weaBus.cloTim variable */) = data->localData[0]->timeValue;
#line 189 OMC_FILE
  TRACE_POP
}
/*
equation index: 228
type: SIMPLE_ASSIGN
$whenCondition2 = weaDat.conTim.canRepeatWeatherFile and weaBus.cloTim > pre(weaDat.conTim.tNext)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  modelica_boolean tmp0;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[58] /* weaBus.cloTim variable */), (data->simulationInfo->realVarsPre[147] /* weaDat.conTim.tNext DISCRETE */), 0, Greater, GreaterZC);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) && tmp0);
#line 206 OMC_FILE
  TRACE_POP
}
/*
equation index: 229
type: SIMPLE_ASSIGN
$cse3 = cos((weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  (data->localData[0]->realVars[12] /* $cse3 variable */) = cos((DIVISION_SIM((data->localData[0]->realVars[58] /* weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848));
  TRACE_POP
}
/*
equation index: 230
type: SIMPLE_ASSIGN
weaBus.solDec = asin((-0.3979486313076103) * $cse3)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  modelica_real tmp1;
  tmp1 = (-0.3979486313076103) * ((data->localData[0]->realVars[12] /* $cse3 variable */));
  if(!(tmp1 >= -1.0 && tmp1 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * $cse3) outside the domain -1.0 <= %g <= 1.0", tmp1);
    }
  }
  (data->localData[0]->realVars[63] /* weaBus.solDec variable */) = asin(tmp1);
  TRACE_POP
}
/*
equation index: 231
type: SIMPLE_ASSIGN
$cse10 = sin(weaBus.solDec)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  (data->localData[0]->realVars[0] /* $cse10 variable */) = sin((data->localData[0]->realVars[63] /* weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 232
type: SIMPLE_ASSIGN
$cse7 = cos(weaBus.solDec)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  (data->localData[0]->realVars[15] /* $cse7 variable */) = cos((data->localData[0]->realVars[63] /* weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 233
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.dec_c = cos(weaBus.solDec)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  (data->localData[0]->realVars[26] /* HDirTil.incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[63] /* weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 234
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.dec_s = sin(weaBus.solDec)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  (data->localData[0]->realVars[27] /* HDirTil.incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[63] /* weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 235
type: SIMPLE_ASSIGN
HDirTil.incAng.decAng.decAng = weaBus.solDec
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  (data->localData[0]->realVars[25] /* HDirTil.incAng.decAng.decAng variable */) = (data->localData[0]->realVars[63] /* weaBus.solDec variable */);
  TRACE_POP
}
/*
equation index: 236
type: SIMPLE_ASSIGN
weaDat.add30Min.y = 1800.0 + weaBus.cloTim
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[69] /* weaDat.add30Min.y variable */) = 1800.0 + (data->localData[0]->realVars[58] /* weaBus.cloTim variable */);
#line 318 OMC_FILE
  TRACE_POP
}
/*
equation index: 237
type: SIMPLE_ASSIGN
$whenCondition1 = weaDat.conTimMin.canRepeatWeatherFile and weaDat.add30Min.y > pre(weaDat.conTimMin.tNext)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  modelica_boolean tmp2;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  relationhysteresis(data, &tmp2, (data->localData[0]->realVars[69] /* weaDat.add30Min.y variable */), (data->simulationInfo->realVarsPre[148] /* weaDat.conTimMin.tNext DISCRETE */), 1, Greater, GreaterZC);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) && tmp2);
#line 335 OMC_FILE
  TRACE_POP
}
/*
equation index: 238
type: WHEN

when {$whenCondition1} then
  weaDat.conTimMin.tNext = if weaDat.conTimMin.canRepeatWeatherFile then weaDat.conTimMin.lenWea * (1.0 + (*Real*)(integer(weaDat.add30Min.y / weaDat.conTimMin.lenWea))) else time;
end when;
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  if(((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    (data->localData[0]->realVars[148] /* weaDat.conTimMin.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[94] /* weaDat.conTimMin.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[69] /* weaDat.add30Min.y variable */),(data->simulationInfo->realParameter[94] /* weaDat.conTimMin.lenWea PARAM */),"weaDat.conTimMin.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 354 OMC_FILE
  }
  TRACE_POP
}
/*
equation index: 239
type: SIMPLE_ASSIGN
weaDat.conTimMin.calTim = if weaDat.conTimMin.canRepeatWeatherFile then weaDat.add30Min.y - weaDat.conTimMin.tNext + weaDat.conTimMin.lenWea else weaDat.add30Min.y
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
#line 38 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[74] /* weaDat.conTimMin.calTim variable */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */)?(data->localData[0]->realVars[69] /* weaDat.add30Min.y variable */) - (data->localData[0]->realVars[148] /* weaDat.conTimMin.tNext DISCRETE */) + (data->simulationInfo->realParameter[94] /* weaDat.conTimMin.lenWea PARAM */):(data->localData[0]->realVars[69] /* weaDat.add30Min.y variable */));
#line 369 OMC_FILE
  TRACE_POP
}
/*
equation index: 240
type: SIMPLE_ASSIGN
weaDat.datRea30Min.y[1] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea30Min.tableID, 1, weaDat.conTimMin.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  (data->localData[0]->realVars[102] /* weaDat.datRea30Min.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 1), (data->localData[0]->realVars[74] /* weaDat.conTimMin.calTim variable */));
  TRACE_POP
}
/*
equation index: 241
type: SIMPLE_ASSIGN
weaDat.datRea30Min.y[2] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea30Min.tableID, 2, weaDat.conTimMin.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  (data->localData[0]->realVars[103] /* weaDat.datRea30Min.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 2), (data->localData[0]->realVars[74] /* weaDat.conTimMin.calTim variable */));
  TRACE_POP
}
/*
equation index: 242
type: SIMPLE_ASSIGN
weaDat.datRea30Min.y[3] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea30Min.tableID, 3, weaDat.conTimMin.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  (data->localData[0]->realVars[104] /* weaDat.datRea30Min.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 3), (data->localData[0]->realVars[74] /* weaDat.conTimMin.calTim variable */));
  TRACE_POP
}
/*
equation index: 243
type: SIMPLE_ASSIGN
weaDat.locTim.locTim = weaBus.cloTim + weaDat.locTim.diff
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LocalCivilTime.mo"
  (data->localData[0]->realVars[107] /* weaDat.locTim.locTim variable */) = (data->localData[0]->realVars[58] /* weaBus.cloTim variable */) + (data->simulationInfo->realParameter[105] /* weaDat.locTim.diff PARAM */);
#line 419 OMC_FILE
  TRACE_POP
}
/*
equation index: 244
type: SIMPLE_ASSIGN
weaDat.eqnTim.Bt = 0.01726149809664721 * (-80.0 + 1.157407407407407e-05 * weaBus.cloTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
#line 17 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/EquationOfTime.mo"
  (data->localData[0]->realVars[105] /* weaDat.eqnTim.Bt variable */) = (0.01726149809664721) * (-80.0 + (1.157407407407407e-05) * ((data->localData[0]->realVars[58] /* weaBus.cloTim variable */)));
#line 433 OMC_FILE
  TRACE_POP
}
/*
equation index: 245
type: SIMPLE_ASSIGN
$cse13 = sin(weaDat.eqnTim.Bt)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  (data->localData[0]->realVars[3] /* $cse13 variable */) = sin((data->localData[0]->realVars[105] /* weaDat.eqnTim.Bt variable */));
  TRACE_POP
}
/*
equation index: 246
type: SIMPLE_ASSIGN
$cse12 = cos(weaDat.eqnTim.Bt)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  (data->localData[0]->realVars[2] /* $cse12 variable */) = cos((data->localData[0]->realVars[105] /* weaDat.eqnTim.Bt variable */));
  TRACE_POP
}
/*
equation index: 247
type: SIMPLE_ASSIGN
$cse11 = sin(2.0 * weaDat.eqnTim.Bt)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  (data->localData[0]->realVars[1] /* $cse11 variable */) = sin((2.0) * ((data->localData[0]->realVars[105] /* weaDat.eqnTim.Bt variable */)));
  TRACE_POP
}
/*
equation index: 248
type: SIMPLE_ASSIGN
weaDat.eqnTim.eqnTim = 60.0 * (9.869999999999999 * $cse11 + (-7.53) * $cse12 + (-1.5) * $cse13)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/EquationOfTime.mo"
  (data->localData[0]->realVars[106] /* weaDat.eqnTim.eqnTim variable */) = (60.0) * ((9.869999999999999) * ((data->localData[0]->realVars[1] /* $cse11 variable */)) + (-7.53) * ((data->localData[0]->realVars[2] /* $cse12 variable */)) + (-1.5) * ((data->localData[0]->realVars[3] /* $cse13 variable */)));
#line 483 OMC_FILE
  TRACE_POP
}
/*
equation index: 249
type: SIMPLE_ASSIGN
weaBus.solTim = weaDat.locTim.locTim + weaDat.eqnTim.eqnTim
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SolarTime.mo"
  (data->localData[0]->realVars[65] /* weaBus.solTim variable */) = (data->localData[0]->realVars[107] /* weaDat.locTim.locTim variable */) + (data->localData[0]->realVars[106] /* weaDat.eqnTim.eqnTim variable */);
#line 497 OMC_FILE
  TRACE_POP
}
/*
equation index: 250
type: SIMPLE_ASSIGN
weaBus.solHouAng = 0.2617993877991494 * (-12.0 + 0.0002777777777777778 * weaBus.solTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/SolarHourAngle.mo"
  (data->localData[0]->realVars[64] /* weaBus.solHouAng variable */) = (0.2617993877991494) * (-12.0 + (0.0002777777777777778) * ((data->localData[0]->realVars[65] /* weaBus.solTim variable */)));
#line 511 OMC_FILE
  TRACE_POP
}
/*
equation index: 251
type: SIMPLE_ASSIGN
$cse8 = cos(weaBus.solHouAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  (data->localData[0]->realVars[16] /* $cse8 variable */) = cos((data->localData[0]->realVars[64] /* weaBus.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 252
type: SIMPLE_ASSIGN
weaBus.solZen = acos($cse6 * $cse7 * $cse8 + $cse9 * $cse10)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  modelica_real tmp3;
  tmp3 = (((data->simulationInfo->realParameter[0] /* $cse6 PARAM */)) * ((data->localData[0]->realVars[15] /* $cse7 variable */))) * ((data->localData[0]->realVars[16] /* $cse8 variable */)) + ((data->simulationInfo->realParameter[1] /* $cse9 PARAM */)) * ((data->localData[0]->realVars[0] /* $cse10 variable */));
  if(!(tmp3 >= -1.0 && tmp3 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos($cse6 * $cse7 * $cse8 + $cse9 * $cse10) outside the domain -1.0 <= %g <= 1.0", tmp3);
    }
  }
  (data->localData[0]->realVars[66] /* weaBus.solZen variable */) = acos(tmp3);
  TRACE_POP
}
/*
equation index: 253
type: SIMPLE_ASSIGN
weaBus.solAlt = 1.570796326794897 - weaBus.solZen
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/AltitudeAngle.mo"
  (data->localData[0]->realVars[62] /* weaBus.solAlt variable */) = 1.570796326794897 - (data->localData[0]->realVars[66] /* weaBus.solZen variable */);
#line 563 OMC_FILE
  TRACE_POP
}
/*
equation index: 254
type: SIMPLE_ASSIGN
$cse14 = cos(weaBus.solZen)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  (data->localData[0]->realVars[4] /* $cse14 variable */) = cos((data->localData[0]->realVars[66] /* weaBus.solZen variable */));
  TRACE_POP
}
/*
equation index: 255
type: SIMPLE_ASSIGN
weaBus.HDifHor = max(0.0, HGloHor_in - HDirNor_in * $cse14)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  (data->localData[0]->realVars[52] /* weaBus.HDifHor variable */) = fmax(0.0,(data->localData[0]->realVars[33] /* HGloHor_in variable */) - (((data->localData[0]->realVars[22] /* HDirNor_in variable */)) * ((data->localData[0]->realVars[4] /* $cse14 variable */))));
  TRACE_POP
}
/*
equation index: 256
type: SIMPLE_ASSIGN
HDifTilIso.add.u1 = 0.4999999999999983 * weaBus.HDifHor
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
#line 28 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffuseIsotropic.mo"
  (data->localData[0]->realVars[20] /* HDifTilIso.add.u1 variable */) = (0.4999999999999983) * ((data->localData[0]->realVars[52] /* weaBus.HDifHor variable */));
#line 601 OMC_FILE
  TRACE_POP
}
/*
equation index: 257
type: SIMPLE_ASSIGN
HDirTil.incAng.solHouAng.solHouAng = 0.2617993877991494 * (-12.0 + 0.0002777777777777778 * weaBus.solTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/SolarHourAngle.mo"
  (data->localData[0]->realVars[32] /* HDirTil.incAng.solHouAng.solHouAng variable */) = (0.2617993877991494) * (-12.0 + (0.0002777777777777778) * ((data->localData[0]->realVars[65] /* weaBus.solTim variable */)));
#line 615 OMC_FILE
  TRACE_POP
}
/*
equation index: 258
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.sol_c = cos(HDirTil.incAng.solHouAng.solHouAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  (data->localData[0]->realVars[30] /* HDirTil.incAng.incAng.sol_c variable */) = cos((data->localData[0]->realVars[32] /* HDirTil.incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 259
type: SIMPLE_ASSIGN
HDirTil.inc = acos((-3.491481338843133e-15) * (HDirTil.incAng.incAng.dec_c * HDirTil.incAng.incAng.sol_c * HDirTil.incAng.incAng.lat_c + HDirTil.incAng.incAng.dec_s * HDirTil.incAng.incAng.lat_s) + HDirTil.incAng.incAng.dec_c * HDirTil.incAng.incAng.sol_c * HDirTil.incAng.incAng.lat_s - HDirTil.incAng.incAng.dec_s * HDirTil.incAng.incAng.lat_c)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  modelica_real tmp4;
  tmp4 = (-3.491481338843133e-15) * ((((data->localData[0]->realVars[26] /* HDirTil.incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[30] /* HDirTil.incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[28] /* HDirTil.incAng.incAng.lat_c variable */)) + ((data->localData[0]->realVars[27] /* HDirTil.incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[29] /* HDirTil.incAng.incAng.lat_s variable */))) + (((data->localData[0]->realVars[26] /* HDirTil.incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[30] /* HDirTil.incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[29] /* HDirTil.incAng.incAng.lat_s variable */)) - (((data->localData[0]->realVars[27] /* HDirTil.incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[28] /* HDirTil.incAng.incAng.lat_c variable */)));
  if(!(tmp4 >= -1.0 && tmp4 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos((-3.491481338843133e-15) * (HDirTil.incAng.incAng.dec_c * HDirTil.incAng.incAng.sol_c * HDirTil.incAng.incAng.lat_c + HDirTil.incAng.incAng.dec_s * HDirTil.incAng.incAng.lat_s) + HDirTil.incAng.incAng.dec_c * HDirTil.incAng.incAng.sol_c * HDirTil.incAng.incAng.lat_s - HDirTil.incAng.incAng.dec_s * HDirTil.incAng.incAng.lat_c) outside the domain -1.0 <= %g <= 1.0", tmp4);
    }
  }
  (data->localData[0]->realVars[24] /* HDirTil.inc variable */) = acos(tmp4);
  TRACE_POP
}
/*
equation index: 260
type: SIMPLE_ASSIGN
winRad.tra.incAng2 = min(HDirTil.inc, 1.570796326794897)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  (data->localData[0]->realVars[144] /* winRad.tra.incAng2 variable */) = fmin((data->localData[0]->realVars[24] /* HDirTil.inc variable */),1.570796326794897);
  TRACE_POP
}
/*
equation index: 261
type: SIMPLE_ASSIGN
winRad.tra.x = 2.0 + 5.729577951308232 * abs(winRad.tra.incAng2)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
#line 77 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[145] /* winRad.tra.x variable */) = 2.0 + (5.729577951308232) * (fabs((data->localData[0]->realVars[144] /* winRad.tra.incAng2 variable */)));
#line 679 OMC_FILE
  TRACE_POP
}
/*
equation index: 262
type: SIMPLE_ASSIGN
$cse5 = Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.tra.coeTraWinExtIrr[1,1,1], winRad.tra.coeTraWinExtIrr[1,2,1], winRad.tra.coeTraWinExtIrr[1,3,1], winRad.tra.coeTraWinExtIrr[1,4,1], winRad.tra.coeTraWinExtIrr[1,5,1], winRad.tra.coeTraWinExtIrr[1,6,1], winRad.tra.coeTraWinExtIrr[1,7,1], winRad.tra.coeTraWinExtIrr[1,8,1], winRad.tra.coeTraWinExtIrr[1,9,1], winRad.tra.coeTraWinExtIrr[1,10,1], winRad.tra.coeTraWinExtIrr[1,11,1], winRad.tra.coeTraWinExtIrr[1,12,1], winRad.tra.coeTraWinExtIrr[1,13,1]}, winRad.tra.x)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,262};
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp5, 13, (modelica_real)(data->simulationInfo->realParameter[932] /* winRad.tra.coeTraWinExtIrr[1,1,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[933] /* winRad.tra.coeTraWinExtIrr[1,2,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[934] /* winRad.tra.coeTraWinExtIrr[1,3,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[935] /* winRad.tra.coeTraWinExtIrr[1,4,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[936] /* winRad.tra.coeTraWinExtIrr[1,5,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[937] /* winRad.tra.coeTraWinExtIrr[1,6,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[938] /* winRad.tra.coeTraWinExtIrr[1,7,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[939] /* winRad.tra.coeTraWinExtIrr[1,8,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[940] /* winRad.tra.coeTraWinExtIrr[1,9,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[941] /* winRad.tra.coeTraWinExtIrr[1,10,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[942] /* winRad.tra.coeTraWinExtIrr[1,11,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[943] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[944] /* winRad.tra.coeTraWinExtIrr[1,13,1] PARAM */));
  (data->localData[0]->realVars[14] /* $cse5 variable */) = omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp5, (data->localData[0]->realVars[145] /* winRad.tra.x variable */));
  TRACE_POP
}
/*
equation index: 263
type: SIMPLE_ASSIGN
$cse4 = Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.tra.coeTraWinExtIrr[2,1,1], winRad.tra.coeTraWinExtIrr[2,2,1], winRad.tra.coeTraWinExtIrr[2,3,1], winRad.tra.coeTraWinExtIrr[2,4,1], winRad.tra.coeTraWinExtIrr[2,5,1], winRad.tra.coeTraWinExtIrr[2,6,1], winRad.tra.coeTraWinExtIrr[2,7,1], winRad.tra.coeTraWinExtIrr[2,8,1], winRad.tra.coeTraWinExtIrr[2,9,1], winRad.tra.coeTraWinExtIrr[2,10,1], winRad.tra.coeTraWinExtIrr[2,11,1], winRad.tra.coeTraWinExtIrr[2,12,1], winRad.tra.coeTraWinExtIrr[2,13,1]}, winRad.tra.x)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,263};
  real_array tmp6;
  array_alloc_scalar_real_array(&tmp6, 13, (modelica_real)(data->simulationInfo->realParameter[945] /* winRad.tra.coeTraWinExtIrr[2,1,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[946] /* winRad.tra.coeTraWinExtIrr[2,2,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[947] /* winRad.tra.coeTraWinExtIrr[2,3,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[948] /* winRad.tra.coeTraWinExtIrr[2,4,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[949] /* winRad.tra.coeTraWinExtIrr[2,5,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[950] /* winRad.tra.coeTraWinExtIrr[2,6,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[951] /* winRad.tra.coeTraWinExtIrr[2,7,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[952] /* winRad.tra.coeTraWinExtIrr[2,8,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[953] /* winRad.tra.coeTraWinExtIrr[2,9,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[954] /* winRad.tra.coeTraWinExtIrr[2,10,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[955] /* winRad.tra.coeTraWinExtIrr[2,11,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[956] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[957] /* winRad.tra.coeTraWinExtIrr[2,13,1] PARAM */));
  (data->localData[0]->realVars[13] /* $cse4 variable */) = omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp6, (data->localData[0]->realVars[145] /* winRad.tra.x variable */));
  TRACE_POP
}
/*
equation index: 264
type: SIMPLE_ASSIGN
$cse2 = cos(HDirTil.inc)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,264};
  (data->localData[0]->realVars[10] /* $cse2 variable */) = cos((data->localData[0]->realVars[24] /* HDirTil.inc variable */));
  TRACE_POP
}
/*
equation index: 265
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.sol_s = sin(HDirTil.incAng.solHouAng.solHouAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,265};
  (data->localData[0]->realVars[31] /* HDirTil.incAng.incAng.sol_s variable */) = sin((data->localData[0]->realVars[32] /* HDirTil.incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 266
type: WHEN

when {$whenCondition2} then
  weaDat.conTim.tNext = if weaDat.conTim.canRepeatWeatherFile then weaDat.conTim.lenWea * (1.0 + (*Real*)(integer(weaBus.cloTim / weaDat.conTim.lenWea))) else time;
end when;
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_266(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,266};
  if(((data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */) /* edge */))
  {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    (data->localData[0]->realVars[147] /* weaDat.conTim.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[91] /* weaDat.conTim.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[58] /* weaBus.cloTim variable */),(data->simulationInfo->realParameter[91] /* weaDat.conTim.lenWea PARAM */),"weaDat.conTim.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 750 OMC_FILE
  }
  TRACE_POP
}
/*
equation index: 267
type: SIMPLE_ASSIGN
weaDat.conTim.calTim = if weaDat.conTim.canRepeatWeatherFile then weaBus.cloTim - weaDat.conTim.tNext + weaDat.conTim.lenWea else weaBus.cloTim
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
#line 38 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */)?(data->localData[0]->realVars[58] /* weaBus.cloTim variable */) - (data->localData[0]->realVars[147] /* weaDat.conTim.tNext DISCRETE */) + (data->simulationInfo->realParameter[91] /* weaDat.conTim.lenWea PARAM */):(data->localData[0]->realVars[58] /* weaBus.cloTim variable */));
#line 765 OMC_FILE
  TRACE_POP
}
/*
equation index: 268
type: SIMPLE_ASSIGN
weaDat.datRea.y[1] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 1, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
  (data->localData[0]->realVars[76] /* weaDat.datRea.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 1), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 269
type: SIMPLE_ASSIGN
weaDat.conTDryBul.y = 273.15 + weaDat.datRea.y[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
#line 37 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[72] /* weaDat.conTDryBul.y variable */) = 273.15 + (data->localData[0]->realVars[76] /* weaDat.datRea.y[1] variable */);
#line 791 OMC_FILE
  TRACE_POP
}
/*
equation index: 270
type: SIMPLE_ASSIGN
weaDat.datRea.y[2] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 2, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  (data->localData[0]->realVars[77] /* weaDat.datRea.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 2), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 271
type: SIMPLE_ASSIGN
weaDat.conTDewPoi.y = 273.15 + weaDat.datRea.y[2]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
#line 37 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[71] /* weaDat.conTDewPoi.y variable */) = 273.15 + (data->localData[0]->realVars[77] /* weaDat.datRea.y[2] variable */);
#line 817 OMC_FILE
  TRACE_POP
}
/*
equation index: 272
type: SIMPLE_ASSIGN
weaDat.datRea.y[3] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 3, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
  (data->localData[0]->realVars[78] /* weaDat.datRea.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 3), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 273
type: SIMPLE_ASSIGN
weaDat.datRea.y[4] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 4, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
  (data->localData[0]->realVars[79] /* weaDat.datRea.y[4] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 4), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 274
type: SIMPLE_ASSIGN
weaDat.datRea.y[5] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 5, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
  (data->localData[0]->realVars[80] /* weaDat.datRea.y[5] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 5), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 275
type: SIMPLE_ASSIGN
weaDat.datRea.y[6] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 6, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
  (data->localData[0]->realVars[81] /* weaDat.datRea.y[6] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 6), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 276
type: SIMPLE_ASSIGN
weaDat.datRea.y[7] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 7, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,276};
  (data->localData[0]->realVars[82] /* weaDat.datRea.y[7] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 7), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 277
type: SIMPLE_ASSIGN
weaDat.datRea.y[8] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 8, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,277};
  (data->localData[0]->realVars[83] /* weaDat.datRea.y[8] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 8), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 278
type: SIMPLE_ASSIGN
weaDat.datRea.y[9] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 9, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
  (data->localData[0]->realVars[84] /* weaDat.datRea.y[9] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 9), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 279
type: SIMPLE_ASSIGN
weaDat.datRea.y[10] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 10, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,279};
  (data->localData[0]->realVars[85] /* weaDat.datRea.y[10] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 10), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 280
type: SIMPLE_ASSIGN
weaDat.datRea.y[11] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 11, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  (data->localData[0]->realVars[86] /* weaDat.datRea.y[11] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 11), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 281
type: SIMPLE_ASSIGN
weaDat.conWinDir.y = 0.0174532925199433 * weaDat.datRea.y[11]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
#line 145 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[75] /* weaDat.conWinDir.y variable */) = (0.0174532925199433) * ((data->localData[0]->realVars[86] /* weaDat.datRea.y[11] variable */));
#line 939 OMC_FILE
  TRACE_POP
}
/*
equation index: 282
type: SIMPLE_ASSIGN
weaDat.datRea.y[12] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 12, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
  (data->localData[0]->realVars[87] /* weaDat.datRea.y[12] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 12), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 283
type: SIMPLE_ASSIGN
weaDat.datRea.y[13] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 13, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  (data->localData[0]->realVars[88] /* weaDat.datRea.y[13] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 13), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 284
type: SIMPLE_ASSIGN
weaDat.datRea.y[14] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 14, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  (data->localData[0]->realVars[89] /* weaDat.datRea.y[14] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 14), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 285
type: SIMPLE_ASSIGN
weaDat.datRea.y[15] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 15, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  (data->localData[0]->realVars[90] /* weaDat.datRea.y[15] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 15), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 286
type: SIMPLE_ASSIGN
weaDat.datRea.y[16] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 16, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  (data->localData[0]->realVars[91] /* weaDat.datRea.y[16] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 16), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 287
type: SIMPLE_ASSIGN
weaDat.datRea.y[17] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 17, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  (data->localData[0]->realVars[92] /* weaDat.datRea.y[17] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 17), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 288
type: SIMPLE_ASSIGN
weaDat.datRea.y[18] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 18, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  (data->localData[0]->realVars[93] /* weaDat.datRea.y[18] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 18), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 289
type: SIMPLE_ASSIGN
weaDat.datRea.y[19] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 19, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  (data->localData[0]->realVars[94] /* weaDat.datRea.y[19] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 19), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 290
type: SIMPLE_ASSIGN
weaDat.datRea.y[20] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 20, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  (data->localData[0]->realVars[95] /* weaDat.datRea.y[20] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 20), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 291
type: SIMPLE_ASSIGN
weaDat.datRea.y[21] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 21, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
  (data->localData[0]->realVars[96] /* weaDat.datRea.y[21] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 21), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 292
type: SIMPLE_ASSIGN
weaDat.datRea.y[22] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 22, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
  (data->localData[0]->realVars[97] /* weaDat.datRea.y[22] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 22), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 293
type: SIMPLE_ASSIGN
weaDat.datRea.y[23] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 23, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
  (data->localData[0]->realVars[98] /* weaDat.datRea.y[23] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 23), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 294
type: SIMPLE_ASSIGN
weaDat.datRea.y[24] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 24, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
  (data->localData[0]->realVars[99] /* weaDat.datRea.y[24] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 24), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 295
type: SIMPLE_ASSIGN
weaDat.datRea.y[25] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 25, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
  (data->localData[0]->realVars[100] /* weaDat.datRea.y[25] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 25), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 296
type: SIMPLE_ASSIGN
weaDat.datRea.y[26] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 26, weaDat.conTim.calTim)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
  (data->localData[0]->realVars[101] /* weaDat.datRea.y[26] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 26), (data->localData[0]->realVars[73] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 297
type: SIMPLE_ASSIGN
weaBus.HGloHor = max(0.0, HGloHor_in)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  (data->localData[0]->realVars[54] /* weaBus.HGloHor variable */) = fmax(0.0,(data->localData[0]->realVars[33] /* HGloHor_in variable */));
  TRACE_POP
}
/*
equation index: 298
type: SIMPLE_ASSIGN
HDifTilIso.add.u2 = 0.1000000000000004 * weaBus.HGloHor
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
#line 29 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffuseIsotropic.mo"
  (data->localData[0]->realVars[21] /* HDifTilIso.add.u2 variable */) = (0.1000000000000004) * ((data->localData[0]->realVars[54] /* weaBus.HGloHor variable */));
#line 1145 OMC_FILE
  TRACE_POP
}
/*
equation index: 299
type: SIMPLE_ASSIGN
HDifTilIso.H = HDifTilIso.add.u1 + HDifTilIso.add.u2
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[18] /* HDifTilIso.H variable */) = (data->localData[0]->realVars[20] /* HDifTilIso.add.u1 variable */) + (data->localData[0]->realVars[21] /* HDifTilIso.add.u2 variable */);
#line 1159 OMC_FILE
  TRACE_POP
}
/*
equation index: 300
type: SIMPLE_ASSIGN
winRad.tra.QTraDifUns_flow[1] = HDifTilIso.H * (1.0 - uSha) * winRad.tra.coeTraWinExtIrr[1,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
#line 82 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[141] /* winRad.tra.QTraDifUns_flow[1] variable */) = ((data->localData[0]->realVars[18] /* HDifTilIso.H variable */)) * ((1.0 - (data->localData[0]->realVars[50] /* uSha variable */)) * ((data->simulationInfo->realParameter[943] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */)));
#line 1173 OMC_FILE
  TRACE_POP
}
/*
equation index: 301
type: SIMPLE_ASSIGN
winRad.tra.QTraDifSha_flow[1] = HDifTilIso.H * uSha * winRad.tra.coeTraWinExtIrr[2,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
#line 90 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[140] /* winRad.tra.QTraDifSha_flow[1] variable */) = ((data->localData[0]->realVars[18] /* HDifTilIso.H variable */)) * (((data->localData[0]->realVars[50] /* uSha variable */)) * ((data->simulationInfo->realParameter[956] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */)));
#line 1187 OMC_FILE
  TRACE_POP
}
/*
equation index: 302
type: SIMPLE_ASSIGN
QTraDif_flow = winRad.tra.QTraDifUns_flow[1] + winRad.tra.QTraDifSha_flow[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
#line 97 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[41] /* QTraDif_flow variable */) = (data->localData[0]->realVars[141] /* winRad.tra.QTraDifUns_flow[1] variable */) + (data->localData[0]->realVars[140] /* winRad.tra.QTraDifSha_flow[1] variable */);
#line 1201 OMC_FILE
  TRACE_POP
}
/*
equation index: 303
type: SIMPLE_ASSIGN
weaBus.HDirNor = max(0.0, HDirNor_in)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  (data->localData[0]->realVars[53] /* weaBus.HDirNor variable */) = fmax(0.0,(data->localData[0]->realVars[22] /* HDirNor_in variable */));
  TRACE_POP
}
/*
equation index: 304
type: SIMPLE_ASSIGN
HDirTil.H = max(0.0, $cse2 * weaBus.HDirNor)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  (data->localData[0]->realVars[23] /* HDirTil.H variable */) = fmax(0.0,((data->localData[0]->realVars[10] /* $cse2 variable */)) * ((data->localData[0]->realVars[53] /* weaBus.HDirNor variable */)));
  TRACE_POP
}
/*
equation index: 305
type: SIMPLE_ASSIGN
winRad.tra.QTraDirSha_flow[1] = HDirTil.H * uSha * $cse4
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
#line 91 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[142] /* winRad.tra.QTraDirSha_flow[1] variable */) = ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[50] /* uSha variable */)) * ((data->localData[0]->realVars[13] /* $cse4 variable */)));
#line 1239 OMC_FILE
  TRACE_POP
}
/*
equation index: 306
type: SIMPLE_ASSIGN
winRad.tra.QTraDirUns_flow[1] = HDirTil.H * (1.0 - uSha) * $cse5
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
#line 83 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[143] /* winRad.tra.QTraDirUns_flow[1] variable */) = ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * ((1.0 - (data->localData[0]->realVars[50] /* uSha variable */)) * ((data->localData[0]->realVars[14] /* $cse5 variable */)));
#line 1253 OMC_FILE
  TRACE_POP
}
/*
equation index: 307
type: SIMPLE_ASSIGN
QTraDir_flow = winRad.tra.QTraDirUns_flow[1] + winRad.tra.QTraDirSha_flow[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,307};
#line 98 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[42] /* QTraDir_flow variable */) = (data->localData[0]->realVars[143] /* winRad.tra.QTraDirUns_flow[1] variable */) + (data->localData[0]->realVars[142] /* winRad.tra.QTraDirSha_flow[1] variable */);
#line 1267 OMC_FILE
  TRACE_POP
}
/*
equation index: 308
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
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,308};
  real_array tmp7;
  index_spec_t tmp8;
  real_array tmp9;
  real_array tmp10;
  index_spec_t tmp11;
  real_array tmp12;
  real_array tmp13;
  index_spec_t tmp14;
  real_array tmp15;
  real_array tmp16;
  index_spec_t tmp17;
  real_array tmp18;
  real_array tmp19;
  index_spec_t tmp20;
  real_array tmp21;
  real_array tmp22;
  index_spec_t tmp23;
  real_array tmp24;
  modelica_integer tmp25;
  modelica_integer tmp26;
  modelica_integer tmp27;
  modelica_integer tmp28;
  modelica_integer tmp29;
  modelica_integer tmp30;
  real_array tmp31;
  real_array tmp32;
  modelica_integer tmp33;
  modelica_integer tmp34;
  modelica_integer tmp35;
  modelica_integer tmp36;
  modelica_integer tmp37;
  modelica_integer tmp38;
  real_array tmp39;
  modelica_integer tmp40;
  modelica_integer tmp41;
  modelica_integer tmp42;
  real_array tmp43;
  real_array tmp44;
  index_spec_t tmp45;
  index_spec_t tmp46;
  real_array tmp47;
  real_array tmp48;
  real_array tmp49;
  index_spec_t tmp50;
  index_spec_t tmp51;
  real_array tmp52;
  real_array tmp53;
  real_array tmp54;
  integer_array tmp55;
  modelica_integer tmp56;
  index_spec_t tmp57;
  index_spec_t tmp58;
  real_array tmp59;
  real_array tmp60;
  real_array tmp61;
  integer_array tmp62;
  modelica_integer tmp63;
  index_spec_t tmp64;
  index_spec_t tmp65;
  real_array tmp66;
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
  array_alloc_scalar_real_array(&tmp7, 1, (modelica_real)0.0);
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp8, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp9, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp7, &tmp9, &tmp8);
#line 1421 OMC_FILE

#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp10, 1, (modelica_real)0.0);
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp11, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp12, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp10, &tmp12, &tmp11);
#line 1431 OMC_FILE

#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp13, 1, (modelica_real)0.0);
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp14, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp15, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp13, &tmp15, &tmp14);
#line 1441 OMC_FILE

#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp16, 1, (modelica_real)0.0);
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp17, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp18, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp16, &tmp18, &tmp17);
#line 1451 OMC_FILE

#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp25 = ((modelica_integer) 1); tmp26 = 1; tmp27 = ((modelica_integer) 2);
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp26 > 0) && (tmp25 > tmp27)) || ((tmp26 < 0) && (tmp25 < tmp27))))
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer i;
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(i = ((modelica_integer) 1); in_range_integer(i, tmp25, tmp27); i += tmp26)
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp19, 1, (modelica_real)(1.0 - (data->localData[0]->realVars[50] /* uSha variable */)) * (((data->localData[0]->realVars[18] /* HDifTilIso.H variable */)) * ((&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (((modelica_integer) 1)-1)])));
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      create_index_spec(&tmp20, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) i + ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      real_array_create(&tmp21, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      indexed_assign_real_array(tmp19, &tmp21, &tmp20);
#line 1473 OMC_FILE

#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp22, 1, (modelica_real)((data->localData[0]->realVars[50] /* uSha variable */)) * (((data->localData[0]->realVars[18] /* HDifTilIso.H variable */)) * ((&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (((modelica_integer) 1)-1)])));
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      create_index_spec(&tmp23, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) i + ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      real_array_create(&tmp24, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      indexed_assign_real_array(tmp22, &tmp24, &tmp23);
#line 1483 OMC_FILE
    }
  }

#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp28 = ((modelica_integer) 1); tmp29 = 1; tmp30 = ((modelica_integer) 1);
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp29 > 0) && (tmp28 > tmp30)) || ((tmp29 < 0) && (tmp28 < tmp30))))
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer iSta;
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp28, tmp30); iSta += tmp29)
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 151 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      (&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] = (0.3052322754811356) * (((data->localData[0]->realVars[50] /* uSha variable */)) * ((data->localData[0]->realVars[18] /* HDifTilIso.H variable */)));
#line 1501 OMC_FILE
    }
  }

#line 160 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->localData[0]->realVars[130] /* winRad.abs.incAng2 variable */) = fmin((data->localData[0]->realVars[24] /* HDirTil.inc variable */),1.570796326794897);
#line 1507 OMC_FILE

#line 162 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->localData[0]->realVars[131] /* winRad.abs.x variable */) = (5.729577951308232) * (fabs((data->localData[0]->realVars[130] /* winRad.abs.incAng2 variable */))) + 2.0;
#line 1511 OMC_FILE

#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp36 = ((modelica_integer) 1); tmp37 = 1; tmp38 = ((modelica_integer) 2);
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp37 > 0) && (tmp36 > tmp38)) || ((tmp37 < 0) && (tmp36 < tmp38))))
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer i;
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(i = ((modelica_integer) 1); in_range_integer(i, tmp36, tmp38); i += tmp37)
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      tmp33 = ((modelica_integer) 1); tmp34 = 1; tmp35 = ((modelica_integer) 1);
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      if(!(((tmp34 > 0) && (tmp33 > tmp35)) || ((tmp34 < 0) && (tmp33 < tmp35))))
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      {
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        modelica_integer iSta;
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp33, tmp35); iSta += tmp34)
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        {
#line 168 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          array_alloc_scalar_real_array(&tmp31, 13, (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 1)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 2)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 3)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 5)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 6)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 7)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 8)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 9)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 10)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 11)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 13)-1)) * 1 + (iSta-1)]);
#line 168 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          (&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 1) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 1) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * ((1.0 - (data->localData[0]->realVars[50] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp31, (data->localData[0]->realVars[131] /* winRad.abs.x variable */))));
#line 1541 OMC_FILE

#line 174 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          array_alloc_scalar_real_array(&tmp32, 13, (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 1)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 2)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 3)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 5)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 6)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 7)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 8)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 9)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 10)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 11)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 13)-1)) * 1 + (iSta-1)]);
#line 174 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          (&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 2) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[50] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp32, (data->localData[0]->realVars[131] /* winRad.abs.x variable */))));
#line 1547 OMC_FILE
        }
      }
    }
  }

#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp40 = ((modelica_integer) 1); tmp41 = 1; tmp42 = ((modelica_integer) 1);
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp41 > 0) && (tmp40 > tmp42)) || ((tmp41 < 0) && (tmp40 < tmp42))))
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer iSta;
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp40, tmp42); iSta += tmp41)
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 184 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp39, 13, (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 2) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 3) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 4) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 5) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 6) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 7) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 8) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 9) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 10) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 11) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 12) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 13) - 1) * 1 + (iSta-1)]);
#line 184 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      (&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[50] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp39, (data->localData[0]->realVars[131] /* winRad.abs.x variable */))));
#line 1569 OMC_FILE
    }
  }

#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp43, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp45, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp43, &tmp45, &tmp44);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp46, 1, (modelica_integer)(1), (int*)0, 'W');
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp47, (modelica_real*)&(data->localData[0]->realVars[116] /* winRad.abs.QAbsExtSha_flow[1] variable */), 1, (_index_t)1);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp44, &tmp47, &tmp46);
#line 1585 OMC_FILE

#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp48, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp50, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp48, &tmp50, &tmp49);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp51, 1, (modelica_integer)(1), (int*)0, 'W');
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp52, (modelica_real*)&(data->localData[0]->realVars[121] /* winRad.abs.QAbsIntSha_flow[1] variable */), 1, (_index_t)1);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp49, &tmp52, &tmp51);
#line 1599 OMC_FILE

#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp53, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_integer_array_from_range(&tmp55, ((modelica_integer) 2), 1, ((modelica_integer) 3));
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp56 = size_of_dimension_base_array(tmp55, 1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp57, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', tmp56, integer_array_make_index_array(tmp55), 'A', (modelica_integer)(1), (int*)0, 'W');
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp53, &tmp57, &tmp54);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp58, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W');
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp59, (modelica_real*)&(data->localData[0]->realVars[119] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */), 2, (_index_t)2, (_index_t)1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp54, &tmp59, &tmp58);
#line 1617 OMC_FILE

#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp60, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_integer_array_from_range(&tmp62, ((modelica_integer) 2), 1, ((modelica_integer) 3));
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp63 = size_of_dimension_base_array(tmp62, 1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp64, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', tmp63, integer_array_make_index_array(tmp62), 'A', (modelica_integer)(1), (int*)0, 'W');
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp60, &tmp64, &tmp61);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp65, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W');
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp66, (modelica_real*)&(data->localData[0]->realVars[117] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */), 2, (_index_t)2, (_index_t)1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp61, &tmp66, &tmp65);
#line 1635 OMC_FILE
  TRACE_POP
}
/*
equation index: 309
type: SIMPLE_ASSIGN
QAbsIntSha_flow = winRad.abs.QAbsIntSha_flow[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
#line 163 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/WindowRadiation.mo"
  (data->localData[0]->realVars[40] /* QAbsIntSha_flow variable */) = (data->localData[0]->realVars[121] /* winRad.abs.QAbsIntSha_flow[1] variable */);
#line 1649 OMC_FILE
  TRACE_POP
}
/*
equation index: 310
type: SIMPLE_ASSIGN
QAbsGlaSha_flow = winRad.abs.QAbsGlaSha_flow[1,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
#line 159 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/WindowRadiation.mo"
  (data->localData[0]->realVars[38] /* QAbsGlaSha_flow variable */) = (data->localData[0]->realVars[117] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */);
#line 1663 OMC_FILE
  TRACE_POP
}
/*
equation index: 311
type: SIMPLE_ASSIGN
QAbsGlaUns_flow = winRad.abs.QAbsGlaUns_flow[1,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
#line 155 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/WindowRadiation.mo"
  (data->localData[0]->realVars[39] /* QAbsGlaUns_flow variable */) = (data->localData[0]->realVars[119] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */);
#line 1677 OMC_FILE
  TRACE_POP
}
/*
equation index: 312
type: SIMPLE_ASSIGN
QAbsExtSha_flow = winRad.abs.QAbsExtSha_flow[1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,312};
#line 150 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/WindowRadiation.mo"
  (data->localData[0]->realVars[37] /* QAbsExtSha_flow variable */) = (data->localData[0]->realVars[116] /* winRad.abs.QAbsExtSha_flow[1] variable */);
#line 1691 OMC_FILE
  TRACE_POP
}
/*
equation index: 313
type: SIMPLE_ASSIGN
weaBus.HHorIR = max(0.0, HInfHor_in)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,313};
  (data->localData[0]->realVars[55] /* weaBus.HHorIR variable */) = fmax(0.0,(data->localData[0]->realVars[34] /* HInfHor_in variable */));
  TRACE_POP
}
/*
equation index: 314
type: SIMPLE_ASSIGN
weaBus.winSpe = max(0.0, winSpe_in)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
  (data->localData[0]->realVars[68] /* weaBus.winSpe variable */) = fmax(0.0,(data->localData[0]->realVars[146] /* winSpe_in variable */));
  TRACE_POP
}
/*
equation index: 315
type: SIMPLE_ASSIGN
weaBus.ceiHei = max(0.0, ceiHei_in)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,315};
  (data->localData[0]->realVars[57] /* weaBus.ceiHei variable */) = fmax(0.0,(data->localData[0]->realVars[46] /* ceiHei_in variable */));
  TRACE_POP
}
/*
equation index: 316
type: SIMPLE_ASSIGN
$cse15 = exp(4102.99 / (TDryBul_in - 35.719) - 17.2799)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  (data->localData[0]->realVars[5] /* $cse15 variable */) = exp(DIVISION_SIM(4102.99,(data->localData[0]->realVars[45] /* TDryBul_in variable */) - 35.719,"TDryBul_in - 35.719",equationIndexes) - 17.2799);
  TRACE_POP
}
/*
equation index: 317
type: SIMPLE_ASSIGN
$cse17 = max(0.0, relHum_in)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
  (data->localData[0]->realVars[7] /* $cse17 variable */) = fmax(0.0,(data->localData[0]->realVars[48] /* relHum_in variable */));
  TRACE_POP
}
/*
equation index: 318
type: SIMPLE_ASSIGN
weaBus.relHum = min(1.0, $cse17)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  (data->localData[0]->realVars[61] /* weaBus.relHum variable */) = fmin(1.0,(data->localData[0]->realVars[7] /* $cse17 variable */));
  TRACE_POP
}
/*
equation index: 319
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiDryBul = 0.621964713077499 * weaBus.relHum / ((-0.378035286922501) * weaBus.relHum + 165.6565689594004 * $cse15)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,319};
#line 63 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  (data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */) = (0.621964713077499) * (DIVISION_SIM((data->localData[0]->realVars[61] /* weaBus.relHum variable */),(-0.378035286922501) * ((data->localData[0]->realVars[61] /* weaBus.relHum variable */)) + (165.6565689594004) * ((data->localData[0]->realVars[5] /* $cse15 variable */)),"(-0.378035286922501) * weaBus.relHum + 165.6565689594004 * $cse15",equationIndexes));
#line 1777 OMC_FILE
  TRACE_POP
}
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_320(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_321(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_322(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_323(DATA*, threadData_t*);
/*
equation index: 329
indexNonlinear: 1
type: NONLINEAR

vars: {weaBus.TWetBul}
eqns: {320, 321, 322, 323}
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,329};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 329 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = (data->localData[0]->realVars[56] /* weaBus.TWetBul variable */);
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,329};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 329 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[56] /* weaBus.TWetBul variable */) = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  TRACE_POP
}
/*
equation index: 330
type: SIMPLE_ASSIGN
$cse18 = max(0.0, winDir_in)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,330};
  (data->localData[0]->realVars[8] /* $cse18 variable */) = fmax(0.0,(data->localData[0]->realVars[115] /* winDir_in variable */));
  TRACE_POP
}
/*
equation index: 331
type: SIMPLE_ASSIGN
weaBus.winDir = min(6.283185307179586, $cse18)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,331};
  (data->localData[0]->realVars[67] /* weaBus.winDir variable */) = fmin(6.283185307179586,(data->localData[0]->realVars[8] /* $cse18 variable */));
  TRACE_POP
}
/*
equation index: 332
type: SIMPLE_ASSIGN
$cse19 = max(0.0, opaSkyCov_in)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,332};
  (data->localData[0]->realVars[9] /* $cse19 variable */) = fmax(0.0,(data->localData[0]->realVars[47] /* opaSkyCov_in variable */));
  TRACE_POP
}
/*
equation index: 333
type: SIMPLE_ASSIGN
weaBus.nOpa = min(1.0, $cse19)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_333(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,333};
  (data->localData[0]->realVars[59] /* weaBus.nOpa variable */) = fmin(1.0,(data->localData[0]->realVars[9] /* $cse19 variable */));
  TRACE_POP
}
/*
equation index: 334
type: SIMPLE_ASSIGN
$cse20 = max(0.0, totSkyCov_in)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  (data->localData[0]->realVars[11] /* $cse20 variable */) = fmax(0.0,(data->localData[0]->realVars[49] /* totSkyCov_in variable */));
  TRACE_POP
}
/*
equation index: 335
type: SIMPLE_ASSIGN
weaBus.nTot = min(1.0, $cse20)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  (data->localData[0]->realVars[60] /* weaBus.nTot variable */) = fmin(1.0,(data->localData[0]->realVars[11] /* $cse20 variable */));
  TRACE_POP
}
/*
equation index: 342
type: ALGORITHM

  assert(noEvent(TBlaSky_in > 0.0) and noEvent(TBlaSky_in < 343.15), "In WinRadCustom.weaDat.cheTemBlaSky: Weather data black-body sky temperature out of bounds.
   TIn = " + String(TBlaSky_in, 6, 0, true));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_342(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,342};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,101,"In WinRadCustom.weaDat.cheTemBlaSky: Weather data black-body sky temperature out of bounds.\n   TIn = ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp0 = Greater((data->localData[0]->realVars[43] /* TBlaSky_in variable */),0.0);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp1 = Less((data->localData[0]->realVars[43] /* TBlaSky_in variable */),343.15);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    if(!(tmp0 && tmp1))
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp3 = modelica_real_to_modelica_string((data->localData[0]->realVars[43] /* TBlaSky_in variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        const char* assert_cond = "(noEvent(TBlaSky_in > 0.0) and noEvent(TBlaSky_in < 343.15))";
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",25,3,27,18,0};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        } else {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",25,3,27,18,0};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  }
#line 1943 OMC_FILE
  TRACE_POP
}
/*
equation index: 341
type: ALGORITHM

  assert(noEvent(TDewPoi_in > 203.15) and noEvent(TDewPoi_in < 343.15), "In WinRadCustom.weaDat.cheTemDewPoi: Weather data dew point temperature out of bounds.
   TIn = " + String(TDewPoi_in, 6, 0, true));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_341(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,341};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  static const MMC_DEFSTRINGLIT(tmp8,96,"In WinRadCustom.weaDat.cheTemDewPoi: Weather data dew point temperature out of bounds.\n   TIn = ");
  modelica_string tmp9;
  modelica_metatype tmpMeta10;
  static int tmp11 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp6 = Greater((data->localData[0]->realVars[44] /* TDewPoi_in variable */),203.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp7 = Less((data->localData[0]->realVars[44] /* TDewPoi_in variable */),343.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    if(!(tmp6 && tmp7))
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp9 = modelica_real_to_modelica_string((data->localData[0]->realVars[44] /* TDewPoi_in variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmpMeta10 = stringAppend(MMC_REFSTRINGLIT(tmp8),tmp9);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        const char* assert_cond = "(noEvent(TDewPoi_in > 203.15) and noEvent(TDewPoi_in < 343.15))";
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  }
#line 2003 OMC_FILE
  TRACE_POP
}
/*
equation index: 340
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim), "In WinRadCustom.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTim.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_340(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,340};
  modelica_boolean tmp12;
  static const MMC_DEFSTRINGLIT(tmp13,125,"In WinRadCustom.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp14;
  modelica_metatype tmpMeta15;
  static const MMC_DEFSTRINGLIT(tmp16,29," is less than the start time ");
  modelica_metatype tmpMeta17;
  modelica_string tmp18;
  modelica_metatype tmpMeta19;
  static const MMC_DEFSTRINGLIT(tmp20,26," of the weather data file.");
  modelica_metatype tmpMeta21;
  static int tmp22 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp12 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[93] /* weaDat.conTim.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp12))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp14 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta15 = stringAppend(MMC_REFSTRINGLIT(tmp13),tmp14);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta17 = stringAppend(tmpMeta15,MMC_REFSTRINGLIT(tmp16));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp18 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[93] /* weaDat.conTim.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta19 = stringAppend(tmpMeta17,tmp18);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta21 = stringAppend(tmpMeta19,MMC_REFSTRINGLIT(tmp20));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta21));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta21));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2074 OMC_FILE
  TRACE_POP
}
/*
equation index: 339
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0), "In WinRadCustom.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTim.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_339(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,339};
  modelica_boolean tmp23;
  static const MMC_DEFSTRINGLIT(tmp24,125,"In WinRadCustom.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp25;
  modelica_metatype tmpMeta26;
  static const MMC_DEFSTRINGLIT(tmp27,22," exceeds the end time ");
  modelica_metatype tmpMeta28;
  modelica_string tmp29;
  modelica_metatype tmpMeta30;
  static const MMC_DEFSTRINGLIT(tmp31,26," of the weather data file.");
  modelica_metatype tmpMeta32;
  static int tmp33 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp23 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[92] /* weaDat.conTim.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp23))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp25 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta26 = stringAppend(MMC_REFSTRINGLIT(tmp24),tmp25);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta28 = stringAppend(tmpMeta26,MMC_REFSTRINGLIT(tmp27));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp29 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[92] /* weaDat.conTim.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta30 = stringAppend(tmpMeta28,tmp29);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta32 = stringAppend(tmpMeta30,MMC_REFSTRINGLIT(tmp31));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta32));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta32));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2145 OMC_FILE
  TRACE_POP
}
/*
equation index: 338
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim), "In WinRadCustom.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTimMin.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,338};
  modelica_boolean tmp34;
  static const MMC_DEFSTRINGLIT(tmp35,128,"In WinRadCustom.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp36;
  modelica_metatype tmpMeta37;
  static const MMC_DEFSTRINGLIT(tmp38,29," is less than the start time ");
  modelica_metatype tmpMeta39;
  modelica_string tmp40;
  modelica_metatype tmpMeta41;
  static const MMC_DEFSTRINGLIT(tmp42,26," of the weather data file.");
  modelica_metatype tmpMeta43;
  static int tmp44 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp34 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[96] /* weaDat.conTimMin.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp34))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp36 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta37 = stringAppend(MMC_REFSTRINGLIT(tmp35),tmp36);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta39 = stringAppend(tmpMeta37,MMC_REFSTRINGLIT(tmp38));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp40 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[96] /* weaDat.conTimMin.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta41 = stringAppend(tmpMeta39,tmp40);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta43 = stringAppend(tmpMeta41,MMC_REFSTRINGLIT(tmp42));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta43));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta43));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2216 OMC_FILE
  TRACE_POP
}
/*
equation index: 337
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0), "In WinRadCustom.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTimMin.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,337};
  modelica_boolean tmp45;
  static const MMC_DEFSTRINGLIT(tmp46,128,"In WinRadCustom.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp47;
  modelica_metatype tmpMeta48;
  static const MMC_DEFSTRINGLIT(tmp49,22," exceeds the end time ");
  modelica_metatype tmpMeta50;
  modelica_string tmp51;
  modelica_metatype tmpMeta52;
  static const MMC_DEFSTRINGLIT(tmp53,26," of the weather data file.");
  modelica_metatype tmpMeta54;
  static int tmp55 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp45 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[95] /* weaDat.conTimMin.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp45))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp47 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta48 = stringAppend(MMC_REFSTRINGLIT(tmp46),tmp47);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta50 = stringAppend(tmpMeta48,MMC_REFSTRINGLIT(tmp49));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp51 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[95] /* weaDat.conTimMin.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta52 = stringAppend(tmpMeta50,tmp51);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta54 = stringAppend(tmpMeta52,MMC_REFSTRINGLIT(tmp53));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta54));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta54));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2287 OMC_FILE
  TRACE_POP
}
/*
equation index: 336
type: ALGORITHM

  assert(noEvent(TDryBul_in > 203.15) and noEvent(TDryBul_in < 343.15), "In WinRadCustom.weaDat.cheTemDryBul: Weather data dry bulb temperature out of bounds.
   TIn = " + String(TDryBul_in, 6, 0, true));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  modelica_boolean tmp56;
  modelica_boolean tmp57;
  static const MMC_DEFSTRINGLIT(tmp58,95,"In WinRadCustom.weaDat.cheTemDryBul: Weather data dry bulb temperature out of bounds.\n   TIn = ");
  modelica_string tmp59;
  modelica_metatype tmpMeta60;
  static int tmp61 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp56 = Greater((data->localData[0]->realVars[45] /* TDryBul_in variable */),203.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp57 = Less((data->localData[0]->realVars[45] /* TDryBul_in variable */),343.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    if(!(tmp56 && tmp57))
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp59 = modelica_real_to_modelica_string((data->localData[0]->realVars[45] /* TDryBul_in variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmpMeta60 = stringAppend(MMC_REFSTRINGLIT(tmp58),tmp59);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        const char* assert_cond = "(noEvent(TDryBul_in > 203.15) and noEvent(TDryBul_in < 343.15))";
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta60));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta60));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  }
#line 2347 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionLocalKnownVars(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_227(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_228(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_229(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_230(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_231(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_232(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_233(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_234(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_235(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_236(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_237(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_238(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_239(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_240(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_241(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_242(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_243(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_244(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_245(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_246(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_247(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_248(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_249(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_250(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_251(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_252(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_253(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_254(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_255(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_256(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_257(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_258(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_259(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_260(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_261(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_262(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_263(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_264(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_265(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_266(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_267(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_268(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_269(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_270(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_271(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_272(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_273(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_274(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_275(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_276(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_277(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_278(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_279(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_280(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_281(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_282(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_283(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_284(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_285(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_286(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_287(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_288(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_289(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_290(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_291(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_292(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_293(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_294(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_295(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_296(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_297(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_298(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_299(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_300(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_301(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_302(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_303(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_304(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_305(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_306(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_307(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_308(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_309(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_310(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_311(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_312(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_313(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_314(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_315(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_316(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_317(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_318(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_319(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_329(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_330(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_331(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_332(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_333(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_334(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_335(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_342(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_341(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_340(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_339(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_338(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_337(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_336(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_12jac.h"
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Buildings_HeatTransfer_Windows_Examples_WinRadCustom_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialNonLinearSystem,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initializeDAEmodeData,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionODE,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionAlgebraics,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionDAE,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionLocalKnownVars,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_input_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_input_function_init,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_input_function_updateStartValues,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_data_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_output_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_setc_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_setb_function,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_storeDelayed,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_storeSpatialDistribution,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_initSpatialDistribution,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_updateBoundVariableAttributes,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionRemovedInitialEquations,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_updateBoundParameters,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_checkForAsserts,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_ZeroCrossingsEquations,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_ZeroCrossings,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_updateRelations,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_zeroCrossingDescription,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_relationDescription,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_initSample,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_A,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_B,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_C,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_D,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_F,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_H,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianA,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianB,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianC,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianD,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianF,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianH,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacA_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacB_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacC_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacD_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacF_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacH_column,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_linear_model_frame,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_linear_model_datarecovery_frame,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_mayer,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_lagrange,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_pickUpBoundsForInputsInOptimization,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_setInputData,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_getTimeGrid,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_symbolicInlineSystem,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_initSynchronous,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_updateSynchronous,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_equationsSynchronous,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_inputNames,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_dataReconciliationInputNames,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_dataReconciliationUnmeasuredVariables,
   Buildings_HeatTransfer_Windows_Examples_WinRadCustom_read_input_fmu,
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
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Buildings_HeatTransfer_Windows_Examples_WinRadCustom_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Buildings.HeatTransfer.Windows.Examples.WinRadCustom";
  data->modelData->modelFilePrefix = "Buildings_HeatTransfer_Windows_Examples_WinRadCustom";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Examples";
  data->modelData->modelGUID = "{fdaf0b3a-fb10-49db-bd9b-f90b44adf92a}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 149;
  data->modelData->nDiscreteReal = 2;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 2;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 1315;
  data->modelData->nParametersInteger = 90;
  data->modelData->nParametersBoolean = 27;
  data->modelData->nParametersString = 5;
  data->modelData->nInputVars = 16;
  data->modelData->nOutputVars = 6;
  
  data->modelData->nAliasReal = 242;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 2;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 2;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 2;
  
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/Buildings_HeatTransfer_Windows_Examples_WinRadCustom_info.json", data->modelData->resourcesDir);
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 24;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 1756;
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

