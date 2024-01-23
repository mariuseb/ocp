#ifndef TwoWayValve__H
#define TwoWayValve__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  modelica_real _p;
  modelica_real _T;
} TwoWayValve_sin_Medium_ThermodynamicState;
extern struct record_description TwoWayValve_sin_Medium_ThermodynamicState__desc;

void TwoWayValve_sin_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define TwoWayValve_sin_Medium_ThermodynamicState_construct(td, ths ) TwoWayValve_sin_Medium_ThermodynamicState_construct_p(td, &ths )
void TwoWayValve_sin_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define TwoWayValve_sin_Medium_ThermodynamicState_copy(src,dst) TwoWayValve_sin_Medium_ThermodynamicState_copy_p(&src, &dst)


void TwoWayValve_sin_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T);
#define TwoWayValve_sin_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T) TwoWayValve_sin_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void TwoWayValve_sin_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T);
// #define TwoWayValve_sin_Medium_ThermodynamicState_copy_to_vars(src,...) TwoWayValve_sin_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t TwoWayValve_sin_Medium_ThermodynamicState_array;
#define alloc_TwoWayValve_sin_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, TwoWayValve_sin_Medium_ThermodynamicState_construct_p, ndims, sizeof(TwoWayValve_sin_Medium_ThermodynamicState), __VA_ARGS__)
#define TwoWayValve_sin_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, TwoWayValve_sin_Medium_ThermodynamicState_copy_p, sizeof(TwoWayValve_sin_Medium_ThermodynamicState))
#define TwoWayValve_sin_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, TwoWayValve_sin_Medium_ThermodynamicState_copy_p, sizeof(TwoWayValve_sin_Medium_ThermodynamicState))
#define TwoWayValve_sin_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(TwoWayValve_sin_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(TwoWayValve_sin_Medium_ThermodynamicState), __VA_ARGS__)))
#define TwoWayValve_sin_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, TwoWayValve_sin_Medium_ThermodynamicState_copy_p, sizeof(TwoWayValve_sin_Medium_ThermodynamicState), __VA_ARGS__)

typedef TwoWayValve_sin_Medium_ThermodynamicState TwoWayValve_sou_Medium_ThermodynamicState;
extern struct record_description TwoWayValve_sou_Medium_ThermodynamicState__desc;

void TwoWayValve_sou_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define TwoWayValve_sou_Medium_ThermodynamicState_construct(td, ths ) TwoWayValve_sou_Medium_ThermodynamicState_construct_p(td, &ths )
void TwoWayValve_sou_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define TwoWayValve_sou_Medium_ThermodynamicState_copy(src,dst) TwoWayValve_sou_Medium_ThermodynamicState_copy_p(&src, &dst)


void TwoWayValve_sou_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T);
#define TwoWayValve_sou_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T) TwoWayValve_sou_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void TwoWayValve_sou_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T);
// #define TwoWayValve_sou_Medium_ThermodynamicState_copy_to_vars(src,...) TwoWayValve_sou_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t TwoWayValve_sou_Medium_ThermodynamicState_array;
#define alloc_TwoWayValve_sou_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, TwoWayValve_sou_Medium_ThermodynamicState_construct_p, ndims, sizeof(TwoWayValve_sou_Medium_ThermodynamicState), __VA_ARGS__)
#define TwoWayValve_sou_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, TwoWayValve_sou_Medium_ThermodynamicState_copy_p, sizeof(TwoWayValve_sou_Medium_ThermodynamicState))
#define TwoWayValve_sou_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, TwoWayValve_sou_Medium_ThermodynamicState_copy_p, sizeof(TwoWayValve_sou_Medium_ThermodynamicState))
#define TwoWayValve_sou_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(TwoWayValve_sou_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(TwoWayValve_sou_Medium_ThermodynamicState), __VA_ARGS__)))
#define TwoWayValve_sou_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, TwoWayValve_sou_Medium_ThermodynamicState_copy_p, sizeof(TwoWayValve_sou_Medium_ThermodynamicState), __VA_ARGS__)

DLLExport
modelica_real omc_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow(threadData_t *threadData, modelica_real _m_flow, modelica_real _k, modelica_real _m_flow_turbulent);
DLLExport
modelica_metatype boxptr_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow(threadData_t *threadData, modelica_metatype _m_flow, modelica_metatype _k, modelica_metatype _m_flow_turbulent);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow,2,0) {(void*) boxptr_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow,0}};
#define boxvar_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow)


DLLExport
void omc_Modelica_Fluid_Utilities_checkBoundary(threadData_t *threadData, modelica_string _mediumName, string_array _substanceNames, modelica_boolean _singleState, modelica_boolean _define_p, real_array _X_boundary, modelica_string _modelName);
DLLExport
void boxptr_Modelica_Fluid_Utilities_checkBoundary(threadData_t *threadData, modelica_metatype _mediumName, modelica_metatype _substanceNames, modelica_metatype _singleState, modelica_metatype _define_p, modelica_metatype _X_boundary, modelica_metatype _modelName);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Fluid_Utilities_checkBoundary,2,0) {(void*) boxptr_Modelica_Fluid_Utilities_checkBoundary,0}};
#define boxvar_Modelica_Fluid_Utilities_checkBoundary MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Fluid_Utilities_checkBoundary)


DLLExport
void omc_Modelica_Utilities_Streams_error(threadData_t *threadData, modelica_string _string);
#define boxptr_Modelica_Utilities_Streams_error omc_Modelica_Utilities_Streams_error
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Streams_error,2,0) {(void*) boxptr_Modelica_Utilities_Streams_error,0}};
#define boxvar_Modelica_Utilities_Streams_error MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Streams_error)

/*
 * The function has annotation(Include=...>) or is builtin
 * the external function definition should be present
 * in one of these files and have this prototype:
 * extern void ModelicaError(const char* (*_string*));
 */

DLLExport
TwoWayValve_sin_Medium_ThermodynamicState omc_TwoWayValve_sin_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T);

DLLExport
modelica_metatype boxptr_TwoWayValve_sin_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T);
static const MMC_DEFSTRUCTLIT(boxvar_lit_TwoWayValve_sin_Medium_ThermodynamicState,2,0) {(void*) boxptr_TwoWayValve_sin_Medium_ThermodynamicState,0}};
#define boxvar_TwoWayValve_sin_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_TwoWayValve_sin_Medium_ThermodynamicState)


DLLExport
TwoWayValve_sin_Medium_ThermodynamicState omc_TwoWayValve_sin_Medium_setState__pTX(threadData_t *threadData, modelica_real _p, modelica_real _T, real_array _X);
DLLExport
modelica_metatype boxptr_TwoWayValve_sin_Medium_setState__pTX(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_TwoWayValve_sin_Medium_setState__pTX,2,0) {(void*) boxptr_TwoWayValve_sin_Medium_setState__pTX,0}};
#define boxvar_TwoWayValve_sin_Medium_setState__pTX MMC_REFSTRUCTLIT(boxvar_lit_TwoWayValve_sin_Medium_setState__pTX)


DLLExport
modelica_real omc_TwoWayValve_sin_Medium_specificEnthalpy(threadData_t *threadData, TwoWayValve_sin_Medium_ThermodynamicState _state);
DLLExport
modelica_metatype boxptr_TwoWayValve_sin_Medium_specificEnthalpy(threadData_t *threadData, modelica_metatype _state);
static const MMC_DEFSTRUCTLIT(boxvar_lit_TwoWayValve_sin_Medium_specificEnthalpy,2,0) {(void*) boxptr_TwoWayValve_sin_Medium_specificEnthalpy,0}};
#define boxvar_TwoWayValve_sin_Medium_specificEnthalpy MMC_REFSTRUCTLIT(boxvar_lit_TwoWayValve_sin_Medium_specificEnthalpy)


DLLExport
TwoWayValve_sou_Medium_ThermodynamicState omc_TwoWayValve_sou_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T);

DLLExport
modelica_metatype boxptr_TwoWayValve_sou_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T);
static const MMC_DEFSTRUCTLIT(boxvar_lit_TwoWayValve_sou_Medium_ThermodynamicState,2,0) {(void*) boxptr_TwoWayValve_sou_Medium_ThermodynamicState,0}};
#define boxvar_TwoWayValve_sou_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_TwoWayValve_sou_Medium_ThermodynamicState)


DLLExport
TwoWayValve_sou_Medium_ThermodynamicState omc_TwoWayValve_sou_Medium_setState__pTX(threadData_t *threadData, modelica_real _p, modelica_real _T, real_array _X);
DLLExport
modelica_metatype boxptr_TwoWayValve_sou_Medium_setState__pTX(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_TwoWayValve_sou_Medium_setState__pTX,2,0) {(void*) boxptr_TwoWayValve_sou_Medium_setState__pTX,0}};
#define boxvar_TwoWayValve_sou_Medium_setState__pTX MMC_REFSTRUCTLIT(boxvar_lit_TwoWayValve_sou_Medium_setState__pTX)


DLLExport
modelica_real omc_TwoWayValve_sou_Medium_specificEnthalpy(threadData_t *threadData, TwoWayValve_sou_Medium_ThermodynamicState _state);
DLLExport
modelica_metatype boxptr_TwoWayValve_sou_Medium_specificEnthalpy(threadData_t *threadData, modelica_metatype _state);
static const MMC_DEFSTRUCTLIT(boxvar_lit_TwoWayValve_sou_Medium_specificEnthalpy,2,0) {(void*) boxptr_TwoWayValve_sou_Medium_specificEnthalpy,0}};
#define boxvar_TwoWayValve_sou_Medium_specificEnthalpy MMC_REFSTRUCTLIT(boxvar_lit_TwoWayValve_sou_Medium_specificEnthalpy)
#include "TwoWayValve_model.h"


#ifdef __cplusplus
}
#endif
#endif

