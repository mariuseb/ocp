#if defined(__cplusplus)
  extern "C" {
#endif
  int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_mayer(DATA* data, modelica_real** res, short*);
  int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_lagrange(DATA* data, modelica_real** res, short *, short *);
  int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_setInputData(DATA *data, const modelica_boolean file);
  int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif