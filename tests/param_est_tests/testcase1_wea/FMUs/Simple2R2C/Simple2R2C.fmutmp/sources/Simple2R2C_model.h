/* Simulation code for Simple2R2C generated by the OpenModelica Compiler OpenModelica 1.21.0. */
#if !defined(Simple2R2C__MODEL_H)
#define Simple2R2C__MODEL_H

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

#include "Simple2R2C_functions.h"


extern void Simple2R2C_callExternalObjectDestructors(DATA *_data, threadData_t *threadData);
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
#endif
#if !defined(OMC_NO_STATESELECTION)
extern void Simple2R2C_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
#endif
extern int Simple2R2C_functionAlgebraics(DATA *data, threadData_t *threadData);
extern int Simple2R2C_function_storeDelayed(DATA *data, threadData_t *threadData);
extern int Simple2R2C_function_storeSpatialDistribution(DATA *data, threadData_t *threadData);
extern int Simple2R2C_function_initSpatialDistribution(DATA *data, threadData_t *threadData);
extern int Simple2R2C_updateBoundVariableAttributes(DATA *data, threadData_t *threadData);
extern int Simple2R2C_functionInitialEquations(DATA *data, threadData_t *threadData);
extern int Simple2R2C_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData);
extern int Simple2R2C_functionRemovedInitialEquations(DATA *data, threadData_t *threadData);
extern int Simple2R2C_updateBoundParameters(DATA *data, threadData_t *threadData);
extern int Simple2R2C_checkForAsserts(DATA *data, threadData_t *threadData);
extern int Simple2R2C_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData);
extern int Simple2R2C_function_ZeroCrossings(DATA *data, threadData_t *threadData, double* gout);
extern int Simple2R2C_function_updateRelations(DATA *data, threadData_t *threadData, int evalZeroCross);
extern const char* Simple2R2C_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* Simple2R2C_relationDescription(int i);
extern void Simple2R2C_function_initSample(DATA *data, threadData_t *threadData);
extern int Simple2R2C_initialAnalyticJacobianG(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Simple2R2C_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Simple2R2C_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Simple2R2C_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Simple2R2C_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Simple2R2C_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Simple2R2C_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int Simple2R2C_functionJacG_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Simple2R2C_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Simple2R2C_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Simple2R2C_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Simple2R2C_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Simple2R2C_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int Simple2R2C_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern const char* Simple2R2C_linear_model_frame(void);
extern const char* Simple2R2C_linear_model_datarecovery_frame(void);
extern int Simple2R2C_mayer(DATA* data, modelica_real** res, short *);
extern int Simple2R2C_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int Simple2R2C_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int Simple2R2C_setInputData(DATA *data, const modelica_boolean file);
extern int Simple2R2C_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
extern void Simple2R2C_function_initSynchronous(DATA * data, threadData_t *threadData);
extern void Simple2R2C_function_updateSynchronous(DATA * data, threadData_t *threadData, long base_idx);
extern int Simple2R2C_function_equationsSynchronous(DATA * data, threadData_t *threadData, long base_idx, long sub_idx);
extern void Simple2R2C_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationData);
extern void Simple2R2C_function_savePreSynchronous(DATA *data, threadData_t *threadData);
extern int Simple2R2C_inputNames(DATA* data, char ** names);
extern int Simple2R2C_dataReconciliationInputNames(DATA* data, char ** names);
extern int Simple2R2C_dataReconciliationUnmeasuredVariables(DATA* data, char ** names);
extern int Simple2R2C_initializeDAEmodeData(DATA *data, DAEMODE_DATA*);
extern int Simple2R2C_functionLocalKnownVars(DATA* data, threadData_t* threadData);
extern int Simple2R2C_symbolicInlineSystem(DATA* data, threadData_t* threadData);

#include "Simple2R2C_literals.h"




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

#endif /* !defined(Simple2R2C__MODEL_H) */

