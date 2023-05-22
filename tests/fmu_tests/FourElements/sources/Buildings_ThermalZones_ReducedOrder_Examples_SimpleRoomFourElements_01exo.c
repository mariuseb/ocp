#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_01exo.c"
#endif
/* External objects file */
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_callExternalObjectDestructors(DATA *data, threadData_t *threadData)
{
  if(data->simulationInfo->extObjs)
  {
    omc_Modelica_Blocks_Types_ExternalCombiTable1D_destructor(threadData,(data->simulationInfo->extObjs[1]));
    omc_Modelica_Blocks_Types_ExternalCombiTable1D_destructor(threadData,(data->simulationInfo->extObjs[2]));
    omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData,(data->simulationInfo->extObjs[0]));
    free(data->simulationInfo->extObjs);
    data->simulationInfo->extObjs = 0;
  }
}
#if defined(__cplusplus)
}
#endif

