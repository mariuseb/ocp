#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustomWea/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_12jac.c"
#endif
/* Jacobians 8 */
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_12jac.h"
#include "util/jacobian_util.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 80
type: SIMPLE_ASSIGN
$cse1 = exp(4102.99 / (weaBus.TWetBul - 35.719) - 17.2799)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_80(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,80};
  jacobian->tmpVars[0] /* $cse1 JACOBIAN_DIFF_VAR */ = exp(DIVISION(4102.99,(data->localData[0]->realVars[45] /* weaBus.TWetBul variable */) - 35.719,"weaBus.TWetBul - 35.719") - 17.2799);
  TRACE_POP
}

/*
equation index: 81
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac4.dummyVarNLSJac4 = 422741.4828629122 * $cse1 * weaBus.TWetBul.SeedNLSJac4 / ((-35.719 + weaBus.TWetBul) * (-0.378035286922501 + 165.6565689594004 * $cse1)) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_81(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,81};
  modelica_real tmp0;
#line 59 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  tmp0 = (-35.719 + (data->localData[0]->realVars[45] /* weaBus.TWetBul variable */)) * (-0.378035286922501 + (165.6565689594004) * (jacobian->tmpVars[0] /* $cse1 JACOBIAN_DIFF_VAR */));
#line 59 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->tmpVars[1] /* weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */ = (422741.4828629122) * ((jacobian->tmpVars[0] /* $cse1 JACOBIAN_DIFF_VAR */) * (DIVISION(jacobian->seedVars[0] /* weaBus.TWetBul.SeedNLSJac4 SEED_VAR */,(tmp0 * tmp0),"((-35.719 + weaBus.TWetBul) * (-0.378035286922501 + 165.6565689594004 * $cse1)) ^ 2.0")));
#line 44 OMC_FILE
  TRACE_POP
}

/*
equation index: 82
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac4.dummyVarNLSJac4 = (1.0 - weaDat.tWetBul_TDryBulXi.XiDryBul) * weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac4.dummyVarNLSJac4 / (1.0 - weaDat.tWetBul_TDryBulXi.XiSat) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_82(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,82};
  modelica_real tmp1;
#line 58 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  tmp1 = 1.0 - (data->localData[0]->realVars[103] /* weaDat.tWetBul_TDryBulXi.XiSat variable */);
#line 58 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */)) * (DIVISION(jacobian->tmpVars[1] /* weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */,(tmp1 * tmp1),"(1.0 - weaDat.tWetBul_TDryBulXi.XiSat) ^ 2.0"));
#line 64 OMC_FILE
  TRACE_POP
}

/*
equation index: 83
type: SIMPLE_ASSIGN
$res_NLSJac4_1.$pDERNLSJac4.dummyVarNLSJac4 = (-2324.0) * (273.15 - weaBus.TWetBul) * weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac4.dummyVarNLSJac4 + (-2501014.5) * weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac4.dummyVarNLSJac4 - weaBus.TWetBul.SeedNLSJac4 * (1006.0 * (1.0 - weaDat.tWetBul_TDryBulXi.XiDryBul) + 1860.0 * weaDat.tWetBul_TDryBulXi.XiSatRefIn + 4184.0 * (weaDat.tWetBul_TDryBulXi.XiDryBul - weaDat.tWetBul_TDryBulXi.XiSatRefIn))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_83(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,83};
#line 67 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->resultVars[0] /* $res_NLSJac4_1.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_VAR */ = (-2324.0) * ((273.15 - (data->localData[0]->realVars[45] /* weaBus.TWetBul variable */)) * (jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */)) + (-2501014.5) * (jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */) - ((jacobian->seedVars[0] /* weaBus.TWetBul.SeedNLSJac4 SEED_VAR */) * ((1006.0) * (1.0 - (data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */)) + (1860.0) * ((data->localData[0]->realVars[104] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */)) + (4184.0) * ((data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */) - (data->localData[0]->realVars[104] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */))));
#line 81 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacNLSJac4_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_NLSJac4;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacNLSJac4_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_NLSJac4;
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_80(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_81(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_82(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_83(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 303
type: SIMPLE_ASSIGN
$cse21 = exp(4102.99 / (weaBus.TWetBul - 35.719) - 17.2799)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_303(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,303};
  jacobian->tmpVars[0] /* $cse21 JACOBIAN_DIFF_VAR */ = exp(DIVISION(4102.99,(data->localData[0]->realVars[45] /* weaBus.TWetBul variable */) - 35.719,"weaBus.TWetBul - 35.719") - 17.2799);
  TRACE_POP
}

/*
equation index: 304
type: SIMPLE_ASSIGN
$cse3.$pDERNLSJac5.dummyVarNLSJac5 = (-4102.99) * $cse21 * weaBus.TWetBul.SeedNLSJac5 / (-35.719 + weaBus.TWetBul) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_304(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,304};
  modelica_real tmp2;
  tmp2 = -35.719 + (data->localData[0]->realVars[45] /* weaBus.TWetBul variable */);
  jacobian->tmpVars[1] /* $cse3.$pDERNLSJac5.dummyVarNLSJac5 JACOBIAN_DIFF_VAR */ = (-4102.99) * ((jacobian->tmpVars[0] /* $cse21 JACOBIAN_DIFF_VAR */) * (DIVISION(jacobian->seedVars[0] /* weaBus.TWetBul.SeedNLSJac5 SEED_VAR */,(tmp2 * tmp2),"(-35.719 + weaBus.TWetBul) ^ 2.0")));
  TRACE_POP
}

/*
equation index: 305
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac5.dummyVarNLSJac5 = (-103.0325403822364) * $cse3.$pDERNLSJac5.dummyVarNLSJac5 / (-0.378035286922501 + 165.6565689594004 * $cse3) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_305(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,305};
  modelica_real tmp3;
#line 59 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  tmp3 = -0.378035286922501 + (165.6565689594004) * ((data->localData[0]->realVars[12] /* $cse3 variable */));
#line 59 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac5.dummyVarNLSJac5 JACOBIAN_DIFF_VAR */ = (-103.0325403822364) * (DIVISION(jacobian->tmpVars[1] /* $cse3.$pDERNLSJac5.dummyVarNLSJac5 JACOBIAN_DIFF_VAR */,(tmp3 * tmp3),"(-0.378035286922501 + 165.6565689594004 * $cse3) ^ 2.0"));
#line 160 OMC_FILE
  TRACE_POP
}

/*
equation index: 306
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac5.dummyVarNLSJac5 = (1.0 - weaDat.tWetBul_TDryBulXi.XiDryBul) * weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac5.dummyVarNLSJac5 / (1.0 - weaDat.tWetBul_TDryBulXi.XiSat) ^ 2.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_306(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,306};
  modelica_real tmp4;
#line 58 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  tmp4 = 1.0 - (data->localData[0]->realVars[103] /* weaDat.tWetBul_TDryBulXi.XiSat variable */);
#line 58 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->tmpVars[3] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac5.dummyVarNLSJac5 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */)) * (DIVISION(jacobian->tmpVars[2] /* weaDat.tWetBul_TDryBulXi.XiSat.$pDERNLSJac5.dummyVarNLSJac5 JACOBIAN_DIFF_VAR */,(tmp4 * tmp4),"(1.0 - weaDat.tWetBul_TDryBulXi.XiSat) ^ 2.0"));
#line 180 OMC_FILE
  TRACE_POP
}

/*
equation index: 307
type: SIMPLE_ASSIGN
$res_NLSJac5_1.$pDERNLSJac5.dummyVarNLSJac5 = (-2324.0) * (273.15 - weaBus.TWetBul) * weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac5.dummyVarNLSJac5 + (-2501014.5) * weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac5.dummyVarNLSJac5 - weaBus.TWetBul.SeedNLSJac5 * (1006.0 * (1.0 - weaDat.tWetBul_TDryBulXi.XiDryBul) + 1860.0 * weaDat.tWetBul_TDryBulXi.XiSatRefIn + 4184.0 * (weaDat.tWetBul_TDryBulXi.XiDryBul - weaDat.tWetBul_TDryBulXi.XiSatRefIn))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_307(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,307};
#line 67 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  jacobian->resultVars[0] /* $res_NLSJac5_1.$pDERNLSJac5.dummyVarNLSJac5 JACOBIAN_VAR */ = (-2324.0) * ((273.15 - (data->localData[0]->realVars[45] /* weaBus.TWetBul variable */)) * (jacobian->tmpVars[3] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac5.dummyVarNLSJac5 JACOBIAN_DIFF_VAR */)) + (-2501014.5) * (jacobian->tmpVars[3] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn.$pDERNLSJac5.dummyVarNLSJac5 JACOBIAN_DIFF_VAR */) - ((jacobian->seedVars[0] /* weaBus.TWetBul.SeedNLSJac5 SEED_VAR */) * ((1006.0) * (1.0 - (data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */)) + (1860.0) * ((data->localData[0]->realVars[104] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */)) + (4184.0) * ((data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */) - (data->localData[0]->realVars[104] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */))));
#line 197 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacNLSJac5_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_NLSJac5;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacNLSJac5_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_INDEX_JAC_NLSJac5;
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_303(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_304(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_305(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_306(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_307(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianNLSJac4(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
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
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianNLSJac5(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
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
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}



