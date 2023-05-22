#if defined(__cplusplus)
  extern "C" {
#endif
  int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_mayer(DATA* data, modelica_real** res, short*);
  int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_lagrange(DATA* data, modelica_real** res, short *, short *);
  int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_setInputData(DATA *data, const modelica_boolean file);
  int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif