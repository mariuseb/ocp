#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustom/Buildings_HeatTransfer_Windows_Examples_WindowCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustom_05evt.c"
#endif
/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *Buildings_HeatTransfer_Windows_Examples_WindowCustom_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time < 0.25",
  "time < 0.75"};
  static const int occurEqs0[] = {1,124};
  static const int occurEqs1[] = {1,124};
  static const int *occurEqs[] = {occurEqs0,occurEqs1};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_boolean tmp1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  tmp0 = LessZC(data->localData[0]->timeValue, 0.25, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp0) ? 1 : -1;

  tmp1 = LessZC(data->localData[0]->timeValue, 0.75, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp1) ? 1 : -1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *Buildings_HeatTransfer_Windows_Examples_WindowCustom_relationDescription(int i)
{
  const char *res[] = {"time < 0.25",
  "time < 0.75"};
  return res[i];
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp2;
  modelica_boolean tmp3;
  
  if(evalforZeroCross) {
    tmp2 = LessZC(data->localData[0]->timeValue, 0.25, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp2;

    tmp3 = LessZC(data->localData[0]->timeValue, 0.75, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp3;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->timeValue < 0.25);

    data->simulationInfo->relations[1] = (data->localData[0]->timeValue < 0.75);
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

