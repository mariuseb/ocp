/* Simulation code for Buildings.HeatTransfer.Windows.Examples.WinRadCustom generated by the OpenModelica Compiler OpenModelica 1.21.0~dev-298-g51286f2. */
#if !defined(Buildings_HeatTransfer_Windows_Examples_WinRadCustom__MODEL_H)
#define Buildings_HeatTransfer_Windows_Examples_WinRadCustom__MODEL_H

#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "simulation/simulation_info_json.h"
#include "simulation/simulation_runtime.h"
#include "util/omc_error.h"
#include "util/parallel_helper.h"
#include "util/jacobian_util.h"
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

#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functions.h"

#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getAltitudeLocationTMY3_index 0
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getHeaderElementTMY3_index 1
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getLastHeaderElementTMY3_index 2
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getLatitudeTMY3_index 3
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getLongitudeTMY3_index 4
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeSpanTMY3_index 5
#define Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeZoneTMY3_index 6
#define Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation_index 7
#define Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax_index 8
#define Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin_index 9
#define Modelica_Blocks_Tables_Internal_getTable1DValue_index 10
#define Modelica_Blocks_Types_ExternalCombiTable1D_constructor_index 11
#define Modelica_Blocks_Types_ExternalCombiTable1D_destructor_index 12
#define Modelica_Fluid_Utilities_cubicHermite_index 13
#define Modelica_Utilities_Streams_readLine_index 14
#define Modelica_Utilities_Strings_compare_index 15
#define Modelica_Utilities_Strings_find_index 16
#define Modelica_Utilities_Strings_findLast_index 17
#define Modelica_Utilities_Strings_isEmpty_index 18
#define Modelica_Utilities_Strings_isEqual_index 19
#define Modelica_Utilities_Strings_length_index 20
#define Modelica_Utilities_Strings_substring_index 21
#define Modelica_Utilities_Strings_Advanced_scanReal_index 22
#define Modelica_Utilities_Strings_Advanced_skipWhiteSpace_index 23

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_callExternalObjectDestructors(DATA *_data, threadData_t *threadData);
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA *data);
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
#endif
#if !defined(OMC_NO_STATESELECTION)
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
#endif
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionAlgebraics(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_storeDelayed(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_storeSpatialDistribution(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_initSpatialDistribution(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_updateBoundVariableAttributes(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionInitialEquations(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionRemovedInitialEquations(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_updateBoundParameters(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_checkForAsserts(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_ZeroCrossings(DATA *data, threadData_t *threadData, double* gout);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_updateRelations(DATA *data, threadData_t *threadData, int evalZeroCross);
extern const char* Buildings_HeatTransfer_Windows_Examples_WinRadCustom_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* Buildings_HeatTransfer_Windows_Examples_WinRadCustom_relationDescription(int i);
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_initSample(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianG(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacG_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern const char* Buildings_HeatTransfer_Windows_Examples_WinRadCustom_linear_model_frame(void);
extern const char* Buildings_HeatTransfer_Windows_Examples_WinRadCustom_linear_model_datarecovery_frame(void);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_mayer(DATA* data, modelica_real** res, short *);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_setInputData(DATA *data, const modelica_boolean file);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_initSynchronous(DATA * data, threadData_t *threadData);
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_updateSynchronous(DATA * data, threadData_t *threadData, long base_idx);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_equationsSynchronous(DATA * data, threadData_t *threadData, long base_idx, long sub_idx);
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationData);
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_function_savePreSynchronous(DATA *data, threadData_t *threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_inputNames(DATA* data, char ** names);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_dataReconciliationInputNames(DATA* data, char ** names);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_dataReconciliationUnmeasuredVariables(DATA* data, char ** names);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initializeDAEmodeData(DATA *data, DAEMODE_DATA*);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionLocalKnownVars(DATA* data, threadData_t* threadData);
extern int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_symbolicInlineSystem(DATA* data, threadData_t* threadData);

#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_literals.h"




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

#endif /* !defined(Buildings_HeatTransfer_Windows_Examples_WinRadCustom__MODEL_H) */


