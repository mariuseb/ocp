#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/Desktop/XML_dump/Buildings.HeatTransfer.Windows.BaseClasses.Examples.DataTest/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest.fmutmp/sources/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest.c"
#endif
/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[0] /* recordTest[1,1,1] variable */);
  data->simulationInfo->outputVars[1] = (data->localData[0]->realVars[1] /* recordTest[1,2,1] variable */);
  data->simulationInfo->outputVars[2] = (data->localData[0]->realVars[2] /* recordTest[1,3,1] variable */);
  data->simulationInfo->outputVars[3] = (data->localData[0]->realVars[3] /* recordTest[1,4,1] variable */);
  data->simulationInfo->outputVars[4] = (data->localData[0]->realVars[4] /* recordTest[1,5,1] variable */);
  data->simulationInfo->outputVars[5] = (data->localData[0]->realVars[5] /* recordTest[1,6,1] variable */);
  data->simulationInfo->outputVars[6] = (data->localData[0]->realVars[6] /* recordTest[1,7,1] variable */);
  data->simulationInfo->outputVars[7] = (data->localData[0]->realVars[7] /* recordTest[1,8,1] variable */);
  data->simulationInfo->outputVars[8] = (data->localData[0]->realVars[8] /* recordTest[1,9,1] variable */);
  data->simulationInfo->outputVars[9] = (data->localData[0]->realVars[9] /* recordTest[1,10,1] variable */);
  data->simulationInfo->outputVars[10] = (data->localData[0]->realVars[10] /* recordTest[1,11,1] variable */);
  data->simulationInfo->outputVars[11] = (data->localData[0]->realVars[11] /* y[1,1,1] variable */);
  data->simulationInfo->outputVars[12] = (data->localData[0]->realVars[12] /* y[1,2,1] variable */);
  data->simulationInfo->outputVars[13] = (data->localData[0]->realVars[13] /* y[1,3,1] variable */);
  data->simulationInfo->outputVars[14] = (data->localData[0]->realVars[14] /* y[1,4,1] variable */);
  data->simulationInfo->outputVars[15] = (data->localData[0]->realVars[15] /* y[1,5,1] variable */);
  data->simulationInfo->outputVars[16] = (data->localData[0]->realVars[16] /* y[1,6,1] variable */);
  data->simulationInfo->outputVars[17] = (data->localData[0]->realVars[17] /* y[1,7,1] variable */);
  data->simulationInfo->outputVars[18] = (data->localData[0]->realVars[18] /* y[1,8,1] variable */);
  data->simulationInfo->outputVars[19] = (data->localData[0]->realVars[19] /* y[1,9,1] variable */);
  data->simulationInfo->outputVars[20] = (data->localData[0]->realVars[20] /* y[1,10,1] variable */);
  data->simulationInfo->outputVars[21] = (data->localData[0]->realVars[21] /* y[1,11,1] variable */);
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 23
type: SIMPLE_ASSIGN
recordTest[1,1,1] = radDat.absExtIrrExtSha[1,1,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[0] /* recordTest[1,1,1] variable */) = (data->simulationInfo->realParameter[51] /* radDat.absExtIrrExtSha[1,1,1] PARAM */);
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
y[1,1,1] = radDat.absExtIrrExtSha[1,1,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[11] /* y[1,1,1] variable */) = (data->simulationInfo->realParameter[51] /* radDat.absExtIrrExtSha[1,1,1] PARAM */);
  TRACE_POP
}
/*
equation index: 25
type: SIMPLE_ASSIGN
recordTest[1,2,1] = radDat.absExtIrrExtSha[1,2,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[1] /* recordTest[1,2,1] variable */) = (data->simulationInfo->realParameter[52] /* radDat.absExtIrrExtSha[1,2,1] PARAM */);
  TRACE_POP
}
/*
equation index: 26
type: SIMPLE_ASSIGN
y[1,2,1] = radDat.absExtIrrExtSha[1,2,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[12] /* y[1,2,1] variable */) = (data->simulationInfo->realParameter[52] /* radDat.absExtIrrExtSha[1,2,1] PARAM */);
  TRACE_POP
}
/*
equation index: 27
type: SIMPLE_ASSIGN
recordTest[1,3,1] = radDat.absExtIrrExtSha[1,3,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->localData[0]->realVars[2] /* recordTest[1,3,1] variable */) = (data->simulationInfo->realParameter[53] /* radDat.absExtIrrExtSha[1,3,1] PARAM */);
  TRACE_POP
}
/*
equation index: 28
type: SIMPLE_ASSIGN
y[1,3,1] = radDat.absExtIrrExtSha[1,3,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->localData[0]->realVars[13] /* y[1,3,1] variable */) = (data->simulationInfo->realParameter[53] /* radDat.absExtIrrExtSha[1,3,1] PARAM */);
  TRACE_POP
}
/*
equation index: 29
type: SIMPLE_ASSIGN
recordTest[1,4,1] = radDat.absExtIrrExtSha[1,4,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->localData[0]->realVars[3] /* recordTest[1,4,1] variable */) = (data->simulationInfo->realParameter[54] /* radDat.absExtIrrExtSha[1,4,1] PARAM */);
  TRACE_POP
}
/*
equation index: 30
type: SIMPLE_ASSIGN
y[1,4,1] = radDat.absExtIrrExtSha[1,4,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->localData[0]->realVars[14] /* y[1,4,1] variable */) = (data->simulationInfo->realParameter[54] /* radDat.absExtIrrExtSha[1,4,1] PARAM */);
  TRACE_POP
}
/*
equation index: 31
type: SIMPLE_ASSIGN
recordTest[1,5,1] = radDat.absExtIrrExtSha[1,5,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  (data->localData[0]->realVars[4] /* recordTest[1,5,1] variable */) = (data->simulationInfo->realParameter[55] /* radDat.absExtIrrExtSha[1,5,1] PARAM */);
  TRACE_POP
}
/*
equation index: 32
type: SIMPLE_ASSIGN
y[1,5,1] = radDat.absExtIrrExtSha[1,5,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  (data->localData[0]->realVars[15] /* y[1,5,1] variable */) = (data->simulationInfo->realParameter[55] /* radDat.absExtIrrExtSha[1,5,1] PARAM */);
  TRACE_POP
}
/*
equation index: 33
type: SIMPLE_ASSIGN
recordTest[1,6,1] = radDat.absExtIrrExtSha[1,6,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  (data->localData[0]->realVars[5] /* recordTest[1,6,1] variable */) = (data->simulationInfo->realParameter[56] /* radDat.absExtIrrExtSha[1,6,1] PARAM */);
  TRACE_POP
}
/*
equation index: 34
type: SIMPLE_ASSIGN
y[1,6,1] = radDat.absExtIrrExtSha[1,6,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  (data->localData[0]->realVars[16] /* y[1,6,1] variable */) = (data->simulationInfo->realParameter[56] /* radDat.absExtIrrExtSha[1,6,1] PARAM */);
  TRACE_POP
}
/*
equation index: 35
type: SIMPLE_ASSIGN
recordTest[1,7,1] = radDat.absExtIrrExtSha[1,7,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  (data->localData[0]->realVars[6] /* recordTest[1,7,1] variable */) = (data->simulationInfo->realParameter[57] /* radDat.absExtIrrExtSha[1,7,1] PARAM */);
  TRACE_POP
}
/*
equation index: 36
type: SIMPLE_ASSIGN
y[1,7,1] = radDat.absExtIrrExtSha[1,7,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  (data->localData[0]->realVars[17] /* y[1,7,1] variable */) = (data->simulationInfo->realParameter[57] /* radDat.absExtIrrExtSha[1,7,1] PARAM */);
  TRACE_POP
}
/*
equation index: 37
type: SIMPLE_ASSIGN
recordTest[1,8,1] = radDat.absExtIrrExtSha[1,8,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  (data->localData[0]->realVars[7] /* recordTest[1,8,1] variable */) = (data->simulationInfo->realParameter[58] /* radDat.absExtIrrExtSha[1,8,1] PARAM */);
  TRACE_POP
}
/*
equation index: 38
type: SIMPLE_ASSIGN
y[1,8,1] = radDat.absExtIrrExtSha[1,8,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  (data->localData[0]->realVars[18] /* y[1,8,1] variable */) = (data->simulationInfo->realParameter[58] /* radDat.absExtIrrExtSha[1,8,1] PARAM */);
  TRACE_POP
}
/*
equation index: 39
type: SIMPLE_ASSIGN
recordTest[1,9,1] = radDat.absExtIrrExtSha[1,9,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  (data->localData[0]->realVars[8] /* recordTest[1,9,1] variable */) = (data->simulationInfo->realParameter[59] /* radDat.absExtIrrExtSha[1,9,1] PARAM */);
  TRACE_POP
}
/*
equation index: 40
type: SIMPLE_ASSIGN
y[1,9,1] = radDat.absExtIrrExtSha[1,9,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  (data->localData[0]->realVars[19] /* y[1,9,1] variable */) = (data->simulationInfo->realParameter[59] /* radDat.absExtIrrExtSha[1,9,1] PARAM */);
  TRACE_POP
}
/*
equation index: 41
type: SIMPLE_ASSIGN
recordTest[1,10,1] = radDat.absExtIrrExtSha[1,10,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  (data->localData[0]->realVars[9] /* recordTest[1,10,1] variable */) = (data->simulationInfo->realParameter[60] /* radDat.absExtIrrExtSha[1,10,1] PARAM */);
  TRACE_POP
}
/*
equation index: 42
type: SIMPLE_ASSIGN
y[1,10,1] = radDat.absExtIrrExtSha[1,10,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  (data->localData[0]->realVars[20] /* y[1,10,1] variable */) = (data->simulationInfo->realParameter[60] /* radDat.absExtIrrExtSha[1,10,1] PARAM */);
  TRACE_POP
}
/*
equation index: 43
type: SIMPLE_ASSIGN
recordTest[1,11,1] = radDat.absExtIrrExtSha[1,11,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  (data->localData[0]->realVars[10] /* recordTest[1,11,1] variable */) = (data->simulationInfo->realParameter[61] /* radDat.absExtIrrExtSha[1,11,1] PARAM */);
  TRACE_POP
}
/*
equation index: 44
type: SIMPLE_ASSIGN
y[1,11,1] = radDat.absExtIrrExtSha[1,11,1]
*/
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  (data->localData[0]->realVars[21] /* y[1,11,1] variable */) = (data->simulationInfo->realParameter[61] /* radDat.absExtIrrExtSha[1,11,1] PARAM */);
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionLocalKnownVars(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_23(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_24(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_25(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_26(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_27(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_28(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_29(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_30(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_31(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_32(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_33(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_34(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_35(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_36(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_37(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_38(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_39(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_40(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_41(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_42(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_43(data, threadData);

  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_44(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_12jac.h"
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initializeDAEmodeData,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionODE,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionAlgebraics,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionDAE,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionLocalKnownVars,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_input_function,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_input_function_init,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_input_function_updateStartValues,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_data_function,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_output_function,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_setc_function,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_setb_function,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_storeDelayed,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_storeSpatialDistribution,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_initSpatialDistribution,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_updateBoundVariableAttributes,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionRemovedInitialEquations,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_updateBoundParameters,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_checkForAsserts,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_ZeroCrossingsEquations,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_ZeroCrossings,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_updateRelations,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_zeroCrossingDescription,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_relationDescription,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_initSample,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_A,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_B,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_C,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_D,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_F,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_H,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianA,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianB,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianC,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianD,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianF,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianH,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacA_column,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacB_column,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacC_column,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacD_column,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacF_column,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacH_column,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_linear_model_frame,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_linear_model_datarecovery_frame,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_mayer,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_lagrange,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_pickUpBoundsForInputsInOptimization,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_setInputData,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_getTimeGrid,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_symbolicInlineSystem,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_initSynchronous,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_updateSynchronous,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_equationsSynchronous,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_inputNames,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_dataReconciliationInputNames,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_dataReconciliationUnmeasuredVariables,
   Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_read_input_fmu,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Buildings"
#define _OMC_LIT_RESOURCE_0_dir_data "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,9,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,67,_OMC_LIT_RESOURCE_0_dir_data);

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
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Buildings.HeatTransfer.Windows.BaseClasses.Examples.DataTest";
  data->modelData->modelFilePrefix = "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/Examples";
  data->modelData->modelGUID = "{3c8d7f0a-ec17-489f-aa2f-306325f4e1a3}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_info.json", data->modelData->resourcesDir);
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 22;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 219;
  data->modelData->nParametersInteger = 4;
  data->modelData->nParametersBoolean = 4;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 22;
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 19;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 246;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 6;
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
  data->modelData->linearizationDumpLanguage = OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

