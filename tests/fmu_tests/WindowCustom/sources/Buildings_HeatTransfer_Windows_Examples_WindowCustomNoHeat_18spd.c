#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustomNoHeat/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_18spd.c"
#endif
/* spatialDistribution */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_storeSpatialDistribution(DATA *data, threadData_t *threadData)
{
  int equationIndexes[2] = {1,-1};
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_initSpatialDistribution(DATA *data, threadData_t *threadData)
{

  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

