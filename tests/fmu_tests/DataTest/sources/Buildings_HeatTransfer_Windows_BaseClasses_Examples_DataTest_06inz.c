#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/Desktop/XML_dump/Buildings.HeatTransfer.Windows.BaseClasses.Examples.DataTest/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest.fmutmp/sources/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_06inz.c"
#endif
/* Initialization */
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_model.h"
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_11mix.h"
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_43(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_44(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_41(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_42(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_39(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_40(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_37(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_38(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_35(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_36(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_33(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_34(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_31(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_32(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_29(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_30(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_27(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_28(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_25(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_26(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_23(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_24(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_43(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_44(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_41(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_42(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_39(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_40(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_37(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_38(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_35(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_36(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_33(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_34(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_31(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_32(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_29(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_30(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_27(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_28(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_25(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_26(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_23(data, threadData);
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_eqFunction_24(data, threadData);
  TRACE_POP
}

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionInitialEquations_lambda0 function */

int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

