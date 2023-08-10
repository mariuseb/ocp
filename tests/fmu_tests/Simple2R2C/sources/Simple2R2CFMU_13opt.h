#if defined(__cplusplus)
  extern "C" {
#endif
  int Simple2R2CFMU_mayer(DATA* data, modelica_real** res, short*);
  int Simple2R2CFMU_lagrange(DATA* data, modelica_real** res, short *, short *);
  int Simple2R2CFMU_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int Simple2R2CFMU_setInputData(DATA *data, const modelica_boolean file);
  int Simple2R2CFMU_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif