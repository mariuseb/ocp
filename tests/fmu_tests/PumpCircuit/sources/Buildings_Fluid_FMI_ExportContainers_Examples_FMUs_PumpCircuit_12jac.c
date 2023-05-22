#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit.fmutmp/sources/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_12jac.c"
#endif
/* Jacobians 7 */
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_model.h"
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_12jac.h"
#include "util/jacobian_util.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 950
type: SIMPLE_ASSIGN
$cse8.T.$pDERFMIDER.dummyVarFMIDER = Tsup.SeedFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_950(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,950};
  jacobian->tmpVars[11] /* $cse8.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = jacobian->seedVars[3] /* Tsup.SeedFMIDER SEED_VAR */;
  TRACE_POP
}

/*
equation index: 951
type: SIMPLE_ASSIGN
hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER = 4184.0 * $cse8.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_951(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,951};
  jacobian->tmpVars[40] /* hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (4184.0) * (jacobian->tmpVars[11] /* $cse8.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
  TRACE_POP
}

/*
equation index: 952
type: SIMPLE_ASSIGN
$DER.fan.filter.s.$pDERFMIDER.dummyVarFMIDER[2] = fan.filter.u_nom * (fan.filter.s.SeedFMIDER[1] - fan.filter.s.SeedFMIDER[2]) * fan.filter.w_u
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_952(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,952};
#line 52 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  jacobian->resultVars[1] /* der(fan.filter.s.$pDERFMIDER.dummyVarFMIDER[2]) JACOBIAN_VAR */ = ((data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */)) * ((jacobian->seedVars[0] /* fan.filter.s.SeedFMIDER[1] SEED_VAR */ - jacobian->seedVars[1] /* fan.filter.s.SeedFMIDER[2] SEED_VAR */) * ((data->simulationInfo->realParameter[197] /* fan.filter.w_u PARAM */)));
#line 56 OMC_FILE
  TRACE_POP
}

/*
equation index: 953
type: SIMPLE_ASSIGN
fluPor.2.m_flow.$pDERFMIDER.dummyVarFMIDER = (-fan.filter.u_nom) * fan.filter.s.SeedFMIDER[2]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_953(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,953};
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  jacobian->resultVars[8] /* fluPor.2.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */ = ((-(data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */))) * (jacobian->seedVars[1] /* fan.filter.s.SeedFMIDER[2] SEED_VAR */);
#line 73 OMC_FILE
  TRACE_POP
}

/*
equation index: 954
type: SIMPLE_ASSIGN
$cse9.$pDERFMIDER.dummyVarFMIDER = if noEvent((-fluPor[2].m_flow) > 1e-07) then -fluPor.2.m_flow.$pDERFMIDER.dummyVarFMIDER else 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_954(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,954};
  modelica_boolean tmp0;
  tmp0 = Greater((-(data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */)),1e-07);
  jacobian->tmpVars[13] /* $cse9.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (tmp0?(-jacobian->resultVars[8] /* fluPor.2.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */):0.0);
  TRACE_POP
}

/*
equation index: 955
type: SIMPLE_ASSIGN
fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER = -fluPor.2.m_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_955(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,955};
#line 13 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */ = (-jacobian->resultVars[8] /* fluPor.2.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */);
#line 107 OMC_FILE
  TRACE_POP
}

/*
equation index: 956
type: SIMPLE_ASSIGN
fan.vol.steBal.m_flowInv.$pDERFMIDER.dummyVarFMIDER = if noEvent(fluPor[1].m_flow > 0.001 * fan.vol.steBal.m_flow_small) or noEvent(fluPor[1].m_flow < (-0.001) * fan.vol.steBal.m_flow_small) then (-fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER) / fluPor[1].m_flow ^ 2.0 else if noEvent(fluPor[1].m_flow < 0.5 * fan.vol.steBal.deltaReg) and noEvent(fluPor[1].m_flow > (-0.5) * fan.vol.steBal.deltaReg) then fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER * fan.vol.steBal.deltaReg ^ 2.0 / fan.vol.steBal.deltaReg ^ 4.0 else (if noEvent(fluPor[1].m_flow >= 0.0) then 1.0 else -1.0) * sign(fluPor[1].m_flow) * fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER * (abs(fluPor[1].m_flow) * (abs(fluPor[1].m_flow) * (abs(fluPor[1].m_flow) * (abs(fluPor[1].m_flow) * fan.vol.steBal.fReg + fan.vol.steBal.eReg + abs(fluPor[1].m_flow) * fan.vol.steBal.fReg) + fan.vol.steBal.dReg + abs(fluPor[1].m_flow) * (fan.vol.steBal.eReg + abs(fluPor[1].m_flow) * fan.vol.steBal.fReg)) + fan.vol.steBal.cReg + abs(fluPor[1].m_flow) * (fan.vol.steBal.dReg + abs(fluPor[1].m_flow) * (fan.vol.steBal.eReg + abs(fluPor[1].m_flow) * fan.vol.steBal.fReg))) + fan.vol.steBal.bReg + abs(fluPor[1].m_flow) * (fan.vol.steBal.cReg + abs(fluPor[1].m_flow) * (fan.vol.steBal.dReg + abs(fluPor[1].m_flow) * (fan.vol.steBal.eReg + abs(fluPor[1].m_flow) * fan.vol.steBal.fReg))))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_956(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,956};
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_boolean tmp11;
  modelica_real tmp12;
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  tmp1 = Greater((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(0.001) * ((data->simulationInfo->realParameter[294] /* fan.vol.steBal.m_flow_small PARAM */)));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  tmp2 = Less((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(-0.001) * ((data->simulationInfo->realParameter[294] /* fan.vol.steBal.m_flow_small PARAM */)));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  tmp11 = (modelica_boolean)(tmp1 || tmp2);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  if(tmp11)
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  {
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp3 = (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp12 = DIVISION((-jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */),(tmp3 * tmp3),"fluPor[1].m_flow ^ 2.0");
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  }
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  else
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  {
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp4 = Less((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(0.5) * ((data->simulationInfo->realParameter[290] /* fan.vol.steBal.deltaReg PARAM */)));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp5 = Greater((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(-0.5) * ((data->simulationInfo->realParameter[290] /* fan.vol.steBal.deltaReg PARAM */)));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp9 = (modelica_boolean)(tmp4 && tmp5);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    if(tmp9)
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    {
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp6 = (data->simulationInfo->realParameter[290] /* fan.vol.steBal.deltaReg PARAM */);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp7 = (data->simulationInfo->realParameter[290] /* fan.vol.steBal.deltaReg PARAM */);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp7 *= tmp7;
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp10 = DIVISION((jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */) * ((tmp6 * tmp6)),(tmp7 * tmp7),"fan.vol.steBal.deltaReg ^ 4.0");
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    }
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    else
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    {
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp8 = GreaterEq((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),0.0);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp10 = ((tmp8?1.0:-1.0)) * (((sign((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * (jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */)) * ((fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[292] /* fan.vol.steBal.fReg PARAM */)) + (data->simulationInfo->realParameter[291] /* fan.vol.steBal.eReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[292] /* fan.vol.steBal.fReg PARAM */))) + (data->simulationInfo->realParameter[288] /* fan.vol.steBal.dReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[291] /* fan.vol.steBal.eReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[292] /* fan.vol.steBal.fReg PARAM */)))) + (data->simulationInfo->realParameter[286] /* fan.vol.steBal.cReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[288] /* fan.vol.steBal.dReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[291] /* fan.vol.steBal.eReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[292] /* fan.vol.steBal.fReg PARAM */))))) + (data->simulationInfo->realParameter[285] /* fan.vol.steBal.bReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[286] /* fan.vol.steBal.cReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[288] /* fan.vol.steBal.dReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[291] /* fan.vol.steBal.eReg PARAM */) + (fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * ((data->simulationInfo->realParameter[292] /* fan.vol.steBal.fReg PARAM */)))))));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    }
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp12 = tmp10;
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  }
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  jacobian->tmpVars[37] /* fan.vol.steBal.m_flowInv.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = tmp12;
#line 190 OMC_FILE
  TRACE_POP
}

/*
equation index: 957
type: SIMPLE_ASSIGN
fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER = 0.001004433569776996 * fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_957(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,957};
#line 451 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  jacobian->tmpVars[19] /* fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (0.001004433569776996) * (jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */);
#line 207 OMC_FILE
  TRACE_POP
}

/*
equation index: 958
type: SIMPLE_ASSIGN
resSup.dp.$pDERFMIDER.dummyVarFMIDER = fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER * resSup.coeff
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_958(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,958};
#line 38 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  jacobian->tmpVars[51] /* resSup.dp.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */) * ((data->simulationInfo->realParameter[357] /* resSup.coeff PARAM */));
#line 224 OMC_FILE
  TRACE_POP
}

/*
equation index: 959
type: SIMPLE_ASSIGN
$cse8.p.$pDERFMIDER.dummyVarFMIDER = -(if hea.preDro.dp_nominal_pos > 1e-15 then fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER * $DER$Buildings$PFluid$PBaseClasses$PFlowModels$PbasicFlowFunction_m_flow(fluPor[1].m_flow, hea.preDro.k, hea.preDro.m_flow_turbulent, 1.0, 0.0, 0.0) else 0.0)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_959(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,959};
  modelica_boolean tmp13;
  tmp13 = Greater((data->simulationInfo->realParameter[326] /* hea.preDro.dp_nominal_pos PARAM */),1e-15);
  jacobian->tmpVars[12] /* $cse8.p.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (-((tmp13?(jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */) * (omc__omcQ_24DER_24Buildings_24PFluid_24PBaseClasses_24PFlowModels_24PbasicFlowFunction_5F_5Fm_5F_5Fflow(threadData, (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), (data->simulationInfo->realParameter[328] /* hea.preDro.k PARAM */), (data->simulationInfo->realParameter[332] /* hea.preDro.m_flow_turbulent PARAM */), 1.0, 0.0, 0.0)):0.0)));
  TRACE_POP
}

/*
equation index: 960
type: SIMPLE_ASSIGN
fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER = resSup.dp.$pDERFMIDER.dummyVarFMIDER - $cse8.p.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_960(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,960};
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Sensors/RelativePressure.mo"
  jacobian->tmpVars[35] /* fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[51] /* resSup.dp.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[12] /* $cse8.p.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 258 OMC_FILE
  TRACE_POP
}

/*
equation index: 961
type: SIMPLE_ASSIGN
fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER = smooth(0, if noEvent(fan.senRelPre.p_rel * fan.VMachine_flow > 0.5 * fan.eff.deltaP) then fan.senRelPre.p_rel * fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER + fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER * fan.VMachine_flow else if noEvent(fan.senRelPre.p_rel * fan.VMachine_flow < (-0.5) * fan.eff.deltaP) then 0.0 else if noEvent(0.5 * fan.eff.deltaP > 0.0) then ((-fan.senRelPre.p_rel) * fan.VMachine_flow * 2.0 * ((4.0 * (fan.senRelPre.p_rel * fan.VMachine_flow / fan.eff.deltaP) ^ 2.0 - 3.0) * (fan.senRelPre.p_rel * fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER + fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER * fan.VMachine_flow) + 4.0 * 2.0 * fan.senRelPre.p_rel * fan.VMachine_flow / fan.eff.deltaP * (fan.senRelPre.p_rel * fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER * fan.eff.deltaP / fan.eff.deltaP ^ 2.0 + fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER * fan.VMachine_flow / fan.eff.deltaP) * fan.senRelPre.p_rel * fan.VMachine_flow) + ((-fan.senRelPre.p_rel) * fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER - fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER * fan.VMachine_flow) * (4.0 * (fan.senRelPre.p_rel * fan.VMachine_flow / fan.eff.deltaP) ^ 2.0 - 3.0) * 2.0 * fan.senRelPre.p_rel * fan.VMachine_flow) * fan.eff.deltaP * 4.0 / (fan.eff.deltaP * 4.0) ^ 2.0 + 0.5 * (fan.senRelPre.p_rel * fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER + fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER * fan.VMachine_flow) else 0.5 * (fan.senRelPre.p_rel * fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER + fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER * fan.VMachine_flow))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_961(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,961};
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  modelica_boolean tmp23;
  modelica_real tmp24;
  modelica_boolean tmp25;
  modelica_real tmp26;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp14 = Greater(((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(0.5) * ((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp25 = (modelica_boolean)tmp14;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  if(tmp25)
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp26 = ((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * (jacobian->tmpVars[19] /* fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (jacobian->tmpVars[35] /* fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  else
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp15 = Less(((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(-0.5) * ((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp23 = (modelica_boolean)tmp15;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    if(tmp23)
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp24 = 0.0;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    else
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp16 = Greater((0.5) * ((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)),0.0);
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp21 = (modelica_boolean)tmp16;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      if(tmp21)
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        tmp17 = ((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * (DIVISION((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */),(data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */),"fan.eff.deltaP"));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        tmp18 = (data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */);
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        tmp19 = ((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * (DIVISION((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */),(data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */),"fan.eff.deltaP"));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        tmp20 = ((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)) * (4.0);
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        tmp22 = DIVISION(((((-(data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */))) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */))) * ((2.0) * (((4.0) * ((tmp17 * tmp17)) - 3.0) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * (jacobian->tmpVars[19] /* fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (jacobian->tmpVars[35] /* fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */))) + ((4.0) * (((2.0) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * (DIVISION((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */),(data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */),"fan.eff.deltaP")))) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * (DIVISION((jacobian->tmpVars[19] /* fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)),(tmp18 * tmp18),"fan.eff.deltaP ^ 2.0")) + (jacobian->tmpVars[35] /* fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * (DIVISION((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */),(data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */),"fan.eff.deltaP"))))) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */))))) + (((-(data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */))) * (jacobian->tmpVars[19] /* fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - ((jacobian->tmpVars[35] /* fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)))) * (((4.0) * ((tmp19 * tmp19)) - 3.0) * ((2.0) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)))))) * (((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)) * (4.0)),(tmp20 * tmp20),"(fan.eff.deltaP * 4.0) ^ 2.0") + (0.5) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * (jacobian->tmpVars[19] /* fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (jacobian->tmpVars[35] /* fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      else
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        tmp22 = (0.5) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * (jacobian->tmpVars[19] /* fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (jacobian->tmpVars[35] /* fan.senRelPre.p_rel.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp24 = tmp22;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp26 = tmp24;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  jacobian->tmpVars[23] /* fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = tmp26;
#line 356 OMC_FILE
  TRACE_POP
}

/*
equation index: 962
type: SIMPLE_ASSIGN
fan.eff.P_internal.$pDERFMIDER.dummyVarFMIDER = 1.428571428571429 * fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_962(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,962};
#line 654 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  jacobian->tmpVars[22] /* fan.eff.P_internal.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (1.428571428571429) * (jacobian->tmpVars[23] /* fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 373 OMC_FILE
  TRACE_POP
}

/*
equation index: 963
type: SIMPLE_ASSIGN
fan.P.$pDERFMIDER.dummyVarFMIDER = 2.040816326530613 * fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_963(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,963};
#line 607 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  jacobian->tmpVars[17] /* fan.P.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (2.040816326530613) * (jacobian->tmpVars[23] /* fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 390 OMC_FILE
  TRACE_POP
}

/*
equation index: 964
type: SIMPLE_ASSIGN
fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER = (if fan.per.motorCooledByFluid then fan.P.$pDERFMIDER.dummyVarFMIDER else fan.eff.P_internal.$pDERFMIDER.dummyVarFMIDER) - fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_964(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,964};
#line 59 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  jacobian->tmpVars[28] /* fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = ((data->simulationInfo->booleanParameter[26] /* fan.per.motorCooledByFluid PARAM */)?jacobian->tmpVars[17] /* fan.P.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */:jacobian->tmpVars[22] /* fan.eff.P_internal.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[23] /* fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 407 OMC_FILE
  TRACE_POP
}

/*
equation index: 965
type: SIMPLE_ASSIGN
fan.PToMed.u1.$pDERFMIDER.dummyVarFMIDER = smooth(0, if noEvent(abs(fan.VMachine_flow) + (-2.0) * fan.heaDis.delta_V_flow > fan.heaDis.delta_V_flow) then fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER else if noEvent(abs(fan.VMachine_flow) + (-2.0) * fan.heaDis.delta_V_flow < (-fan.heaDis.delta_V_flow)) then 0.0 else if noEvent(fan.heaDis.delta_V_flow > 0.0) then 0.25 * ((2.0 - abs(fan.VMachine_flow) / fan.heaDis.delta_V_flow) * ((abs(fan.VMachine_flow) / fan.heaDis.delta_V_flow + -2.0) ^ 2.0 - 3.0) * fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER + ((2.0 - abs(fan.VMachine_flow) / fan.heaDis.delta_V_flow) * 2.0 * (abs(fan.VMachine_flow) / fan.heaDis.delta_V_flow + -2.0) * sign(fan.VMachine_flow) * fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER * fan.heaDis.delta_V_flow / fan.heaDis.delta_V_flow ^ 2.0 - sign(fan.VMachine_flow) * fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER * fan.heaDis.delta_V_flow / fan.heaDis.delta_V_flow ^ 2.0 * ((abs(fan.VMachine_flow) / fan.heaDis.delta_V_flow + -2.0) ^ 2.0 - 3.0)) * fan.heaDis.QThe_flow) + 0.5 * fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER else 0.5 * fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_965(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,965};
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  modelica_boolean tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_real tmp33;
  modelica_boolean tmp34;
  modelica_real tmp35;
  modelica_boolean tmp36;
  modelica_real tmp37;
  modelica_boolean tmp38;
  modelica_real tmp39;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  tmp27 = Greater(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)) + (-2.0) * ((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  tmp38 = (modelica_boolean)tmp27;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  if(tmp38)
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp39 = jacobian->tmpVars[28] /* fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  else
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp28 = Less(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)) + (-2.0) * ((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)),(-(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp36 = (modelica_boolean)tmp28;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    if(tmp36)
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp37 = 0.0;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    else
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp29 = Greater((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),0.0);
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp34 = (modelica_boolean)tmp29;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      if(tmp34)
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp30 = DIVISION(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),"fan.heaDis.delta_V_flow") + -2.0;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp31 = (data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */);
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp32 = (data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */);
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp33 = DIVISION(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),"fan.heaDis.delta_V_flow") + -2.0;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp35 = (0.25) * (((2.0 - (DIVISION(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),"fan.heaDis.delta_V_flow"))) * ((tmp30 * tmp30) - 3.0)) * (jacobian->tmpVars[28] /* fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + ((2.0 - (DIVISION(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),"fan.heaDis.delta_V_flow"))) * (DIVISION(((2.0) * (DIVISION(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),"fan.heaDis.delta_V_flow") + -2.0)) * (((sign((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */))) * (jacobian->tmpVars[19] /* fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */)) * ((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */))),(tmp31 * tmp31),"fan.heaDis.delta_V_flow ^ 2.0")) - ((DIVISION(((sign((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */))) * (jacobian->tmpVars[19] /* fan.VMachine_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */)) * ((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)),(tmp32 * tmp32),"fan.heaDis.delta_V_flow ^ 2.0")) * ((tmp33 * tmp33) - 3.0))) * ((data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */))) + (0.5) * (jacobian->tmpVars[28] /* fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      else
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp35 = (0.5) * (jacobian->tmpVars[28] /* fan.heaDis.QThe_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp37 = tmp35;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp39 = tmp37;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  jacobian->tmpVars[18] /* fan.PToMed.u1.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = tmp39;
#line 505 OMC_FILE
  TRACE_POP
}

/*
equation index: 966
type: SIMPLE_ASSIGN
fan.prePow.Q_flow.$pDERFMIDER.dummyVarFMIDER = fan.PToMed.u1.$pDERFMIDER.dummyVarFMIDER + fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_966(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,966};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->tmpVars[33] /* fan.prePow.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[18] /* fan.PToMed.u1.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[23] /* fan.eff.WFlo.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 522 OMC_FILE
  TRACE_POP
}

/*
equation index: 967
type: SIMPLE_ASSIGN
hea.outCon.m_flow_pos.$pDERFMIDER.dummyVarFMIDER = smooth(0, if noEvent(fluPor[1].m_flow > hea.outCon.m_flow_small) then fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER else if noEvent(fluPor[1].m_flow < (-hea.outCon.m_flow_small)) then 0.0 else if noEvent(hea.outCon.m_flow_small > 0.0) then 0.25 * ((3.0 - (fluPor[1].m_flow / hea.outCon.m_flow_small) ^ 2.0) * 2.0 * fluPor[1].m_flow * fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER - 2.0 * fluPor[1].m_flow / hea.outCon.m_flow_small * fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER * hea.outCon.m_flow_small / hea.outCon.m_flow_small ^ 2.0 * fluPor[1].m_flow ^ 2.0) * hea.outCon.m_flow_small / hea.outCon.m_flow_small ^ 2.0 + 0.5 * fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER else 0.5 * fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_967(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,967};
  modelica_boolean tmp40;
  modelica_boolean tmp41;
  modelica_boolean tmp42;
  modelica_real tmp43;
  modelica_real tmp44;
  modelica_real tmp45;
  modelica_real tmp46;
  modelica_boolean tmp47;
  modelica_real tmp48;
  modelica_boolean tmp49;
  modelica_real tmp50;
  modelica_boolean tmp51;
  modelica_real tmp52;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp40 = Greater((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */));
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp51 = (modelica_boolean)tmp40;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  if(tmp51)
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp52 = jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  else
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp41 = Less((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(-(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */)));
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp49 = (modelica_boolean)tmp41;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    if(tmp49)
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp50 = 0.0;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    else
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp42 = Greater((data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),0.0);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp47 = (modelica_boolean)tmp42;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      if(tmp47)
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp43 = DIVISION((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),"hea.outCon.m_flow_small");
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp44 = (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp45 = (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp46 = (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp48 = (0.25) * (DIVISION(((3.0 - ((tmp43 * tmp43))) * (((2.0) * ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) * (jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */)) - ((DIVISION(((2.0) * (DIVISION((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),"hea.outCon.m_flow_small"))) * ((jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */) * ((data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */))),(tmp44 * tmp44),"hea.outCon.m_flow_small ^ 2.0")) * ((tmp45 * tmp45)))) * ((data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */)),(tmp46 * tmp46),"hea.outCon.m_flow_small ^ 2.0")) + (0.5) * (jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      else
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp48 = (0.5) * (jacobian->resultVars[7] /* fluPor.1.m_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp50 = tmp48;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp52 = tmp50;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  jacobian->tmpVars[44] /* hea.outCon.m_flow_pos.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = tmp52;
#line 620 OMC_FILE
  TRACE_POP
}

/*
equation index: 968
type: SIMPLE_ASSIGN
fan.filter.x.$pDERFMIDER.dummyVarFMIDER[1] = fan.filter.u_nom * fan.filter.s.SeedFMIDER[1]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_968(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,968};
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  jacobian->tmpVars[26] /* fan.filter.x.$pDERFMIDER.dummyVarFMIDER[1] JACOBIAN_DIFF_VAR */ = ((data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */)) * (jacobian->seedVars[0] /* fan.filter.s.SeedFMIDER[1] SEED_VAR */);
#line 637 OMC_FILE
  TRACE_POP
}

/*
equation index: 969
type: SIMPLE_ASSIGN
$DER.fan.filter.s.$pDERFMIDER.dummyVarFMIDER[1] = (ovePum.SeedFMIDER - fan.filter.x.$pDERFMIDER.dummyVarFMIDER[1]) * fan.filter.w_u
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_969(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,969};
#line 50 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  jacobian->resultVars[0] /* der(fan.filter.s.$pDERFMIDER.dummyVarFMIDER[1]) JACOBIAN_VAR */ = (jacobian->seedVars[6] /* ovePum.SeedFMIDER SEED_VAR */ - jacobian->tmpVars[26] /* fan.filter.x.$pDERFMIDER.dummyVarFMIDER[1] JACOBIAN_DIFF_VAR */) * ((data->simulationInfo->realParameter[197] /* fan.filter.w_u PARAM */));
#line 654 OMC_FILE
  TRACE_POP
}

/*
equation index: 970
type: SIMPLE_ASSIGN
bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER = 4184.0 * $cse1.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_970(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,970};
  jacobian->tmpVars[16] /* bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (4184.0) * (jacobian->tmpVars[0] /* $cse1.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
  TRACE_POP
}

/*
equation index: 971
type: SIMPLE_ASSIGN
fluPor.2.forward.T.$pDERFMIDER.dummyVarFMIDER = if fluPor[2].m_flow >= 0.0 then 0.0002390057361376673 * bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER else 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_971(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,971};
  modelica_boolean tmp53;
  relationhysteresis(data, &tmp53, (data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */), 0.0, 0, GreaterEq, GreaterEqZC);
  jacobian->resultVars[6] /* fluPor.2.forward.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */ = (tmp53?(0.0002390057361376673) * (jacobian->tmpVars[16] /* bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */):0.0);
  TRACE_POP
}

/*
equation index: 972
type: SIMPLE_ASSIGN
hea.outCon.dhAct.$pDERFMIDER.dummyVarFMIDER = smooth(0, if noEvent(hea.outCon.hSet - bou.ports[1].h_outflow > hea.outCon.deltaH) then hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER - bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER else if noEvent(hea.outCon.hSet - bou.ports[1].h_outflow < (-hea.outCon.deltaH)) then 0.0 else if noEvent(hea.outCon.deltaH > 0.0) then 0.25 * ((((hea.outCon.hSet - bou.ports[1].h_outflow) / hea.outCon.deltaH) ^ 2.0 - 3.0) * (bou.ports[1].h_outflow - hea.outCon.hSet) / hea.outCon.deltaH * (hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER - bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER) + ((((hea.outCon.hSet - bou.ports[1].h_outflow) / hea.outCon.deltaH) ^ 2.0 - 3.0) * (bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER - hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER) + 2.0 * (hea.outCon.hSet - bou.ports[1].h_outflow) / hea.outCon.deltaH * (hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER - bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER) * hea.outCon.deltaH / hea.outCon.deltaH ^ 2.0 * (bou.ports[1].h_outflow - hea.outCon.hSet)) * hea.outCon.deltaH / hea.outCon.deltaH ^ 2.0 * (hea.outCon.hSet - bou.ports[1].h_outflow)) + 0.5 * (hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER - bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER) else 0.5 * (hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER - bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_972(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,972};
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  modelica_boolean tmp56;
  modelica_real tmp57;
  modelica_real tmp58;
  modelica_real tmp59;
  modelica_real tmp60;
  modelica_boolean tmp61;
  modelica_real tmp62;
  modelica_boolean tmp63;
  modelica_real tmp64;
  modelica_boolean tmp65;
  modelica_real tmp66;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp54 = Greater((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */));
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp65 = (modelica_boolean)tmp54;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  if(tmp65)
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp66 = jacobian->tmpVars[40] /* hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[16] /* bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  else
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp55 = Less((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),(-(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */)));
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp63 = (modelica_boolean)tmp55;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    if(tmp63)
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp64 = 0.0;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    else
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp56 = Greater((data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */),0.0);
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp61 = (modelica_boolean)tmp56;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      if(tmp61)
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp57 = DIVISION((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */),"hea.outCon.deltaH");
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp58 = DIVISION((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */),"hea.outCon.deltaH");
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp59 = (data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */);
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp60 = (data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */);
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp62 = (0.25) * ((DIVISION(((tmp57 * tmp57) - 3.0) * ((data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */) - (data->localData[0]->realVars[76] /* hea.outCon.hSet variable */)),(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */),"hea.outCon.deltaH")) * (jacobian->tmpVars[40] /* hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[16] /* bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (DIVISION((((tmp58 * tmp58) - 3.0) * (jacobian->tmpVars[16] /* bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[40] /* hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (DIVISION(((2.0) * (DIVISION((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */),"hea.outCon.deltaH"))) * ((jacobian->tmpVars[40] /* hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[16] /* bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */))),(tmp59 * tmp59),"hea.outCon.deltaH ^ 2.0")) * ((data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */) - (data->localData[0]->realVars[76] /* hea.outCon.hSet variable */))) * ((data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */)),(tmp60 * tmp60),"hea.outCon.deltaH ^ 2.0")) * ((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */))) + (0.5) * (jacobian->tmpVars[40] /* hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[16] /* bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      else
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp62 = (0.5) * (jacobian->tmpVars[40] /* hea.outCon.hSet.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[16] /* bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp64 = tmp62;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp66 = tmp64;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  jacobian->tmpVars[39] /* hea.outCon.dhAct.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = tmp66;
#line 784 OMC_FILE
  TRACE_POP
}

/*
equation index: 973
type: SIMPLE_ASSIGN
y.$pDERFMIDER.dummyVarFMIDER = hea.outCon.m_flow_pos * hea.outCon.dhAct.$pDERFMIDER.dummyVarFMIDER + hea.outCon.m_flow_pos.$pDERFMIDER.dummyVarFMIDER * hea.outCon.dhAct
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_973(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,973};
#line 294 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  jacobian->resultVars[9] /* y.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */ = ((data->localData[0]->realVars[81] /* hea.outCon.m_flow_pos variable */)) * (jacobian->tmpVars[39] /* hea.outCon.dhAct.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (jacobian->tmpVars[44] /* hea.outCon.m_flow_pos.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[74] /* hea.outCon.dhAct variable */));
#line 801 OMC_FILE
  TRACE_POP
}

/*
equation index: 974
type: SIMPLE_ASSIGN
hea.port_a.h_outflow.$pDERFMIDER.dummyVarFMIDER = bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER + hea.outCon.dhAct.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_974(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,974};
#line 293 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  jacobian->tmpVars[45] /* hea.port_a.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[16] /* bou.ports.1.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[39] /* hea.outCon.dhAct.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 818 OMC_FILE
  TRACE_POP
}

/*
equation index: 975
type: SIMPLE_ASSIGN
fan.vol.ports.2.h_outflow.$pDERFMIDER.dummyVarFMIDER = hea.port_a.h_outflow.$pDERFMIDER.dummyVarFMIDER + fan.prePow.Q_flow * fan.vol.steBal.m_flowInv.$pDERFMIDER.dummyVarFMIDER + fan.prePow.Q_flow.$pDERFMIDER.dummyVarFMIDER * fan.vol.steBal.m_flowInv
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_975(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,975};
#line 209 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  jacobian->tmpVars[36] /* fan.vol.ports.2.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[45] /* hea.port_a.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + ((data->localData[0]->realVars[47] /* fan.prePow.Q_flow variable */)) * (jacobian->tmpVars[37] /* fan.vol.steBal.m_flowInv.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (jacobian->tmpVars[33] /* fan.prePow.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[62] /* fan.vol.steBal.m_flowInv variable */));
#line 835 OMC_FILE
  TRACE_POP
}

/*
equation index: 976
type: SIMPLE_ASSIGN
resSup.port_b.h_outflow.$pDERFMIDER.dummyVarFMIDER = $cse9 * (fan.vol.ports.2.h_outflow.$pDERFMIDER.dummyVarFMIDER * (1e-07 + $cse9) - fan.vol.ports[2].h_outflow * $cse9.$pDERFMIDER.dummyVarFMIDER) / (1e-07 + $cse9) ^ 2.0 + $cse9.$pDERFMIDER.dummyVarFMIDER * fan.vol.ports[2].h_outflow / (1e-07 + $cse9)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_976(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,976};
  modelica_real tmp67;
#line 428 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  tmp67 = 1e-07 + (data->localData[0]->realVars[17] /* $cse9 variable */);
#line 428 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  jacobian->tmpVars[52] /* resSup.port_b.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[17] /* $cse9 variable */)) * (DIVISION((jacobian->tmpVars[36] /* fan.vol.ports.2.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * (1e-07 + (data->localData[0]->realVars[17] /* $cse9 variable */)) - (((data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */)) * (jacobian->tmpVars[13] /* $cse9.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */)),(tmp67 * tmp67),"(1e-07 + $cse9) ^ 2.0")) + (jacobian->tmpVars[13] /* $cse9.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * (DIVISION((data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */),1e-07 + (data->localData[0]->realVars[17] /* $cse9 variable */),"1e-07 + $cse9"));
#line 855 OMC_FILE
  TRACE_POP
}

/*
equation index: 977
type: SIMPLE_ASSIGN
fluPor.1.forward.T.$pDERFMIDER.dummyVarFMIDER = if fluPor[1].m_flow >= 0.0 then 0.0002390057361376673 * resSup.port_b.h_outflow.$pDERFMIDER.dummyVarFMIDER else 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_977(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,977};
  modelica_boolean tmp68;
  relationhysteresis(data, &tmp68, (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), 0.0, 1, GreaterEq, GreaterEqZC);
  jacobian->resultVars[5] /* fluPor.1.forward.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */ = (tmp68?(0.0002390057361376673) * (jacobian->tmpVars[52] /* resSup.port_b.h_outflow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */):0.0);
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacFMIDER_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_FMIDER;
  
  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacFMIDER_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_FMIDER;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_950(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_951(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_952(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_953(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_954(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_955(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_956(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_957(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_958(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_959(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_960(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_961(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_962(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_963(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_964(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_965(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_966(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_967(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_968(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_969(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_970(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_971(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_972(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_973(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_974(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_975(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_976(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_977(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 978
type: SIMPLE_ASSIGN
fan.filter.x.$pDERA.dummyVarA[1] = fan.filter.u_nom * fan.filter.s.SeedA[1]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_978(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,978};
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  jacobian->tmpVars[29] /* fan.filter.x.$pDERA.dummyVarA[1] JACOBIAN_DIFF_VAR */ = ((data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */)) * (jacobian->seedVars[0] /* fan.filter.s.SeedA[1] SEED_VAR */);
#line 970 OMC_FILE
  TRACE_POP
}

/*
equation index: 979
type: SIMPLE_ASSIGN
$DER.fan.filter.s.$pDERA.dummyVarA[1] = (-fan.filter.x.$pDERA.dummyVarA[1]) * fan.filter.w_u
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_979(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,979};
#line 50 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  jacobian->resultVars[0] /* der(fan.filter.s.$pDERA.dummyVarA[1]) JACOBIAN_VAR */ = ((-jacobian->tmpVars[29] /* fan.filter.x.$pDERA.dummyVarA[1] JACOBIAN_DIFF_VAR */)) * ((data->simulationInfo->realParameter[197] /* fan.filter.w_u PARAM */));
#line 987 OMC_FILE
  TRACE_POP
}

/*
equation index: 980
type: SIMPLE_ASSIGN
$DER.fan.filter.s.$pDERA.dummyVarA[2] = fan.filter.u_nom * (fan.filter.s.SeedA[1] - fan.filter.s.SeedA[2]) * fan.filter.w_u
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_980(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,980};
#line 52 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  jacobian->resultVars[1] /* der(fan.filter.s.$pDERA.dummyVarA[2]) JACOBIAN_VAR */ = ((data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */)) * ((jacobian->seedVars[0] /* fan.filter.s.SeedA[1] SEED_VAR */ - jacobian->seedVars[1] /* fan.filter.s.SeedA[2] SEED_VAR */) * ((data->simulationInfo->realParameter[197] /* fan.filter.w_u PARAM */)));
#line 1004 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacA_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_A;
  
  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_A;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_978(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_979(data, threadData, jacobian, parentJacobian);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_980(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianFMIDER(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+7] = {0,2,6,0,2,0,0,1};
  const int rowIndex[11] = {0,1,1,5,6,7,8,9,5,9,0};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 7, 10, 63, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(7, 11, 2);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (7+1)*sizeof(unsigned int));
  
  for(i=2;i<7+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 11*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 2 columns */
  const int indices_1[2] = {1, 6};
  for(i=0; i<2; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 5 columns */
  const int indices_2[5] = {0, 3, 2, 5, 4};
  for(i=0; i<5; i++)
    jacobian->sparsePattern->colorCols[indices_2[i]] = 2;
  TRACE_POP
  return 0;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
OMC_DISABLE_OPT
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+2] = {0,2,1};
  const int rowIndex[3] = {0,1,1};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 2, 2, 63, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(2, 3, 2);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (2+1)*sizeof(unsigned int));
  
  for(i=2;i<2+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 3*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {1};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {0};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_2[i]] = 2;
  TRACE_POP
  return 0;
}



