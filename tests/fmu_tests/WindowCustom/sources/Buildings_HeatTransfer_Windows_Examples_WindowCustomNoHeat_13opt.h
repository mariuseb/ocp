#if defined(__cplusplus)
  extern "C" {
#endif
  int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_mayer(DATA* data, modelica_real** res, short*);
  int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_lagrange(DATA* data, modelica_real** res, short *, short *);
  int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_setInputData(DATA *data, const modelica_boolean file);
  int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif