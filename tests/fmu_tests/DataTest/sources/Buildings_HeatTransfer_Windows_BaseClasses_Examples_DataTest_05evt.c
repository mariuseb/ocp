#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/Desktop/XML_dump/Buildings.HeatTransfer.Windows.BaseClasses.Examples.DataTest/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest.fmutmp/sources/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_05evt.c"
#endif
/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  *out_EquationIndexes = NULL;
  return "empty";
}

/* forwarded equations */

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;


#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;


#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_relationDescription(int i)
{
  return "empty";
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  
  if(evalforZeroCross) {
  } else {
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

