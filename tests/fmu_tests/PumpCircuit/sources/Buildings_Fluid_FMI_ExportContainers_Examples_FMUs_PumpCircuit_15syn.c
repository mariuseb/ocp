#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit.fmutmp/sources/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_15syn.c"
#endif
/* Synchronous systems */
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the clocks of model. */
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_initSynchronous(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  data->simulationInfo->baseClocks = calloc(0, sizeof(BASECLOCK_DATA));
  
  TRACE_POP
}

/* Update base-clock. */
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_updateSynchronous(DATA *data, threadData_t *threadData, long base_idx)
{
  TRACE_PUSH
  modelica_boolean ret;
  switch (base_idx) {
    default:
      throwStreamPrint(NULL, "Internal Error: unknown base partition %ld", base_idx);
      break;
  }
  TRACE_POP
}



/* Clocked systems equations */
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_equationsSynchronous(DATA *data, threadData_t *threadData, long base_idx, long sub_idx)
{
  TRACE_PUSH
  int ret;

  switch (base_idx) {
    default:
      throwStreamPrint(NULL, "Internal Error: unknown base-clock partition %ld", base_idx);
      ret = 1;
      break;
  }

  TRACE_POP
  return ret;
}

/* %v% = pre(%v%)*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_savePreSynchronous(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
}

#if defined(__cplusplus)
}
#endif

