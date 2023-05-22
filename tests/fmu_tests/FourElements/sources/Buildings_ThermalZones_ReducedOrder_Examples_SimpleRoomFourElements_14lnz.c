#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_14lnz.c"
#endif
/* Linearization */
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_linear_model_frame()
{
  return "model linearized_model \"Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements\" \n  parameter Integer n = 6 \"number of states\";\n  parameter Integer m = 0 \"number of inputs\";\n  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m];\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'x_thermalZoneFourElements.extWallRC.thermCapExt[1].T' = x[1];\n""  Real 'x_thermalZoneFourElements.floorRC.thermCapExt[1].T' = x[2];\n""  Real 'x_thermalZoneFourElements.intWallRC.thermCapInt[1].T' = x[3];\n""  Real 'x_thermalZoneFourElements.roofRC.thermCapExt[1].T' = x[4];\n""  Real 'x_thermalZoneFourElements.volAir.dynBal.U' = x[5];\n""  Real 'x_thermalZoneFourElements.volAir.dynBal.m' = x[6];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linearized_model;\n";
}
const char *Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_linear_model_datarecovery_frame()
{
  return "model linearized_model \"Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements\" \n parameter Integer n = 6 \"number of states\";\n  parameter Integer m = 0 \"number of inputs\";\n  parameter Integer p = 0 \"number of outputs\";\n  parameter Integer nz = 346 \"data recovery variables\";\n"
  "  parameter Real x0[6] = %s;\n"
  "  parameter Real u0[0] = %s;\n"
  "  parameter Real z0[346] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "  parameter Real Cz[nz, n] =\n\t[%s];\n\n"
  "  parameter Real Dz[nz, m] = zeros(nz, m);%s\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m];\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'x_thermalZoneFourElements.extWallRC.thermCapExt[1].T' = x[1];\n""  Real 'x_thermalZoneFourElements.floorRC.thermCapExt[1].T' = x[2];\n""  Real 'x_thermalZoneFourElements.intWallRC.thermCapInt[1].T' = x[3];\n""  Real 'x_thermalZoneFourElements.roofRC.thermCapExt[1].T' = x[4];\n""  Real 'x_thermalZoneFourElements.volAir.dynBal.U' = x[5];\n""  Real 'x_thermalZoneFourElements.volAir.dynBal.m' = x[6];\n"
  "  Real 'z_$cse1' = z[1];\n""  Real 'z_$cse10' = z[2];\n""  Real 'z_$cse12' = z[3];\n""  Real 'z_$cse13' = z[4];\n""  Real 'z_$cse15' = z[5];\n""  Real 'z_$cse16' = z[6];\n""  Real 'z_$cse17' = z[7];\n""  Real 'z_$cse18' = z[8];\n""  Real 'z_$cse19' = z[9];\n""  Real 'z_$cse2' = z[10];\n""  Real 'z_$cse3' = z[11];\n""  Real 'z_$cse4' = z[12];\n""  Real 'z_$cse5' = z[13];\n""  Real 'z_$cse6' = z[14];\n""  Real 'z_$cse7' = z[15];\n""  Real 'z_$cse9' = z[16];\n""  Real 'z_HDifTil[1].H' = z[17];\n""  Real 'z_HDifTil[2].H' = z[18];\n""  Real 'z_HDifTil[1].HDifTil.a' = z[19];\n""  Real 'z_HDifTil[2].HDifTil.a' = z[20];\n""  Real 'z_HDifTil[1].HDifTil.b' = z[21];\n""  Real 'z_HDifTil[2].HDifTil.b' = z[22];\n""  Real 'z_HDifTil[1].HGroDifTil' = z[23];\n""  Real 'z_HDifTil[2].HGroDifTil' = z[24];\n""  Real 'z_HDifTil[1].HSkyDifTil' = z[25];\n""  Real 'z_HDifTil[2].HSkyDifTil' = z[26];\n""  Real 'z_HDifTil[1].briCoe.F1' = z[27];\n""  Real 'z_HDifTil[2].briCoe.F1' = z[28];\n""  Real 'z_HDifTil[1].briCoe.F11' = z[29];\n""  Real 'z_HDifTil[2].briCoe.F11' = z[30];\n""  Real 'z_HDifTil[1].briCoe.F12' = z[31];\n""  Real 'z_HDifTil[2].briCoe.F12' = z[32];\n""  Real 'z_HDifTil[1].briCoe.F13' = z[33];\n""  Real 'z_HDifTil[2].briCoe.F13' = z[34];\n""  Real 'z_HDifTil[1].briCoe.F2' = z[35];\n""  Real 'z_HDifTil[2].briCoe.F2' = z[36];\n""  Real 'z_HDifTil[1].briCoe.F21' = z[37];\n""  Real 'z_HDifTil[2].briCoe.F21' = z[38];\n""  Real 'z_HDifTil[1].briCoe.F22' = z[39];\n""  Real 'z_HDifTil[2].briCoe.F22' = z[40];\n""  Real 'z_HDifTil[1].briCoe.F23' = z[41];\n""  Real 'z_HDifTil[2].briCoe.F23' = z[42];\n""  Real 'z_HDifTil[1].briCoe.a1' = z[43];\n""  Real 'z_HDifTil[2].briCoe.a1' = z[44];\n""  Real 'z_HDifTil[1].briCoe.a2' = z[45];\n""  Real 'z_HDifTil[2].briCoe.a2' = z[46];\n""  Real 'z_HDifTil[1].briCoe.a3' = z[47];\n""  Real 'z_HDifTil[2].briCoe.a3' = z[48];\n""  Real 'z_HDifTil[1].briCoe.a4' = z[49];\n""  Real 'z_HDifTil[2].briCoe.a4' = z[50];\n""  Real 'z_HDifTil[1].briCoe.a5' = z[51];\n""  Real 'z_HDifTil[2].briCoe.a5' = z[52];\n""  Real 'z_HDifTil[1].briCoe.a6' = z[53];\n""  Real 'z_HDifTil[2].briCoe.a6' = z[54];\n""  Real 'z_HDifTil[1].briCoe.a7' = z[55];\n""  Real 'z_HDifTil[2].briCoe.a7' = z[56];\n""  Real 'z_HDifTil[1].briCoe.a8' = z[57];\n""  Real 'z_HDifTil[2].briCoe.a8' = z[58];\n""  Real 'z_HDifTil[1].briCoe.b2' = z[59];\n""  Real 'z_HDifTil[2].briCoe.b2' = z[60];\n""  Real 'z_HDifTil[1].briCoe.b3' = z[61];\n""  Real 'z_HDifTil[2].briCoe.b3' = z[62];\n""  Real 'z_HDifTil[1].briCoe.b4' = z[63];\n""  Real 'z_HDifTil[2].briCoe.b4' = z[64];\n""  Real 'z_HDifTil[1].briCoe.b5' = z[65];\n""  Real 'z_HDifTil[2].briCoe.b5' = z[66];\n""  Real 'z_HDifTil[1].briCoe.b6' = z[67];\n""  Real 'z_HDifTil[2].briCoe.b6' = z[68];\n""  Real 'z_HDifTil[1].briCoe.b7' = z[69];\n""  Real 'z_HDifTil[2].briCoe.b7' = z[70];\n""  Real 'z_HDifTil[1].briCoe.d' = z[71];\n""  Real 'z_HDifTil[2].briCoe.d' = z[72];\n""  Real 'z_HDifTil[1].incAng.decAng.decAng' = z[73];\n""  Real 'z_HDifTil[2].incAng.decAng.decAng' = z[74];\n""  Real 'z_HDifTil[1].incAng.incAng.dec_c' = z[75];\n""  Real 'z_HDifTil[2].incAng.incAng.dec_c' = z[76];\n""  Real 'z_HDifTil[1].incAng.incAng.dec_s' = z[77];\n""  Real 'z_HDifTil[2].incAng.incAng.dec_s' = z[78];\n""  Real 'z_HDifTil[1].incAng.incAng.lat_c' = z[79];\n""  Real 'z_HDifTil[2].incAng.incAng.lat_c' = z[80];\n""  Real 'z_HDifTil[1].incAng.incAng.lat_s' = z[81];\n""  Real 'z_HDifTil[2].incAng.incAng.lat_s' = z[82];\n""  Real 'z_HDifTil[1].incAng.incAng.sol_c' = z[83];\n""  Real 'z_HDifTil[2].incAng.incAng.sol_c' = z[84];\n""  Real 'z_HDifTil[1].incAng.incAng.sol_s' = z[85];\n""  Real 'z_HDifTil[2].incAng.incAng.sol_s' = z[86];\n""  Real 'z_HDifTil[1].incAng.solHouAng.solHouAng' = z[87];\n""  Real 'z_HDifTil[2].incAng.solHouAng.solHouAng' = z[88];\n""  Real 'z_HDifTil[1].incAng.y' = z[89];\n""  Real 'z_HDifTil[2].incAng.y' = z[90];\n""  Real 'z_HDifTil[1].relAirMas.relAirMas' = z[91];\n""  Real 'z_HDifTil[2].relAirMas.relAirMas' = z[92];\n""  Real 'z_HDifTil[1].relAirMas.zenDeg' = z[93];\n""  Real 'z_HDifTil[2].relAirMas.zenDeg' = z[94];\n""  Real 'z_HDifTil[1].relAirMas.zenLim' = z[95];\n""  Real 'z_HDifTil[2].relAirMas.zenLim' = z[96];\n""  Real 'z_HDifTil[1].skyBri.extRadCor' = z[97];\n""  Real 'z_HDifTil[2].skyBri.extRadCor' = z[98];\n""  Real 'z_HDifTil[1].skyBri.skyBri' = z[99];\n""  Real 'z_HDifTil[2].skyBri.skyBri' = z[100];\n""  Real 'z_HDifTil[1].skyCle.HDifHorBou' = z[101];\n""  Real 'z_HDifTil[2].skyCle.HDifHorBou' = z[102];\n""  Real 'z_HDifTil[1].skyCle.skyCle' = z[103];\n""  Real 'z_HDifTil[2].skyCle.skyCle' = z[104];\n""  Real 'z_HDifTil[1].skyCle.tmp1' = z[105];\n""  Real 'z_HDifTil[2].skyCle.tmp1' = z[106];\n""  Real 'z_HDifTil[1].weaBus.HDifHor' = z[107];\n""  Real 'z_HDifTil[1].weaBus.HDirNor' = z[108];\n""  Real 'z_HDifTil[1].weaBus.HHorIR' = z[109];\n""  Real 'z_HDifTil[1].weaBus.ceiHei' = z[110];\n""  Real 'z_HDifTil[1].weaBus.cloTim' = z[111];\n""  Real 'z_HDifTil[1].weaBus.nOpa' = z[112];\n""  Real 'z_HDifTil[1].weaBus.nTot' = z[113];\n""  Real 'z_HDifTil[1].weaBus.relHum' = z[114];\n""  Real 'z_HDifTil[1].weaBus.solAlt' = z[115];\n""  Real 'z_HDifTil[1].weaBus.solDec' = z[116];\n""  Real 'z_HDifTil[1].weaBus.solHouAng' = z[117];\n""  Real 'z_HDifTil[1].weaBus.solTim' = z[118];\n""  Real 'z_HDifTil[1].weaBus.solZen' = z[119];\n""  Real 'z_HDifTil[1].weaBus.winDir' = z[120];\n""  Real 'z_HDifTil[1].weaBus.winSpe' = z[121];\n""  Real 'z_HDirTil[1].H' = z[122];\n""  Real 'z_HDirTil[2].H' = z[123];\n""  Real 'z_HDirTil[1].inc' = z[124];\n""  Real 'z_HDirTil[2].inc' = z[125];\n""  Real 'z_HDirTil[1].incAng.decAng.decAng' = z[126];\n""  Real 'z_HDirTil[2].incAng.decAng.decAng' = z[127];\n""  Real 'z_HDirTil[1].incAng.incAng.dec_c' = z[128];\n""  Real 'z_HDirTil[2].incAng.incAng.dec_c' = z[129];\n""  Real 'z_HDirTil[1].incAng.incAng.dec_s' = z[130];\n""  Real 'z_HDirTil[2].incAng.incAng.dec_s' = z[131];\n""  Real 'z_HDirTil[1].incAng.incAng.lat_c' = z[132];\n""  Real 'z_HDirTil[2].incAng.incAng.lat_c' = z[133];\n""  Real 'z_HDirTil[1].incAng.incAng.lat_s' = z[134];\n""  Real 'z_HDirTil[2].incAng.incAng.lat_s' = z[135];\n""  Real 'z_HDirTil[1].incAng.incAng.sol_c' = z[136];\n""  Real 'z_HDirTil[2].incAng.incAng.sol_c' = z[137];\n""  Real 'z_HDirTil[1].incAng.incAng.sol_s' = z[138];\n""  Real 'z_HDirTil[2].incAng.incAng.sol_s' = z[139];\n""  Real 'z_HDirTil[1].incAng.solHouAng.solHouAng' = z[140];\n""  Real 'z_HDirTil[2].incAng.solHouAng.solHouAng' = z[141];\n""  Real 'z_HDirTil[2].weaBus.HGloHor' = z[142];\n""  Real 'z_TSoil.y' = z[143];\n""  Real 'z_const[1].y' = z[144];\n""  Real 'z_const[2].y' = z[145];\n""  Real 'z_const1.y' = z[146];\n""  Real 'z_corGDouPan.CorG_dir[1]' = z[147];\n""  Real 'z_corGDouPan.CorG_dir[2]' = z[148];\n""  Real 'z_corGDouPan.Q21_dir[1]' = z[149];\n""  Real 'z_corGDouPan.Q21_dir[2]' = z[150];\n""  Real 'z_corGDouPan.Q22_dir[1]' = z[151];\n""  Real 'z_corGDouPan.Q22_dir[2]' = z[152];\n""  Real 'z_corGDouPan.Qsek2_dir[1]' = z[153];\n""  Real 'z_corGDouPan.Qsek2_dir[2]' = z[154];\n""  Real 'z_corGDouPan.Ta1_dir[1]' = z[155];\n""  Real 'z_corGDouPan.Ta1_dir[2]' = z[156];\n""  Real 'z_corGDouPan.Ta2_dir[1]' = z[157];\n""  Real 'z_corGDouPan.Ta2_dir[2]' = z[158];\n""  Real 'z_corGDouPan.Ta_dir[1]' = z[159];\n""  Real 'z_corGDouPan.Ta_dir[2]' = z[160];\n""  Real 'z_corGDouPan.Tai_dir[1]' = z[161];\n""  Real 'z_corGDouPan.Tai_dir[2]' = z[162];\n""  Real 'z_corGDouPan.XN2_dir[1]' = z[163];\n""  Real 'z_corGDouPan.XN2_dir[2]' = z[164];\n""  Real 'z_corGDouPan.a1_dir[1]' = z[165];\n""  Real 'z_corGDouPan.a1_dir[2]' = z[166];\n""  Real 'z_corGDouPan.rho_11_dir[1]' = z[167];\n""  Real 'z_corGDouPan.rho_11_dir[2]' = z[168];\n""  Real 'z_corGDouPan.rho_1_dir[1]' = z[169];\n""  Real 'z_corGDouPan.rho_1_dir[2]' = z[170];\n""  Real 'z_corGDouPan.rho_T1_dir[1]' = z[171];\n""  Real 'z_corGDouPan.rho_T1_dir[2]' = z[172];\n""  Real 'z_corGDouPan.solarRadWinTrans[1]' = z[173];\n""  Real 'z_corGDouPan.solarRadWinTrans[2]' = z[174];\n""  Real 'z_eqAirTemp.TEqWall[1]' = z[175];\n""  Real 'z_eqAirTemp.TEqWall[2]' = z[176];\n""  Real 'z_eqAirTemp.TEqWin[1]' = z[177];\n""  Real 'z_eqAirTemp.TEqWin[2]' = z[178];\n""  Real 'z_eqAirTemp.delTEqLW' = z[179];\n""  Real 'z_eqAirTemp.delTEqSW[1]' = z[180];\n""  Real 'z_eqAirTemp.delTEqSW[2]' = z[181];\n""  Real 'z_eqAirTempVDI.TEqWall[1]' = z[182];\n""  Real 'z_eqAirTempVDI.TEqWin[1]' = z[183];\n""  Real 'z_eqAirTempVDI.delTEqLWWin' = z[184];\n""  Real 'z_eqAirTempVDI.delTEqSW[1]' = z[185];\n""  Real 'z_hConRoof.y' = z[186];\n""  Real 'z_hConWall.y' = z[187];\n""  Real 'z_hConWin.y' = z[188];\n""  Real 'z_intGai.timeScaled' = z[189];\n""  Real 'z_intGai.y[1]' = z[190];\n""  Real 'z_intGai.y[2]' = z[191];\n""  Real 'z_intGai.y[3]' = z[192];\n""  Real 'z_preTem.T' = z[193];\n""  Real 'z_preTem1.T' = z[194];\n""  Real 'z_solRad[1].y' = z[195];\n""  Real 'z_solRad[2].y' = z[196];\n""  Real 'z_theConRoof.Q_flow' = z[197];\n""  Real 'z_theConRoof.dT' = z[198];\n""  Real 'z_theConRoof.solid.T' = z[199];\n""  Real 'z_theConWall.Q_flow' = z[200];\n""  Real 'z_theConWall.dT' = z[201];\n""  Real 'z_theConWin.Q_flow' = z[202];\n""  Real 'z_theConWin.dT' = z[203];\n""  Real 'z_theConWin.solid.T' = z[204];\n""  Real 'z_thermalZoneFourElements.TAir' = z[205];\n""  Real 'z_thermalZoneFourElements.TRad' = z[206];\n""  Real 'z_thermalZoneFourElements.convExtWall.Q_flow' = z[207];\n""  Real 'z_thermalZoneFourElements.convExtWall.dT' = z[208];\n""  Real 'z_thermalZoneFourElements.convFloor.Q_flow' = z[209];\n""  Real 'z_thermalZoneFourElements.convFloor.dT' = z[210];\n""  Real 'z_thermalZoneFourElements.convHeatSol.Q_flow' = z[211];\n""  Real 'z_thermalZoneFourElements.convIntWall.Q_flow' = z[212];\n""  Real 'z_thermalZoneFourElements.convIntWall.dT' = z[213];\n""  Real 'z_thermalZoneFourElements.convRoof.Q_flow' = z[214];\n""  Real 'z_thermalZoneFourElements.convRoof.dT' = z[215];\n""  Real 'z_thermalZoneFourElements.convWin.Q_flow' = z[216];\n""  Real 'z_thermalZoneFourElements.convWin.dT' = z[217];\n""  Real 'z_thermalZoneFourElements.eConvSol[1].y' = z[218];\n""  Real 'z_thermalZoneFourElements.eConvSol[2].y' = z[219];\n""  Real 'z_thermalZoneFourElements.extWall.T' = z[220];\n""  Real 'z_thermalZoneFourElements.extWallRC.port_a.Q_flow' = z[221];\n""  Real 'z_thermalZoneFourElements.extWallRC.thermCapExt[1].der_T' = z[222];\n""  Real 'z_thermalZoneFourElements.extWallRC.thermCapExt[1].port.Q_flow' = z[223];\n""  Real 'z_thermalZoneFourElements.extWallRC.thermResExt[1].dT' = z[224];\n""  Real 'z_thermalZoneFourElements.extWallRC.thermResExtRem.dT' = z[225];\n""  Real 'z_thermalZoneFourElements.floor.Q_flow' = z[226];\n""  Real 'z_thermalZoneFourElements.floorRC.port_a.Q_flow' = z[227];\n""  Real 'z_thermalZoneFourElements.floorRC.thermCapExt[1].der_T' = z[228];\n""  Real 'z_thermalZoneFourElements.floorRC.thermCapExt[1].port.Q_flow' = z[229];\n""  Real 'z_thermalZoneFourElements.floorRC.thermResExt[1].dT' = z[230];\n""  Real 'z_thermalZoneFourElements.floorRC.thermResExtRem.dT' = z[231];\n""  Real 'z_thermalZoneFourElements.hConExtWall_const.y' = z[232];\n""  Real 'z_thermalZoneFourElements.hConFloor_const.y' = z[233];\n""  Real 'z_thermalZoneFourElements.hConIntWall.y' = z[234];\n""  Real 'z_thermalZoneFourElements.hConRoof_const.y' = z[235];\n""  Real 'z_thermalZoneFourElements.hConWin_const.y' = z[236];\n""  Real 'z_thermalZoneFourElements.intGainsConv.Q_flow' = z[237];\n""  Real 'z_thermalZoneFourElements.intWallRC.thermCapInt[1].der_T' = z[238];\n""  Real 'z_thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow' = z[239];\n""  Real 'z_thermalZoneFourElements.intWallRC.thermResInt[1].dT' = z[240];\n""  Real 'z_thermalZoneFourElements.radHeatSol[1].Q_flow' = z[241];\n""  Real 'z_thermalZoneFourElements.radHeatSol[2].Q_flow' = z[242];\n""  Real 'z_thermalZoneFourElements.radHeatSol[1].port.T' = z[243];\n""  Real 'z_thermalZoneFourElements.radHeatSol[2].port.T' = z[244];\n""  Real 'z_thermalZoneFourElements.resExtWallFloor.Q_flow' = z[245];\n""  Real 'z_thermalZoneFourElements.resExtWallFloor.dT' = z[246];\n""  Real 'z_thermalZoneFourElements.resExtWallIntWall.Q_flow' = z[247];\n""  Real 'z_thermalZoneFourElements.resExtWallIntWall.dT' = z[248];\n""  Real 'z_thermalZoneFourElements.resExtWallRoof.Q_flow' = z[249];\n""  Real 'z_thermalZoneFourElements.resExtWallRoof.dT' = z[250];\n""  Real 'z_thermalZoneFourElements.resExtWallWin.Q_flow' = z[251];\n""  Real 'z_thermalZoneFourElements.resExtWallWin.dT' = z[252];\n""  Real 'z_thermalZoneFourElements.resFloorWin.Q_flow' = z[253];\n""  Real 'z_thermalZoneFourElements.resFloorWin.dT' = z[254];\n""  Real 'z_thermalZoneFourElements.resIntRoof.Q_flow' = z[255];\n""  Real 'z_thermalZoneFourElements.resIntRoof.dT' = z[256];\n""  Real 'z_thermalZoneFourElements.resIntWallFloor.Q_flow' = z[257];\n""  Real 'z_thermalZoneFourElements.resIntWallFloor.dT' = z[258];\n""  Real 'z_thermalZoneFourElements.resIntWallWin.Q_flow' = z[259];\n""  Real 'z_thermalZoneFourElements.resIntWallWin.dT' = z[260];\n""  Real 'z_thermalZoneFourElements.resRoofFloor.Q_flow' = z[261];\n""  Real 'z_thermalZoneFourElements.resRoofFloor.dT' = z[262];\n""  Real 'z_thermalZoneFourElements.resRoofWin.Q_flow' = z[263];\n""  Real 'z_thermalZoneFourElements.resRoofWin.dT' = z[264];\n""  Real 'z_thermalZoneFourElements.resWin.dT' = z[265];\n""  Real 'z_thermalZoneFourElements.roofRC.port_a.Q_flow' = z[266];\n""  Real 'z_thermalZoneFourElements.roofRC.thermCapExt[1].der_T' = z[267];\n""  Real 'z_thermalZoneFourElements.roofRC.thermCapExt[1].port.Q_flow' = z[268];\n""  Real 'z_thermalZoneFourElements.roofRC.thermResExt[1].dT' = z[269];\n""  Real 'z_thermalZoneFourElements.roofRC.thermResExtRem.dT' = z[270];\n""  Real 'z_thermalZoneFourElements.senTAir.port.Q_flow' = z[271];\n""  Real 'z_thermalZoneFourElements.senTRad.port.Q_flow' = z[272];\n""  Real 'z_thermalZoneFourElements.thermSplitterIntGains.portOut[2].Q_flow' = z[273];\n""  Real 'z_thermalZoneFourElements.thermSplitterIntGains.portOut[3].Q_flow' = z[274];\n""  Real 'z_thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow' = z[275];\n""  Real 'z_thermalZoneFourElements.thermSplitterIntGains.portOut[3].T' = z[276];\n""  Real 'z_thermalZoneFourElements.thermSplitterIntGains.portOut[4].T' = z[277];\n""  Real 'z_thermalZoneFourElements.thermSplitterIntGains.portOut[5].T' = z[278];\n""  Real 'z_thermalZoneFourElements.thermSplitterSolRad.portOut[1].Q_flow' = z[279];\n""  Real 'z_thermalZoneFourElements.thermSplitterSolRad.portOut[2].Q_flow' = z[280];\n""  Real 'z_thermalZoneFourElements.thermSplitterSolRad.portOut[3].Q_flow' = z[281];\n""  Real 'z_thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow' = z[282];\n""  Real 'z_thermalZoneFourElements.thermSplitterSolRad.portOut[1].T' = z[283];\n""  Real 'z_thermalZoneFourElements.thermSplitterSolRad.portOut[2].T' = z[284];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.Hb_flow' = z[285];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.mWat_flow_internal' = z[286];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.mb_flow' = z[287];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.medium.MM' = z[288];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.medium.R_s' = z[289];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.medium.T' = z[290];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.medium.T_degC' = z[291];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.medium.X[1]' = z[292];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.medium.d' = z[293];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.medium.p' = z[294];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.medium.p_bar' = z[295];\n""  Real 'z_thermalZoneFourElements.volAir.dynBal.medium.u' = z[296];\n""  Real 'z_thermalZoneFourElements.volAir.hOut_internal' = z[297];\n""  Real 'z_thermalZoneFourElements.volAir.heatPort.Q_flow' = z[298];\n""  Real 'z_thermalZoneFourElements.volAir.p' = z[299];\n""  Real 'z_weaBus.TBlaSky' = z[300];\n""  Real 'z_weaBus.TDewPoi' = z[301];\n""  Real 'z_weaBus.TDryBul' = z[302];\n""  Real 'z_weaDat.TBlaSkyCom.TDewPoiK' = z[303];\n""  Real 'z_weaDat.TBlaSkyCom.epsSky' = z[304];\n""  Real 'z_weaDat.TBlaSkyCom.nOpa10' = z[305];\n""  Real 'z_weaDat.add30Min.y' = z[306];\n""  Real 'z_weaDat.con30Min.y' = z[307];\n""  Real 'z_weaDat.conTim.calTim' = z[308];\n""  Real 'z_weaDat.conTimMin.calTim' = z[309];\n""  Real 'z_weaDat.conWinDir.y' = z[310];\n""  Real 'z_weaDat.datRea.y[1]' = z[311];\n""  Real 'z_weaDat.datRea.y[2]' = z[312];\n""  Real 'z_weaDat.datRea.y[3]' = z[313];\n""  Real 'z_weaDat.datRea.y[4]' = z[314];\n""  Real 'z_weaDat.datRea.y[5]' = z[315];\n""  Real 'z_weaDat.datRea.y[6]' = z[316];\n""  Real 'z_weaDat.datRea.y[7]' = z[317];\n""  Real 'z_weaDat.datRea.y[8]' = z[318];\n""  Real 'z_weaDat.datRea.y[9]' = z[319];\n""  Real 'z_weaDat.datRea.y[10]' = z[320];\n""  Real 'z_weaDat.datRea.y[11]' = z[321];\n""  Real 'z_weaDat.datRea.y[12]' = z[322];\n""  Real 'z_weaDat.datRea.y[13]' = z[323];\n""  Real 'z_weaDat.datRea.y[14]' = z[324];\n""  Real 'z_weaDat.datRea.y[15]' = z[325];\n""  Real 'z_weaDat.datRea.y[16]' = z[326];\n""  Real 'z_weaDat.datRea.y[17]' = z[327];\n""  Real 'z_weaDat.datRea.y[18]' = z[328];\n""  Real 'z_weaDat.datRea.y[19]' = z[329];\n""  Real 'z_weaDat.datRea.y[20]' = z[330];\n""  Real 'z_weaDat.datRea.y[21]' = z[331];\n""  Real 'z_weaDat.datRea.y[22]' = z[332];\n""  Real 'z_weaDat.datRea.y[23]' = z[333];\n""  Real 'z_weaDat.datRea.y[24]' = z[334];\n""  Real 'z_weaDat.datRea.y[25]' = z[335];\n""  Real 'z_weaDat.datRea.y[26]' = z[336];\n""  Real 'z_weaDat.datRea30Min.y[1]' = z[337];\n""  Real 'z_weaDat.datRea30Min.y[2]' = z[338];\n""  Real 'z_weaDat.datRea30Min.y[3]' = z[339];\n""  Real 'z_weaDat.eqnTim.Bt' = z[340];\n""  Real 'z_weaDat.eqnTim.eqnTim' = z[341];\n""  Real 'z_weaDat.locTim.locTim' = z[342];\n""  Real 'z_weaDat.opaSkyCovSel.y' = z[343];\n""  Real 'z_weaDat.pAtmSel.y' = z[344];\n""  Real 'z_weaDat.relHumSel.uFil' = z[345];\n""  Real 'z_weaDat.totSkyCovSel.y' = z[346];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

