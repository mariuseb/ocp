#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustom/Buildings_HeatTransfer_Windows_Examples_WinRadCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustom_10asr.c"
#endif
/* Asserts */
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 1751
type: ALGORITHM

  assert(weaBus.TWetBul >= 0.0, "Variable violating min constraint: 0.0 <= weaBus.TWetBul, has value: " + String(weaBus.TWetBul, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1751(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1751};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,69,"Variable violating min constraint: 0.0 <= weaBus.TWetBul, has value: ");
  modelica_string tmp2;
  modelica_metatype tmpMeta3;
  static int tmp4 = 0;
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp4)
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp0 = GreaterEq((data->localData[0]->realVars[56] /* weaBus.TWetBul variable */),0.0);
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp0)
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp2 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[56] /* weaBus.TWetBul variable */), (modelica_string) mmc_strings_len1[103]);
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta3 = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaBus.TWetBul >= 0.0)";
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",750,3,755,29,0};
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",750,3,755,29,0};
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp4 = 1;
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 68 OMC_FILE
  TRACE_POP
}

/*
equation index: 1752
type: ALGORITHM

  assert(weaBus.relHum >= 0.0 and weaBus.relHum <= 1.0, "Variable violating min/max constraint: 0.0 <= weaBus.relHum <= 1.0, has value: " + String(weaBus.relHum, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1752(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1752};
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,79,"Variable violating min/max constraint: 0.0 <= weaBus.relHum <= 1.0, has value: ");
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static int tmp10 = 0;
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp10)
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp5 = GreaterEq((data->localData[0]->realVars[61] /* weaBus.relHum variable */),0.0);
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp6 = LessEq((data->localData[0]->realVars[61] /* weaBus.relHum variable */),1.0);
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp5 && tmp6))
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp8 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[61] /* weaBus.relHum variable */), (modelica_string) mmc_strings_len1[103]);
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta9 = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaBus.relHum >= 0.0 and weaBus.relHum <= 1.0)";
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",757,3,761,29,0};
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",757,3,761,29,0};
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp10 = 1;
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 130 OMC_FILE
  TRACE_POP
}

/*
equation index: 1753
type: ALGORITHM

  assert(weaDat.tWetBul_TDryBulXi.XiDryBul >= 0.0 and weaDat.tWetBul_TDryBulXi.XiDryBul <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiDryBul <= 1.0, has value: " + String(weaDat.tWetBul_TDryBulXi.XiDryBul, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1753(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1753};
  modelica_boolean tmp11;
  modelica_boolean tmp12;
  static const MMC_DEFSTRINGLIT(tmp13,99,"Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiDryBul <= 1.0, has value: ");
  modelica_string tmp14;
  modelica_metatype tmpMeta15;
  static int tmp16 = 0;
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  if(!tmp16)
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp11 = GreaterEq((data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */),0.0);
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp12 = LessEq((data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */),1.0);
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    if(!(tmp11 && tmp12))
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp14 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */), (modelica_string) mmc_strings_len1[103]);
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmpMeta15 = stringAppend(MMC_REFSTRINGLIT(tmp13),tmp14);
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        const char* assert_cond = "(weaDat.tWetBul_TDryBulXi.XiDryBul >= 0.0 and weaDat.tWetBul_TDryBulXi.XiDryBul <= 1.0)";
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",38,3,39,50,0};
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        } else {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",38,3,39,50,0};
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        }
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      }
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp16 = 1;
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    }
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  }
#line 192 OMC_FILE
  TRACE_POP
}

/*
equation index: 1754
type: ALGORITHM

  assert(weaDat.tWetBul_TDryBulXi.XiSat >= 0.0 and weaDat.tWetBul_TDryBulXi.XiSat <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiSat <= 1.0, has value: " + String(weaDat.tWetBul_TDryBulXi.XiSat, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1754(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1754};
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  static const MMC_DEFSTRINGLIT(tmp19,96,"Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiSat <= 1.0, has value: ");
  modelica_string tmp20;
  modelica_metatype tmpMeta21;
  static int tmp22 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  if(!tmp22)
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp17 = GreaterEq((data->localData[0]->realVars[112] /* weaDat.tWetBul_TDryBulXi.XiSat variable */),0.0);
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp18 = LessEq((data->localData[0]->realVars[112] /* weaDat.tWetBul_TDryBulXi.XiSat variable */),1.0);
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    if(!(tmp17 && tmp18))
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp20 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[112] /* weaDat.tWetBul_TDryBulXi.XiSat variable */), (modelica_string) mmc_strings_len1[103]);
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmpMeta21 = stringAppend(MMC_REFSTRINGLIT(tmp19),tmp20);
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        const char* assert_cond = "(weaDat.tWetBul_TDryBulXi.XiSat >= 0.0 and weaDat.tWetBul_TDryBulXi.XiSat <= 1.0)";
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",40,3,41,46,0};
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta21));
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",40,3,41,46,0};
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta21));
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp22 = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  }
#line 254 OMC_FILE
  TRACE_POP
}

/*
equation index: 1755
type: ALGORITHM

  assert(weaDat.tWetBul_TDryBulXi.XiSatRefIn >= 0.0 and weaDat.tWetBul_TDryBulXi.XiSatRefIn <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiSatRefIn <= 1.0, has value: " + String(weaDat.tWetBul_TDryBulXi.XiSatRefIn, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1755(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1755};
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  static const MMC_DEFSTRINGLIT(tmp25,101,"Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiSatRefIn <= 1.0, has value: ");
  modelica_string tmp26;
  modelica_metatype tmpMeta27;
  static int tmp28 = 0;
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  if(!tmp28)
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp23 = GreaterEq((data->localData[0]->realVars[113] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */),0.0);
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp24 = LessEq((data->localData[0]->realVars[113] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */),1.0);
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    if(!(tmp23 && tmp24))
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp26 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[113] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */), (modelica_string) mmc_strings_len1[103]);
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmpMeta27 = stringAppend(MMC_REFSTRINGLIT(tmp25),tmp26);
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        const char* assert_cond = "(weaDat.tWetBul_TDryBulXi.XiSatRefIn >= 0.0 and weaDat.tWetBul_TDryBulXi.XiSatRefIn <= 1.0)";
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",42,3,43,82,0};
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta27));
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        } else {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",42,3,43,82,0};
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta27));
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        }
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      }
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp28 = 1;
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    }
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  }
#line 316 OMC_FILE
  TRACE_POP
}
/* function to check assert after a step is done */
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1751(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1752(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1753(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1754(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1755(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

