#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_05evt.c"
#endif
/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time >= pre(intGai.nextTimeEvent)",
  "weaDat.conTimMin.canRepeatWeatherFile and weaDat.add30Min.y > pre(weaDat.conTimMin.tNext)",
  "weaDat.conTim.canRepeatWeatherFile and HDifTil[1].weaBus.cloTim > pre(weaDat.conTim.tNext)"};
  static const int occurEqs0[] = {1,669};
  static const int occurEqs1[] = {1,412};
  static const int occurEqs2[] = {1,450};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_410(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_411(DATA* data, threadData_t *threadData);

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_410(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_411(data, threadData);
  
  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  tmp0 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[358] /* intGai.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp0) ? 1 : -1;

  tmp1 = GreaterZC((data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */), (data->simulationInfo->realVarsPre[361] /* weaDat.conTimMin.tNext DISCRETE */), data->simulationInfo->storedRelations[1]);
  gout[1] = (((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) && tmp1)) ? 1 : -1;

  tmp2 = GreaterZC((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */), (data->simulationInfo->realVarsPre[360] /* weaDat.conTim.tNext DISCRETE */), data->simulationInfo->storedRelations[2]);
  gout[2] = (((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */) && tmp2)) ? 1 : -1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_relationDescription(int i)
{
  const char *res[] = {"time >= pre(intGai.nextTimeEvent)",
  "weaDat.add30Min.y > pre(weaDat.conTimMin.tNext)",
  "HDifTil[1].weaBus.cloTim > pre(weaDat.conTim.tNext)"};
  return res[i];
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  
  if(evalforZeroCross) {
    tmp3 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[358] /* intGai.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp3;

    tmp4 = GreaterZC((data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */), (data->simulationInfo->realVarsPre[361] /* weaDat.conTimMin.tNext DISCRETE */), data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp4;

    tmp5 = GreaterZC((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */), (data->simulationInfo->realVarsPre[360] /* weaDat.conTim.tNext DISCRETE */), data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp5;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->timeValue >= (data->simulationInfo->realVarsPre[358] /* intGai.nextTimeEvent DISCRETE */));

    data->simulationInfo->relations[1] = ((data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */) > (data->simulationInfo->realVarsPre[361] /* weaDat.conTimMin.tNext DISCRETE */));

    data->simulationInfo->relations[2] = ((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */) > (data->simulationInfo->realVarsPre[360] /* weaDat.conTim.tNext DISCRETE */));
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

