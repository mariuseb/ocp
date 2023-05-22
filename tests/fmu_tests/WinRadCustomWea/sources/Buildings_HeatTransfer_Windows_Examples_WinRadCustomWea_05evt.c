#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustomWea/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_05evt.c"
#endif
/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"weaDat.conTim.canRepeatWeatherFile and weaBus.cloTim > pre(weaDat.conTim.tNext)",
  "weaDat.conTimMin.canRepeatWeatherFile and weaDat.add30Min.y > pre(weaDat.conTimMin.tNext)"};
  static const int occurEqs0[] = {1,231};
  static const int occurEqs1[] = {1,240};
  static const int *occurEqs[] = {occurEqs0,occurEqs1};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_230(DATA* data, threadData_t *threadData);
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_239(DATA* data, threadData_t *threadData);

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_230(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_239(data, threadData);
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_boolean tmp1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  tmp0 = GreaterZC((data->localData[0]->realVars[47] /* weaBus.cloTim variable */), (data->simulationInfo->realVarsPre[139] /* weaDat.conTim.tNext DISCRETE */), data->simulationInfo->storedRelations[0]);
  gout[0] = (((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) && tmp0)) ? 1 : -1;

  tmp1 = GreaterZC((data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */), (data->simulationInfo->realVarsPre[140] /* weaDat.conTimMin.tNext DISCRETE */), data->simulationInfo->storedRelations[1]);
  gout[1] = (((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) && tmp1)) ? 1 : -1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_relationDescription(int i)
{
  const char *res[] = {"weaBus.cloTim > pre(weaDat.conTim.tNext)",
  "weaDat.add30Min.y > pre(weaDat.conTimMin.tNext)"};
  return res[i];
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp2;
  modelica_boolean tmp3;
  
  if(evalforZeroCross) {
    tmp2 = GreaterZC((data->localData[0]->realVars[47] /* weaBus.cloTim variable */), (data->simulationInfo->realVarsPre[139] /* weaDat.conTim.tNext DISCRETE */), data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp2;

    tmp3 = GreaterZC((data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */), (data->simulationInfo->realVarsPre[140] /* weaDat.conTimMin.tNext DISCRETE */), data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp3;
  } else {
    data->simulationInfo->relations[0] = ((data->localData[0]->realVars[47] /* weaBus.cloTim variable */) > (data->simulationInfo->realVarsPre[139] /* weaDat.conTim.tNext DISCRETE */));

    data->simulationInfo->relations[1] = ((data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */) > (data->simulationInfo->realVarsPre[140] /* weaDat.conTimMin.tNext DISCRETE */));
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

