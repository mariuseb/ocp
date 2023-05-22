#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustom/Buildings_HeatTransfer_Windows_Examples_WindowCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustom_08bnd.c"
#endif
/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}

void Buildings_HeatTransfer_Windows_Examples_WindowCustom_updateBoundParameters_0(DATA *data, threadData_t *threadData);
extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_8(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_7(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_6(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_5(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_4(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_3(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_2(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_1(DATA *data, threadData_t *threadData);


/*
equation index: 497
type: ALGORITHM

  assert(intShaCon.conWinUns.conMod >= Buildings.HeatTransfer.Types.InteriorConvection.Fixed and intShaCon.conWinUns.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature, "Variable violating min/max constraint: Buildings.HeatTransfer.Types.InteriorConvection.Fixed <= intShaCon.conWinUns.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature, has value: " + String(intShaCon.conWinUns.conMod, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_497(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,497};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,198,"Variable violating min/max constraint: Buildings.HeatTransfer.Types.InteriorConvection.Fixed <= intShaCon.conWinUns.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  if(!tmp5)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    tmp0 = GreaterEq((data->simulationInfo->integerParameter[2] /* intShaCon.conWinUns.conMod PARAM */),1);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    tmp1 = LessEq((data->simulationInfo->integerParameter[2] /* intShaCon.conWinUns.conMod PARAM */),2);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    if(!(tmp0 && tmp1))
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      tmp3 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[2] /* intShaCon.conWinUns.conMod PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
        const char* assert_cond = "(intShaCon.conWinUns.conMod >= Buildings.HeatTransfer.Types.InteriorConvection.Fixed and intShaCon.conWinUns.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature)";
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo",9,3,12,28,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
        } else {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo",9,3,12,28,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
        }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      tmp5 = 1;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  }
#line 116 OMC_FILE
  TRACE_POP
}

/*
equation index: 498
type: ALGORITHM

  assert(intShaCon.conFra.conMod >= Buildings.HeatTransfer.Types.InteriorConvection.Fixed and intShaCon.conFra.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature, "Variable violating min/max constraint: Buildings.HeatTransfer.Types.InteriorConvection.Fixed <= intShaCon.conFra.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature, has value: " + String(intShaCon.conFra.conMod, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_498(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,498};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  static const MMC_DEFSTRINGLIT(tmp8,195,"Variable violating min/max constraint: Buildings.HeatTransfer.Types.InteriorConvection.Fixed <= intShaCon.conFra.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature, has value: ");
  modelica_string tmp9;
  modelica_metatype tmpMeta10;
  static int tmp11 = 0;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  if(!tmp11)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    tmp6 = GreaterEq((data->simulationInfo->integerParameter[0] /* intShaCon.conFra.conMod PARAM */),1);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    tmp7 = LessEq((data->simulationInfo->integerParameter[0] /* intShaCon.conFra.conMod PARAM */),2);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    if(!(tmp6 && tmp7))
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      tmp9 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* intShaCon.conFra.conMod PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      tmpMeta10 = stringAppend(MMC_REFSTRINGLIT(tmp8),tmp9);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
        const char* assert_cond = "(intShaCon.conFra.conMod >= Buildings.HeatTransfer.Types.InteriorConvection.Fixed and intShaCon.conFra.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature)";
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo",9,3,12,28,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
        } else {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo",9,3,12,28,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
        }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
      tmp11 = 1;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
    }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  }
#line 179 OMC_FILE
  TRACE_POP
}

/*
equation index: 499
type: ALGORITHM

  assert(intShaCon.conSha.k >= 0.0 and intShaCon.conSha.k <= 1.0, "Variable violating min/max constraint: 0.0 <= intShaCon.conSha.k <= 1.0, has value: " + String(intShaCon.conSha.k, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_499(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,499};
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  static const MMC_DEFSTRINGLIT(tmp14,84,"Variable violating min/max constraint: 0.0 <= intShaCon.conSha.k <= 1.0, has value: ");
  modelica_string tmp15;
  modelica_metatype tmpMeta16;
  static int tmp17 = 0;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  if(!tmp17)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    tmp12 = GreaterEq((data->simulationInfo->realParameter[79] /* intShaCon.conSha.k PARAM */),0.0);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    tmp13 = LessEq((data->simulationInfo->realParameter[79] /* intShaCon.conSha.k PARAM */),1.0);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    if(!(tmp12 && tmp13))
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      tmp15 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[79] /* intShaCon.conSha.k PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      tmpMeta16 = stringAppend(MMC_REFSTRINGLIT(tmp14),tmp15);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
        const char* assert_cond = "(intShaCon.conSha.k >= 0.0 and intShaCon.conSha.k <= 1.0)";
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo",9,3,10,67,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta16));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
        } else {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo",9,3,10,67,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta16));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
        }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      tmp17 = 1;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  }
#line 242 OMC_FILE
  TRACE_POP
}

/*
equation index: 500
type: ALGORITHM

  assert(intShaCon.conMod >= Buildings.HeatTransfer.Types.InteriorConvection.Fixed and intShaCon.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature, "Variable violating min/max constraint: Buildings.HeatTransfer.Types.InteriorConvection.Fixed <= intShaCon.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature, has value: " + String(intShaCon.conMod, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_500(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,500};
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  static const MMC_DEFSTRINGLIT(tmp20,188,"Variable violating min/max constraint: Buildings.HeatTransfer.Types.InteriorConvection.Fixed <= intShaCon.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature, has value: ");
  modelica_string tmp21;
  modelica_metatype tmpMeta22;
  static int tmp23 = 0;
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
  if(!tmp23)
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
  {
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
    tmp18 = GreaterEq((data->simulationInfo->integerParameter[1] /* intShaCon.conMod PARAM */),1);
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
    tmp19 = LessEq((data->simulationInfo->integerParameter[1] /* intShaCon.conMod PARAM */),2);
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
    if(!(tmp18 && tmp19))
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
    {
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
      tmp21 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[1] /* intShaCon.conMod PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
      tmpMeta22 = stringAppend(MMC_REFSTRINGLIT(tmp20),tmp21);
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
      {
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
        const char* assert_cond = "(intShaCon.conMod >= Buildings.HeatTransfer.Types.InteriorConvection.Fixed and intShaCon.conMod <= Buildings.HeatTransfer.Types.InteriorConvection.Temperature)";
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo",8,3,9,37,0};
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta22));
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
        } else {
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo",8,3,9,37,0};
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta22));
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
        }
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
      }
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
      tmp23 = 1;
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
    }
#line 8 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/InteriorHeatTransferConvective.mo"
  }
#line 305 OMC_FILE
  TRACE_POP
}

/*
equation index: 501
type: ALGORITHM

  assert(intShaRad.T03 >= 0.0, "Variable violating min constraint: 0.0 <= intShaRad.T03, has value: " + String(intShaRad.T03, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_501(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,501};
  modelica_boolean tmp24;
  static const MMC_DEFSTRINGLIT(tmp25,68,"Variable violating min constraint: 0.0 <= intShaRad.T03, has value: ");
  modelica_string tmp26;
  modelica_metatype tmpMeta27;
  static int tmp28 = 0;
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp28)
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp24 = GreaterEq((data->simulationInfo->realParameter[90] /* intShaRad.T03 PARAM */),0.0);
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!tmp24)
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp26 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[90] /* intShaRad.T03 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta27 = stringAppend(MMC_REFSTRINGLIT(tmp25),tmp26);
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(intShaRad.T03 >= 0.0)";
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",84,2,85,34,0};
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta27));
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",84,2,85,34,0};
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta27));
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp28 = 1;
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 365 OMC_FILE
  TRACE_POP
}

/*
equation index: 502
type: ALGORITHM

  assert(intShaRad.T0 >= 0.0, "Variable violating min constraint: 0.0 <= intShaRad.T0, has value: " + String(intShaRad.T0, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_502(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,502};
  modelica_boolean tmp29;
  static const MMC_DEFSTRINGLIT(tmp30,67,"Variable violating min constraint: 0.0 <= intShaRad.T0, has value: ");
  modelica_string tmp31;
  modelica_metatype tmpMeta32;
  static int tmp33 = 0;
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp33)
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp29 = GreaterEq((data->simulationInfo->realParameter[89] /* intShaRad.T0 PARAM */),0.0);
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!tmp29)
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp31 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[89] /* intShaRad.T0 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta32 = stringAppend(MMC_REFSTRINGLIT(tmp30),tmp31);
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(intShaRad.T0 >= 0.0)";
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",27,3,29,42,0};
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta32));
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",27,3,29,42,0};
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta32));
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp33 = 1;
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 425 OMC_FILE
  TRACE_POP
}

/*
equation index: 503
type: ALGORITHM

  assert(glaSys.gas[1].MM >= 0.0, "Variable violating min constraint: 0.0 <= glaSys.gas[1].MM, has value: " + String(glaSys.gas[1].MM, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_503(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,503};
  modelica_boolean tmp34;
  static const MMC_DEFSTRINGLIT(tmp35,71,"Variable violating min constraint: 0.0 <= glaSys.gas[1].MM, has value: ");
  modelica_string tmp36;
  modelica_metatype tmpMeta37;
  static int tmp38 = 0;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp38)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp34 = GreaterEq((data->simulationInfo->realParameter[37] /* glaSys.gas[1].MM PARAM */),0.0);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp34)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp36 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[37] /* glaSys.gas[1].MM PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta37 = stringAppend(MMC_REFSTRINGLIT(tmp35),tmp36);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(glaSys.gas[1].MM >= 0.0)";
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta37));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta37));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp38 = 1;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 485 OMC_FILE
  TRACE_POP
}

/*
equation index: 504
type: ALGORITHM

  assert(glaSys.gas[1].a_mu >= 0.0, "Variable violating min constraint: 0.0 <= glaSys.gas[1].a_mu, has value: " + String(glaSys.gas[1].a_mu, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_504(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,504};
  modelica_boolean tmp39;
  static const MMC_DEFSTRINGLIT(tmp40,73,"Variable violating min constraint: 0.0 <= glaSys.gas[1].a_mu, has value: ");
  modelica_string tmp41;
  modelica_metatype tmpMeta42;
  static int tmp43 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp43)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp39 = GreaterEq((data->simulationInfo->realParameter[41] /* glaSys.gas[1].a_mu PARAM */),0.0);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp39)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp41 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[41] /* glaSys.gas[1].a_mu PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta42 = stringAppend(MMC_REFSTRINGLIT(tmp40),tmp41);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(glaSys.gas[1].a_mu >= 0.0)";
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta42));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta42));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp43 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 545 OMC_FILE
  TRACE_POP
}

/*
equation index: 505
type: ALGORITHM

  assert(indRad.T04 >= 0.0, "Variable violating min constraint: 0.0 <= indRad.T04, has value: " + String(indRad.T04, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_505(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,505};
  modelica_boolean tmp44;
  static const MMC_DEFSTRINGLIT(tmp45,65,"Variable violating min constraint: 0.0 <= indRad.T04, has value: ");
  modelica_string tmp46;
  modelica_metatype tmpMeta47;
  static int tmp48 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
  if(!tmp48)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
    tmp44 = GreaterEq((data->simulationInfo->realParameter[65] /* indRad.T04 PARAM */),0.0);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
    if(!tmp44)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      tmp46 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[65] /* indRad.T04 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      tmpMeta47 = stringAppend(MMC_REFSTRINGLIT(tmp45),tmp46);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
        const char* assert_cond = "(indRad.T04 >= 0.0)";
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo",12,3,14,58,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta47));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo",12,3,14,58,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta47));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      tmp48 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
  }
#line 605 OMC_FILE
  TRACE_POP
}

/*
equation index: 506
type: ALGORITHM

  assert(indRad.T03 >= 0.0, "Variable violating min constraint: 0.0 <= indRad.T03, has value: " + String(indRad.T03, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,506};
  modelica_boolean tmp49;
  static const MMC_DEFSTRINGLIT(tmp50,65,"Variable violating min constraint: 0.0 <= indRad.T03, has value: ");
  modelica_string tmp51;
  modelica_metatype tmpMeta52;
  static int tmp53 = 0;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
  if(!tmp53)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
    tmp49 = GreaterEq((data->simulationInfo->realParameter[64] /* indRad.T03 PARAM */),0.0);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
    if(!tmp49)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      tmp51 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[64] /* indRad.T03 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      tmpMeta52 = stringAppend(MMC_REFSTRINGLIT(tmp50),tmp51);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
        const char* assert_cond = "(indRad.T03 >= 0.0)";
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo",14,2,14,79,0};
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
        } else {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo",14,2,14,79,0};
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
        }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      tmp53 = 1;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
  }
#line 665 OMC_FILE
  TRACE_POP
}

/*
equation index: 507
type: ALGORITHM

  assert(indRad.T0 >= 0.0, "Variable violating min constraint: 0.0 <= indRad.T0, has value: " + String(indRad.T0, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_507(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,507};
  modelica_boolean tmp54;
  static const MMC_DEFSTRINGLIT(tmp55,64,"Variable violating min constraint: 0.0 <= indRad.T0, has value: ");
  modelica_string tmp56;
  modelica_metatype tmpMeta57;
  static int tmp58 = 0;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
  if(!tmp58)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
  {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
    tmp54 = GreaterEq((data->simulationInfo->realParameter[63] /* indRad.T0 PARAM */),0.0);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
    if(!tmp54)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
    {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      tmp56 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[63] /* indRad.T0 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      tmpMeta57 = stringAppend(MMC_REFSTRINGLIT(tmp55),tmp56);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
        const char* assert_cond = "(indRad.T0 >= 0.0)";
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo",10,3,12,42,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta57));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
        } else {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo",10,3,12,42,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta57));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
        }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
      tmp58 = 1;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
    }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersOneSurface.mo"
  }
#line 725 OMC_FILE
  TRACE_POP
}

/*
equation index: 508
type: ALGORITHM

  assert(uSha.duration >= 0.0, "Variable violating min constraint: 0.0 <= uSha.duration, has value: " + String(uSha.duration, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_508(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,508};
  modelica_boolean tmp59;
  static const MMC_DEFSTRINGLIT(tmp60,68,"Variable violating min constraint: 0.0 <= uSha.duration, has value: ");
  modelica_string tmp61;
  modelica_metatype tmpMeta62;
  static int tmp63 = 0;
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  if(!tmp63)
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  {
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp59 = GreaterEq((data->simulationInfo->realParameter[100] /* uSha.duration PARAM */),0.0);
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    if(!tmp59)
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    {
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp61 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[100] /* uSha.duration PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmpMeta62 = stringAppend(MMC_REFSTRINGLIT(tmp60),tmp61);
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      {
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        const char* assert_cond = "(uSha.duration >= 0.0)";
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",247,5,248,46,0};
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta62));
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        } else {
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",247,5,248,46,0};
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta62));
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
        }
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      }
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
      tmp63 = 1;
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    }
#line 247 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  }
#line 785 OMC_FILE
  TRACE_POP
}

/*
equation index: 509
type: ALGORITHM

  assert(extCon.shaCon.k >= 0.0 and extCon.shaCon.k <= 1.0, "Variable violating min/max constraint: 0.0 <= extCon.shaCon.k <= 1.0, has value: " + String(extCon.shaCon.k, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_509(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,509};
  modelica_boolean tmp64;
  modelica_boolean tmp65;
  static const MMC_DEFSTRINGLIT(tmp66,81,"Variable violating min/max constraint: 0.0 <= extCon.shaCon.k <= 1.0, has value: ");
  modelica_string tmp67;
  modelica_metatype tmpMeta68;
  static int tmp69 = 0;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  if(!tmp69)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    tmp64 = GreaterEq((data->simulationInfo->realParameter[20] /* extCon.shaCon.k PARAM */),0.0);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    tmp65 = LessEq((data->simulationInfo->realParameter[20] /* extCon.shaCon.k PARAM */),1.0);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    if(!(tmp64 && tmp65))
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      tmp67 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[20] /* extCon.shaCon.k PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      tmpMeta68 = stringAppend(MMC_REFSTRINGLIT(tmp66),tmp67);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
        const char* assert_cond = "(extCon.shaCon.k >= 0.0 and extCon.shaCon.k <= 1.0)";
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo",9,3,10,67,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
        } else {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo",9,3,10,67,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
        }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
      tmp69 = 1;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
    }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  }
#line 848 OMC_FILE
  TRACE_POP
}

/*
equation index: 510
type: ALGORITHM

  assert(extCon.shaRad.T03 >= 0.0, "Variable violating min constraint: 0.0 <= extCon.shaRad.T03, has value: " + String(extCon.shaRad.T03, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_510(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,510};
  modelica_boolean tmp70;
  static const MMC_DEFSTRINGLIT(tmp71,72,"Variable violating min constraint: 0.0 <= extCon.shaRad.T03, has value: ");
  modelica_string tmp72;
  modelica_metatype tmpMeta73;
  static int tmp74 = 0;
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp74)
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp70 = GreaterEq((data->simulationInfo->realParameter[23] /* extCon.shaRad.T03 PARAM */),0.0);
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!tmp70)
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp72 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[23] /* extCon.shaRad.T03 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta73 = stringAppend(MMC_REFSTRINGLIT(tmp71),tmp72);
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(extCon.shaRad.T03 >= 0.0)";
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",84,2,85,34,0};
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta73));
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",84,2,85,34,0};
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta73));
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp74 = 1;
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 84 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 908 OMC_FILE
  TRACE_POP
}

/*
equation index: 511
type: ALGORITHM

  assert(extCon.shaRad.T0 >= 0.0, "Variable violating min constraint: 0.0 <= extCon.shaRad.T0, has value: " + String(extCon.shaRad.T0, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_511(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,511};
  modelica_boolean tmp75;
  static const MMC_DEFSTRINGLIT(tmp76,71,"Variable violating min constraint: 0.0 <= extCon.shaRad.T0, has value: ");
  modelica_string tmp77;
  modelica_metatype tmpMeta78;
  static int tmp79 = 0;
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp79)
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp75 = GreaterEq((data->simulationInfo->realParameter[22] /* extCon.shaRad.T0 PARAM */),0.0);
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!tmp75)
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp77 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[22] /* extCon.shaRad.T0 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta78 = stringAppend(MMC_REFSTRINGLIT(tmp76),tmp77);
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(extCon.shaRad.T0 >= 0.0)";
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",27,3,29,42,0};
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta78));
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",27,3,29,42,0};
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta78));
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp79 = 1;
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 968 OMC_FILE
  TRACE_POP
}

/*
equation index: 512
type: ALGORITHM

  assert(extCon.radOut.T04 >= 0.0, "Variable violating min constraint: 0.0 <= extCon.radOut.T04, has value: " + String(extCon.radOut.T04, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_512(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,512};
  modelica_boolean tmp80;
  static const MMC_DEFSTRINGLIT(tmp81,72,"Variable violating min constraint: 0.0 <= extCon.radOut.T04, has value: ");
  modelica_string tmp82;
  modelica_metatype tmpMeta83;
  static int tmp84 = 0;
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  if(!tmp84)
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    tmp80 = GreaterEq((data->simulationInfo->realParameter[17] /* extCon.radOut.T04 PARAM */),0.0);
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    if(!tmp80)
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp82 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[17] /* extCon.radOut.T04 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmpMeta83 = stringAppend(MMC_REFSTRINGLIT(tmp81),tmp82);
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        const char* assert_cond = "(extCon.radOut.T04 >= 0.0)";
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",35,3,37,58,0};
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta83));
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        } else {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",35,3,37,58,0};
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta83));
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        }
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      }
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp84 = 1;
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    }
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  }
#line 1028 OMC_FILE
  TRACE_POP
}

/*
equation index: 513
type: ALGORITHM

  assert(extCon.radOut.T03 >= 0.0, "Variable violating min constraint: 0.0 <= extCon.radOut.T03, has value: " + String(extCon.radOut.T03, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_513(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,513};
  modelica_boolean tmp85;
  static const MMC_DEFSTRINGLIT(tmp86,72,"Variable violating min constraint: 0.0 <= extCon.radOut.T03, has value: ");
  modelica_string tmp87;
  modelica_metatype tmpMeta88;
  static int tmp89 = 0;
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  if(!tmp89)
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  {
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    tmp85 = GreaterEq((data->simulationInfo->realParameter[16] /* extCon.radOut.T03 PARAM */),0.0);
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    if(!tmp85)
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    {
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp87 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[16] /* extCon.radOut.T03 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmpMeta88 = stringAppend(MMC_REFSTRINGLIT(tmp86),tmp87);
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      {
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        const char* assert_cond = "(extCon.radOut.T03 >= 0.0)";
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",32,3,34,58,0};
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta88));
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        } else {
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",32,3,34,58,0};
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta88));
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        }
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      }
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp89 = 1;
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    }
#line 32 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  }
#line 1088 OMC_FILE
  TRACE_POP
}

/*
equation index: 514
type: ALGORITHM

  assert(extCon.radOut.T0 >= 0.0, "Variable violating min constraint: 0.0 <= extCon.radOut.T0, has value: " + String(extCon.radOut.T0, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_514(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,514};
  modelica_boolean tmp90;
  static const MMC_DEFSTRINGLIT(tmp91,71,"Variable violating min constraint: 0.0 <= extCon.radOut.T0, has value: ");
  modelica_string tmp92;
  modelica_metatype tmpMeta93;
  static int tmp94 = 0;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  if(!tmp94)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    tmp90 = GreaterEq((data->simulationInfo->realParameter[15] /* extCon.radOut.T0 PARAM */),0.0);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    if(!tmp90)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp92 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[15] /* extCon.radOut.T0 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmpMeta93 = stringAppend(MMC_REFSTRINGLIT(tmp91),tmp92);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        const char* assert_cond = "(extCon.radOut.T0 >= 0.0)";
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",9,3,11,42,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta93));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        } else {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",9,3,11,42,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta93));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp94 = 1;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  }
#line 1148 OMC_FILE
  TRACE_POP
}

/*
equation index: 515
type: ALGORITHM

  assert(extCon.radOut.vieFacSky >= 0.0 and extCon.radOut.vieFacSky <= 1.0, "Variable violating min/max constraint: 0.0 <= extCon.radOut.vieFacSky <= 1.0, has value: " + String(extCon.radOut.vieFacSky, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_515(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,515};
  modelica_boolean tmp95;
  modelica_boolean tmp96;
  static const MMC_DEFSTRINGLIT(tmp97,89,"Variable violating min/max constraint: 0.0 <= extCon.radOut.vieFacSky <= 1.0, has value: ");
  modelica_string tmp98;
  modelica_metatype tmpMeta99;
  static int tmp100 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  if(!tmp100)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    tmp95 = GreaterEq((data->simulationInfo->realParameter[18] /* extCon.radOut.vieFacSky PARAM */),0.0);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    tmp96 = LessEq((data->simulationInfo->realParameter[18] /* extCon.radOut.vieFacSky PARAM */),1.0);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    if(!(tmp95 && tmp96))
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp98 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[18] /* extCon.radOut.vieFacSky PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmpMeta99 = stringAppend(MMC_REFSTRINGLIT(tmp97),tmp98);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        const char* assert_cond = "(extCon.radOut.vieFacSky >= 0.0 and extCon.radOut.vieFacSky <= 1.0)";
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",5,3,6,63,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta99));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",5,3,6,63,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta99));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp100 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  }
#line 1211 OMC_FILE
  TRACE_POP
}

/*
equation index: 516
type: ALGORITHM

  assert(extCon.vieFacSky >= 0.0 and extCon.vieFacSky <= 1.0, "Variable violating min/max constraint: 0.0 <= extCon.vieFacSky <= 1.0, has value: " + String(extCon.vieFacSky, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_516(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,516};
  modelica_boolean tmp101;
  modelica_boolean tmp102;
  static const MMC_DEFSTRINGLIT(tmp103,82,"Variable violating min/max constraint: 0.0 <= extCon.vieFacSky <= 1.0, has value: ");
  modelica_string tmp104;
  modelica_metatype tmpMeta105;
  static int tmp106 = 0;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  if(!tmp106)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    tmp101 = GreaterEq((data->simulationInfo->realParameter[32] /* extCon.vieFacSky PARAM */),0.0);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    tmp102 = LessEq((data->simulationInfo->realParameter[32] /* extCon.vieFacSky PARAM */),1.0);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    if(!(tmp101 && tmp102))
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp104 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[32] /* extCon.vieFacSky PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmpMeta105 = stringAppend(MMC_REFSTRINGLIT(tmp103),tmp104);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        const char* assert_cond = "(extCon.vieFacSky >= 0.0 and extCon.vieFacSky <= 1.0)";
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",21,3,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta105));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        } else {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",21,3,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta105));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp106 = 1;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  }
#line 1274 OMC_FILE
  TRACE_POP
}

/*
equation index: 517
type: ALGORITHM

  assert(window.matGla.TLiq >= 0.0, "Variable violating min constraint: 0.0 <= window.matGla.TLiq, has value: " + String(window.matGla.TLiq, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_517(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,517};
  modelica_boolean tmp107;
  static const MMC_DEFSTRINGLIT(tmp108,73,"Variable violating min constraint: 0.0 <= window.matGla.TLiq, has value: ");
  modelica_string tmp109;
  modelica_metatype tmpMeta110;
  static int tmp111 = 0;
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp111)
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp107 = GreaterEq((data->simulationInfo->realParameter[234] /* window.matGla.TLiq PARAM */),0.0);
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp107)
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp109 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[234] /* window.matGla.TLiq PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta110 = stringAppend(MMC_REFSTRINGLIT(tmp108),tmp109);
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matGla.TLiq >= 0.0)";
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",33,5,35,72,0};
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta110));
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",33,5,35,72,0};
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta110));
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp111 = 1;
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1334 OMC_FILE
  TRACE_POP
}

/*
equation index: 518
type: ALGORITHM

  assert(window.matGla.TSol >= 0.0, "Variable violating min constraint: 0.0 <= window.matGla.TSol, has value: " + String(window.matGla.TSol, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,518};
  modelica_boolean tmp112;
  static const MMC_DEFSTRINGLIT(tmp113,73,"Variable violating min constraint: 0.0 <= window.matGla.TSol, has value: ");
  modelica_string tmp114;
  modelica_metatype tmpMeta115;
  static int tmp116 = 0;
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp116)
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp112 = GreaterEq((data->simulationInfo->realParameter[235] /* window.matGla.TSol PARAM */),0.0);
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp112)
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp114 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[235] /* window.matGla.TSol PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta115 = stringAppend(MMC_REFSTRINGLIT(tmp113),tmp114);
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matGla.TSol >= 0.0)";
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",30,5,32,72,0};
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta115));
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",30,5,32,72,0};
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta115));
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp116 = 1;
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1394 OMC_FILE
  TRACE_POP
}

/*
equation index: 519
type: ALGORITHM

  assert(window.matGla.nStaReal >= 0.0, "Variable violating min constraint: 0.0 <= window.matGla.nStaReal, has value: " + String(window.matGla.nStaReal, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_519(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,519};
  modelica_boolean tmp117;
  static const MMC_DEFSTRINGLIT(tmp118,77,"Variable violating min constraint: 0.0 <= window.matGla.nStaReal, has value: ");
  modelica_string tmp119;
  modelica_metatype tmpMeta120;
  static int tmp121 = 0;
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp121)
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp117 = GreaterEq((data->simulationInfo->realParameter[239] /* window.matGla.nStaReal PARAM */),0.0);
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp117)
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp119 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[239] /* window.matGla.nStaReal PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta120 = stringAppend(MMC_REFSTRINGLIT(tmp118),tmp119);
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matGla.nStaReal >= 0.0)";
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",26,5,28,42,0};
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta120));
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",26,5,28,42,0};
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta120));
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp121 = 1;
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1454 OMC_FILE
  TRACE_POP
}

/*
equation index: 520
type: ALGORITHM

  assert(window.matGla.nSta >= 1, "Variable violating min constraint: 1 <= window.matGla.nSta, has value: " + String(window.matGla.nSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_520(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,520};
  modelica_boolean tmp122;
  static const MMC_DEFSTRINGLIT(tmp123,71,"Variable violating min constraint: 1 <= window.matGla.nSta, has value: ");
  modelica_string tmp124;
  modelica_metatype tmpMeta125;
  static int tmp126 = 0;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp126)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp122 = GreaterEq((data->simulationInfo->integerParameter[8] /* window.matGla.nSta PARAM */),((modelica_integer) 1));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp122)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp124 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[8] /* window.matGla.nSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta125 = stringAppend(MMC_REFSTRINGLIT(tmp123),tmp124);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matGla.nSta >= 1)";
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",14,5,16,56,0};
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta125));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",14,5,16,56,0};
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta125));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp126 = 1;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1514 OMC_FILE
  TRACE_POP
}

/*
equation index: 521
type: ALGORITHM

  assert(window.matGla.nStaRef >= 0, "Variable violating min constraint: 0 <= window.matGla.nStaRef, has value: " + String(window.matGla.nStaRef, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_521(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,521};
  modelica_boolean tmp127;
  static const MMC_DEFSTRINGLIT(tmp128,74,"Variable violating min constraint: 0 <= window.matGla.nStaRef, has value: ");
  modelica_string tmp129;
  modelica_metatype tmpMeta130;
  static int tmp131 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp131)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp127 = GreaterEq((data->simulationInfo->integerParameter[9] /* window.matGla.nStaRef PARAM */),((modelica_integer) 0));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp127)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp129 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[9] /* window.matGla.nStaRef PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta130 = stringAppend(MMC_REFSTRINGLIT(tmp128),tmp129);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matGla.nStaRef >= 0)";
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",12,5,13,76,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta130));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",12,5,13,76,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta130));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp131 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1574 OMC_FILE
  TRACE_POP
}

/*
equation index: 522
type: ALGORITHM

  assert(window.matGla.d >= 0.0, "Variable violating min constraint: 0.0 <= window.matGla.d, has value: " + String(window.matGla.d, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_522(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,522};
  modelica_boolean tmp132;
  static const MMC_DEFSTRINGLIT(tmp133,70,"Variable violating min constraint: 0.0 <= window.matGla.d, has value: ");
  modelica_string tmp134;
  modelica_metatype tmpMeta135;
  static int tmp136 = 0;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp136)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp132 = GreaterEq((data->simulationInfo->realParameter[237] /* window.matGla.d PARAM */),0.0);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp132)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp134 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[237] /* window.matGla.d PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta135 = stringAppend(MMC_REFSTRINGLIT(tmp133),tmp134);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matGla.d >= 0.0)";
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",9,5,9,57,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta135));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",9,5,9,57,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta135));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp136 = 1;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1634 OMC_FILE
  TRACE_POP
}

/*
equation index: 523
type: ALGORITHM

  assert(window.matFra.TLiq >= 0.0, "Variable violating min constraint: 0.0 <= window.matFra.TLiq, has value: " + String(window.matFra.TLiq, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_523(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,523};
  modelica_boolean tmp137;
  static const MMC_DEFSTRINGLIT(tmp138,73,"Variable violating min constraint: 0.0 <= window.matFra.TLiq, has value: ");
  modelica_string tmp139;
  modelica_metatype tmpMeta140;
  static int tmp141 = 0;
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp141)
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp137 = GreaterEq((data->simulationInfo->realParameter[223] /* window.matFra.TLiq PARAM */),0.0);
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp137)
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp139 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[223] /* window.matFra.TLiq PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta140 = stringAppend(MMC_REFSTRINGLIT(tmp138),tmp139);
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matFra.TLiq >= 0.0)";
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",33,5,35,72,0};
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta140));
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",33,5,35,72,0};
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta140));
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp141 = 1;
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 33 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1694 OMC_FILE
  TRACE_POP
}

/*
equation index: 524
type: ALGORITHM

  assert(window.matFra.TSol >= 0.0, "Variable violating min constraint: 0.0 <= window.matFra.TSol, has value: " + String(window.matFra.TSol, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_524(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,524};
  modelica_boolean tmp142;
  static const MMC_DEFSTRINGLIT(tmp143,73,"Variable violating min constraint: 0.0 <= window.matFra.TSol, has value: ");
  modelica_string tmp144;
  modelica_metatype tmpMeta145;
  static int tmp146 = 0;
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp146)
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp142 = GreaterEq((data->simulationInfo->realParameter[224] /* window.matFra.TSol PARAM */),0.0);
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp142)
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp144 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[224] /* window.matFra.TSol PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta145 = stringAppend(MMC_REFSTRINGLIT(tmp143),tmp144);
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matFra.TSol >= 0.0)";
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",30,5,32,72,0};
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta145));
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",30,5,32,72,0};
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta145));
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp146 = 1;
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 30 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1754 OMC_FILE
  TRACE_POP
}

/*
equation index: 525
type: ALGORITHM

  assert(window.matFra.nStaReal >= 0.0, "Variable violating min constraint: 0.0 <= window.matFra.nStaReal, has value: " + String(window.matFra.nStaReal, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_525(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,525};
  modelica_boolean tmp147;
  static const MMC_DEFSTRINGLIT(tmp148,77,"Variable violating min constraint: 0.0 <= window.matFra.nStaReal, has value: ");
  modelica_string tmp149;
  modelica_metatype tmpMeta150;
  static int tmp151 = 0;
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp151)
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp147 = GreaterEq((data->simulationInfo->realParameter[228] /* window.matFra.nStaReal PARAM */),0.0);
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp147)
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp149 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[228] /* window.matFra.nStaReal PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta150 = stringAppend(MMC_REFSTRINGLIT(tmp148),tmp149);
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matFra.nStaReal >= 0.0)";
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",26,5,28,42,0};
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta150));
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",26,5,28,42,0};
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta150));
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp151 = 1;
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1814 OMC_FILE
  TRACE_POP
}

/*
equation index: 526
type: ALGORITHM

  assert(window.matFra.nSta >= 1, "Variable violating min constraint: 1 <= window.matFra.nSta, has value: " + String(window.matFra.nSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_526(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,526};
  modelica_boolean tmp152;
  static const MMC_DEFSTRINGLIT(tmp153,71,"Variable violating min constraint: 1 <= window.matFra.nSta, has value: ");
  modelica_string tmp154;
  modelica_metatype tmpMeta155;
  static int tmp156 = 0;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp156)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp152 = GreaterEq((data->simulationInfo->integerParameter[6] /* window.matFra.nSta PARAM */),((modelica_integer) 1));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp152)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp154 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[6] /* window.matFra.nSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta155 = stringAppend(MMC_REFSTRINGLIT(tmp153),tmp154);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matFra.nSta >= 1)";
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",14,5,16,56,0};
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta155));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",14,5,16,56,0};
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta155));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp156 = 1;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1874 OMC_FILE
  TRACE_POP
}

/*
equation index: 527
type: ALGORITHM

  assert(window.matFra.nStaRef >= 0, "Variable violating min constraint: 0 <= window.matFra.nStaRef, has value: " + String(window.matFra.nStaRef, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_527(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,527};
  modelica_boolean tmp157;
  static const MMC_DEFSTRINGLIT(tmp158,74,"Variable violating min constraint: 0 <= window.matFra.nStaRef, has value: ");
  modelica_string tmp159;
  modelica_metatype tmpMeta160;
  static int tmp161 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp161)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp157 = GreaterEq((data->simulationInfo->integerParameter[7] /* window.matFra.nStaRef PARAM */),((modelica_integer) 0));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp157)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp159 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[7] /* window.matFra.nStaRef PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta160 = stringAppend(MMC_REFSTRINGLIT(tmp158),tmp159);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matFra.nStaRef >= 0)";
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",12,5,13,76,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta160));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",12,5,13,76,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta160));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp161 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1934 OMC_FILE
  TRACE_POP
}

/*
equation index: 528
type: ALGORITHM

  assert(window.matFra.d >= 0.0, "Variable violating min constraint: 0.0 <= window.matFra.d, has value: " + String(window.matFra.d, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_528(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,528};
  modelica_boolean tmp162;
  static const MMC_DEFSTRINGLIT(tmp163,70,"Variable violating min constraint: 0.0 <= window.matFra.d, has value: ");
  modelica_string tmp164;
  modelica_metatype tmpMeta165;
  static int tmp166 = 0;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  if(!tmp166)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    tmp162 = GreaterEq((data->simulationInfo->realParameter[226] /* window.matFra.d PARAM */),0.0);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    if(!tmp162)
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp164 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[226] /* window.matFra.d PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmpMeta165 = stringAppend(MMC_REFSTRINGLIT(tmp163),tmp164);
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        const char* assert_cond = "(window.matFra.d >= 0.0)";
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",9,5,9,57,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta165));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        } else {
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo",9,5,9,57,0};
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta165));
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
        }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
      tmp166 = 1;
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
    }
#line 9 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/BaseClasses.mo"
  }
#line 1994 OMC_FILE
  TRACE_POP
}

/*
equation index: 529
type: ALGORITHM

  assert(window.glaSha.glass[1].T04 >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSha.glass[1].T04, has value: " + String(window.glaSha.glass[1].T04, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_529(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,529};
  modelica_boolean tmp167;
  static const MMC_DEFSTRINGLIT(tmp168,81,"Variable violating min constraint: 0.0 <= window.glaSha.glass[1].T04, has value: ");
  modelica_string tmp169;
  modelica_metatype tmpMeta170;
  static int tmp171 = 0;
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  if(!tmp171)
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    tmp167 = GreaterEq((data->simulationInfo->realParameter[142] /* window.glaSha.glass[1].T04 PARAM */),0.0);
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    if(!tmp167)
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp169 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[142] /* window.glaSha.glass[1].T04 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmpMeta170 = stringAppend(MMC_REFSTRINGLIT(tmp168),tmp169);
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        const char* assert_cond = "(window.glaSha.glass[1].T04 >= 0.0)";
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",22,2,23,34,0};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta170));
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        } else {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",22,2,23,34,0};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta170));
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        }
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      }
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp171 = 1;
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  }
#line 2054 OMC_FILE
  TRACE_POP
}

/*
equation index: 530
type: ALGORITHM

  assert(window.glaSha.glass[1].T03 >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSha.glass[1].T03, has value: " + String(window.glaSha.glass[1].T03, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_530(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,530};
  modelica_boolean tmp172;
  static const MMC_DEFSTRINGLIT(tmp173,81,"Variable violating min constraint: 0.0 <= window.glaSha.glass[1].T03, has value: ");
  modelica_string tmp174;
  modelica_metatype tmpMeta175;
  static int tmp176 = 0;
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  if(!tmp176)
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    tmp172 = GreaterEq((data->simulationInfo->realParameter[141] /* window.glaSha.glass[1].T03 PARAM */),0.0);
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    if(!tmp172)
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp174 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[141] /* window.glaSha.glass[1].T03 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmpMeta175 = stringAppend(MMC_REFSTRINGLIT(tmp173),tmp174);
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        const char* assert_cond = "(window.glaSha.glass[1].T03 >= 0.0)";
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",20,2,21,34,0};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta175));
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        } else {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",20,2,21,34,0};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta175));
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        }
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      }
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp176 = 1;
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    }
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  }
#line 2114 OMC_FILE
  TRACE_POP
}

/*
equation index: 531
type: ALGORITHM

  assert(window.glaSha.glass[1].T0 >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSha.glass[1].T0, has value: " + String(window.glaSha.glass[1].T0, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_531(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,531};
  modelica_boolean tmp177;
  static const MMC_DEFSTRINGLIT(tmp178,80,"Variable violating min constraint: 0.0 <= window.glaSha.glass[1].T0, has value: ");
  modelica_string tmp179;
  modelica_metatype tmpMeta180;
  static int tmp181 = 0;
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  if(!tmp181)
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    tmp177 = GreaterEq((data->simulationInfo->realParameter[140] /* window.glaSha.glass[1].T0 PARAM */),0.0);
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    if(!tmp177)
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp179 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[140] /* window.glaSha.glass[1].T0 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmpMeta180 = stringAppend(MMC_REFSTRINGLIT(tmp178),tmp179);
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        const char* assert_cond = "(window.glaSha.glass[1].T0 >= 0.0)";
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",16,3,18,42,0};
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta180));
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        } else {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",16,3,18,42,0};
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta180));
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        }
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      }
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp181 = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  }
#line 2174 OMC_FILE
  TRACE_POP
}

/*
equation index: 532
type: ALGORITHM

  assert(window.glaSha.glaSys.gas[1].MM >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSha.glaSys.gas[1].MM, has value: " + String(window.glaSha.glaSys.gas[1].MM, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_532(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,532};
  modelica_boolean tmp182;
  static const MMC_DEFSTRINGLIT(tmp183,85,"Variable violating min constraint: 0.0 <= window.glaSha.glaSys.gas[1].MM, has value: ");
  modelica_string tmp184;
  modelica_metatype tmpMeta185;
  static int tmp186 = 0;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp186)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp182 = GreaterEq((data->simulationInfo->realParameter[113] /* window.glaSha.glaSys.gas[1].MM PARAM */),0.0);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp182)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp184 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[113] /* window.glaSha.glaSys.gas[1].MM PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta185 = stringAppend(MMC_REFSTRINGLIT(tmp183),tmp184);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(window.glaSha.glaSys.gas[1].MM >= 0.0)";
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta185));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta185));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp186 = 1;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 2234 OMC_FILE
  TRACE_POP
}

/*
equation index: 533
type: ALGORITHM

  assert(window.glaSha.glaSys.gas[1].a_mu >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSha.glaSys.gas[1].a_mu, has value: " + String(window.glaSha.glaSys.gas[1].a_mu, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_533(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,533};
  modelica_boolean tmp187;
  static const MMC_DEFSTRINGLIT(tmp188,87,"Variable violating min constraint: 0.0 <= window.glaSha.glaSys.gas[1].a_mu, has value: ");
  modelica_string tmp189;
  modelica_metatype tmpMeta190;
  static int tmp191 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp191)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp187 = GreaterEq((data->simulationInfo->realParameter[117] /* window.glaSha.glaSys.gas[1].a_mu PARAM */),0.0);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp187)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp189 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[117] /* window.glaSha.glaSys.gas[1].a_mu PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta190 = stringAppend(MMC_REFSTRINGLIT(tmp188),tmp189);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(window.glaSha.glaSys.gas[1].a_mu >= 0.0)";
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta190));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta190));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp191 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 2294 OMC_FILE
  TRACE_POP
}

/*
equation index: 534
type: ALGORITHM

  assert(window.glaUns.glass[1].T04 >= 0.0, "Variable violating min constraint: 0.0 <= window.glaUns.glass[1].T04, has value: " + String(window.glaUns.glass[1].T04, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_534(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,534};
  modelica_boolean tmp192;
  static const MMC_DEFSTRINGLIT(tmp193,81,"Variable violating min constraint: 0.0 <= window.glaUns.glass[1].T04, has value: ");
  modelica_string tmp194;
  modelica_metatype tmpMeta195;
  static int tmp196 = 0;
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  if(!tmp196)
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    tmp192 = GreaterEq((data->simulationInfo->realParameter[212] /* window.glaUns.glass[1].T04 PARAM */),0.0);
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    if(!tmp192)
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp194 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[212] /* window.glaUns.glass[1].T04 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmpMeta195 = stringAppend(MMC_REFSTRINGLIT(tmp193),tmp194);
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        const char* assert_cond = "(window.glaUns.glass[1].T04 >= 0.0)";
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",22,2,23,34,0};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta195));
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        } else {
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",22,2,23,34,0};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta195));
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        }
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      }
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp196 = 1;
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  }
#line 2354 OMC_FILE
  TRACE_POP
}

/*
equation index: 535
type: ALGORITHM

  assert(window.glaUns.glass[1].T03 >= 0.0, "Variable violating min constraint: 0.0 <= window.glaUns.glass[1].T03, has value: " + String(window.glaUns.glass[1].T03, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_535(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,535};
  modelica_boolean tmp197;
  static const MMC_DEFSTRINGLIT(tmp198,81,"Variable violating min constraint: 0.0 <= window.glaUns.glass[1].T03, has value: ");
  modelica_string tmp199;
  modelica_metatype tmpMeta200;
  static int tmp201 = 0;
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  if(!tmp201)
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    tmp197 = GreaterEq((data->simulationInfo->realParameter[211] /* window.glaUns.glass[1].T03 PARAM */),0.0);
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    if(!tmp197)
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp199 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[211] /* window.glaUns.glass[1].T03 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmpMeta200 = stringAppend(MMC_REFSTRINGLIT(tmp198),tmp199);
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        const char* assert_cond = "(window.glaUns.glass[1].T03 >= 0.0)";
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",20,2,21,34,0};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta200));
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        } else {
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",20,2,21,34,0};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta200));
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        }
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      }
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp201 = 1;
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    }
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  }
#line 2414 OMC_FILE
  TRACE_POP
}

/*
equation index: 536
type: ALGORITHM

  assert(window.glaUns.glass[1].T0 >= 0.0, "Variable violating min constraint: 0.0 <= window.glaUns.glass[1].T0, has value: " + String(window.glaUns.glass[1].T0, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_536(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,536};
  modelica_boolean tmp202;
  static const MMC_DEFSTRINGLIT(tmp203,80,"Variable violating min constraint: 0.0 <= window.glaUns.glass[1].T0, has value: ");
  modelica_string tmp204;
  modelica_metatype tmpMeta205;
  static int tmp206 = 0;
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  if(!tmp206)
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    tmp202 = GreaterEq((data->simulationInfo->realParameter[210] /* window.glaUns.glass[1].T0 PARAM */),0.0);
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    if(!tmp202)
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp204 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[210] /* window.glaUns.glass[1].T0 PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmpMeta205 = stringAppend(MMC_REFSTRINGLIT(tmp203),tmp204);
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        const char* assert_cond = "(window.glaUns.glass[1].T0 >= 0.0)";
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",16,3,18,42,0};
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta205));
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        } else {
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo",16,3,18,42,0};
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta205));
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
        }
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      }
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
      tmp206 = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/ParametersTwoSurfaces.mo"
  }
#line 2474 OMC_FILE
  TRACE_POP
}

/*
equation index: 537
type: ALGORITHM

  assert(window.glaUns.glaSys.gas[1].MM >= 0.0, "Variable violating min constraint: 0.0 <= window.glaUns.glaSys.gas[1].MM, has value: " + String(window.glaUns.glaSys.gas[1].MM, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_537(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,537};
  modelica_boolean tmp207;
  static const MMC_DEFSTRINGLIT(tmp208,85,"Variable violating min constraint: 0.0 <= window.glaUns.glaSys.gas[1].MM, has value: ");
  modelica_string tmp209;
  modelica_metatype tmpMeta210;
  static int tmp211 = 0;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp211)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp207 = GreaterEq((data->simulationInfo->realParameter[183] /* window.glaUns.glaSys.gas[1].MM PARAM */),0.0);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp207)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp209 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[183] /* window.glaUns.glaSys.gas[1].MM PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta210 = stringAppend(MMC_REFSTRINGLIT(tmp208),tmp209);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(window.glaUns.glaSys.gas[1].MM >= 0.0)";
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta210));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta210));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp211 = 1;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 2534 OMC_FILE
  TRACE_POP
}

/*
equation index: 538
type: ALGORITHM

  assert(window.glaUns.glaSys.gas[1].a_mu >= 0.0, "Variable violating min constraint: 0.0 <= window.glaUns.glaSys.gas[1].a_mu, has value: " + String(window.glaUns.glaSys.gas[1].a_mu, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_538(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,538};
  modelica_boolean tmp212;
  static const MMC_DEFSTRINGLIT(tmp213,87,"Variable violating min constraint: 0.0 <= window.glaUns.glaSys.gas[1].a_mu, has value: ");
  modelica_string tmp214;
  modelica_metatype tmpMeta215;
  static int tmp216 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp216)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp212 = GreaterEq((data->simulationInfo->realParameter[187] /* window.glaUns.glaSys.gas[1].a_mu PARAM */),0.0);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp212)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp214 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[187] /* window.glaUns.glaSys.gas[1].a_mu PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta215 = stringAppend(MMC_REFSTRINGLIT(tmp213),tmp214);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(window.glaUns.glaSys.gas[1].a_mu >= 0.0)";
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta215));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta215));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp216 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 2594 OMC_FILE
  TRACE_POP
}

/*
equation index: 539
type: ALGORITHM

  assert(window.fFra >= 0.0 and window.fFra <= 1.0, "Variable violating min/max constraint: 0.0 <= window.fFra <= 1.0, has value: " + String(window.fFra, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_539(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,539};
  modelica_boolean tmp217;
  modelica_boolean tmp218;
  static const MMC_DEFSTRINGLIT(tmp219,77,"Variable violating min/max constraint: 0.0 <= window.fFra <= 1.0, has value: ");
  modelica_string tmp220;
  modelica_metatype tmpMeta221;
  static int tmp222 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
  if(!tmp222)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    tmp217 = GreaterEq((data->simulationInfo->realParameter[107] /* window.fFra PARAM */),0.0);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    tmp218 = LessEq((data->simulationInfo->realParameter[107] /* window.fFra PARAM */),1.0);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    if(!(tmp217 && tmp218))
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      tmp220 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[107] /* window.fFra PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      tmpMeta221 = stringAppend(MMC_REFSTRINGLIT(tmp219),tmp220);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        const char* assert_cond = "(window.fFra >= 0.0 and window.fFra <= 1.0)";
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo",12,3,12,60,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta221));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo",12,3,12,60,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta221));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      tmp222 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
  }
#line 2657 OMC_FILE
  TRACE_POP
}

/*
equation index: 540
type: ALGORITHM

  assert(window.glaSys.gas[1].MM >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSys.gas[1].MM, has value: " + String(window.glaSys.gas[1].MM, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_540(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,540};
  modelica_boolean tmp223;
  static const MMC_DEFSTRINGLIT(tmp224,78,"Variable violating min constraint: 0.0 <= window.glaSys.gas[1].MM, has value: ");
  modelica_string tmp225;
  modelica_metatype tmpMeta226;
  static int tmp227 = 0;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp227)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp223 = GreaterEq((data->simulationInfo->realParameter[154] /* window.glaSys.gas[1].MM PARAM */),0.0);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp223)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp225 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[154] /* window.glaSys.gas[1].MM PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta226 = stringAppend(MMC_REFSTRINGLIT(tmp224),tmp225);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(window.glaSys.gas[1].MM >= 0.0)";
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta226));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta226));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp227 = 1;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 2717 OMC_FILE
  TRACE_POP
}

/*
equation index: 541
type: ALGORITHM

  assert(window.glaSys.gas[1].a_mu >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSys.gas[1].a_mu, has value: " + String(window.glaSys.gas[1].a_mu, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_541(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,541};
  modelica_boolean tmp228;
  static const MMC_DEFSTRINGLIT(tmp229,80,"Variable violating min constraint: 0.0 <= window.glaSys.gas[1].a_mu, has value: ");
  modelica_string tmp230;
  modelica_metatype tmpMeta231;
  static int tmp232 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp232)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp228 = GreaterEq((data->simulationInfo->realParameter[158] /* window.glaSys.gas[1].a_mu PARAM */),0.0);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp228)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp230 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[158] /* window.glaSys.gas[1].a_mu PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta231 = stringAppend(MMC_REFSTRINGLIT(tmp229),tmp230);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(window.glaSys.gas[1].a_mu >= 0.0)";
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta231));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta231));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp232 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 2777 OMC_FILE
  TRACE_POP
}
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_8(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_7(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_6(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_5(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_4(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_3(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_2(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_1(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_497(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_498(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_499(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_500(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_501(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_502(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_503(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_504(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_505(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_506(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_507(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_508(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_509(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_510(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_511(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_512(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_513(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_514(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_515(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_516(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_517(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_518(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_519(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_520(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_521(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_522(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_523(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_524(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_525(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_526(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_527(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_528(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_529(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_530(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_531(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_532(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_533(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_534(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_535(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_536(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_537(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_538(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_539(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_540(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_541(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->integerParameter[3] /* sumJ.nin PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[3].time_unvarying = 1;
  (data->simulationInfo->integerParameter[4] /* window.glaSha.nGlaLay PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[4].time_unvarying = 1;
  (data->simulationInfo->integerParameter[5] /* window.glaUns.nGlaLay PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[5].time_unvarying = 1;
  (data->simulationInfo->integerParameter[6] /* window.matFra.nSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[6].time_unvarying = 1;
  (data->simulationInfo->integerParameter[7] /* window.matFra.nStaRef PARAM */) = ((modelica_integer) 3);
  data->modelData->integerParameterData[7].time_unvarying = 1;
  (data->simulationInfo->integerParameter[8] /* window.matGla.nSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[8].time_unvarying = 1;
  (data->simulationInfo->integerParameter[9] /* window.matGla.nStaRef PARAM */) = ((modelica_integer) 3);
  data->modelData->integerParameterData[9].time_unvarying = 1;
  (data->localData[0]->realVars[34] /* heatFlowSensor.port_b.Q_flow variable */) = -0.0;
  data->modelData->realVarsData[34].time_unvarying = 1;
  (data->localData[0]->realVars[36] /* heatFlowSensor1.port_b.Q_flow variable */) = -0.0;
  data->modelData->realVarsData[36].time_unvarying = 1;
  (data->localData[0]->realVars[39] /* indRad.heatPort.Q_flow variable */) = -0.0;
  data->modelData->realVarsData[39].time_unvarying = 1;
  (data->localData[0]->realVars[42] /* intShaCon.air.Q_flow variable */) = -0.0;
  data->modelData->realVarsData[42].time_unvarying = 1;
  (data->simulationInfo->realParameter[0] /* A PARAM */) = 1.0;
  data->modelData->realParameterData[0].time_unvarying = 1;
  (data->simulationInfo->realParameter[1] /* AFra PARAM */) = 0.2;
  data->modelData->realParameterData[1].time_unvarying = 1;
  (data->simulationInfo->realParameter[2] /* AGla PARAM */) = 0.8;
  data->modelData->realParameterData[2].time_unvarying = 1;
  (data->simulationInfo->realParameter[3] /* add.k1 PARAM */) = 1.0;
  data->modelData->realParameterData[3].time_unvarying = 1;
  (data->simulationInfo->realParameter[4] /* add.k2 PARAM */) = 1.0;
  data->modelData->realParameterData[4].time_unvarying = 1;
  (data->simulationInfo->realParameter[5] /* azi PARAM */) = 0.0;
  data->modelData->realParameterData[5].time_unvarying = 1;
  (data->simulationInfo->realParameter[6] /* extCon.A PARAM */) = 1.0;
  data->modelData->realParameterData[6].time_unvarying = 1;
  (data->simulationInfo->realParameter[7] /* extCon.AFra PARAM */) = 0.2;
  data->modelData->realParameterData[7].time_unvarying = 1;
  (data->simulationInfo->realParameter[8] /* extCon.AGla PARAM */) = 0.8;
  data->modelData->realParameterData[8].time_unvarying = 1;
  (data->simulationInfo->realParameter[9] /* extCon.absIRSha_air PARAM */) = 0.25;
  data->modelData->realParameterData[9].time_unvarying = 1;
  (data->simulationInfo->realParameter[10] /* extCon.absIRSha_glass PARAM */) = 0.25;
  data->modelData->realParameterData[10].time_unvarying = 1;
  (data->simulationInfo->realParameter[11] /* extCon.conCoeFra.A PARAM */) = 0.2;
  data->modelData->realParameterData[11].time_unvarying = 1;
  (data->simulationInfo->realParameter[12] /* extCon.conCoeGla.A PARAM */) = 0.8;
  data->modelData->realParameterData[12].time_unvarying = 1;
  (data->simulationInfo->realParameter[13] /* extCon.fFra PARAM */) = 0.2;
  data->modelData->realParameterData[13].time_unvarying = 1;
  (data->simulationInfo->realParameter[14] /* extCon.radOut.A PARAM */) = 0.8;
  data->modelData->realParameterData[14].time_unvarying = 1;
  (data->simulationInfo->realParameter[15] /* extCon.radOut.T0 PARAM */) = 293.15;
  data->modelData->realParameterData[15].time_unvarying = 1;
  (data->simulationInfo->realParameter[16] /* extCon.radOut.T03 PARAM */) = 25192408.83087499;
  data->modelData->realParameterData[16].time_unvarying = 1;
  (data->simulationInfo->realParameter[17] /* extCon.radOut.T04 PARAM */) = 7385154648.771004;
  data->modelData->realParameterData[17].time_unvarying = 1;
  (data->simulationInfo->realParameter[18] /* extCon.radOut.vieFacSky PARAM */) = 0.5;
  data->modelData->realParameterData[18].time_unvarying = 1;
  (data->simulationInfo->realParameter[19] /* extCon.shaCon.A PARAM */) = 0.8;
  data->modelData->realParameterData[19].time_unvarying = 1;
  (data->simulationInfo->realParameter[20] /* extCon.shaCon.k PARAM */) = 1.0;
  data->modelData->realParameterData[20].time_unvarying = 1;
  (data->simulationInfo->realParameter[21] /* extCon.shaRad.A PARAM */) = 0.8;
  data->modelData->realParameterData[21].time_unvarying = 1;
  (data->simulationInfo->realParameter[22] /* extCon.shaRad.T0 PARAM */) = 293.15;
  data->modelData->realParameterData[22].time_unvarying = 1;
  (data->simulationInfo->realParameter[23] /* extCon.shaRad.T03 PARAM */) = 25192408.83087499;
  data->modelData->realParameterData[23].time_unvarying = 1;
  (data->simulationInfo->realParameter[24] /* extCon.shaRad.absIR_air PARAM */) = 0.0;
  data->modelData->realParameterData[24].time_unvarying = 1;
  (data->simulationInfo->realParameter[25] /* extCon.shaRad.absIR_glass PARAM */) = 0.0;
  data->modelData->realParameterData[25].time_unvarying = 1;
  (data->simulationInfo->realParameter[26] /* extCon.shaRad.rhoIR_air PARAM */) = 0.0;
  data->modelData->realParameterData[26].time_unvarying = 1;
  (data->simulationInfo->realParameter[27] /* extCon.shaRad.rhoIR_glass PARAM */) = 0.0;
  data->modelData->realParameterData[27].time_unvarying = 1;
  (data->simulationInfo->realParameter[28] /* extCon.shaRad.tauIR_air PARAM */) = 1.0;
  data->modelData->realParameterData[28].time_unvarying = 1;
  (data->simulationInfo->realParameter[29] /* extCon.shaRad.tauIR_glass PARAM */) = 1.0;
  data->modelData->realParameterData[29].time_unvarying = 1;
  (data->simulationInfo->realParameter[30] /* extCon.tauIRSha_air PARAM */) = 0.0;
  data->modelData->realParameterData[30].time_unvarying = 1;
  (data->simulationInfo->realParameter[31] /* extCon.tauIRSha_glass PARAM */) = 0.0;
  data->modelData->realParameterData[31].time_unvarying = 1;
  (data->simulationInfo->realParameter[32] /* extCon.vieFacSky PARAM */) = 0.5;
  data->modelData->realParameterData[32].time_unvarying = 1;
  (data->simulationInfo->realParameter[33] /* fFra PARAM */) = 0.2;
  data->modelData->realParameterData[33].time_unvarying = 1;
  (data->simulationInfo->realParameter[34] /* glaSys.UFra PARAM */) = 3.0;
  data->modelData->realParameterData[34].time_unvarying = 1;
  (data->simulationInfo->realParameter[35] /* glaSys.absIRFra PARAM */) = 0.8;
  data->modelData->realParameterData[35].time_unvarying = 1;
  (data->simulationInfo->realParameter[36] /* glaSys.absSolFra PARAM */) = 0.5;
  data->modelData->realParameterData[36].time_unvarying = 1;
  (data->simulationInfo->realParameter[54] /* glaSys.shade.absIR_a PARAM */) = 0.25;
  data->modelData->realParameterData[54].time_unvarying = 1;
  (data->simulationInfo->realParameter[55] /* glaSys.shade.absIR_b PARAM */) = 0.25;
  data->modelData->realParameterData[55].time_unvarying = 1;
  (data->simulationInfo->realParameter[58] /* glaSys.shade.tauIR_a PARAM */) = 0.0;
  data->modelData->realParameterData[58].time_unvarying = 1;
  (data->simulationInfo->realParameter[59] /* glaSys.shade.tauIR_b PARAM */) = 0.0;
  data->modelData->realParameterData[59].time_unvarying = 1;
  (data->simulationInfo->realParameter[62] /* indRad.A PARAM */) = 1.0;
  data->modelData->realParameterData[62].time_unvarying = 1;
  (data->simulationInfo->realParameter[63] /* indRad.T0 PARAM */) = 293.15;
  data->modelData->realParameterData[63].time_unvarying = 1;
  (data->simulationInfo->realParameter[64] /* indRad.T03 PARAM */) = 25192408.83087499;
  data->modelData->realParameterData[64].time_unvarying = 1;
  (data->simulationInfo->realParameter[65] /* indRad.T04 PARAM */) = 7385154648.771004;
  data->modelData->realParameterData[65].time_unvarying = 1;
  (data->simulationInfo->realParameter[66] /* indRad.absIR PARAM */) = 1.0;
  data->modelData->realParameterData[66].time_unvarying = 1;
  (data->simulationInfo->realParameter[67] /* indRad.rhoIR PARAM */) = 0.0;
  data->modelData->realParameterData[67].time_unvarying = 1;
  (data->simulationInfo->realParameter[68] /* indRad.tauIR PARAM */) = 0.0;
  data->modelData->realParameterData[68].time_unvarying = 1;
  (data->simulationInfo->realParameter[69] /* intShaCon.A PARAM */) = 1.0;
  data->modelData->realParameterData[69].time_unvarying = 1;
  (data->simulationInfo->realParameter[70] /* intShaCon.AFra PARAM */) = 0.2;
  data->modelData->realParameterData[70].time_unvarying = 1;
  (data->simulationInfo->realParameter[71] /* intShaCon.AGla PARAM */) = 0.8;
  data->modelData->realParameterData[71].time_unvarying = 1;
  (data->simulationInfo->realParameter[72] /* intShaCon.conCoeGla.A PARAM */) = 0.8;
  data->modelData->realParameterData[72].time_unvarying = 1;
  (data->simulationInfo->realParameter[73] /* intShaCon.conFra.A PARAM */) = 0.2;
  data->modelData->realParameterData[73].time_unvarying = 1;
  (data->simulationInfo->realParameter[74] /* intShaCon.conFra.cosTil PARAM */) = 6.123233995736766e-17;
  data->modelData->realParameterData[74].time_unvarying = 1;
  (data->simulationInfo->realParameter[75] /* intShaCon.conFra.hFixed PARAM */) = 4.0;
  data->modelData->realParameterData[75].time_unvarying = 1;
  (data->simulationInfo->realParameter[76] /* intShaCon.conFra.sinTil PARAM */) = 1.0;
  data->modelData->realParameterData[76].time_unvarying = 1;
  (data->simulationInfo->realParameter[77] /* intShaCon.conFra.til PARAM */) = 1.570796326794897;
  data->modelData->realParameterData[77].time_unvarying = 1;
  (data->simulationInfo->realParameter[78] /* intShaCon.conSha.A PARAM */) = 0.8;
  data->modelData->realParameterData[78].time_unvarying = 1;
  (data->simulationInfo->realParameter[79] /* intShaCon.conSha.k PARAM */) = 1.0;
  data->modelData->realParameterData[79].time_unvarying = 1;
  (data->simulationInfo->realParameter[80] /* intShaCon.conWinUns.A PARAM */) = 0.8;
  data->modelData->realParameterData[80].time_unvarying = 1;
  (data->simulationInfo->realParameter[81] /* intShaCon.conWinUns.cosTil PARAM */) = 6.123233995736766e-17;
  data->modelData->realParameterData[81].time_unvarying = 1;
  (data->simulationInfo->realParameter[82] /* intShaCon.conWinUns.hFixed PARAM */) = 4.0;
  data->modelData->realParameterData[82].time_unvarying = 1;
  (data->simulationInfo->realParameter[83] /* intShaCon.conWinUns.sinTil PARAM */) = 1.0;
  data->modelData->realParameterData[83].time_unvarying = 1;
  (data->simulationInfo->realParameter[84] /* intShaCon.conWinUns.til PARAM */) = 1.570796326794897;
  data->modelData->realParameterData[84].time_unvarying = 1;
  (data->simulationInfo->realParameter[85] /* intShaCon.fFra PARAM */) = 0.2;
  data->modelData->realParameterData[85].time_unvarying = 1;
  (data->simulationInfo->realParameter[86] /* intShaCon.hFixed PARAM */) = 4.0;
  data->modelData->realParameterData[86].time_unvarying = 1;
  (data->simulationInfo->realParameter[87] /* intShaCon.til PARAM */) = 1.570796326794897;
  data->modelData->realParameterData[87].time_unvarying = 1;
  (data->simulationInfo->realParameter[88] /* intShaRad.A PARAM */) = 0.8;
  data->modelData->realParameterData[88].time_unvarying = 1;
  (data->simulationInfo->realParameter[89] /* intShaRad.T0 PARAM */) = 293.15;
  data->modelData->realParameterData[89].time_unvarying = 1;
  (data->simulationInfo->realParameter[90] /* intShaRad.T03 PARAM */) = 25192408.83087499;
  data->modelData->realParameterData[90].time_unvarying = 1;
  (data->simulationInfo->realParameter[91] /* intShaRad.absIR_air PARAM */) = 0.25;
  data->modelData->realParameterData[91].time_unvarying = 1;
  (data->simulationInfo->realParameter[92] /* intShaRad.absIR_glass PARAM */) = 0.25;
  data->modelData->realParameterData[92].time_unvarying = 1;
  (data->simulationInfo->realParameter[93] /* intShaRad.rhoIR_air PARAM */) = 0.75;
  data->modelData->realParameterData[93].time_unvarying = 1;
  (data->simulationInfo->realParameter[94] /* intShaRad.rhoIR_glass PARAM */) = 0.75;
  data->modelData->realParameterData[94].time_unvarying = 1;
  (data->simulationInfo->realParameter[95] /* intShaRad.tauIR_air PARAM */) = 0.0;
  data->modelData->realParameterData[95].time_unvarying = 1;
  (data->simulationInfo->realParameter[96] /* intShaRad.tauIR_glass PARAM */) = 0.0;
  data->modelData->realParameterData[96].time_unvarying = 1;
  (data->simulationInfo->realParameter[97] /* sumJ.k[1] PARAM */) = 1.0;
  data->modelData->realParameterData[97].time_unvarying = 1;
  (data->simulationInfo->realParameter[98] /* sumJ.k[2] PARAM */) = 1.0;
  data->modelData->realParameterData[98].time_unvarying = 1;
  (data->simulationInfo->realParameter[99] /* til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[99].time_unvarying = 1;
  (data->simulationInfo->realParameter[100] /* uSha.duration PARAM */) = 0.5;
  data->modelData->realParameterData[100].time_unvarying = 1;
  (data->simulationInfo->realParameter[101] /* uSha.height PARAM */) = 1.0;
  data->modelData->realParameterData[101].time_unvarying = 1;
  (data->simulationInfo->realParameter[102] /* uSha.offset PARAM */) = 0.0;
  data->modelData->realParameterData[102].time_unvarying = 1;
  (data->simulationInfo->realParameter[103] /* uSha.startTime PARAM */) = 0.25;
  data->modelData->realParameterData[103].time_unvarying = 1;
  (data->simulationInfo->realParameter[104] /* window.A PARAM */) = 1.0;
  data->modelData->realParameterData[104].time_unvarying = 1;
  (data->simulationInfo->realParameter[105] /* window.AFra PARAM */) = 0.2;
  data->modelData->realParameterData[105].time_unvarying = 1;
  (data->simulationInfo->realParameter[106] /* window.AGla PARAM */) = 0.8;
  data->modelData->realParameterData[106].time_unvarying = 1;
  (data->simulationInfo->realParameter[107] /* window.fFra PARAM */) = 0.2;
  data->modelData->realParameterData[107].time_unvarying = 1;
  (data->simulationInfo->realParameter[108] /* window.frame.G PARAM */) = 0.6000000000000001;
  data->modelData->realParameterData[108].time_unvarying = 1;
  (data->simulationInfo->realParameter[109] /* window.glaSha.A PARAM */) = 0.8;
  data->modelData->realParameterData[109].time_unvarying = 1;
  (data->simulationInfo->realParameter[110] /* window.glaSha.glaSys.UFra PARAM */) = 3.0;
  data->modelData->realParameterData[110].time_unvarying = 1;
  (data->simulationInfo->realParameter[111] /* window.glaSha.glaSys.absIRFra PARAM */) = 0.8;
  data->modelData->realParameterData[111].time_unvarying = 1;
  (data->simulationInfo->realParameter[112] /* window.glaSha.glaSys.absSolFra PARAM */) = 0.5;
  data->modelData->realParameterData[112].time_unvarying = 1;
  (data->simulationInfo->realParameter[113] /* window.glaSha.glaSys.gas[1].MM PARAM */) = 0.02897;
  data->modelData->realParameterData[113].time_unvarying = 1;
  (data->simulationInfo->realParameter[114] /* window.glaSha.glaSys.gas[1].P0 PARAM */) = 101325.0;
  data->modelData->realParameterData[114].time_unvarying = 1;
  (data->simulationInfo->realParameter[115] /* window.glaSha.glaSys.gas[1].a_c PARAM */) = 1002.737;
  data->modelData->realParameterData[115].time_unvarying = 1;
  (data->simulationInfo->realParameter[116] /* window.glaSha.glaSys.gas[1].a_k PARAM */) = 0.002873;
  data->modelData->realParameterData[116].time_unvarying = 1;
  (data->simulationInfo->realParameter[117] /* window.glaSha.glaSys.gas[1].a_mu PARAM */) = 3.723e-06;
  data->modelData->realParameterData[117].time_unvarying = 1;
  (data->simulationInfo->realParameter[118] /* window.glaSha.glaSys.gas[1].b_c PARAM */) = 0.012324;
  data->modelData->realParameterData[118].time_unvarying = 1;
  (data->simulationInfo->realParameter[119] /* window.glaSha.glaSys.gas[1].b_k PARAM */) = 7.76e-05;
  data->modelData->realParameterData[119].time_unvarying = 1;
  (data->simulationInfo->realParameter[120] /* window.glaSha.glaSys.gas[1].b_mu PARAM */) = 4.94e-08;
  data->modelData->realParameterData[120].time_unvarying = 1;
  (data->simulationInfo->realParameter[121] /* window.glaSha.glaSys.gas[1].x PARAM */) = -1.0;
  data->modelData->realParameterData[121].time_unvarying = 1;
  (data->simulationInfo->realParameter[122] /* window.glaSha.glaSys.glass[1].absIR_a PARAM */) = 0.84;
  data->modelData->realParameterData[122].time_unvarying = 1;
  (data->simulationInfo->realParameter[123] /* window.glaSha.glaSys.glass[1].absIR_b PARAM */) = 0.84;
  data->modelData->realParameterData[123].time_unvarying = 1;
  (data->simulationInfo->realParameter[124] /* window.glaSha.glaSys.glass[1].k PARAM */) = 1.0;
  data->modelData->realParameterData[124].time_unvarying = 1;
  (data->simulationInfo->realParameter[125] /* window.glaSha.glaSys.glass[1].rhoSol_a[1] PARAM */) = 0.075;
  data->modelData->realParameterData[125].time_unvarying = 1;
  (data->simulationInfo->realParameter[126] /* window.glaSha.glaSys.glass[1].rhoSol_b[1] PARAM */) = 0.075;
  data->modelData->realParameterData[126].time_unvarying = 1;
  (data->simulationInfo->realParameter[127] /* window.glaSha.glaSys.glass[1].tauIR PARAM */) = 0.0;
  data->modelData->realParameterData[127].time_unvarying = 1;
  (data->simulationInfo->realParameter[128] /* window.glaSha.glaSys.glass[1].tauSol[1] PARAM */) = 0.834;
  data->modelData->realParameterData[128].time_unvarying = 1;
  (data->simulationInfo->realParameter[129] /* window.glaSha.glaSys.glass[1].x PARAM */) = 0.003;
  data->modelData->realParameterData[129].time_unvarying = 1;
  (data->simulationInfo->realParameter[130] /* window.glaSha.glaSys.shade.absIR_a PARAM */) = 0.25;
  data->modelData->realParameterData[130].time_unvarying = 1;
  (data->simulationInfo->realParameter[131] /* window.glaSha.glaSys.shade.absIR_b PARAM */) = 0.25;
  data->modelData->realParameterData[131].time_unvarying = 1;
  (data->simulationInfo->realParameter[132] /* window.glaSha.glaSys.shade.rhoSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[132].time_unvarying = 1;
  (data->simulationInfo->realParameter[133] /* window.glaSha.glaSys.shade.rhoSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[133].time_unvarying = 1;
  (data->simulationInfo->realParameter[134] /* window.glaSha.glaSys.shade.tauIR_a PARAM */) = 0.0;
  data->modelData->realParameterData[134].time_unvarying = 1;
  (data->simulationInfo->realParameter[135] /* window.glaSha.glaSys.shade.tauIR_b PARAM */) = 0.0;
  data->modelData->realParameterData[135].time_unvarying = 1;
  (data->simulationInfo->realParameter[136] /* window.glaSha.glaSys.shade.tauSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[136].time_unvarying = 1;
  (data->simulationInfo->realParameter[137] /* window.glaSha.glaSys.shade.tauSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[137].time_unvarying = 1;
  (data->simulationInfo->realParameter[138] /* window.glaSha.glass[1].A PARAM */) = 0.8;
  data->modelData->realParameterData[138].time_unvarying = 1;
  (data->simulationInfo->realParameter[139] /* window.glaSha.glass[1].R PARAM */) = 0.001875;
  data->modelData->realParameterData[139].time_unvarying = 1;
  (data->simulationInfo->realParameter[140] /* window.glaSha.glass[1].T0 PARAM */) = 293.15;
  data->modelData->realParameterData[140].time_unvarying = 1;
  (data->simulationInfo->realParameter[141] /* window.glaSha.glass[1].T03 PARAM */) = 25192408.83087499;
  data->modelData->realParameterData[141].time_unvarying = 1;
  (data->simulationInfo->realParameter[142] /* window.glaSha.glass[1].T04 PARAM */) = 7385154648.771004;
  data->modelData->realParameterData[142].time_unvarying = 1;
  (data->simulationInfo->realParameter[143] /* window.glaSha.glass[1].absIR_a PARAM */) = 0.84;
  data->modelData->realParameterData[143].time_unvarying = 1;
  (data->simulationInfo->realParameter[144] /* window.glaSha.glass[1].absIR_b PARAM */) = 0.84;
  data->modelData->realParameterData[144].time_unvarying = 1;
  (data->simulationInfo->realParameter[145] /* window.glaSha.glass[1].k PARAM */) = 1.0;
  data->modelData->realParameterData[145].time_unvarying = 1;
  (data->simulationInfo->realParameter[146] /* window.glaSha.glass[1].rhoIR_a PARAM */) = 0.16;
  data->modelData->realParameterData[146].time_unvarying = 1;
  (data->simulationInfo->realParameter[147] /* window.glaSha.glass[1].rhoIR_b PARAM */) = 0.16;
  data->modelData->realParameterData[147].time_unvarying = 1;
  (data->simulationInfo->realParameter[148] /* window.glaSha.glass[1].tauIR PARAM */) = 0.0;
  data->modelData->realParameterData[148].time_unvarying = 1;
  (data->simulationInfo->realParameter[149] /* window.glaSha.glass[1].x PARAM */) = 0.003;
  data->modelData->realParameterData[149].time_unvarying = 1;
  (data->simulationInfo->realParameter[150] /* window.glaSha.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[150].time_unvarying = 1;
  (data->simulationInfo->realParameter[151] /* window.glaSys.UFra PARAM */) = 3.0;
  data->modelData->realParameterData[151].time_unvarying = 1;
  (data->simulationInfo->realParameter[170] /* window.glaSys.glass[1].x PARAM */) = 0.003;
  data->modelData->realParameterData[170].time_unvarying = 1;
  (data->simulationInfo->realParameter[179] /* window.glaUns.A PARAM */) = 0.8;
  data->modelData->realParameterData[179].time_unvarying = 1;
  (data->simulationInfo->realParameter[180] /* window.glaUns.glaSys.UFra PARAM */) = 3.0;
  data->modelData->realParameterData[180].time_unvarying = 1;
  (data->simulationInfo->realParameter[181] /* window.glaUns.glaSys.absIRFra PARAM */) = 0.8;
  data->modelData->realParameterData[181].time_unvarying = 1;
  (data->simulationInfo->realParameter[182] /* window.glaUns.glaSys.absSolFra PARAM */) = 0.5;
  data->modelData->realParameterData[182].time_unvarying = 1;
  (data->simulationInfo->realParameter[183] /* window.glaUns.glaSys.gas[1].MM PARAM */) = 0.02897;
  data->modelData->realParameterData[183].time_unvarying = 1;
  (data->simulationInfo->realParameter[184] /* window.glaUns.glaSys.gas[1].P0 PARAM */) = 101325.0;
  data->modelData->realParameterData[184].time_unvarying = 1;
  (data->simulationInfo->realParameter[185] /* window.glaUns.glaSys.gas[1].a_c PARAM */) = 1002.737;
  data->modelData->realParameterData[185].time_unvarying = 1;
  (data->simulationInfo->realParameter[186] /* window.glaUns.glaSys.gas[1].a_k PARAM */) = 0.002873;
  data->modelData->realParameterData[186].time_unvarying = 1;
  (data->simulationInfo->realParameter[187] /* window.glaUns.glaSys.gas[1].a_mu PARAM */) = 3.723e-06;
  data->modelData->realParameterData[187].time_unvarying = 1;
  (data->simulationInfo->realParameter[188] /* window.glaUns.glaSys.gas[1].b_c PARAM */) = 0.012324;
  data->modelData->realParameterData[188].time_unvarying = 1;
  (data->simulationInfo->realParameter[189] /* window.glaUns.glaSys.gas[1].b_k PARAM */) = 7.76e-05;
  data->modelData->realParameterData[189].time_unvarying = 1;
  (data->simulationInfo->realParameter[190] /* window.glaUns.glaSys.gas[1].b_mu PARAM */) = 4.94e-08;
  data->modelData->realParameterData[190].time_unvarying = 1;
  (data->simulationInfo->realParameter[191] /* window.glaUns.glaSys.gas[1].x PARAM */) = -1.0;
  data->modelData->realParameterData[191].time_unvarying = 1;
  (data->simulationInfo->realParameter[192] /* window.glaUns.glaSys.glass[1].absIR_a PARAM */) = 0.84;
  data->modelData->realParameterData[192].time_unvarying = 1;
  (data->simulationInfo->realParameter[193] /* window.glaUns.glaSys.glass[1].absIR_b PARAM */) = 0.84;
  data->modelData->realParameterData[193].time_unvarying = 1;
  (data->simulationInfo->realParameter[194] /* window.glaUns.glaSys.glass[1].k PARAM */) = 1.0;
  data->modelData->realParameterData[194].time_unvarying = 1;
  (data->simulationInfo->realParameter[195] /* window.glaUns.glaSys.glass[1].rhoSol_a[1] PARAM */) = 0.075;
  data->modelData->realParameterData[195].time_unvarying = 1;
  (data->simulationInfo->realParameter[196] /* window.glaUns.glaSys.glass[1].rhoSol_b[1] PARAM */) = 0.075;
  data->modelData->realParameterData[196].time_unvarying = 1;
  (data->simulationInfo->realParameter[197] /* window.glaUns.glaSys.glass[1].tauIR PARAM */) = 0.0;
  data->modelData->realParameterData[197].time_unvarying = 1;
  (data->simulationInfo->realParameter[198] /* window.glaUns.glaSys.glass[1].tauSol[1] PARAM */) = 0.834;
  data->modelData->realParameterData[198].time_unvarying = 1;
  (data->simulationInfo->realParameter[199] /* window.glaUns.glaSys.glass[1].x PARAM */) = 0.003;
  data->modelData->realParameterData[199].time_unvarying = 1;
  (data->simulationInfo->realParameter[200] /* window.glaUns.glaSys.shade.absIR_a PARAM */) = 0.25;
  data->modelData->realParameterData[200].time_unvarying = 1;
  (data->simulationInfo->realParameter[201] /* window.glaUns.glaSys.shade.absIR_b PARAM */) = 0.25;
  data->modelData->realParameterData[201].time_unvarying = 1;
  (data->simulationInfo->realParameter[202] /* window.glaUns.glaSys.shade.rhoSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[202].time_unvarying = 1;
  (data->simulationInfo->realParameter[203] /* window.glaUns.glaSys.shade.rhoSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[203].time_unvarying = 1;
  (data->simulationInfo->realParameter[204] /* window.glaUns.glaSys.shade.tauIR_a PARAM */) = 0.0;
  data->modelData->realParameterData[204].time_unvarying = 1;
  (data->simulationInfo->realParameter[205] /* window.glaUns.glaSys.shade.tauIR_b PARAM */) = 0.0;
  data->modelData->realParameterData[205].time_unvarying = 1;
  (data->simulationInfo->realParameter[206] /* window.glaUns.glaSys.shade.tauSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[206].time_unvarying = 1;
  (data->simulationInfo->realParameter[207] /* window.glaUns.glaSys.shade.tauSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[207].time_unvarying = 1;
  (data->simulationInfo->realParameter[208] /* window.glaUns.glass[1].A PARAM */) = 0.8;
  data->modelData->realParameterData[208].time_unvarying = 1;
  (data->simulationInfo->realParameter[209] /* window.glaUns.glass[1].R PARAM */) = 0.001875;
  data->modelData->realParameterData[209].time_unvarying = 1;
  (data->simulationInfo->realParameter[210] /* window.glaUns.glass[1].T0 PARAM */) = 293.15;
  data->modelData->realParameterData[210].time_unvarying = 1;
  (data->simulationInfo->realParameter[211] /* window.glaUns.glass[1].T03 PARAM */) = 25192408.83087499;
  data->modelData->realParameterData[211].time_unvarying = 1;
  (data->simulationInfo->realParameter[212] /* window.glaUns.glass[1].T04 PARAM */) = 7385154648.771004;
  data->modelData->realParameterData[212].time_unvarying = 1;
  (data->simulationInfo->realParameter[213] /* window.glaUns.glass[1].absIR_a PARAM */) = 0.84;
  data->modelData->realParameterData[213].time_unvarying = 1;
  (data->simulationInfo->realParameter[214] /* window.glaUns.glass[1].absIR_b PARAM */) = 0.84;
  data->modelData->realParameterData[214].time_unvarying = 1;
  (data->simulationInfo->realParameter[215] /* window.glaUns.glass[1].k PARAM */) = 1.0;
  data->modelData->realParameterData[215].time_unvarying = 1;
  (data->simulationInfo->realParameter[216] /* window.glaUns.glass[1].rhoIR_a PARAM */) = 0.16;
  data->modelData->realParameterData[216].time_unvarying = 1;
  (data->simulationInfo->realParameter[217] /* window.glaUns.glass[1].rhoIR_b PARAM */) = 0.16;
  data->modelData->realParameterData[217].time_unvarying = 1;
  (data->simulationInfo->realParameter[218] /* window.glaUns.glass[1].tauIR PARAM */) = 0.0;
  data->modelData->realParameterData[218].time_unvarying = 1;
  (data->simulationInfo->realParameter[219] /* window.glaUns.glass[1].x PARAM */) = 0.003;
  data->modelData->realParameterData[219].time_unvarying = 1;
  (data->simulationInfo->realParameter[220] /* window.glaUns.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[220].time_unvarying = 1;
  (data->simulationInfo->realParameter[221] /* window.matFra.LHea PARAM */) = 0.0;
  data->modelData->realParameterData[221].time_unvarying = 1;
  (data->simulationInfo->realParameter[222] /* window.matFra.R PARAM */) = 0.25;
  data->modelData->realParameterData[222].time_unvarying = 1;
  (data->simulationInfo->realParameter[223] /* window.matFra.TLiq PARAM */) = 293.15;
  data->modelData->realParameterData[223].time_unvarying = 1;
  (data->simulationInfo->realParameter[224] /* window.matFra.TSol PARAM */) = 293.15;
  data->modelData->realParameterData[224].time_unvarying = 1;
  (data->simulationInfo->realParameter[225] /* window.matFra.c PARAM */) = 1210.0;
  data->modelData->realParameterData[225].time_unvarying = 1;
  (data->simulationInfo->realParameter[226] /* window.matFra.d PARAM */) = 540.0;
  data->modelData->realParameterData[226].time_unvarying = 1;
  (data->simulationInfo->realParameter[227] /* window.matFra.k PARAM */) = 0.12;
  data->modelData->realParameterData[227].time_unvarying = 1;
  (data->simulationInfo->realParameter[228] /* window.matFra.nStaReal PARAM */) = 0.6337076463862541;
  data->modelData->realParameterData[228].time_unvarying = 1;
  (data->simulationInfo->realParameter[229] /* window.matFra.piMat PARAM */) = 70.0035713374682;
  data->modelData->realParameterData[229].time_unvarying = 1;
  (data->simulationInfo->realParameter[230] /* window.matFra.piRef PARAM */) = 331.4;
  data->modelData->realParameterData[230].time_unvarying = 1;
  (data->simulationInfo->realParameter[231] /* window.matFra.x PARAM */) = 0.03;
  data->modelData->realParameterData[231].time_unvarying = 1;
  (data->simulationInfo->realParameter[232] /* window.matGla.LHea PARAM */) = 0.0;
  data->modelData->realParameterData[232].time_unvarying = 1;
  (data->simulationInfo->realParameter[233] /* window.matGla.R PARAM */) = 0.003;
  data->modelData->realParameterData[233].time_unvarying = 1;
  (data->simulationInfo->realParameter[234] /* window.matGla.TLiq PARAM */) = 293.15;
  data->modelData->realParameterData[234].time_unvarying = 1;
  (data->simulationInfo->realParameter[235] /* window.matGla.TSol PARAM */) = 293.15;
  data->modelData->realParameterData[235].time_unvarying = 1;
  (data->simulationInfo->realParameter[236] /* window.matGla.c PARAM */) = 700.0;
  data->modelData->realParameterData[236].time_unvarying = 1;
  (data->simulationInfo->realParameter[237] /* window.matGla.d PARAM */) = 2500.0;
  data->modelData->realParameterData[237].time_unvarying = 1;
  (data->simulationInfo->realParameter[238] /* window.matGla.k PARAM */) = 1.0;
  data->modelData->realParameterData[238].time_unvarying = 1;
  (data->simulationInfo->realParameter[239] /* window.matGla.nStaReal PARAM */) = 1.0;
  data->modelData->realParameterData[239].time_unvarying = 1;
  (data->simulationInfo->realParameter[240] /* window.matGla.piMat PARAM */) = 3.968626966596886;
  data->modelData->realParameterData[240].time_unvarying = 1;
  (data->simulationInfo->realParameter[241] /* window.matGla.piRef PARAM */) = 331.4;
  data->modelData->realParameterData[241].time_unvarying = 1;
  (data->simulationInfo->realParameter[242] /* window.matGla.x PARAM */) = 0.003;
  data->modelData->realParameterData[242].time_unvarying = 1;
  (data->simulationInfo->realParameter[243] /* window.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[243].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[0] /* extCon.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[1] /* extCon.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[1].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[2] /* extCon.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[2].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[3] /* extCon.linearizeRadiation PARAM */) = 1;
  data->modelData->booleanParameterData[3].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[4] /* extCon.radOut.linearize PARAM */) = 1;
  data->modelData->booleanParameterData[4].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[5] /* extCon.shaCon.thisSideHasShade PARAM */) = 0;
  data->modelData->booleanParameterData[5].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[6] /* extCon.shaRad.linearize PARAM */) = 1;
  data->modelData->booleanParameterData[6].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[7] /* extCon.shaRad.thisSideHasShade PARAM */) = 0;
  data->modelData->booleanParameterData[7].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[8] /* extCon.shaSig.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[8].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[9] /* extCon.thisSideHasShade PARAM */) = 0;
  data->modelData->booleanParameterData[9].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[10] /* glaSys.haveControllableWindow PARAM */) = 0;
  data->modelData->booleanParameterData[10].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[11] /* glaSys.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[11].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[12] /* glaSys.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[12].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[13] /* glaSys.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[13].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[14] /* indRad.linearize PARAM */) = 1;
  data->modelData->booleanParameterData[14].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[15] /* intShaCon.conFra.is_ceiling PARAM */) = 0;
  data->modelData->booleanParameterData[15].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[16] /* intShaCon.conFra.is_floor PARAM */) = 0;
  data->modelData->booleanParameterData[16].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[17] /* intShaCon.conSha.thisSideHasShade PARAM */) = 1;
  data->modelData->booleanParameterData[17].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[18] /* intShaCon.conWinUns.is_ceiling PARAM */) = 0;
  data->modelData->booleanParameterData[18].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[19] /* intShaCon.conWinUns.is_floor PARAM */) = 0;
  data->modelData->booleanParameterData[19].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[20] /* intShaCon.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[20].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[21] /* intShaCon.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[21].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[22] /* intShaCon.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[22].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[23] /* intShaCon.shaSig.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[23].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[24] /* intShaCon.thisSideHasShade PARAM */) = 1;
  data->modelData->booleanParameterData[24].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[25] /* intShaRad.linearize PARAM */) = 1;
  data->modelData->booleanParameterData[25].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[26] /* intShaRad.thisSideHasShade PARAM */) = 1;
  data->modelData->booleanParameterData[26].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[27] /* linearize PARAM */) = 1;
  data->modelData->booleanParameterData[27].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[28] /* shaSig.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[28].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[29] /* window.glaSha.glaSys.haveControllableWindow PARAM */) = 0;
  data->modelData->booleanParameterData[29].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[30] /* window.glaSha.glaSys.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[30].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[31] /* window.glaSha.glaSys.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[31].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[32] /* window.glaSha.glaSys.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[32].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[33] /* window.glaSha.glass[1].linearize PARAM */) = 1;
  data->modelData->booleanParameterData[33].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[34] /* window.glaSha.have_GasLay PARAM */) = 0;
  data->modelData->booleanParameterData[34].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[35] /* window.glaSha.linearize PARAM */) = 1;
  data->modelData->booleanParameterData[35].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[36] /* window.glaSys.haveControllableWindow PARAM */) = 0;
  data->modelData->booleanParameterData[36].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[37] /* window.glaSys.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[37].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[38] /* window.glaSys.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[38].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[39] /* window.glaSys.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[39].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[40] /* window.glaUns.glaSys.haveControllableWindow PARAM */) = 0;
  data->modelData->booleanParameterData[40].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[41] /* window.glaUns.glaSys.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[41].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[42] /* window.glaUns.glaSys.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[42].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[43] /* window.glaUns.glaSys.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[43].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[44] /* window.glaUns.glass[1].linearize PARAM */) = 1;
  data->modelData->booleanParameterData[44].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[45] /* window.glaUns.have_GasLay PARAM */) = 0;
  data->modelData->booleanParameterData[45].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[46] /* window.glaUns.linearize PARAM */) = 1;
  data->modelData->booleanParameterData[46].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[47] /* window.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[47].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[48] /* window.linearize PARAM */) = 1;
  data->modelData->booleanParameterData[48].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[49] /* window.matFra.steadyState PARAM */) = 0;
  data->modelData->booleanParameterData[49].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[50] /* window.matGla.steadyState PARAM */) = 0;
  data->modelData->booleanParameterData[50].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[51] /* window.shaSig.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[51].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[52] /* window.steadyState PARAM */) = 1;
  data->modelData->booleanParameterData[52].time_unvarying = 1;
  (data->simulationInfo->integerParameter[0] /* intShaCon.conFra.conMod PARAM */) = 1;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[1] /* intShaCon.conMod PARAM */) = 1;
  data->modelData->integerParameterData[1].time_unvarying = 1;
  (data->simulationInfo->integerParameter[2] /* intShaCon.conWinUns.conMod PARAM */) = 1;
  data->modelData->integerParameterData[2].time_unvarying = 1;
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

