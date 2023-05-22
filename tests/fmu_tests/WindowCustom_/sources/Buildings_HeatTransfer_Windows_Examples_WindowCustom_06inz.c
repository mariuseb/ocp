#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustom/Buildings_HeatTransfer_Windows_Examples_WindowCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustom_06inz.c"
#endif
/* Initialization */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_11mix.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
extCon.shaRad.QRadAbs_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
#line 59 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[28] /* extCon.shaRad.QRadAbs_flow variable */) = 0.0;
#line 27 OMC_FILE
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
extCon.shaRad.T4 = 7385154648.771004
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[29] /* extCon.shaRad.T4 variable */) = 7385154648.771004;
#line 42 OMC_FILE
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
extCon.shaRad.E_air = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
#line 88 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[26] /* extCon.shaRad.E_air variable */) = 0.0;
#line 57 OMC_FILE
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
extCon.shaRad.E_glass = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
#line 90 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[27] /* extCon.shaRad.E_glass variable */) = 0.0;
#line 72 OMC_FILE
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
extCon.shaRad.TSha_internal = 293.15
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
#line 80 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[30] /* extCon.shaRad.TSha_internal variable */) = 293.15;
#line 87 OMC_FILE
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
intShaCon.conCoeGla.GCon = 3.2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvectionCoefficient.mo"
  (data->localData[0]->realVars[43] /* intShaCon.conCoeGla.GCon variable */) = 3.2;
#line 102 OMC_FILE
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
temperatureSensor.port.Q_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[64] /* temperatureSensor.port.Q_flow variable */) = 0.0;
#line 117 OMC_FILE
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
temperatureSensor1.port.Q_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[65] /* temperatureSensor1.port.Q_flow variable */) = 0.0;
#line 132 OMC_FILE
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
heatFlowSensor1.port_b.Q_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[36] /* heatFlowSensor1.port_b.Q_flow variable */) = 0.0;
#line 147 OMC_FILE
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
intShaCon.air.Q_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[42] /* intShaCon.air.Q_flow variable */) = 0.0;
#line 162 OMC_FILE
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
heatFlowSensor.port_b.Q_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[34] /* heatFlowSensor.port_b.Q_flow variable */) = 0.0;
#line 177 OMC_FILE
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
indRad.heatPort.Q_flow = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[39] /* indRad.heatPort.Q_flow variable */) = 0.0;
#line 192 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_119(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_120(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_121(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_122(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_123(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_124(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_130(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_135(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_131(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_133(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_132(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_134(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_136(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_137(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_125(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_126(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_127(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_128(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_129(DATA *data, threadData_t *threadData);


/*
equation index: 111
type: LINEAR

<var>window.fra_b.T</var>
<var>heatFlowSensor1.port_a.T</var>
<var>window.glaUns_b.T</var>
<var>intShaCon.TSha</var>
<var>intShaRad.JIn_glass</var>
<var>window.JOutUns_b</var>
<var>window.glaUns_a.T</var>
<var>window.glaSha_a.T</var>
<var>indRad.JIn</var>
<var>intShaCon.glaSha.T</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  /* Linear equation system */
  int retValue;
  double aux_x[10] = { (data->localData[1]->realVars[71] /* window.fra_b.T variable */),(data->localData[1]->realVars[35] /* heatFlowSensor1.port_a.T variable */),(data->localData[1]->realVars[85] /* window.glaUns_b.T variable */),(data->localData[1]->realVars[41] /* intShaCon.TSha variable */),(data->localData[1]->realVars[58] /* intShaRad.JIn_glass variable */),(data->localData[1]->realVars[69] /* window.JOutUns_b variable */),(data->localData[1]->realVars[84] /* window.glaUns_a.T variable */),(data->localData[1]->realVars[78] /* window.glaSha_a.T variable */),(data->localData[1]->realVars[37] /* indRad.JIn variable */),(data->localData[1]->realVars[54] /* intShaCon.glaSha.T variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 111 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 0, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,111};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 111 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[71] /* window.fra_b.T variable */) = aux_x[0];
  (data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */) = aux_x[1];
  (data->localData[0]->realVars[85] /* window.glaUns_b.T variable */) = aux_x[2];
  (data->localData[0]->realVars[41] /* intShaCon.TSha variable */) = aux_x[3];
  (data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */) = aux_x[4];
  (data->localData[0]->realVars[69] /* window.JOutUns_b variable */) = aux_x[5];
  (data->localData[0]->realVars[84] /* window.glaUns_a.T variable */) = aux_x[6];
  (data->localData[0]->realVars[78] /* window.glaSha_a.T variable */) = aux_x[7];
  (data->localData[0]->realVars[37] /* indRad.JIn variable */) = aux_x[8];
  (data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */) = aux_x[9];

  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_221(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_222(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_223(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_220(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_218(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_219(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_224(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_1(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_2(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_3(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_4(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_5(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_6(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_7(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_8(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_9(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_10(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_11(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_12(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_119(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_120(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_121(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_122(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_123(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_124(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_130(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_135(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_131(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_133(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_132(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_134(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_136(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_137(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_125(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_126(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_127(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_128(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_129(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_111(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_221(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_222(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_223(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_220(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_218(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_219(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_224(data, threadData);
  TRACE_POP
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionInitialEquations_lambda0 function */

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

