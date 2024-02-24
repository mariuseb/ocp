/* Simulation code for Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements generated by the OpenModelica Compiler OpenModelica 1.22.2~3-g9f40725. */
#if !defined(SimpleRoomFourElements__MODEL_H)
#define SimpleRoomFourElements__MODEL_H

#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "simulation/simulation_info_json.h"
#include "simulation/simulation_runtime.h"
#include "util/omc_error.h"
#include "util/parallel_helper.h"
#include "simulation/jacobian_util.h"
#include "simulation/simulation_omc_assert.h"
#include "simulation/solver/model_help.h"
#include "simulation/solver/delay.h"
#include "simulation/solver/linearSystem.h"
#include "simulation/solver/nonlinearSystem.h"
#include "simulation/solver/mixedSystem.h"
#include "simulation/solver/spatialDistribution.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>

#include "SimpleRoomFourElements_functions.h"

#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getAltitudeLocationTMY3_index 0
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getHeaderElementTMY3_index 1
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getLastHeaderElementTMY3_index 2
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getLatitudeTMY3_index 3
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getLongitudeTMY3_index 4
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeSpanTMY3_index 5
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeZoneTMY3_index 6
#define Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_thermalZoneFourElements_volAir_Medium_temperature__phX_index 7
#define Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_thermalZoneFourElements_volAir_dynBal_Medium_specificEnthalpy__pTX_index 8
#define Buildings_Utilities_Math_Functions_regStep_index 9
#define Buildings_Utilities_Math_Functions_smoothLimit_index 10
#define Buildings_Utilities_Math_Functions_smoothMax_index 11
#define Buildings_Utilities_Math_Functions_smoothMin_index 12
#define Modelica_Blocks_Tables_Internal_getNextTimeEvent_index 13
#define Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax_index 14
#define Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin_index 15
#define Modelica_Blocks_Tables_Internal_getTable1DValue_index 16
#define Modelica_Blocks_Tables_Internal_getTimeTableTmax_index 17
#define Modelica_Blocks_Tables_Internal_getTimeTableTmin_index 18
#define Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer2_index 19
#define Modelica_Blocks_Types_ExternalCombiTable1D_constructor_index 20
#define Modelica_Blocks_Types_ExternalCombiTable1D_destructor_index 21
#define Modelica_Blocks_Types_ExternalCombiTimeTable_constructor_index 22
#define Modelica_Blocks_Types_ExternalCombiTimeTable_destructor_index 23
#define Modelica_Utilities_Streams_readLine_index 24
#define Modelica_Utilities_Strings_compare_index 25
#define Modelica_Utilities_Strings_find_index 26
#define Modelica_Utilities_Strings_findLast_index 27
#define Modelica_Utilities_Strings_isEmpty_index 28
#define Modelica_Utilities_Strings_isEqual_index 29
#define Modelica_Utilities_Strings_length_index 30
#define Modelica_Utilities_Strings_substring_index 31
#define Modelica_Utilities_Strings_Advanced_scanReal_index 32
#define Modelica_Utilities_Strings_Advanced_skipWhiteSpace_index 33

extern void SimpleRoomFourElements_callExternalObjectDestructors(DATA *_data, threadData_t *threadData);
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
extern void SimpleRoomFourElements_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA *data);
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
extern void SimpleRoomFourElements_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA *data);
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
#endif
#if !defined(OMC_NO_STATESELECTION)
extern void SimpleRoomFourElements_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
#endif
extern int SimpleRoomFourElements_functionAlgebraics(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_function_storeDelayed(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_function_storeSpatialDistribution(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_function_initSpatialDistribution(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_updateBoundVariableAttributes(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_functionInitialEquations(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_functionRemovedInitialEquations(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_updateBoundParameters(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_checkForAsserts(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_function_ZeroCrossings(DATA *data, threadData_t *threadData, double* gout);
extern int SimpleRoomFourElements_function_updateRelations(DATA *data, threadData_t *threadData, int evalZeroCross);
extern const char* SimpleRoomFourElements_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* SimpleRoomFourElements_relationDescription(int i);
extern void SimpleRoomFourElements_function_initSample(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_initialAnalyticJacobianG(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRoomFourElements_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRoomFourElements_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRoomFourElements_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRoomFourElements_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRoomFourElements_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRoomFourElements_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRoomFourElements_functionJacG_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRoomFourElements_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRoomFourElements_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRoomFourElements_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRoomFourElements_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRoomFourElements_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRoomFourElements_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern const char* SimpleRoomFourElements_linear_model_frame(void);
extern const char* SimpleRoomFourElements_linear_model_datarecovery_frame(void);
extern int SimpleRoomFourElements_mayer(DATA* data, modelica_real** res, short *);
extern int SimpleRoomFourElements_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int SimpleRoomFourElements_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int SimpleRoomFourElements_setInputData(DATA *data, const modelica_boolean file);
extern int SimpleRoomFourElements_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
extern void SimpleRoomFourElements_function_initSynchronous(DATA * data, threadData_t *threadData);
extern void SimpleRoomFourElements_function_updateSynchronous(DATA * data, threadData_t *threadData, long base_idx);
extern int SimpleRoomFourElements_function_equationsSynchronous(DATA * data, threadData_t *threadData, long base_idx, long sub_idx);
extern void SimpleRoomFourElements_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationData);
extern void SimpleRoomFourElements_function_savePreSynchronous(DATA *data, threadData_t *threadData);
extern int SimpleRoomFourElements_inputNames(DATA* data, char ** names);
extern int SimpleRoomFourElements_dataReconciliationInputNames(DATA* data, char ** names);
extern int SimpleRoomFourElements_dataReconciliationUnmeasuredVariables(DATA* data, char ** names);
extern int SimpleRoomFourElements_initializeDAEmodeData(DATA *data, DAEMODE_DATA*);
extern int SimpleRoomFourElements_functionLocalKnownVars(DATA* data, threadData_t* threadData);
extern int SimpleRoomFourElements_symbolicInlineSystem(DATA* data, threadData_t* threadData);

#include "SimpleRoomFourElements_literals.h"




#if defined(HPCOM) && !defined(_OPENMP)
  #error "HPCOM requires OpenMP or the results are wrong"
#endif
#if defined(_OPENMP)
  #include <omp.h>
#else
  /* dummy omp defines */
  #define omp_get_max_threads() 1
#endif

#if defined(__cplusplus)
}
#endif

#endif /* !defined(SimpleRoomFourElements__MODEL_H) */


