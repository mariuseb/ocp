#if defined(__cplusplus)
  extern "C" {
#endif
  int SimpleRC_mayer(DATA* data, modelica_real** res, short*);
  int SimpleRC_lagrange(DATA* data, modelica_real** res, short *, short *);
  int SimpleRC_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int SimpleRC_setInputData(DATA *data, const modelica_boolean file);
  int SimpleRC_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif