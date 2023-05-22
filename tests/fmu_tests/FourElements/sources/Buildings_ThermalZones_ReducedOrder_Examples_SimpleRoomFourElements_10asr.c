#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_10asr.c"
#endif
/* Asserts */
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 1562
type: ALGORITHM

  assert(preTem1.T >= 0.0, "Variable violating min constraint: 0.0 <= preTem1.T, has value: " + String(preTem1.T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1562(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1562};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,64,"Variable violating min constraint: 0.0 <= preTem1.T, has value: ");
  modelica_string tmp2;
  modelica_metatype tmpMeta3;
  static int tmp4 = 0;
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
  if(!tmp4)
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
  {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
    tmp0 = GreaterEq((data->localData[0]->realVars[205] /* preTem1.T variable */),0.0);
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
    if(!tmp0)
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
    {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      tmp2 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[205] /* preTem1.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      tmpMeta3 = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
        const char* assert_cond = "(preTem1.T >= 0.0)";
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo",6,3,7,43,0};
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
        } else {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo",6,3,7,43,0};
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
        }
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      }
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      tmp4 = 1;
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
    }
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
  }
#line 68 OMC_FILE
  TRACE_POP
}

/*
equation index: 1563
type: ALGORITHM

  assert(eqAirTemp.TEqWin[1] >= 0.0, "Variable violating min constraint: 0.0 <= eqAirTemp.TEqWin[1], has value: " + String(eqAirTemp.TEqWin[1], "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1563(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1563};
  modelica_boolean tmp5;
  static const MMC_DEFSTRINGLIT(tmp6,74,"Variable violating min constraint: 0.0 <= eqAirTemp.TEqWin[1], has value: ");
  modelica_string tmp7;
  modelica_metatype tmpMeta8;
  static int tmp9 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  if(!tmp9)
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    tmp5 = GreaterEq((data->localData[0]->realVars[188] /* eqAirTemp.TEqWin[1] variable */),0.0);
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    if(!tmp5)
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp7 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[188] /* eqAirTemp.TEqWin[1] variable */), (modelica_string) mmc_strings_len1[103]);
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmpMeta8 = stringAppend(MMC_REFSTRINGLIT(tmp6),tmp7);
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        const char* assert_cond = "(eqAirTemp.TEqWin[1] >= 0.0)";
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",23,3,23,74,0};
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",23,3,23,74,0};
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp9 = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  }
#line 127 OMC_FILE
  TRACE_POP
}

/*
equation index: 1564
type: ALGORITHM

  assert(HDifTil[1].weaBus.nOpa >= 0.0 and HDifTil[1].weaBus.nOpa <= 1.0, "Variable violating min/max constraint: 0.0 <= HDifTil[1].weaBus.nOpa <= 1.0, has value: " + String(HDifTil[1].weaBus.nOpa, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1564(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1564};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  static const MMC_DEFSTRINGLIT(tmp12,88,"Variable violating min/max constraint: 0.0 <= HDifTil[1].weaBus.nOpa <= 1.0, has value: ");
  modelica_string tmp13;
  modelica_metatype tmpMeta14;
  static int tmp15 = 0;
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp15)
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp10 = GreaterEq((data->localData[0]->realVars[123] /* HDifTil[1].weaBus.nOpa variable */),0.0);
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp11 = LessEq((data->localData[0]->realVars[123] /* HDifTil[1].weaBus.nOpa variable */),1.0);
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp10 && tmp11))
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp13 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[123] /* HDifTil[1].weaBus.nOpa variable */), (modelica_string) mmc_strings_len1[103]);
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta14 = stringAppend(MMC_REFSTRINGLIT(tmp12),tmp13);
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(HDifTil[1].weaBus.nOpa >= 0.0 and HDifTil[1].weaBus.nOpa <= 1.0)";
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",822,3,826,29,0};
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",822,3,826,29,0};
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp15 = 1;
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 822 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 189 OMC_FILE
  TRACE_POP
}

/*
equation index: 1565
type: ALGORITHM

  assert(HDifTil[1].weaBus.HHorIR >= 0.0, "Variable violating min constraint: 0.0 <= HDifTil[1].weaBus.HHorIR, has value: " + String(HDifTil[1].weaBus.HHorIR, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1565(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1565};
  modelica_boolean tmp16;
  static const MMC_DEFSTRINGLIT(tmp17,79,"Variable violating min constraint: 0.0 <= HDifTil[1].weaBus.HHorIR, has value: ");
  modelica_string tmp18;
  modelica_metatype tmpMeta19;
  static int tmp20 = 0;
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp20)
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp16 = GreaterEq((data->localData[0]->realVars[120] /* HDifTil[1].weaBus.HHorIR variable */),0.0);
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp16)
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp18 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[120] /* HDifTil[1].weaBus.HHorIR variable */), (modelica_string) mmc_strings_len1[103]);
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta19 = stringAppend(MMC_REFSTRINGLIT(tmp17),tmp18);
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(HDifTil[1].weaBus.HHorIR >= 0.0)";
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",790,3,795,47,0};
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta19));
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",790,3,795,47,0};
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta19));
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp20 = 1;
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 790 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 248 OMC_FILE
  TRACE_POP
}

/*
equation index: 1566
type: ALGORITHM

  assert(thermalZoneFourElements.TAir >= 273.15 and thermalZoneFourElements.TAir <= 373.15, "Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.TAir <= 373.15, has value: " + String(thermalZoneFourElements.TAir, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1566(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1566};
  modelica_boolean tmp21;
  modelica_boolean tmp22;
  static const MMC_DEFSTRINGLIT(tmp23,100,"Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.TAir <= 373.15, has value: ");
  modelica_string tmp24;
  modelica_metatype tmpMeta25;
  static int tmp26 = 0;
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  if(!tmp26)
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  {
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    tmp21 = GreaterEq((data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */),273.15);
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    tmp22 = LessEq((data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */),373.15);
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    if(!(tmp21 && tmp22))
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    {
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp24 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */), (modelica_string) mmc_strings_len1[103]);
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmpMeta25 = stringAppend(MMC_REFSTRINGLIT(tmp23),tmp24);
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      {
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        const char* assert_cond = "(thermalZoneFourElements.TAir >= 273.15 and thermalZoneFourElements.TAir <= 373.15)";
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",76,3,81,55,0};
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta25));
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        } else {
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",76,3,81,55,0};
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta25));
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        }
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      }
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp26 = 1;
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    }
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  }
#line 310 OMC_FILE
  TRACE_POP
}

/*
equation index: 1567
type: ALGORITHM

  assert(thermalZoneFourElements.TRad >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.TRad, has value: " + String(thermalZoneFourElements.TRad, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1567(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1567};
  modelica_boolean tmp27;
  static const MMC_DEFSTRINGLIT(tmp28,83,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.TRad, has value: ");
  modelica_string tmp29;
  modelica_metatype tmpMeta30;
  static int tmp31 = 0;
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  if(!tmp31)
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  {
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    tmp27 = GreaterEq((data->localData[0]->realVars[217] /* thermalZoneFourElements.TRad variable */),0.0);
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    if(!tmp27)
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    {
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp29 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[217] /* thermalZoneFourElements.TRad variable */), (modelica_string) mmc_strings_len1[103]);
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmpMeta30 = stringAppend(MMC_REFSTRINGLIT(tmp28),tmp29);
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      {
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        const char* assert_cond = "(thermalZoneFourElements.TRad >= 0.0)";
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",83,3,88,55,0};
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta30));
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        } else {
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo",83,3,88,55,0};
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta30));
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
        }
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      }
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
      tmp31 = 1;
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
    }
#line 83 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/OneElement.mo"
  }
#line 369 OMC_FILE
  TRACE_POP
}

/*
equation index: 1568
type: ALGORITHM

  assert(thermalZoneFourElements.extWall.T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.extWall.T, has value: " + String(thermalZoneFourElements.extWall.T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1568(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1568};
  modelica_boolean tmp32;
  static const MMC_DEFSTRINGLIT(tmp33,88,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.extWall.T, has value: ");
  modelica_string tmp34;
  modelica_metatype tmpMeta35;
  static int tmp36 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp36)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp32 = GreaterEq((data->localData[0]->realVars[231] /* thermalZoneFourElements.extWall.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp32)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp34 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[231] /* thermalZoneFourElements.extWall.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta35 = stringAppend(MMC_REFSTRINGLIT(tmp33),tmp34);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(thermalZoneFourElements.extWall.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta35));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta35));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp36 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 428 OMC_FILE
  TRACE_POP
}

/*
equation index: 1569
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.medium.p >= 0.0 and thermalZoneFourElements.volAir.dynBal.medium.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.medium.p <= 100000000.0, has value: " + String(thermalZoneFourElements.volAir.dynBal.medium.p, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1569(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1569};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  static const MMC_DEFSTRINGLIT(tmp39,120,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.medium.p <= 100000000.0, has value: ");
  modelica_string tmp40;
  modelica_metatype tmpMeta41;
  static int tmp42 = 0;
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp42)
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp37 = GreaterEq((data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */),0.0);
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp38 = LessEq((data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */),100000000.0);
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp37 && tmp38))
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp40 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */), (modelica_string) mmc_strings_len1[103]);
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta41 = stringAppend(MMC_REFSTRINGLIT(tmp39),tmp40);
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.medium.p >= 0.0 and thermalZoneFourElements.volAir.dynBal.medium.p <= 100000000.0)";
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",3978,7,3978,60,0};
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta41));
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",3978,7,3978,60,0};
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta41));
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp42 = 1;
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 3978 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 490 OMC_FILE
  TRACE_POP
}

/*
equation index: 1570
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.medium.d >= 0.0 and thermalZoneFourElements.volAir.dynBal.medium.d <= 100000.0, "Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.medium.d <= 100000.0, has value: " + String(thermalZoneFourElements.volAir.dynBal.medium.d, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1570(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1570};
  modelica_boolean tmp43;
  modelica_boolean tmp44;
  static const MMC_DEFSTRINGLIT(tmp45,117,"Variable violating min/max constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.medium.d <= 100000.0, has value: ");
  modelica_string tmp46;
  modelica_metatype tmpMeta47;
  static int tmp48 = 0;
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp48)
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp43 = GreaterEq((data->localData[0]->realVars[304] /* thermalZoneFourElements.volAir.dynBal.medium.d variable */),0.0);
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp44 = LessEq((data->localData[0]->realVars[304] /* thermalZoneFourElements.volAir.dynBal.medium.d variable */),100000.0);
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp43 && tmp44))
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp46 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[304] /* thermalZoneFourElements.volAir.dynBal.medium.d variable */), (modelica_string) mmc_strings_len1[103]);
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta47 = stringAppend(MMC_REFSTRINGLIT(tmp45),tmp46);
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.medium.d >= 0.0 and thermalZoneFourElements.volAir.dynBal.medium.d <= 100000.0)";
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",3982,7,3982,36,0};
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta47));
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",3982,7,3982,36,0};
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta47));
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp48 = 1;
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 3982 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 552 OMC_FILE
  TRACE_POP
}

/*
equation index: 1571
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.medium.T >= 273.15 and thermalZoneFourElements.volAir.dynBal.medium.T <= 373.15, "Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.dynBal.medium.T <= 373.15, has value: " + String(thermalZoneFourElements.volAir.dynBal.medium.T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1571(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1571};
  modelica_boolean tmp49;
  modelica_boolean tmp50;
  static const MMC_DEFSTRINGLIT(tmp51,118,"Variable violating min/max constraint: 273.15 <= thermalZoneFourElements.volAir.dynBal.medium.T <= 373.15, has value: ");
  modelica_string tmp52;
  modelica_metatype tmpMeta53;
  static int tmp54 = 0;
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp54)
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp49 = GreaterEq((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */),273.15);
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp50 = LessEq((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */),373.15);
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp49 && tmp50))
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp52 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta53 = stringAppend(MMC_REFSTRINGLIT(tmp51),tmp52);
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.medium.T >= 273.15 and thermalZoneFourElements.volAir.dynBal.medium.T <= 373.15)";
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",3983,7,3983,44,0};
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta53));
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",3983,7,3983,44,0};
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta53));
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp54 = 1;
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 3983 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 614 OMC_FILE
  TRACE_POP
}

/*
equation index: 1572
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.medium.u >= -100000000.0 and thermalZoneFourElements.volAir.dynBal.medium.u <= 100000000.0, "Variable violating min/max constraint: -100000000.0 <= thermalZoneFourElements.volAir.dynBal.medium.u <= 100000000.0, has value: " + String(thermalZoneFourElements.volAir.dynBal.medium.u, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1572(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1572};
  modelica_boolean tmp55;
  modelica_boolean tmp56;
  static const MMC_DEFSTRINGLIT(tmp57,129,"Variable violating min/max constraint: -100000000.0 <= thermalZoneFourElements.volAir.dynBal.medium.u <= 100000000.0, has value: ");
  modelica_string tmp58;
  modelica_metatype tmpMeta59;
  static int tmp60 = 0;
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  if(!tmp60)
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp55 = GreaterEq((data->localData[0]->realVars[307] /* thermalZoneFourElements.volAir.dynBal.medium.u variable */),-100000000.0);
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp56 = LessEq((data->localData[0]->realVars[307] /* thermalZoneFourElements.volAir.dynBal.medium.u variable */),100000000.0);
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp55 && tmp56))
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp58 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[307] /* thermalZoneFourElements.volAir.dynBal.medium.u variable */), (modelica_string) mmc_strings_len1[103]);
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta59 = stringAppend(MMC_REFSTRINGLIT(tmp57),tmp58);
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.medium.u >= -100000000.0 and thermalZoneFourElements.volAir.dynBal.medium.u <= 100000000.0)";
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",3986,7,3986,68,0};
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta59));
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",3986,7,3986,68,0};
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta59));
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp60 = 1;
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 3986 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 676 OMC_FILE
  TRACE_POP
}

/*
equation index: 1573
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.m >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.m, has value: " + String(thermalZoneFourElements.volAir.dynBal.m, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1573(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1573};
  modelica_boolean tmp61;
  static const MMC_DEFSTRINGLIT(tmp62,94,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.volAir.dynBal.m, has value: ");
  modelica_string tmp63;
  modelica_metatype tmpMeta64;
  static int tmp65 = 0;
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  if(!tmp65)
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    tmp61 = GreaterEq((data->localData[0]->realVars[5] /* thermalZoneFourElements.volAir.dynBal.m STATE(1) */),0.0);
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    if(!tmp61)
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      tmp63 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[5] /* thermalZoneFourElements.volAir.dynBal.m STATE(1) */), (modelica_string) mmc_strings_len1[103]);
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      tmpMeta64 = stringAppend(MMC_REFSTRINGLIT(tmp62),tmp63);
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.m >= 0.0)";
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo",96,3,98,69,0};
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta64));
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        } else {
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo",96,3,98,69,0};
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta64));
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
        }
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      }
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
      tmp65 = 1;
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
    }
#line 96 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  }
#line 735 OMC_FILE
  TRACE_POP
}

/*
equation index: 1574
type: ALGORITHM

  assert(thermalZoneFourElements.radHeatSol[1].port.T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.radHeatSol[1].port.T, has value: " + String(thermalZoneFourElements.radHeatSol[1].port.T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1574(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1574};
  modelica_boolean tmp66;
  static const MMC_DEFSTRINGLIT(tmp67,99,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.radHeatSol[1].port.T, has value: ");
  modelica_string tmp68;
  modelica_metatype tmpMeta69;
  static int tmp70 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp70)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp66 = GreaterEq((data->localData[0]->realVars[254] /* thermalZoneFourElements.radHeatSol[1].port.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp66)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp68 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[254] /* thermalZoneFourElements.radHeatSol[1].port.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta69 = stringAppend(MMC_REFSTRINGLIT(tmp67),tmp68);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(thermalZoneFourElements.radHeatSol[1].port.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta69));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta69));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp70 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 794 OMC_FILE
  TRACE_POP
}

/*
equation index: 1575
type: ALGORITHM

  assert(thermalZoneFourElements.radHeatSol[2].port.T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.radHeatSol[2].port.T, has value: " + String(thermalZoneFourElements.radHeatSol[2].port.T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1575(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1575};
  modelica_boolean tmp71;
  static const MMC_DEFSTRINGLIT(tmp72,99,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.radHeatSol[2].port.T, has value: ");
  modelica_string tmp73;
  modelica_metatype tmpMeta74;
  static int tmp75 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp75)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp71 = GreaterEq((data->localData[0]->realVars[255] /* thermalZoneFourElements.radHeatSol[2].port.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp71)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp73 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[255] /* thermalZoneFourElements.radHeatSol[2].port.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta74 = stringAppend(MMC_REFSTRINGLIT(tmp72),tmp73);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(thermalZoneFourElements.radHeatSol[2].port.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta74));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta74));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp75 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 853 OMC_FILE
  TRACE_POP
}

/*
equation index: 1576
type: ALGORITHM

  assert(thermalZoneFourElements.thermSplitterIntGains.portOut[3].T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterIntGains.portOut[3].T, has value: " + String(thermalZoneFourElements.thermSplitterIntGains.portOut[3].T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1576(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1576};
  modelica_boolean tmp76;
  static const MMC_DEFSTRINGLIT(tmp77,113,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterIntGains.portOut[3].T, has value: ");
  modelica_string tmp78;
  modelica_metatype tmpMeta79;
  static int tmp80 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp80)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp76 = GreaterEq((data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp76)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp78 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta79 = stringAppend(MMC_REFSTRINGLIT(tmp77),tmp78);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(thermalZoneFourElements.thermSplitterIntGains.portOut[3].T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta79));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta79));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp80 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 912 OMC_FILE
  TRACE_POP
}

/*
equation index: 1577
type: ALGORITHM

  assert(thermalZoneFourElements.thermSplitterIntGains.portOut[4].T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterIntGains.portOut[4].T, has value: " + String(thermalZoneFourElements.thermSplitterIntGains.portOut[4].T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1577(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1577};
  modelica_boolean tmp81;
  static const MMC_DEFSTRINGLIT(tmp82,113,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterIntGains.portOut[4].T, has value: ");
  modelica_string tmp83;
  modelica_metatype tmpMeta84;
  static int tmp85 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp85)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp81 = GreaterEq((data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp81)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp83 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta84 = stringAppend(MMC_REFSTRINGLIT(tmp82),tmp83);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(thermalZoneFourElements.thermSplitterIntGains.portOut[4].T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta84));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta84));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp85 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 971 OMC_FILE
  TRACE_POP
}

/*
equation index: 1578
type: ALGORITHM

  assert(thermalZoneFourElements.thermSplitterIntGains.portOut[5].T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterIntGains.portOut[5].T, has value: " + String(thermalZoneFourElements.thermSplitterIntGains.portOut[5].T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1578(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1578};
  modelica_boolean tmp86;
  static const MMC_DEFSTRINGLIT(tmp87,113,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterIntGains.portOut[5].T, has value: ");
  modelica_string tmp88;
  modelica_metatype tmpMeta89;
  static int tmp90 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp90)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp86 = GreaterEq((data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp86)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp88 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta89 = stringAppend(MMC_REFSTRINGLIT(tmp87),tmp88);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(thermalZoneFourElements.thermSplitterIntGains.portOut[5].T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta89));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta89));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp90 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 1030 OMC_FILE
  TRACE_POP
}

/*
equation index: 1579
type: ALGORITHM

  assert(thermalZoneFourElements.thermSplitterSolRad.portOut[1].T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterSolRad.portOut[1].T, has value: " + String(thermalZoneFourElements.thermSplitterSolRad.portOut[1].T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1579(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1579};
  modelica_boolean tmp91;
  static const MMC_DEFSTRINGLIT(tmp92,111,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterSolRad.portOut[1].T, has value: ");
  modelica_string tmp93;
  modelica_metatype tmpMeta94;
  static int tmp95 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp95)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp91 = GreaterEq((data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp91)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp93 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta94 = stringAppend(MMC_REFSTRINGLIT(tmp92),tmp93);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(thermalZoneFourElements.thermSplitterSolRad.portOut[1].T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta94));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta94));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp95 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 1089 OMC_FILE
  TRACE_POP
}

/*
equation index: 1580
type: ALGORITHM

  assert(thermalZoneFourElements.thermSplitterSolRad.portOut[2].T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterSolRad.portOut[2].T, has value: " + String(thermalZoneFourElements.thermSplitterSolRad.portOut[2].T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1580(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1580};
  modelica_boolean tmp96;
  static const MMC_DEFSTRINGLIT(tmp97,111,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.thermSplitterSolRad.portOut[2].T, has value: ");
  modelica_string tmp98;
  modelica_metatype tmpMeta99;
  static int tmp100 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp100)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp96 = GreaterEq((data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp96)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp98 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta99 = stringAppend(MMC_REFSTRINGLIT(tmp97),tmp98);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(thermalZoneFourElements.thermSplitterSolRad.portOut[2].T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta99));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta99));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp100 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 1148 OMC_FILE
  TRACE_POP
}

/*
equation index: 1581
type: ALGORITHM

  assert(thermalZoneFourElements.extWallRC.thermCapExt[1].T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.extWallRC.thermCapExt[1].T, has value: " + String(thermalZoneFourElements.extWallRC.thermCapExt[1].T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1581(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1581};
  modelica_boolean tmp101;
  static const MMC_DEFSTRINGLIT(tmp102,105,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.extWallRC.thermCapExt[1].T, has value: ");
  modelica_string tmp103;
  modelica_metatype tmpMeta104;
  static int tmp105 = 0;
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  if(!tmp105)
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    tmp101 = GreaterEq((data->localData[0]->realVars[0] /* thermalZoneFourElements.extWallRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.extWallRC.thermCapExt[1].der_T) */),0.0);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    if(!tmp101)
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmp103 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[0] /* thermalZoneFourElements.extWallRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.extWallRC.thermCapExt[1].der_T) */), (modelica_string) mmc_strings_len1[103]);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmpMeta104 = stringAppend(MMC_REFSTRINGLIT(tmp102),tmp103);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        const char* assert_cond = "(thermalZoneFourElements.extWallRC.thermCapExt[1].T >= 0.0)";
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo",5,3,6,29,0};
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta104));
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        } else {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo",5,3,6,29,0};
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta104));
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmp105 = 1;
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  }
#line 1207 OMC_FILE
  TRACE_POP
}

/*
equation index: 1582
type: ALGORITHM

  assert(thermalZoneFourElements.intWallRC.thermCapInt[1].T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.intWallRC.thermCapInt[1].T, has value: " + String(thermalZoneFourElements.intWallRC.thermCapInt[1].T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1582(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1582};
  modelica_boolean tmp106;
  static const MMC_DEFSTRINGLIT(tmp107,105,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.intWallRC.thermCapInt[1].T, has value: ");
  modelica_string tmp108;
  modelica_metatype tmpMeta109;
  static int tmp110 = 0;
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  if(!tmp110)
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    tmp106 = GreaterEq((data->localData[0]->realVars[2] /* thermalZoneFourElements.intWallRC.thermCapInt[1].T STATE(1,thermalZoneFourElements.intWallRC.thermCapInt[1].der_T) */),0.0);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    if(!tmp106)
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmp108 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[2] /* thermalZoneFourElements.intWallRC.thermCapInt[1].T STATE(1,thermalZoneFourElements.intWallRC.thermCapInt[1].der_T) */), (modelica_string) mmc_strings_len1[103]);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmpMeta109 = stringAppend(MMC_REFSTRINGLIT(tmp107),tmp108);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        const char* assert_cond = "(thermalZoneFourElements.intWallRC.thermCapInt[1].T >= 0.0)";
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo",5,3,6,29,0};
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta109));
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        } else {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo",5,3,6,29,0};
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta109));
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmp110 = 1;
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  }
#line 1266 OMC_FILE
  TRACE_POP
}

/*
equation index: 1583
type: ALGORITHM

  assert(thermalZoneFourElements.floorRC.thermCapExt[1].T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.floorRC.thermCapExt[1].T, has value: " + String(thermalZoneFourElements.floorRC.thermCapExt[1].T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1583(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1583};
  modelica_boolean tmp111;
  static const MMC_DEFSTRINGLIT(tmp112,103,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.floorRC.thermCapExt[1].T, has value: ");
  modelica_string tmp113;
  modelica_metatype tmpMeta114;
  static int tmp115 = 0;
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  if(!tmp115)
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    tmp111 = GreaterEq((data->localData[0]->realVars[1] /* thermalZoneFourElements.floorRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.floorRC.thermCapExt[1].der_T) */),0.0);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    if(!tmp111)
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmp113 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[1] /* thermalZoneFourElements.floorRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.floorRC.thermCapExt[1].der_T) */), (modelica_string) mmc_strings_len1[103]);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmpMeta114 = stringAppend(MMC_REFSTRINGLIT(tmp112),tmp113);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        const char* assert_cond = "(thermalZoneFourElements.floorRC.thermCapExt[1].T >= 0.0)";
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo",5,3,6,29,0};
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta114));
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        } else {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo",5,3,6,29,0};
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta114));
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmp115 = 1;
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  }
#line 1325 OMC_FILE
  TRACE_POP
}

/*
equation index: 1584
type: ALGORITHM

  assert(thermalZoneFourElements.roofRC.thermCapExt[1].T >= 0.0, "Variable violating min constraint: 0.0 <= thermalZoneFourElements.roofRC.thermCapExt[1].T, has value: " + String(thermalZoneFourElements.roofRC.thermCapExt[1].T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1584(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1584};
  modelica_boolean tmp116;
  static const MMC_DEFSTRINGLIT(tmp117,102,"Variable violating min constraint: 0.0 <= thermalZoneFourElements.roofRC.thermCapExt[1].T, has value: ");
  modelica_string tmp118;
  modelica_metatype tmpMeta119;
  static int tmp120 = 0;
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  if(!tmp120)
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    tmp116 = GreaterEq((data->localData[0]->realVars[3] /* thermalZoneFourElements.roofRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.roofRC.thermCapExt[1].der_T) */),0.0);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    if(!tmp116)
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmp118 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[3] /* thermalZoneFourElements.roofRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.roofRC.thermCapExt[1].der_T) */), (modelica_string) mmc_strings_len1[103]);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmpMeta119 = stringAppend(MMC_REFSTRINGLIT(tmp117),tmp118);
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        const char* assert_cond = "(thermalZoneFourElements.roofRC.thermCapExt[1].T >= 0.0)";
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo",5,3,6,29,0};
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta119));
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        } else {
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo",5,3,6,29,0};
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta119));
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
        }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
      tmp120 = 1;
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
    }
#line 5 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  }
#line 1384 OMC_FILE
  TRACE_POP
}

/*
equation index: 1585
type: ALGORITHM

  assert(eqAirTemp.TEqWall[1] >= 0.0, "Variable violating min constraint: 0.0 <= eqAirTemp.TEqWall[1], has value: " + String(eqAirTemp.TEqWall[1], "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1585(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1585};
  modelica_boolean tmp121;
  static const MMC_DEFSTRINGLIT(tmp122,75,"Variable violating min constraint: 0.0 <= eqAirTemp.TEqWall[1], has value: ");
  modelica_string tmp123;
  modelica_metatype tmpMeta124;
  static int tmp125 = 0;
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  if(!tmp125)
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    tmp121 = GreaterEq((data->localData[0]->realVars[186] /* eqAirTemp.TEqWall[1] variable */),0.0);
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    if(!tmp121)
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp123 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[186] /* eqAirTemp.TEqWall[1] variable */), (modelica_string) mmc_strings_len1[103]);
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmpMeta124 = stringAppend(MMC_REFSTRINGLIT(tmp122),tmp123);
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        const char* assert_cond = "(eqAirTemp.TEqWall[1] >= 0.0)";
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",22,3,22,73,0};
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta124));
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        } else {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",22,3,22,73,0};
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta124));
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        }
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      }
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp125 = 1;
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  }
#line 1443 OMC_FILE
  TRACE_POP
}

/*
equation index: 1586
type: ALGORITHM

  assert(eqAirTemp.TEqWall[2] >= 0.0, "Variable violating min constraint: 0.0 <= eqAirTemp.TEqWall[2], has value: " + String(eqAirTemp.TEqWall[2], "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1586(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1586};
  modelica_boolean tmp126;
  static const MMC_DEFSTRINGLIT(tmp127,75,"Variable violating min constraint: 0.0 <= eqAirTemp.TEqWall[2], has value: ");
  modelica_string tmp128;
  modelica_metatype tmpMeta129;
  static int tmp130 = 0;
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  if(!tmp130)
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    tmp126 = GreaterEq((data->localData[0]->realVars[187] /* eqAirTemp.TEqWall[2] variable */),0.0);
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    if(!tmp126)
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp128 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[187] /* eqAirTemp.TEqWall[2] variable */), (modelica_string) mmc_strings_len1[103]);
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmpMeta129 = stringAppend(MMC_REFSTRINGLIT(tmp127),tmp128);
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        const char* assert_cond = "(eqAirTemp.TEqWall[2] >= 0.0)";
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",22,3,22,73,0};
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta129));
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        } else {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",22,3,22,73,0};
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta129));
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        }
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      }
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp130 = 1;
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  }
#line 1502 OMC_FILE
  TRACE_POP
}

/*
equation index: 1587
type: ALGORITHM

  assert(eqAirTemp.TEqWin[2] >= 0.0, "Variable violating min constraint: 0.0 <= eqAirTemp.TEqWin[2], has value: " + String(eqAirTemp.TEqWin[2], "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1587(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1587};
  modelica_boolean tmp131;
  static const MMC_DEFSTRINGLIT(tmp132,74,"Variable violating min constraint: 0.0 <= eqAirTemp.TEqWin[2], has value: ");
  modelica_string tmp133;
  modelica_metatype tmpMeta134;
  static int tmp135 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  if(!tmp135)
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    tmp131 = GreaterEq((data->localData[0]->realVars[189] /* eqAirTemp.TEqWin[2] variable */),0.0);
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    if(!tmp131)
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp133 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[189] /* eqAirTemp.TEqWin[2] variable */), (modelica_string) mmc_strings_len1[103]);
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmpMeta134 = stringAppend(MMC_REFSTRINGLIT(tmp132),tmp133);
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        const char* assert_cond = "(eqAirTemp.TEqWin[2] >= 0.0)";
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",23,3,23,74,0};
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta134));
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",23,3,23,74,0};
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta134));
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp135 = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  }
#line 1561 OMC_FILE
  TRACE_POP
}

/*
equation index: 1588
type: ALGORITHM

  assert(preTem.T >= 0.0, "Variable violating min constraint: 0.0 <= preTem.T, has value: " + String(preTem.T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1588(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1588};
  modelica_boolean tmp136;
  static const MMC_DEFSTRINGLIT(tmp137,63,"Variable violating min constraint: 0.0 <= preTem.T, has value: ");
  modelica_string tmp138;
  modelica_metatype tmpMeta139;
  static int tmp140 = 0;
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
  if(!tmp140)
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
  {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
    tmp136 = GreaterEq((data->localData[0]->realVars[204] /* preTem.T variable */),0.0);
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
    if(!tmp136)
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
    {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      tmp138 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[204] /* preTem.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      tmpMeta139 = stringAppend(MMC_REFSTRINGLIT(tmp137),tmp138);
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
        const char* assert_cond = "(preTem.T >= 0.0)";
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo",6,3,7,43,0};
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta139));
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
        } else {
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo",6,3,7,43,0};
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta139));
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
        }
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      }
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
      tmp140 = 1;
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
    }
#line 6 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Sources/PrescribedTemperature.mo"
  }
#line 1620 OMC_FILE
  TRACE_POP
}

/*
equation index: 1589
type: ALGORITHM

  assert(theConWin.solid.T >= 0.0, "Variable violating min constraint: 0.0 <= theConWin.solid.T, has value: " + String(theConWin.solid.T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1589(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1589};
  modelica_boolean tmp141;
  static const MMC_DEFSTRINGLIT(tmp142,72,"Variable violating min constraint: 0.0 <= theConWin.solid.T, has value: ");
  modelica_string tmp143;
  modelica_metatype tmpMeta144;
  static int tmp145 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp145)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp141 = GreaterEq((data->localData[0]->realVars[215] /* theConWin.solid.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp141)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp143 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[215] /* theConWin.solid.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta144 = stringAppend(MMC_REFSTRINGLIT(tmp142),tmp143);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(theConWin.solid.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta144));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta144));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp145 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 1679 OMC_FILE
  TRACE_POP
}

/*
equation index: 1590
type: ALGORITHM

  assert(eqAirTempVDI.TEqWall[1] >= 0.0, "Variable violating min constraint: 0.0 <= eqAirTempVDI.TEqWall[1], has value: " + String(eqAirTempVDI.TEqWall[1], "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1590(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1590};
  modelica_boolean tmp146;
  static const MMC_DEFSTRINGLIT(tmp147,78,"Variable violating min constraint: 0.0 <= eqAirTempVDI.TEqWall[1], has value: ");
  modelica_string tmp148;
  modelica_metatype tmpMeta149;
  static int tmp150 = 0;
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  if(!tmp150)
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    tmp146 = GreaterEq((data->localData[0]->realVars[193] /* eqAirTempVDI.TEqWall[1] variable */),0.0);
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    if(!tmp146)
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp148 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[193] /* eqAirTempVDI.TEqWall[1] variable */), (modelica_string) mmc_strings_len1[103]);
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmpMeta149 = stringAppend(MMC_REFSTRINGLIT(tmp147),tmp148);
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        const char* assert_cond = "(eqAirTempVDI.TEqWall[1] >= 0.0)";
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",22,3,22,73,0};
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta149));
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        } else {
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",22,3,22,73,0};
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta149));
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        }
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      }
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp150 = 1;
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  }
#line 1738 OMC_FILE
  TRACE_POP
}

/*
equation index: 1591
type: ALGORITHM

  assert(eqAirTempVDI.TEqWin[1] >= 0.0, "Variable violating min constraint: 0.0 <= eqAirTempVDI.TEqWin[1], has value: " + String(eqAirTempVDI.TEqWin[1], "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1591(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1591};
  modelica_boolean tmp151;
  static const MMC_DEFSTRINGLIT(tmp152,77,"Variable violating min constraint: 0.0 <= eqAirTempVDI.TEqWin[1], has value: ");
  modelica_string tmp153;
  modelica_metatype tmpMeta154;
  static int tmp155 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  if(!tmp155)
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    tmp151 = GreaterEq((data->localData[0]->realVars[194] /* eqAirTempVDI.TEqWin[1] variable */),0.0);
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    if(!tmp151)
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp153 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[194] /* eqAirTempVDI.TEqWin[1] variable */), (modelica_string) mmc_strings_len1[103]);
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmpMeta154 = stringAppend(MMC_REFSTRINGLIT(tmp152),tmp153);
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        const char* assert_cond = "(eqAirTempVDI.TEqWin[1] >= 0.0)";
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",23,3,23,74,0};
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta154));
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo",23,3,23,74,0};
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta154));
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
      tmp155 = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  }
#line 1797 OMC_FILE
  TRACE_POP
}

/*
equation index: 1592
type: ALGORITHM

  assert(theConRoof.solid.T >= 0.0, "Variable violating min constraint: 0.0 <= theConRoof.solid.T, has value: " + String(theConRoof.solid.T, "g"));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1592(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1592};
  modelica_boolean tmp156;
  static const MMC_DEFSTRINGLIT(tmp157,73,"Variable violating min constraint: 0.0 <= theConRoof.solid.T, has value: ");
  modelica_string tmp158;
  modelica_metatype tmpMeta159;
  static int tmp160 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp160)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp156 = GreaterEq((data->localData[0]->realVars[210] /* theConRoof.solid.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp156)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp158 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[210] /* theConRoof.solid.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta159 = stringAppend(MMC_REFSTRINGLIT(tmp157),tmp158);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(theConRoof.solid.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta159));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta159));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp160 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 1856 OMC_FILE
  TRACE_POP
}
/* function to check assert after a step is done */
OMC_DISABLE_OPT
int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1562(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1563(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1564(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1565(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1566(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1567(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1568(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1569(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1570(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1571(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1572(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1573(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1574(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1575(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1576(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1577(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1578(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1579(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1580(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1581(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1582(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1583(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1584(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1585(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1586(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1587(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1588(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1589(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1590(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1591(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1592(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

