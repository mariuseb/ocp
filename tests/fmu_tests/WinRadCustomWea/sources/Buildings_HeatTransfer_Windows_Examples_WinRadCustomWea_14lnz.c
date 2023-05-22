#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustomWea/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_14lnz.c"
#endif
/* Linearization */
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_linear_model_frame()
{
  return "model linearized_model \"Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea\" \n  parameter Integer n = 0 \"number of states\";\n  parameter Integer m = 2 \"number of inputs\";\n  parameter Integer p = 4 \"number of outputs\";\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'u_uSha' = u[1];\n""  Real 'u_uSta' = u[2];\n"
  "  Real 'y_QAbsExtSha_flow' = y[1];\n""  Real 'y_QAbsGlaSha_flow' = y[2];\n""  Real 'y_QAbsGlaUns_flow' = y[3];\n""  Real 'y_QAbsIntSha_flow' = y[4];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linearized_model;\n";
}
const char *Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_linear_model_datarecovery_frame()
{
  return "model linearized_model \"Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea\" \n parameter Integer n = 0 \"number of states\";\n  parameter Integer m = 2 \"number of inputs\";\n  parameter Integer p = 4 \"number of outputs\";\n  parameter Integer nz = 139 \"data recovery variables\";\n"
  "  parameter Real x0[0] = %s;\n"
  "  parameter Real u0[2] = %s;\n"
  "  parameter Real z0[139] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "  parameter Real Cz[nz, n] = zeros(nz, n);%s\n\n"
  "  parameter Real Dz[nz, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'u_uSha' = u[1];\n""  Real 'u_uSta' = u[2];\n"
  "  Real 'y_QAbsExtSha_flow' = y[1];\n""  Real 'y_QAbsGlaSha_flow' = y[2];\n""  Real 'y_QAbsGlaUns_flow' = y[3];\n""  Real 'y_QAbsIntSha_flow' = y[4];\n"
  "  Real 'z_$cse10' = z[1];\n""  Real 'z_$cse11' = z[2];\n""  Real 'z_$cse12' = z[3];\n""  Real 'z_$cse13' = z[4];\n""  Real 'z_$cse14' = z[5];\n""  Real 'z_$cse15' = z[6];\n""  Real 'z_$cse16' = z[7];\n""  Real 'z_$cse17' = z[8];\n""  Real 'z_$cse18' = z[9];\n""  Real 'z_$cse19' = z[10];\n""  Real 'z_$cse2' = z[11];\n""  Real 'z_$cse20' = z[12];\n""  Real 'z_$cse3' = z[13];\n""  Real 'z_$cse4' = z[14];\n""  Real 'z_$cse6' = z[15];\n""  Real 'z_$cse7' = z[16];\n""  Real 'z_$cse9' = z[17];\n""  Real 'z_HDifTilIso.H' = z[18];\n""  Real 'z_HDifTilIso.HDifTilIso.til_c' = z[19];\n""  Real 'z_HDifTilIso.add.u1' = z[20];\n""  Real 'z_HDifTilIso.add.u2' = z[21];\n""  Real 'z_HDirTil.H' = z[22];\n""  Real 'z_HDirTil.inc' = z[23];\n""  Real 'z_HDirTil.incAng.decAng.decAng' = z[24];\n""  Real 'z_HDirTil.incAng.incAng.dec_c' = z[25];\n""  Real 'z_HDirTil.incAng.incAng.dec_s' = z[26];\n""  Real 'z_HDirTil.incAng.incAng.lat_c' = z[27];\n""  Real 'z_HDirTil.incAng.incAng.lat_s' = z[28];\n""  Real 'z_HDirTil.incAng.incAng.sol_c' = z[29];\n""  Real 'z_HDirTil.incAng.incAng.sol_s' = z[30];\n""  Real 'z_HDirTil.incAng.solHouAng.solHouAng' = z[31];\n""  Real 'z_HRoo.y' = z[32];\n""  Real 'z_QAbsExtSha_flow' = z[33];\n""  Real 'z_QAbsGlaSha_flow' = z[34];\n""  Real 'z_QAbsGlaUns_flow' = z[35];\n""  Real 'z_QAbsIntSha_flow' = z[36];\n""  Real 'z_uSha' = z[37];\n""  Real 'z_uSta' = z[38];\n""  Real 'z_weaBus.HDifHor' = z[39];\n""  Real 'z_weaBus.HDirNor' = z[40];\n""  Real 'z_weaBus.HGloHor' = z[41];\n""  Real 'z_weaBus.HHorIR' = z[42];\n""  Real 'z_weaBus.TBlaSky' = z[43];\n""  Real 'z_weaBus.TDewPoi' = z[44];\n""  Real 'z_weaBus.TDryBul' = z[45];\n""  Real 'z_weaBus.TWetBul' = z[46];\n""  Real 'z_weaBus.ceiHei' = z[47];\n""  Real 'z_weaBus.cloTim' = z[48];\n""  Real 'z_weaBus.nOpa' = z[49];\n""  Real 'z_weaBus.nTot' = z[50];\n""  Real 'z_weaBus.relHum' = z[51];\n""  Real 'z_weaBus.solAlt' = z[52];\n""  Real 'z_weaBus.solDec' = z[53];\n""  Real 'z_weaBus.solHouAng' = z[54];\n""  Real 'z_weaBus.solTim' = z[55];\n""  Real 'z_weaBus.solZen' = z[56];\n""  Real 'z_weaBus.winDir' = z[57];\n""  Real 'z_weaBus.winSpe' = z[58];\n""  Real 'z_weaDat.TBlaSkyCom.TDewPoiK' = z[59];\n""  Real 'z_weaDat.TBlaSkyCom.epsSky' = z[60];\n""  Real 'z_weaDat.TBlaSkyCom.nOpa10' = z[61];\n""  Real 'z_weaDat.add30Min.y' = z[62];\n""  Real 'z_weaDat.con30Min.y' = z[63];\n""  Real 'z_weaDat.conTim.calTim' = z[64];\n""  Real 'z_weaDat.conTimMin.calTim' = z[65];\n""  Real 'z_weaDat.conWinDir.y' = z[66];\n""  Real 'z_weaDat.datRea.y[1]' = z[67];\n""  Real 'z_weaDat.datRea.y[2]' = z[68];\n""  Real 'z_weaDat.datRea.y[3]' = z[69];\n""  Real 'z_weaDat.datRea.y[4]' = z[70];\n""  Real 'z_weaDat.datRea.y[5]' = z[71];\n""  Real 'z_weaDat.datRea.y[6]' = z[72];\n""  Real 'z_weaDat.datRea.y[7]' = z[73];\n""  Real 'z_weaDat.datRea.y[8]' = z[74];\n""  Real 'z_weaDat.datRea.y[9]' = z[75];\n""  Real 'z_weaDat.datRea.y[10]' = z[76];\n""  Real 'z_weaDat.datRea.y[11]' = z[77];\n""  Real 'z_weaDat.datRea.y[12]' = z[78];\n""  Real 'z_weaDat.datRea.y[13]' = z[79];\n""  Real 'z_weaDat.datRea.y[14]' = z[80];\n""  Real 'z_weaDat.datRea.y[15]' = z[81];\n""  Real 'z_weaDat.datRea.y[16]' = z[82];\n""  Real 'z_weaDat.datRea.y[17]' = z[83];\n""  Real 'z_weaDat.datRea.y[18]' = z[84];\n""  Real 'z_weaDat.datRea.y[19]' = z[85];\n""  Real 'z_weaDat.datRea.y[20]' = z[86];\n""  Real 'z_weaDat.datRea.y[21]' = z[87];\n""  Real 'z_weaDat.datRea.y[22]' = z[88];\n""  Real 'z_weaDat.datRea.y[23]' = z[89];\n""  Real 'z_weaDat.datRea.y[24]' = z[90];\n""  Real 'z_weaDat.datRea.y[25]' = z[91];\n""  Real 'z_weaDat.datRea.y[26]' = z[92];\n""  Real 'z_weaDat.datRea30Min.y[1]' = z[93];\n""  Real 'z_weaDat.datRea30Min.y[2]' = z[94];\n""  Real 'z_weaDat.datRea30Min.y[3]' = z[95];\n""  Real 'z_weaDat.eqnTim.Bt' = z[96];\n""  Real 'z_weaDat.eqnTim.eqnTim' = z[97];\n""  Real 'z_weaDat.locTim.locTim' = z[98];\n""  Real 'z_weaDat.opaSkyCovSel.y' = z[99];\n""  Real 'z_weaDat.pAtmSel.y' = z[100];\n""  Real 'z_weaDat.relHumSel.uFil' = z[101];\n""  Real 'z_weaDat.tWetBul_TDryBulXi.TDryBul_degC' = z[102];\n""  Real 'z_weaDat.tWetBul_TDryBulXi.XiDryBul' = z[103];\n""  Real 'z_weaDat.tWetBul_TDryBulXi.XiSat' = z[104];\n""  Real 'z_weaDat.tWetBul_TDryBulXi.XiSatRefIn' = z[105];\n""  Real 'z_weaDat.tWetBul_TDryBulXi.rh_per' = z[106];\n""  Real 'z_weaDat.totSkyCovSel.y' = z[107];\n""  Real 'z_winRad.QTraDif_flow' = z[108];\n""  Real 'z_winRad.QTraDir_flow' = z[109];\n""  Real 'z_winRad.abs.QAbsExtSha_flow[1]' = z[110];\n""  Real 'z_winRad.abs.QAbsGlaSha_flow[1,1]' = z[111];\n""  Real 'z_winRad.abs.QAbsGlaSha_flow[2,1]' = z[112];\n""  Real 'z_winRad.abs.QAbsGlaUns_flow[1,1]' = z[113];\n""  Real 'z_winRad.abs.QAbsGlaUns_flow[2,1]' = z[114];\n""  Real 'z_winRad.abs.QAbsIntSha_flow[1]' = z[115];\n""  Real 'z_winRad.abs.absRad[1,1,1]' = z[116];\n""  Real 'z_winRad.abs.absRad[1,2,1]' = z[117];\n""  Real 'z_winRad.abs.absRad[1,3,1]' = z[118];\n""  Real 'z_winRad.abs.absRad[1,4,1]' = z[119];\n""  Real 'z_winRad.abs.absRad[2,1,1]' = z[120];\n""  Real 'z_winRad.abs.absRad[2,2,1]' = z[121];\n""  Real 'z_winRad.abs.absRad[2,3,1]' = z[122];\n""  Real 'z_winRad.abs.absRad[2,4,1]' = z[123];\n""  Real 'z_winRad.abs.incAng2' = z[124];\n""  Real 'z_winRad.abs.x' = z[125];\n""  Real 'z_winRad.staIntQAbsExtSha_flow.uSta_internal' = z[126];\n""  Real 'z_winRad.staIntQAbsGlaSha_flow[1].uSta_internal' = z[127];\n""  Real 'z_winRad.staIntQAbsGlaSha_flow[2].uSta_internal' = z[128];\n""  Real 'z_winRad.staIntQAbsGlaUns_flow[1].uSta_internal' = z[129];\n""  Real 'z_winRad.staIntQAbsGlaUns_flow[2].uSta_internal' = z[130];\n""  Real 'z_winRad.staIntQAbsIntSha_flow.uSta_internal' = z[131];\n""  Real 'z_winRad.staIntQTraDif_flow.uSta_internal' = z[132];\n""  Real 'z_winRad.staIntQTraDir_flow.uSta_internal' = z[133];\n""  Real 'z_winRad.tra.QTraDifSha_flow[1]' = z[134];\n""  Real 'z_winRad.tra.QTraDifUns_flow[1]' = z[135];\n""  Real 'z_winRad.tra.QTraDirSha_flow[1]' = z[136];\n""  Real 'z_winRad.tra.QTraDirUns_flow[1]' = z[137];\n""  Real 'z_winRad.tra.incAng2' = z[138];\n""  Real 'z_winRad.tra.x' = z[139];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

