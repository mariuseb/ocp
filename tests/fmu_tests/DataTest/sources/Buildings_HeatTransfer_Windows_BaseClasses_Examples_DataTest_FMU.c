// define class name and unique id
#define MODEL_IDENTIFIER Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest
#define MODEL_GUID "{3c8d7f0a-ec17-489f-aa2f-306325f4e1a3}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functions.h"
#include "simulation/solver/initialization/initialization.h"
#include "simulation/solver/events.h"
#include "fmi-export/fmu2_model_interface.h"
#include "fmi-export/fmu_read_flags.h"

#ifdef __cplusplus
extern "C" {
#endif

void setStartValues(ModelInstance *comp);
void setDefaultStartValues(ModelInstance *comp);
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo);
fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value);
fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value);
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value);
fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value);
fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value);
fmi2ValueReference mapInputReference2InputNumber(const fmi2ValueReference vr);
fmi2ValueReference mapOutputReference2OutputNumber(const fmi2ValueReference vr);
fmi2ValueReference mapOutputReference2RealOutputDerivatives(const fmi2ValueReference vr);
fmi2ValueReference mapInitialUnknownsdependentIndex(const fmi2ValueReference vr);
fmi2ValueReference mapInitialUnknownsIndependentIndex(const fmi2ValueReference vr);

// define model size
#define NUMBER_OF_STATES 0
#define NUMBER_OF_EVENT_INDICATORS 0
#define NUMBER_OF_REALS 241
#define NUMBER_OF_REAL_INPUTS 0
#define NUMBER_OF_INTEGERS 4
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_BOOLEANS 4
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define initial state vector as vector of value references
#define STATES {  }
#define STATESDERIVATIVES {  }


// implementation of the Model Exchange functions
extern void Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_setupDataStruc(DATA *data, threadData_t *threadData);
#define fmu2_model_interface_setupDataStruc Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_setupDataStruc
#include "fmi-export/fmu2_model_interface.c.inc"
#include "fmi-export/fmu_read_flags.c.inc"

// Set values for all variables that define a start value
OMC_DISABLE_OPT
void setDefaultStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[1].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[2].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[3].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[4].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[5].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[6].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[7].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[8].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[9].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[10].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[11].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[12].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[13].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[14].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[15].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[16].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[17].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[18].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[19].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[20].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[21].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[0].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[1].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[2].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[3].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[4].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[5].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[6].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[7].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[8].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[9].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[10].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[11].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[12].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[13].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[14].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[15].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[16].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[17].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[18].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[19].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[20].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[21].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[22].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[23].attribute.start = 2.0;
  comp->fmuData->modelData->realParameterData[24].attribute.start = 0.8;
  comp->fmuData->modelData->realParameterData[25].attribute.start = 0.5;
  comp->fmuData->modelData->realParameterData[26].attribute.start = 0.02897;
  comp->fmuData->modelData->realParameterData[27].attribute.start = 101325.0;
  comp->fmuData->modelData->realParameterData[28].attribute.start = 1002.737;
  comp->fmuData->modelData->realParameterData[29].attribute.start = 0.002873;
  comp->fmuData->modelData->realParameterData[30].attribute.start = 3.723e-06;
  comp->fmuData->modelData->realParameterData[31].attribute.start = 0.012324;
  comp->fmuData->modelData->realParameterData[32].attribute.start = 7.76e-05;
  comp->fmuData->modelData->realParameterData[33].attribute.start = 4.94e-08;
  comp->fmuData->modelData->realParameterData[34].attribute.start = -1.0;
  comp->fmuData->modelData->realParameterData[35].attribute.start = 0.84;
  comp->fmuData->modelData->realParameterData[36].attribute.start = 0.84;
  comp->fmuData->modelData->realParameterData[37].attribute.start = 1.0;
  comp->fmuData->modelData->realParameterData[38].attribute.start = 0.075;
  comp->fmuData->modelData->realParameterData[39].attribute.start = 0.075;
  comp->fmuData->modelData->realParameterData[40].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[41].attribute.start = 0.834;
  comp->fmuData->modelData->realParameterData[42].attribute.start = 0.003;
  comp->fmuData->modelData->realParameterData[43].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[44].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[45].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[46].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[47].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[48].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[49].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[50].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[51].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[52].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[53].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[54].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[55].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[56].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[57].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[58].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[59].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[60].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[61].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[62].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[63].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[64].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[65].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[66].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[67].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[68].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[69].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[70].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[71].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[72].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[73].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[74].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[75].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[76].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[77].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[78].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[79].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[80].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[81].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[82].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[83].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[84].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[85].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[86].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[87].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[88].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[89].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[90].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[91].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[92].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[93].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[94].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[95].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[96].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[97].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[98].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[99].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[100].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[101].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[102].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[103].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[104].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[105].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[106].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[107].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[108].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[109].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[110].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[111].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[112].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[113].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[114].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[115].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[116].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[117].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[118].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[119].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[120].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[121].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[122].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[123].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[124].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[125].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[126].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[127].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[128].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[129].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[130].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[131].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[132].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[133].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[134].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[135].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[136].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[137].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[138].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[139].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[140].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[141].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[142].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[143].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[144].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[145].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[146].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[147].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[148].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[149].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[150].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[151].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[152].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[153].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[154].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[155].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[156].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[157].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[158].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[159].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[160].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[161].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[162].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[163].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[164].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[165].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[166].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[167].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[168].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[169].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[170].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[171].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[172].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[173].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[174].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[175].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[176].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[177].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[178].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[179].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[180].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[181].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[182].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[183].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[184].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[185].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[186].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[187].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[188].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[189].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[190].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[191].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[192].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[193].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[194].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[195].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[196].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[197].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[198].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[199].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[200].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[201].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[202].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[203].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[204].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[205].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[206].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[207].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[208].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[209].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[210].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[211].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[212].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[213].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[214].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[215].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[216].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[217].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[218].attribute.start = 1.5707963267949;
  comp->fmuData->modelData->integerParameterData[0].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[1].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[2].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[3].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[0].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[1].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[2].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[3].attribute.start = 0;
}
// Set values for all variables that define a start value
OMC_DISABLE_OPT
void setStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start =  comp->fmuData->localData[0]->realVars[0];
  comp->fmuData->modelData->realVarsData[1].attribute.start =  comp->fmuData->localData[0]->realVars[1];
  comp->fmuData->modelData->realVarsData[2].attribute.start =  comp->fmuData->localData[0]->realVars[2];
  comp->fmuData->modelData->realVarsData[3].attribute.start =  comp->fmuData->localData[0]->realVars[3];
  comp->fmuData->modelData->realVarsData[4].attribute.start =  comp->fmuData->localData[0]->realVars[4];
  comp->fmuData->modelData->realVarsData[5].attribute.start =  comp->fmuData->localData[0]->realVars[5];
  comp->fmuData->modelData->realVarsData[6].attribute.start =  comp->fmuData->localData[0]->realVars[6];
  comp->fmuData->modelData->realVarsData[7].attribute.start =  comp->fmuData->localData[0]->realVars[7];
  comp->fmuData->modelData->realVarsData[8].attribute.start =  comp->fmuData->localData[0]->realVars[8];
  comp->fmuData->modelData->realVarsData[9].attribute.start =  comp->fmuData->localData[0]->realVars[9];
  comp->fmuData->modelData->realVarsData[10].attribute.start =  comp->fmuData->localData[0]->realVars[10];
  comp->fmuData->modelData->realVarsData[11].attribute.start =  comp->fmuData->localData[0]->realVars[11];
  comp->fmuData->modelData->realVarsData[12].attribute.start =  comp->fmuData->localData[0]->realVars[12];
  comp->fmuData->modelData->realVarsData[13].attribute.start =  comp->fmuData->localData[0]->realVars[13];
  comp->fmuData->modelData->realVarsData[14].attribute.start =  comp->fmuData->localData[0]->realVars[14];
  comp->fmuData->modelData->realVarsData[15].attribute.start =  comp->fmuData->localData[0]->realVars[15];
  comp->fmuData->modelData->realVarsData[16].attribute.start =  comp->fmuData->localData[0]->realVars[16];
  comp->fmuData->modelData->realVarsData[17].attribute.start =  comp->fmuData->localData[0]->realVars[17];
  comp->fmuData->modelData->realVarsData[18].attribute.start =  comp->fmuData->localData[0]->realVars[18];
  comp->fmuData->modelData->realVarsData[19].attribute.start =  comp->fmuData->localData[0]->realVars[19];
  comp->fmuData->modelData->realVarsData[20].attribute.start =  comp->fmuData->localData[0]->realVars[20];
  comp->fmuData->modelData->realVarsData[21].attribute.start =  comp->fmuData->localData[0]->realVars[21];
  comp->fmuData->modelData->realParameterData[0].attribute.start = comp->fmuData->simulationInfo->realParameter[0];
  comp->fmuData->modelData->realParameterData[1].attribute.start = comp->fmuData->simulationInfo->realParameter[1];
  comp->fmuData->modelData->realParameterData[2].attribute.start = comp->fmuData->simulationInfo->realParameter[2];
  comp->fmuData->modelData->realParameterData[3].attribute.start = comp->fmuData->simulationInfo->realParameter[3];
  comp->fmuData->modelData->realParameterData[4].attribute.start = comp->fmuData->simulationInfo->realParameter[4];
  comp->fmuData->modelData->realParameterData[5].attribute.start = comp->fmuData->simulationInfo->realParameter[5];
  comp->fmuData->modelData->realParameterData[6].attribute.start = comp->fmuData->simulationInfo->realParameter[6];
  comp->fmuData->modelData->realParameterData[7].attribute.start = comp->fmuData->simulationInfo->realParameter[7];
  comp->fmuData->modelData->realParameterData[8].attribute.start = comp->fmuData->simulationInfo->realParameter[8];
  comp->fmuData->modelData->realParameterData[9].attribute.start = comp->fmuData->simulationInfo->realParameter[9];
  comp->fmuData->modelData->realParameterData[10].attribute.start = comp->fmuData->simulationInfo->realParameter[10];
  comp->fmuData->modelData->realParameterData[11].attribute.start = comp->fmuData->simulationInfo->realParameter[11];
  comp->fmuData->modelData->realParameterData[12].attribute.start = comp->fmuData->simulationInfo->realParameter[12];
  comp->fmuData->modelData->realParameterData[13].attribute.start = comp->fmuData->simulationInfo->realParameter[13];
  comp->fmuData->modelData->realParameterData[14].attribute.start = comp->fmuData->simulationInfo->realParameter[14];
  comp->fmuData->modelData->realParameterData[15].attribute.start = comp->fmuData->simulationInfo->realParameter[15];
  comp->fmuData->modelData->realParameterData[16].attribute.start = comp->fmuData->simulationInfo->realParameter[16];
  comp->fmuData->modelData->realParameterData[17].attribute.start = comp->fmuData->simulationInfo->realParameter[17];
  comp->fmuData->modelData->realParameterData[18].attribute.start = comp->fmuData->simulationInfo->realParameter[18];
  comp->fmuData->modelData->realParameterData[19].attribute.start = comp->fmuData->simulationInfo->realParameter[19];
  comp->fmuData->modelData->realParameterData[20].attribute.start = comp->fmuData->simulationInfo->realParameter[20];
  comp->fmuData->modelData->realParameterData[21].attribute.start = comp->fmuData->simulationInfo->realParameter[21];
  comp->fmuData->modelData->realParameterData[22].attribute.start = comp->fmuData->simulationInfo->realParameter[22];
  comp->fmuData->modelData->realParameterData[23].attribute.start = comp->fmuData->simulationInfo->realParameter[23];
  comp->fmuData->modelData->realParameterData[24].attribute.start = comp->fmuData->simulationInfo->realParameter[24];
  comp->fmuData->modelData->realParameterData[25].attribute.start = comp->fmuData->simulationInfo->realParameter[25];
  comp->fmuData->modelData->realParameterData[26].attribute.start = comp->fmuData->simulationInfo->realParameter[26];
  comp->fmuData->modelData->realParameterData[27].attribute.start = comp->fmuData->simulationInfo->realParameter[27];
  comp->fmuData->modelData->realParameterData[28].attribute.start = comp->fmuData->simulationInfo->realParameter[28];
  comp->fmuData->modelData->realParameterData[29].attribute.start = comp->fmuData->simulationInfo->realParameter[29];
  comp->fmuData->modelData->realParameterData[30].attribute.start = comp->fmuData->simulationInfo->realParameter[30];
  comp->fmuData->modelData->realParameterData[31].attribute.start = comp->fmuData->simulationInfo->realParameter[31];
  comp->fmuData->modelData->realParameterData[32].attribute.start = comp->fmuData->simulationInfo->realParameter[32];
  comp->fmuData->modelData->realParameterData[33].attribute.start = comp->fmuData->simulationInfo->realParameter[33];
  comp->fmuData->modelData->realParameterData[34].attribute.start = comp->fmuData->simulationInfo->realParameter[34];
  comp->fmuData->modelData->realParameterData[35].attribute.start = comp->fmuData->simulationInfo->realParameter[35];
  comp->fmuData->modelData->realParameterData[36].attribute.start = comp->fmuData->simulationInfo->realParameter[36];
  comp->fmuData->modelData->realParameterData[37].attribute.start = comp->fmuData->simulationInfo->realParameter[37];
  comp->fmuData->modelData->realParameterData[38].attribute.start = comp->fmuData->simulationInfo->realParameter[38];
  comp->fmuData->modelData->realParameterData[39].attribute.start = comp->fmuData->simulationInfo->realParameter[39];
  comp->fmuData->modelData->realParameterData[40].attribute.start = comp->fmuData->simulationInfo->realParameter[40];
  comp->fmuData->modelData->realParameterData[41].attribute.start = comp->fmuData->simulationInfo->realParameter[41];
  comp->fmuData->modelData->realParameterData[42].attribute.start = comp->fmuData->simulationInfo->realParameter[42];
  comp->fmuData->modelData->realParameterData[43].attribute.start = comp->fmuData->simulationInfo->realParameter[43];
  comp->fmuData->modelData->realParameterData[44].attribute.start = comp->fmuData->simulationInfo->realParameter[44];
  comp->fmuData->modelData->realParameterData[45].attribute.start = comp->fmuData->simulationInfo->realParameter[45];
  comp->fmuData->modelData->realParameterData[46].attribute.start = comp->fmuData->simulationInfo->realParameter[46];
  comp->fmuData->modelData->realParameterData[47].attribute.start = comp->fmuData->simulationInfo->realParameter[47];
  comp->fmuData->modelData->realParameterData[48].attribute.start = comp->fmuData->simulationInfo->realParameter[48];
  comp->fmuData->modelData->realParameterData[49].attribute.start = comp->fmuData->simulationInfo->realParameter[49];
  comp->fmuData->modelData->realParameterData[50].attribute.start = comp->fmuData->simulationInfo->realParameter[50];
  comp->fmuData->modelData->realParameterData[51].attribute.start = comp->fmuData->simulationInfo->realParameter[51];
  comp->fmuData->modelData->realParameterData[52].attribute.start = comp->fmuData->simulationInfo->realParameter[52];
  comp->fmuData->modelData->realParameterData[53].attribute.start = comp->fmuData->simulationInfo->realParameter[53];
  comp->fmuData->modelData->realParameterData[54].attribute.start = comp->fmuData->simulationInfo->realParameter[54];
  comp->fmuData->modelData->realParameterData[55].attribute.start = comp->fmuData->simulationInfo->realParameter[55];
  comp->fmuData->modelData->realParameterData[56].attribute.start = comp->fmuData->simulationInfo->realParameter[56];
  comp->fmuData->modelData->realParameterData[57].attribute.start = comp->fmuData->simulationInfo->realParameter[57];
  comp->fmuData->modelData->realParameterData[58].attribute.start = comp->fmuData->simulationInfo->realParameter[58];
  comp->fmuData->modelData->realParameterData[59].attribute.start = comp->fmuData->simulationInfo->realParameter[59];
  comp->fmuData->modelData->realParameterData[60].attribute.start = comp->fmuData->simulationInfo->realParameter[60];
  comp->fmuData->modelData->realParameterData[61].attribute.start = comp->fmuData->simulationInfo->realParameter[61];
  comp->fmuData->modelData->realParameterData[62].attribute.start = comp->fmuData->simulationInfo->realParameter[62];
  comp->fmuData->modelData->realParameterData[63].attribute.start = comp->fmuData->simulationInfo->realParameter[63];
  comp->fmuData->modelData->realParameterData[64].attribute.start = comp->fmuData->simulationInfo->realParameter[64];
  comp->fmuData->modelData->realParameterData[65].attribute.start = comp->fmuData->simulationInfo->realParameter[65];
  comp->fmuData->modelData->realParameterData[66].attribute.start = comp->fmuData->simulationInfo->realParameter[66];
  comp->fmuData->modelData->realParameterData[67].attribute.start = comp->fmuData->simulationInfo->realParameter[67];
  comp->fmuData->modelData->realParameterData[68].attribute.start = comp->fmuData->simulationInfo->realParameter[68];
  comp->fmuData->modelData->realParameterData[69].attribute.start = comp->fmuData->simulationInfo->realParameter[69];
  comp->fmuData->modelData->realParameterData[70].attribute.start = comp->fmuData->simulationInfo->realParameter[70];
  comp->fmuData->modelData->realParameterData[71].attribute.start = comp->fmuData->simulationInfo->realParameter[71];
  comp->fmuData->modelData->realParameterData[72].attribute.start = comp->fmuData->simulationInfo->realParameter[72];
  comp->fmuData->modelData->realParameterData[73].attribute.start = comp->fmuData->simulationInfo->realParameter[73];
  comp->fmuData->modelData->realParameterData[74].attribute.start = comp->fmuData->simulationInfo->realParameter[74];
  comp->fmuData->modelData->realParameterData[75].attribute.start = comp->fmuData->simulationInfo->realParameter[75];
  comp->fmuData->modelData->realParameterData[76].attribute.start = comp->fmuData->simulationInfo->realParameter[76];
  comp->fmuData->modelData->realParameterData[77].attribute.start = comp->fmuData->simulationInfo->realParameter[77];
  comp->fmuData->modelData->realParameterData[78].attribute.start = comp->fmuData->simulationInfo->realParameter[78];
  comp->fmuData->modelData->realParameterData[79].attribute.start = comp->fmuData->simulationInfo->realParameter[79];
  comp->fmuData->modelData->realParameterData[80].attribute.start = comp->fmuData->simulationInfo->realParameter[80];
  comp->fmuData->modelData->realParameterData[81].attribute.start = comp->fmuData->simulationInfo->realParameter[81];
  comp->fmuData->modelData->realParameterData[82].attribute.start = comp->fmuData->simulationInfo->realParameter[82];
  comp->fmuData->modelData->realParameterData[83].attribute.start = comp->fmuData->simulationInfo->realParameter[83];
  comp->fmuData->modelData->realParameterData[84].attribute.start = comp->fmuData->simulationInfo->realParameter[84];
  comp->fmuData->modelData->realParameterData[85].attribute.start = comp->fmuData->simulationInfo->realParameter[85];
  comp->fmuData->modelData->realParameterData[86].attribute.start = comp->fmuData->simulationInfo->realParameter[86];
  comp->fmuData->modelData->realParameterData[87].attribute.start = comp->fmuData->simulationInfo->realParameter[87];
  comp->fmuData->modelData->realParameterData[88].attribute.start = comp->fmuData->simulationInfo->realParameter[88];
  comp->fmuData->modelData->realParameterData[89].attribute.start = comp->fmuData->simulationInfo->realParameter[89];
  comp->fmuData->modelData->realParameterData[90].attribute.start = comp->fmuData->simulationInfo->realParameter[90];
  comp->fmuData->modelData->realParameterData[91].attribute.start = comp->fmuData->simulationInfo->realParameter[91];
  comp->fmuData->modelData->realParameterData[92].attribute.start = comp->fmuData->simulationInfo->realParameter[92];
  comp->fmuData->modelData->realParameterData[93].attribute.start = comp->fmuData->simulationInfo->realParameter[93];
  comp->fmuData->modelData->realParameterData[94].attribute.start = comp->fmuData->simulationInfo->realParameter[94];
  comp->fmuData->modelData->realParameterData[95].attribute.start = comp->fmuData->simulationInfo->realParameter[95];
  comp->fmuData->modelData->realParameterData[96].attribute.start = comp->fmuData->simulationInfo->realParameter[96];
  comp->fmuData->modelData->realParameterData[97].attribute.start = comp->fmuData->simulationInfo->realParameter[97];
  comp->fmuData->modelData->realParameterData[98].attribute.start = comp->fmuData->simulationInfo->realParameter[98];
  comp->fmuData->modelData->realParameterData[99].attribute.start = comp->fmuData->simulationInfo->realParameter[99];
  comp->fmuData->modelData->realParameterData[100].attribute.start = comp->fmuData->simulationInfo->realParameter[100];
  comp->fmuData->modelData->realParameterData[101].attribute.start = comp->fmuData->simulationInfo->realParameter[101];
  comp->fmuData->modelData->realParameterData[102].attribute.start = comp->fmuData->simulationInfo->realParameter[102];
  comp->fmuData->modelData->realParameterData[103].attribute.start = comp->fmuData->simulationInfo->realParameter[103];
  comp->fmuData->modelData->realParameterData[104].attribute.start = comp->fmuData->simulationInfo->realParameter[104];
  comp->fmuData->modelData->realParameterData[105].attribute.start = comp->fmuData->simulationInfo->realParameter[105];
  comp->fmuData->modelData->realParameterData[106].attribute.start = comp->fmuData->simulationInfo->realParameter[106];
  comp->fmuData->modelData->realParameterData[107].attribute.start = comp->fmuData->simulationInfo->realParameter[107];
  comp->fmuData->modelData->realParameterData[108].attribute.start = comp->fmuData->simulationInfo->realParameter[108];
  comp->fmuData->modelData->realParameterData[109].attribute.start = comp->fmuData->simulationInfo->realParameter[109];
  comp->fmuData->modelData->realParameterData[110].attribute.start = comp->fmuData->simulationInfo->realParameter[110];
  comp->fmuData->modelData->realParameterData[111].attribute.start = comp->fmuData->simulationInfo->realParameter[111];
  comp->fmuData->modelData->realParameterData[112].attribute.start = comp->fmuData->simulationInfo->realParameter[112];
  comp->fmuData->modelData->realParameterData[113].attribute.start = comp->fmuData->simulationInfo->realParameter[113];
  comp->fmuData->modelData->realParameterData[114].attribute.start = comp->fmuData->simulationInfo->realParameter[114];
  comp->fmuData->modelData->realParameterData[115].attribute.start = comp->fmuData->simulationInfo->realParameter[115];
  comp->fmuData->modelData->realParameterData[116].attribute.start = comp->fmuData->simulationInfo->realParameter[116];
  comp->fmuData->modelData->realParameterData[117].attribute.start = comp->fmuData->simulationInfo->realParameter[117];
  comp->fmuData->modelData->realParameterData[118].attribute.start = comp->fmuData->simulationInfo->realParameter[118];
  comp->fmuData->modelData->realParameterData[119].attribute.start = comp->fmuData->simulationInfo->realParameter[119];
  comp->fmuData->modelData->realParameterData[120].attribute.start = comp->fmuData->simulationInfo->realParameter[120];
  comp->fmuData->modelData->realParameterData[121].attribute.start = comp->fmuData->simulationInfo->realParameter[121];
  comp->fmuData->modelData->realParameterData[122].attribute.start = comp->fmuData->simulationInfo->realParameter[122];
  comp->fmuData->modelData->realParameterData[123].attribute.start = comp->fmuData->simulationInfo->realParameter[123];
  comp->fmuData->modelData->realParameterData[124].attribute.start = comp->fmuData->simulationInfo->realParameter[124];
  comp->fmuData->modelData->realParameterData[125].attribute.start = comp->fmuData->simulationInfo->realParameter[125];
  comp->fmuData->modelData->realParameterData[126].attribute.start = comp->fmuData->simulationInfo->realParameter[126];
  comp->fmuData->modelData->realParameterData[127].attribute.start = comp->fmuData->simulationInfo->realParameter[127];
  comp->fmuData->modelData->realParameterData[128].attribute.start = comp->fmuData->simulationInfo->realParameter[128];
  comp->fmuData->modelData->realParameterData[129].attribute.start = comp->fmuData->simulationInfo->realParameter[129];
  comp->fmuData->modelData->realParameterData[130].attribute.start = comp->fmuData->simulationInfo->realParameter[130];
  comp->fmuData->modelData->realParameterData[131].attribute.start = comp->fmuData->simulationInfo->realParameter[131];
  comp->fmuData->modelData->realParameterData[132].attribute.start = comp->fmuData->simulationInfo->realParameter[132];
  comp->fmuData->modelData->realParameterData[133].attribute.start = comp->fmuData->simulationInfo->realParameter[133];
  comp->fmuData->modelData->realParameterData[134].attribute.start = comp->fmuData->simulationInfo->realParameter[134];
  comp->fmuData->modelData->realParameterData[135].attribute.start = comp->fmuData->simulationInfo->realParameter[135];
  comp->fmuData->modelData->realParameterData[136].attribute.start = comp->fmuData->simulationInfo->realParameter[136];
  comp->fmuData->modelData->realParameterData[137].attribute.start = comp->fmuData->simulationInfo->realParameter[137];
  comp->fmuData->modelData->realParameterData[138].attribute.start = comp->fmuData->simulationInfo->realParameter[138];
  comp->fmuData->modelData->realParameterData[139].attribute.start = comp->fmuData->simulationInfo->realParameter[139];
  comp->fmuData->modelData->realParameterData[140].attribute.start = comp->fmuData->simulationInfo->realParameter[140];
  comp->fmuData->modelData->realParameterData[141].attribute.start = comp->fmuData->simulationInfo->realParameter[141];
  comp->fmuData->modelData->realParameterData[142].attribute.start = comp->fmuData->simulationInfo->realParameter[142];
  comp->fmuData->modelData->realParameterData[143].attribute.start = comp->fmuData->simulationInfo->realParameter[143];
  comp->fmuData->modelData->realParameterData[144].attribute.start = comp->fmuData->simulationInfo->realParameter[144];
  comp->fmuData->modelData->realParameterData[145].attribute.start = comp->fmuData->simulationInfo->realParameter[145];
  comp->fmuData->modelData->realParameterData[146].attribute.start = comp->fmuData->simulationInfo->realParameter[146];
  comp->fmuData->modelData->realParameterData[147].attribute.start = comp->fmuData->simulationInfo->realParameter[147];
  comp->fmuData->modelData->realParameterData[148].attribute.start = comp->fmuData->simulationInfo->realParameter[148];
  comp->fmuData->modelData->realParameterData[149].attribute.start = comp->fmuData->simulationInfo->realParameter[149];
  comp->fmuData->modelData->realParameterData[150].attribute.start = comp->fmuData->simulationInfo->realParameter[150];
  comp->fmuData->modelData->realParameterData[151].attribute.start = comp->fmuData->simulationInfo->realParameter[151];
  comp->fmuData->modelData->realParameterData[152].attribute.start = comp->fmuData->simulationInfo->realParameter[152];
  comp->fmuData->modelData->realParameterData[153].attribute.start = comp->fmuData->simulationInfo->realParameter[153];
  comp->fmuData->modelData->realParameterData[154].attribute.start = comp->fmuData->simulationInfo->realParameter[154];
  comp->fmuData->modelData->realParameterData[155].attribute.start = comp->fmuData->simulationInfo->realParameter[155];
  comp->fmuData->modelData->realParameterData[156].attribute.start = comp->fmuData->simulationInfo->realParameter[156];
  comp->fmuData->modelData->realParameterData[157].attribute.start = comp->fmuData->simulationInfo->realParameter[157];
  comp->fmuData->modelData->realParameterData[158].attribute.start = comp->fmuData->simulationInfo->realParameter[158];
  comp->fmuData->modelData->realParameterData[159].attribute.start = comp->fmuData->simulationInfo->realParameter[159];
  comp->fmuData->modelData->realParameterData[160].attribute.start = comp->fmuData->simulationInfo->realParameter[160];
  comp->fmuData->modelData->realParameterData[161].attribute.start = comp->fmuData->simulationInfo->realParameter[161];
  comp->fmuData->modelData->realParameterData[162].attribute.start = comp->fmuData->simulationInfo->realParameter[162];
  comp->fmuData->modelData->realParameterData[163].attribute.start = comp->fmuData->simulationInfo->realParameter[163];
  comp->fmuData->modelData->realParameterData[164].attribute.start = comp->fmuData->simulationInfo->realParameter[164];
  comp->fmuData->modelData->realParameterData[165].attribute.start = comp->fmuData->simulationInfo->realParameter[165];
  comp->fmuData->modelData->realParameterData[166].attribute.start = comp->fmuData->simulationInfo->realParameter[166];
  comp->fmuData->modelData->realParameterData[167].attribute.start = comp->fmuData->simulationInfo->realParameter[167];
  comp->fmuData->modelData->realParameterData[168].attribute.start = comp->fmuData->simulationInfo->realParameter[168];
  comp->fmuData->modelData->realParameterData[169].attribute.start = comp->fmuData->simulationInfo->realParameter[169];
  comp->fmuData->modelData->realParameterData[170].attribute.start = comp->fmuData->simulationInfo->realParameter[170];
  comp->fmuData->modelData->realParameterData[171].attribute.start = comp->fmuData->simulationInfo->realParameter[171];
  comp->fmuData->modelData->realParameterData[172].attribute.start = comp->fmuData->simulationInfo->realParameter[172];
  comp->fmuData->modelData->realParameterData[173].attribute.start = comp->fmuData->simulationInfo->realParameter[173];
  comp->fmuData->modelData->realParameterData[174].attribute.start = comp->fmuData->simulationInfo->realParameter[174];
  comp->fmuData->modelData->realParameterData[175].attribute.start = comp->fmuData->simulationInfo->realParameter[175];
  comp->fmuData->modelData->realParameterData[176].attribute.start = comp->fmuData->simulationInfo->realParameter[176];
  comp->fmuData->modelData->realParameterData[177].attribute.start = comp->fmuData->simulationInfo->realParameter[177];
  comp->fmuData->modelData->realParameterData[178].attribute.start = comp->fmuData->simulationInfo->realParameter[178];
  comp->fmuData->modelData->realParameterData[179].attribute.start = comp->fmuData->simulationInfo->realParameter[179];
  comp->fmuData->modelData->realParameterData[180].attribute.start = comp->fmuData->simulationInfo->realParameter[180];
  comp->fmuData->modelData->realParameterData[181].attribute.start = comp->fmuData->simulationInfo->realParameter[181];
  comp->fmuData->modelData->realParameterData[182].attribute.start = comp->fmuData->simulationInfo->realParameter[182];
  comp->fmuData->modelData->realParameterData[183].attribute.start = comp->fmuData->simulationInfo->realParameter[183];
  comp->fmuData->modelData->realParameterData[184].attribute.start = comp->fmuData->simulationInfo->realParameter[184];
  comp->fmuData->modelData->realParameterData[185].attribute.start = comp->fmuData->simulationInfo->realParameter[185];
  comp->fmuData->modelData->realParameterData[186].attribute.start = comp->fmuData->simulationInfo->realParameter[186];
  comp->fmuData->modelData->realParameterData[187].attribute.start = comp->fmuData->simulationInfo->realParameter[187];
  comp->fmuData->modelData->realParameterData[188].attribute.start = comp->fmuData->simulationInfo->realParameter[188];
  comp->fmuData->modelData->realParameterData[189].attribute.start = comp->fmuData->simulationInfo->realParameter[189];
  comp->fmuData->modelData->realParameterData[190].attribute.start = comp->fmuData->simulationInfo->realParameter[190];
  comp->fmuData->modelData->realParameterData[191].attribute.start = comp->fmuData->simulationInfo->realParameter[191];
  comp->fmuData->modelData->realParameterData[192].attribute.start = comp->fmuData->simulationInfo->realParameter[192];
  comp->fmuData->modelData->realParameterData[193].attribute.start = comp->fmuData->simulationInfo->realParameter[193];
  comp->fmuData->modelData->realParameterData[194].attribute.start = comp->fmuData->simulationInfo->realParameter[194];
  comp->fmuData->modelData->realParameterData[195].attribute.start = comp->fmuData->simulationInfo->realParameter[195];
  comp->fmuData->modelData->realParameterData[196].attribute.start = comp->fmuData->simulationInfo->realParameter[196];
  comp->fmuData->modelData->realParameterData[197].attribute.start = comp->fmuData->simulationInfo->realParameter[197];
  comp->fmuData->modelData->realParameterData[198].attribute.start = comp->fmuData->simulationInfo->realParameter[198];
  comp->fmuData->modelData->realParameterData[199].attribute.start = comp->fmuData->simulationInfo->realParameter[199];
  comp->fmuData->modelData->realParameterData[200].attribute.start = comp->fmuData->simulationInfo->realParameter[200];
  comp->fmuData->modelData->realParameterData[201].attribute.start = comp->fmuData->simulationInfo->realParameter[201];
  comp->fmuData->modelData->realParameterData[202].attribute.start = comp->fmuData->simulationInfo->realParameter[202];
  comp->fmuData->modelData->realParameterData[203].attribute.start = comp->fmuData->simulationInfo->realParameter[203];
  comp->fmuData->modelData->realParameterData[204].attribute.start = comp->fmuData->simulationInfo->realParameter[204];
  comp->fmuData->modelData->realParameterData[205].attribute.start = comp->fmuData->simulationInfo->realParameter[205];
  comp->fmuData->modelData->realParameterData[206].attribute.start = comp->fmuData->simulationInfo->realParameter[206];
  comp->fmuData->modelData->realParameterData[207].attribute.start = comp->fmuData->simulationInfo->realParameter[207];
  comp->fmuData->modelData->realParameterData[208].attribute.start = comp->fmuData->simulationInfo->realParameter[208];
  comp->fmuData->modelData->realParameterData[209].attribute.start = comp->fmuData->simulationInfo->realParameter[209];
  comp->fmuData->modelData->realParameterData[210].attribute.start = comp->fmuData->simulationInfo->realParameter[210];
  comp->fmuData->modelData->realParameterData[211].attribute.start = comp->fmuData->simulationInfo->realParameter[211];
  comp->fmuData->modelData->realParameterData[212].attribute.start = comp->fmuData->simulationInfo->realParameter[212];
  comp->fmuData->modelData->realParameterData[213].attribute.start = comp->fmuData->simulationInfo->realParameter[213];
  comp->fmuData->modelData->realParameterData[214].attribute.start = comp->fmuData->simulationInfo->realParameter[214];
  comp->fmuData->modelData->realParameterData[215].attribute.start = comp->fmuData->simulationInfo->realParameter[215];
  comp->fmuData->modelData->realParameterData[216].attribute.start = comp->fmuData->simulationInfo->realParameter[216];
  comp->fmuData->modelData->realParameterData[217].attribute.start = comp->fmuData->simulationInfo->realParameter[217];
  comp->fmuData->modelData->realParameterData[218].attribute.start = comp->fmuData->simulationInfo->realParameter[218];
  comp->fmuData->modelData->integerParameterData[0].attribute.start = comp->fmuData->simulationInfo->integerParameter[0];
  comp->fmuData->modelData->integerParameterData[1].attribute.start = comp->fmuData->simulationInfo->integerParameter[1];
  comp->fmuData->modelData->integerParameterData[2].attribute.start = comp->fmuData->simulationInfo->integerParameter[2];
  comp->fmuData->modelData->integerParameterData[3].attribute.start = comp->fmuData->simulationInfo->integerParameter[3];
  comp->fmuData->modelData->booleanParameterData[0].attribute.start = comp->fmuData->simulationInfo->booleanParameter[0];
  comp->fmuData->modelData->booleanParameterData[1].attribute.start = comp->fmuData->simulationInfo->booleanParameter[1];
  comp->fmuData->modelData->booleanParameterData[2].attribute.start = comp->fmuData->simulationInfo->booleanParameter[2];
  comp->fmuData->modelData->booleanParameterData[3].attribute.start = comp->fmuData->simulationInfo->booleanParameter[3];
}

// Used to set the next time event, if any.
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo) {
}

fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr) {
  if (vr < 22) {
    return comp->fmuData->localData[0]->realVars[vr];
  }
  if (vr < 241) {
    return comp->fmuData->simulationInfo->realParameter[vr-22];
  }
  return NAN;
}

fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value) {
  // set start value attribute for all variable that has start value, till initialization mode
  if (vr < 22 && (comp->state == model_state_instantiated || comp->state == model_state_initialization_mode)) {
    comp->fmuData->modelData->realVarsData[vr].attribute.start = value;
  }
  if (vr < 22) {
    comp->fmuData->localData[0]->realVars[vr] = value;
    return fmi2OK;
  }
  if (vr < 241) {
    comp->fmuData->simulationInfo->realParameter[vr-22] = value;
    return fmi2OK;
  }
  return fmi2Error;
}

fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr) {
  if (vr < 0) {
    return comp->fmuData->localData[0]->integerVars[vr];
  }
  if (vr < 4) {
    return comp->fmuData->simulationInfo->integerParameter[vr-0];
  }
  return 0;
}

fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value) {
  // set start value attribute for all variable that has start value, till initialization mode
  if (vr < 0 && (comp->state == model_state_instantiated || comp->state == model_state_initialization_mode)) {
    comp->fmuData->modelData->integerVarsData[vr].attribute.start = value;
  }
  if (vr < 0) {
    comp->fmuData->localData[0]->integerVars[vr] = value;
    return fmi2OK;
  }
  if (vr < 4) {
    comp->fmuData->simulationInfo->integerParameter[vr-0] = value;
    return fmi2OK;
  }
  return fmi2Error;
}
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case 0 : return comp->fmuData->simulationInfo->booleanParameter[0]; break;
    case 1 : return comp->fmuData->simulationInfo->booleanParameter[1]; break;
    case 2 : return comp->fmuData->simulationInfo->booleanParameter[2]; break;
    case 3 : return comp->fmuData->simulationInfo->booleanParameter[3]; break;
    default:
      return fmi2False;
  }
}

fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value) {
  switch (vr) {
    case 0 : comp->fmuData->simulationInfo->booleanParameter[0] = value; break;
    case 1 : comp->fmuData->simulationInfo->booleanParameter[1] = value; break;
    case 2 : comp->fmuData->simulationInfo->booleanParameter[2] = value; break;
    case 3 : comp->fmuData->simulationInfo->booleanParameter[3] = value; break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    default:
      return "";
  }
}

fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value) {
  switch (vr) {
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value){
  switch (vr) {
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

/* function maps input references to a input index used in partialDerivatives */
fmi2ValueReference mapInputReference2InputNumber(const fmi2ValueReference vr) {
    switch (vr) {
      default:
        return -1;
    }
}
/* function maps output references to a input index used in partialDerivatives */
fmi2ValueReference mapOutputReference2OutputNumber(const fmi2ValueReference vr) {
    switch (vr) {
      case 0: return 0; break;
      case 1: return 1; break;
      case 2: return 2; break;
      case 3: return 3; break;
      case 4: return 4; break;
      case 5: return 5; break;
      case 6: return 6; break;
      case 7: return 7; break;
      case 8: return 8; break;
      case 9: return 9; break;
      case 10: return 10; break;
      case 11: return 11; break;
      case 12: return 12; break;
      case 13: return 13; break;
      case 14: return 14; break;
      case 15: return 15; break;
      case 16: return 16; break;
      case 17: return 17; break;
      case 18: return 18; break;
      case 19: return 19; break;
      case 20: return 20; break;
      case 21: return 21; break;
      default:
        return -1;
    }
}
/* function maps output references to an internal output Real derivatives */
fmi2ValueReference mapOutputReference2RealOutputDerivatives(const fmi2ValueReference vr) {
    switch (vr) {
      case 0: return -1; break;
      case 1: return -1; break;
      case 2: return -1; break;
      case 3: return -1; break;
      case 4: return -1; break;
      case 5: return -1; break;
      case 6: return -1; break;
      case 7: return -1; break;
      case 8: return -1; break;
      case 9: return -1; break;
      case 10: return -1; break;
      case 11: return -1; break;
      case 12: return -1; break;
      case 13: return -1; break;
      case 14: return -1; break;
      case 15: return -1; break;
      case 16: return -1; break;
      case 17: return -1; break;
      case 18: return -1; break;
      case 19: return -1; break;
      case 20: return -1; break;
      case 21: return -1; break;
      default:
        return -1;
    }
}
/* function maps initialUnknowns UnknownVars ValueReferences to an internal partial derivatives index */
fmi2ValueReference mapInitialUnknownsdependentIndex(const fmi2ValueReference vr) {
    switch (vr) {
      case 32: return 0; break;
      case 43: return 1; break;
      case 31: return 2; break;
      case 42: return 3; break;
      case 30: return 4; break;
      case 41: return 5; break;
      case 29: return 6; break;
      case 40: return 7; break;
      case 28: return 8; break;
      case 39: return 9; break;
      case 27: return 10; break;
      case 38: return 11; break;
      case 26: return 12; break;
      case 37: return 13; break;
      case 25: return 14; break;
      case 36: return 15; break;
      case 24: return 16; break;
      case 35: return 17; break;
      case 23: return 18; break;
      case 34: return 19; break;
      case 22: return 20; break;
      case 33: return 21; break;
      case 0: return 22; break;
      case 1: return 23; break;
      case 2: return 24; break;
      case 3: return 25; break;
      case 4: return 26; break;
      case 5: return 27; break;
      case 6: return 28; break;
      case 7: return 29; break;
      case 8: return 30; break;
      case 9: return 31; break;
      case 10: return 32; break;
      case 11: return 33; break;
      case 12: return 34; break;
      case 13: return 35; break;
      case 14: return 36; break;
      case 15: return 37; break;
      case 16: return 38; break;
      case 17: return 39; break;
      case 18: return 40; break;
      case 19: return 41; break;
      case 20: return 42; break;
      case 21: return 43; break;
      case 73: return 44; break;
      case 74: return 45; break;
      case 75: return 46; break;
      case 76: return 47; break;
      case 77: return 48; break;
      case 78: return 49; break;
      case 79: return 50; break;
      case 80: return 51; break;
      case 81: return 52; break;
      case 82: return 53; break;
      case 83: return 54; break;
      case 84: return 55; break;
      case 85: return 56; break;
      case 86: return 57; break;
      case 87: return 58; break;
      case 88: return 59; break;
      case 89: return 60; break;
      case 90: return 61; break;
      case 91: return 62; break;
      case 92: return 63; break;
      case 93: return 64; break;
      case 94: return 65; break;
      case 95: return 66; break;
      case 96: return 67; break;
      case 97: return 68; break;
      case 98: return 69; break;
      case 99: return 70; break;
      case 100: return 71; break;
      case 101: return 72; break;
      case 102: return 73; break;
      case 103: return 74; break;
      case 104: return 75; break;
      case 105: return 76; break;
      case 106: return 77; break;
      case 107: return 78; break;
      case 108: return 79; break;
      case 109: return 80; break;
      case 110: return 81; break;
      case 111: return 82; break;
      case 112: return 83; break;
      case 113: return 84; break;
      case 114: return 85; break;
      case 115: return 86; break;
      case 116: return 87; break;
      case 117: return 88; break;
      case 118: return 89; break;
      case 119: return 90; break;
      case 120: return 91; break;
      case 121: return 92; break;
      case 122: return 93; break;
      case 123: return 94; break;
      case 124: return 95; break;
      case 125: return 96; break;
      case 126: return 97; break;
      case 127: return 98; break;
      case 128: return 99; break;
      case 129: return 100; break;
      case 130: return 101; break;
      case 131: return 102; break;
      case 132: return 103; break;
      case 133: return 104; break;
      case 134: return 105; break;
      case 135: return 106; break;
      case 136: return 107; break;
      case 137: return 108; break;
      case 138: return 109; break;
      case 139: return 110; break;
      case 140: return 111; break;
      case 141: return 112; break;
      case 142: return 113; break;
      case 143: return 114; break;
      case 144: return 115; break;
      case 145: return 116; break;
      case 146: return 117; break;
      case 147: return 118; break;
      case 148: return 119; break;
      case 149: return 120; break;
      case 150: return 121; break;
      case 151: return 122; break;
      case 152: return 123; break;
      case 153: return 124; break;
      case 154: return 125; break;
      case 155: return 126; break;
      case 156: return 127; break;
      case 157: return 128; break;
      case 158: return 129; break;
      case 159: return 130; break;
      case 160: return 131; break;
      case 161: return 132; break;
      case 162: return 133; break;
      case 163: return 134; break;
      case 164: return 135; break;
      case 165: return 136; break;
      case 166: return 137; break;
      case 167: return 138; break;
      case 168: return 139; break;
      case 169: return 140; break;
      case 170: return 141; break;
      case 171: return 142; break;
      case 172: return 143; break;
      case 173: return 144; break;
      case 174: return 145; break;
      case 175: return 146; break;
      case 176: return 147; break;
      case 177: return 148; break;
      case 178: return 149; break;
      case 179: return 150; break;
      case 180: return 151; break;
      case 181: return 152; break;
      case 182: return 153; break;
      case 183: return 154; break;
      case 184: return 155; break;
      case 185: return 156; break;
      case 186: return 157; break;
      case 187: return 158; break;
      case 188: return 159; break;
      case 189: return 160; break;
      case 190: return 161; break;
      case 191: return 162; break;
      case 192: return 163; break;
      case 193: return 164; break;
      case 194: return 165; break;
      case 195: return 166; break;
      case 196: return 167; break;
      case 197: return 168; break;
      case 198: return 169; break;
      case 199: return 170; break;
      case 200: return 171; break;
      case 201: return 172; break;
      case 202: return 173; break;
      case 203: return 174; break;
      case 204: return 175; break;
      case 205: return 176; break;
      case 206: return 177; break;
      case 207: return 178; break;
      case 208: return 179; break;
      case 209: return 180; break;
      case 210: return 181; break;
      case 211: return 182; break;
      case 212: return 183; break;
      case 213: return 184; break;
      case 214: return 185; break;
      case 215: return 186; break;
      case 216: return 187; break;
      case 217: return 188; break;
      case 218: return 189; break;
      case 219: return 190; break;
      case 220: return 191; break;
      case 221: return 192; break;
      case 222: return 193; break;
      case 223: return 194; break;
      case 224: return 195; break;
      case 225: return 196; break;
      case 226: return 197; break;
      case 227: return 198; break;
      case 228: return 199; break;
      case 229: return 200; break;
      case 230: return 201; break;
      case 231: return 202; break;
      case 232: return 203; break;
      case 233: return 204; break;
      case 234: return 205; break;
      case 235: return 206; break;
      case 236: return 207; break;
      case 237: return 208; break;
      case 238: return 209; break;
      case 239: return 210; break;
      default:
        return -1;
    }
}
/* function maps initialUnknowns knownVars ValueReferences to an internal partial derivatives index */
fmi2ValueReference mapInitialUnknownsIndependentIndex(const fmi2ValueReference vr) {
    switch (vr) {
      case 60: return 0; break;
      case 61: return 1; break;
      case 63: return 2; break;
      case 64: return 3; break;
      case 67: return 4; break;
      case 68: return 5; break;
      case 71: return 6; break;
      case 72: return 7; break;
      default:
        return -1;
    }
}

#ifdef __cplusplus
}
#endif

