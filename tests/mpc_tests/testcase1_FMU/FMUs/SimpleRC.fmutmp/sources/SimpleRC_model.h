/* Simulation code for SimpleRC generated by the OpenModelica Compiler OpenModelica 1.22.1. */
#if !defined(SimpleRC__MODEL_H)
#define SimpleRC__MODEL_H

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

#include "SimpleRC_functions.h"


extern void SimpleRC_callExternalObjectDestructors(DATA *_data, threadData_t *threadData);
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
#endif
#if !defined(OMC_NO_STATESELECTION)
extern void SimpleRC_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
#endif
extern int SimpleRC_functionAlgebraics(DATA *data, threadData_t *threadData);
extern int SimpleRC_function_storeDelayed(DATA *data, threadData_t *threadData);
extern int SimpleRC_function_storeSpatialDistribution(DATA *data, threadData_t *threadData);
extern int SimpleRC_function_initSpatialDistribution(DATA *data, threadData_t *threadData);
extern int SimpleRC_updateBoundVariableAttributes(DATA *data, threadData_t *threadData);
extern int SimpleRC_functionInitialEquations(DATA *data, threadData_t *threadData);
extern int SimpleRC_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData);
extern int SimpleRC_functionRemovedInitialEquations(DATA *data, threadData_t *threadData);
extern int SimpleRC_updateBoundParameters(DATA *data, threadData_t *threadData);
extern int SimpleRC_checkForAsserts(DATA *data, threadData_t *threadData);
extern int SimpleRC_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData);
extern int SimpleRC_function_ZeroCrossings(DATA *data, threadData_t *threadData, double* gout);
extern int SimpleRC_function_updateRelations(DATA *data, threadData_t *threadData, int evalZeroCross);
extern const char* SimpleRC_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* SimpleRC_relationDescription(int i);
extern void SimpleRC_function_initSample(DATA *data, threadData_t *threadData);
extern int SimpleRC_initialAnalyticJacobianG(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRC_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRC_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRC_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRC_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRC_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRC_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int SimpleRC_functionJacG_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRC_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRC_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRC_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRC_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRC_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int SimpleRC_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern const char* SimpleRC_linear_model_frame(void);
extern const char* SimpleRC_linear_model_datarecovery_frame(void);
extern int SimpleRC_mayer(DATA* data, modelica_real** res, short *);
extern int SimpleRC_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int SimpleRC_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int SimpleRC_setInputData(DATA *data, const modelica_boolean file);
extern int SimpleRC_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
extern void SimpleRC_function_initSynchronous(DATA * data, threadData_t *threadData);
extern void SimpleRC_function_updateSynchronous(DATA * data, threadData_t *threadData, long base_idx);
extern int SimpleRC_function_equationsSynchronous(DATA * data, threadData_t *threadData, long base_idx, long sub_idx);
extern void SimpleRC_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationData);
extern void SimpleRC_function_savePreSynchronous(DATA *data, threadData_t *threadData);
extern int SimpleRC_inputNames(DATA* data, char ** names);
extern int SimpleRC_dataReconciliationInputNames(DATA* data, char ** names);
extern int SimpleRC_dataReconciliationUnmeasuredVariables(DATA* data, char ** names);
extern int SimpleRC_initializeDAEmodeData(DATA *data, DAEMODE_DATA*);
extern int SimpleRC_functionLocalKnownVars(DATA* data, threadData_t* threadData);
extern int SimpleRC_symbolicInlineSystem(DATA* data, threadData_t* threadData);

#include "SimpleRC_literals.h"




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

#endif /* !defined(SimpleRC__MODEL_H) */


