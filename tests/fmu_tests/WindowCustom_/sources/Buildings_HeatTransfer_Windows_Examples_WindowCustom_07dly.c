#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustom/Buildings_HeatTransfer_Windows_Examples_WindowCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustom_07dly.c"
#endif
/* Delay */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_function_storeDelayed(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  int equationIndexes[2] = {1,-1};
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

