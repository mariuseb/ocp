#if defined(__cplusplus)
  extern "C" {
#endif
  int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_HVACZone_mayer(DATA* data, modelica_real** res, short*);
  int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_HVACZone_lagrange(DATA* data, modelica_real** res, short *, short *);
  int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_HVACZone_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_HVACZone_setInputData(DATA *data, const modelica_boolean file);
  int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_HVACZone_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif