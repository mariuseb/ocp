#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit.fmutmp/sources/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_10asr.c"
#endif
/* Asserts */
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 935
type: ALGORITHM

  assert(fan.filter.y >= 0.0 and fan.filter.y <= 100000.0, "Variable violating min/max constraint: 0.0 <= fan.filter.y <= 100000.0, has value: " + String(fan.filter.y, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_935(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,935};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,83,"Variable violating min/max constraint: 0.0 <= fan.filter.y <= 100000.0, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  if(!tmp5)
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  {
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    tmp0 = GreaterEq((data->localData[0]->realVars[40] /* fan.filter.y variable */),0.0);
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    tmp1 = LessEq((data->localData[0]->realVars[40] /* fan.filter.y variable */),100000.0);
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    if(!(tmp0 && tmp1))
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    {
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmp3 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[40] /* fan.filter.y variable */), (modelica_string) mmc_strings_len1[103]);
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      {
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        const char* assert_cond = "(fan.filter.y >= 0.0 and fan.filter.y <= 100000.0)";
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo",329,5,330,56,0};
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        } else {
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo",329,5,330,56,0};
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
        }
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      }
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
      tmp5 = 1;
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
    }
#line 329 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  }
#line 71 OMC_FILE
  TRACE_POP
}

/*
equation index: 936
type: ALGORITHM

  assert(fluPor[1].m_flow >= 0.0 and fluPor[1].m_flow <= 100000.0, "Variable violating min/max constraint: 0.0 <= fluPor[1].m_flow <= 100000.0, has value: " + String(fluPor[1].m_flow, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_936(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,936};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  static const MMC_DEFSTRINGLIT(tmp8,87,"Variable violating min/max constraint: 0.0 <= fluPor[1].m_flow <= 100000.0, has value: ");
  modelica_string tmp9;
  modelica_metatype tmpMeta10;
  static int tmp11 = 0;
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
  if(!tmp11)
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    tmp6 = GreaterEq((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),0.0);
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    tmp7 = LessEq((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),100000.0);
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    if(!(tmp6 && tmp7))
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      tmp9 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), (modelica_string) mmc_strings_len1[103]);
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      tmpMeta10 = stringAppend(MMC_REFSTRINGLIT(tmp8),tmp9);
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
        const char* assert_cond = "(fluPor[1].m_flow >= 0.0 and fluPor[1].m_flow <= 100000.0)";
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo",22,3,23,66,0};
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
        } else {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo",22,3,23,66,0};
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
        }
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      }
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      tmp11 = 1;
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
  }
#line 133 OMC_FILE
  TRACE_POP
}

/*
equation index: 937
type: ALGORITHM

  assert(fluPor[1].forward.T >= 1.0 and fluPor[1].forward.T <= 10000.0, "Variable violating min/max constraint: 1.0 <= fluPor[1].forward.T <= 10000.0, has value: " + String(fluPor[1].forward.T, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_937(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,937};
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  static const MMC_DEFSTRINGLIT(tmp14,89,"Variable violating min/max constraint: 1.0 <= fluPor[1].forward.T <= 10000.0, has value: ");
  modelica_string tmp15;
  modelica_metatype tmpMeta16;
  static int tmp17 = 0;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
  if(!tmp17)
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
  {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    tmp12 = GreaterEq((data->localData[0]->realVars[66] /* fluPor[1].forward.T variable */),1.0);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    tmp13 = LessEq((data->localData[0]->realVars[66] /* fluPor[1].forward.T variable */),10000.0);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    if(!(tmp12 && tmp13))
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      tmp15 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[66] /* fluPor[1].forward.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      tmpMeta16 = stringAppend(MMC_REFSTRINGLIT(tmp14),tmp15);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
        const char* assert_cond = "(fluPor[1].forward.T >= 1.0 and fluPor[1].forward.T <= 10000.0)";
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo",15,3,15,37,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta16));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
        } else {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo",15,3,15,37,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta16));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
        }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      tmp17 = 1;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
  }
#line 195 OMC_FILE
  TRACE_POP
}

/*
equation index: 938
type: ALGORITHM

  assert(fluPor[2].m_flow >= -100000.0 and fluPor[2].m_flow <= -0.0, "Variable violating min/max constraint: -100000.0 <= fluPor[2].m_flow <= -0.0, has value: " + String(fluPor[2].m_flow, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_938(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,938};
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  static const MMC_DEFSTRINGLIT(tmp20,89,"Variable violating min/max constraint: -100000.0 <= fluPor[2].m_flow <= -0.0, has value: ");
  modelica_string tmp21;
  modelica_metatype tmpMeta22;
  static int tmp23 = 0;
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
  if(!tmp23)
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    tmp18 = GreaterEq((data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */),-100000.0);
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    tmp19 = LessEq((data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */),-0.0);
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    if(!(tmp18 && tmp19))
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      tmp21 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */), (modelica_string) mmc_strings_len1[103]);
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      tmpMeta22 = stringAppend(MMC_REFSTRINGLIT(tmp20),tmp21);
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
        const char* assert_cond = "(fluPor[2].m_flow >= -100000.0 and fluPor[2].m_flow <= -0.0)";
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo",22,3,23,66,0};
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta22));
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
        } else {
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo",22,3,23,66,0};
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta22));
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
        }
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      }
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
      tmp23 = 1;
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/Outlet.mo"
  }
#line 257 OMC_FILE
  TRACE_POP
}

/*
equation index: 939
type: ALGORITHM

  assert(fluPor[2].forward.T >= 1.0 and fluPor[2].forward.T <= 10000.0, "Variable violating min/max constraint: 1.0 <= fluPor[2].forward.T <= 10000.0, has value: " + String(fluPor[2].forward.T, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_939(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,939};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  static const MMC_DEFSTRINGLIT(tmp26,89,"Variable violating min/max constraint: 1.0 <= fluPor[2].forward.T <= 10000.0, has value: ");
  modelica_string tmp27;
  modelica_metatype tmpMeta28;
  static int tmp29 = 0;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
  if(!tmp29)
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
  {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    tmp24 = GreaterEq((data->localData[0]->realVars[67] /* fluPor[2].forward.T variable */),1.0);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    tmp25 = LessEq((data->localData[0]->realVars[67] /* fluPor[2].forward.T variable */),10000.0);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    if(!(tmp24 && tmp25))
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      tmp27 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[67] /* fluPor[2].forward.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      tmpMeta28 = stringAppend(MMC_REFSTRINGLIT(tmp26),tmp27);
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
        const char* assert_cond = "(fluPor[2].forward.T >= 1.0 and fluPor[2].forward.T <= 10000.0)";
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo",15,3,15,37,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta28));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
        } else {
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo",15,3,15,37,0};
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta28));
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
        }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
      tmp29 = 1;
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
    }
#line 15 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Interfaces/FluidProperties.mo"
  }
#line 319 OMC_FILE
  TRACE_POP
}

/*
equation index: 940
type: ALGORITHM

  assert(hvacAda.ports[1].h_outflow >= -10000000000.0 and hvacAda.ports[1].h_outflow <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= hvacAda.ports[1].h_outflow <= 10000000000.0, has value: " + String(hvacAda.ports[1].h_outflow, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_940(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,940};
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,113,"Variable violating min/max constraint: -10000000000.0 <= hvacAda.ports[1].h_outflow <= 10000000000.0, has value: ");
  modelica_string tmp33;
  modelica_metatype tmpMeta34;
  static int tmp35 = 0;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  if(!tmp35)
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp30 = GreaterEq((data->localData[0]->realVars[90] /* hvacAda.ports[1].h_outflow variable */),-10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp31 = LessEq((data->localData[0]->realVars[90] /* hvacAda.ports[1].h_outflow variable */),10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    if(!(tmp30 && tmp31))
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp33 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[90] /* hvacAda.ports[1].h_outflow variable */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmpMeta34 = stringAppend(MMC_REFSTRINGLIT(tmp32),tmp33);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        const char* assert_cond = "(hvacAda.ports[1].h_outflow >= -10000000000.0 and hvacAda.ports[1].h_outflow <= 10000000000.0)";
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta34));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        } else {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta34));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp35 = 1;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  }
#line 381 OMC_FILE
  TRACE_POP
}

/*
equation index: 941
type: ALGORITHM

  assert(fan.port_a.p >= 0.0 and fan.port_a.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= fan.port_a.p <= 100000000.0, has value: " + String(fan.port_a.p, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_941(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,941};
  modelica_boolean tmp36;
  modelica_boolean tmp37;
  static const MMC_DEFSTRINGLIT(tmp38,86,"Variable violating min/max constraint: 0.0 <= fan.port_a.p <= 100000000.0, has value: ");
  modelica_string tmp39;
  modelica_metatype tmpMeta40;
  static int tmp41 = 0;
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  if(!tmp41)
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp36 = GreaterEq((data->localData[0]->realVars[45] /* fan.port_a.p variable */),0.0);
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp37 = LessEq((data->localData[0]->realVars[45] /* fan.port_a.p variable */),100000000.0);
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    if(!(tmp36 && tmp37))
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp39 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[45] /* fan.port_a.p variable */), (modelica_string) mmc_strings_len1[103]);
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmpMeta40 = stringAppend(MMC_REFSTRINGLIT(tmp38),tmp39);
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        const char* assert_cond = "(fan.port_a.p >= 0.0 and fan.port_a.p <= 100000000.0)";
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",15,5,15,79,0};
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta40));
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        } else {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",15,5,15,79,0};
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta40));
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        }
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      }
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp41 = 1;
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    }
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  }
#line 443 OMC_FILE
  TRACE_POP
}

/*
equation index: 942
type: ALGORITHM

  assert(fan.port_b.p >= 0.0 and fan.port_b.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= fan.port_b.p <= 100000000.0, has value: " + String(fan.port_b.p, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_942(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,942};
  modelica_boolean tmp42;
  modelica_boolean tmp43;
  static const MMC_DEFSTRINGLIT(tmp44,86,"Variable violating min/max constraint: 0.0 <= fan.port_b.p <= 100000000.0, has value: ");
  modelica_string tmp45;
  modelica_metatype tmpMeta46;
  static int tmp47 = 0;
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  if(!tmp47)
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp42 = GreaterEq((data->localData[0]->realVars[46] /* fan.port_b.p variable */),0.0);
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp43 = LessEq((data->localData[0]->realVars[46] /* fan.port_b.p variable */),100000000.0);
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    if(!(tmp42 && tmp43))
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp45 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[46] /* fan.port_b.p variable */), (modelica_string) mmc_strings_len1[103]);
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmpMeta46 = stringAppend(MMC_REFSTRINGLIT(tmp44),tmp45);
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        const char* assert_cond = "(fan.port_b.p >= 0.0 and fan.port_b.p <= 100000000.0)";
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",15,5,15,79,0};
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta46));
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        } else {
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",15,5,15,79,0};
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta46));
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        }
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      }
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp47 = 1;
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    }
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  }
#line 505 OMC_FILE
  TRACE_POP
}

/*
equation index: 943
type: ALGORITHM

  assert(fan.heatPort.T >= 1.0 and fan.heatPort.T <= 10000.0, "Variable violating min/max constraint: 1.0 <= fan.heatPort.T <= 10000.0, has value: " + String(fan.heatPort.T, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_943(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,943};
  modelica_boolean tmp48;
  modelica_boolean tmp49;
  static const MMC_DEFSTRINGLIT(tmp50,84,"Variable violating min/max constraint: 1.0 <= fan.heatPort.T <= 10000.0, has value: ");
  modelica_string tmp51;
  modelica_metatype tmpMeta52;
  static int tmp53 = 0;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  if(!tmp53)
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp48 = GreaterEq((data->localData[0]->realVars[44] /* fan.heatPort.T variable */),1.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    tmp49 = LessEq((data->localData[0]->realVars[44] /* fan.heatPort.T variable */),10000.0);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    if(!(tmp48 && tmp49))
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp51 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[44] /* fan.heatPort.T variable */), (modelica_string) mmc_strings_len1[103]);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmpMeta52 = stringAppend(MMC_REFSTRINGLIT(tmp50),tmp51);
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        const char* assert_cond = "(fan.heatPort.T >= 1.0 and fan.heatPort.T <= 10000.0)";
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        } else {
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo",3,3,3,38,0};
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
        }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
      tmp53 = 1;
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
    }
#line 3 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  }
#line 567 OMC_FILE
  TRACE_POP
}

/*
equation index: 944
type: ALGORITHM

  assert(fan.vol.ports[2].h_outflow >= -10000000000.0 and fan.vol.ports[2].h_outflow <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= fan.vol.ports[2].h_outflow <= 10000000000.0, has value: " + String(fan.vol.ports[2].h_outflow, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_944(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,944};
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  static const MMC_DEFSTRINGLIT(tmp56,113,"Variable violating min/max constraint: -10000000000.0 <= fan.vol.ports[2].h_outflow <= 10000000000.0, has value: ");
  modelica_string tmp57;
  modelica_metatype tmpMeta58;
  static int tmp59 = 0;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  if(!tmp59)
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp54 = GreaterEq((data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */),-10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp55 = LessEq((data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */),10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    if(!(tmp54 && tmp55))
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp57 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmpMeta58 = stringAppend(MMC_REFSTRINGLIT(tmp56),tmp57);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        const char* assert_cond = "(fan.vol.ports[2].h_outflow >= -10000000000.0 and fan.vol.ports[2].h_outflow <= 10000000000.0)";
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta58));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        } else {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta58));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp59 = 1;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  }
#line 629 OMC_FILE
  TRACE_POP
}

/*
equation index: 945
type: ALGORITHM

  assert(fan.heaDis.etaHyd >= 0.0, "Variable violating min constraint: 0.0 <= fan.heaDis.etaHyd, has value: " + String(fan.heaDis.etaHyd, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_945(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,945};
  modelica_boolean tmp60;
  static const MMC_DEFSTRINGLIT(tmp61,72,"Variable violating min constraint: 0.0 <= fan.heaDis.etaHyd, has value: ");
  modelica_string tmp62;
  modelica_metatype tmpMeta63;
  static int tmp64 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  if(!tmp64)
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp60 = GreaterEq((data->localData[0]->realVars[42] /* fan.heaDis.etaHyd variable */),0.0);
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    if(!tmp60)
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp62 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[42] /* fan.heaDis.etaHyd variable */), (modelica_string) mmc_strings_len1[103]);
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmpMeta63 = stringAppend(MMC_REFSTRINGLIT(tmp61),tmp62);
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        const char* assert_cond = "(fan.heaDis.etaHyd >= 0.0)";
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo",46,3,47,27,0};
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo",46,3,47,27,0};
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp64 = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  }
#line 688 OMC_FILE
  TRACE_POP
}

/*
equation index: 946
type: ALGORITHM

  assert(fan.eff.yMot >= 0.0, "Variable violating min constraint: 0.0 <= fan.eff.yMot, has value: " + String(fan.eff.yMot, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_946(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,946};
  modelica_boolean tmp65;
  static const MMC_DEFSTRINGLIT(tmp66,67,"Variable violating min constraint: 0.0 <= fan.eff.yMot, has value: ");
  modelica_string tmp67;
  modelica_metatype tmpMeta68;
  static int tmp69 = 0;
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  if(!tmp69)
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  {
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp65 = GreaterEq((data->localData[0]->realVars[37] /* fan.eff.yMot variable */),0.0);
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    if(!tmp65)
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    {
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp67 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[37] /* fan.eff.yMot variable */), (modelica_string) mmc_strings_len1[103]);
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmpMeta68 = stringAppend(MMC_REFSTRINGLIT(tmp66),tmp67);
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      {
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        const char* assert_cond = "(fan.eff.yMot >= 0.0)";
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo",310,3,314,28,0};
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        } else {
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo",310,3,314,28,0};
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        }
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      }
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp69 = 1;
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    }
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  }
#line 747 OMC_FILE
  TRACE_POP
}

/*
equation index: 947
type: ALGORITHM

  assert(resSup.port_b.h_outflow >= -10000000000.0 and resSup.port_b.h_outflow <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= resSup.port_b.h_outflow <= 10000000000.0, has value: " + String(resSup.port_b.h_outflow, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_947(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,947};
  modelica_boolean tmp70;
  modelica_boolean tmp71;
  static const MMC_DEFSTRINGLIT(tmp72,110,"Variable violating min/max constraint: -10000000000.0 <= resSup.port_b.h_outflow <= 10000000000.0, has value: ");
  modelica_string tmp73;
  modelica_metatype tmpMeta74;
  static int tmp75 = 0;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  if(!tmp75)
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp70 = GreaterEq((data->localData[0]->realVars[93] /* resSup.port_b.h_outflow variable */),-10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp71 = LessEq((data->localData[0]->realVars[93] /* resSup.port_b.h_outflow variable */),10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    if(!(tmp70 && tmp71))
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp73 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[93] /* resSup.port_b.h_outflow variable */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmpMeta74 = stringAppend(MMC_REFSTRINGLIT(tmp72),tmp73);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        const char* assert_cond = "(resSup.port_b.h_outflow >= -10000000000.0 and resSup.port_b.h_outflow <= 10000000000.0)";
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta74));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        } else {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta74));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp75 = 1;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  }
#line 809 OMC_FILE
  TRACE_POP
}

/*
equation index: 948
type: ALGORITHM

  assert(bou.ports[1].h_outflow >= -10000000000.0 and bou.ports[1].h_outflow <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= bou.ports[1].h_outflow <= 10000000000.0, has value: " + String(bou.ports[1].h_outflow, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_948(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,948};
  modelica_boolean tmp76;
  modelica_boolean tmp77;
  static const MMC_DEFSTRINGLIT(tmp78,109,"Variable violating min/max constraint: -10000000000.0 <= bou.ports[1].h_outflow <= 10000000000.0, has value: ");
  modelica_string tmp79;
  modelica_metatype tmpMeta80;
  static int tmp81 = 0;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  if(!tmp81)
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp76 = GreaterEq((data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),-10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp77 = LessEq((data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    if(!(tmp76 && tmp77))
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp79 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmpMeta80 = stringAppend(MMC_REFSTRINGLIT(tmp78),tmp79);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        const char* assert_cond = "(bou.ports[1].h_outflow >= -10000000000.0 and bou.ports[1].h_outflow <= 10000000000.0)";
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta80));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        } else {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta80));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp81 = 1;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  }
#line 871 OMC_FILE
  TRACE_POP
}

/*
equation index: 949
type: ALGORITHM

  assert(hea.port_a.h_outflow >= -10000000000.0 and hea.port_a.h_outflow <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= hea.port_a.h_outflow <= 10000000000.0, has value: " + String(hea.port_a.h_outflow, "g"));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_949(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,949};
  modelica_boolean tmp82;
  modelica_boolean tmp83;
  static const MMC_DEFSTRINGLIT(tmp84,107,"Variable violating min/max constraint: -10000000000.0 <= hea.port_a.h_outflow <= 10000000000.0, has value: ");
  modelica_string tmp85;
  modelica_metatype tmpMeta86;
  static int tmp87 = 0;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  if(!tmp87)
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp82 = GreaterEq((data->localData[0]->realVars[82] /* hea.port_a.h_outflow variable */),-10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    tmp83 = LessEq((data->localData[0]->realVars[82] /* hea.port_a.h_outflow variable */),10000000000.0);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    if(!(tmp82 && tmp83))
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp85 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[82] /* hea.port_a.h_outflow variable */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmpMeta86 = stringAppend(MMC_REFSTRINGLIT(tmp84),tmp85);
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        const char* assert_cond = "(hea.port_a.h_outflow >= -10000000000.0 and hea.port_a.h_outflow <= 10000000000.0)";
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta86));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        } else {
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo",16,5,17,84,0};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta86));
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
        }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
      tmp87 = 1;
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
    }
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  }
#line 933 OMC_FILE
  TRACE_POP
}
/* function to check assert after a step is done */
OMC_DISABLE_OPT
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_935(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_936(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_937(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_938(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_939(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_940(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_941(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_942(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_943(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_944(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_945(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_946(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_947(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_948(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_949(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

