#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_07dly.c"
#endif
/* Delay */
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_storeDelayed(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  int equationIndexes[2] = {1,-1};
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

