#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustomNoHeat/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_03lsy.c"
#endif
/* Linear Systems */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* linear systems */

/*
equation index: 144
type: SIMPLE_ASSIGN
window.glaUns.glass[1].E_b = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass[1].T4_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[74] /* window.glaUns.glass[1].E_b variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[76] /* window.glaUns.glass[1].T4_b variable */)));
#line 26 OMC_FILE
  TRACE_POP
}
/*
equation index: 145
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT = 219.8625 - window.glaUns.glass[1].T4_b / (-100769635.3235) - 293.15
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
  (data->localData[0]->realVars[47] /* intShaCon.conWinUns.dT variable */) = 219.8625 - (DIVISION_SIM((data->localData[0]->realVars[76] /* window.glaUns.glass[1].T4_b variable */),-100769635.3235,"-100769635.3235",equationIndexes)) - 293.15;
  TRACE_POP
}
/*
equation index: 146
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow = 4.0 * intShaCon.conFra.u * intShaCon.conWinUns.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  (data->localData[0]->realVars[48] /* intShaCon.conWinUns.q_flow variable */) = (4.0) * (((data->localData[0]->realVars[43] /* intShaCon.conFra.u variable */)) * ((data->localData[0]->realVars[47] /* intShaCon.conWinUns.dT variable */)));
#line 52 OMC_FILE
  TRACE_POP
}
/*
equation index: 147
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow = 0.8 * intShaCon.conWinUns.q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[46] /* intShaCon.conWinUns.Q_flow variable */) = (0.8) * ((data->localData[0]->realVars[48] /* intShaCon.conWinUns.q_flow variable */));
#line 66 OMC_FILE
  TRACE_POP
}
/*
equation index: 148
type: SIMPLE_ASSIGN
window.glaUns_b.T = intShaCon.conWinUns.dT - -293.15
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,148};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[79] /* window.glaUns_b.T variable */) = (data->localData[0]->realVars[47] /* intShaCon.conWinUns.dT variable */) - (-293.15);
#line 80 OMC_FILE
  TRACE_POP
}
/*
equation index: 149
type: SIMPLE_ASSIGN
window.glaSha.glass[1].T4_b = -22155463946.31301 + 100769635.3235 * intShaCon.glaSha.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[70] /* window.glaSha.glass[1].T4_b variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */));
#line 94 OMC_FILE
  TRACE_POP
}
/*
equation index: 150
type: SIMPLE_ASSIGN
window.glaSha.glass[1].E_b = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass[1].T4_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[68] /* window.glaSha.glass[1].E_b variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[70] /* window.glaSha.glass[1].T4_b variable */)));
#line 108 OMC_FILE
  TRACE_POP
}
/*
equation index: 151
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow = intShaCon.conSha.Gc * (293.15 + 2.0 * (293.15 - intShaCon.TSha) - intShaCon.glaSha.T)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
#line 50 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[45] /* intShaCon.conSha.air.Q_flow variable */) = ((data->localData[0]->realVars[44] /* intShaCon.conSha.Gc variable */)) * (293.15 + (2.0) * (293.15 - (data->localData[0]->realVars[38] /* intShaCon.TSha variable */)) - (data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */));
#line 122 OMC_FILE
  TRACE_POP
}
/*
equation index: 152
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow = intShaCon.conSha.Gc * (-293.15 + 2.0 * intShaCon.glaSha.T - intShaCon.TSha)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[49] /* intShaCon.glaSha.Q_flow variable */) = ((data->localData[0]->realVars[44] /* intShaCon.conSha.Gc variable */)) * (-293.15 + (2.0) * ((data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */)) - (data->localData[0]->realVars[38] /* intShaCon.TSha variable */));
#line 136 OMC_FILE
  TRACE_POP
}
/*
equation index: 153
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow = (-intShaCon.conSha.air.Q_flow) - intShaCon.glaSha.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[37] /* intShaCon.QRadAbs_flow variable */) = (-(data->localData[0]->realVars[45] /* intShaCon.conSha.air.Q_flow variable */)) - (data->localData[0]->realVars[49] /* intShaCon.glaSha.Q_flow variable */);
#line 150 OMC_FILE
  TRACE_POP
}
/*
equation index: 154
type: SIMPLE_ASSIGN
intShaRad.T4 = 25192408.83087499 * intShaCon.TSha
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[57] /* intShaRad.T4 variable */) = (25192408.83087499) * ((data->localData[0]->realVars[38] /* intShaCon.TSha variable */));
#line 164 OMC_FILE
  TRACE_POP
}
/*
equation index: 155
type: SIMPLE_ASSIGN
intShaRad.E_glass = 1.134074883836886e-08 * shaSig.y * intShaRad.T4
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
#line 115 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[52] /* intShaRad.E_glass variable */) = (1.134074883836886e-08) * (((data->localData[0]->realVars[58] /* shaSig.y variable */)) * ((data->localData[0]->realVars[57] /* intShaRad.T4 variable */)));
#line 178 OMC_FILE
  TRACE_POP
}
/*
equation index: 156
type: SIMPLE_ASSIGN
intShaRad.JIn_air = shaSig.y * indRad.JIn
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,156};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (data->localData[0]->realVars[53] /* intShaRad.JIn_air variable */) = ((data->localData[0]->realVars[58] /* shaSig.y variable */)) * ((data->localData[0]->realVars[34] /* indRad.JIn variable */));
#line 192 OMC_FILE
  TRACE_POP
}
/*
equation index: 157
type: SIMPLE_ASSIGN
window.JInUns_b = (1.0 - shaSig.y) * indRad.JIn
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,157};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (data->localData[0]->realVars[62] /* window.JInUns_b variable */) = (1.0 - (data->localData[0]->realVars[58] /* shaSig.y variable */)) * ((data->localData[0]->realVars[34] /* indRad.JIn variable */));
#line 206 OMC_FILE
  TRACE_POP
}
/*
equation index: 158
type: SIMPLE_ASSIGN
intShaRad.JIn_glass = 8.0 * intShaRad.E_glass + 4.0 * intShaCon.QRadAbs_flow - (4.0 * QSolAbsInt_flow + intShaRad.JIn_air)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */) = (8.0) * ((data->localData[0]->realVars[52] /* intShaRad.E_glass variable */)) + (4.0) * ((data->localData[0]->realVars[37] /* intShaCon.QRadAbs_flow variable */)) - ((4.0) * ((data->localData[0]->realVars[3] /* QSolAbsInt_flow variable */)) + (data->localData[0]->realVars[53] /* intShaRad.JIn_air variable */));
#line 220 OMC_FILE
  TRACE_POP
}
/*
equation index: 159
type: SIMPLE_ASSIGN
window.JOutUns_b = window.glaUns.glass[1].E_b + 0.16 * window.JInUns_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,159};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[63] /* window.JOutUns_b variable */) = (data->localData[0]->realVars[74] /* window.glaUns.glass[1].E_b variable */) + (0.16) * ((data->localData[0]->realVars[62] /* window.JInUns_b variable */));
#line 234 OMC_FILE
  TRACE_POP
}
/*
equation index: 160
type: SIMPLE_ASSIGN
intShaRad.JOut_air = intShaRad.E_glass + 0.75 * intShaRad.JIn_air
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[55] /* intShaRad.JOut_air variable */) = (data->localData[0]->realVars[52] /* intShaRad.E_glass variable */) + (0.75) * ((data->localData[0]->realVars[53] /* intShaRad.JIn_air variable */));
#line 248 OMC_FILE
  TRACE_POP
}
/*
equation index: 161
type: SIMPLE_ASSIGN
intShaRad.JOut_glass = (window.glaSha.glass[1].E_b - intShaRad.JIn_glass) / (-0.16)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,161};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[56] /* intShaRad.JOut_glass variable */) = DIVISION_SIM((data->localData[0]->realVars[68] /* window.glaSha.glass[1].E_b variable */) - (data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */),-0.16,"-0.16",equationIndexes);
#line 262 OMC_FILE
  TRACE_POP
}
/*
equation index: 162
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow = (-extCon.shaCon.Gc) * (TOut - window.glaSha_a.T)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[19] /* extCon.glaSha.Q_flow variable */) = ((-(data->localData[0]->realVars[23] /* extCon.shaCon.Gc variable */))) * ((data->localData[0]->realVars[5] /* TOut variable */) - (data->localData[0]->realVars[72] /* window.glaSha_a.T variable */));
#line 276 OMC_FILE
  TRACE_POP
}
/*
equation index: 163
type: SIMPLE_ASSIGN
extCon.JInSha = extCon.JOutSha - ((-0.5) * QAbsSha_flow + extCon.glaSha.Q_flow) - window.glaSha.u * (intShaCon.glaSha.T - window.glaSha_a.T) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,163};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[9] /* extCon.JInSha variable */) = (data->localData[0]->realVars[11] /* extCon.JOutSha variable */) - ((-0.5) * ((data->localData[0]->realVars[0] /* QAbsSha_flow variable */)) + (data->localData[0]->realVars[19] /* extCon.glaSha.Q_flow variable */)) - (DIVISION_SIM(((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */) - (data->localData[0]->realVars[72] /* window.glaSha_a.T variable */)),-0.00375,"-0.00375",equationIndexes));
#line 290 OMC_FILE
  TRACE_POP
}
/*
equation index: 164
type: SIMPLE_ASSIGN
window.glaSha.glass[1].T4_a = -22155463946.31301 + 100769635.3235 * window.glaSha_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[69] /* window.glaSha.glass[1].T4_a variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[72] /* window.glaSha_a.T variable */));
#line 304 OMC_FILE
  TRACE_POP
}
/*
equation index: 165
type: SIMPLE_ASSIGN
window.glaSha.glass[1].E_a = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass[1].T4_a
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[67] /* window.glaSha.glass[1].E_a variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[69] /* window.glaSha.glass[1].T4_a variable */)));
#line 318 OMC_FILE
  TRACE_POP
}
/*
equation index: 166
type: SIMPLE_ASSIGN
window.glaUns.glass[1].T4_a = -22155463946.31301 + 100769635.3235 * window.glaUns_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[75] /* window.glaUns.glass[1].T4_a variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[78] /* window.glaUns_a.T variable */));
#line 332 OMC_FILE
  TRACE_POP
}
/*
equation index: 167
type: SIMPLE_ASSIGN
window.glaUns.glass[1].E_a = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass[1].T4_a
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[73] /* window.glaUns.glass[1].E_a variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[75] /* window.glaUns.glass[1].T4_a variable */)));
#line 346 OMC_FILE
  TRACE_POP
}
/*
equation index: 168
type: SIMPLE_ASSIGN
extCon.JInUns = window.glaUns.glass[1].E_a + 0.16 * extCon.JOutUns
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[10] /* extCon.JInUns variable */) = (data->localData[0]->realVars[73] /* window.glaUns.glass[1].E_a variable */) + (0.16) * ((data->localData[0]->realVars[12] /* extCon.JOutUns variable */));
#line 360 OMC_FILE
  TRACE_POP
}
/*
equation index: 169
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow = extCon.JOutUns - ((-0.5) * QAbsUns_flow + extCon.JInUns) - window.glaUns.u * (window.glaUns_b.T - window.glaUns_a.T) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[17] /* extCon.conWinUns.Q_flow variable */) = (data->localData[0]->realVars[12] /* extCon.JOutUns variable */) - ((-0.5) * ((data->localData[0]->realVars[1] /* QAbsUns_flow variable */)) + (data->localData[0]->realVars[10] /* extCon.JInUns variable */)) - (DIVISION_SIM(((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[79] /* window.glaUns_b.T variable */) - (data->localData[0]->realVars[78] /* window.glaUns_a.T variable */)),-0.00375,"-0.00375",equationIndexes));
#line 374 OMC_FILE
  TRACE_POP
}
/*
equation index: 170
type: SIMPLE_ASSIGN
extCon.conWinUns.dT = window.glaUns_a.T - TOut
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[18] /* extCon.conWinUns.dT variable */) = (data->localData[0]->realVars[78] /* window.glaUns_a.T variable */) - (data->localData[0]->realVars[5] /* TOut variable */);
#line 388 OMC_FILE
  TRACE_POP
}

void residualFunc207(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,207};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[78] /* window.glaUns_a.T variable */) = xloc[0];
  (data->localData[0]->realVars[72] /* window.glaSha_a.T variable */) = xloc[1];
  (data->localData[0]->realVars[34] /* indRad.JIn variable */) = xloc[2];
  (data->localData[0]->realVars[38] /* intShaCon.TSha variable */) = xloc[3];
  (data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */) = xloc[4];
  (data->localData[0]->realVars[76] /* window.glaUns.glass[1].T4_b variable */) = xloc[5];
  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_144(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_145(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_146(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_147(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_148(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_149(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_150(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_151(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_152(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_153(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_154(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_155(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_156(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_157(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_158(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_159(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_160(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_161(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_162(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_163(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_164(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_165(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_166(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_167(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_168(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_169(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_170(data, threadData);
  res[0] = (0.75) * ((data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */)) + (data->localData[0]->realVars[52] /* intShaRad.E_glass variable */) - (data->localData[0]->realVars[56] /* intShaRad.JOut_glass variable */);

  res[1] = (0.16) * ((data->localData[0]->realVars[11] /* extCon.JOutSha variable */)) + (data->localData[0]->realVars[67] /* window.glaSha.glass[1].E_a variable */) - (data->localData[0]->realVars[9] /* extCon.JInSha variable */);

  res[2] = (-(data->localData[0]->realVars[9] /* extCon.JInSha variable */)) - (data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */) - (data->localData[0]->realVars[19] /* extCon.glaSha.Q_flow variable */) - (data->localData[0]->realVars[49] /* intShaCon.glaSha.Q_flow variable */) + (data->localData[0]->realVars[56] /* intShaRad.JOut_glass variable */) + (data->localData[0]->realVars[11] /* extCon.JOutSha variable */) + (data->localData[0]->realVars[0] /* QAbsSha_flow variable */);

  res[3] = (data->localData[0]->realVars[55] /* intShaRad.JOut_air variable */) + (data->localData[0]->realVars[63] /* window.JOutUns_b variable */) - (data->localData[0]->realVars[34] /* indRad.JIn variable */);

  res[4] = ((data->localData[0]->realVars[16] /* extCon.conWinUns.Gc variable */)) * ((data->localData[0]->realVars[18] /* extCon.conWinUns.dT variable */)) - (data->localData[0]->realVars[17] /* extCon.conWinUns.Q_flow variable */);

  res[5] = (-(data->localData[0]->realVars[10] /* extCon.JInUns variable */)) - (data->localData[0]->realVars[63] /* window.JOutUns_b variable */) - (data->localData[0]->realVars[17] /* extCon.conWinUns.Q_flow variable */) - (data->localData[0]->realVars[46] /* intShaCon.conWinUns.Q_flow variable */) + (data->localData[0]->realVars[62] /* window.JInUns_b variable */) + (data->localData[0]->realVars[12] /* extCon.JOutUns variable */) + (data->localData[0]->realVars[1] /* QAbsUns_flow variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData207(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for window.glaUns_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[78].attribute /* window.glaUns_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[78].attribute /* window.glaUns_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[78].attribute /* window.glaUns_a.T */.max;
  /* static ls data for window.glaSha_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[72].attribute /* window.glaSha_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[72].attribute /* window.glaSha_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[72].attribute /* window.glaSha_a.T */.max;
  /* static ls data for indRad.JIn */
  linearSystemData->nominal[i] = data->modelData->realVarsData[34].attribute /* indRad.JIn */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[34].attribute /* indRad.JIn */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[34].attribute /* indRad.JIn */.max;
  /* static ls data for intShaCon.TSha */
  linearSystemData->nominal[i] = data->modelData->realVarsData[38].attribute /* intShaCon.TSha */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[38].attribute /* intShaCon.TSha */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[38].attribute /* intShaCon.TSha */.max;
  /* static ls data for intShaCon.glaSha.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[50].attribute /* intShaCon.glaSha.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[50].attribute /* intShaCon.glaSha.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[50].attribute /* intShaCon.glaSha.T */.max;
  /* static ls data for window.glaUns.glass[1].T4_b */
  linearSystemData->nominal[i] = data->modelData->realVarsData[76].attribute /* window.glaUns.glass[1].T4_b */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[76].attribute /* window.glaUns.glass[1].T4_b */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[76].attribute /* window.glaUns.glass[1].T4_b */.max;
}


/*
equation index: 131
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow = (-extCon.conCoeFra.GCon) * extCon.conFra.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[40] /* intShaCon.conFra.Q_flow variable */) = ((-(data->localData[0]->realVars[13] /* extCon.conCoeFra.GCon variable */))) * ((data->localData[0]->realVars[15] /* extCon.conFra.dT variable */));
#line 540 OMC_FILE
  TRACE_POP
}
/*
equation index: 132
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow = 5.0 * intShaCon.conFra.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[42] /* intShaCon.conFra.q_flow variable */) = (5.0) * ((data->localData[0]->realVars[40] /* intShaCon.conFra.Q_flow variable */));
#line 554 OMC_FILE
  TRACE_POP
}
/*
equation index: 133
type: SIMPLE_ASSIGN
window.frame.dT = 0.3333333333333333 * intShaCon.conFra.q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,133};
  (data->localData[0]->realVars[66] /* window.frame.dT variable */) = (0.3333333333333333) * ((data->localData[0]->realVars[42] /* intShaCon.conFra.q_flow variable */));
  TRACE_POP
}
/*
equation index: 134
type: SIMPLE_ASSIGN
window.fra_a.T = TOut + extCon.conFra.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[64] /* window.fra_a.T variable */) = (data->localData[0]->realVars[5] /* TOut variable */) + (data->localData[0]->realVars[15] /* extCon.conFra.dT variable */);
#line 580 OMC_FILE
  TRACE_POP
}
/*
equation index: 135
type: SIMPLE_ASSIGN
window.fra_b.T = window.fra_a.T - window.frame.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,135};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[65] /* window.fra_b.T variable */) = (data->localData[0]->realVars[64] /* window.fra_a.T variable */) - (data->localData[0]->realVars[66] /* window.frame.dT variable */);
#line 594 OMC_FILE
  TRACE_POP
}
/*
equation index: 136
type: SIMPLE_ASSIGN
intShaCon.conFra.dT = -293.15 + window.fra_b.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[41] /* intShaCon.conFra.dT variable */) = -293.15 + (data->localData[0]->realVars[65] /* window.fra_b.T variable */);
#line 608 OMC_FILE
  TRACE_POP
}

void residualFunc143(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,143};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[15] /* extCon.conFra.dT variable */) = xloc[0];
  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_131(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_132(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_133(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_134(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_135(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_136(data, threadData);
  res[0] = (4.0) * (((data->localData[0]->realVars[43] /* intShaCon.conFra.u variable */)) * ((data->localData[0]->realVars[41] /* intShaCon.conFra.dT variable */))) - (data->localData[0]->realVars[42] /* intShaCon.conFra.q_flow variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData143(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for extCon.conFra.dT */
  linearSystemData->nominal[i] = data->modelData->realVarsData[15].attribute /* extCon.conFra.dT */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[15].attribute /* extCon.conFra.dT */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[15].attribute /* extCon.conFra.dT */.max;
}


/*
equation index: 42
type: SIMPLE_ASSIGN
window.glaUns.glass[1].E_b = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass[1].T4_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[74] /* window.glaUns.glass[1].E_b variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[76] /* window.glaUns.glass[1].T4_b variable */)));
#line 662 OMC_FILE
  TRACE_POP
}
/*
equation index: 43
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT = 219.8625 - window.glaUns.glass[1].T4_b / (-100769635.3235) - 293.15
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  (data->localData[0]->realVars[47] /* intShaCon.conWinUns.dT variable */) = 219.8625 - (DIVISION_SIM((data->localData[0]->realVars[76] /* window.glaUns.glass[1].T4_b variable */),-100769635.3235,"-100769635.3235",equationIndexes)) - 293.15;
  TRACE_POP
}
/*
equation index: 44
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow = 4.0 * intShaCon.conFra.u * intShaCon.conWinUns.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  (data->localData[0]->realVars[48] /* intShaCon.conWinUns.q_flow variable */) = (4.0) * (((data->localData[0]->realVars[43] /* intShaCon.conFra.u variable */)) * ((data->localData[0]->realVars[47] /* intShaCon.conWinUns.dT variable */)));
#line 688 OMC_FILE
  TRACE_POP
}
/*
equation index: 45
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow = 0.8 * intShaCon.conWinUns.q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[46] /* intShaCon.conWinUns.Q_flow variable */) = (0.8) * ((data->localData[0]->realVars[48] /* intShaCon.conWinUns.q_flow variable */));
#line 702 OMC_FILE
  TRACE_POP
}
/*
equation index: 46
type: SIMPLE_ASSIGN
window.glaUns_b.T = intShaCon.conWinUns.dT - -293.15
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[79] /* window.glaUns_b.T variable */) = (data->localData[0]->realVars[47] /* intShaCon.conWinUns.dT variable */) - (-293.15);
#line 716 OMC_FILE
  TRACE_POP
}
/*
equation index: 47
type: SIMPLE_ASSIGN
window.glaSha.glass[1].T4_b = -22155463946.31301 + 100769635.3235 * intShaCon.glaSha.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[70] /* window.glaSha.glass[1].T4_b variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */));
#line 730 OMC_FILE
  TRACE_POP
}
/*
equation index: 48
type: SIMPLE_ASSIGN
window.glaSha.glass[1].E_b = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass[1].T4_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[68] /* window.glaSha.glass[1].E_b variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[70] /* window.glaSha.glass[1].T4_b variable */)));
#line 744 OMC_FILE
  TRACE_POP
}
/*
equation index: 49
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow = intShaCon.conSha.Gc * (293.15 + 2.0 * (293.15 - intShaCon.TSha) - intShaCon.glaSha.T)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
#line 50 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[45] /* intShaCon.conSha.air.Q_flow variable */) = ((data->localData[0]->realVars[44] /* intShaCon.conSha.Gc variable */)) * (293.15 + (2.0) * (293.15 - (data->localData[0]->realVars[38] /* intShaCon.TSha variable */)) - (data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */));
#line 758 OMC_FILE
  TRACE_POP
}
/*
equation index: 50
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow = intShaCon.conSha.Gc * (-293.15 + 2.0 * intShaCon.glaSha.T - intShaCon.TSha)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[49] /* intShaCon.glaSha.Q_flow variable */) = ((data->localData[0]->realVars[44] /* intShaCon.conSha.Gc variable */)) * (-293.15 + (2.0) * ((data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */)) - (data->localData[0]->realVars[38] /* intShaCon.TSha variable */));
#line 772 OMC_FILE
  TRACE_POP
}
/*
equation index: 51
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow = (-intShaCon.conSha.air.Q_flow) - intShaCon.glaSha.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[37] /* intShaCon.QRadAbs_flow variable */) = (-(data->localData[0]->realVars[45] /* intShaCon.conSha.air.Q_flow variable */)) - (data->localData[0]->realVars[49] /* intShaCon.glaSha.Q_flow variable */);
#line 786 OMC_FILE
  TRACE_POP
}
/*
equation index: 52
type: SIMPLE_ASSIGN
intShaRad.T4 = 25192408.83087499 * intShaCon.TSha
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[57] /* intShaRad.T4 variable */) = (25192408.83087499) * ((data->localData[0]->realVars[38] /* intShaCon.TSha variable */));
#line 800 OMC_FILE
  TRACE_POP
}
/*
equation index: 53
type: SIMPLE_ASSIGN
intShaRad.E_glass = 1.134074883836886e-08 * shaSig.y * intShaRad.T4
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
#line 115 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[52] /* intShaRad.E_glass variable */) = (1.134074883836886e-08) * (((data->localData[0]->realVars[58] /* shaSig.y variable */)) * ((data->localData[0]->realVars[57] /* intShaRad.T4 variable */)));
#line 814 OMC_FILE
  TRACE_POP
}
/*
equation index: 54
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow = (-extCon.shaCon.Gc) * (TOut - window.glaSha_a.T)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[19] /* extCon.glaSha.Q_flow variable */) = ((-(data->localData[0]->realVars[23] /* extCon.shaCon.Gc variable */))) * ((data->localData[0]->realVars[5] /* TOut variable */) - (data->localData[0]->realVars[72] /* window.glaSha_a.T variable */));
#line 828 OMC_FILE
  TRACE_POP
}
/*
equation index: 55
type: SIMPLE_ASSIGN
extCon.JInSha = extCon.JOutSha - ((-0.5) * QAbsSha_flow + extCon.glaSha.Q_flow) - window.glaSha.u * (intShaCon.glaSha.T - window.glaSha_a.T) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[9] /* extCon.JInSha variable */) = (data->localData[0]->realVars[11] /* extCon.JOutSha variable */) - ((-0.5) * ((data->localData[0]->realVars[0] /* QAbsSha_flow variable */)) + (data->localData[0]->realVars[19] /* extCon.glaSha.Q_flow variable */)) - (DIVISION_SIM(((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */) - (data->localData[0]->realVars[72] /* window.glaSha_a.T variable */)),-0.00375,"-0.00375",equationIndexes));
#line 842 OMC_FILE
  TRACE_POP
}
/*
equation index: 56
type: SIMPLE_ASSIGN
window.glaSha.glass[1].T4_a = -22155463946.31301 + 100769635.3235 * window.glaSha_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[69] /* window.glaSha.glass[1].T4_a variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[72] /* window.glaSha_a.T variable */));
#line 856 OMC_FILE
  TRACE_POP
}
/*
equation index: 57
type: SIMPLE_ASSIGN
window.glaSha.glass[1].E_a = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass[1].T4_a
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[67] /* window.glaSha.glass[1].E_a variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[69] /* window.glaSha.glass[1].T4_a variable */)));
#line 870 OMC_FILE
  TRACE_POP
}
/*
equation index: 58
type: SIMPLE_ASSIGN
intShaRad.JIn_air = 8.0 * intShaRad.E_glass + 4.0 * intShaCon.QRadAbs_flow - (4.0 * QSolAbsInt_flow + intShaRad.JIn_glass)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[53] /* intShaRad.JIn_air variable */) = (8.0) * ((data->localData[0]->realVars[52] /* intShaRad.E_glass variable */)) + (4.0) * ((data->localData[0]->realVars[37] /* intShaCon.QRadAbs_flow variable */)) - ((4.0) * ((data->localData[0]->realVars[3] /* QSolAbsInt_flow variable */)) + (data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */));
#line 884 OMC_FILE
  TRACE_POP
}
/*
equation index: 59
type: SIMPLE_ASSIGN
intShaRad.JOut_glass = extCon.JInSha - (QAbsSha_flow + extCon.JOutSha - intShaCon.glaSha.Q_flow - extCon.glaSha.Q_flow - intShaRad.JIn_glass)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[56] /* intShaRad.JOut_glass variable */) = (data->localData[0]->realVars[9] /* extCon.JInSha variable */) - ((data->localData[0]->realVars[0] /* QAbsSha_flow variable */) + (data->localData[0]->realVars[11] /* extCon.JOutSha variable */) - (data->localData[0]->realVars[49] /* intShaCon.glaSha.Q_flow variable */) - (data->localData[0]->realVars[19] /* extCon.glaSha.Q_flow variable */) - (data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */));
#line 898 OMC_FILE
  TRACE_POP
}
/*
equation index: 60
type: SIMPLE_ASSIGN
intShaRad.JOut_air = intShaRad.E_glass + 0.75 * intShaRad.JIn_air
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[55] /* intShaRad.JOut_air variable */) = (data->localData[0]->realVars[52] /* intShaRad.E_glass variable */) + (0.75) * ((data->localData[0]->realVars[53] /* intShaRad.JIn_air variable */));
#line 912 OMC_FILE
  TRACE_POP
}
/*
equation index: 61
type: SIMPLE_ASSIGN
window.JInUns_b = (1.0 - shaSig.y) * indRad.JIn
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (data->localData[0]->realVars[62] /* window.JInUns_b variable */) = (1.0 - (data->localData[0]->realVars[58] /* shaSig.y variable */)) * ((data->localData[0]->realVars[34] /* indRad.JIn variable */));
#line 926 OMC_FILE
  TRACE_POP
}
/*
equation index: 62
type: SIMPLE_ASSIGN
window.JOutUns_b = window.glaUns.glass[1].E_b + 0.16 * window.JInUns_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[63] /* window.JOutUns_b variable */) = (data->localData[0]->realVars[74] /* window.glaUns.glass[1].E_b variable */) + (0.16) * ((data->localData[0]->realVars[62] /* window.JInUns_b variable */));
#line 940 OMC_FILE
  TRACE_POP
}
/*
equation index: 63
type: SIMPLE_ASSIGN
window.glaUns.glass[1].T4_a = -22155463946.31301 + 100769635.3235 * window.glaUns_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[75] /* window.glaUns.glass[1].T4_a variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[78] /* window.glaUns_a.T variable */));
#line 954 OMC_FILE
  TRACE_POP
}
/*
equation index: 64
type: SIMPLE_ASSIGN
window.glaUns.glass[1].E_a = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass[1].T4_a
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[73] /* window.glaUns.glass[1].E_a variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[75] /* window.glaUns.glass[1].T4_a variable */)));
#line 968 OMC_FILE
  TRACE_POP
}
/*
equation index: 65
type: SIMPLE_ASSIGN
extCon.conWinUns.dT = window.glaUns_a.T - TOut
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[18] /* extCon.conWinUns.dT variable */) = (data->localData[0]->realVars[78] /* window.glaUns_a.T variable */) - (data->localData[0]->realVars[5] /* TOut variable */);
#line 982 OMC_FILE
  TRACE_POP
}
/*
equation index: 66
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow = extCon.conWinUns.Gc * extCon.conWinUns.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[17] /* extCon.conWinUns.Q_flow variable */) = ((data->localData[0]->realVars[16] /* extCon.conWinUns.Gc variable */)) * ((data->localData[0]->realVars[18] /* extCon.conWinUns.dT variable */));
#line 996 OMC_FILE
  TRACE_POP
}
/*
equation index: 67
type: SIMPLE_ASSIGN
extCon.JInUns = extCon.JOutUns - ((-0.5) * QAbsUns_flow + extCon.conWinUns.Q_flow) - window.glaUns.u * (window.glaUns_b.T - window.glaUns_a.T) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[10] /* extCon.JInUns variable */) = (data->localData[0]->realVars[12] /* extCon.JOutUns variable */) - ((-0.5) * ((data->localData[0]->realVars[1] /* QAbsUns_flow variable */)) + (data->localData[0]->realVars[17] /* extCon.conWinUns.Q_flow variable */)) - (DIVISION_SIM(((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[79] /* window.glaUns_b.T variable */) - (data->localData[0]->realVars[78] /* window.glaUns_a.T variable */)),-0.00375,"-0.00375",equationIndexes));
#line 1010 OMC_FILE
  TRACE_POP
}

void residualFunc106(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,106};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[78] /* window.glaUns_a.T variable */) = xloc[0];
  (data->localData[0]->realVars[34] /* indRad.JIn variable */) = xloc[1];
  (data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */) = xloc[2];
  (data->localData[0]->realVars[72] /* window.glaSha_a.T variable */) = xloc[3];
  (data->localData[0]->realVars[38] /* intShaCon.TSha variable */) = xloc[4];
  (data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */) = xloc[5];
  (data->localData[0]->realVars[76] /* window.glaUns.glass[1].T4_b variable */) = xloc[6];
  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_42(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_43(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_44(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_45(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_46(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_47(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_48(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_49(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_50(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_51(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_52(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_53(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_54(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_55(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_56(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_57(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_58(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_59(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_60(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_61(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_62(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_63(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_64(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_65(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_66(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_67(data, threadData);
  res[0] = ((data->localData[0]->realVars[58] /* shaSig.y variable */)) * ((data->localData[0]->realVars[34] /* indRad.JIn variable */)) - (data->localData[0]->realVars[53] /* intShaRad.JIn_air variable */);

  res[1] = (0.16) * ((data->localData[0]->realVars[11] /* extCon.JOutSha variable */)) + (data->localData[0]->realVars[67] /* window.glaSha.glass[1].E_a variable */) - (data->localData[0]->realVars[9] /* extCon.JInSha variable */);

  res[2] = (0.16) * ((data->localData[0]->realVars[56] /* intShaRad.JOut_glass variable */)) + (data->localData[0]->realVars[68] /* window.glaSha.glass[1].E_b variable */) - (data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */);

  res[3] = (0.75) * ((data->localData[0]->realVars[54] /* intShaRad.JIn_glass variable */)) + (data->localData[0]->realVars[52] /* intShaRad.E_glass variable */) - (data->localData[0]->realVars[56] /* intShaRad.JOut_glass variable */);

  res[4] = (data->localData[0]->realVars[55] /* intShaRad.JOut_air variable */) + (data->localData[0]->realVars[63] /* window.JOutUns_b variable */) - (data->localData[0]->realVars[34] /* indRad.JIn variable */);

  res[5] = (0.16) * ((data->localData[0]->realVars[12] /* extCon.JOutUns variable */)) + (data->localData[0]->realVars[73] /* window.glaUns.glass[1].E_a variable */) - (data->localData[0]->realVars[10] /* extCon.JInUns variable */);

  res[6] = (-(data->localData[0]->realVars[10] /* extCon.JInUns variable */)) - (data->localData[0]->realVars[63] /* window.JOutUns_b variable */) - (data->localData[0]->realVars[17] /* extCon.conWinUns.Q_flow variable */) - (data->localData[0]->realVars[46] /* intShaCon.conWinUns.Q_flow variable */) + (data->localData[0]->realVars[62] /* window.JInUns_b variable */) + (data->localData[0]->realVars[12] /* extCon.JOutUns variable */) + (data->localData[0]->realVars[1] /* QAbsUns_flow variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData106(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for window.glaUns_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[78].attribute /* window.glaUns_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[78].attribute /* window.glaUns_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[78].attribute /* window.glaUns_a.T */.max;
  /* static ls data for indRad.JIn */
  linearSystemData->nominal[i] = data->modelData->realVarsData[34].attribute /* indRad.JIn */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[34].attribute /* indRad.JIn */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[34].attribute /* indRad.JIn */.max;
  /* static ls data for intShaRad.JIn_glass */
  linearSystemData->nominal[i] = data->modelData->realVarsData[54].attribute /* intShaRad.JIn_glass */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[54].attribute /* intShaRad.JIn_glass */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[54].attribute /* intShaRad.JIn_glass */.max;
  /* static ls data for window.glaSha_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[72].attribute /* window.glaSha_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[72].attribute /* window.glaSha_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[72].attribute /* window.glaSha_a.T */.max;
  /* static ls data for intShaCon.TSha */
  linearSystemData->nominal[i] = data->modelData->realVarsData[38].attribute /* intShaCon.TSha */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[38].attribute /* intShaCon.TSha */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[38].attribute /* intShaCon.TSha */.max;
  /* static ls data for intShaCon.glaSha.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[50].attribute /* intShaCon.glaSha.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[50].attribute /* intShaCon.glaSha.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[50].attribute /* intShaCon.glaSha.T */.max;
  /* static ls data for window.glaUns.glass[1].T4_b */
  linearSystemData->nominal[i] = data->modelData->realVarsData[76].attribute /* window.glaUns.glass[1].T4_b */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[76].attribute /* window.glaUns.glass[1].T4_b */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[76].attribute /* window.glaUns.glass[1].T4_b */.max;
}


/*
equation index: 29
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow = 4.0 * intShaCon.conFra.u * intShaCon.conFra.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  (data->localData[0]->realVars[42] /* intShaCon.conFra.q_flow variable */) = (4.0) * (((data->localData[0]->realVars[43] /* intShaCon.conFra.u variable */)) * ((data->localData[0]->realVars[41] /* intShaCon.conFra.dT variable */)));
#line 1166 OMC_FILE
  TRACE_POP
}
/*
equation index: 30
type: SIMPLE_ASSIGN
window.frame.dT = 0.3333333333333333 * intShaCon.conFra.q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->localData[0]->realVars[66] /* window.frame.dT variable */) = (0.3333333333333333) * ((data->localData[0]->realVars[42] /* intShaCon.conFra.q_flow variable */));
  TRACE_POP
}
/*
equation index: 31
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow = 0.2 * intShaCon.conFra.q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[40] /* intShaCon.conFra.Q_flow variable */) = (0.2) * ((data->localData[0]->realVars[42] /* intShaCon.conFra.q_flow variable */));
#line 1192 OMC_FILE
  TRACE_POP
}
/*
equation index: 32
type: SIMPLE_ASSIGN
window.fra_b.T = intShaCon.conFra.dT - -293.15
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[65] /* window.fra_b.T variable */) = (data->localData[0]->realVars[41] /* intShaCon.conFra.dT variable */) - (-293.15);
#line 1206 OMC_FILE
  TRACE_POP
}
/*
equation index: 33
type: SIMPLE_ASSIGN
window.fra_a.T = window.fra_b.T + window.frame.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[64] /* window.fra_a.T variable */) = (data->localData[0]->realVars[65] /* window.fra_b.T variable */) + (data->localData[0]->realVars[66] /* window.frame.dT variable */);
#line 1220 OMC_FILE
  TRACE_POP
}
/*
equation index: 34
type: SIMPLE_ASSIGN
extCon.conFra.dT = window.fra_a.T - TOut
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[15] /* extCon.conFra.dT variable */) = (data->localData[0]->realVars[64] /* window.fra_a.T variable */) - (data->localData[0]->realVars[5] /* TOut variable */);
#line 1234 OMC_FILE
  TRACE_POP
}

void residualFunc41(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,41};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[41] /* intShaCon.conFra.dT variable */) = xloc[0];
  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_29(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_30(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_31(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_32(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_33(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_34(data, threadData);
  res[0] = ((data->localData[0]->realVars[13] /* extCon.conCoeFra.GCon variable */)) * ((data->localData[0]->realVars[15] /* extCon.conFra.dT variable */)) + (data->localData[0]->realVars[40] /* intShaCon.conFra.Q_flow variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData41(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for intShaCon.conFra.dT */
  linearSystemData->nominal[i] = data->modelData->realVarsData[41].attribute /* intShaCon.conFra.dT */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[41].attribute /* intShaCon.conFra.dT */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[41].attribute /* intShaCon.conFra.dT */.max;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize linear systems */
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA* linearSystemData)
{
  /* linear systems */
  assertStreamPrint(NULL, nLinearSystems > 3, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[3].equationIndex = 207;
  linearSystemData[3].size = 6;
  linearSystemData[3].nnz = 0;
  linearSystemData[3].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[3].residualFunc = residualFunc207;
  linearSystemData[3].strictTearingFunctionCall = NULL;
  linearSystemData[3].analyticalJacobianColumn = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac111_column;
  linearSystemData[3].initialAnalyticalJacobian = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianLSJac111;
  linearSystemData[3].jacobianIndex = 3 /*jacInx*/;
  linearSystemData[3].setA = NULL;  //setLinearMatrixA207;
  linearSystemData[3].setb = NULL;  //setLinearVectorb207;
  linearSystemData[3].initializeStaticLSData = initializeStaticLSData207;
  
  assertStreamPrint(NULL, nLinearSystems > 2, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[2].equationIndex = 143;
  linearSystemData[2].size = 1;
  linearSystemData[2].nnz = 0;
  linearSystemData[2].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[2].residualFunc = residualFunc143;
  linearSystemData[2].strictTearingFunctionCall = NULL;
  linearSystemData[2].analyticalJacobianColumn = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac110_column;
  linearSystemData[2].initialAnalyticalJacobian = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianLSJac110;
  linearSystemData[2].jacobianIndex = 2 /*jacInx*/;
  linearSystemData[2].setA = NULL;  //setLinearMatrixA143;
  linearSystemData[2].setb = NULL;  //setLinearVectorb143;
  linearSystemData[2].initializeStaticLSData = initializeStaticLSData143;
  
  assertStreamPrint(NULL, nLinearSystems > 1, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[1].equationIndex = 106;
  linearSystemData[1].size = 7;
  linearSystemData[1].nnz = 0;
  linearSystemData[1].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[1].residualFunc = residualFunc106;
  linearSystemData[1].strictTearingFunctionCall = NULL;
  linearSystemData[1].analyticalJacobianColumn = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac109_column;
  linearSystemData[1].initialAnalyticalJacobian = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianLSJac109;
  linearSystemData[1].jacobianIndex = 1 /*jacInx*/;
  linearSystemData[1].setA = NULL;  //setLinearMatrixA106;
  linearSystemData[1].setb = NULL;  //setLinearVectorb106;
  linearSystemData[1].initializeStaticLSData = initializeStaticLSData106;
  
  assertStreamPrint(NULL, nLinearSystems > 0, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[0].equationIndex = 41;
  linearSystemData[0].size = 1;
  linearSystemData[0].nnz = 0;
  linearSystemData[0].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[0].residualFunc = residualFunc41;
  linearSystemData[0].strictTearingFunctionCall = NULL;
  linearSystemData[0].analyticalJacobianColumn = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac108_column;
  linearSystemData[0].initialAnalyticalJacobian = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianLSJac108;
  linearSystemData[0].jacobianIndex = 0 /*jacInx*/;
  linearSystemData[0].setA = NULL;  //setLinearMatrixA41;
  linearSystemData[0].setb = NULL;  //setLinearVectorb41;
  linearSystemData[0].initializeStaticLSData = initializeStaticLSData41;
}

#if defined(__cplusplus)
}
#endif

