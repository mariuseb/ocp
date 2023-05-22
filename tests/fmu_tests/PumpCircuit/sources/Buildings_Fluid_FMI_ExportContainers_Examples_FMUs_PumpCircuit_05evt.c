#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit.fmutmp/sources/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_05evt.c"
#endif
/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"fluPor[2].m_flow >= 0.0",
  "fluPor[1].m_flow >= 0.0"};
  static const int occurEqs0[] = {1,255};
  static const int occurEqs1[] = {1,258};
  static const int *occurEqs[] = {occurEqs0,occurEqs1};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(DATA* data, threadData_t *threadData);
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_254(DATA* data, threadData_t *threadData);
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_256(DATA* data, threadData_t *threadData);
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_285(DATA* data, threadData_t *threadData);
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_286(DATA* data, threadData_t *threadData);

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_254(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_256(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_285(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_286(data, threadData);
  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_boolean tmp1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  tmp0 = GreaterEqZC((data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */), 0.0, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp0) ? 1 : -1;

  tmp1 = GreaterEqZC((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), 0.0, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp1) ? 1 : -1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_relationDescription(int i)
{
  const char *res[] = {"fluPor[2].m_flow >= 0.0",
  "fluPor[1].m_flow >= 0.0"};
  return res[i];
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp2;
  modelica_boolean tmp3;
  
  if(evalforZeroCross) {
    tmp2 = GreaterEqZC((data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */), 0.0, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp2;

    tmp3 = GreaterEqZC((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), 0.0, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp3;
  } else {
    data->simulationInfo->relations[0] = ((data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */) >= 0.0);

    data->simulationInfo->relations[1] = ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */) >= 0.0);
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

