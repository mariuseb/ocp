#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/Desktop/XML_dump/Buildings.HeatTransfer.Windows.BaseClasses.Examples.DataTest/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest.fmutmp/sources/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_13opt.c"
#endif
/* Optimization */
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_model.h"
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_mayer(DATA* data, modelica_real** res,short *i) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_lagrange(DATA* data, modelica_real** res, short * i1, short*i2) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_setInputData(DATA *data, const modelica_boolean file) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t) {
  throwStreamPrint(NULL, "The model was not compiled with -g=Optimica and the corresponding goal function. The optimization solver cannot be used.");
  return 0;
}
#if defined(__cplusplus)
}
#endif