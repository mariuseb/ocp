#if defined(__cplusplus)
  extern "C" {
#endif
  int ThreeWayValves_mayer(DATA* data, modelica_real** res, short*);
  int ThreeWayValves_lagrange(DATA* data, modelica_real** res, short *, short *);
  int ThreeWayValves_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int ThreeWayValves_setInputData(DATA *data, const modelica_boolean file);
  int ThreeWayValves_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif