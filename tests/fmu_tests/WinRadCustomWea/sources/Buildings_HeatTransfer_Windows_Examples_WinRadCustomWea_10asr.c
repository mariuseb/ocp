#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustomWea/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_10asr.c"
#endif
/* Asserts */
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 1765
type: ALGORITHM

  assert(weaBus.nOpa >= 0.0 and weaBus.nOpa <= 1.0, "Variable violating min/max constraint: 0.0 <= weaBus.nOpa <= 1.0, has value: " + String(weaBus.nOpa, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1765(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1765};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,77,"Variable violating min/max constraint: 0.0 <= weaBus.nOpa <= 1.0, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp5)
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp0 = GreaterEq((data->localData[0]->realVars[48] /* weaBus.nOpa variable */),0.0);
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp1 = LessEq((data->localData[0]->realVars[48] /* weaBus.nOpa variable */),1.0);
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp0 && tmp1))
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp3 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[48] /* weaBus.nOpa variable */), (modelica_string) mmc_strings_len1[103]);
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaBus.nOpa >= 0.0 and weaBus.nOpa <= 1.0)";
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",822,3,826,29,0};
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",822,3,826,29,0};
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp5 = 1;
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 71 OMC_FILE
  TRACE_POP
}

/*
equation index: 1766
type: ALGORITHM

  assert(weaBus.TDryBul >= 0.0, "Variable violating min constraint: 0.0 <= weaBus.TDryBul, has value: " + String(weaBus.TDryBul, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1766(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1766};
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,69,"Variable violating min constraint: 0.0 <= weaBus.TDryBul, has value: ");
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static int tmp10 = 0;
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp10)
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp6 = GreaterEq((data->localData[0]->realVars[44] /* weaBus.TDryBul variable */),0.0);
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp6)
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp8 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[44] /* weaBus.TDryBul variable */), (modelica_string) mmc_strings_len1[103]);
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta9 = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaBus.TDryBul >= 0.0)";
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",737,3,742,47,0};
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",737,3,742,47,0};
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp10 = 1;
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 737 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 130 OMC_FILE
  TRACE_POP
}

/*
equation index: 1767
type: ALGORITHM

  assert(weaBus.HHorIR >= 0.0, "Variable violating min constraint: 0.0 <= weaBus.HHorIR, has value: " + String(weaBus.HHorIR, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1767(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1767};
  modelica_boolean tmp11;
  static const MMC_DEFSTRINGLIT(tmp12,68,"Variable violating min constraint: 0.0 <= weaBus.HHorIR, has value: ");
  modelica_string tmp13;
  modelica_metatype tmpMeta14;
  static int tmp15 = 0;
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp15)
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp11 = GreaterEq((data->localData[0]->realVars[41] /* weaBus.HHorIR variable */),0.0);
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp11)
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp13 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[41] /* weaBus.HHorIR variable */), (modelica_string) mmc_strings_len1[103]);
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta14 = stringAppend(MMC_REFSTRINGLIT(tmp12),tmp13);
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaBus.HHorIR >= 0.0)";
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",790,3,795,47,0};
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",790,3,795,47,0};
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp15 = 1;
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 189 OMC_FILE
  TRACE_POP
}

/*
equation index: 1768
type: ALGORITHM

  assert(weaBus.TWetBul >= 0.0, "Variable violating min constraint: 0.0 <= weaBus.TWetBul, has value: " + String(weaBus.TWetBul, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1768(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1768};
  modelica_boolean tmp16;
  static const MMC_DEFSTRINGLIT(tmp17,69,"Variable violating min constraint: 0.0 <= weaBus.TWetBul, has value: ");
  modelica_string tmp18;
  modelica_metatype tmpMeta19;
  static int tmp20 = 0;
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp20)
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp16 = GreaterEq((data->localData[0]->realVars[45] /* weaBus.TWetBul variable */),0.0);
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp16)
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp18 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[45] /* weaBus.TWetBul variable */), (modelica_string) mmc_strings_len1[103]);
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta19 = stringAppend(MMC_REFSTRINGLIT(tmp17),tmp18);
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaBus.TWetBul >= 0.0)";
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",750,3,755,29,0};
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta19));
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",750,3,755,29,0};
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta19));
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp20 = 1;
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 750 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 248 OMC_FILE
  TRACE_POP
}

/*
equation index: 1769
type: ALGORITHM

  assert(weaBus.relHum >= 0.0 and weaBus.relHum <= 1.0, "Variable violating min/max constraint: 0.0 <= weaBus.relHum <= 1.0, has value: " + String(weaBus.relHum, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1769(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1769};
  modelica_boolean tmp21;
  modelica_boolean tmp22;
  static const MMC_DEFSTRINGLIT(tmp23,79,"Variable violating min/max constraint: 0.0 <= weaBus.relHum <= 1.0, has value: ");
  modelica_string tmp24;
  modelica_metatype tmpMeta25;
  static int tmp26 = 0;
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp26)
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp21 = GreaterEq((data->localData[0]->realVars[50] /* weaBus.relHum variable */),0.0);
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp22 = LessEq((data->localData[0]->realVars[50] /* weaBus.relHum variable */),1.0);
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp21 && tmp22))
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp24 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[50] /* weaBus.relHum variable */), (modelica_string) mmc_strings_len1[103]);
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta25 = stringAppend(MMC_REFSTRINGLIT(tmp23),tmp24);
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaBus.relHum >= 0.0 and weaBus.relHum <= 1.0)";
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",757,3,761,29,0};
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta25));
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",757,3,761,29,0};
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta25));
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp26 = 1;
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 757 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 310 OMC_FILE
  TRACE_POP
}

/*
equation index: 1770
type: ALGORITHM

  assert(weaDat.TBlaSkyCom.TDewPoiK >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.TBlaSkyCom.TDewPoiK, has value: " + String(weaDat.TBlaSkyCom.TDewPoiK, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1770(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1770};
  modelica_boolean tmp27;
  static const MMC_DEFSTRINGLIT(tmp28,81,"Variable violating min constraint: 0.0 <= weaDat.TBlaSkyCom.TDewPoiK, has value: ");
  modelica_string tmp29;
  modelica_metatype tmpMeta30;
  static int tmp31 = 0;
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  if(!tmp31)
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp27 = GreaterEq((data->localData[0]->realVars[58] /* weaDat.TBlaSkyCom.TDewPoiK variable */),0.0);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    if(!tmp27)
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp29 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[58] /* weaDat.TBlaSkyCom.TDewPoiK variable */), (modelica_string) mmc_strings_len1[103]);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmpMeta30 = stringAppend(MMC_REFSTRINGLIT(tmp28),tmp29);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        const char* assert_cond = "(weaDat.TBlaSkyCom.TDewPoiK >= 0.0)";
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo",34,3,34,64,0};
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta30));
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        } else {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo",34,3,34,64,0};
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta30));
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        }
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp31 = 1;
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 369 OMC_FILE
  TRACE_POP
}

/*
equation index: 1771
type: ALGORITHM

  assert(weaDat.TBlaSkyCom.nOpa10 >= 0.0 and weaDat.TBlaSkyCom.nOpa10 <= 10.0, "Variable violating min/max constraint: 0.0 <= weaDat.TBlaSkyCom.nOpa10 <= 10.0, has value: " + String(weaDat.TBlaSkyCom.nOpa10, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1771(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1771};
  modelica_boolean tmp32;
  modelica_boolean tmp33;
  static const MMC_DEFSTRINGLIT(tmp34,91,"Variable violating min/max constraint: 0.0 <= weaDat.TBlaSkyCom.nOpa10 <= 10.0, has value: ");
  modelica_string tmp35;
  modelica_metatype tmpMeta36;
  static int tmp37 = 0;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  if(!tmp37)
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp32 = GreaterEq((data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */),0.0);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp33 = LessEq((data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */),10.0);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    if(!(tmp32 && tmp33))
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp35 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */), (modelica_string) mmc_strings_len1[103]);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmpMeta36 = stringAppend(MMC_REFSTRINGLIT(tmp34),tmp35);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        const char* assert_cond = "(weaDat.TBlaSkyCom.nOpa10 >= 0.0 and weaDat.TBlaSkyCom.nOpa10 <= 10.0)";
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo",36,3,36,59,0};
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta36));
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        } else {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo",36,3,36,59,0};
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta36));
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        }
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp37 = 1;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 431 OMC_FILE
  TRACE_POP
}

/*
equation index: 1772
type: ALGORITHM

  assert(weaDat.tWetBul_TDryBulXi.XiDryBul >= 0.0 and weaDat.tWetBul_TDryBulXi.XiDryBul <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiDryBul <= 1.0, has value: " + String(weaDat.tWetBul_TDryBulXi.XiDryBul, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1772(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1772};
  modelica_boolean tmp38;
  modelica_boolean tmp39;
  static const MMC_DEFSTRINGLIT(tmp40,99,"Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiDryBul <= 1.0, has value: ");
  modelica_string tmp41;
  modelica_metatype tmpMeta42;
  static int tmp43 = 0;
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  if(!tmp43)
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp38 = GreaterEq((data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */),0.0);
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp39 = LessEq((data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */),1.0);
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    if(!(tmp38 && tmp39))
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp41 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */), (modelica_string) mmc_strings_len1[103]);
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmpMeta42 = stringAppend(MMC_REFSTRINGLIT(tmp40),tmp41);
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        const char* assert_cond = "(weaDat.tWetBul_TDryBulXi.XiDryBul >= 0.0 and weaDat.tWetBul_TDryBulXi.XiDryBul <= 1.0)";
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",38,3,39,50,0};
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta42));
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        } else {
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",38,3,39,50,0};
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta42));
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        }
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      }
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp43 = 1;
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    }
#line 38 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  }
#line 493 OMC_FILE
  TRACE_POP
}

/*
equation index: 1773
type: ALGORITHM

  assert(weaDat.tWetBul_TDryBulXi.XiSat >= 0.0 and weaDat.tWetBul_TDryBulXi.XiSat <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiSat <= 1.0, has value: " + String(weaDat.tWetBul_TDryBulXi.XiSat, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1773(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1773};
  modelica_boolean tmp44;
  modelica_boolean tmp45;
  static const MMC_DEFSTRINGLIT(tmp46,96,"Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiSat <= 1.0, has value: ");
  modelica_string tmp47;
  modelica_metatype tmpMeta48;
  static int tmp49 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  if(!tmp49)
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp44 = GreaterEq((data->localData[0]->realVars[103] /* weaDat.tWetBul_TDryBulXi.XiSat variable */),0.0);
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp45 = LessEq((data->localData[0]->realVars[103] /* weaDat.tWetBul_TDryBulXi.XiSat variable */),1.0);
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    if(!(tmp44 && tmp45))
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp47 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[103] /* weaDat.tWetBul_TDryBulXi.XiSat variable */), (modelica_string) mmc_strings_len1[103]);
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmpMeta48 = stringAppend(MMC_REFSTRINGLIT(tmp46),tmp47);
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        const char* assert_cond = "(weaDat.tWetBul_TDryBulXi.XiSat >= 0.0 and weaDat.tWetBul_TDryBulXi.XiSat <= 1.0)";
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",40,3,41,46,0};
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta48));
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",40,3,41,46,0};
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta48));
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp49 = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  }
#line 555 OMC_FILE
  TRACE_POP
}

/*
equation index: 1774
type: ALGORITHM

  assert(weaDat.tWetBul_TDryBulXi.XiSatRefIn >= 0.0 and weaDat.tWetBul_TDryBulXi.XiSatRefIn <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiSatRefIn <= 1.0, has value: " + String(weaDat.tWetBul_TDryBulXi.XiSatRefIn, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1774(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1774};
  modelica_boolean tmp50;
  modelica_boolean tmp51;
  static const MMC_DEFSTRINGLIT(tmp52,101,"Variable violating min/max constraint: 0.0 <= weaDat.tWetBul_TDryBulXi.XiSatRefIn <= 1.0, has value: ");
  modelica_string tmp53;
  modelica_metatype tmpMeta54;
  static int tmp55 = 0;
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  if(!tmp55)
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp50 = GreaterEq((data->localData[0]->realVars[104] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */),0.0);
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    tmp51 = LessEq((data->localData[0]->realVars[104] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */),1.0);
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    if(!(tmp50 && tmp51))
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp53 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[104] /* weaDat.tWetBul_TDryBulXi.XiSatRefIn variable */), (modelica_string) mmc_strings_len1[103]);
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmpMeta54 = stringAppend(MMC_REFSTRINGLIT(tmp52),tmp53);
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        const char* assert_cond = "(weaDat.tWetBul_TDryBulXi.XiSatRefIn >= 0.0 and weaDat.tWetBul_TDryBulXi.XiSatRefIn <= 1.0)";
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",42,3,43,82,0};
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta54));
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        } else {
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo",42,3,43,82,0};
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta54));
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
        }
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      }
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
      tmp55 = 1;
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
    }
#line 42 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  }
#line 617 OMC_FILE
  TRACE_POP
}
/* function to check assert after a step is done */
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1765(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1766(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1767(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1768(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1769(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1770(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1771(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1772(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1773(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1774(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

