#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_02nls.c"
#endif
/* Non Linear Systems */
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_12jac.h"
#include "util/jacobian_util.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
equation index: 658
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.p = (-thermalZoneFourElements.volAir.dynBal.medium.d) * thermalZoneFourElements.volAir.dynBal.medium.T / (-0.003483702703378509)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_658(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,658};
#line 6188 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */) = DIVISION_SIM(((-(data->localData[0]->realVars[304] /* thermalZoneFourElements.volAir.dynBal.medium.d variable */))) * ((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */)),-0.003483702703378509,"-0.003483702703378509",equationIndexes);
#line 27 OMC_FILE
  TRACE_POP
}
/*
equation index: 659
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.hOut_internal = Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements.thermalZoneFourElements.volAir.dynBal.Medium.specificEnthalpy_pTX(thermalZoneFourElements.volAir.dynBal.medium.p, thermalZoneFourElements.volAir.dynBal.medium.T, {1.0})
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_659(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,659};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 1, (modelica_real)1.0);
  (data->localData[0]->realVars[308] /* thermalZoneFourElements.volAir.hOut_internal variable */) = omc_Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_thermalZoneFourElements_volAir_dynBal_Medium_specificEnthalpy__pTX(threadData, (data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */), (data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */), tmp0);
  TRACE_POP
}

void residualFunc661(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,661};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc661: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc661 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_658(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_659(data, threadData);
  /* body */
  res[0] = (-287.0509010514002) * ((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */)) + (data->localData[0]->realVars[308] /* thermalZoneFourElements.volAir.hOut_internal variable */) - (data->localData[0]->realVars[307] /* thermalZoneFourElements.volAir.dynBal.medium.u variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS661(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 1;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
void initializeNonlinearPatternNLS661(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
} //TS//

OMC_DISABLE_OPT
void initializeStaticDataNLS661(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for thermalZoneFourElements.volAir.dynBal.medium.T */
  sysData->nominal[i] = data->modelData->realVarsData[301].attribute /* thermalZoneFourElements.volAir.dynBal.medium.T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[301].attribute /* thermalZoneFourElements.volAir.dynBal.medium.T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[301].attribute /* thermalZoneFourElements.volAir.dynBal.medium.T */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS661(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS661(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS661(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */);
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[0].equationIndex = 661;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0;
  nonLinearSystemData[0].mixedSystem = 0;
  nonLinearSystemData[0].residualFunc = residualFunc661;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = NULL;
  nonLinearSystemData[0].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[0].jacobianIndex = -1;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS661;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS661;
  nonLinearSystemData[0].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif

