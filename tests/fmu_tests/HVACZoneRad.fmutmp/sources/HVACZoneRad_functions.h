#ifndef HVACZoneRad__H
#define HVACZoneRad__H
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
  real_array _V_flow;
  real_array _eta;
} Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters;
extern struct record_description Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters__desc;

void Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_construct_p(threadData_t *threadData, void* v_ths );
#define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_construct(td, ths ) Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_construct_p(td, &ths )
void Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_copy_p(void* v_src, void* v_dst);
#define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_copy(src,dst) Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_copy_p(&src, &dst)


void Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_wrap_vars_p(threadData_t *threadData , void* v_dst , real_array in_V_flow, real_array in_eta);
#define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_wrap_vars(td, dst , in_V_flow, in_eta) Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_wrap_vars_p(td, &dst , in_V_flow, in_eta)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_copy_to_vars_p(void* v_src , real_array* in_V_flow, real_array* in_eta);
// #define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_copy_to_vars(src,...) Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_array;
#define alloc_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_array(dst,ndims,...) generic_array_create(NULL, dst, Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_construct_p, ndims, sizeof(Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters), __VA_ARGS__)
#define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_copy_p, sizeof(Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters))
#define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_copy_p, sizeof(Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters))
#define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_array_get(src,ndims,...)   (*(Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters*)(generic_array_get(&src, sizeof(Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters), __VA_ARGS__)))
#define Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_set(dst,val,...)           generic_array_set(&dst, &val, Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters_copy_p, sizeof(Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters), __VA_ARGS__)

typedef struct {
  modelica_real _p;
  modelica_real _T;
} HVACZoneRad_bou_Medium_ThermodynamicState;
extern struct record_description HVACZoneRad_bou_Medium_ThermodynamicState__desc;

void HVACZoneRad_bou_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define HVACZoneRad_bou_Medium_ThermodynamicState_construct(td, ths ) HVACZoneRad_bou_Medium_ThermodynamicState_construct_p(td, &ths )
void HVACZoneRad_bou_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define HVACZoneRad_bou_Medium_ThermodynamicState_copy(src,dst) HVACZoneRad_bou_Medium_ThermodynamicState_copy_p(&src, &dst)


void HVACZoneRad_bou_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T);
#define HVACZoneRad_bou_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T) HVACZoneRad_bou_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void HVACZoneRad_bou_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T);
// #define HVACZoneRad_bou_Medium_ThermodynamicState_copy_to_vars(src,...) HVACZoneRad_bou_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t HVACZoneRad_bou_Medium_ThermodynamicState_array;
#define alloc_HVACZoneRad_bou_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, HVACZoneRad_bou_Medium_ThermodynamicState_construct_p, ndims, sizeof(HVACZoneRad_bou_Medium_ThermodynamicState), __VA_ARGS__)
#define HVACZoneRad_bou_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, HVACZoneRad_bou_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_bou_Medium_ThermodynamicState))
#define HVACZoneRad_bou_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, HVACZoneRad_bou_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_bou_Medium_ThermodynamicState))
#define HVACZoneRad_bou_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(HVACZoneRad_bou_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(HVACZoneRad_bou_Medium_ThermodynamicState), __VA_ARGS__)))
#define HVACZoneRad_bou_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, HVACZoneRad_bou_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_bou_Medium_ThermodynamicState), __VA_ARGS__)

typedef struct {
  modelica_real _p;
  modelica_real _T;
  real_array _X;
} HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState;
extern struct record_description HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState__desc;

void HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_construct(td, ths ) HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_construct_p(td, &ths )
void HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_copy(src,dst) HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_copy_p(&src, &dst)


void HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T, real_array in_X);
#define HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T, in_X) HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T, in_X)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T, real_array* in_X);
// #define HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_copy_to_vars(src,...) HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_array;
#define alloc_HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_construct_p, ndims, sizeof(HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState), __VA_ARGS__)
#define HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState))
#define HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState))
#define HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState), __VA_ARGS__)))
#define HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState), __VA_ARGS__)

typedef HVACZoneRad_bou_Medium_ThermodynamicState HVACZoneRad_hea_outCon_Medium_ThermodynamicState;
extern struct record_description HVACZoneRad_hea_outCon_Medium_ThermodynamicState__desc;

void HVACZoneRad_hea_outCon_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define HVACZoneRad_hea_outCon_Medium_ThermodynamicState_construct(td, ths ) HVACZoneRad_hea_outCon_Medium_ThermodynamicState_construct_p(td, &ths )
void HVACZoneRad_hea_outCon_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define HVACZoneRad_hea_outCon_Medium_ThermodynamicState_copy(src,dst) HVACZoneRad_hea_outCon_Medium_ThermodynamicState_copy_p(&src, &dst)


void HVACZoneRad_hea_outCon_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T);
#define HVACZoneRad_hea_outCon_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T) HVACZoneRad_hea_outCon_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void HVACZoneRad_hea_outCon_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T);
// #define HVACZoneRad_hea_outCon_Medium_ThermodynamicState_copy_to_vars(src,...) HVACZoneRad_hea_outCon_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t HVACZoneRad_hea_outCon_Medium_ThermodynamicState_array;
#define alloc_HVACZoneRad_hea_outCon_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, HVACZoneRad_hea_outCon_Medium_ThermodynamicState_construct_p, ndims, sizeof(HVACZoneRad_hea_outCon_Medium_ThermodynamicState), __VA_ARGS__)
#define HVACZoneRad_hea_outCon_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, HVACZoneRad_hea_outCon_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_hea_outCon_Medium_ThermodynamicState))
#define HVACZoneRad_hea_outCon_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, HVACZoneRad_hea_outCon_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_hea_outCon_Medium_ThermodynamicState))
#define HVACZoneRad_hea_outCon_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(HVACZoneRad_hea_outCon_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(HVACZoneRad_hea_outCon_Medium_ThermodynamicState), __VA_ARGS__)))
#define HVACZoneRad_hea_outCon_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, HVACZoneRad_hea_outCon_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_hea_outCon_Medium_ThermodynamicState), __VA_ARGS__)

typedef HVACZoneRad_bou_Medium_ThermodynamicState HVACZoneRad_pump_Medium_ThermodynamicState;
extern struct record_description HVACZoneRad_pump_Medium_ThermodynamicState__desc;

void HVACZoneRad_pump_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define HVACZoneRad_pump_Medium_ThermodynamicState_construct(td, ths ) HVACZoneRad_pump_Medium_ThermodynamicState_construct_p(td, &ths )
void HVACZoneRad_pump_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define HVACZoneRad_pump_Medium_ThermodynamicState_copy(src,dst) HVACZoneRad_pump_Medium_ThermodynamicState_copy_p(&src, &dst)


void HVACZoneRad_pump_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T);
#define HVACZoneRad_pump_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T) HVACZoneRad_pump_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void HVACZoneRad_pump_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T);
// #define HVACZoneRad_pump_Medium_ThermodynamicState_copy_to_vars(src,...) HVACZoneRad_pump_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t HVACZoneRad_pump_Medium_ThermodynamicState_array;
#define alloc_HVACZoneRad_pump_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, HVACZoneRad_pump_Medium_ThermodynamicState_construct_p, ndims, sizeof(HVACZoneRad_pump_Medium_ThermodynamicState), __VA_ARGS__)
#define HVACZoneRad_pump_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, HVACZoneRad_pump_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_pump_Medium_ThermodynamicState))
#define HVACZoneRad_pump_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, HVACZoneRad_pump_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_pump_Medium_ThermodynamicState))
#define HVACZoneRad_pump_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(HVACZoneRad_pump_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(HVACZoneRad_pump_Medium_ThermodynamicState), __VA_ARGS__)))
#define HVACZoneRad_pump_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, HVACZoneRad_pump_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_pump_Medium_ThermodynamicState), __VA_ARGS__)

typedef HVACZoneRad_bou_Medium_ThermodynamicState HVACZoneRad_pump_preSou_Medium_ThermodynamicState;
extern struct record_description HVACZoneRad_pump_preSou_Medium_ThermodynamicState__desc;

void HVACZoneRad_pump_preSou_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define HVACZoneRad_pump_preSou_Medium_ThermodynamicState_construct(td, ths ) HVACZoneRad_pump_preSou_Medium_ThermodynamicState_construct_p(td, &ths )
void HVACZoneRad_pump_preSou_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define HVACZoneRad_pump_preSou_Medium_ThermodynamicState_copy(src,dst) HVACZoneRad_pump_preSou_Medium_ThermodynamicState_copy_p(&src, &dst)


void HVACZoneRad_pump_preSou_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T);
#define HVACZoneRad_pump_preSou_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T) HVACZoneRad_pump_preSou_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void HVACZoneRad_pump_preSou_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T);
// #define HVACZoneRad_pump_preSou_Medium_ThermodynamicState_copy_to_vars(src,...) HVACZoneRad_pump_preSou_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t HVACZoneRad_pump_preSou_Medium_ThermodynamicState_array;
#define alloc_HVACZoneRad_pump_preSou_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, HVACZoneRad_pump_preSou_Medium_ThermodynamicState_construct_p, ndims, sizeof(HVACZoneRad_pump_preSou_Medium_ThermodynamicState), __VA_ARGS__)
#define HVACZoneRad_pump_preSou_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, HVACZoneRad_pump_preSou_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_pump_preSou_Medium_ThermodynamicState))
#define HVACZoneRad_pump_preSou_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, HVACZoneRad_pump_preSou_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_pump_preSou_Medium_ThermodynamicState))
#define HVACZoneRad_pump_preSou_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(HVACZoneRad_pump_preSou_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(HVACZoneRad_pump_preSou_Medium_ThermodynamicState), __VA_ARGS__)))
#define HVACZoneRad_pump_preSou_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, HVACZoneRad_pump_preSou_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_pump_preSou_Medium_ThermodynamicState), __VA_ARGS__)

typedef HVACZoneRad_bou_Medium_ThermodynamicState HVACZoneRad_rad_Medium_ThermodynamicState;
extern struct record_description HVACZoneRad_rad_Medium_ThermodynamicState__desc;

void HVACZoneRad_rad_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define HVACZoneRad_rad_Medium_ThermodynamicState_construct(td, ths ) HVACZoneRad_rad_Medium_ThermodynamicState_construct_p(td, &ths )
void HVACZoneRad_rad_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define HVACZoneRad_rad_Medium_ThermodynamicState_copy(src,dst) HVACZoneRad_rad_Medium_ThermodynamicState_copy_p(&src, &dst)


void HVACZoneRad_rad_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T);
#define HVACZoneRad_rad_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T) HVACZoneRad_rad_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void HVACZoneRad_rad_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T);
// #define HVACZoneRad_rad_Medium_ThermodynamicState_copy_to_vars(src,...) HVACZoneRad_rad_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t HVACZoneRad_rad_Medium_ThermodynamicState_array;
#define alloc_HVACZoneRad_rad_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, HVACZoneRad_rad_Medium_ThermodynamicState_construct_p, ndims, sizeof(HVACZoneRad_rad_Medium_ThermodynamicState), __VA_ARGS__)
#define HVACZoneRad_rad_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, HVACZoneRad_rad_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_rad_Medium_ThermodynamicState))
#define HVACZoneRad_rad_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, HVACZoneRad_rad_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_rad_Medium_ThermodynamicState))
#define HVACZoneRad_rad_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(HVACZoneRad_rad_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(HVACZoneRad_rad_Medium_ThermodynamicState), __VA_ARGS__)))
#define HVACZoneRad_rad_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, HVACZoneRad_rad_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_rad_Medium_ThermodynamicState), __VA_ARGS__)

typedef HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState HVACZoneRad_hvacAda_con_Medium_ThermodynamicState;
extern struct record_description HVACZoneRad_hvacAda_con_Medium_ThermodynamicState__desc;

void HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_construct(td, ths ) HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_construct_p(td, &ths )
void HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_copy(src,dst) HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_copy_p(&src, &dst)


void HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T, real_array in_X);
#define HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T, in_X) HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T, in_X)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T, real_array* in_X);
// #define HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_copy_to_vars(src,...) HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_array;
#define alloc_HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_construct_p, ndims, sizeof(HVACZoneRad_hvacAda_con_Medium_ThermodynamicState), __VA_ARGS__)
#define HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_hvacAda_con_Medium_ThermodynamicState))
#define HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_hvacAda_con_Medium_ThermodynamicState))
#define HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(HVACZoneRad_hvacAda_con_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(HVACZoneRad_hvacAda_con_Medium_ThermodynamicState), __VA_ARGS__)))
#define HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, HVACZoneRad_hvacAda_con_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_hvacAda_con_Medium_ThermodynamicState), __VA_ARGS__)

typedef HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState HVACZoneRad_vol_Medium_ThermodynamicState;
extern struct record_description HVACZoneRad_vol_Medium_ThermodynamicState__desc;

void HVACZoneRad_vol_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define HVACZoneRad_vol_Medium_ThermodynamicState_construct(td, ths ) HVACZoneRad_vol_Medium_ThermodynamicState_construct_p(td, &ths )
void HVACZoneRad_vol_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define HVACZoneRad_vol_Medium_ThermodynamicState_copy(src,dst) HVACZoneRad_vol_Medium_ThermodynamicState_copy_p(&src, &dst)


void HVACZoneRad_vol_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T, real_array in_X);
#define HVACZoneRad_vol_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T, in_X) HVACZoneRad_vol_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T, in_X)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void HVACZoneRad_vol_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T, real_array* in_X);
// #define HVACZoneRad_vol_Medium_ThermodynamicState_copy_to_vars(src,...) HVACZoneRad_vol_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t HVACZoneRad_vol_Medium_ThermodynamicState_array;
#define alloc_HVACZoneRad_vol_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, HVACZoneRad_vol_Medium_ThermodynamicState_construct_p, ndims, sizeof(HVACZoneRad_vol_Medium_ThermodynamicState), __VA_ARGS__)
#define HVACZoneRad_vol_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, HVACZoneRad_vol_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_vol_Medium_ThermodynamicState))
#define HVACZoneRad_vol_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, HVACZoneRad_vol_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_vol_Medium_ThermodynamicState))
#define HVACZoneRad_vol_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(HVACZoneRad_vol_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(HVACZoneRad_vol_Medium_ThermodynamicState), __VA_ARGS__)))
#define HVACZoneRad_vol_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, HVACZoneRad_vol_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_vol_Medium_ThermodynamicState), __VA_ARGS__)

typedef HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState HVACZoneRad_vol_dynBal_Medium_ThermodynamicState;
extern struct record_description HVACZoneRad_vol_dynBal_Medium_ThermodynamicState__desc;

void HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_construct_p(threadData_t *threadData, void* v_ths );
#define HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_construct(td, ths ) HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_construct_p(td, &ths )
void HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_copy_p(void* v_src, void* v_dst);
#define HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_copy(src,dst) HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_copy_p(&src, &dst)


void HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_wrap_vars_p(threadData_t *threadData , void* v_dst , modelica_real in_p, modelica_real in_T, real_array in_X);
#define HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_wrap_vars(td, dst , in_p, in_T, in_X) HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_wrap_vars_p(td, &dst , in_p, in_T, in_X)

// This function is not needed anymore. If you want to know how a record
// is 'assigned to' in simulation context see assignRhsExpToRecordCrefSimContext and
// splitRecordAssignmentToMemberAssignments (simCode). Basically the record is
// split up assignments generated for each member individually.
// void HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_copy_to_vars_p(void* v_src , modelica_real* in_p, modelica_real* in_T, real_array* in_X);
// #define HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_copy_to_vars(src,...) HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_copy_to_vars_p(&src, __VA_ARGS__)

typedef base_array_t HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_array;
#define alloc_HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_array(dst,ndims,...) generic_array_create(NULL, dst, HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_construct_p, ndims, sizeof(HVACZoneRad_vol_dynBal_Medium_ThermodynamicState), __VA_ARGS__)
#define HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_array_copy_data(src,dst)   generic_array_copy_data(src, &dst, HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_vol_dynBal_Medium_ThermodynamicState))
#define HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_array_alloc_copy(src,dst)  generic_array_alloc_copy(src, &dst, HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_vol_dynBal_Medium_ThermodynamicState))
#define HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_array_get(src,ndims,...)   (*(HVACZoneRad_vol_dynBal_Medium_ThermodynamicState*)(generic_array_get(&src, sizeof(HVACZoneRad_vol_dynBal_Medium_ThermodynamicState), __VA_ARGS__)))
#define HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_set(dst,val,...)           generic_array_set(&dst, &val, HVACZoneRad_vol_dynBal_Medium_ThermodynamicState_copy_p, sizeof(HVACZoneRad_vol_dynBal_Medium_ThermodynamicState), __VA_ARGS__)

DLLExport
modelica_real omc__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fdp(threadData_t *threadData, modelica_real _dp, modelica_real _k, modelica_real _m_flow_turbulent, modelica_real __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fdp_24funDERdp, modelica_real __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fdp_24funDERk, modelica_real __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fdp_24funDERm_5Fflow_5Fturbulent);
DLLExport
modelica_metatype boxptr__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fdp(threadData_t *threadData, modelica_metatype _dp, modelica_metatype _k, modelica_metatype _m_flow_turbulent, modelica_metatype __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fdp_24funDERdp, modelica_metatype __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fdp_24funDERk, modelica_metatype __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fdp_24funDERm_5Fflow_5Fturbulent);
static const MMC_DEFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fdp,2,0) {(void*) boxptr__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fdp,0}};
#define boxvar__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fdp MMC_REFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fdp)


DLLExport
modelica_real omc__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fm_5F_5Fflow(threadData_t *threadData, modelica_real _m_flow, modelica_real _k, modelica_real _m_flow_turbulent, modelica_real __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fm_5Fflow_24funDERm_5Fflow, modelica_real __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fm_5Fflow_24funDERk, modelica_real __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fm_5Fflow_24funDERm_5Fflow_5Fturbulent);
DLLExport
modelica_metatype boxptr__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fm_5F_5Fflow(threadData_t *threadData, modelica_metatype _m_flow, modelica_metatype _k, modelica_metatype _m_flow_turbulent, modelica_metatype __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fm_5Fflow_24funDERm_5Fflow, modelica_metatype __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fm_5Fflow_24funDERk, modelica_metatype __omcQ_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5Fm_5Fflow_24funDERm_5Fflow_5Fturbulent);
static const MMC_DEFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fm_5F_5Fflow,2,0) {(void*) boxptr__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fm_5F_5Fflow,0}};
#define boxvar__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fm_5F_5Fflow MMC_REFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fm_5F_5Fflow)


DLLExport
modelica_real omc__omcQ_24DER_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency(threadData_t *threadData, Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters _per, modelica_real _V_flow, real_array _d, modelica_real _r_N, modelica_real _delta, Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERper, modelica_real __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERV_5Fflow, real_array __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERd, modelica_real __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERr_5FN, modelica_real __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERdelta);
DLLExport
modelica_metatype boxptr__omcQ_24DER_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency(threadData_t *threadData, modelica_metatype _per, modelica_metatype _V_flow, modelica_metatype _d, modelica_metatype _r_N, modelica_metatype _delta, modelica_metatype __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERper, modelica_metatype __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERV_5Fflow, modelica_metatype __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERd, modelica_metatype __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERr_5FN, modelica_metatype __omcQ_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency_24funDERdelta);
static const MMC_DEFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency,2,0) {(void*) boxptr__omcQ_24DER_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency,0}};
#define boxvar__omcQ_24DER_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency MMC_REFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Buildings_24PFluid_24PMovers_24PBaseClasses_24PCharacteristics_24Pefficiency)


DLLExport
modelica_real omc__omcQ_24DER_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation(threadData_t *threadData, modelica_real _x, modelica_real _x1, modelica_real _x2, modelica_real _y1, modelica_real _y2, modelica_real _y1d, modelica_real _y2d, modelica_real __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERx, modelica_real __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERx1, modelica_real __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERx2, modelica_real __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERy1, modelica_real __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERy2, modelica_real __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERy1d, modelica_real __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERy2d);
DLLExport
modelica_metatype boxptr__omcQ_24DER_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x1, modelica_metatype _x2, modelica_metatype _y1, modelica_metatype _y2, modelica_metatype _y1d, modelica_metatype _y2d, modelica_metatype __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERx, modelica_metatype __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERx1, modelica_metatype __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERx2, modelica_metatype __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERy1, modelica_metatype __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERy2, modelica_metatype __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERy1d, modelica_metatype __omcQ_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation_24funDERy2d);
static const MMC_DEFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation,2,0) {(void*) boxptr__omcQ_24DER_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation,0}};
#define boxvar__omcQ_24DER_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation MMC_REFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Buildings_24PUtilities_24PMath_24PFunctions_24PcubicHermiteLinearExtrapolation)


DLLExport
modelica_real omc__omcQ_24DER_24Modelica_24PFluid_24PUtilities_24PcubicHermite(threadData_t *threadData, modelica_real _x, modelica_real _x1, modelica_real _x2, modelica_real _y1, modelica_real _y2, modelica_real _y1d, modelica_real _y2d, modelica_real __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERx, modelica_real __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERx1, modelica_real __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERx2, modelica_real __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERy1, modelica_real __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERy2, modelica_real __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERy1d, modelica_real __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERy2d);
DLLExport
modelica_metatype boxptr__omcQ_24DER_24Modelica_24PFluid_24PUtilities_24PcubicHermite(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x1, modelica_metatype _x2, modelica_metatype _y1, modelica_metatype _y2, modelica_metatype _y1d, modelica_metatype _y2d, modelica_metatype __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERx, modelica_metatype __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERx1, modelica_metatype __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERx2, modelica_metatype __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERy1, modelica_metatype __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERy2, modelica_metatype __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERy1d, modelica_metatype __omcQ_24Modelica_24PFluid_24PUtilities_24PcubicHermite_24funDERy2d);
static const MMC_DEFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Modelica_24PFluid_24PUtilities_24PcubicHermite,2,0) {(void*) boxptr__omcQ_24DER_24Modelica_24PFluid_24PUtilities_24PcubicHermite,0}};
#define boxvar__omcQ_24DER_24Modelica_24PFluid_24PUtilities_24PcubicHermite MMC_REFSTRUCTLIT(boxvar_lit__omcQ_24DER_24Modelica_24PFluid_24PUtilities_24PcubicHermite)


DLLExport
modelica_real omc_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__dp(threadData_t *threadData, modelica_real _dp, modelica_real _k, modelica_real _m_flow_turbulent);
DLLExport
modelica_metatype boxptr_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__dp(threadData_t *threadData, modelica_metatype _dp, modelica_metatype _k, modelica_metatype _m_flow_turbulent);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__dp,2,0) {(void*) boxptr_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__dp,0}};
#define boxvar_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__dp MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__dp)


DLLExport
modelica_real omc_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow(threadData_t *threadData, modelica_real _m_flow, modelica_real _k, modelica_real _m_flow_turbulent);
DLLExport
modelica_metatype boxptr_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow(threadData_t *threadData, modelica_metatype _m_flow, modelica_metatype _k, modelica_metatype _m_flow_turbulent);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow,2,0) {(void*) boxptr_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow,0}};
#define boxvar_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow)


DLLExport
modelica_real omc_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiency(threadData_t *threadData, Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters _per, modelica_real _V_flow, real_array _d, modelica_real _r_N, modelica_real _delta);
DLLExport
modelica_metatype boxptr_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiency(threadData_t *threadData, modelica_metatype _per, modelica_metatype _V_flow, modelica_metatype _d, modelica_metatype _r_N, modelica_metatype _delta);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiency,2,0) {(void*) boxptr_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiency,0}};
#define boxvar_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiency MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiency)


DLLExport
Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters omc_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters (threadData_t *threadData, real_array omc_V_flow, real_array omc_eta);

DLLExport
modelica_metatype boxptr_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters(threadData_t *threadData, modelica_metatype _V_flow, modelica_metatype _eta);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters,2,0) {(void*) boxptr_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters,0}};
#define boxvar_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Fluid_Movers_BaseClasses_Characteristics_efficiencyParameters)


DLLExport
modelica_real omc_Buildings_Utilities_Math_Functions_cubicHermiteLinearExtrapolation(threadData_t *threadData, modelica_real _x, modelica_real _x1, modelica_real _x2, modelica_real _y1, modelica_real _y2, modelica_real _y1d, modelica_real _y2d);
DLLExport
modelica_metatype boxptr_Buildings_Utilities_Math_Functions_cubicHermiteLinearExtrapolation(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x1, modelica_metatype _x2, modelica_metatype _y1, modelica_metatype _y2, modelica_metatype _y1d, modelica_metatype _y2d);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_cubicHermiteLinearExtrapolation,2,0) {(void*) boxptr_Buildings_Utilities_Math_Functions_cubicHermiteLinearExtrapolation,0}};
#define boxvar_Buildings_Utilities_Math_Functions_cubicHermiteLinearExtrapolation MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_cubicHermiteLinearExtrapolation)


DLLExport
modelica_real omc_Buildings_Utilities_Math_Functions_regNonZeroPower(threadData_t *threadData, modelica_real _x, modelica_real _n, modelica_real _delta);
DLLExport
modelica_metatype boxptr_Buildings_Utilities_Math_Functions_regNonZeroPower(threadData_t *threadData, modelica_metatype _x, modelica_metatype _n, modelica_metatype _delta);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_regNonZeroPower,2,0) {(void*) boxptr_Buildings_Utilities_Math_Functions_regNonZeroPower,0}};
#define boxvar_Buildings_Utilities_Math_Functions_regNonZeroPower MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_regNonZeroPower)


DLLExport
modelica_real omc_Buildings_Utilities_Math_Functions_regStep(threadData_t *threadData, modelica_real _x, modelica_real _y1, modelica_real _y2, modelica_real _x_small);
DLLExport
modelica_metatype boxptr_Buildings_Utilities_Math_Functions_regStep(threadData_t *threadData, modelica_metatype _x, modelica_metatype _y1, modelica_metatype _y2, modelica_metatype _x_small);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_regStep,2,0) {(void*) boxptr_Buildings_Utilities_Math_Functions_regStep,0}};
#define boxvar_Buildings_Utilities_Math_Functions_regStep MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_regStep)


DLLExport
modelica_real omc_Buildings_Utilities_Math_Functions_smoothMax(threadData_t *threadData, modelica_real _x1, modelica_real _x2, modelica_real _deltaX);
DLLExport
modelica_metatype boxptr_Buildings_Utilities_Math_Functions_smoothMax(threadData_t *threadData, modelica_metatype _x1, modelica_metatype _x2, modelica_metatype _deltaX);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_smoothMax,2,0) {(void*) boxptr_Buildings_Utilities_Math_Functions_smoothMax,0}};
#define boxvar_Buildings_Utilities_Math_Functions_smoothMax MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_smoothMax)


DLLExport
modelica_real omc_Buildings_Utilities_Math_Functions_BaseClasses_der__regNonZeroPower(threadData_t *threadData, modelica_real _x, modelica_real _n, modelica_real _delta, modelica_real _der_x);
DLLExport
modelica_metatype boxptr_Buildings_Utilities_Math_Functions_BaseClasses_der__regNonZeroPower(threadData_t *threadData, modelica_metatype _x, modelica_metatype _n, modelica_metatype _delta, modelica_metatype _der_x);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_BaseClasses_der__regNonZeroPower,2,0) {(void*) boxptr_Buildings_Utilities_Math_Functions_BaseClasses_der__regNonZeroPower,0}};
#define boxvar_Buildings_Utilities_Math_Functions_BaseClasses_der__regNonZeroPower MMC_REFSTRUCTLIT(boxvar_lit_Buildings_Utilities_Math_Functions_BaseClasses_der__regNonZeroPower)


DLLExport
HVACZoneRad_bou_Medium_ThermodynamicState omc_HVACZoneRad_bou_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T);

DLLExport
modelica_metatype boxptr_HVACZoneRad_bou_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_bou_Medium_ThermodynamicState,2,0) {(void*) boxptr_HVACZoneRad_bou_Medium_ThermodynamicState,0}};
#define boxvar_HVACZoneRad_bou_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_bou_Medium_ThermodynamicState)


DLLExport
HVACZoneRad_bou_Medium_ThermodynamicState omc_HVACZoneRad_bou_Medium_setState__pTX(threadData_t *threadData, modelica_real _p, modelica_real _T, real_array _X);
DLLExport
modelica_metatype boxptr_HVACZoneRad_bou_Medium_setState__pTX(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_bou_Medium_setState__pTX,2,0) {(void*) boxptr_HVACZoneRad_bou_Medium_setState__pTX,0}};
#define boxvar_HVACZoneRad_bou_Medium_setState__pTX MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_bou_Medium_setState__pTX)


DLLExport
modelica_real omc_HVACZoneRad_bou_Medium_specificEnthalpy(threadData_t *threadData, HVACZoneRad_bou_Medium_ThermodynamicState _state);
DLLExport
modelica_metatype boxptr_HVACZoneRad_bou_Medium_specificEnthalpy(threadData_t *threadData, modelica_metatype _state);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_bou_Medium_specificEnthalpy,2,0) {(void*) boxptr_HVACZoneRad_bou_Medium_specificEnthalpy,0}};
#define boxvar_HVACZoneRad_bou_Medium_specificEnthalpy MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_bou_Medium_specificEnthalpy)


DLLExport
HVACZoneRad_hea_outCon_Medium_ThermodynamicState omc_HVACZoneRad_hea_outCon_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T);

DLLExport
modelica_metatype boxptr_HVACZoneRad_hea_outCon_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_hea_outCon_Medium_ThermodynamicState,2,0) {(void*) boxptr_HVACZoneRad_hea_outCon_Medium_ThermodynamicState,0}};
#define boxvar_HVACZoneRad_hea_outCon_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_hea_outCon_Medium_ThermodynamicState)


DLLExport
HVACZoneRad_hea_outCon_Medium_ThermodynamicState omc_HVACZoneRad_hea_outCon_Medium_setState__pTX(threadData_t *threadData, modelica_real _p, modelica_real _T, real_array _X);
DLLExport
modelica_metatype boxptr_HVACZoneRad_hea_outCon_Medium_setState__pTX(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_hea_outCon_Medium_setState__pTX,2,0) {(void*) boxptr_HVACZoneRad_hea_outCon_Medium_setState__pTX,0}};
#define boxvar_HVACZoneRad_hea_outCon_Medium_setState__pTX MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_hea_outCon_Medium_setState__pTX)


DLLExport
modelica_real omc_HVACZoneRad_hea_outCon_Medium_specificEnthalpy(threadData_t *threadData, HVACZoneRad_hea_outCon_Medium_ThermodynamicState _state);
DLLExport
modelica_metatype boxptr_HVACZoneRad_hea_outCon_Medium_specificEnthalpy(threadData_t *threadData, modelica_metatype _state);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_hea_outCon_Medium_specificEnthalpy,2,0) {(void*) boxptr_HVACZoneRad_hea_outCon_Medium_specificEnthalpy,0}};
#define boxvar_HVACZoneRad_hea_outCon_Medium_specificEnthalpy MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_hea_outCon_Medium_specificEnthalpy)


DLLExport
HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState omc_HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T, real_array omc_X);

DLLExport
modelica_metatype boxptr_HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState,2,0) {(void*) boxptr_HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState,0}};
#define boxvar_HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_hvacAda_bou_Medium_ThermodynamicState)


DLLExport
HVACZoneRad_hvacAda_con_Medium_ThermodynamicState omc_HVACZoneRad_hvacAda_con_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T, real_array omc_X);

DLLExport
modelica_metatype boxptr_HVACZoneRad_hvacAda_con_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_hvacAda_con_Medium_ThermodynamicState,2,0) {(void*) boxptr_HVACZoneRad_hvacAda_con_Medium_ThermodynamicState,0}};
#define boxvar_HVACZoneRad_hvacAda_con_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_hvacAda_con_Medium_ThermodynamicState)


DLLExport
HVACZoneRad_pump_Medium_ThermodynamicState omc_HVACZoneRad_pump_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T);

DLLExport
modelica_metatype boxptr_HVACZoneRad_pump_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_Medium_ThermodynamicState,2,0) {(void*) boxptr_HVACZoneRad_pump_Medium_ThermodynamicState,0}};
#define boxvar_HVACZoneRad_pump_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_Medium_ThermodynamicState)


DLLExport
HVACZoneRad_pump_preSou_Medium_ThermodynamicState omc_HVACZoneRad_pump_preSou_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T);

DLLExport
modelica_metatype boxptr_HVACZoneRad_pump_preSou_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_preSou_Medium_ThermodynamicState,2,0) {(void*) boxptr_HVACZoneRad_pump_preSou_Medium_ThermodynamicState,0}};
#define boxvar_HVACZoneRad_pump_preSou_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_preSou_Medium_ThermodynamicState)


DLLExport
modelica_real omc_HVACZoneRad_pump_preSou_Medium_density(threadData_t *threadData, HVACZoneRad_pump_preSou_Medium_ThermodynamicState _state);
DLLExport
modelica_metatype boxptr_HVACZoneRad_pump_preSou_Medium_density(threadData_t *threadData, modelica_metatype _state);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_preSou_Medium_density,2,0) {(void*) boxptr_HVACZoneRad_pump_preSou_Medium_density,0}};
#define boxvar_HVACZoneRad_pump_preSou_Medium_density MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_preSou_Medium_density)


DLLExport
HVACZoneRad_pump_preSou_Medium_ThermodynamicState omc_HVACZoneRad_pump_preSou_Medium_setState__phX(threadData_t *threadData, modelica_real _p, modelica_real _h, real_array _X);
DLLExport
modelica_metatype boxptr_HVACZoneRad_pump_preSou_Medium_setState__phX(threadData_t *threadData, modelica_metatype _p, modelica_metatype _h, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_preSou_Medium_setState__phX,2,0) {(void*) boxptr_HVACZoneRad_pump_preSou_Medium_setState__phX,0}};
#define boxvar_HVACZoneRad_pump_preSou_Medium_setState__phX MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_preSou_Medium_setState__phX)


DLLExport
modelica_real omc_HVACZoneRad_pump_vol_Medium_temperature__phX(threadData_t *threadData, modelica_real _p, modelica_real _h, real_array _X);
DLLExport
modelica_metatype boxptr_HVACZoneRad_pump_vol_Medium_temperature__phX(threadData_t *threadData, modelica_metatype _p, modelica_metatype _h, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_vol_Medium_temperature__phX,2,0) {(void*) boxptr_HVACZoneRad_pump_vol_Medium_temperature__phX,0}};
#define boxvar_HVACZoneRad_pump_vol_Medium_temperature__phX MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_pump_vol_Medium_temperature__phX)


DLLExport
HVACZoneRad_rad_Medium_ThermodynamicState omc_HVACZoneRad_rad_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T);

DLLExport
modelica_metatype boxptr_HVACZoneRad_rad_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_rad_Medium_ThermodynamicState,2,0) {(void*) boxptr_HVACZoneRad_rad_Medium_ThermodynamicState,0}};
#define boxvar_HVACZoneRad_rad_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_rad_Medium_ThermodynamicState)


DLLExport
HVACZoneRad_rad_Medium_ThermodynamicState omc_HVACZoneRad_rad_Medium_setState__pTX(threadData_t *threadData, modelica_real _p, modelica_real _T, real_array _X);
DLLExport
modelica_metatype boxptr_HVACZoneRad_rad_Medium_setState__pTX(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_rad_Medium_setState__pTX,2,0) {(void*) boxptr_HVACZoneRad_rad_Medium_setState__pTX,0}};
#define boxvar_HVACZoneRad_rad_Medium_setState__pTX MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_rad_Medium_setState__pTX)


DLLExport
modelica_real omc_HVACZoneRad_rad_Medium_specificHeatCapacityCp(threadData_t *threadData, HVACZoneRad_rad_Medium_ThermodynamicState _state);
DLLExport
modelica_metatype boxptr_HVACZoneRad_rad_Medium_specificHeatCapacityCp(threadData_t *threadData, modelica_metatype _state);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_rad_Medium_specificHeatCapacityCp,2,0) {(void*) boxptr_HVACZoneRad_rad_Medium_specificHeatCapacityCp,0}};
#define boxvar_HVACZoneRad_rad_Medium_specificHeatCapacityCp MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_rad_Medium_specificHeatCapacityCp)


DLLExport
modelica_real omc_HVACZoneRad_rad_vol_Medium_temperature__phX(threadData_t *threadData, modelica_real _p, modelica_real _h, real_array _X);
DLLExport
modelica_metatype boxptr_HVACZoneRad_rad_vol_Medium_temperature__phX(threadData_t *threadData, modelica_metatype _p, modelica_metatype _h, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_rad_vol_Medium_temperature__phX,2,0) {(void*) boxptr_HVACZoneRad_rad_vol_Medium_temperature__phX,0}};
#define boxvar_HVACZoneRad_rad_vol_Medium_temperature__phX MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_rad_vol_Medium_temperature__phX)


DLLExport
HVACZoneRad_vol_Medium_ThermodynamicState omc_HVACZoneRad_vol_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T, real_array omc_X);

DLLExport
modelica_metatype boxptr_HVACZoneRad_vol_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_vol_Medium_ThermodynamicState,2,0) {(void*) boxptr_HVACZoneRad_vol_Medium_ThermodynamicState,0}};
#define boxvar_HVACZoneRad_vol_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_vol_Medium_ThermodynamicState)


DLLExport
HVACZoneRad_vol_dynBal_Medium_ThermodynamicState omc_HVACZoneRad_vol_dynBal_Medium_ThermodynamicState (threadData_t *threadData, modelica_real omc_p, modelica_real omc_T, real_array omc_X);

DLLExport
modelica_metatype boxptr_HVACZoneRad_vol_dynBal_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X);
static const MMC_DEFSTRUCTLIT(boxvar_lit_HVACZoneRad_vol_dynBal_Medium_ThermodynamicState,2,0) {(void*) boxptr_HVACZoneRad_vol_dynBal_Medium_ThermodynamicState,0}};
#define boxvar_HVACZoneRad_vol_dynBal_Medium_ThermodynamicState MMC_REFSTRUCTLIT(boxvar_lit_HVACZoneRad_vol_dynBal_Medium_ThermodynamicState)


DLLExport
void omc_Modelica_Fluid_Utilities_checkBoundary(threadData_t *threadData, modelica_string _mediumName, string_array _substanceNames, modelica_boolean _singleState, modelica_boolean _define_p, real_array _X_boundary, modelica_string _modelName);
DLLExport
void boxptr_Modelica_Fluid_Utilities_checkBoundary(threadData_t *threadData, modelica_metatype _mediumName, modelica_metatype _substanceNames, modelica_metatype _singleState, modelica_metatype _define_p, modelica_metatype _X_boundary, modelica_metatype _modelName);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Fluid_Utilities_checkBoundary,2,0) {(void*) boxptr_Modelica_Fluid_Utilities_checkBoundary,0}};
#define boxvar_Modelica_Fluid_Utilities_checkBoundary MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Fluid_Utilities_checkBoundary)


DLLExport
modelica_real omc_Modelica_Fluid_Utilities_cubicHermite(threadData_t *threadData, modelica_real _x, modelica_real _x1, modelica_real _x2, modelica_real _y1, modelica_real _y2, modelica_real _y1d, modelica_real _y2d);
DLLExport
modelica_metatype boxptr_Modelica_Fluid_Utilities_cubicHermite(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x1, modelica_metatype _x2, modelica_metatype _y1, modelica_metatype _y2, modelica_metatype _y1d, modelica_metatype _y2d);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Fluid_Utilities_cubicHermite,2,0) {(void*) boxptr_Modelica_Fluid_Utilities_cubicHermite,0}};
#define boxvar_Modelica_Fluid_Utilities_cubicHermite MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Fluid_Utilities_cubicHermite)


DLLExport
modelica_real omc_Modelica_Fluid_Utilities_regStep(threadData_t *threadData, modelica_real _x, modelica_real _y1, modelica_real _y2, modelica_real _x_small);
DLLExport
modelica_metatype boxptr_Modelica_Fluid_Utilities_regStep(threadData_t *threadData, modelica_metatype _x, modelica_metatype _y1, modelica_metatype _y2, modelica_metatype _x_small);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Fluid_Utilities_regStep,2,0) {(void*) boxptr_Modelica_Fluid_Utilities_regStep,0}};
#define boxvar_Modelica_Fluid_Utilities_regStep MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Fluid_Utilities_regStep)


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
#include "HVACZoneRad_model.h"


#ifdef __cplusplus
}
#endif
#endif

