/* Simulation code for HVACZoneRad generated by the OpenModelica Compiler v1.21.0-2-g0bc3d29bd9-cmake. */
#if !defined(HVACZoneRad__MODEL_H)
#define HVACZoneRad__MODEL_H

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

#include "HVACZoneRad_functions.h"

#define _omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fdp_index 0
#define _omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fm_5F_5Fflow_index 1
#define _omcQ_24DER_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_index 2
#define _omcQ_24DER_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_index 3
#define _omcQ_24DER_24Modelica_24PFluid_24PUtilities_24PcubicHermite_index 4
#define Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__dp_index 5
#define Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow_index 6
#define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiency_index 7
#define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_index 8
#define Buildings_Utilities_Math_Functions_cubicHermiteLinearExtrapolation_index 9
#define Buildings_Utilities_Math_Functions_regNonZeroPower_index 10
#define Buildings_Utilities_Math_Functions_regStep_index 11
#define Buildings_Utilities_Math_Functions_smoothMax_index 12
#define Buildings_Utilities_Math_Functions_BaseClasses_der__regNonZeroPower_index 13
#define HVACZoneRad_bou_Medium_ThermodynamicState_index 14
#define HVACZoneRad_bou_Medium_setState__pTX_index 15
#define HVACZoneRad_bou_Medium_specificEnthalpy_index 16
#define HVACZoneRad_hea_outCon_Medium_ThermodynamicState_index 17
#define HVACZoneRad_hea_outCon_Medium_setState__pTX_index 18
#define HVACZoneRad_hea_outCon_Medium_specificEnthalpy_index 19
#define HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_index 20
#define HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_index 21
#define HVACZoneRad_pump_Medium_ThermodynamicState_index 22
#define HVACZoneRad_pump_preSou_Medium_ThermodynamicState_index 23
#define HVACZoneRad_pump_preSou_Medium_density_index 24
#define HVACZoneRad_pump_preSou_Medium_setState__phX_index 25
#define HVACZoneRad_pump_vol_Medium_temperature__phX_index 26
#define HVACZoneRad_rad_Medium_ThermodynamicState_index 27
#define HVACZoneRad_rad_Medium_setState__pTX_index 28
#define HVACZoneRad_rad_Medium_specificHeatCapacityCp_index 29
#define HVACZoneRad_rad_vol_Medium_temperature__phX_index 30
#define HVACZoneRad_vol_Medium_ThermodynamicState_index 31
#define HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_index 32
#define Modelica_Fluid_Utilities_checkBoundary_index 33
#define Modelica_Fluid_Utilities_cubicHermite_index 34
#define Modelica_Fluid_Utilities_regStep_index 35
#define Modelica_Utilities_Streams_error_index 36

extern void HVACZoneRad_callExternalObjectDestructors(DATA *_data, threadData_t *threadData);
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
extern void HVACZoneRad_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA *data);
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
extern void HVACZoneRad_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA *data);
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
#endif
#if !defined(OMC_NO_STATESELECTION)
extern void HVACZoneRad_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
#endif
extern int HVACZoneRad_functionAlgebraics(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_function_storeDelayed(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_function_storeSpatialDistribution(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_function_initSpatialDistribution(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_updateBoundVariableAttributes(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_functionInitialEquations(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_functionRemovedInitialEquations(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_updateBoundParameters(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_checkForAsserts(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_function_ZeroCrossings(DATA *data, threadData_t *threadData, double* gout);
extern int HVACZoneRad_function_updateRelations(DATA *data, threadData_t *threadData, int evalZeroCross);
extern const char* HVACZoneRad_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* HVACZoneRad_relationDescription(int i);
extern void HVACZoneRad_function_initSample(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_initialAnalyticJacobianG(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int HVACZoneRad_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int HVACZoneRad_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int HVACZoneRad_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int HVACZoneRad_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int HVACZoneRad_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int HVACZoneRad_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int HVACZoneRad_functionJacG_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int HVACZoneRad_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int HVACZoneRad_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int HVACZoneRad_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int HVACZoneRad_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int HVACZoneRad_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int HVACZoneRad_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern const char* HVACZoneRad_linear_model_frame(void);
extern const char* HVACZoneRad_linear_model_datarecovery_frame(void);
extern int HVACZoneRad_mayer(DATA* data, modelica_real** res, short *);
extern int HVACZoneRad_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int HVACZoneRad_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int HVACZoneRad_setInputData(DATA *data, const modelica_boolean file);
extern int HVACZoneRad_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
extern void HVACZoneRad_function_initSynchronous(DATA * data, threadData_t *threadData);
extern void HVACZoneRad_function_updateSynchronous(DATA * data, threadData_t *threadData, long base_idx);
extern int HVACZoneRad_function_equationsSynchronous(DATA * data, threadData_t *threadData, long base_idx, long sub_idx);
extern void HVACZoneRad_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationData);
extern void HVACZoneRad_function_savePreSynchronous(DATA *data, threadData_t *threadData);
extern int HVACZoneRad_inputNames(DATA* data, char ** names);
extern int HVACZoneRad_dataReconciliationInputNames(DATA* data, char ** names);
extern int HVACZoneRad_dataReconciliationUnmeasuredVariables(DATA* data, char ** names);
extern int HVACZoneRad_initializeDAEmodeData(DATA *data, DAEMODE_DATA*);
extern int HVACZoneRad_functionLocalKnownVars(DATA* data, threadData_t* threadData);
extern int HVACZoneRad_symbolicInlineSystem(DATA* data, threadData_t* threadData);

#include "HVACZoneRad_literals.h"




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

#endif /* !defined(HVACZoneRad__MODEL_H) */

