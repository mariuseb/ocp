#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_03lsy.c"
#endif
/* Linear Systems */
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* linear systems */

/*
equation index: 2362
type: SIMPLE_ASSIGN
thermalZoneFourElements.convIntWall.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA - thermalZoneFourElements.TAir.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2362(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2362};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[218]) /* thermalZoneFourElements.convIntWall.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 26 OMC_FILE
  TRACE_POP
}
/*
equation index: 2363
type: SIMPLE_ASSIGN
thermalZoneFourElements.convIntWall.Q_flow.$pDERA.dummyVarA = 128.26 * thermalZoneFourElements.convIntWall.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2363(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2363};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[217]) /* thermalZoneFourElements.convIntWall.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (128.26) * ((parentJacobian->tmpVars[218]) /* thermalZoneFourElements.convIntWall.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 40 OMC_FILE
  TRACE_POP
}
/*
equation index: 2364
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermResInt.1.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA - thermalZoneFourElements.intWallRC.thermCapInt[1].T.SeedA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2364(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2364};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[240]) /* thermalZoneFourElements.intWallRC.thermResInt.1.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->seedVars[2]) /* thermalZoneFourElements.intWallRC.thermCapInt[1].T.SeedA SEED_VAR */;
#line 54 OMC_FILE
  TRACE_POP
}
/*
equation index: 2365
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermCapInt.1.port.Q_flow.$pDERA.dummyVarA = (-thermalZoneFourElements.intWallRC.thermResInt.1.dT.$pDERA.dummyVarA) / (-0.000668895639141)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2365(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2365};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[239]) /* thermalZoneFourElements.intWallRC.thermCapInt.1.port.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[240]) /* thermalZoneFourElements.intWallRC.thermResInt.1.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-0.000668895639141,"-0.000668895639141");
#line 68 OMC_FILE
  TRACE_POP
}
/*
equation index: 2366
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallFloor.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA - thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2366(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2366};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[258]) /* thermalZoneFourElements.resIntWallFloor.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 82 OMC_FILE
  TRACE_POP
}
/*
equation index: 2367
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERA.dummyVarA = 57.5 * thermalZoneFourElements.resIntWallFloor.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2367(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2367};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[257]) /* thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[258]) /* thermalZoneFourElements.resIntWallFloor.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 96 OMC_FILE
  TRACE_POP
}
/*
equation index: 2368
type: SIMPLE_ASSIGN
thermalZoneFourElements.convFloor.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA - thermalZoneFourElements.TAir.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2368(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2368};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[215]) /* thermalZoneFourElements.convFloor.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 110 OMC_FILE
  TRACE_POP
}
/*
equation index: 2369
type: SIMPLE_ASSIGN
thermalZoneFourElements.convFloor.Q_flow.$pDERA.dummyVarA = 31.05 * thermalZoneFourElements.convFloor.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2369(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2369};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[214]) /* thermalZoneFourElements.convFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (31.05) * ((parentJacobian->tmpVars[215]) /* thermalZoneFourElements.convFloor.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 124 OMC_FILE
  TRACE_POP
}
/*
equation index: 2370
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermResExt.1.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA - thermalZoneFourElements.floorRC.thermCapExt[1].T.SeedA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2370(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2370};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[235]) /* thermalZoneFourElements.floorRC.thermResExt.1.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->seedVars[1]) /* thermalZoneFourElements.floorRC.thermCapExt[1].T.SeedA SEED_VAR */;
#line 138 OMC_FILE
  TRACE_POP
}
/*
equation index: 2371
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.port_a.Q_flow.$pDERA.dummyVarA = (-thermalZoneFourElements.floorRC.thermResExt.1.dT.$pDERA.dummyVarA) / (-0.00331421908725)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2371(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2371};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[232]) /* thermalZoneFourElements.floorRC.port_a.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[235]) /* thermalZoneFourElements.floorRC.thermResExt.1.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-0.00331421908725,"-0.00331421908725");
#line 152 OMC_FILE
  TRACE_POP
}
/*
equation index: 2372
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallFloor.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA - thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2372(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2372};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[246]) /* thermalZoneFourElements.resExtWallFloor.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 166 OMC_FILE
  TRACE_POP
}
/*
equation index: 2373
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERA.dummyVarA = 57.5 * thermalZoneFourElements.resExtWallFloor.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2373(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2373};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[245]) /* thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[246]) /* thermalZoneFourElements.resExtWallFloor.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 180 OMC_FILE
  TRACE_POP
}
/*
equation index: 2374
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallIntWall.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA - thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2374(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2374};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[248]) /* thermalZoneFourElements.resExtWallIntWall.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 194 OMC_FILE
  TRACE_POP
}
/*
equation index: 2375
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERA.dummyVarA = 57.5 * thermalZoneFourElements.resExtWallIntWall.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2375(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2375};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[247]) /* thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[248]) /* thermalZoneFourElements.resExtWallIntWall.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 208 OMC_FILE
  TRACE_POP
}
/*
equation index: 2376
type: SIMPLE_ASSIGN
thermalZoneFourElements.convExtWall.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA - thermalZoneFourElements.TAir.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2376(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2376};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[213]) /* thermalZoneFourElements.convExtWall.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 222 OMC_FILE
  TRACE_POP
}
/*
equation index: 2377
type: SIMPLE_ASSIGN
thermalZoneFourElements.convExtWall.Q_flow.$pDERA.dummyVarA = 31.05 * thermalZoneFourElements.convExtWall.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2377(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2377};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[212]) /* thermalZoneFourElements.convExtWall.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (31.05) * ((parentJacobian->tmpVars[213]) /* thermalZoneFourElements.convExtWall.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 236 OMC_FILE
  TRACE_POP
}
/*
equation index: 2378
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermResExt.1.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA - thermalZoneFourElements.extWallRC.thermCapExt[1].T.SeedA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2378(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2378};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[229]) /* thermalZoneFourElements.extWallRC.thermResExt.1.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->seedVars[0]) /* thermalZoneFourElements.extWallRC.thermCapExt[1].T.SeedA SEED_VAR */;
#line 250 OMC_FILE
  TRACE_POP
}
/*
equation index: 2379
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.port_a.Q_flow.$pDERA.dummyVarA = (-thermalZoneFourElements.extWallRC.thermResExt.1.dT.$pDERA.dummyVarA) / (-0.00331421908725)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2379(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2379};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[226]) /* thermalZoneFourElements.extWallRC.port_a.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[229]) /* thermalZoneFourElements.extWallRC.thermResExt.1.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-0.00331421908725,"-0.00331421908725");
#line 264 OMC_FILE
  TRACE_POP
}
/*
equation index: 2380
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofFloor.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA - thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2380(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2380};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[262]) /* thermalZoneFourElements.resRoofFloor.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 278 OMC_FILE
  TRACE_POP
}
/*
equation index: 2381
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofFloor.Q_flow.$pDERA.dummyVarA = 57.5 * thermalZoneFourElements.resRoofFloor.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2381(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2381};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[261]) /* thermalZoneFourElements.resRoofFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[262]) /* thermalZoneFourElements.resRoofFloor.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 292 OMC_FILE
  TRACE_POP
}
/*
equation index: 2382
type: SIMPLE_ASSIGN
thermalZoneFourElements.resFloorWin.Q_flow.$pDERA.dummyVarA = thermalZoneFourElements.convFloor.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.floorRC.port_a.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.thermSplitterSolRad.portOut.5.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.resRoofFloor.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2382(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2382};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[253]) /* thermalZoneFourElements.resFloorWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[214]) /* thermalZoneFourElements.convFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[232]) /* thermalZoneFourElements.floorRC.port_a.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[280]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.5.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[261]) /* thermalZoneFourElements.resRoofFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[245]) /* thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[257]) /* thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 306 OMC_FILE
  TRACE_POP
}
/*
equation index: 2383
type: SIMPLE_ASSIGN
thermalZoneFourElements.resFloorWin.dT.$pDERA.dummyVarA = (-thermalZoneFourElements.resFloorWin.Q_flow.$pDERA.dummyVarA) / (-57.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2383(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2383};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[254]) /* thermalZoneFourElements.resFloorWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[253]) /* thermalZoneFourElements.resFloorWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-57.5,"-57.5");
#line 320 OMC_FILE
  TRACE_POP
}
/*
equation index: 2384
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA + thermalZoneFourElements.resFloorWin.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2384(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2384};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[254]) /* thermalZoneFourElements.resFloorWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 334 OMC_FILE
  TRACE_POP
}
/*
equation index: 2385
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallWin.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA - thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2385(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2385};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[252]) /* thermalZoneFourElements.resExtWallWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 348 OMC_FILE
  TRACE_POP
}
/*
equation index: 2386
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallWin.Q_flow.$pDERA.dummyVarA = 57.5 * thermalZoneFourElements.resExtWallWin.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2386(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2386};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[251]) /* thermalZoneFourElements.resExtWallWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[252]) /* thermalZoneFourElements.resExtWallWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 362 OMC_FILE
  TRACE_POP
}
/*
equation index: 2387
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERA.dummyVarA = thermalZoneFourElements.resExtWallWin.Q_flow.$pDERA.dummyVarA - (thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.convExtWall.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.extWallRC.port_a.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.thermSplitterSolRad.portOut.1.Q_flow.$pDERA.dummyVarA)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2387(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2387};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[249]) /* thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[251]) /* thermalZoneFourElements.resExtWallWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - ((parentJacobian->tmpVars[245]) /* thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[247]) /* thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[212]) /* thermalZoneFourElements.convExtWall.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[226]) /* thermalZoneFourElements.extWallRC.port_a.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[277]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 376 OMC_FILE
  TRACE_POP
}
/*
equation index: 2388
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallRoof.dT.$pDERA.dummyVarA = (-thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERA.dummyVarA) / (-57.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2388(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2388};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[250]) /* thermalZoneFourElements.resExtWallRoof.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[249]) /* thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-57.5,"-57.5");
#line 390 OMC_FILE
  TRACE_POP
}
/*
equation index: 2389
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofWin.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA - thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2389(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2389};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[264]) /* thermalZoneFourElements.resRoofWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 404 OMC_FILE
  TRACE_POP
}
/*
equation index: 2390
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofWin.Q_flow.$pDERA.dummyVarA = 57.5 * thermalZoneFourElements.resRoofWin.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2390(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2390};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[263]) /* thermalZoneFourElements.resRoofWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[264]) /* thermalZoneFourElements.resRoofWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 418 OMC_FILE
  TRACE_POP
}
/*
equation index: 2391
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntRoof.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA - thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2391(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2391};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[256]) /* thermalZoneFourElements.resIntRoof.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 432 OMC_FILE
  TRACE_POP
}
/*
equation index: 2392
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntRoof.Q_flow.$pDERA.dummyVarA = 57.5 * thermalZoneFourElements.resIntRoof.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2392(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2392};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[255]) /* thermalZoneFourElements.resIntRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[256]) /* thermalZoneFourElements.resIntRoof.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 446 OMC_FILE
  TRACE_POP
}
/*
equation index: 2393
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallWin.Q_flow.$pDERA.dummyVarA = thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.convIntWall.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.intWallRC.thermCapInt.1.port.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.thermSplitterSolRad.portOut.3.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.resIntRoof.Q_flow.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2393(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2393};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[259]) /* thermalZoneFourElements.resIntWallWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[257]) /* thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[217]) /* thermalZoneFourElements.convIntWall.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[239]) /* thermalZoneFourElements.intWallRC.thermCapInt.1.port.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[279]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.3.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[247]) /* thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[255]) /* thermalZoneFourElements.resIntRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 460 OMC_FILE
  TRACE_POP
}
/*
equation index: 2394
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallWin.dT.$pDERA.dummyVarA = (-thermalZoneFourElements.resIntWallWin.Q_flow.$pDERA.dummyVarA) / (-70.0)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2394(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2394};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[260]) /* thermalZoneFourElements.resIntWallWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[259]) /* thermalZoneFourElements.resIntWallWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-70.0,"-70.0");
#line 474 OMC_FILE
  TRACE_POP
}
/*
equation index: 2395
type: SIMPLE_ASSIGN
thermalZoneFourElements.convWin.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA - thermalZoneFourElements.TAir.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2395(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2395};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[222]) /* thermalZoneFourElements.convWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 488 OMC_FILE
  TRACE_POP
}
/*
equation index: 2396
type: SIMPLE_ASSIGN
thermalZoneFourElements.convWin.Q_flow.$pDERA.dummyVarA = 37.8 * thermalZoneFourElements.convWin.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2396(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2396};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[221]) /* thermalZoneFourElements.convWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (37.8) * ((parentJacobian->tmpVars[222]) /* thermalZoneFourElements.convWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 502 OMC_FILE
  TRACE_POP
}
/*
equation index: 2397
type: SIMPLE_ASSIGN
theConWin.Q_flow.$pDERA.dummyVarA = (-thermalZoneFourElements.resRoofWin.Q_flow.$pDERA.dummyVarA) - thermalZoneFourElements.resFloorWin.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.resIntWallWin.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.resExtWallWin.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.convWin.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.thermSplitterSolRad.portOut.2.Q_flow.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2397(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2397};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[207]) /* theConWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (-(parentJacobian->tmpVars[263]) /* thermalZoneFourElements.resRoofWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[253]) /* thermalZoneFourElements.resFloorWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[259]) /* thermalZoneFourElements.resIntWallWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[251]) /* thermalZoneFourElements.resExtWallWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[221]) /* thermalZoneFourElements.convWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[278]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 516 OMC_FILE
  TRACE_POP
}
/*
equation index: 2398
type: SIMPLE_ASSIGN
thermalZoneFourElements.resWin.dT.$pDERA.dummyVarA = (-0.01642857143) * theConWin.Q_flow.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2398(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2398};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[265]) /* thermalZoneFourElements.resWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (-0.01642857143) * ((parentJacobian->tmpVars[207]) /* theConWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 530 OMC_FILE
  TRACE_POP
}
/*
equation index: 2399
type: SIMPLE_ASSIGN
theConWin.dT.$pDERA.dummyVarA = (-theConWin.Q_flow.$pDERA.dummyVarA) / (-280.0)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2399(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2399};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[208]) /* theConWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[207]) /* theConWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-280.0,"-280.0");
#line 544 OMC_FILE
  TRACE_POP
}
/*
equation index: 2400
type: SIMPLE_ASSIGN
theConWin.solid.T.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA + thermalZoneFourElements.resWin.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2400(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2400};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[209]) /* theConWin.solid.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[265]) /* thermalZoneFourElements.resWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 558 OMC_FILE
  TRACE_POP
}
/*
equation index: 2401
type: SIMPLE_ASSIGN
thermalZoneFourElements.convRoof.dT.$pDERA.dummyVarA = thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA - thermalZoneFourElements.TAir.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2401(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2401};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[220]) /* thermalZoneFourElements.convRoof.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 572 OMC_FILE
  TRACE_POP
}
/*
equation index: 2402
type: SIMPLE_ASSIGN
thermalZoneFourElements.convRoof.Q_flow.$pDERA.dummyVarA = 31.05 * thermalZoneFourElements.convRoof.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2402(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2402};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[219]) /* thermalZoneFourElements.convRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (31.05) * ((parentJacobian->tmpVars[220]) /* thermalZoneFourElements.convRoof.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 586 OMC_FILE
  TRACE_POP
}
/*
equation index: 2403
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.port_a.Q_flow.$pDERA.dummyVarA = thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERA.dummyVarA - (thermalZoneFourElements.resRoofFloor.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.resIntRoof.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.convRoof.Q_flow.$pDERA.dummyVarA + thermalZoneFourElements.thermSplitterSolRad.portOut.5.Q_flow.$pDERA.dummyVarA - thermalZoneFourElements.resRoofWin.Q_flow.$pDERA.dummyVarA)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2403(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2403};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[266]) /* thermalZoneFourElements.roofRC.port_a.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[249]) /* thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - ((parentJacobian->tmpVars[261]) /* thermalZoneFourElements.resRoofFloor.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[255]) /* thermalZoneFourElements.resIntRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[219]) /* thermalZoneFourElements.convRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[280]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.5.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[263]) /* thermalZoneFourElements.resRoofWin.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 600 OMC_FILE
  TRACE_POP
}
/*
equation index: 2404
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermResExt.1.dT.$pDERA.dummyVarA = 0.00331421908725 * thermalZoneFourElements.roofRC.port_a.Q_flow.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2404(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2404};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[269]) /* thermalZoneFourElements.roofRC.thermResExt.1.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (0.00331421908725) * ((parentJacobian->tmpVars[266]) /* thermalZoneFourElements.roofRC.port_a.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */);
#line 614 OMC_FILE
  TRACE_POP
}

void residualFunc2448(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,2448};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[11].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = xloc[0];
  (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = xloc[1];
  (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = xloc[2];
  (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = xloc[3];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2362(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2363(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2364(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2365(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2366(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2367(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2368(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2369(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2370(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2371(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2372(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2373(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2374(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2375(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2376(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2377(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2378(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2379(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2380(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2381(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2382(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2383(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2384(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2385(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2386(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2387(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2388(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2389(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2390(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2391(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2392(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2393(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2394(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2395(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2396(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2397(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2398(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2399(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2400(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2401(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2402(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2403(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2404(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[209]) /* theConWin.solid.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[186]) /* eqAirTemp.TEqWin.$pDERA.dummyVarA[2] JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[208]) /* theConWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;

  res[1] = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[260]) /* thermalZoneFourElements.resIntWallWin.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;

  res[2] = (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (-(parentJacobian->seedVars[3]) /* thermalZoneFourElements.roofRC.thermCapExt[1].T.SeedA SEED_VAR */) - (parentJacobian->tmpVars[269]) /* thermalZoneFourElements.roofRC.thermResExt.1.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;

  res[3] = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[250]) /* thermalZoneFourElements.resExtWallRoof.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData2448(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA */
  linearSystemData->nominal[i] = data->modelData->realVarsData[276].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[276].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[276].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERA.dummyVarA */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA */
  linearSystemData->nominal[i] = data->modelData->realVarsData[281].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[281].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[281].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERA.dummyVarA */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA */
  linearSystemData->nominal[i] = data->modelData->realVarsData[275].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[275].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[275].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERA.dummyVarA */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA */
  linearSystemData->nominal[i] = data->modelData->realVarsData[274].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[274].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[274].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERA.dummyVarA */.max;
}


/*
equation index: 2354
type: SIMPLE_ASSIGN
theConRoof.Q_flow.$pDERA.dummyVarA = (-thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERA.dummyVarA) / (-0.1265217391)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2354(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2354};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[202]) /* theConRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[270]) /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-0.1265217391,"-0.1265217391");
#line 801 OMC_FILE
  TRACE_POP
}
/*
equation index: 2355
type: SIMPLE_ASSIGN
theConRoof.dT.$pDERA.dummyVarA = (-theConRoof.Q_flow.$pDERA.dummyVarA) / (-287.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2355(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2355};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[203]) /* theConRoof.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[202]) /* theConRoof.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-287.5,"-287.5");
#line 815 OMC_FILE
  TRACE_POP
}
/*
equation index: 2356
type: SIMPLE_ASSIGN
theConRoof.solid.T.$pDERA.dummyVarA = thermalZoneFourElements.roofRC.thermCapExt[1].T.SeedA - thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2356(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2356};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[204]) /* theConRoof.solid.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->seedVars[3]) /* thermalZoneFourElements.roofRC.thermCapExt[1].T.SeedA SEED_VAR */ - (parentJacobian->tmpVars[270]) /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 829 OMC_FILE
  TRACE_POP
}

void residualFunc2361(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,2361};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[10].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[270]) /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = xloc[0];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2354(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2355(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2356(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[204]) /* theConRoof.solid.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[190]) /* eqAirTempVDI.TEqWall.$pDERA.dummyVarA[1] JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[203]) /* theConRoof.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData2361(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERA.dummyVarA */
  linearSystemData->nominal[i] = data->modelData->realVarsData[270].attribute /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERA.dummyVarA */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[270].attribute /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERA.dummyVarA */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[270].attribute /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERA.dummyVarA */.max;
}


/*
equation index: 2345
type: SIMPLE_ASSIGN
theConWall.Q_flow.$pDERA.dummyVarA = (-thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERA.dummyVarA) / (-0.1265217391)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2345(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2345};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[205]) /* theConWall.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[230]) /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-0.1265217391,"-0.1265217391");
#line 875 OMC_FILE
  TRACE_POP
}
/*
equation index: 2346
type: SIMPLE_ASSIGN
theConWall.dT.$pDERA.dummyVarA = (-theConWall.Q_flow.$pDERA.dummyVarA) / (-287.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2346(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2346};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[206]) /* theConWall.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[205]) /* theConWall.Q_flow.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */),-287.5,"-287.5");
#line 889 OMC_FILE
  TRACE_POP
}
/*
equation index: 2347
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWall.T.$pDERA.dummyVarA = thermalZoneFourElements.extWallRC.thermCapExt[1].T.SeedA - thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2347(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2347};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[225]) /* thermalZoneFourElements.extWall.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->seedVars[0]) /* thermalZoneFourElements.extWallRC.thermCapExt[1].T.SeedA SEED_VAR */ - (parentJacobian->tmpVars[230]) /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
#line 903 OMC_FILE
  TRACE_POP
}

void residualFunc2352(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,2352};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[9].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[230]) /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = xloc[0];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2345(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2346(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2347(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[225]) /* thermalZoneFourElements.extWall.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[198]) /* preTem.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[206]) /* theConWall.dT.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData2352(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERA.dummyVarA */
  linearSystemData->nominal[i] = data->modelData->realVarsData[230].attribute /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERA.dummyVarA */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[230].attribute /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERA.dummyVarA */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[230].attribute /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERA.dummyVarA */.max;
}


/*
equation index: 2189
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.hOut_internal.$pDERA.dummyVarA = thermalZoneFourElements.volAir.dynBal.medium.u.$pDERA.dummyVarA - (-287.0509010514002) * thermalZoneFourElements.volAir.dynBal.medium.T.$pDERA.dummyVarA
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2189(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2189};
#line 6186 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (parentJacobian->tmpVars[289]) /* thermalZoneFourElements.volAir.hOut_internal.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[288]) /* thermalZoneFourElements.volAir.dynBal.medium.u.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ - ((-287.0509010514002) * ((parentJacobian->tmpVars[283]) /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */));
#line 949 OMC_FILE
  TRACE_POP
}

void residualFunc2193(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,2193};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[8].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[283]) /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */ = xloc[0];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2189(data, threadData, jacobian, parentJacobian);
  res[0] = (1005.45) * ((parentJacobian->tmpVars[283]) /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[289]) /* thermalZoneFourElements.volAir.hOut_internal.$pDERA.dummyVarA JACOBIAN_DIFF_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData2193(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.volAir.dynBal.medium.T.$pDERA.dummyVarA */
  linearSystemData->nominal[i] = data->modelData->realVarsData[283].attribute /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERA.dummyVarA */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[283].attribute /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERA.dummyVarA */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[283].attribute /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERA.dummyVarA */.max;
}


/*
equation index: 1794
type: SIMPLE_ASSIGN
thermalZoneFourElements.convIntWall.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1794(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1794};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[218]) /* thermalZoneFourElements.convIntWall.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 989 OMC_FILE
  TRACE_POP
}
/*
equation index: 1795
type: SIMPLE_ASSIGN
thermalZoneFourElements.convIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER = 128.26 * thermalZoneFourElements.convIntWall.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1795(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1795};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[217]) /* thermalZoneFourElements.convIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (128.26) * ((parentJacobian->tmpVars[218]) /* thermalZoneFourElements.convIntWall.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1003 OMC_FILE
  TRACE_POP
}
/*
equation index: 1796
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermResInt.1.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.intWallRC.thermCapInt[1].T.SeedFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1796(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1796};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[240]) /* thermalZoneFourElements.intWallRC.thermResInt.1.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->seedVars[2]) /* thermalZoneFourElements.intWallRC.thermCapInt[1].T.SeedFMIDER SEED_VAR */;
#line 1017 OMC_FILE
  TRACE_POP
}
/*
equation index: 1797
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermCapInt.1.port.Q_flow.$pDERFMIDER.dummyVarFMIDER = (-thermalZoneFourElements.intWallRC.thermResInt.1.dT.$pDERFMIDER.dummyVarFMIDER) / (-0.000668895639141)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1797(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1797};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[239]) /* thermalZoneFourElements.intWallRC.thermCapInt.1.port.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[240]) /* thermalZoneFourElements.intWallRC.thermResInt.1.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-0.000668895639141,"-0.000668895639141");
#line 1031 OMC_FILE
  TRACE_POP
}
/*
equation index: 1798
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallFloor.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1798(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1798};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[258]) /* thermalZoneFourElements.resIntWallFloor.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1045 OMC_FILE
  TRACE_POP
}
/*
equation index: 1799
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER = 57.5 * thermalZoneFourElements.resIntWallFloor.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1799(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1799};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[257]) /* thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[258]) /* thermalZoneFourElements.resIntWallFloor.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1059 OMC_FILE
  TRACE_POP
}
/*
equation index: 1800
type: SIMPLE_ASSIGN
thermalZoneFourElements.convFloor.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1800(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1800};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[215]) /* thermalZoneFourElements.convFloor.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1073 OMC_FILE
  TRACE_POP
}
/*
equation index: 1801
type: SIMPLE_ASSIGN
thermalZoneFourElements.convFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER = 31.05 * thermalZoneFourElements.convFloor.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1801(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1801};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[214]) /* thermalZoneFourElements.convFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (31.05) * ((parentJacobian->tmpVars[215]) /* thermalZoneFourElements.convFloor.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1087 OMC_FILE
  TRACE_POP
}
/*
equation index: 1802
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.floorRC.thermCapExt[1].T.SeedFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1802(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1802};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[235]) /* thermalZoneFourElements.floorRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->seedVars[1]) /* thermalZoneFourElements.floorRC.thermCapExt[1].T.SeedFMIDER SEED_VAR */;
#line 1101 OMC_FILE
  TRACE_POP
}
/*
equation index: 1803
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER = (-thermalZoneFourElements.floorRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER) / (-0.00331421908725)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1803(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1803};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[232]) /* thermalZoneFourElements.floorRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[235]) /* thermalZoneFourElements.floorRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-0.00331421908725,"-0.00331421908725");
#line 1115 OMC_FILE
  TRACE_POP
}
/*
equation index: 1804
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallFloor.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1804(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1804};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[246]) /* thermalZoneFourElements.resExtWallFloor.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1129 OMC_FILE
  TRACE_POP
}
/*
equation index: 1805
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER = 57.5 * thermalZoneFourElements.resExtWallFloor.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1805(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1805};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[245]) /* thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[246]) /* thermalZoneFourElements.resExtWallFloor.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1143 OMC_FILE
  TRACE_POP
}
/*
equation index: 1806
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallIntWall.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1806(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1806};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[248]) /* thermalZoneFourElements.resExtWallIntWall.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1157 OMC_FILE
  TRACE_POP
}
/*
equation index: 1807
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER = 57.5 * thermalZoneFourElements.resExtWallIntWall.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1807(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1807};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[247]) /* thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[248]) /* thermalZoneFourElements.resExtWallIntWall.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1171 OMC_FILE
  TRACE_POP
}
/*
equation index: 1808
type: SIMPLE_ASSIGN
thermalZoneFourElements.convExtWall.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1808(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1808};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[213]) /* thermalZoneFourElements.convExtWall.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1185 OMC_FILE
  TRACE_POP
}
/*
equation index: 1809
type: SIMPLE_ASSIGN
thermalZoneFourElements.convExtWall.Q_flow.$pDERFMIDER.dummyVarFMIDER = 31.05 * thermalZoneFourElements.convExtWall.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1809(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1809};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[212]) /* thermalZoneFourElements.convExtWall.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (31.05) * ((parentJacobian->tmpVars[213]) /* thermalZoneFourElements.convExtWall.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1199 OMC_FILE
  TRACE_POP
}
/*
equation index: 1810
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.extWallRC.thermCapExt[1].T.SeedFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1810(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1810};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[229]) /* thermalZoneFourElements.extWallRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->seedVars[0]) /* thermalZoneFourElements.extWallRC.thermCapExt[1].T.SeedFMIDER SEED_VAR */;
#line 1213 OMC_FILE
  TRACE_POP
}
/*
equation index: 1811
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER = (-thermalZoneFourElements.extWallRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER) / (-0.00331421908725)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1811(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1811};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[226]) /* thermalZoneFourElements.extWallRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[229]) /* thermalZoneFourElements.extWallRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-0.00331421908725,"-0.00331421908725");
#line 1227 OMC_FILE
  TRACE_POP
}
/*
equation index: 1812
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofFloor.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1812(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1812};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[262]) /* thermalZoneFourElements.resRoofFloor.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1241 OMC_FILE
  TRACE_POP
}
/*
equation index: 1813
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER = 57.5 * thermalZoneFourElements.resRoofFloor.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1813(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1813};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[261]) /* thermalZoneFourElements.resRoofFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[262]) /* thermalZoneFourElements.resRoofFloor.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1255 OMC_FILE
  TRACE_POP
}
/*
equation index: 1814
type: SIMPLE_ASSIGN
thermalZoneFourElements.resFloorWin.Q_flow.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.convFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.floorRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.thermSplitterSolRad.portOut.5.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.resRoofFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1814(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1814};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[253]) /* thermalZoneFourElements.resFloorWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[214]) /* thermalZoneFourElements.convFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[232]) /* thermalZoneFourElements.floorRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[280]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.5.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[261]) /* thermalZoneFourElements.resRoofFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[245]) /* thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[257]) /* thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1269 OMC_FILE
  TRACE_POP
}
/*
equation index: 1815
type: SIMPLE_ASSIGN
thermalZoneFourElements.resFloorWin.dT.$pDERFMIDER.dummyVarFMIDER = (-thermalZoneFourElements.resFloorWin.Q_flow.$pDERFMIDER.dummyVarFMIDER) / (-57.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1815(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1815};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[254]) /* thermalZoneFourElements.resFloorWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[253]) /* thermalZoneFourElements.resFloorWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-57.5,"-57.5");
#line 1283 OMC_FILE
  TRACE_POP
}
/*
equation index: 1816
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.resFloorWin.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1816(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1816};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[254]) /* thermalZoneFourElements.resFloorWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1297 OMC_FILE
  TRACE_POP
}
/*
equation index: 1817
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallWin.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1817(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1817};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[252]) /* thermalZoneFourElements.resExtWallWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1311 OMC_FILE
  TRACE_POP
}
/*
equation index: 1818
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER = 57.5 * thermalZoneFourElements.resExtWallWin.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1818(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1818};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[251]) /* thermalZoneFourElements.resExtWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[252]) /* thermalZoneFourElements.resExtWallWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1325 OMC_FILE
  TRACE_POP
}
/*
equation index: 1819
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.resExtWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER - (thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.convExtWall.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.extWallRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.thermSplitterSolRad.portOut.1.Q_flow.$pDERFMIDER.dummyVarFMIDER)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1819(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1819};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[249]) /* thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[251]) /* thermalZoneFourElements.resExtWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - ((parentJacobian->tmpVars[245]) /* thermalZoneFourElements.resExtWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[247]) /* thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[212]) /* thermalZoneFourElements.convExtWall.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[226]) /* thermalZoneFourElements.extWallRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[277]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1339 OMC_FILE
  TRACE_POP
}
/*
equation index: 1820
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallRoof.dT.$pDERFMIDER.dummyVarFMIDER = (-thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER) / (-57.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1820(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1820};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[250]) /* thermalZoneFourElements.resExtWallRoof.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[249]) /* thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-57.5,"-57.5");
#line 1353 OMC_FILE
  TRACE_POP
}
/*
equation index: 1821
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofWin.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1821(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1821};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[264]) /* thermalZoneFourElements.resRoofWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1367 OMC_FILE
  TRACE_POP
}
/*
equation index: 1822
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofWin.Q_flow.$pDERFMIDER.dummyVarFMIDER = 57.5 * thermalZoneFourElements.resRoofWin.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1822(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1822};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[263]) /* thermalZoneFourElements.resRoofWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[264]) /* thermalZoneFourElements.resRoofWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1381 OMC_FILE
  TRACE_POP
}
/*
equation index: 1823
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntRoof.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1823(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1823};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[256]) /* thermalZoneFourElements.resIntRoof.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1395 OMC_FILE
  TRACE_POP
}
/*
equation index: 1824
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER = 57.5 * thermalZoneFourElements.resIntRoof.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1824(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1824};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[255]) /* thermalZoneFourElements.resIntRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (57.5) * ((parentJacobian->tmpVars[256]) /* thermalZoneFourElements.resIntRoof.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1409 OMC_FILE
  TRACE_POP
}
/*
equation index: 1825
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.convIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.intWallRC.thermCapInt.1.port.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.thermSplitterSolRad.portOut.3.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.resIntRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1825(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1825};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[259]) /* thermalZoneFourElements.resIntWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[257]) /* thermalZoneFourElements.resIntWallFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[217]) /* thermalZoneFourElements.convIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[239]) /* thermalZoneFourElements.intWallRC.thermCapInt.1.port.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[279]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.3.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[247]) /* thermalZoneFourElements.resExtWallIntWall.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[255]) /* thermalZoneFourElements.resIntRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1423 OMC_FILE
  TRACE_POP
}
/*
equation index: 1826
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallWin.dT.$pDERFMIDER.dummyVarFMIDER = (-thermalZoneFourElements.resIntWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER) / (-70.0)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1826(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1826};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (parentJacobian->tmpVars[260]) /* thermalZoneFourElements.resIntWallWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[259]) /* thermalZoneFourElements.resIntWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-70.0,"-70.0");
#line 1437 OMC_FILE
  TRACE_POP
}
/*
equation index: 1827
type: SIMPLE_ASSIGN
thermalZoneFourElements.convWin.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1827(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1827};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[222]) /* thermalZoneFourElements.convWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1451 OMC_FILE
  TRACE_POP
}
/*
equation index: 1828
type: SIMPLE_ASSIGN
thermalZoneFourElements.convWin.Q_flow.$pDERFMIDER.dummyVarFMIDER = 37.8 * thermalZoneFourElements.convWin.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1828(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1828};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[221]) /* thermalZoneFourElements.convWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (37.8) * ((parentJacobian->tmpVars[222]) /* thermalZoneFourElements.convWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1465 OMC_FILE
  TRACE_POP
}
/*
equation index: 1829
type: SIMPLE_ASSIGN
theConWin.Q_flow.$pDERFMIDER.dummyVarFMIDER = (-thermalZoneFourElements.resRoofWin.Q_flow.$pDERFMIDER.dummyVarFMIDER) - thermalZoneFourElements.resFloorWin.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.resIntWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.resExtWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.convWin.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.thermSplitterSolRad.portOut.2.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1829(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1829};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[207]) /* theConWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (-(parentJacobian->tmpVars[263]) /* thermalZoneFourElements.resRoofWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[253]) /* thermalZoneFourElements.resFloorWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[259]) /* thermalZoneFourElements.resIntWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[251]) /* thermalZoneFourElements.resExtWallWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[221]) /* thermalZoneFourElements.convWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[278]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1479 OMC_FILE
  TRACE_POP
}
/*
equation index: 1830
type: SIMPLE_ASSIGN
thermalZoneFourElements.resWin.dT.$pDERFMIDER.dummyVarFMIDER = (-0.01642857143) * theConWin.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1830(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1830};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[265]) /* thermalZoneFourElements.resWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (-0.01642857143) * ((parentJacobian->tmpVars[207]) /* theConWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1493 OMC_FILE
  TRACE_POP
}
/*
equation index: 1831
type: SIMPLE_ASSIGN
theConWin.dT.$pDERFMIDER.dummyVarFMIDER = (-theConWin.Q_flow.$pDERFMIDER.dummyVarFMIDER) / (-280.0)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1831(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1831};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[208]) /* theConWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[207]) /* theConWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-280.0,"-280.0");
#line 1507 OMC_FILE
  TRACE_POP
}
/*
equation index: 1832
type: SIMPLE_ASSIGN
theConWin.solid.T.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.resWin.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1832(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1832};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[209]) /* theConWin.solid.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[265]) /* thermalZoneFourElements.resWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1521 OMC_FILE
  TRACE_POP
}
/*
equation index: 1833
type: SIMPLE_ASSIGN
thermalZoneFourElements.convRoof.dT.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1833(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1833};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[220]) /* thermalZoneFourElements.convRoof.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[210]) /* thermalZoneFourElements.TAir.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1535 OMC_FILE
  TRACE_POP
}
/*
equation index: 1834
type: SIMPLE_ASSIGN
thermalZoneFourElements.convRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER = 31.05 * thermalZoneFourElements.convRoof.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1834(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1834};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[219]) /* thermalZoneFourElements.convRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (31.05) * ((parentJacobian->tmpVars[220]) /* thermalZoneFourElements.convRoof.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1549 OMC_FILE
  TRACE_POP
}
/*
equation index: 1835
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER - (thermalZoneFourElements.resRoofFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.resIntRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.convRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER + thermalZoneFourElements.thermSplitterSolRad.portOut.5.Q_flow.$pDERFMIDER.dummyVarFMIDER - thermalZoneFourElements.resRoofWin.Q_flow.$pDERFMIDER.dummyVarFMIDER)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1835(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1835};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[266]) /* thermalZoneFourElements.roofRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[249]) /* thermalZoneFourElements.resExtWallRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - ((parentJacobian->tmpVars[261]) /* thermalZoneFourElements.resRoofFloor.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[255]) /* thermalZoneFourElements.resIntRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[219]) /* thermalZoneFourElements.convRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[280]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.5.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[263]) /* thermalZoneFourElements.resRoofWin.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1563 OMC_FILE
  TRACE_POP
}
/*
equation index: 1836
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER = 0.00331421908725 * thermalZoneFourElements.roofRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1836(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1836};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[269]) /* thermalZoneFourElements.roofRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (0.00331421908725) * ((parentJacobian->tmpVars[266]) /* thermalZoneFourElements.roofRC.port_a.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 1577 OMC_FILE
  TRACE_POP
}

void residualFunc1880(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1880};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[7].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[0];
  (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[1];
  (parentJacobian->tmpVars[275]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[2];
  (parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[3];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1794(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1795(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1796(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1797(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1798(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1799(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1800(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1801(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1802(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1803(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1804(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1805(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1806(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1807(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1808(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1809(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1810(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1811(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1812(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1813(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1814(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1815(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1816(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1817(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1818(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1819(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1820(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1821(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1822(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1823(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1824(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1825(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1826(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1827(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1828(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1829(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1830(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1831(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1832(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1833(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1834(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1835(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1836(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[209]) /* theConWin.solid.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[186]) /* eqAirTemp.TEqWin.$pDERFMIDER.dummyVarFMIDER[2] JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[208]) /* theConWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[1] = (parentJacobian->tmpVars[282]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.2.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[274]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[260]) /* thermalZoneFourElements.resIntWallWin.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[2] = (parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (-(parentJacobian->seedVars[3]) /* thermalZoneFourElements.roofRC.thermCapExt[1].T.SeedFMIDER SEED_VAR */) - (parentJacobian->tmpVars[269]) /* thermalZoneFourElements.roofRC.thermResExt.1.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[3] = (parentJacobian->tmpVars[281]) /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[276]) /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[250]) /* thermalZoneFourElements.resExtWallRoof.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData1880(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[276].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[276].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[276].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.5.T.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[281].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[281].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[281].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut.1.T.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[275].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[275].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[275].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.4.T.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[274].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[274].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[274].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut.3.T.$pDERFMIDER.dummyVarFMIDER */.max;
}


/*
equation index: 1786
type: SIMPLE_ASSIGN
theConRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER = (-thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER) / (-0.1265217391)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1786(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1786};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[202]) /* theConRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[270]) /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-0.1265217391,"-0.1265217391");
#line 1764 OMC_FILE
  TRACE_POP
}
/*
equation index: 1787
type: SIMPLE_ASSIGN
theConRoof.dT.$pDERFMIDER.dummyVarFMIDER = (-theConRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER) / (-287.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1787(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1787};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[203]) /* theConRoof.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[202]) /* theConRoof.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-287.5,"-287.5");
#line 1778 OMC_FILE
  TRACE_POP
}
/*
equation index: 1788
type: SIMPLE_ASSIGN
theConRoof.solid.T.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.roofRC.thermCapExt[1].T.SeedFMIDER - thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1788(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1788};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[204]) /* theConRoof.solid.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->seedVars[3]) /* thermalZoneFourElements.roofRC.thermCapExt[1].T.SeedFMIDER SEED_VAR */ - (parentJacobian->tmpVars[270]) /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1792 OMC_FILE
  TRACE_POP
}

void residualFunc1793(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1793};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[6].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[270]) /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[0];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1786(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1787(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1788(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[204]) /* theConRoof.solid.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[190]) /* eqAirTempVDI.TEqWall.$pDERFMIDER.dummyVarFMIDER[1] JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[203]) /* theConRoof.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData1793(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[270].attribute /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[270].attribute /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[270].attribute /* thermalZoneFourElements.roofRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER */.max;
}


/*
equation index: 1777
type: SIMPLE_ASSIGN
theConWall.Q_flow.$pDERFMIDER.dummyVarFMIDER = (-thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER) / (-0.1265217391)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1777(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1777};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (parentJacobian->tmpVars[205]) /* theConWall.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[230]) /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-0.1265217391,"-0.1265217391");
#line 1838 OMC_FILE
  TRACE_POP
}
/*
equation index: 1778
type: SIMPLE_ASSIGN
theConWall.dT.$pDERFMIDER.dummyVarFMIDER = (-theConWall.Q_flow.$pDERFMIDER.dummyVarFMIDER) / (-287.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1778(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1778};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[206]) /* theConWall.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[205]) /* theConWall.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-287.5,"-287.5");
#line 1852 OMC_FILE
  TRACE_POP
}
/*
equation index: 1779
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWall.T.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.extWallRC.thermCapExt[1].T.SeedFMIDER - thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1779(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1779};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[225]) /* thermalZoneFourElements.extWall.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->seedVars[0]) /* thermalZoneFourElements.extWallRC.thermCapExt[1].T.SeedFMIDER SEED_VAR */ - (parentJacobian->tmpVars[230]) /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 1866 OMC_FILE
  TRACE_POP
}

void residualFunc1784(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1784};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[5].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[230]) /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[0];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1777(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1778(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1779(data, threadData, jacobian, parentJacobian);
  res[0] = (parentJacobian->tmpVars[225]) /* thermalZoneFourElements.extWall.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (-(parentJacobian->tmpVars[198]) /* preTem.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[206]) /* theConWall.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData1784(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[230].attribute /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[230].attribute /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[230].attribute /* thermalZoneFourElements.extWallRC.thermResExtRem.dT.$pDERFMIDER.dummyVarFMIDER */.max;
}


/*
equation index: 1621
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.hOut_internal.$pDERFMIDER.dummyVarFMIDER = thermalZoneFourElements.volAir.dynBal.medium.u.$pDERFMIDER.dummyVarFMIDER - (-287.0509010514002) * thermalZoneFourElements.volAir.dynBal.medium.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1621(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1621};
#line 6186 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (parentJacobian->tmpVars[289]) /* thermalZoneFourElements.volAir.hOut_internal.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[288]) /* thermalZoneFourElements.volAir.dynBal.medium.u.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - ((-287.0509010514002) * ((parentJacobian->tmpVars[283]) /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */));
#line 1912 OMC_FILE
  TRACE_POP
}

void residualFunc1625(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1625};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[4].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[283]) /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[0];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1621(data, threadData, jacobian, parentJacobian);
  res[0] = (1005.45) * ((parentJacobian->tmpVars[283]) /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[289]) /* thermalZoneFourElements.volAir.hOut_internal.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData1625(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.volAir.dynBal.medium.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[283].attribute /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[283].attribute /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[283].attribute /* thermalZoneFourElements.volAir.dynBal.medium.T.$pDERFMIDER.dummyVarFMIDER */.max;
}


/*
equation index: 675
type: SIMPLE_ASSIGN
thermalZoneFourElements.convExtWall.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[1].T - thermalZoneFourElements.TAir
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_675(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,675};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[219] /* thermalZoneFourElements.convExtWall.dT variable */) = (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) - (data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */);
#line 1952 OMC_FILE
  TRACE_POP
}
/*
equation index: 676
type: SIMPLE_ASSIGN
thermalZoneFourElements.convExtWall.Q_flow = 31.05 * thermalZoneFourElements.convExtWall.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_676(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,676};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[218] /* thermalZoneFourElements.convExtWall.Q_flow variable */) = (31.05) * ((data->localData[0]->realVars[219] /* thermalZoneFourElements.convExtWall.dT variable */));
#line 1966 OMC_FILE
  TRACE_POP
}
/*
equation index: 677
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermResExt[1].dT = thermalZoneFourElements.thermSplitterSolRad.portOut[1].T - thermalZoneFourElements.extWallRC.thermCapExt[1].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_677(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,677};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[235] /* thermalZoneFourElements.extWallRC.thermResExt[1].dT variable */) = (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) - (data->localData[0]->realVars[0] /* thermalZoneFourElements.extWallRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.extWallRC.thermCapExt[1].der_T) */);
#line 1980 OMC_FILE
  TRACE_POP
}
/*
equation index: 678
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.port_a.Q_flow = (-thermalZoneFourElements.extWallRC.thermResExt[1].dT) / (-0.00331421908725)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_678(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,678};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[232] /* thermalZoneFourElements.extWallRC.port_a.Q_flow variable */) = DIVISION_SIM((-(data->localData[0]->realVars[235] /* thermalZoneFourElements.extWallRC.thermResExt[1].dT variable */)),-0.00331421908725,"-0.00331421908725",equationIndexes);
#line 1994 OMC_FILE
  TRACE_POP
}
/*
equation index: 679
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallFloor.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[1].T - thermalZoneFourElements.thermSplitterIntGains.portOut[4].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_679(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,679};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[257] /* thermalZoneFourElements.resExtWallFloor.dT variable */) = (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) - (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */);
#line 2008 OMC_FILE
  TRACE_POP
}
/*
equation index: 680
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallFloor.Q_flow = 57.5 * thermalZoneFourElements.resExtWallFloor.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_680(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,680};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[256] /* thermalZoneFourElements.resExtWallFloor.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[257] /* thermalZoneFourElements.resExtWallFloor.dT variable */));
#line 2022 OMC_FILE
  TRACE_POP
}
/*
equation index: 681
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermResExt[1].dT = thermalZoneFourElements.thermSplitterIntGains.portOut[4].T - thermalZoneFourElements.floorRC.thermCapExt[1].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_681(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,681};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[241] /* thermalZoneFourElements.floorRC.thermResExt[1].dT variable */) = (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) - (data->localData[0]->realVars[1] /* thermalZoneFourElements.floorRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.floorRC.thermCapExt[1].der_T) */);
#line 2036 OMC_FILE
  TRACE_POP
}
/*
equation index: 682
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.port_a.Q_flow = (-thermalZoneFourElements.floorRC.thermResExt[1].dT) / (-0.00331421908725)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_682(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,682};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[238] /* thermalZoneFourElements.floorRC.port_a.Q_flow variable */) = DIVISION_SIM((-(data->localData[0]->realVars[241] /* thermalZoneFourElements.floorRC.thermResExt[1].dT variable */)),-0.00331421908725,"-0.00331421908725",equationIndexes);
#line 2050 OMC_FILE
  TRACE_POP
}
/*
equation index: 683
type: SIMPLE_ASSIGN
thermalZoneFourElements.convFloor.dT = thermalZoneFourElements.thermSplitterIntGains.portOut[4].T - thermalZoneFourElements.TAir
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_683(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,683};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[221] /* thermalZoneFourElements.convFloor.dT variable */) = (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) - (data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */);
#line 2064 OMC_FILE
  TRACE_POP
}
/*
equation index: 684
type: SIMPLE_ASSIGN
thermalZoneFourElements.convFloor.Q_flow = 31.05 * thermalZoneFourElements.convFloor.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_684(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,684};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[220] /* thermalZoneFourElements.convFloor.Q_flow variable */) = (31.05) * ((data->localData[0]->realVars[221] /* thermalZoneFourElements.convFloor.dT variable */));
#line 2078 OMC_FILE
  TRACE_POP
}
/*
equation index: 685
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofFloor.dT = thermalZoneFourElements.thermSplitterIntGains.portOut[5].T - thermalZoneFourElements.thermSplitterIntGains.portOut[4].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_685(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,685};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[273] /* thermalZoneFourElements.resRoofFloor.dT variable */) = (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) - (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */);
#line 2092 OMC_FILE
  TRACE_POP
}
/*
equation index: 686
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofFloor.Q_flow = 57.5 * thermalZoneFourElements.resRoofFloor.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_686(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,686};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[272] /* thermalZoneFourElements.resRoofFloor.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[273] /* thermalZoneFourElements.resRoofFloor.dT variable */));
#line 2106 OMC_FILE
  TRACE_POP
}
/*
equation index: 687
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallRoof.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[1].T - thermalZoneFourElements.thermSplitterIntGains.portOut[5].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_687(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,687};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[261] /* thermalZoneFourElements.resExtWallRoof.dT variable */) = (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) - (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */);
#line 2120 OMC_FILE
  TRACE_POP
}
/*
equation index: 688
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallRoof.Q_flow = 57.5 * thermalZoneFourElements.resExtWallRoof.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_688(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,688};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[260] /* thermalZoneFourElements.resExtWallRoof.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[261] /* thermalZoneFourElements.resExtWallRoof.dT variable */));
#line 2134 OMC_FILE
  TRACE_POP
}
/*
equation index: 689
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermResExt[1].dT = thermalZoneFourElements.thermSplitterIntGains.portOut[5].T - thermalZoneFourElements.roofRC.thermCapExt[1].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_689(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,689};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[280] /* thermalZoneFourElements.roofRC.thermResExt[1].dT variable */) = (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) - (data->localData[0]->realVars[3] /* thermalZoneFourElements.roofRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.roofRC.thermCapExt[1].der_T) */);
#line 2148 OMC_FILE
  TRACE_POP
}
/*
equation index: 690
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.port_a.Q_flow = (-thermalZoneFourElements.roofRC.thermResExt[1].dT) / (-0.00331421908725)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_690(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,690};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[277] /* thermalZoneFourElements.roofRC.port_a.Q_flow variable */) = DIVISION_SIM((-(data->localData[0]->realVars[280] /* thermalZoneFourElements.roofRC.thermResExt[1].dT variable */)),-0.00331421908725,"-0.00331421908725",equationIndexes);
#line 2162 OMC_FILE
  TRACE_POP
}
/*
equation index: 691
type: SIMPLE_ASSIGN
thermalZoneFourElements.convRoof.dT = thermalZoneFourElements.thermSplitterIntGains.portOut[5].T - thermalZoneFourElements.TAir
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_691(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,691};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[226] /* thermalZoneFourElements.convRoof.dT variable */) = (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) - (data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */);
#line 2176 OMC_FILE
  TRACE_POP
}
/*
equation index: 692
type: SIMPLE_ASSIGN
thermalZoneFourElements.convRoof.Q_flow = 31.05 * thermalZoneFourElements.convRoof.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_692(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,692};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[225] /* thermalZoneFourElements.convRoof.Q_flow variable */) = (31.05) * ((data->localData[0]->realVars[226] /* thermalZoneFourElements.convRoof.dT variable */));
#line 2190 OMC_FILE
  TRACE_POP
}
/*
equation index: 693
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntRoof.dT = thermalZoneFourElements.thermSplitterIntGains.portOut[5].T - thermalZoneFourElements.thermSplitterIntGains.portOut[3].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_693(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,693};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[267] /* thermalZoneFourElements.resIntRoof.dT variable */) = (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) - (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */);
#line 2204 OMC_FILE
  TRACE_POP
}
/*
equation index: 694
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntRoof.Q_flow = 57.5 * thermalZoneFourElements.resIntRoof.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_694(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,694};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[266] /* thermalZoneFourElements.resIntRoof.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[267] /* thermalZoneFourElements.resIntRoof.dT variable */));
#line 2218 OMC_FILE
  TRACE_POP
}
/*
equation index: 695
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofWin.Q_flow = thermalZoneFourElements.resRoofFloor.Q_flow + thermalZoneFourElements.resIntRoof.Q_flow + thermalZoneFourElements.convRoof.Q_flow + thermalZoneFourElements.roofRC.port_a.Q_flow + thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow + thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow - thermalZoneFourElements.resExtWallRoof.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_695(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,695};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[274] /* thermalZoneFourElements.resRoofWin.Q_flow variable */) = (data->localData[0]->realVars[272] /* thermalZoneFourElements.resRoofFloor.Q_flow variable */) + (data->localData[0]->realVars[266] /* thermalZoneFourElements.resIntRoof.Q_flow variable */) + (data->localData[0]->realVars[225] /* thermalZoneFourElements.convRoof.Q_flow variable */) + (data->localData[0]->realVars[277] /* thermalZoneFourElements.roofRC.port_a.Q_flow variable */) + (data->localData[0]->realVars[293] /* thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow variable */) + (data->localData[0]->realVars[286] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow variable */) - (data->localData[0]->realVars[260] /* thermalZoneFourElements.resExtWallRoof.Q_flow variable */);
#line 2232 OMC_FILE
  TRACE_POP
}
/*
equation index: 696
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofWin.dT = (-thermalZoneFourElements.resRoofWin.Q_flow) / (-57.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_696(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,696};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[275] /* thermalZoneFourElements.resRoofWin.dT variable */) = DIVISION_SIM((-(data->localData[0]->realVars[274] /* thermalZoneFourElements.resRoofWin.Q_flow variable */)),-57.5,"-57.5",equationIndexes);
#line 2246 OMC_FILE
  TRACE_POP
}
/*
equation index: 697
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterSolRad.portOut[2].T = thermalZoneFourElements.thermSplitterIntGains.portOut[5].T + thermalZoneFourElements.resRoofWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_697(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,697};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) = (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) + (data->localData[0]->realVars[275] /* thermalZoneFourElements.resRoofWin.dT variable */);
#line 2260 OMC_FILE
  TRACE_POP
}
/*
equation index: 698
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallWin.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T - thermalZoneFourElements.thermSplitterSolRad.portOut[1].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_698(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,698};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[263] /* thermalZoneFourElements.resExtWallWin.dT variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) - (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */);
#line 2274 OMC_FILE
  TRACE_POP
}
/*
equation index: 699
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallWin.Q_flow = 57.5 * thermalZoneFourElements.resExtWallWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_699(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,699};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[262] /* thermalZoneFourElements.resExtWallWin.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[263] /* thermalZoneFourElements.resExtWallWin.dT variable */));
#line 2288 OMC_FILE
  TRACE_POP
}
/*
equation index: 700
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallIntWall.Q_flow = thermalZoneFourElements.resExtWallWin.Q_flow - (thermalZoneFourElements.resExtWallRoof.Q_flow + thermalZoneFourElements.resExtWallFloor.Q_flow + thermalZoneFourElements.convExtWall.Q_flow + thermalZoneFourElements.extWallRC.port_a.Q_flow + thermalZoneFourElements.thermSplitterSolRad.portOut[1].Q_flow + thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_700(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,700};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[258] /* thermalZoneFourElements.resExtWallIntWall.Q_flow variable */) = (data->localData[0]->realVars[262] /* thermalZoneFourElements.resExtWallWin.Q_flow variable */) - ((data->localData[0]->realVars[260] /* thermalZoneFourElements.resExtWallRoof.Q_flow variable */) + (data->localData[0]->realVars[256] /* thermalZoneFourElements.resExtWallFloor.Q_flow variable */) + (data->localData[0]->realVars[218] /* thermalZoneFourElements.convExtWall.Q_flow variable */) + (data->localData[0]->realVars[232] /* thermalZoneFourElements.extWallRC.port_a.Q_flow variable */) + (data->localData[0]->realVars[290] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].Q_flow variable */) + (data->localData[0]->realVars[286] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow variable */));
#line 2302 OMC_FILE
  TRACE_POP
}
/*
equation index: 701
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallIntWall.dT = (-thermalZoneFourElements.resExtWallIntWall.Q_flow) / (-57.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_701(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,701};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[259] /* thermalZoneFourElements.resExtWallIntWall.dT variable */) = DIVISION_SIM((-(data->localData[0]->realVars[258] /* thermalZoneFourElements.resExtWallIntWall.Q_flow variable */)),-57.5,"-57.5",equationIndexes);
#line 2316 OMC_FILE
  TRACE_POP
}
/*
equation index: 702
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallWin.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T - thermalZoneFourElements.thermSplitterIntGains.portOut[3].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_702(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,702};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[271] /* thermalZoneFourElements.resIntWallWin.dT variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) - (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */);
#line 2330 OMC_FILE
  TRACE_POP
}
/*
equation index: 703
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallWin.Q_flow = 70.0 * thermalZoneFourElements.resIntWallWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_703(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,703};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[270] /* thermalZoneFourElements.resIntWallWin.Q_flow variable */) = (70.0) * ((data->localData[0]->realVars[271] /* thermalZoneFourElements.resIntWallWin.dT variable */));
#line 2344 OMC_FILE
  TRACE_POP
}
/*
equation index: 704
type: SIMPLE_ASSIGN
thermalZoneFourElements.resFloorWin.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T - thermalZoneFourElements.thermSplitterIntGains.portOut[4].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_704(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,704};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[265] /* thermalZoneFourElements.resFloorWin.dT variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) - (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */);
#line 2358 OMC_FILE
  TRACE_POP
}
/*
equation index: 705
type: SIMPLE_ASSIGN
thermalZoneFourElements.resFloorWin.Q_flow = 57.5 * thermalZoneFourElements.resFloorWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_705(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,705};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[264] /* thermalZoneFourElements.resFloorWin.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[265] /* thermalZoneFourElements.resFloorWin.dT variable */));
#line 2372 OMC_FILE
  TRACE_POP
}
/*
equation index: 706
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallFloor.Q_flow = thermalZoneFourElements.convFloor.Q_flow + thermalZoneFourElements.floorRC.port_a.Q_flow + thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow + thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow - thermalZoneFourElements.resFloorWin.Q_flow - thermalZoneFourElements.resRoofFloor.Q_flow - thermalZoneFourElements.resExtWallFloor.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_706(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,706};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[268] /* thermalZoneFourElements.resIntWallFloor.Q_flow variable */) = (data->localData[0]->realVars[220] /* thermalZoneFourElements.convFloor.Q_flow variable */) + (data->localData[0]->realVars[238] /* thermalZoneFourElements.floorRC.port_a.Q_flow variable */) + (data->localData[0]->realVars[293] /* thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow variable */) + (data->localData[0]->realVars[286] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow variable */) - (data->localData[0]->realVars[264] /* thermalZoneFourElements.resFloorWin.Q_flow variable */) - (data->localData[0]->realVars[272] /* thermalZoneFourElements.resRoofFloor.Q_flow variable */) - (data->localData[0]->realVars[256] /* thermalZoneFourElements.resExtWallFloor.Q_flow variable */);
#line 2386 OMC_FILE
  TRACE_POP
}
/*
equation index: 707
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallFloor.dT = (-thermalZoneFourElements.resIntWallFloor.Q_flow) / (-57.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_707(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,707};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[269] /* thermalZoneFourElements.resIntWallFloor.dT variable */) = DIVISION_SIM((-(data->localData[0]->realVars[268] /* thermalZoneFourElements.resIntWallFloor.Q_flow variable */)),-57.5,"-57.5",equationIndexes);
#line 2400 OMC_FILE
  TRACE_POP
}
/*
equation index: 708
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermResInt[1].dT = thermalZoneFourElements.thermSplitterIntGains.portOut[3].T - thermalZoneFourElements.intWallRC.thermCapInt[1].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_708(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,708};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[251] /* thermalZoneFourElements.intWallRC.thermResInt[1].dT variable */) = (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) - (data->localData[0]->realVars[2] /* thermalZoneFourElements.intWallRC.thermCapInt[1].T STATE(1,thermalZoneFourElements.intWallRC.thermCapInt[1].der_T) */);
#line 2414 OMC_FILE
  TRACE_POP
}
/*
equation index: 709
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow = (-thermalZoneFourElements.intWallRC.thermResInt[1].dT) / (-0.000668895639141)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_709(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,709};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[250] /* thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow variable */) = DIVISION_SIM((-(data->localData[0]->realVars[251] /* thermalZoneFourElements.intWallRC.thermResInt[1].dT variable */)),-0.000668895639141,"-0.000668895639141",equationIndexes);
#line 2428 OMC_FILE
  TRACE_POP
}
/*
equation index: 710
type: SIMPLE_ASSIGN
thermalZoneFourElements.convIntWall.Q_flow = thermalZoneFourElements.resExtWallIntWall.Q_flow - (thermalZoneFourElements.resIntWallFloor.Q_flow + thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow + thermalZoneFourElements.thermSplitterSolRad.portOut[3].Q_flow + thermalZoneFourElements.thermSplitterIntGains.portOut[3].Q_flow - thermalZoneFourElements.resIntWallWin.Q_flow - thermalZoneFourElements.resIntRoof.Q_flow)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_710(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,710};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[223] /* thermalZoneFourElements.convIntWall.Q_flow variable */) = (data->localData[0]->realVars[258] /* thermalZoneFourElements.resExtWallIntWall.Q_flow variable */) - ((data->localData[0]->realVars[268] /* thermalZoneFourElements.resIntWallFloor.Q_flow variable */) + (data->localData[0]->realVars[250] /* thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow variable */) + (data->localData[0]->realVars[292] /* thermalZoneFourElements.thermSplitterSolRad.portOut[3].Q_flow variable */) + (data->localData[0]->realVars[285] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].Q_flow variable */) - (data->localData[0]->realVars[270] /* thermalZoneFourElements.resIntWallWin.Q_flow variable */) - (data->localData[0]->realVars[266] /* thermalZoneFourElements.resIntRoof.Q_flow variable */));
#line 2442 OMC_FILE
  TRACE_POP
}
/*
equation index: 711
type: SIMPLE_ASSIGN
thermalZoneFourElements.convIntWall.dT = (-thermalZoneFourElements.convIntWall.Q_flow) / (-128.26)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_711(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,711};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[224] /* thermalZoneFourElements.convIntWall.dT variable */) = DIVISION_SIM((-(data->localData[0]->realVars[223] /* thermalZoneFourElements.convIntWall.Q_flow variable */)),-128.26,"-128.26",equationIndexes);
#line 2456 OMC_FILE
  TRACE_POP
}
/*
equation index: 712
type: SIMPLE_ASSIGN
thermalZoneFourElements.convWin.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T - thermalZoneFourElements.TAir
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_712(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,712};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[228] /* thermalZoneFourElements.convWin.dT variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) - (data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */);
#line 2470 OMC_FILE
  TRACE_POP
}
/*
equation index: 713
type: SIMPLE_ASSIGN
thermalZoneFourElements.convWin.Q_flow = 37.8 * thermalZoneFourElements.convWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_713(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,713};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[227] /* thermalZoneFourElements.convWin.Q_flow variable */) = (37.8) * ((data->localData[0]->realVars[228] /* thermalZoneFourElements.convWin.dT variable */));
#line 2484 OMC_FILE
  TRACE_POP
}
/*
equation index: 714
type: SIMPLE_ASSIGN
theConWin.Q_flow = (-thermalZoneFourElements.resRoofWin.Q_flow) - thermalZoneFourElements.resFloorWin.Q_flow - thermalZoneFourElements.resIntWallWin.Q_flow - thermalZoneFourElements.resExtWallWin.Q_flow - thermalZoneFourElements.convWin.Q_flow - thermalZoneFourElements.thermSplitterSolRad.portOut[2].Q_flow - thermalZoneFourElements.thermSplitterIntGains.portOut[2].Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_714(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,714};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[213] /* theConWin.Q_flow variable */) = (-(data->localData[0]->realVars[274] /* thermalZoneFourElements.resRoofWin.Q_flow variable */)) - (data->localData[0]->realVars[264] /* thermalZoneFourElements.resFloorWin.Q_flow variable */) - (data->localData[0]->realVars[270] /* thermalZoneFourElements.resIntWallWin.Q_flow variable */) - (data->localData[0]->realVars[262] /* thermalZoneFourElements.resExtWallWin.Q_flow variable */) - (data->localData[0]->realVars[227] /* thermalZoneFourElements.convWin.Q_flow variable */) - (data->localData[0]->realVars[291] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].Q_flow variable */) - (data->localData[0]->realVars[284] /* thermalZoneFourElements.thermSplitterIntGains.portOut[2].Q_flow variable */);
#line 2498 OMC_FILE
  TRACE_POP
}
/*
equation index: 715
type: SIMPLE_ASSIGN
theConWin.dT = (-theConWin.Q_flow) / (-280.0)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_715(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,715};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[214] /* theConWin.dT variable */) = DIVISION_SIM((-(data->localData[0]->realVars[213] /* theConWin.Q_flow variable */)),-280.0,"-280.0",equationIndexes);
#line 2512 OMC_FILE
  TRACE_POP
}
/*
equation index: 716
type: SIMPLE_ASSIGN
thermalZoneFourElements.resWin.dT = (-0.01642857143) * theConWin.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_716(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,716};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[276] /* thermalZoneFourElements.resWin.dT variable */) = (-0.01642857143) * ((data->localData[0]->realVars[213] /* theConWin.Q_flow variable */));
#line 2526 OMC_FILE
  TRACE_POP
}
/*
equation index: 717
type: SIMPLE_ASSIGN
theConWin.solid.T = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T + thermalZoneFourElements.resWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_717(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,717};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[215] /* theConWin.solid.T variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) + (data->localData[0]->realVars[276] /* thermalZoneFourElements.resWin.dT variable */);
#line 2540 OMC_FILE
  TRACE_POP
}

void residualFunc761(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,761};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) = xloc[0];
  (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) = xloc[1];
  (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) = xloc[2];
  (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) = xloc[3];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_675(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_676(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_677(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_678(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_679(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_680(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_681(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_682(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_683(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_684(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_685(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_686(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_687(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_688(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_689(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_690(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_691(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_692(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_693(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_694(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_695(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_696(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_697(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_698(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_699(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_700(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_701(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_702(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_703(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_704(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_705(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_706(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_707(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_708(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_709(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_710(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_711(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_712(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_713(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_714(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_715(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_716(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_717(data, threadData);
  res[0] = (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) + (-(data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */)) - (data->localData[0]->realVars[259] /* thermalZoneFourElements.resExtWallIntWall.dT variable */);

  res[1] = (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) + (-(data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */)) - (data->localData[0]->realVars[224] /* thermalZoneFourElements.convIntWall.dT variable */);

  res[2] = (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) + (-(data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */)) - (data->localData[0]->realVars[269] /* thermalZoneFourElements.resIntWallFloor.dT variable */);

  res[3] = (data->localData[0]->realVars[215] /* theConWin.solid.T variable */) + (-(data->localData[0]->realVars[189] /* eqAirTemp.TEqWin[2] variable */)) - (data->localData[0]->realVars[214] /* theConWin.dT variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData761(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut[3].T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[287].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[287].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[287].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut[5].T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[289].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[289].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[289].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut[4].T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[288].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[288].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[288].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterSolRad.portOut[1].T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[294].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[294].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[294].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T */.max;
}


/*
equation index: 644
type: SIMPLE_ASSIGN
theConWall.Q_flow = 287.5 * theConWall.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_644(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,644};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[211] /* theConWall.Q_flow variable */) = (287.5) * ((data->localData[0]->realVars[212] /* theConWall.dT variable */));
#line 2726 OMC_FILE
  TRACE_POP
}
/*
equation index: 645
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermResExtRem.dT = 0.1265217391 * theConWall.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_645(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,645};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[236] /* thermalZoneFourElements.extWallRC.thermResExtRem.dT variable */) = (0.1265217391) * ((data->localData[0]->realVars[211] /* theConWall.Q_flow variable */));
#line 2740 OMC_FILE
  TRACE_POP
}
/*
equation index: 646
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWall.T = preTem.T + theConWall.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_646(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,646};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[231] /* thermalZoneFourElements.extWall.T variable */) = (data->localData[0]->realVars[204] /* preTem.T variable */) + (data->localData[0]->realVars[212] /* theConWall.dT variable */);
#line 2754 OMC_FILE
  TRACE_POP
}

void residualFunc651(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,651};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[212] /* theConWall.dT variable */) = xloc[0];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_644(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_645(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_646(data, threadData);
  res[0] = (data->localData[0]->realVars[0] /* thermalZoneFourElements.extWallRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.extWallRC.thermCapExt[1].der_T) */) + (-(data->localData[0]->realVars[231] /* thermalZoneFourElements.extWall.T variable */)) - (data->localData[0]->realVars[236] /* thermalZoneFourElements.extWallRC.thermResExtRem.dT variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData651(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for theConWall.dT */
  linearSystemData->nominal[i] = data->modelData->realVarsData[212].attribute /* theConWall.dT */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[212].attribute /* theConWall.dT */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[212].attribute /* theConWall.dT */.max;
}


/*
equation index: 504
type: SIMPLE_ASSIGN
theConRoof.dT = theConRoof.solid.T - eqAirTempVDI.TEqWall[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_504(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,504};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[209] /* theConRoof.dT variable */) = (data->localData[0]->realVars[210] /* theConRoof.solid.T variable */) - (data->localData[0]->realVars[193] /* eqAirTempVDI.TEqWall[1] variable */);
#line 2799 OMC_FILE
  TRACE_POP
}
/*
equation index: 505
type: SIMPLE_ASSIGN
theConRoof.Q_flow = 287.5 * theConRoof.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_505(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,505};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[208] /* theConRoof.Q_flow variable */) = (287.5) * ((data->localData[0]->realVars[209] /* theConRoof.dT variable */));
#line 2813 OMC_FILE
  TRACE_POP
}
/*
equation index: 506
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermResExtRem.dT = 0.1265217391 * theConRoof.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,506};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[281] /* thermalZoneFourElements.roofRC.thermResExtRem.dT variable */) = (0.1265217391) * ((data->localData[0]->realVars[208] /* theConRoof.Q_flow variable */));
#line 2827 OMC_FILE
  TRACE_POP
}

void residualFunc511(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,511};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[210] /* theConRoof.solid.T variable */) = xloc[0];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_504(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_505(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_506(data, threadData);
  res[0] = (data->localData[0]->realVars[3] /* thermalZoneFourElements.roofRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.roofRC.thermCapExt[1].der_T) */) + (-(data->localData[0]->realVars[210] /* theConRoof.solid.T variable */)) - (data->localData[0]->realVars[281] /* thermalZoneFourElements.roofRC.thermResExtRem.dT variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData511(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for theConRoof.solid.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[210].attribute /* theConRoof.solid.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[210].attribute /* theConRoof.solid.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[210].attribute /* theConRoof.solid.T */.max;
}


/*
equation index: 263
type: SIMPLE_ASSIGN
thermalZoneFourElements.convExtWall.Q_flow = 31.05 * thermalZoneFourElements.convExtWall.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,263};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[218] /* thermalZoneFourElements.convExtWall.Q_flow variable */) = (31.05) * ((data->localData[0]->realVars[219] /* thermalZoneFourElements.convExtWall.dT variable */));
#line 2872 OMC_FILE
  TRACE_POP
}
/*
equation index: 264
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterSolRad.portOut[1].T = thermalZoneFourElements.TAir + thermalZoneFourElements.convExtWall.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,264};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) = (data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */) + (data->localData[0]->realVars[219] /* thermalZoneFourElements.convExtWall.dT variable */);
#line 2886 OMC_FILE
  TRACE_POP
}
/*
equation index: 265
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallWin.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T - thermalZoneFourElements.thermSplitterSolRad.portOut[1].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,265};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[263] /* thermalZoneFourElements.resExtWallWin.dT variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) - (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */);
#line 2900 OMC_FILE
  TRACE_POP
}
/*
equation index: 266
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallWin.Q_flow = 57.5 * thermalZoneFourElements.resExtWallWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_266(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,266};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[262] /* thermalZoneFourElements.resExtWallWin.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[263] /* thermalZoneFourElements.resExtWallWin.dT variable */));
#line 2914 OMC_FILE
  TRACE_POP
}
/*
equation index: 267
type: SIMPLE_ASSIGN
thermalZoneFourElements.convWin.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T - thermalZoneFourElements.TAir
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[228] /* thermalZoneFourElements.convWin.dT variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) - (data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */);
#line 2928 OMC_FILE
  TRACE_POP
}
/*
equation index: 268
type: SIMPLE_ASSIGN
thermalZoneFourElements.convWin.Q_flow = 37.8 * thermalZoneFourElements.convWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[227] /* thermalZoneFourElements.convWin.Q_flow variable */) = (37.8) * ((data->localData[0]->realVars[228] /* thermalZoneFourElements.convWin.dT variable */));
#line 2942 OMC_FILE
  TRACE_POP
}
/*
equation index: 269
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallFloor.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[1].T - thermalZoneFourElements.thermSplitterIntGains.portOut[4].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[257] /* thermalZoneFourElements.resExtWallFloor.dT variable */) = (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) - (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */);
#line 2956 OMC_FILE
  TRACE_POP
}
/*
equation index: 270
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallFloor.Q_flow = 57.5 * thermalZoneFourElements.resExtWallFloor.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[256] /* thermalZoneFourElements.resExtWallFloor.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[257] /* thermalZoneFourElements.resExtWallFloor.dT variable */));
#line 2970 OMC_FILE
  TRACE_POP
}
/*
equation index: 271
type: SIMPLE_ASSIGN
thermalZoneFourElements.resFloorWin.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T - thermalZoneFourElements.thermSplitterIntGains.portOut[4].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[265] /* thermalZoneFourElements.resFloorWin.dT variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) - (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */);
#line 2984 OMC_FILE
  TRACE_POP
}
/*
equation index: 272
type: SIMPLE_ASSIGN
thermalZoneFourElements.resFloorWin.Q_flow = 57.5 * thermalZoneFourElements.resFloorWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[264] /* thermalZoneFourElements.resFloorWin.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[265] /* thermalZoneFourElements.resFloorWin.dT variable */));
#line 2998 OMC_FILE
  TRACE_POP
}
/*
equation index: 273
type: SIMPLE_ASSIGN
thermalZoneFourElements.convFloor.dT = thermalZoneFourElements.thermSplitterIntGains.portOut[4].T - thermalZoneFourElements.TAir
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[221] /* thermalZoneFourElements.convFloor.dT variable */) = (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) - (data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */);
#line 3012 OMC_FILE
  TRACE_POP
}
/*
equation index: 274
type: SIMPLE_ASSIGN
thermalZoneFourElements.convFloor.Q_flow = 31.05 * thermalZoneFourElements.convFloor.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[220] /* thermalZoneFourElements.convFloor.Q_flow variable */) = (31.05) * ((data->localData[0]->realVars[221] /* thermalZoneFourElements.convFloor.dT variable */));
#line 3026 OMC_FILE
  TRACE_POP
}
/*
equation index: 275
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofFloor.dT = thermalZoneFourElements.thermSplitterIntGains.portOut[5].T - thermalZoneFourElements.thermSplitterIntGains.portOut[4].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[273] /* thermalZoneFourElements.resRoofFloor.dT variable */) = (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) - (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */);
#line 3040 OMC_FILE
  TRACE_POP
}
/*
equation index: 276
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofFloor.Q_flow = 57.5 * thermalZoneFourElements.resRoofFloor.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,276};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[272] /* thermalZoneFourElements.resRoofFloor.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[273] /* thermalZoneFourElements.resRoofFloor.dT variable */));
#line 3054 OMC_FILE
  TRACE_POP
}
/*
equation index: 277
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallRoof.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[1].T - thermalZoneFourElements.thermSplitterIntGains.portOut[5].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,277};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[261] /* thermalZoneFourElements.resExtWallRoof.dT variable */) = (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) - (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */);
#line 3068 OMC_FILE
  TRACE_POP
}
/*
equation index: 278
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallRoof.Q_flow = 57.5 * thermalZoneFourElements.resExtWallRoof.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[260] /* thermalZoneFourElements.resExtWallRoof.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[261] /* thermalZoneFourElements.resExtWallRoof.dT variable */));
#line 3082 OMC_FILE
  TRACE_POP
}
/*
equation index: 279
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofWin.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T - thermalZoneFourElements.thermSplitterIntGains.portOut[5].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,279};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[275] /* thermalZoneFourElements.resRoofWin.dT variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) - (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */);
#line 3096 OMC_FILE
  TRACE_POP
}
/*
equation index: 280
type: SIMPLE_ASSIGN
thermalZoneFourElements.resRoofWin.Q_flow = 57.5 * thermalZoneFourElements.resRoofWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[274] /* thermalZoneFourElements.resRoofWin.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[275] /* thermalZoneFourElements.resRoofWin.dT variable */));
#line 3110 OMC_FILE
  TRACE_POP
}
/*
equation index: 281
type: SIMPLE_ASSIGN
thermalZoneFourElements.convRoof.dT = thermalZoneFourElements.thermSplitterIntGains.portOut[5].T - thermalZoneFourElements.TAir
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[226] /* thermalZoneFourElements.convRoof.dT variable */) = (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) - (data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */);
#line 3124 OMC_FILE
  TRACE_POP
}
/*
equation index: 282
type: SIMPLE_ASSIGN
thermalZoneFourElements.convRoof.Q_flow = 31.05 * thermalZoneFourElements.convRoof.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[225] /* thermalZoneFourElements.convRoof.Q_flow variable */) = (31.05) * ((data->localData[0]->realVars[226] /* thermalZoneFourElements.convRoof.dT variable */));
#line 3138 OMC_FILE
  TRACE_POP
}
/*
equation index: 283
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallWin.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T - thermalZoneFourElements.thermSplitterIntGains.portOut[3].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[271] /* thermalZoneFourElements.resIntWallWin.dT variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) - (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */);
#line 3152 OMC_FILE
  TRACE_POP
}
/*
equation index: 284
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallWin.Q_flow = 70.0 * thermalZoneFourElements.resIntWallWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[270] /* thermalZoneFourElements.resIntWallWin.Q_flow variable */) = (70.0) * ((data->localData[0]->realVars[271] /* thermalZoneFourElements.resIntWallWin.dT variable */));
#line 3166 OMC_FILE
  TRACE_POP
}
/*
equation index: 285
type: SIMPLE_ASSIGN
theConWin.Q_flow = (-thermalZoneFourElements.resRoofWin.Q_flow) - thermalZoneFourElements.resFloorWin.Q_flow - thermalZoneFourElements.resIntWallWin.Q_flow - thermalZoneFourElements.resExtWallWin.Q_flow - thermalZoneFourElements.convWin.Q_flow - thermalZoneFourElements.thermSplitterSolRad.portOut[2].Q_flow - thermalZoneFourElements.thermSplitterIntGains.portOut[2].Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[213] /* theConWin.Q_flow variable */) = (-(data->localData[0]->realVars[274] /* thermalZoneFourElements.resRoofWin.Q_flow variable */)) - (data->localData[0]->realVars[264] /* thermalZoneFourElements.resFloorWin.Q_flow variable */) - (data->localData[0]->realVars[270] /* thermalZoneFourElements.resIntWallWin.Q_flow variable */) - (data->localData[0]->realVars[262] /* thermalZoneFourElements.resExtWallWin.Q_flow variable */) - (data->localData[0]->realVars[227] /* thermalZoneFourElements.convWin.Q_flow variable */) - (data->localData[0]->realVars[291] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].Q_flow variable */) - (data->localData[0]->realVars[284] /* thermalZoneFourElements.thermSplitterIntGains.portOut[2].Q_flow variable */);
#line 3180 OMC_FILE
  TRACE_POP
}
/*
equation index: 286
type: SIMPLE_ASSIGN
thermalZoneFourElements.resWin.dT = (-0.01642857143) * theConWin.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[276] /* thermalZoneFourElements.resWin.dT variable */) = (-0.01642857143) * ((data->localData[0]->realVars[213] /* theConWin.Q_flow variable */));
#line 3194 OMC_FILE
  TRACE_POP
}
/*
equation index: 287
type: SIMPLE_ASSIGN
theConWin.dT = (-theConWin.Q_flow) / (-280.0)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[214] /* theConWin.dT variable */) = DIVISION_SIM((-(data->localData[0]->realVars[213] /* theConWin.Q_flow variable */)),-280.0,"-280.0",equationIndexes);
#line 3208 OMC_FILE
  TRACE_POP
}
/*
equation index: 288
type: SIMPLE_ASSIGN
theConWin.solid.T = thermalZoneFourElements.thermSplitterSolRad.portOut[2].T + thermalZoneFourElements.resWin.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[215] /* theConWin.solid.T variable */) = (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) + (data->localData[0]->realVars[276] /* thermalZoneFourElements.resWin.dT variable */);
#line 3222 OMC_FILE
  TRACE_POP
}
/*
equation index: 289
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallIntWall.dT = thermalZoneFourElements.thermSplitterSolRad.portOut[1].T - thermalZoneFourElements.thermSplitterIntGains.portOut[3].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[259] /* thermalZoneFourElements.resExtWallIntWall.dT variable */) = (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) - (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */);
#line 3236 OMC_FILE
  TRACE_POP
}
/*
equation index: 290
type: SIMPLE_ASSIGN
thermalZoneFourElements.resExtWallIntWall.Q_flow = 57.5 * thermalZoneFourElements.resExtWallIntWall.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[258] /* thermalZoneFourElements.resExtWallIntWall.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[259] /* thermalZoneFourElements.resExtWallIntWall.dT variable */));
#line 3250 OMC_FILE
  TRACE_POP
}
/*
equation index: 291
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.port_a.Q_flow = thermalZoneFourElements.resExtWallWin.Q_flow - (thermalZoneFourElements.resExtWallRoof.Q_flow + thermalZoneFourElements.resExtWallFloor.Q_flow + thermalZoneFourElements.resExtWallIntWall.Q_flow + thermalZoneFourElements.convExtWall.Q_flow + thermalZoneFourElements.thermSplitterSolRad.portOut[1].Q_flow + thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[232] /* thermalZoneFourElements.extWallRC.port_a.Q_flow variable */) = (data->localData[0]->realVars[262] /* thermalZoneFourElements.resExtWallWin.Q_flow variable */) - ((data->localData[0]->realVars[260] /* thermalZoneFourElements.resExtWallRoof.Q_flow variable */) + (data->localData[0]->realVars[256] /* thermalZoneFourElements.resExtWallFloor.Q_flow variable */) + (data->localData[0]->realVars[258] /* thermalZoneFourElements.resExtWallIntWall.Q_flow variable */) + (data->localData[0]->realVars[218] /* thermalZoneFourElements.convExtWall.Q_flow variable */) + (data->localData[0]->realVars[290] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].Q_flow variable */) + (data->localData[0]->realVars[286] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow variable */));
#line 3264 OMC_FILE
  TRACE_POP
}
/*
equation index: 292
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermResExt[1].dT = 0.00331421908725 * thermalZoneFourElements.extWallRC.port_a.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[235] /* thermalZoneFourElements.extWallRC.thermResExt[1].dT variable */) = (0.00331421908725) * ((data->localData[0]->realVars[232] /* thermalZoneFourElements.extWallRC.port_a.Q_flow variable */));
#line 3278 OMC_FILE
  TRACE_POP
}
/*
equation index: 293
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermCapExt[1].T = thermalZoneFourElements.thermSplitterSolRad.portOut[1].T - thermalZoneFourElements.extWallRC.thermResExt[1].dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[0] /* thermalZoneFourElements.extWallRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.extWallRC.thermCapExt[1].der_T) */) = (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) - (data->localData[0]->realVars[235] /* thermalZoneFourElements.extWallRC.thermResExt[1].dT variable */);
#line 3292 OMC_FILE
  TRACE_POP
}
/*
equation index: 294
type: SIMPLE_ASSIGN
theConWall.Q_flow = thermalZoneFourElements.extWallRC.port_a.Q_flow - thermalZoneFourElements.extWallRC.thermCapExt[1].port.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[211] /* theConWall.Q_flow variable */) = (data->localData[0]->realVars[232] /* thermalZoneFourElements.extWallRC.port_a.Q_flow variable */) - (data->localData[0]->realVars[234] /* thermalZoneFourElements.extWallRC.thermCapExt[1].port.Q_flow variable */);
#line 3306 OMC_FILE
  TRACE_POP
}
/*
equation index: 295
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermResExtRem.dT = 0.1265217391 * theConWall.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[236] /* thermalZoneFourElements.extWallRC.thermResExtRem.dT variable */) = (0.1265217391) * ((data->localData[0]->realVars[211] /* theConWall.Q_flow variable */));
#line 3320 OMC_FILE
  TRACE_POP
}
/*
equation index: 296
type: SIMPLE_ASSIGN
theConWall.dT = (-theConWall.Q_flow) / (-287.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[212] /* theConWall.dT variable */) = DIVISION_SIM((-(data->localData[0]->realVars[211] /* theConWall.Q_flow variable */)),-287.5,"-287.5",equationIndexes);
#line 3334 OMC_FILE
  TRACE_POP
}
/*
equation index: 297
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWall.T = thermalZoneFourElements.extWallRC.thermCapExt[1].T - thermalZoneFourElements.extWallRC.thermResExtRem.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[231] /* thermalZoneFourElements.extWall.T variable */) = (data->localData[0]->realVars[0] /* thermalZoneFourElements.extWallRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.extWallRC.thermCapExt[1].der_T) */) - (data->localData[0]->realVars[236] /* thermalZoneFourElements.extWallRC.thermResExtRem.dT variable */);
#line 3348 OMC_FILE
  TRACE_POP
}
/*
equation index: 298
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallFloor.dT = thermalZoneFourElements.thermSplitterIntGains.portOut[3].T - thermalZoneFourElements.thermSplitterIntGains.portOut[4].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[269] /* thermalZoneFourElements.resIntWallFloor.dT variable */) = (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) - (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */);
#line 3362 OMC_FILE
  TRACE_POP
}
/*
equation index: 299
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntWallFloor.Q_flow = 57.5 * thermalZoneFourElements.resIntWallFloor.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[268] /* thermalZoneFourElements.resIntWallFloor.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[269] /* thermalZoneFourElements.resIntWallFloor.dT variable */));
#line 3376 OMC_FILE
  TRACE_POP
}
/*
equation index: 300
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.port_a.Q_flow = thermalZoneFourElements.resExtWallFloor.Q_flow - (thermalZoneFourElements.convFloor.Q_flow + thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow + thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow - thermalZoneFourElements.resFloorWin.Q_flow - thermalZoneFourElements.resRoofFloor.Q_flow - thermalZoneFourElements.resIntWallFloor.Q_flow)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[238] /* thermalZoneFourElements.floorRC.port_a.Q_flow variable */) = (data->localData[0]->realVars[256] /* thermalZoneFourElements.resExtWallFloor.Q_flow variable */) - ((data->localData[0]->realVars[220] /* thermalZoneFourElements.convFloor.Q_flow variable */) + (data->localData[0]->realVars[293] /* thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow variable */) + (data->localData[0]->realVars[286] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow variable */) - (data->localData[0]->realVars[264] /* thermalZoneFourElements.resFloorWin.Q_flow variable */) - (data->localData[0]->realVars[272] /* thermalZoneFourElements.resRoofFloor.Q_flow variable */) - (data->localData[0]->realVars[268] /* thermalZoneFourElements.resIntWallFloor.Q_flow variable */));
#line 3390 OMC_FILE
  TRACE_POP
}
/*
equation index: 301
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermResExt[1].dT = 0.00331421908725 * thermalZoneFourElements.floorRC.port_a.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[241] /* thermalZoneFourElements.floorRC.thermResExt[1].dT variable */) = (0.00331421908725) * ((data->localData[0]->realVars[238] /* thermalZoneFourElements.floorRC.port_a.Q_flow variable */));
#line 3404 OMC_FILE
  TRACE_POP
}
/*
equation index: 302
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermCapExt[1].T = thermalZoneFourElements.thermSplitterIntGains.portOut[4].T - thermalZoneFourElements.floorRC.thermResExt[1].dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[1] /* thermalZoneFourElements.floorRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.floorRC.thermCapExt[1].der_T) */) = (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) - (data->localData[0]->realVars[241] /* thermalZoneFourElements.floorRC.thermResExt[1].dT variable */);
#line 3418 OMC_FILE
  TRACE_POP
}
/*
equation index: 303
type: SIMPLE_ASSIGN
thermalZoneFourElements.floor.Q_flow = thermalZoneFourElements.floorRC.thermCapExt[1].port.Q_flow - thermalZoneFourElements.floorRC.port_a.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[237] /* thermalZoneFourElements.floor.Q_flow variable */) = (data->localData[0]->realVars[240] /* thermalZoneFourElements.floorRC.thermCapExt[1].port.Q_flow variable */) - (data->localData[0]->realVars[238] /* thermalZoneFourElements.floorRC.port_a.Q_flow variable */);
#line 3432 OMC_FILE
  TRACE_POP
}
/*
equation index: 304
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermResExtRem.dT = (-0.1265217391) * thermalZoneFourElements.floor.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[242] /* thermalZoneFourElements.floorRC.thermResExtRem.dT variable */) = (-0.1265217391) * ((data->localData[0]->realVars[237] /* thermalZoneFourElements.floor.Q_flow variable */));
#line 3446 OMC_FILE
  TRACE_POP
}
/*
equation index: 305
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntRoof.dT = thermalZoneFourElements.thermSplitterIntGains.portOut[5].T - thermalZoneFourElements.thermSplitterIntGains.portOut[3].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[267] /* thermalZoneFourElements.resIntRoof.dT variable */) = (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) - (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */);
#line 3460 OMC_FILE
  TRACE_POP
}
/*
equation index: 306
type: SIMPLE_ASSIGN
thermalZoneFourElements.resIntRoof.Q_flow = 57.5 * thermalZoneFourElements.resIntRoof.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalConductor.mo"
  (data->localData[0]->realVars[266] /* thermalZoneFourElements.resIntRoof.Q_flow variable */) = (57.5) * ((data->localData[0]->realVars[267] /* thermalZoneFourElements.resIntRoof.dT variable */));
#line 3474 OMC_FILE
  TRACE_POP
}
/*
equation index: 307
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.port_a.Q_flow = thermalZoneFourElements.resExtWallRoof.Q_flow - (thermalZoneFourElements.resRoofFloor.Q_flow + thermalZoneFourElements.resIntRoof.Q_flow + thermalZoneFourElements.convRoof.Q_flow + thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow + thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow - thermalZoneFourElements.resRoofWin.Q_flow)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,307};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[277] /* thermalZoneFourElements.roofRC.port_a.Q_flow variable */) = (data->localData[0]->realVars[260] /* thermalZoneFourElements.resExtWallRoof.Q_flow variable */) - ((data->localData[0]->realVars[272] /* thermalZoneFourElements.resRoofFloor.Q_flow variable */) + (data->localData[0]->realVars[266] /* thermalZoneFourElements.resIntRoof.Q_flow variable */) + (data->localData[0]->realVars[225] /* thermalZoneFourElements.convRoof.Q_flow variable */) + (data->localData[0]->realVars[293] /* thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow variable */) + (data->localData[0]->realVars[286] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow variable */) - (data->localData[0]->realVars[274] /* thermalZoneFourElements.resRoofWin.Q_flow variable */));
#line 3488 OMC_FILE
  TRACE_POP
}
/*
equation index: 308
type: SIMPLE_ASSIGN
thermalZoneFourElements.convIntWall.Q_flow = thermalZoneFourElements.resExtWallIntWall.Q_flow - (thermalZoneFourElements.resIntWallFloor.Q_flow + thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow + thermalZoneFourElements.thermSplitterSolRad.portOut[3].Q_flow + thermalZoneFourElements.thermSplitterIntGains.portOut[3].Q_flow - thermalZoneFourElements.resIntWallWin.Q_flow - thermalZoneFourElements.resIntRoof.Q_flow)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,308};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[223] /* thermalZoneFourElements.convIntWall.Q_flow variable */) = (data->localData[0]->realVars[258] /* thermalZoneFourElements.resExtWallIntWall.Q_flow variable */) - ((data->localData[0]->realVars[268] /* thermalZoneFourElements.resIntWallFloor.Q_flow variable */) + (data->localData[0]->realVars[250] /* thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow variable */) + (data->localData[0]->realVars[292] /* thermalZoneFourElements.thermSplitterSolRad.portOut[3].Q_flow variable */) + (data->localData[0]->realVars[285] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].Q_flow variable */) - (data->localData[0]->realVars[270] /* thermalZoneFourElements.resIntWallWin.Q_flow variable */) - (data->localData[0]->realVars[266] /* thermalZoneFourElements.resIntRoof.Q_flow variable */));
#line 3502 OMC_FILE
  TRACE_POP
}
/*
equation index: 309
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermResExt[1].dT = 0.00331421908725 * thermalZoneFourElements.roofRC.port_a.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[280] /* thermalZoneFourElements.roofRC.thermResExt[1].dT variable */) = (0.00331421908725) * ((data->localData[0]->realVars[277] /* thermalZoneFourElements.roofRC.port_a.Q_flow variable */));
#line 3516 OMC_FILE
  TRACE_POP
}
/*
equation index: 310
type: SIMPLE_ASSIGN
thermalZoneFourElements.convIntWall.dT = (-thermalZoneFourElements.convIntWall.Q_flow) / (-128.26)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[224] /* thermalZoneFourElements.convIntWall.dT variable */) = DIVISION_SIM((-(data->localData[0]->realVars[223] /* thermalZoneFourElements.convIntWall.Q_flow variable */)),-128.26,"-128.26",equationIndexes);
#line 3530 OMC_FILE
  TRACE_POP
}
/*
equation index: 311
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermCapExt[1].T = thermalZoneFourElements.thermSplitterIntGains.portOut[5].T - thermalZoneFourElements.roofRC.thermResExt[1].dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[3] /* thermalZoneFourElements.roofRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.roofRC.thermCapExt[1].der_T) */) = (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) - (data->localData[0]->realVars[280] /* thermalZoneFourElements.roofRC.thermResExt[1].dT variable */);
#line 3544 OMC_FILE
  TRACE_POP
}
/*
equation index: 312
type: SIMPLE_ASSIGN
theConRoof.Q_flow = thermalZoneFourElements.roofRC.port_a.Q_flow - thermalZoneFourElements.roofRC.thermCapExt[1].port.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,312};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[208] /* theConRoof.Q_flow variable */) = (data->localData[0]->realVars[277] /* thermalZoneFourElements.roofRC.port_a.Q_flow variable */) - (data->localData[0]->realVars[279] /* thermalZoneFourElements.roofRC.thermCapExt[1].port.Q_flow variable */);
#line 3558 OMC_FILE
  TRACE_POP
}
/*
equation index: 313
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermResExtRem.dT = 0.1265217391 * theConRoof.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,313};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[281] /* thermalZoneFourElements.roofRC.thermResExtRem.dT variable */) = (0.1265217391) * ((data->localData[0]->realVars[208] /* theConRoof.Q_flow variable */));
#line 3572 OMC_FILE
  TRACE_POP
}
/*
equation index: 314
type: SIMPLE_ASSIGN
theConRoof.dT = (-theConRoof.Q_flow) / (-287.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[209] /* theConRoof.dT variable */) = DIVISION_SIM((-(data->localData[0]->realVars[208] /* theConRoof.Q_flow variable */)),-287.5,"-287.5",equationIndexes);
#line 3586 OMC_FILE
  TRACE_POP
}
/*
equation index: 315
type: SIMPLE_ASSIGN
theConRoof.solid.T = thermalZoneFourElements.roofRC.thermCapExt[1].T - thermalZoneFourElements.roofRC.thermResExtRem.dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,315};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[210] /* theConRoof.solid.T variable */) = (data->localData[0]->realVars[3] /* thermalZoneFourElements.roofRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.roofRC.thermCapExt[1].der_T) */) - (data->localData[0]->realVars[281] /* thermalZoneFourElements.roofRC.thermResExtRem.dT variable */);
#line 3600 OMC_FILE
  TRACE_POP
}

void residualFunc372(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,372};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) = xloc[0];
  (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) = xloc[1];
  (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) = xloc[2];
  (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) = xloc[3];
  (data->localData[0]->realVars[219] /* thermalZoneFourElements.convExtWall.dT variable */) = xloc[4];
  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_263(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_264(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_265(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_266(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_267(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_268(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_269(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_270(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_271(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_272(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_273(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_274(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_275(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_276(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_277(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_278(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_279(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_280(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_281(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_282(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_283(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_284(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_285(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_286(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_287(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_288(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_289(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_290(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_291(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_292(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_293(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_294(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_295(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_296(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_297(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_298(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_299(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_300(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_301(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_302(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_303(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_304(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_305(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_306(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_307(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_308(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_309(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_310(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_311(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_312(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_313(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_314(data, threadData);

  /* local constraints */
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_315(data, threadData);
  res[0] = (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) + (-(data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */)) - (data->localData[0]->realVars[224] /* thermalZoneFourElements.convIntWall.dT variable */);

  res[1] = (data->localData[0]->realVars[210] /* theConRoof.solid.T variable */) + (-(data->localData[0]->realVars[193] /* eqAirTempVDI.TEqWall[1] variable */)) - (data->localData[0]->realVars[209] /* theConRoof.dT variable */);

  res[2] = -283.15 + (data->localData[0]->realVars[1] /* thermalZoneFourElements.floorRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.floorRC.thermCapExt[1].der_T) */) - (data->localData[0]->realVars[242] /* thermalZoneFourElements.floorRC.thermResExtRem.dT variable */);

  res[3] = (data->localData[0]->realVars[231] /* thermalZoneFourElements.extWall.T variable */) + (-(data->localData[0]->realVars[204] /* preTem.T variable */)) - (data->localData[0]->realVars[212] /* theConWall.dT variable */);

  res[4] = (data->localData[0]->realVars[215] /* theConWin.solid.T variable */) + (-(data->localData[0]->realVars[205] /* preTem1.T variable */)) - (data->localData[0]->realVars[214] /* theConWin.dT variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData372(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut[3].T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[287].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[287].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[287].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut[5].T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[289].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[289].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[289].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterIntGains.portOut[4].T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[288].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[288].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[288].attribute /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T */.max;
  /* static ls data for thermalZoneFourElements.thermSplitterSolRad.portOut[2].T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[295].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[295].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[295].attribute /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T */.max;
  /* static ls data for thermalZoneFourElements.convExtWall.dT */
  linearSystemData->nominal[i] = data->modelData->realVarsData[219].attribute /* thermalZoneFourElements.convExtWall.dT */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[219].attribute /* thermalZoneFourElements.convExtWall.dT */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[219].attribute /* thermalZoneFourElements.convExtWall.dT */.max;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize linear systems */
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA* linearSystemData)
{
  /* linear systems */
  assertStreamPrint(NULL, nLinearSystems > 11, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[11].equationIndex = 2448;
  linearSystemData[11].size = 4;
  linearSystemData[11].nnz = 0;
  linearSystemData[11].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[11].residualFunc = residualFunc2448;
  linearSystemData[11].strictTearingFunctionCall = NULL;
  linearSystemData[11].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac8_column;
  linearSystemData[11].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac8;
  linearSystemData[11].jacobianIndex = 18 /*jacInx*/;
  linearSystemData[11].setA = NULL;  //setLinearMatrixA2448;
  linearSystemData[11].setb = NULL;  //setLinearVectorb2448;
  linearSystemData[11].initializeStaticLSData = initializeStaticLSData2448;
  
  assertStreamPrint(NULL, nLinearSystems > 10, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[10].equationIndex = 2361;
  linearSystemData[10].size = 1;
  linearSystemData[10].nnz = 0;
  linearSystemData[10].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[10].residualFunc = residualFunc2361;
  linearSystemData[10].strictTearingFunctionCall = NULL;
  linearSystemData[10].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac7_column;
  linearSystemData[10].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac7;
  linearSystemData[10].jacobianIndex = 17 /*jacInx*/;
  linearSystemData[10].setA = NULL;  //setLinearMatrixA2361;
  linearSystemData[10].setb = NULL;  //setLinearVectorb2361;
  linearSystemData[10].initializeStaticLSData = initializeStaticLSData2361;
  
  assertStreamPrint(NULL, nLinearSystems > 9, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[9].equationIndex = 2352;
  linearSystemData[9].size = 1;
  linearSystemData[9].nnz = 0;
  linearSystemData[9].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[9].residualFunc = residualFunc2352;
  linearSystemData[9].strictTearingFunctionCall = NULL;
  linearSystemData[9].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac6_column;
  linearSystemData[9].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac6;
  linearSystemData[9].jacobianIndex = 16 /*jacInx*/;
  linearSystemData[9].setA = NULL;  //setLinearMatrixA2352;
  linearSystemData[9].setb = NULL;  //setLinearVectorb2352;
  linearSystemData[9].initializeStaticLSData = initializeStaticLSData2352;
  
  assertStreamPrint(NULL, nLinearSystems > 8, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[8].equationIndex = 2193;
  linearSystemData[8].size = 1;
  linearSystemData[8].nnz = 0;
  linearSystemData[8].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[8].residualFunc = residualFunc2193;
  linearSystemData[8].strictTearingFunctionCall = NULL;
  linearSystemData[8].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac5_column;
  linearSystemData[8].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac5;
  linearSystemData[8].jacobianIndex = 15 /*jacInx*/;
  linearSystemData[8].setA = NULL;  //setLinearMatrixA2193;
  linearSystemData[8].setb = NULL;  //setLinearVectorb2193;
  linearSystemData[8].initializeStaticLSData = initializeStaticLSData2193;
  
  assertStreamPrint(NULL, nLinearSystems > 7, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[7].equationIndex = 1880;
  linearSystemData[7].size = 4;
  linearSystemData[7].nnz = 0;
  linearSystemData[7].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[7].residualFunc = residualFunc1880;
  linearSystemData[7].strictTearingFunctionCall = NULL;
  linearSystemData[7].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac12_column;
  linearSystemData[7].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac12;
  linearSystemData[7].jacobianIndex = 8 /*jacInx*/;
  linearSystemData[7].setA = NULL;  //setLinearMatrixA1880;
  linearSystemData[7].setb = NULL;  //setLinearVectorb1880;
  linearSystemData[7].initializeStaticLSData = initializeStaticLSData1880;
  
  assertStreamPrint(NULL, nLinearSystems > 6, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[6].equationIndex = 1793;
  linearSystemData[6].size = 1;
  linearSystemData[6].nnz = 0;
  linearSystemData[6].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[6].residualFunc = residualFunc1793;
  linearSystemData[6].strictTearingFunctionCall = NULL;
  linearSystemData[6].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac11_column;
  linearSystemData[6].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac11;
  linearSystemData[6].jacobianIndex = 7 /*jacInx*/;
  linearSystemData[6].setA = NULL;  //setLinearMatrixA1793;
  linearSystemData[6].setb = NULL;  //setLinearVectorb1793;
  linearSystemData[6].initializeStaticLSData = initializeStaticLSData1793;
  
  assertStreamPrint(NULL, nLinearSystems > 5, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[5].equationIndex = 1784;
  linearSystemData[5].size = 1;
  linearSystemData[5].nnz = 0;
  linearSystemData[5].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[5].residualFunc = residualFunc1784;
  linearSystemData[5].strictTearingFunctionCall = NULL;
  linearSystemData[5].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac10_column;
  linearSystemData[5].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac10;
  linearSystemData[5].jacobianIndex = 6 /*jacInx*/;
  linearSystemData[5].setA = NULL;  //setLinearMatrixA1784;
  linearSystemData[5].setb = NULL;  //setLinearVectorb1784;
  linearSystemData[5].initializeStaticLSData = initializeStaticLSData1784;
  
  assertStreamPrint(NULL, nLinearSystems > 4, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[4].equationIndex = 1625;
  linearSystemData[4].size = 1;
  linearSystemData[4].nnz = 0;
  linearSystemData[4].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[4].residualFunc = residualFunc1625;
  linearSystemData[4].strictTearingFunctionCall = NULL;
  linearSystemData[4].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac9_column;
  linearSystemData[4].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac9;
  linearSystemData[4].jacobianIndex = 5 /*jacInx*/;
  linearSystemData[4].setA = NULL;  //setLinearMatrixA1625;
  linearSystemData[4].setb = NULL;  //setLinearVectorb1625;
  linearSystemData[4].initializeStaticLSData = initializeStaticLSData1625;
  
  assertStreamPrint(NULL, nLinearSystems > 3, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[3].equationIndex = 761;
  linearSystemData[3].size = 4;
  linearSystemData[3].nnz = 0;
  linearSystemData[3].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[3].residualFunc = residualFunc761;
  linearSystemData[3].strictTearingFunctionCall = NULL;
  linearSystemData[3].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac4_column;
  linearSystemData[3].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac4;
  linearSystemData[3].jacobianIndex = 3 /*jacInx*/;
  linearSystemData[3].setA = NULL;  //setLinearMatrixA761;
  linearSystemData[3].setb = NULL;  //setLinearVectorb761;
  linearSystemData[3].initializeStaticLSData = initializeStaticLSData761;
  
  assertStreamPrint(NULL, nLinearSystems > 2, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[2].equationIndex = 651;
  linearSystemData[2].size = 1;
  linearSystemData[2].nnz = 0;
  linearSystemData[2].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[2].residualFunc = residualFunc651;
  linearSystemData[2].strictTearingFunctionCall = NULL;
  linearSystemData[2].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac2_column;
  linearSystemData[2].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac2;
  linearSystemData[2].jacobianIndex = 2 /*jacInx*/;
  linearSystemData[2].setA = NULL;  //setLinearMatrixA651;
  linearSystemData[2].setb = NULL;  //setLinearVectorb651;
  linearSystemData[2].initializeStaticLSData = initializeStaticLSData651;
  
  assertStreamPrint(NULL, nLinearSystems > 1, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[1].equationIndex = 511;
  linearSystemData[1].size = 1;
  linearSystemData[1].nnz = 0;
  linearSystemData[1].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[1].residualFunc = residualFunc511;
  linearSystemData[1].strictTearingFunctionCall = NULL;
  linearSystemData[1].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac1_column;
  linearSystemData[1].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac1;
  linearSystemData[1].jacobianIndex = 1 /*jacInx*/;
  linearSystemData[1].setA = NULL;  //setLinearMatrixA511;
  linearSystemData[1].setb = NULL;  //setLinearVectorb511;
  linearSystemData[1].initializeStaticLSData = initializeStaticLSData511;
  
  assertStreamPrint(NULL, nLinearSystems > 0, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[0].equationIndex = 372;
  linearSystemData[0].size = 5;
  linearSystemData[0].nnz = 0;
  linearSystemData[0].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[0].residualFunc = residualFunc372;
  linearSystemData[0].strictTearingFunctionCall = NULL;
  linearSystemData[0].analyticalJacobianColumn = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacLSJac0_column;
  linearSystemData[0].initialAnalyticalJacobian = Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianLSJac0;
  linearSystemData[0].jacobianIndex = 0 /*jacInx*/;
  linearSystemData[0].setA = NULL;  //setLinearMatrixA372;
  linearSystemData[0].setb = NULL;  //setLinearVectorb372;
  linearSystemData[0].initializeStaticLSData = initializeStaticLSData372;
}

#if defined(__cplusplus)
}
#endif

