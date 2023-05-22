#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustomNoHeat/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_01exo.c"
#endif
/* External objects file */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_callExternalObjectDestructors(DATA *data, threadData_t *threadData)
{
  if(data->simulationInfo->extObjs)
  {
    free(data->simulationInfo->extObjs);
    data->simulationInfo->extObjs = 0;
  }
}
#if defined(__cplusplus)
}
#endif

