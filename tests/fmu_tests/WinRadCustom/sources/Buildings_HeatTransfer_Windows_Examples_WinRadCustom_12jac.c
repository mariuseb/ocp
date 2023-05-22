#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustom/Buildings_HeatTransfer_Windows_Examples_WinRadCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustom_12jac.c"
#endif
/* Jacobians 8 */
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_12jac.h"
#include "util/jacobian_util.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 194
type: SIMPLE_ASSIGN
$cse1 = exp(4102.99 / (weaBus.TWetBul - 35.719) - 17.2799)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_194(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,194};
  jacobian->tmpVars[0] /* $cse1 JACOBIAN_DIFF_VAR */ = exp(DIVISION(4102.99,(data->localData[0]->realVars[56] /* weaBus.TWetBul variable */) - 35.719,"weaBus.TWetBul - 35.719") - 17.2799);
  TRACE_POP
}

/*
equation index: 195
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac18.dummyVarNLSJac18 = 422741.4828629122 * $cse1 * weaBus.TWetBul.SeedNLSJac18 / ((-35.719 + weaBus.TWetBul) * (-0.378035286922501 + 165.6565689594004 * $cse1)) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_195(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,195};
  modelica_real tmp0;
#line 59 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  tmp0 = (-35.719 + (data->localData[0]->realVars[56] /* weaBus.TWetBul variable */)) * (-0.378035286922501 + (165.6565689594004) * (jacobian->tmpVars[0] /* $cse1 JACOBIAN_DIFF_VAR */));
#line 59 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->tmpVars[1] /* weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac18.dummyVarNLSJac18 JACOBIAN_DIFF_VAR */ = (422741.4828629122) * ((jacobian->tmpVars[0] /* $cse1 JACOBIAN_DIFF_VAR */) * (DIVISION(jacobian->seedVars[0] /* weaBus.TWetBul.SeedNLSJac18 SEED_VAR */,(tmp0 * tmp0),"((-35.719 + weaBus.TWetBul) * (-0.378035286922501 + 165.6565689594004 * $cse1)) ^ 2.0")));
#line 44 OMC_FILE
  TRACE_POP
}

/*
equation index: 196
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac18.dummyVarNLSJac18 = (1.0 - weaDat.tWetBul_TDryBulXi.XiDryBul) * weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac18.dummyVarNLSJac18 / (1.0 - weaDat.tWetBul_TDryBulXi.XiSat) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_196(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,196};
  modelica_real tmp1;
#line 58 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  tmp1 = 1.0 - (data->localData[0]->realVars[112] /* weaDat.tWetBul_TDryBulXi.XiSat variable */);
#line 58 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac18.dummyVarNLSJac18 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */)) * (DIVISION(jacobian->tmpVars[1] /* weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac18.dummyVarNLSJac18 JACOBIAN_DIFF_VAR */,(tmp1 * tmp1),"(1.0 - weaDat.tWetBul_TDryBulXi.XiSat) ^ 2.0"));
#line 64 OMC_FILE
  TRACE_POP
}

/*
equation index: 197
type: SIMPLE_ASSIGN
$res_NLSJac18_1.$pDERNLSJac18.dummyVarNLSJac18 = (-2324.0) * (273.15 - weaBus.TWetBul) * weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac18.dummyVarNLSJac18 + (-2501014.5) * weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac18.dummyVarNLSJac18 - weaBus.TWetBul.SeedNLSJac18 * (1006.0 * (1.0 - weaDat.tWetBul_TDryBulXi.XiDryBul) + 1860.0 * weaDat.tWetBul_TDryBulXi.XiSatRefIn + 4184.0 * (weaDat.tWetBul_TDryBulXi.XiDryBul - weaDat.tWetBul_TDryBulXi.XiSatRefIn))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_197(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,197};
#line 67 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->resultVars[0] /* $res_NLSJac18_1.$pDERNLSJac18.dummyVarNLSJac18 JACOBIAN_VAR */ = (-2324.0) * ((273.15 - (data->localData[0]->realVars[56] /* weaBus.TWetBul variable */)) * (jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac18.dummyVarNLSJac18 JACOBIAN_DIFF_VAR */)) + (-2501014.5) * (jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac18.dummyVarNLSJac18 JACOBIAN_DIFF_VAR */) - ((jacobian->seedVars[0] /* weaBus.TWetBul.SeedNLSJac18 SEED_VAR */) * ((1006.0) * (1.0 - (data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */)) + (1860.0) * ((data->localData[0]->realVars[113] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */)) + (4184.0) * ((data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */) - (data->localData[0]->realVars[113] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */))));
#line 81 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacNLSJac18_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_NLSJac18;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacNLSJac18_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_NLSJac18;
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_194(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_195(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_196(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_197(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 324
type: SIMPLE_ASSIGN
$cse21 = exp(4102.99 / (weaBus.TWetBul - 35.719) - 17.2799)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_324(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,324};
  jacobian->tmpVars[0] /* $cse21 JACOBIAN_DIFF_VAR */ = exp(DIVISION(4102.99,(data->localData[0]->realVars[56] /* weaBus.TWetBul variable */) - 35.719,"weaBus.TWetBul - 35.719") - 17.2799);
  TRACE_POP
}

/*
equation index: 325
type: SIMPLE_ASSIGN
$cse16.$pDERNLSJac19.dummyVarNLSJac19 = (-4102.99) * $cse21 * weaBus.TWetBul.SeedNLSJac19 / (-35.719 + weaBus.TWetBul) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_325(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,325};
  modelica_real tmp2;
  tmp2 = -35.719 + (data->localData[0]->realVars[56] /* weaBus.TWetBul variable */);
  jacobian->tmpVars[1] /* $cse16.$pDERNLSJac19.dummyVarNLSJac19 JACOBIAN_DIFF_VAR */ = (-4102.99) * ((jacobian->tmpVars[0] /* $cse21 JACOBIAN_DIFF_VAR */) * (DIVISION(jacobian->seedVars[0] /* weaBus.TWetBul.SeedNLSJac19 SEED_VAR */,(tmp2 * tmp2),"(-35.719 + weaBus.TWetBul) ^ 2.0")));
  TRACE_POP
}

/*
equation index: 326
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac19.dummyVarNLSJac19 = (-103.0325403822364) * $cse16.$pDERNLSJac19.dummyVarNLSJac19 / (-0.378035286922501 + 165.6565689594004 * $cse16) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_326(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,326};
  modelica_real tmp3;
#line 59 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  tmp3 = -0.378035286922501 + (165.6565689594004) * ((data->localData[0]->realVars[6] /* $cse16 variable */));
#line 59 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac19.dummyVarNLSJac19 JACOBIAN_DIFF_VAR */ = (-103.0325403822364) * (DIVISION(jacobian->tmpVars[1] /* $cse16.$pDERNLSJac19.dummyVarNLSJac19 JACOBIAN_DIFF_VAR */,(tmp3 * tmp3),"(-0.378035286922501 + 165.6565689594004 * $cse16) ^ 2.0"));
#line 160 OMC_FILE
  TRACE_POP
}

/*
equation index: 327
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac19.dummyVarNLSJac19 = (1.0 - weaDat.tWetBul_TDryBulXi.XiDryBul) * weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac19.dummyVarNLSJac19 / (1.0 - weaDat.tWetBul_TDryBulXi.XiSat) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_327(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,327};
  modelica_real tmp4;
#line 58 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  tmp4 = 1.0 - (data->localData[0]->realVars[112] /* weaDat.tWetBul_TDryBulXi.XiSat variable */);
#line 58 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->tmpVars[3] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac19.dummyVarNLSJac19 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */)) * (DIVISION(jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac19.dummyVarNLSJac19 JACOBIAN_DIFF_VAR */,(tmp4 * tmp4),"(1.0 - weaDat.tWetBul_TDryBulXi.XiSat) ^ 2.0"));
#line 180 OMC_FILE
  TRACE_POP
}

/*
equation index: 328
type: SIMPLE_ASSIGN
$res_NLSJac19_1.$pDERNLSJac19.dummyVarNLSJac19 = (-2324.0) * (273.15 - weaBus.TWetBul) * weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac19.dummyVarNLSJac19 + (-2501014.5) * weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac19.dummyVarNLSJac19 - weaBus.TWetBul.SeedNLSJac19 * (1006.0 * (1.0 - weaDat.tWetBul_TDryBulXi.XiDryBul) + 1860.0 * weaDat.tWetBul_TDryBulXi.XiSatRefIn + 4184.0 * (weaDat.tWetBul_TDryBulXi.XiDryBul - weaDat.tWetBul_TDryBulXi.XiSatRefIn))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_328(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,328};
#line 67 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->resultVars[0] /* $res_NLSJac19_1.$pDERNLSJac19.dummyVarNLSJac19 JACOBIAN_VAR */ = (-2324.0) * ((273.15 - (data->localData[0]->realVars[56] /* weaBus.TWetBul variable */)) * (jacobian->tmpVars[3] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac19.dummyVarNLSJac19 JACOBIAN_DIFF_VAR */)) + (-2501014.5) * (jacobian->tmpVars[3] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac19.dummyVarNLSJac19 JACOBIAN_DIFF_VAR */) - ((jacobian->seedVars[0] /* weaBus.TWetBul.SeedNLSJac19 SEED_VAR */) * ((1006.0) * (1.0 - (data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */)) + (1860.0) * ((data->localData[0]->realVars[113] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */)) + (4184.0) * ((data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */) - (data->localData[0]->realVars[113] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */))));
#line 197 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacNLSJac19_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_NLSJac19;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacNLSJac19_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WinRadCustom_INDEX_JAC_NLSJac19;
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_324(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_325(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_326(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_327(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_328(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianNLSJac18(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 1, 1, 4, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianNLSJac19(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 1, 1, 5, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}



