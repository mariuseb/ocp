#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustom/Buildings_HeatTransfer_Windows_Examples_WindowCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustom_10asr.c"
#endif
/* Asserts */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 542
type: ALGORITHM

  assert(window.JOutUns_b >= 0.0, "Variable violating min constraint: 0.0 <= window.JOutUns_b, has value: " + String(window.JOutUns_b, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_542(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,542};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,71,"Variable violating min constraint: 0.0 <= window.JOutUns_b, has value: ");
  modelica_string tmp2;
  modelica_metatype tmpMeta3;
  static int tmp4 = 0;
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
  if(!tmp4)
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
  {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    tmp0 = GreaterEq((data->localData[0]->realVars[69] /* window.JOutUns_b variable */),0.0);
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    if(!tmp0)
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      tmp2 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[69] /* window.JOutUns_b variable */), (modelica_string) mmc_strings_len1[103]);
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      tmpMeta3 = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        const char* assert_cond = "(window.JOutUns_b >= 0.0)";
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo",35,3,37,73,0};
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        } else {
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo",35,3,37,73,0};
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        }
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      }
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      tmp4 = 1;
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    }
#line 35 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
  }
#line 68 OMC_FILE
  TRACE_POP
}

/*
equation index: 543
type: ALGORITHM

  assert(window.JInUns_b >= 0.0, "Variable violating min constraint: 0.0 <= window.JInUns_b, has value: " + String(window.JInUns_b, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_543(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,543};
  modelica_boolean tmp5;
  static const MMC_DEFSTRINGLIT(tmp6,70,"Variable violating min constraint: 0.0 <= window.JInUns_b, has value: ");
  modelica_string tmp7;
  modelica_metatype tmpMeta8;
  static int tmp9 = 0;
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
  if(!tmp9)
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
  {
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    tmp5 = GreaterEq((data->localData[0]->realVars[68] /* window.JInUns_b variable */),0.0);
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    if(!tmp5)
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    {
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      tmp7 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[68] /* window.JInUns_b variable */), (modelica_string) mmc_strings_len1[103]);
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      tmpMeta8 = stringAppend(MMC_REFSTRINGLIT(tmp6),tmp7);
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      {
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        const char* assert_cond = "(window.JInUns_b >= 0.0)";
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo",38,3,40,71,0};
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        } else {
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo",38,3,40,71,0};
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
        }
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      }
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
      tmp9 = 1;
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
    }
#line 38 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Window.mo"
  }
#line 127 OMC_FILE
  TRACE_POP
}

/*
equation index: 544
type: ALGORITHM

  assert(window.glaUns.glass[1].T4_a >= 100000000.0, "Variable violating min constraint: 100000000.0 <= window.glaUns.glass[1].T4_a, has value: " + String(window.glaUns.glass[1].T4_a, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_544(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,544};
  modelica_boolean tmp10;
  static const MMC_DEFSTRINGLIT(tmp11,90,"Variable violating min constraint: 100000000.0 <= window.glaUns.glass[1].T4_a, has value: ");
  modelica_string tmp12;
  modelica_metatype tmpMeta13;
  static int tmp14 = 0;
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  if(!tmp14)
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    tmp10 = GreaterEq((data->localData[0]->realVars[81] /* window.glaUns.glass[1].T4_a variable */),100000000.0);
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    if(!tmp10)
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp12 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[81] /* window.glaUns.glass[1].T4_a variable */), (modelica_string) mmc_strings_len1[103]);
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmpMeta13 = stringAppend(MMC_REFSTRINGLIT(tmp11),tmp12);
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        const char* assert_cond = "(window.glaUns.glass[1].T4_a >= 100000000.0)";
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",37,2,38,44,0};
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta13));
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        } else {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",37,2,38,44,0};
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta13));
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        }
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      }
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp14 = 1;
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    }
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  }
#line 186 OMC_FILE
  TRACE_POP
}

/*
equation index: 545
type: ALGORITHM

  assert(window.glaUns.glass[1].T4_b >= 100000000.0, "Variable violating min constraint: 100000000.0 <= window.glaUns.glass[1].T4_b, has value: " + String(window.glaUns.glass[1].T4_b, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_545(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,545};
  modelica_boolean tmp15;
  static const MMC_DEFSTRINGLIT(tmp16,90,"Variable violating min constraint: 100000000.0 <= window.glaUns.glass[1].T4_b, has value: ");
  modelica_string tmp17;
  modelica_metatype tmpMeta18;
  static int tmp19 = 0;
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  if(!tmp19)
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    tmp15 = GreaterEq((data->localData[0]->realVars[82] /* window.glaUns.glass[1].T4_b variable */),100000000.0);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    if(!tmp15)
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp17 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[82] /* window.glaUns.glass[1].T4_b variable */), (modelica_string) mmc_strings_len1[103]);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmpMeta18 = stringAppend(MMC_REFSTRINGLIT(tmp16),tmp17);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        const char* assert_cond = "(window.glaUns.glass[1].T4_b >= 100000000.0)";
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",39,2,40,44,0};
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta18));
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        } else {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",39,2,40,44,0};
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta18));
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        }
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      }
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp19 = 1;
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    }
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  }
#line 245 OMC_FILE
  TRACE_POP
}

/*
equation index: 546
type: ALGORITHM

  assert(window.glaUns.glass[1].E_a >= 0.0, "Variable violating min constraint: 0.0 <= window.glaUns.glass[1].E_a, has value: " + String(window.glaUns.glass[1].E_a, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_546(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,546};
  modelica_boolean tmp20;
  static const MMC_DEFSTRINGLIT(tmp21,81,"Variable violating min constraint: 0.0 <= window.glaUns.glass[1].E_a, has value: ");
  modelica_string tmp22;
  modelica_metatype tmpMeta23;
  static int tmp24 = 0;
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  if(!tmp24)
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    tmp20 = GreaterEq((data->localData[0]->realVars[79] /* window.glaUns.glass[1].E_a variable */),0.0);
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    if(!tmp20)
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp22 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[79] /* window.glaUns.glass[1].E_a variable */), (modelica_string) mmc_strings_len1[103]);
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmpMeta23 = stringAppend(MMC_REFSTRINGLIT(tmp21),tmp22);
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        const char* assert_cond = "(window.glaUns.glass[1].E_a >= 0.0)";
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",41,3,42,34,0};
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta23));
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        } else {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",41,3,42,34,0};
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta23));
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        }
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      }
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp24 = 1;
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    }
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  }
#line 304 OMC_FILE
  TRACE_POP
}

/*
equation index: 547
type: ALGORITHM

  assert(window.glaUns.glass[1].E_b >= 0.0, "Variable violating min constraint: 0.0 <= window.glaUns.glass[1].E_b, has value: " + String(window.glaUns.glass[1].E_b, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_547(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,547};
  modelica_boolean tmp25;
  static const MMC_DEFSTRINGLIT(tmp26,81,"Variable violating min constraint: 0.0 <= window.glaUns.glass[1].E_b, has value: ");
  modelica_string tmp27;
  modelica_metatype tmpMeta28;
  static int tmp29 = 0;
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  if(!tmp29)
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    tmp25 = GreaterEq((data->localData[0]->realVars[80] /* window.glaUns.glass[1].E_b variable */),0.0);
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    if(!tmp25)
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp27 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[80] /* window.glaUns.glass[1].E_b variable */), (modelica_string) mmc_strings_len1[103]);
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmpMeta28 = stringAppend(MMC_REFSTRINGLIT(tmp26),tmp27);
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        const char* assert_cond = "(window.glaUns.glass[1].E_b >= 0.0)";
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",43,3,44,34,0};
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta28));
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        } else {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",43,3,44,34,0};
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta28));
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        }
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      }
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp29 = 1;
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    }
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  }
#line 363 OMC_FILE
  TRACE_POP
}

/*
equation index: 548
type: ALGORITHM

  assert(window.glaSha.glass[1].T4_a >= 100000000.0, "Variable violating min constraint: 100000000.0 <= window.glaSha.glass[1].T4_a, has value: " + String(window.glaSha.glass[1].T4_a, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_548(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,548};
  modelica_boolean tmp30;
  static const MMC_DEFSTRINGLIT(tmp31,90,"Variable violating min constraint: 100000000.0 <= window.glaSha.glass[1].T4_a, has value: ");
  modelica_string tmp32;
  modelica_metatype tmpMeta33;
  static int tmp34 = 0;
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  if(!tmp34)
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    tmp30 = GreaterEq((data->localData[0]->realVars[75] /* window.glaSha.glass[1].T4_a variable */),100000000.0);
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    if(!tmp30)
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp32 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[75] /* window.glaSha.glass[1].T4_a variable */), (modelica_string) mmc_strings_len1[103]);
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmpMeta33 = stringAppend(MMC_REFSTRINGLIT(tmp31),tmp32);
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        const char* assert_cond = "(window.glaSha.glass[1].T4_a >= 100000000.0)";
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",37,2,38,44,0};
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta33));
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        } else {
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",37,2,38,44,0};
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta33));
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        }
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      }
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp34 = 1;
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    }
#line 37 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  }
#line 422 OMC_FILE
  TRACE_POP
}

/*
equation index: 549
type: ALGORITHM

  assert(window.glaSha.glass[1].T4_b >= 100000000.0, "Variable violating min constraint: 100000000.0 <= window.glaSha.glass[1].T4_b, has value: " + String(window.glaSha.glass[1].T4_b, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_549(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,549};
  modelica_boolean tmp35;
  static const MMC_DEFSTRINGLIT(tmp36,90,"Variable violating min constraint: 100000000.0 <= window.glaSha.glass[1].T4_b, has value: ");
  modelica_string tmp37;
  modelica_metatype tmpMeta38;
  static int tmp39 = 0;
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  if(!tmp39)
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    tmp35 = GreaterEq((data->localData[0]->realVars[76] /* window.glaSha.glass[1].T4_b variable */),100000000.0);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    if(!tmp35)
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp37 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[76] /* window.glaSha.glass[1].T4_b variable */), (modelica_string) mmc_strings_len1[103]);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmpMeta38 = stringAppend(MMC_REFSTRINGLIT(tmp36),tmp37);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        const char* assert_cond = "(window.glaSha.glass[1].T4_b >= 100000000.0)";
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",39,2,40,44,0};
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta38));
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        } else {
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",39,2,40,44,0};
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta38));
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        }
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      }
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp39 = 1;
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    }
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  }
#line 481 OMC_FILE
  TRACE_POP
}

/*
equation index: 550
type: ALGORITHM

  assert(window.glaSha.glass[1].E_a >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSha.glass[1].E_a, has value: " + String(window.glaSha.glass[1].E_a, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_550(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,550};
  modelica_boolean tmp40;
  static const MMC_DEFSTRINGLIT(tmp41,81,"Variable violating min constraint: 0.0 <= window.glaSha.glass[1].E_a, has value: ");
  modelica_string tmp42;
  modelica_metatype tmpMeta43;
  static int tmp44 = 0;
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  if(!tmp44)
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    tmp40 = GreaterEq((data->localData[0]->realVars[73] /* window.glaSha.glass[1].E_a variable */),0.0);
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    if(!tmp40)
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp42 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[73] /* window.glaSha.glass[1].E_a variable */), (modelica_string) mmc_strings_len1[103]);
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmpMeta43 = stringAppend(MMC_REFSTRINGLIT(tmp41),tmp42);
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        const char* assert_cond = "(window.glaSha.glass[1].E_a >= 0.0)";
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",41,3,42,34,0};
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta43));
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        } else {
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",41,3,42,34,0};
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta43));
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        }
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      }
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp44 = 1;
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    }
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  }
#line 540 OMC_FILE
  TRACE_POP
}

/*
equation index: 551
type: ALGORITHM

  assert(window.glaSha.glass[1].E_b >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSha.glass[1].E_b, has value: " + String(window.glaSha.glass[1].E_b, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_551(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,551};
  modelica_boolean tmp45;
  static const MMC_DEFSTRINGLIT(tmp46,81,"Variable violating min constraint: 0.0 <= window.glaSha.glass[1].E_b, has value: ");
  modelica_string tmp47;
  modelica_metatype tmpMeta48;
  static int tmp49 = 0;
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  if(!tmp49)
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    tmp45 = GreaterEq((data->localData[0]->realVars[74] /* window.glaSha.glass[1].E_b variable */),0.0);
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    if(!tmp45)
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp47 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[74] /* window.glaSha.glass[1].E_b variable */), (modelica_string) mmc_strings_len1[103]);
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmpMeta48 = stringAppend(MMC_REFSTRINGLIT(tmp46),tmp47);
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        const char* assert_cond = "(window.glaSha.glass[1].E_b >= 0.0)";
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",43,3,44,34,0};
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta48));
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        } else {
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo",43,3,44,34,0};
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta48));
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
        }
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      }
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
      tmp49 = 1;
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
    }
#line 43 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  }
#line 599 OMC_FILE
  TRACE_POP
}

/*
equation index: 552
type: ALGORITHM

  assert(window.glaUns_a.T >= 0.0, "Variable violating min constraint: 0.0 <= window.glaUns_a.T, has value: " + String(window.glaUns_a.T, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_552(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,552};
  modelica_boolean tmp50;
  static const MMC_DEFSTRINGLIT(tmp51,72,"Variable violating min constraint: 0.0 <= window.glaUns_a.T, has value: ");
  modelica_string tmp52;
  modelica_metatype tmpMeta53;
  static int tmp54 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp54)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp50 = GreaterEq((data->localData[0]->realVars[84] /* window.glaUns_a.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp50)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp52 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[84] /* window.glaUns_a.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta53 = stringAppend(MMC_REFSTRINGLIT(tmp51),tmp52);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(window.glaUns_a.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta53));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta53));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp54 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 658 OMC_FILE
  TRACE_POP
}

/*
equation index: 553
type: ALGORITHM

  assert(window.glaUns_b.T >= 0.0, "Variable violating min constraint: 0.0 <= window.glaUns_b.T, has value: " + String(window.glaUns_b.T, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_553(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,553};
  modelica_boolean tmp55;
  static const MMC_DEFSTRINGLIT(tmp56,72,"Variable violating min constraint: 0.0 <= window.glaUns_b.T, has value: ");
  modelica_string tmp57;
  modelica_metatype tmpMeta58;
  static int tmp59 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp59)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp55 = GreaterEq((data->localData[0]->realVars[85] /* window.glaUns_b.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp55)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp57 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[85] /* window.glaUns_b.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta58 = stringAppend(MMC_REFSTRINGLIT(tmp56),tmp57);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(window.glaUns_b.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta58));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta58));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp59 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 717 OMC_FILE
  TRACE_POP
}

/*
equation index: 554
type: ALGORITHM

  assert(window.glaSha_a.T >= 0.0, "Variable violating min constraint: 0.0 <= window.glaSha_a.T, has value: " + String(window.glaSha_a.T, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_554(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,554};
  modelica_boolean tmp60;
  static const MMC_DEFSTRINGLIT(tmp61,72,"Variable violating min constraint: 0.0 <= window.glaSha_a.T, has value: ");
  modelica_string tmp62;
  modelica_metatype tmpMeta63;
  static int tmp64 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp64)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp60 = GreaterEq((data->localData[0]->realVars[78] /* window.glaSha_a.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp60)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp62 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[78] /* window.glaSha_a.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta63 = stringAppend(MMC_REFSTRINGLIT(tmp61),tmp62);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(window.glaSha_a.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp64 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 776 OMC_FILE
  TRACE_POP
}

/*
equation index: 555
type: ALGORITHM

  assert(window.fra_a.T >= 0.0, "Variable violating min constraint: 0.0 <= window.fra_a.T, has value: " + String(window.fra_a.T, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_555(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,555};
  modelica_boolean tmp65;
  static const MMC_DEFSTRINGLIT(tmp66,69,"Variable violating min constraint: 0.0 <= window.fra_a.T, has value: ");
  modelica_string tmp67;
  modelica_metatype tmpMeta68;
  static int tmp69 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp69)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp65 = GreaterEq((data->localData[0]->realVars[70] /* window.fra_a.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp65)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp67 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[70] /* window.fra_a.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta68 = stringAppend(MMC_REFSTRINGLIT(tmp66),tmp67);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(window.fra_a.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp69 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 835 OMC_FILE
  TRACE_POP
}

/*
equation index: 556
type: ALGORITHM

  assert(window.fra_b.T >= 0.0, "Variable violating min constraint: 0.0 <= window.fra_b.T, has value: " + String(window.fra_b.T, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_556(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,556};
  modelica_boolean tmp70;
  static const MMC_DEFSTRINGLIT(tmp71,69,"Variable violating min constraint: 0.0 <= window.fra_b.T, has value: ");
  modelica_string tmp72;
  modelica_metatype tmpMeta73;
  static int tmp74 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp74)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp70 = GreaterEq((data->localData[0]->realVars[71] /* window.fra_b.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp70)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp72 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[71] /* window.fra_b.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta73 = stringAppend(MMC_REFSTRINGLIT(tmp71),tmp72);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(window.fra_b.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta73));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta73));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp74 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 894 OMC_FILE
  TRACE_POP
}

/*
equation index: 557
type: ALGORITHM

  assert(extCon.radOut.TRad >= 0.0, "Variable violating min constraint: 0.0 <= extCon.radOut.TRad, has value: " + String(extCon.radOut.TRad, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_557(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,557};
  modelica_boolean tmp75;
  static const MMC_DEFSTRINGLIT(tmp76,73,"Variable violating min constraint: 0.0 <= extCon.radOut.TRad, has value: ");
  modelica_string tmp77;
  modelica_metatype tmpMeta78;
  static int tmp79 = 0;
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  if(!tmp79)
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  {
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    tmp75 = GreaterEq((data->localData[0]->realVars[22] /* extCon.radOut.TRad variable */),0.0);
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    if(!tmp75)
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    {
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp77 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[22] /* extCon.radOut.TRad variable */), (modelica_string) mmc_strings_len1[103]);
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmpMeta78 = stringAppend(MMC_REFSTRINGLIT(tmp76),tmp77);
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      {
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        const char* assert_cond = "(extCon.radOut.TRad >= 0.0)";
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",13,3,13,64,0};
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta78));
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        } else {
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",13,3,13,64,0};
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta78));
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        }
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      }
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp79 = 1;
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    }
#line 13 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  }
#line 953 OMC_FILE
  TRACE_POP
}

/*
equation index: 558
type: ALGORITHM

  assert(extCon.radOut.JOut >= 0.0, "Variable violating min constraint: 0.0 <= extCon.radOut.JOut, has value: " + String(extCon.radOut.JOut, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_558(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,558};
  modelica_boolean tmp80;
  static const MMC_DEFSTRINGLIT(tmp81,73,"Variable violating min constraint: 0.0 <= extCon.radOut.JOut, has value: ");
  modelica_string tmp82;
  modelica_metatype tmpMeta83;
  static int tmp84 = 0;
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  if(!tmp84)
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    tmp80 = GreaterEq((data->localData[0]->realVars[21] /* extCon.radOut.JOut variable */),0.0);
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    if(!tmp80)
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp82 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[21] /* extCon.radOut.JOut variable */), (modelica_string) mmc_strings_len1[103]);
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmpMeta83 = stringAppend(MMC_REFSTRINGLIT(tmp81),tmp82);
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        const char* assert_cond = "(extCon.radOut.JOut >= 0.0)";
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",27,3,30,36,0};
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta83));
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        } else {
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo",27,3,30,36,0};
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta83));
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
        }
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      }
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
      tmp84 = 1;
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
    }
#line 27 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  }
#line 1012 OMC_FILE
  TRACE_POP
}

/*
equation index: 559
type: ALGORITHM

  assert(extCon.JOutUns >= 0.0, "Variable violating min constraint: 0.0 <= extCon.JOutUns, has value: " + String(extCon.JOutUns, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_559(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,559};
  modelica_boolean tmp85;
  static const MMC_DEFSTRINGLIT(tmp86,69,"Variable violating min constraint: 0.0 <= extCon.JOutUns, has value: ");
  modelica_string tmp87;
  modelica_metatype tmpMeta88;
  static int tmp89 = 0;
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  if(!tmp89)
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  {
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    tmp85 = GreaterEq((data->localData[0]->realVars[13] /* extCon.JOutUns variable */),0.0);
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    if(!tmp85)
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    {
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp87 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[13] /* extCon.JOutUns variable */), (modelica_string) mmc_strings_len1[103]);
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmpMeta88 = stringAppend(MMC_REFSTRINGLIT(tmp86),tmp87);
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      {
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        const char* assert_cond = "(extCon.JOutUns >= 0.0)";
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",51,3,53,71,0};
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta88));
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        } else {
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",51,3,53,71,0};
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta88));
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        }
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      }
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp89 = 1;
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    }
#line 51 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  }
#line 1071 OMC_FILE
  TRACE_POP
}

/*
equation index: 560
type: ALGORITHM

  assert(extCon.JInUns >= 0.0, "Variable violating min constraint: 0.0 <= extCon.JInUns, has value: " + String(extCon.JInUns, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_560(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,560};
  modelica_boolean tmp90;
  static const MMC_DEFSTRINGLIT(tmp91,68,"Variable violating min constraint: 0.0 <= extCon.JInUns, has value: ");
  modelica_string tmp92;
  modelica_metatype tmpMeta93;
  static int tmp94 = 0;
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  if(!tmp94)
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  {
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    tmp90 = GreaterEq((data->localData[0]->realVars[11] /* extCon.JInUns variable */),0.0);
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    if(!tmp90)
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    {
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp92 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[11] /* extCon.JInUns variable */), (modelica_string) mmc_strings_len1[103]);
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmpMeta93 = stringAppend(MMC_REFSTRINGLIT(tmp91),tmp92);
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      {
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        const char* assert_cond = "(extCon.JInUns >= 0.0)";
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",54,3,56,71,0};
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta93));
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        } else {
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",54,3,56,71,0};
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta93));
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        }
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      }
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp94 = 1;
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    }
#line 54 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  }
#line 1130 OMC_FILE
  TRACE_POP
}

/*
equation index: 561
type: ALGORITHM

  assert(extCon.JOutSha >= 0.0, "Variable violating min constraint: 0.0 <= extCon.JOutSha, has value: " + String(extCon.JOutSha, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_561(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,561};
  modelica_boolean tmp95;
  static const MMC_DEFSTRINGLIT(tmp96,69,"Variable violating min constraint: 0.0 <= extCon.JOutSha, has value: ");
  modelica_string tmp97;
  modelica_metatype tmpMeta98;
  static int tmp99 = 0;
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  if(!tmp99)
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  {
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    tmp95 = GreaterEq((data->localData[0]->realVars[12] /* extCon.JOutSha variable */),0.0);
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    if(!tmp95)
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    {
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp97 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[12] /* extCon.JOutSha variable */), (modelica_string) mmc_strings_len1[103]);
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmpMeta98 = stringAppend(MMC_REFSTRINGLIT(tmp96),tmp97);
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      {
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        const char* assert_cond = "(extCon.JOutSha >= 0.0)";
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",57,3,59,73,0};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta98));
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        } else {
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",57,3,59,73,0};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta98));
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        }
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      }
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp99 = 1;
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    }
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  }
#line 1189 OMC_FILE
  TRACE_POP
}

/*
equation index: 562
type: ALGORITHM

  assert(extCon.JInSha >= 0.0, "Variable violating min constraint: 0.0 <= extCon.JInSha, has value: " + String(extCon.JInSha, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_562(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,562};
  modelica_boolean tmp100;
  static const MMC_DEFSTRINGLIT(tmp101,68,"Variable violating min constraint: 0.0 <= extCon.JInSha, has value: ");
  modelica_string tmp102;
  modelica_metatype tmpMeta103;
  static int tmp104 = 0;
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  if(!tmp104)
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  {
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    tmp100 = GreaterEq((data->localData[0]->realVars[10] /* extCon.JInSha variable */),0.0);
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    if(!tmp100)
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    {
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp102 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[10] /* extCon.JInSha variable */), (modelica_string) mmc_strings_len1[103]);
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmpMeta103 = stringAppend(MMC_REFSTRINGLIT(tmp101),tmp102);
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      {
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        const char* assert_cond = "(extCon.JInSha >= 0.0)";
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",60,3,62,73,0};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta103));
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        } else {
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo",60,3,62,73,0};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta103));
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
        }
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      }
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
      tmp104 = 1;
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
    }
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/ExteriorHeatTransfer.mo"
  }
#line 1248 OMC_FILE
  TRACE_POP
}

/*
equation index: 563
type: ALGORITHM

  assert(extCon.shaRad.u >= 0.0 and extCon.shaRad.u <= 1.0, "Variable violating min/max constraint: 0.0 <= extCon.shaRad.u <= 1.0, has value: " + String(extCon.shaRad.u, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_563(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,563};
  modelica_boolean tmp105;
  modelica_boolean tmp106;
  static const MMC_DEFSTRINGLIT(tmp107,81,"Variable violating min/max constraint: 0.0 <= extCon.shaRad.u <= 1.0, has value: ");
  modelica_string tmp108;
  modelica_metatype tmpMeta109;
  static int tmp110 = 0;
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp110)
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp105 = GreaterEq((data->localData[0]->realVars[31] /* extCon.shaRad.u variable */),0.0);
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp106 = LessEq((data->localData[0]->realVars[31] /* extCon.shaRad.u variable */),1.0);
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!(tmp105 && tmp106))
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp108 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[31] /* extCon.shaRad.u variable */), (modelica_string) mmc_strings_len1[103]);
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta109 = stringAppend(MMC_REFSTRINGLIT(tmp107),tmp108);
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(extCon.shaRad.u >= 0.0 and extCon.shaRad.u <= 1.0)";
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",31,3,34,59,0};
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta109));
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",31,3,34,59,0};
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta109));
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp110 = 1;
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 31 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 1310 OMC_FILE
  TRACE_POP
}

/*
equation index: 564
type: ALGORITHM

  assert(uSha.y >= 0.0 and uSha.y <= 1.0, "Variable violating min/max constraint: 0.0 <= uSha.y <= 1.0, has value: " + String(uSha.y, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_564(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,564};
  modelica_boolean tmp111;
  modelica_boolean tmp112;
  static const MMC_DEFSTRINGLIT(tmp113,72,"Variable violating min/max constraint: 0.0 <= uSha.y <= 1.0, has value: ");
  modelica_string tmp114;
  modelica_metatype tmpMeta115;
  static int tmp116 = 0;
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  if(!tmp116)
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    tmp111 = GreaterEq((data->localData[0]->realVars[66] /* uSha.y variable */),0.0);
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    tmp112 = LessEq((data->localData[0]->realVars[66] /* uSha.y variable */),1.0);
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    if(!(tmp111 && tmp112))
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmp114 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[66] /* uSha.y variable */), (modelica_string) mmc_strings_len1[103]);
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmpMeta115 = stringAppend(MMC_REFSTRINGLIT(tmp113),tmp114);
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        const char* assert_cond = "(uSha.y >= 0.0 and uSha.y <= 1.0)";
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo",300,5,301,56,0};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta115));
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        } else {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo",300,5,301,56,0};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta115));
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        }
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      }
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmp116 = 1;
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    }
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  }
#line 1372 OMC_FILE
  TRACE_POP
}

/*
equation index: 565
type: ALGORITHM

  assert(indRad.JIn >= 0.0, "Variable violating min constraint: 0.0 <= indRad.JIn, has value: " + String(indRad.JIn, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_565(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,565};
  modelica_boolean tmp117;
  static const MMC_DEFSTRINGLIT(tmp118,65,"Variable violating min constraint: 0.0 <= indRad.JIn, has value: ");
  modelica_string tmp119;
  modelica_metatype tmpMeta120;
  static int tmp121 = 0;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
  if(!tmp121)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
  {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
    tmp117 = GreaterEq((data->localData[0]->realVars[37] /* indRad.JIn variable */),0.0);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
    if(!tmp117)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
    {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
      tmp119 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[37] /* indRad.JIn variable */), (modelica_string) mmc_strings_len1[103]);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
      tmpMeta120 = stringAppend(MMC_REFSTRINGLIT(tmp118),tmp119);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
      {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
        const char* assert_cond = "(indRad.JIn >= 0.0)";
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo",7,3,9,73,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta120));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
        } else {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo",7,3,9,73,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta120));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
        }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
      }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
      tmp121 = 1;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
    }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/BaseClasses/RadiosityOneSurface.mo"
  }
#line 1431 OMC_FILE
  TRACE_POP
}

/*
equation index: 566
type: ALGORITHM

  assert(indRad.T4 >= 100000000.0, "Variable violating min constraint: 100000000.0 <= indRad.T4, has value: " + String(indRad.T4, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_566(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,566};
  modelica_boolean tmp122;
  static const MMC_DEFSTRINGLIT(tmp123,72,"Variable violating min constraint: 100000000.0 <= indRad.T4, has value: ");
  modelica_string tmp124;
  modelica_metatype tmpMeta125;
  static int tmp126 = 0;
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
  if(!tmp126)
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
  {
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
    tmp122 = GreaterEq((data->localData[0]->realVars[38] /* indRad.T4 variable */),100000000.0);
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
    if(!tmp122)
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
    {
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      tmp124 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[38] /* indRad.T4 variable */), (modelica_string) mmc_strings_len1[103]);
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      tmpMeta125 = stringAppend(MMC_REFSTRINGLIT(tmp123),tmp124);
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      {
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
        const char* assert_cond = "(indRad.T4 >= 100000000.0)";
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo",15,3,19,48,0};
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta125));
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
        } else {
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo",15,3,19,48,0};
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta125));
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
        }
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      }
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
      tmp126 = 1;
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
    }
#line 15 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
  }
#line 1490 OMC_FILE
  TRACE_POP
}

/*
equation index: 567
type: ALGORITHM

  assert(intShaRad.JIn_air >= 0.0, "Variable violating min constraint: 0.0 <= intShaRad.JIn_air, has value: " + String(intShaRad.JIn_air, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_567(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,567};
  modelica_boolean tmp127;
  static const MMC_DEFSTRINGLIT(tmp128,72,"Variable violating min constraint: 0.0 <= intShaRad.JIn_air, has value: ");
  modelica_string tmp129;
  modelica_metatype tmpMeta130;
  static int tmp131 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp131)
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp127 = GreaterEq((data->localData[0]->realVars[57] /* intShaRad.JIn_air variable */),0.0);
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!tmp127)
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp129 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[57] /* intShaRad.JIn_air variable */), (modelica_string) mmc_strings_len1[103]);
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta130 = stringAppend(MMC_REFSTRINGLIT(tmp128),tmp129);
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(intShaRad.JIn_air >= 0.0)";
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",46,3,48,75,0};
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta130));
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",46,3,48,75,0};
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta130));
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp131 = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 1549 OMC_FILE
  TRACE_POP
}

/*
equation index: 568
type: ALGORITHM

  assert(intShaRad.JIn_glass >= 0.0, "Variable violating min constraint: 0.0 <= intShaRad.JIn_glass, has value: " + String(intShaRad.JIn_glass, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_568(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,568};
  modelica_boolean tmp132;
  static const MMC_DEFSTRINGLIT(tmp133,74,"Variable violating min constraint: 0.0 <= intShaRad.JIn_glass, has value: ");
  modelica_string tmp134;
  modelica_metatype tmpMeta135;
  static int tmp136 = 0;
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp136)
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp132 = GreaterEq((data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */),0.0);
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!tmp132)
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp134 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */), (modelica_string) mmc_strings_len1[103]);
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta135 = stringAppend(MMC_REFSTRINGLIT(tmp133),tmp134);
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(intShaRad.JIn_glass >= 0.0)";
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",49,3,51,73,0};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta135));
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",49,3,51,73,0};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta135));
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp136 = 1;
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 1608 OMC_FILE
  TRACE_POP
}

/*
equation index: 569
type: ALGORITHM

  assert(intShaRad.JOut_air >= 0.0, "Variable violating min constraint: 0.0 <= intShaRad.JOut_air, has value: " + String(intShaRad.JOut_air, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_569(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,569};
  modelica_boolean tmp137;
  static const MMC_DEFSTRINGLIT(tmp138,73,"Variable violating min constraint: 0.0 <= intShaRad.JOut_air, has value: ");
  modelica_string tmp139;
  modelica_metatype tmpMeta140;
  static int tmp141 = 0;
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp141)
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp137 = GreaterEq((data->localData[0]->realVars[59] /* intShaRad.JOut_air variable */),0.0);
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!tmp137)
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp139 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[59] /* intShaRad.JOut_air variable */), (modelica_string) mmc_strings_len1[103]);
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta140 = stringAppend(MMC_REFSTRINGLIT(tmp138),tmp139);
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(intShaRad.JOut_air >= 0.0)";
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",52,3,54,75,0};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta140));
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",52,3,54,75,0};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta140));
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp141 = 1;
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 1667 OMC_FILE
  TRACE_POP
}

/*
equation index: 570
type: ALGORITHM

  assert(intShaRad.JOut_glass >= 0.0, "Variable violating min constraint: 0.0 <= intShaRad.JOut_glass, has value: " + String(intShaRad.JOut_glass, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_570(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,570};
  modelica_boolean tmp142;
  static const MMC_DEFSTRINGLIT(tmp143,75,"Variable violating min constraint: 0.0 <= intShaRad.JOut_glass, has value: ");
  modelica_string tmp144;
  modelica_metatype tmpMeta145;
  static int tmp146 = 0;
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp146)
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp142 = GreaterEq((data->localData[0]->realVars[60] /* intShaRad.JOut_glass variable */),0.0);
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!tmp142)
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp144 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[60] /* intShaRad.JOut_glass variable */), (modelica_string) mmc_strings_len1[103]);
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta145 = stringAppend(MMC_REFSTRINGLIT(tmp143),tmp144);
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(intShaRad.JOut_glass >= 0.0)";
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",55,3,57,73,0};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta145));
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",55,3,57,73,0};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta145));
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp146 = 1;
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 1726 OMC_FILE
  TRACE_POP
}

/*
equation index: 571
type: ALGORITHM

  assert(intShaRad.T4 >= 100000000.0, "Variable violating min constraint: 100000000.0 <= intShaRad.T4, has value: " + String(intShaRad.T4, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_571(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,571};
  modelica_boolean tmp147;
  static const MMC_DEFSTRINGLIT(tmp148,75,"Variable violating min constraint: 100000000.0 <= intShaRad.T4, has value: ");
  modelica_string tmp149;
  modelica_metatype tmpMeta150;
  static int tmp151 = 0;
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  if(!tmp151)
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  {
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    tmp147 = GreaterEq((data->localData[0]->realVars[61] /* intShaRad.T4 variable */),100000000.0);
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    if(!tmp147)
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    {
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp149 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[61] /* intShaRad.T4 variable */), (modelica_string) mmc_strings_len1[103]);
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmpMeta150 = stringAppend(MMC_REFSTRINGLIT(tmp148),tmp149);
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      {
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        const char* assert_cond = "(intShaRad.T4 >= 100000000.0)";
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",86,2,87,31,0};
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta150));
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        } else {
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo",86,2,87,31,0};
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta150));
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
        }
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      }
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
      tmp151 = 1;
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
    }
#line 86 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  }
#line 1785 OMC_FILE
  TRACE_POP
}

/*
equation index: 572
type: ALGORITHM

  assert(shaSig.y >= 0.0 and shaSig.y <= 1.0, "Variable violating min/max constraint: 0.0 <= shaSig.y <= 1.0, has value: " + String(shaSig.y, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_572(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,572};
  modelica_boolean tmp152;
  modelica_boolean tmp153;
  static const MMC_DEFSTRINGLIT(tmp154,74,"Variable violating min/max constraint: 0.0 <= shaSig.y <= 1.0, has value: ");
  modelica_string tmp155;
  modelica_metatype tmpMeta156;
  static int tmp157 = 0;
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  if(!tmp157)
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    tmp152 = GreaterEq((data->localData[0]->realVars[62] /* shaSig.y variable */),0.0);
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    tmp153 = LessEq((data->localData[0]->realVars[62] /* shaSig.y variable */),1.0);
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    if(!(tmp152 && tmp153))
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmp155 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[62] /* shaSig.y variable */), (modelica_string) mmc_strings_len1[103]);
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmpMeta156 = stringAppend(MMC_REFSTRINGLIT(tmp154),tmp155);
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        const char* assert_cond = "(shaSig.y >= 0.0 and shaSig.y <= 1.0)";
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo",300,5,301,56,0};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta156));
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        } else {
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo",300,5,301,56,0};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta156));
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        }
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      }
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmp157 = 1;
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    }
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  }
#line 1847 OMC_FILE
  TRACE_POP
}

/*
equation index: 573
type: ALGORITHM

  assert(intShaCon.glaSha.T >= 0.0, "Variable violating min constraint: 0.0 <= intShaCon.glaSha.T, has value: " + String(intShaCon.glaSha.T, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_573(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,573};
  modelica_boolean tmp158;
  static const MMC_DEFSTRINGLIT(tmp159,73,"Variable violating min constraint: 0.0 <= intShaCon.glaSha.T, has value: ");
  modelica_string tmp160;
  modelica_metatype tmpMeta161;
  static int tmp162 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp162)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp158 = GreaterEq((data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp158)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp160 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta161 = stringAppend(MMC_REFSTRINGLIT(tmp159),tmp160);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(intShaCon.glaSha.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta161));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta161));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp162 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 1906 OMC_FILE
  TRACE_POP
}

/*
equation index: 574
type: ALGORITHM

  assert(heatFlowSensor.port_a.T >= 0.0, "Variable violating min constraint: 0.0 <= heatFlowSensor.port_a.T, has value: " + String(heatFlowSensor.port_a.T, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_574(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,574};
  modelica_boolean tmp163;
  static const MMC_DEFSTRINGLIT(tmp164,78,"Variable violating min constraint: 0.0 <= heatFlowSensor.port_a.T, has value: ");
  modelica_string tmp165;
  modelica_metatype tmpMeta166;
  static int tmp167 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp167)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp163 = GreaterEq((data->localData[0]->realVars[33] /* heatFlowSensor.port_a.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp163)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp165 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[33] /* heatFlowSensor.port_a.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta166 = stringAppend(MMC_REFSTRINGLIT(tmp164),tmp165);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(heatFlowSensor.port_a.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta166));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta166));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp167 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 1965 OMC_FILE
  TRACE_POP
}

/*
equation index: 575
type: ALGORITHM

  assert(heatFlowSensor1.port_a.T >= 0.0, "Variable violating min constraint: 0.0 <= heatFlowSensor1.port_a.T, has value: " + String(heatFlowSensor1.port_a.T, "g"));
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_575(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,575};
  modelica_boolean tmp168;
  static const MMC_DEFSTRINGLIT(tmp169,79,"Variable violating min constraint: 0.0 <= heatFlowSensor1.port_a.T, has value: ");
  modelica_string tmp170;
  modelica_metatype tmpMeta171;
  static int tmp172 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp172)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp168 = GreaterEq((data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */),0.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!tmp168)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp170 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta171 = stringAppend(MMC_REFSTRINGLIT(tmp169),tmp170);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(heatFlowSensor1.port_a.T >= 0.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta171));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta171));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp172 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 2024 OMC_FILE
  TRACE_POP
}
/* function to check assert after a step is done */
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_542(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_543(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_544(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_545(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_546(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_547(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_548(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_549(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_550(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_551(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_552(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_553(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_554(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_555(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_556(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_557(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_558(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_559(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_560(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_561(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_562(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_563(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_564(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_565(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_566(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_567(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_568(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_569(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_570(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_571(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_572(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_573(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_574(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_575(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

