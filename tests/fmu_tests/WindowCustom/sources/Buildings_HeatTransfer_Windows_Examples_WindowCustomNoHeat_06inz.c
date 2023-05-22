#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustomNoHeat/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_06inz.c"
#endif
/* Initialization */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_11mix.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
extCon.shaRad.QRadAbs_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
#line 59 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[27] /* extCon.shaRad.QRadAbs_flow variable */) = 0.0;
#line 27 OMC_FILE
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
extCon.shaRad.T4 = 7385154648.771004
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[28] /* extCon.shaRad.T4 variable */) = 7385154648.771004;
#line 42 OMC_FILE
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
extCon.shaRad.E_air = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
#line 88 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[25] /* extCon.shaRad.E_air variable */) = 0.0;
#line 57 OMC_FILE
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
extCon.shaRad.E_glass = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
#line 90 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[26] /* extCon.shaRad.E_glass variable */) = 0.0;
#line 72 OMC_FILE
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
extCon.shaRad.TSha_internal = 293.15
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
#line 80 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[29] /* extCon.shaRad.TSha_internal variable */) = 293.15;
#line 87 OMC_FILE
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
intShaCon.conCoeGla.GCon = 3.2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvectionCoefficient.mo"
  (data->localData[0]->realVars[39] /* intShaCon.conCoeGla.GCon variable */) = 3.2;
#line 102 OMC_FILE
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
fixedHeatFlow.port.Q_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[32] /* fixedHeatFlow.port.Q_flow variable */) = 0.0;
#line 117 OMC_FILE
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
TRAir.port.T = 293.15
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[8] /* TRAir.port.T variable */) = 293.15;
#line 132 OMC_FILE
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
indRad.heatPort.Q_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[36] /* indRad.heatPort.Q_flow variable */) = 0.0;
#line 147 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_122(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_121(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_118(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_119(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_120(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_112(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_123(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_127(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_124(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_126(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_125(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_128(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_129(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_130(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_113(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_114(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_115(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_116(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_117(DATA *data, threadData_t *threadData);


/*
equation index: 41
type: LINEAR

<var>intShaCon.conFra.dT</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { (data->localData[1]->realVars[41] /* intShaCon.conFra.dT variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 41 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 0, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,41};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 41 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[41] /* intShaCon.conFra.dT variable */) = aux_x[0];

  TRACE_POP
}

/*
equation index: 106
type: LINEAR

<var>window.glaUns_a.T</var>
<var>indRad.JIn</var>
<var>intShaRad.JIn_glass</var>
<var>window.glaSha_a.T</var>
<var>intShaCon.TSha</var>
<var>intShaCon.glaSha.T</var>
<var>window.glaUns.glass[1].T4_b</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  /* Linear equation system */
  int retValue;
  double aux_x[7] = { (data->localData[1]->realVars[78] /* window.glaUns_a.T variable */),(data->localData[1]->realVars[34] /* indRad.JIn variable */),(data->localData[1]->realVars[54] /* intShaRad.JIn_glass variable */),(data->localData[1]->realVars[72] /* window.glaSha_a.T variable */),(data->localData[1]->realVars[38] /* intShaCon.TSha variable */),(data->localData[1]->realVars[50] /* intShaCon.glaSha.T variable */),(data->localData[1]->realVars[76] /* window.glaUns.glass[1].T4_b variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 106 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 1, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,106};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 106 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[78] /* window.glaUns_a.T variable */) = aux_x[0];
  (data->localData[0]->realVars[34] /* indRad.JIn variable */) = aux_x[1];
  (data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */) = aux_x[2];
  (data->localData[0]->realVars[72] /* window.glaSha_a.T variable */) = aux_x[3];
  (data->localData[0]->realVars[38] /* intShaCon.TSha variable */) = aux_x[4];
  (data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */) = aux_x[5];
  (data->localData[0]->realVars[76] /* window.glaUns.glass[1].T4_b variable */) = aux_x[6];

  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_210(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_209(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_208(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_212(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_211(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_1(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_2(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_3(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_4(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_5(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_6(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_7(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_8(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_9(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_122(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_121(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_118(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_119(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_120(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_112(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_123(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_127(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_124(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_126(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_125(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_128(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_129(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_130(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_113(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_114(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_115(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_116(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_117(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_41(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_106(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_210(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_209(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_208(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_212(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_211(data, threadData);
  TRACE_POP
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionInitialEquations_lambda0 function */

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

