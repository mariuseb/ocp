/* Simulation code for Buildings.Fluid.Actuators.Valves.Examples.ThreeWayValves generated by the OpenModelica Compiler v1.21.0-2-g0bc3d29bd9-cmake. */
#if !defined(ThreeWayValves__MODEL_H)
#define ThreeWayValves__MODEL_H

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

#include "ThreeWayValves_functions.h"

#define _omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fdp_index 0
#define Buildings_Fluid_Actuators_BaseClasses_equalPercentage_index 1
#define Buildings_Fluid_Actuators_Valves_Examples_ThreeWayValves_ret_Medium_ThermodynamicState_index 2
#define Buildings_Fluid_Actuators_Valves_Examples_ThreeWayValves_sin_Medium_ThermodynamicState_index 3
#define Buildings_Fluid_Actuators_Valves_Examples_ThreeWayValves_sou_Medium_ThermodynamicState_index 4
#define Buildings_Fluid_Actuators_Valves_Examples_ThreeWayValves_valEquPerLin_vol_Medium_temperature__phX_index 5
#define Buildings_Fluid_Actuators_Valves_Examples_ThreeWayValves_valLin_vol_Medium_temperature__phX_index 6
#define Buildings_Fluid_Actuators_Valves_Examples_ThreeWayValves_valTab_vol_Medium_temperature__phX_index 7
#define Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__dp_index 8
#define Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax_index 9
#define Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin_index 10
#define Modelica_Blocks_Tables_Internal_getTable1DValue_index 11
#define Modelica_Blocks_Types_ExternalCombiTable1D_constructor_index 12
#define Modelica_Blocks_Types_ExternalCombiTable1D_destructor_index 13
#define Modelica_Fluid_Utilities_checkBoundary_index 14
#define Modelica_Utilities_Streams_error_index 15

extern void ThreeWayValves_callExternalObjectDestructors(DATA *_data, threadData_t *threadData);
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
#endif
#if !defined(OMC_NO_STATESELECTION)
extern void ThreeWayValves_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
#endif
extern int ThreeWayValves_functionAlgebraics(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_function_storeDelayed(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_function_storeSpatialDistribution(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_function_initSpatialDistribution(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_updateBoundVariableAttributes(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_functionInitialEquations(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_functionRemovedInitialEquations(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_updateBoundParameters(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_checkForAsserts(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_function_ZeroCrossings(DATA *data, threadData_t *threadData, double* gout);
extern int ThreeWayValves_function_updateRelations(DATA *data, threadData_t *threadData, int evalZeroCross);
extern const char* ThreeWayValves_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* ThreeWayValves_relationDescription(int i);
extern void ThreeWayValves_function_initSample(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_initialAnalyticJacobianG(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int ThreeWayValves_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int ThreeWayValves_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int ThreeWayValves_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int ThreeWayValves_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int ThreeWayValves_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int ThreeWayValves_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int ThreeWayValves_functionJacG_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int ThreeWayValves_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int ThreeWayValves_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int ThreeWayValves_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int ThreeWayValves_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int ThreeWayValves_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int ThreeWayValves_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern const char* ThreeWayValves_linear_model_frame(void);
extern const char* ThreeWayValves_linear_model_datarecovery_frame(void);
extern int ThreeWayValves_mayer(DATA* data, modelica_real** res, short *);
extern int ThreeWayValves_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int ThreeWayValves_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int ThreeWayValves_setInputData(DATA *data, const modelica_boolean file);
extern int ThreeWayValves_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
extern void ThreeWayValves_function_initSynchronous(DATA * data, threadData_t *threadData);
extern void ThreeWayValves_function_updateSynchronous(DATA * data, threadData_t *threadData, long base_idx);
extern int ThreeWayValves_function_equationsSynchronous(DATA * data, threadData_t *threadData, long base_idx, long sub_idx);
extern void ThreeWayValves_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationData);
extern void ThreeWayValves_function_savePreSynchronous(DATA *data, threadData_t *threadData);
extern int ThreeWayValves_inputNames(DATA* data, char ** names);
extern int ThreeWayValves_dataReconciliationInputNames(DATA* data, char ** names);
extern int ThreeWayValves_dataReconciliationUnmeasuredVariables(DATA* data, char ** names);
extern int ThreeWayValves_initializeDAEmodeData(DATA *data, DAEMODE_DATA*);
extern int ThreeWayValves_functionLocalKnownVars(DATA* data, threadData_t* threadData);
extern int ThreeWayValves_symbolicInlineSystem(DATA* data, threadData_t* threadData);

#include "ThreeWayValves_literals.h"




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

#endif /* !defined(ThreeWayValves__MODEL_H) */

