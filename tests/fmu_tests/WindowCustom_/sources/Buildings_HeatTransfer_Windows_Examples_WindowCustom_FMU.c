// define class name and unique id
#define MODEL_IDENTIFIER Buildings_HeatTransfer_Windows_Examples_WindowCustom
#define MODEL_GUID "{e9b71b29-d47d-4456-998d-7c44fc6da4ac}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_functions.h"
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
#define NUMBER_OF_EVENT_INDICATORS 2
#define NUMBER_OF_REALS 503
#define NUMBER_OF_REAL_INPUTS 7
#define NUMBER_OF_INTEGERS 10
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_BOOLEANS 53
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define initial state vector as vector of value references
#define STATES {  }
#define STATESDERIVATIVES {  }


// implementation of the Model Exchange functions
extern void Buildings_HeatTransfer_Windows_Examples_WindowCustom_setupDataStruc(DATA *data, threadData_t *threadData);
#define fmu2_model_interface_setupDataStruc Buildings_HeatTransfer_Windows_Examples_WindowCustom_setupDataStruc
#include "fmi-export/fmu2_model_interface.c.inc"
#include "fmi-export/fmu_read_flags.c.inc"

// Set values for all variables that define a start value
OMC_DISABLE_OPT
void setDefaultStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[1].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[2].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[3].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[4].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[5].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[6].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[7].attribute.start = 0.0;
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
  comp->fmuData->modelData->realVarsData[22].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[23].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[24].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[25].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[26].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[27].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[28].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[29].attribute.start = 7385154648.771004;
  comp->fmuData->modelData->realVarsData[30].attribute.start = 293.15;
  comp->fmuData->modelData->realVarsData[31].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[32].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[33].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[34].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[35].attribute.start = 288.15;
  comp->fmuData->modelData->realVarsData[36].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[37].attribute.start = 335.0127360168967;
  comp->fmuData->modelData->realVarsData[38].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[39].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[40].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[41].attribute.start = 293.15;
  comp->fmuData->modelData->realVarsData[42].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[43].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[44].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[45].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[46].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[47].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[48].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[49].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[50].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[51].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[52].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[53].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[54].attribute.start = 288.15;
  comp->fmuData->modelData->realVarsData[55].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[56].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[57].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[58].attribute.start = 268.0101888135174;
  comp->fmuData->modelData->realVarsData[59].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[60].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[61].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[62].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[63].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[64].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[65].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[66].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[67].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[68].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[69].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[70].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[71].attribute.start = 288.15;
  comp->fmuData->modelData->realVarsData[72].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[73].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[74].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[75].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[76].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[77].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[78].attribute.start = 288.15;
  comp->fmuData->modelData->realVarsData[79].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[80].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[81].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[82].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[83].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[84].attribute.start = 288.15;
  comp->fmuData->modelData->realVarsData[85].attribute.start = 288.15;
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
  comp->fmuData->modelData->realParameterData[22].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[23].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[24].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[25].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[26].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[27].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[28].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[29].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[30].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[31].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[32].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[33].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[34].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[35].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[36].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[37].attribute.start = 0.02897;
  comp->fmuData->modelData->realParameterData[38].attribute.start = 101325.0;
  comp->fmuData->modelData->realParameterData[39].attribute.start = 1002.737;
  comp->fmuData->modelData->realParameterData[40].attribute.start = 0.002873;
  comp->fmuData->modelData->realParameterData[41].attribute.start = 3.723e-06;
  comp->fmuData->modelData->realParameterData[42].attribute.start = 0.012324;
  comp->fmuData->modelData->realParameterData[43].attribute.start = 7.76e-05;
  comp->fmuData->modelData->realParameterData[44].attribute.start = 4.94e-08;
  comp->fmuData->modelData->realParameterData[45].attribute.start = -1.0;
  comp->fmuData->modelData->realParameterData[46].attribute.start = 0.84;
  comp->fmuData->modelData->realParameterData[47].attribute.start = 0.84;
  comp->fmuData->modelData->realParameterData[48].attribute.start = 1.0;
  comp->fmuData->modelData->realParameterData[49].attribute.start = 0.075;
  comp->fmuData->modelData->realParameterData[50].attribute.start = 0.075;
  comp->fmuData->modelData->realParameterData[51].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[52].attribute.start = 0.834;
  comp->fmuData->modelData->realParameterData[53].attribute.start = 0.003;
  comp->fmuData->modelData->realParameterData[54].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[55].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[56].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[57].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[58].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[59].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[60].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[61].attribute.start = 0.25;
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
  comp->fmuData->modelData->realParameterData[152].attribute.start = 0.8;
  comp->fmuData->modelData->realParameterData[153].attribute.start = 0.5;
  comp->fmuData->modelData->realParameterData[154].attribute.start = 0.02897;
  comp->fmuData->modelData->realParameterData[155].attribute.start = 101325.0;
  comp->fmuData->modelData->realParameterData[156].attribute.start = 1002.737;
  comp->fmuData->modelData->realParameterData[157].attribute.start = 0.002873;
  comp->fmuData->modelData->realParameterData[158].attribute.start = 3.723e-06;
  comp->fmuData->modelData->realParameterData[159].attribute.start = 0.012324;
  comp->fmuData->modelData->realParameterData[160].attribute.start = 7.76e-05;
  comp->fmuData->modelData->realParameterData[161].attribute.start = 4.94e-08;
  comp->fmuData->modelData->realParameterData[162].attribute.start = -1.0;
  comp->fmuData->modelData->realParameterData[163].attribute.start = 0.84;
  comp->fmuData->modelData->realParameterData[164].attribute.start = 0.84;
  comp->fmuData->modelData->realParameterData[165].attribute.start = 1.0;
  comp->fmuData->modelData->realParameterData[166].attribute.start = 0.075;
  comp->fmuData->modelData->realParameterData[167].attribute.start = 0.075;
  comp->fmuData->modelData->realParameterData[168].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[169].attribute.start = 0.834;
  comp->fmuData->modelData->realParameterData[170].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[171].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[172].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[173].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[174].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[175].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[176].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[177].attribute.start = 0.25;
  comp->fmuData->modelData->realParameterData[178].attribute.start = 0.25;
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
  comp->fmuData->modelData->realParameterData[218].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[219].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[220].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[221].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[222].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[223].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[224].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[225].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[226].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[227].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[228].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[229].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[230].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[231].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[232].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[233].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[234].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[235].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[236].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[237].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[238].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[239].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[240].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[241].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[242].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[243].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[0].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[1].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[2].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[3].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[4].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[5].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[6].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[7].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[8].attribute.start = 0;
  comp->fmuData->modelData->integerParameterData[9].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[0].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[1].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[2].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[3].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[4].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[5].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[6].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[7].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[8].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[9].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[10].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[11].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[12].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[13].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[14].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[15].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[16].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[17].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[18].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[19].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[20].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[21].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[22].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[23].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[24].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[25].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[26].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[27].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[28].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[29].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[30].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[31].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[32].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[33].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[34].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[35].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[36].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[37].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[38].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[39].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[40].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[41].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[42].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[43].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[44].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[45].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[46].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[47].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[48].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[49].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[50].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[51].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[52].attribute.start = 0;
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
  comp->fmuData->modelData->realVarsData[22].attribute.start =  comp->fmuData->localData[0]->realVars[22];
  comp->fmuData->modelData->realVarsData[23].attribute.start =  comp->fmuData->localData[0]->realVars[23];
  comp->fmuData->modelData->realVarsData[24].attribute.start =  comp->fmuData->localData[0]->realVars[24];
  comp->fmuData->modelData->realVarsData[25].attribute.start =  comp->fmuData->localData[0]->realVars[25];
  comp->fmuData->modelData->realVarsData[26].attribute.start =  comp->fmuData->localData[0]->realVars[26];
  comp->fmuData->modelData->realVarsData[27].attribute.start =  comp->fmuData->localData[0]->realVars[27];
  comp->fmuData->modelData->realVarsData[28].attribute.start =  comp->fmuData->localData[0]->realVars[28];
  comp->fmuData->modelData->realVarsData[29].attribute.start =  comp->fmuData->localData[0]->realVars[29];
  comp->fmuData->modelData->realVarsData[30].attribute.start =  comp->fmuData->localData[0]->realVars[30];
  comp->fmuData->modelData->realVarsData[31].attribute.start =  comp->fmuData->localData[0]->realVars[31];
  comp->fmuData->modelData->realVarsData[32].attribute.start =  comp->fmuData->localData[0]->realVars[32];
  comp->fmuData->modelData->realVarsData[33].attribute.start =  comp->fmuData->localData[0]->realVars[33];
  comp->fmuData->modelData->realVarsData[34].attribute.start =  comp->fmuData->localData[0]->realVars[34];
  comp->fmuData->modelData->realVarsData[35].attribute.start =  comp->fmuData->localData[0]->realVars[35];
  comp->fmuData->modelData->realVarsData[36].attribute.start =  comp->fmuData->localData[0]->realVars[36];
  comp->fmuData->modelData->realVarsData[37].attribute.start =  comp->fmuData->localData[0]->realVars[37];
  comp->fmuData->modelData->realVarsData[38].attribute.start =  comp->fmuData->localData[0]->realVars[38];
  comp->fmuData->modelData->realVarsData[39].attribute.start =  comp->fmuData->localData[0]->realVars[39];
  comp->fmuData->modelData->realVarsData[40].attribute.start =  comp->fmuData->localData[0]->realVars[40];
  comp->fmuData->modelData->realVarsData[41].attribute.start =  comp->fmuData->localData[0]->realVars[41];
  comp->fmuData->modelData->realVarsData[42].attribute.start =  comp->fmuData->localData[0]->realVars[42];
  comp->fmuData->modelData->realVarsData[43].attribute.start =  comp->fmuData->localData[0]->realVars[43];
  comp->fmuData->modelData->realVarsData[44].attribute.start =  comp->fmuData->localData[0]->realVars[44];
  comp->fmuData->modelData->realVarsData[45].attribute.start =  comp->fmuData->localData[0]->realVars[45];
  comp->fmuData->modelData->realVarsData[46].attribute.start =  comp->fmuData->localData[0]->realVars[46];
  comp->fmuData->modelData->realVarsData[47].attribute.start =  comp->fmuData->localData[0]->realVars[47];
  comp->fmuData->modelData->realVarsData[48].attribute.start =  comp->fmuData->localData[0]->realVars[48];
  comp->fmuData->modelData->realVarsData[49].attribute.start =  comp->fmuData->localData[0]->realVars[49];
  comp->fmuData->modelData->realVarsData[50].attribute.start =  comp->fmuData->localData[0]->realVars[50];
  comp->fmuData->modelData->realVarsData[51].attribute.start =  comp->fmuData->localData[0]->realVars[51];
  comp->fmuData->modelData->realVarsData[52].attribute.start =  comp->fmuData->localData[0]->realVars[52];
  comp->fmuData->modelData->realVarsData[53].attribute.start =  comp->fmuData->localData[0]->realVars[53];
  comp->fmuData->modelData->realVarsData[54].attribute.start =  comp->fmuData->localData[0]->realVars[54];
  comp->fmuData->modelData->realVarsData[55].attribute.start =  comp->fmuData->localData[0]->realVars[55];
  comp->fmuData->modelData->realVarsData[56].attribute.start =  comp->fmuData->localData[0]->realVars[56];
  comp->fmuData->modelData->realVarsData[57].attribute.start =  comp->fmuData->localData[0]->realVars[57];
  comp->fmuData->modelData->realVarsData[58].attribute.start =  comp->fmuData->localData[0]->realVars[58];
  comp->fmuData->modelData->realVarsData[59].attribute.start =  comp->fmuData->localData[0]->realVars[59];
  comp->fmuData->modelData->realVarsData[60].attribute.start =  comp->fmuData->localData[0]->realVars[60];
  comp->fmuData->modelData->realVarsData[61].attribute.start =  comp->fmuData->localData[0]->realVars[61];
  comp->fmuData->modelData->realVarsData[62].attribute.start =  comp->fmuData->localData[0]->realVars[62];
  comp->fmuData->modelData->realVarsData[63].attribute.start =  comp->fmuData->localData[0]->realVars[63];
  comp->fmuData->modelData->realVarsData[64].attribute.start =  comp->fmuData->localData[0]->realVars[64];
  comp->fmuData->modelData->realVarsData[65].attribute.start =  comp->fmuData->localData[0]->realVars[65];
  comp->fmuData->modelData->realVarsData[66].attribute.start =  comp->fmuData->localData[0]->realVars[66];
  comp->fmuData->modelData->realVarsData[67].attribute.start =  comp->fmuData->localData[0]->realVars[67];
  comp->fmuData->modelData->realVarsData[68].attribute.start =  comp->fmuData->localData[0]->realVars[68];
  comp->fmuData->modelData->realVarsData[69].attribute.start =  comp->fmuData->localData[0]->realVars[69];
  comp->fmuData->modelData->realVarsData[70].attribute.start =  comp->fmuData->localData[0]->realVars[70];
  comp->fmuData->modelData->realVarsData[71].attribute.start =  comp->fmuData->localData[0]->realVars[71];
  comp->fmuData->modelData->realVarsData[72].attribute.start =  comp->fmuData->localData[0]->realVars[72];
  comp->fmuData->modelData->realVarsData[73].attribute.start =  comp->fmuData->localData[0]->realVars[73];
  comp->fmuData->modelData->realVarsData[74].attribute.start =  comp->fmuData->localData[0]->realVars[74];
  comp->fmuData->modelData->realVarsData[75].attribute.start =  comp->fmuData->localData[0]->realVars[75];
  comp->fmuData->modelData->realVarsData[76].attribute.start =  comp->fmuData->localData[0]->realVars[76];
  comp->fmuData->modelData->realVarsData[77].attribute.start =  comp->fmuData->localData[0]->realVars[77];
  comp->fmuData->modelData->realVarsData[78].attribute.start =  comp->fmuData->localData[0]->realVars[78];
  comp->fmuData->modelData->realVarsData[79].attribute.start =  comp->fmuData->localData[0]->realVars[79];
  comp->fmuData->modelData->realVarsData[80].attribute.start =  comp->fmuData->localData[0]->realVars[80];
  comp->fmuData->modelData->realVarsData[81].attribute.start =  comp->fmuData->localData[0]->realVars[81];
  comp->fmuData->modelData->realVarsData[82].attribute.start =  comp->fmuData->localData[0]->realVars[82];
  comp->fmuData->modelData->realVarsData[83].attribute.start =  comp->fmuData->localData[0]->realVars[83];
  comp->fmuData->modelData->realVarsData[84].attribute.start =  comp->fmuData->localData[0]->realVars[84];
  comp->fmuData->modelData->realVarsData[85].attribute.start =  comp->fmuData->localData[0]->realVars[85];
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
  comp->fmuData->modelData->realParameterData[219].attribute.start = comp->fmuData->simulationInfo->realParameter[219];
  comp->fmuData->modelData->realParameterData[220].attribute.start = comp->fmuData->simulationInfo->realParameter[220];
  comp->fmuData->modelData->realParameterData[221].attribute.start = comp->fmuData->simulationInfo->realParameter[221];
  comp->fmuData->modelData->realParameterData[222].attribute.start = comp->fmuData->simulationInfo->realParameter[222];
  comp->fmuData->modelData->realParameterData[223].attribute.start = comp->fmuData->simulationInfo->realParameter[223];
  comp->fmuData->modelData->realParameterData[224].attribute.start = comp->fmuData->simulationInfo->realParameter[224];
  comp->fmuData->modelData->realParameterData[225].attribute.start = comp->fmuData->simulationInfo->realParameter[225];
  comp->fmuData->modelData->realParameterData[226].attribute.start = comp->fmuData->simulationInfo->realParameter[226];
  comp->fmuData->modelData->realParameterData[227].attribute.start = comp->fmuData->simulationInfo->realParameter[227];
  comp->fmuData->modelData->realParameterData[228].attribute.start = comp->fmuData->simulationInfo->realParameter[228];
  comp->fmuData->modelData->realParameterData[229].attribute.start = comp->fmuData->simulationInfo->realParameter[229];
  comp->fmuData->modelData->realParameterData[230].attribute.start = comp->fmuData->simulationInfo->realParameter[230];
  comp->fmuData->modelData->realParameterData[231].attribute.start = comp->fmuData->simulationInfo->realParameter[231];
  comp->fmuData->modelData->realParameterData[232].attribute.start = comp->fmuData->simulationInfo->realParameter[232];
  comp->fmuData->modelData->realParameterData[233].attribute.start = comp->fmuData->simulationInfo->realParameter[233];
  comp->fmuData->modelData->realParameterData[234].attribute.start = comp->fmuData->simulationInfo->realParameter[234];
  comp->fmuData->modelData->realParameterData[235].attribute.start = comp->fmuData->simulationInfo->realParameter[235];
  comp->fmuData->modelData->realParameterData[236].attribute.start = comp->fmuData->simulationInfo->realParameter[236];
  comp->fmuData->modelData->realParameterData[237].attribute.start = comp->fmuData->simulationInfo->realParameter[237];
  comp->fmuData->modelData->realParameterData[238].attribute.start = comp->fmuData->simulationInfo->realParameter[238];
  comp->fmuData->modelData->realParameterData[239].attribute.start = comp->fmuData->simulationInfo->realParameter[239];
  comp->fmuData->modelData->realParameterData[240].attribute.start = comp->fmuData->simulationInfo->realParameter[240];
  comp->fmuData->modelData->realParameterData[241].attribute.start = comp->fmuData->simulationInfo->realParameter[241];
  comp->fmuData->modelData->realParameterData[242].attribute.start = comp->fmuData->simulationInfo->realParameter[242];
  comp->fmuData->modelData->realParameterData[243].attribute.start = comp->fmuData->simulationInfo->realParameter[243];
  comp->fmuData->modelData->integerParameterData[0].attribute.start = comp->fmuData->simulationInfo->integerParameter[0];
  comp->fmuData->modelData->integerParameterData[1].attribute.start = comp->fmuData->simulationInfo->integerParameter[1];
  comp->fmuData->modelData->integerParameterData[2].attribute.start = comp->fmuData->simulationInfo->integerParameter[2];
  comp->fmuData->modelData->integerParameterData[3].attribute.start = comp->fmuData->simulationInfo->integerParameter[3];
  comp->fmuData->modelData->integerParameterData[4].attribute.start = comp->fmuData->simulationInfo->integerParameter[4];
  comp->fmuData->modelData->integerParameterData[5].attribute.start = comp->fmuData->simulationInfo->integerParameter[5];
  comp->fmuData->modelData->integerParameterData[6].attribute.start = comp->fmuData->simulationInfo->integerParameter[6];
  comp->fmuData->modelData->integerParameterData[7].attribute.start = comp->fmuData->simulationInfo->integerParameter[7];
  comp->fmuData->modelData->integerParameterData[8].attribute.start = comp->fmuData->simulationInfo->integerParameter[8];
  comp->fmuData->modelData->integerParameterData[9].attribute.start = comp->fmuData->simulationInfo->integerParameter[9];
  comp->fmuData->modelData->booleanParameterData[0].attribute.start = comp->fmuData->simulationInfo->booleanParameter[0];
  comp->fmuData->modelData->booleanParameterData[1].attribute.start = comp->fmuData->simulationInfo->booleanParameter[1];
  comp->fmuData->modelData->booleanParameterData[2].attribute.start = comp->fmuData->simulationInfo->booleanParameter[2];
  comp->fmuData->modelData->booleanParameterData[3].attribute.start = comp->fmuData->simulationInfo->booleanParameter[3];
  comp->fmuData->modelData->booleanParameterData[4].attribute.start = comp->fmuData->simulationInfo->booleanParameter[4];
  comp->fmuData->modelData->booleanParameterData[5].attribute.start = comp->fmuData->simulationInfo->booleanParameter[5];
  comp->fmuData->modelData->booleanParameterData[6].attribute.start = comp->fmuData->simulationInfo->booleanParameter[6];
  comp->fmuData->modelData->booleanParameterData[7].attribute.start = comp->fmuData->simulationInfo->booleanParameter[7];
  comp->fmuData->modelData->booleanParameterData[8].attribute.start = comp->fmuData->simulationInfo->booleanParameter[8];
  comp->fmuData->modelData->booleanParameterData[9].attribute.start = comp->fmuData->simulationInfo->booleanParameter[9];
  comp->fmuData->modelData->booleanParameterData[10].attribute.start = comp->fmuData->simulationInfo->booleanParameter[10];
  comp->fmuData->modelData->booleanParameterData[11].attribute.start = comp->fmuData->simulationInfo->booleanParameter[11];
  comp->fmuData->modelData->booleanParameterData[12].attribute.start = comp->fmuData->simulationInfo->booleanParameter[12];
  comp->fmuData->modelData->booleanParameterData[13].attribute.start = comp->fmuData->simulationInfo->booleanParameter[13];
  comp->fmuData->modelData->booleanParameterData[14].attribute.start = comp->fmuData->simulationInfo->booleanParameter[14];
  comp->fmuData->modelData->booleanParameterData[15].attribute.start = comp->fmuData->simulationInfo->booleanParameter[15];
  comp->fmuData->modelData->booleanParameterData[16].attribute.start = comp->fmuData->simulationInfo->booleanParameter[16];
  comp->fmuData->modelData->booleanParameterData[17].attribute.start = comp->fmuData->simulationInfo->booleanParameter[17];
  comp->fmuData->modelData->booleanParameterData[18].attribute.start = comp->fmuData->simulationInfo->booleanParameter[18];
  comp->fmuData->modelData->booleanParameterData[19].attribute.start = comp->fmuData->simulationInfo->booleanParameter[19];
  comp->fmuData->modelData->booleanParameterData[20].attribute.start = comp->fmuData->simulationInfo->booleanParameter[20];
  comp->fmuData->modelData->booleanParameterData[21].attribute.start = comp->fmuData->simulationInfo->booleanParameter[21];
  comp->fmuData->modelData->booleanParameterData[22].attribute.start = comp->fmuData->simulationInfo->booleanParameter[22];
  comp->fmuData->modelData->booleanParameterData[23].attribute.start = comp->fmuData->simulationInfo->booleanParameter[23];
  comp->fmuData->modelData->booleanParameterData[24].attribute.start = comp->fmuData->simulationInfo->booleanParameter[24];
  comp->fmuData->modelData->booleanParameterData[25].attribute.start = comp->fmuData->simulationInfo->booleanParameter[25];
  comp->fmuData->modelData->booleanParameterData[26].attribute.start = comp->fmuData->simulationInfo->booleanParameter[26];
  comp->fmuData->modelData->booleanParameterData[27].attribute.start = comp->fmuData->simulationInfo->booleanParameter[27];
  comp->fmuData->modelData->booleanParameterData[28].attribute.start = comp->fmuData->simulationInfo->booleanParameter[28];
  comp->fmuData->modelData->booleanParameterData[29].attribute.start = comp->fmuData->simulationInfo->booleanParameter[29];
  comp->fmuData->modelData->booleanParameterData[30].attribute.start = comp->fmuData->simulationInfo->booleanParameter[30];
  comp->fmuData->modelData->booleanParameterData[31].attribute.start = comp->fmuData->simulationInfo->booleanParameter[31];
  comp->fmuData->modelData->booleanParameterData[32].attribute.start = comp->fmuData->simulationInfo->booleanParameter[32];
  comp->fmuData->modelData->booleanParameterData[33].attribute.start = comp->fmuData->simulationInfo->booleanParameter[33];
  comp->fmuData->modelData->booleanParameterData[34].attribute.start = comp->fmuData->simulationInfo->booleanParameter[34];
  comp->fmuData->modelData->booleanParameterData[35].attribute.start = comp->fmuData->simulationInfo->booleanParameter[35];
  comp->fmuData->modelData->booleanParameterData[36].attribute.start = comp->fmuData->simulationInfo->booleanParameter[36];
  comp->fmuData->modelData->booleanParameterData[37].attribute.start = comp->fmuData->simulationInfo->booleanParameter[37];
  comp->fmuData->modelData->booleanParameterData[38].attribute.start = comp->fmuData->simulationInfo->booleanParameter[38];
  comp->fmuData->modelData->booleanParameterData[39].attribute.start = comp->fmuData->simulationInfo->booleanParameter[39];
  comp->fmuData->modelData->booleanParameterData[40].attribute.start = comp->fmuData->simulationInfo->booleanParameter[40];
  comp->fmuData->modelData->booleanParameterData[41].attribute.start = comp->fmuData->simulationInfo->booleanParameter[41];
  comp->fmuData->modelData->booleanParameterData[42].attribute.start = comp->fmuData->simulationInfo->booleanParameter[42];
  comp->fmuData->modelData->booleanParameterData[43].attribute.start = comp->fmuData->simulationInfo->booleanParameter[43];
  comp->fmuData->modelData->booleanParameterData[44].attribute.start = comp->fmuData->simulationInfo->booleanParameter[44];
  comp->fmuData->modelData->booleanParameterData[45].attribute.start = comp->fmuData->simulationInfo->booleanParameter[45];
  comp->fmuData->modelData->booleanParameterData[46].attribute.start = comp->fmuData->simulationInfo->booleanParameter[46];
  comp->fmuData->modelData->booleanParameterData[47].attribute.start = comp->fmuData->simulationInfo->booleanParameter[47];
  comp->fmuData->modelData->booleanParameterData[48].attribute.start = comp->fmuData->simulationInfo->booleanParameter[48];
  comp->fmuData->modelData->booleanParameterData[49].attribute.start = comp->fmuData->simulationInfo->booleanParameter[49];
  comp->fmuData->modelData->booleanParameterData[50].attribute.start = comp->fmuData->simulationInfo->booleanParameter[50];
  comp->fmuData->modelData->booleanParameterData[51].attribute.start = comp->fmuData->simulationInfo->booleanParameter[51];
  comp->fmuData->modelData->booleanParameterData[52].attribute.start = comp->fmuData->simulationInfo->booleanParameter[52];
}

// Used to set the next time event, if any.
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo) {
}

static const int realAliasIndexes[173] = {
  2, 6, 9, 7, 7, 64, 65, 2, 3, 5, 7, -9, 7, 67, 67, 14, -45, 44, 7, -45,
  70, -19, 7, 18, 84, -45, 70, 78, 18, 84, 15, 31, 24, 32, 15, 17, 5, 7, 21, 12,
  13, 31, 28, -21, 7, 20, 78, 12, 10, 10, 12, 3, 66, 66, 31, 66, 67, 64, 64, 33,
  65, 65, 35, 37, 33, 35, -45, 35, 44, 71, 40, 41, 35, 53, 54, -51, 35, 50, 85, 47,
  44, 71, 50, 85, 43, 48, 66, 66, 55, 47, 66, 56, 40, 4, 41, 41, 62, 37, 57, 68,
  62, 66, 66, 69, 59, 37, 9, 33, 6, 35, 12, 60, 13, 10, 58, 11, 0, 1, 44, -45,
  44, 44, 70, -45, 71, 12, 60, 10, 58, 0, 12, 60, 10, 58, 0, -21, 78, -54, 54, 77,
  -21, 78, -54, 54, -21, -54, 54, 13, 68, 11, 69, 1, 13, 68, 11, 69, 1, -19, 84, -51,
  85, 83, -19, 84, -51, 85, -19, -51, 66, 66, 77, 83, 66
};

fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr) {
  if (vr < 86) {
    return comp->fmuData->localData[0]->realVars[vr];
  }
  if (vr < 330) {
    return comp->fmuData->simulationInfo->realParameter[vr-86];
  }
  if (vr < 503) {
    int ix = realAliasIndexes[vr-330];
    return ix>=0 ? getReal(comp, ix) : -getReal(comp, -(ix+1));
  }
  return NAN;
}

fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value) {
  // set start value attribute for all variable that has start value, till initialization mode
  if (vr < 86 && (comp->state == model_state_instantiated || comp->state == model_state_initialization_mode)) {
    comp->fmuData->modelData->realVarsData[vr].attribute.start = value;
  }
  if (vr < 86) {
    comp->fmuData->localData[0]->realVars[vr] = value;
    return fmi2OK;
  }
  if (vr < 330) {
    comp->fmuData->simulationInfo->realParameter[vr-86] = value;
    return fmi2OK;
  }
  if (vr < 503) {
    int ix = realAliasIndexes[vr-330];
    return ix >= 0 ? setReal(comp, ix, value) : setReal(comp, -(ix+1), -value);
  }
  return fmi2Error;
}

fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr) {
  if (vr < 0) {
    return comp->fmuData->localData[0]->integerVars[vr];
  }
  if (vr < 10) {
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
  if (vr < 10) {
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
    case 4 : return comp->fmuData->simulationInfo->booleanParameter[4]; break;
    case 5 : return comp->fmuData->simulationInfo->booleanParameter[5]; break;
    case 6 : return comp->fmuData->simulationInfo->booleanParameter[6]; break;
    case 7 : return comp->fmuData->simulationInfo->booleanParameter[7]; break;
    case 8 : return comp->fmuData->simulationInfo->booleanParameter[8]; break;
    case 9 : return comp->fmuData->simulationInfo->booleanParameter[9]; break;
    case 10 : return comp->fmuData->simulationInfo->booleanParameter[10]; break;
    case 11 : return comp->fmuData->simulationInfo->booleanParameter[11]; break;
    case 12 : return comp->fmuData->simulationInfo->booleanParameter[12]; break;
    case 13 : return comp->fmuData->simulationInfo->booleanParameter[13]; break;
    case 14 : return comp->fmuData->simulationInfo->booleanParameter[14]; break;
    case 15 : return comp->fmuData->simulationInfo->booleanParameter[15]; break;
    case 16 : return comp->fmuData->simulationInfo->booleanParameter[16]; break;
    case 17 : return comp->fmuData->simulationInfo->booleanParameter[17]; break;
    case 18 : return comp->fmuData->simulationInfo->booleanParameter[18]; break;
    case 19 : return comp->fmuData->simulationInfo->booleanParameter[19]; break;
    case 20 : return comp->fmuData->simulationInfo->booleanParameter[20]; break;
    case 21 : return comp->fmuData->simulationInfo->booleanParameter[21]; break;
    case 22 : return comp->fmuData->simulationInfo->booleanParameter[22]; break;
    case 23 : return comp->fmuData->simulationInfo->booleanParameter[23]; break;
    case 24 : return comp->fmuData->simulationInfo->booleanParameter[24]; break;
    case 25 : return comp->fmuData->simulationInfo->booleanParameter[25]; break;
    case 26 : return comp->fmuData->simulationInfo->booleanParameter[26]; break;
    case 27 : return comp->fmuData->simulationInfo->booleanParameter[27]; break;
    case 28 : return comp->fmuData->simulationInfo->booleanParameter[28]; break;
    case 29 : return comp->fmuData->simulationInfo->booleanParameter[29]; break;
    case 30 : return comp->fmuData->simulationInfo->booleanParameter[30]; break;
    case 31 : return comp->fmuData->simulationInfo->booleanParameter[31]; break;
    case 32 : return comp->fmuData->simulationInfo->booleanParameter[32]; break;
    case 33 : return comp->fmuData->simulationInfo->booleanParameter[33]; break;
    case 34 : return comp->fmuData->simulationInfo->booleanParameter[34]; break;
    case 35 : return comp->fmuData->simulationInfo->booleanParameter[35]; break;
    case 36 : return comp->fmuData->simulationInfo->booleanParameter[36]; break;
    case 37 : return comp->fmuData->simulationInfo->booleanParameter[37]; break;
    case 38 : return comp->fmuData->simulationInfo->booleanParameter[38]; break;
    case 39 : return comp->fmuData->simulationInfo->booleanParameter[39]; break;
    case 40 : return comp->fmuData->simulationInfo->booleanParameter[40]; break;
    case 41 : return comp->fmuData->simulationInfo->booleanParameter[41]; break;
    case 42 : return comp->fmuData->simulationInfo->booleanParameter[42]; break;
    case 43 : return comp->fmuData->simulationInfo->booleanParameter[43]; break;
    case 44 : return comp->fmuData->simulationInfo->booleanParameter[44]; break;
    case 45 : return comp->fmuData->simulationInfo->booleanParameter[45]; break;
    case 46 : return comp->fmuData->simulationInfo->booleanParameter[46]; break;
    case 47 : return comp->fmuData->simulationInfo->booleanParameter[47]; break;
    case 48 : return comp->fmuData->simulationInfo->booleanParameter[48]; break;
    case 49 : return comp->fmuData->simulationInfo->booleanParameter[49]; break;
    case 50 : return comp->fmuData->simulationInfo->booleanParameter[50]; break;
    case 51 : return comp->fmuData->simulationInfo->booleanParameter[51]; break;
    case 52 : return comp->fmuData->simulationInfo->booleanParameter[52]; break;
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
    case 4 : comp->fmuData->simulationInfo->booleanParameter[4] = value; break;
    case 5 : comp->fmuData->simulationInfo->booleanParameter[5] = value; break;
    case 6 : comp->fmuData->simulationInfo->booleanParameter[6] = value; break;
    case 7 : comp->fmuData->simulationInfo->booleanParameter[7] = value; break;
    case 8 : comp->fmuData->simulationInfo->booleanParameter[8] = value; break;
    case 9 : comp->fmuData->simulationInfo->booleanParameter[9] = value; break;
    case 10 : comp->fmuData->simulationInfo->booleanParameter[10] = value; break;
    case 11 : comp->fmuData->simulationInfo->booleanParameter[11] = value; break;
    case 12 : comp->fmuData->simulationInfo->booleanParameter[12] = value; break;
    case 13 : comp->fmuData->simulationInfo->booleanParameter[13] = value; break;
    case 14 : comp->fmuData->simulationInfo->booleanParameter[14] = value; break;
    case 15 : comp->fmuData->simulationInfo->booleanParameter[15] = value; break;
    case 16 : comp->fmuData->simulationInfo->booleanParameter[16] = value; break;
    case 17 : comp->fmuData->simulationInfo->booleanParameter[17] = value; break;
    case 18 : comp->fmuData->simulationInfo->booleanParameter[18] = value; break;
    case 19 : comp->fmuData->simulationInfo->booleanParameter[19] = value; break;
    case 20 : comp->fmuData->simulationInfo->booleanParameter[20] = value; break;
    case 21 : comp->fmuData->simulationInfo->booleanParameter[21] = value; break;
    case 22 : comp->fmuData->simulationInfo->booleanParameter[22] = value; break;
    case 23 : comp->fmuData->simulationInfo->booleanParameter[23] = value; break;
    case 24 : comp->fmuData->simulationInfo->booleanParameter[24] = value; break;
    case 25 : comp->fmuData->simulationInfo->booleanParameter[25] = value; break;
    case 26 : comp->fmuData->simulationInfo->booleanParameter[26] = value; break;
    case 27 : comp->fmuData->simulationInfo->booleanParameter[27] = value; break;
    case 28 : comp->fmuData->simulationInfo->booleanParameter[28] = value; break;
    case 29 : comp->fmuData->simulationInfo->booleanParameter[29] = value; break;
    case 30 : comp->fmuData->simulationInfo->booleanParameter[30] = value; break;
    case 31 : comp->fmuData->simulationInfo->booleanParameter[31] = value; break;
    case 32 : comp->fmuData->simulationInfo->booleanParameter[32] = value; break;
    case 33 : comp->fmuData->simulationInfo->booleanParameter[33] = value; break;
    case 34 : comp->fmuData->simulationInfo->booleanParameter[34] = value; break;
    case 35 : comp->fmuData->simulationInfo->booleanParameter[35] = value; break;
    case 36 : comp->fmuData->simulationInfo->booleanParameter[36] = value; break;
    case 37 : comp->fmuData->simulationInfo->booleanParameter[37] = value; break;
    case 38 : comp->fmuData->simulationInfo->booleanParameter[38] = value; break;
    case 39 : comp->fmuData->simulationInfo->booleanParameter[39] = value; break;
    case 40 : comp->fmuData->simulationInfo->booleanParameter[40] = value; break;
    case 41 : comp->fmuData->simulationInfo->booleanParameter[41] = value; break;
    case 42 : comp->fmuData->simulationInfo->booleanParameter[42] = value; break;
    case 43 : comp->fmuData->simulationInfo->booleanParameter[43] = value; break;
    case 44 : comp->fmuData->simulationInfo->booleanParameter[44] = value; break;
    case 45 : comp->fmuData->simulationInfo->booleanParameter[45] = value; break;
    case 46 : comp->fmuData->simulationInfo->booleanParameter[46] = value; break;
    case 47 : comp->fmuData->simulationInfo->booleanParameter[47] = value; break;
    case 48 : comp->fmuData->simulationInfo->booleanParameter[48] = value; break;
    case 49 : comp->fmuData->simulationInfo->booleanParameter[49] = value; break;
    case 50 : comp->fmuData->simulationInfo->booleanParameter[50] = value; break;
    case 51 : comp->fmuData->simulationInfo->booleanParameter[51] = value; break;
    case 52 : comp->fmuData->simulationInfo->booleanParameter[52] = value; break;
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
      case 0: return 0; break;
      case 1: return 1; break;
      case 3: return 2; break;
      case 4: return 3; break;
      case 5: return 4; break;
      case 7: return 5; break;
      case 67: return 6; break;
      default:
        return -1;
    }
}
/* function maps output references to a input index used in partialDerivatives */
fmi2ValueReference mapOutputReference2OutputNumber(const fmi2ValueReference vr) {
    switch (vr) {
      case 2: return 0; break;
      case 6: return 1; break;
      case 9: return 2; break;
      default:
        return -1;
    }
}
/* function maps output references to an internal output Real derivatives */
fmi2ValueReference mapOutputReference2RealOutputDerivatives(const fmi2ValueReference vr) {
    switch (vr) {
      case 2: return -1; break;
      case 6: return -1; break;
      case 9: return -1; break;
      default:
        return -1;
    }
}
/* function maps initialUnknowns UnknownVars ValueReferences to an internal partial derivatives index */
fmi2ValueReference mapInitialUnknownsdependentIndex(const fmi2ValueReference vr) {
    switch (vr) {
      case 297: return 0; break;
      case 298: return 1; break;
      case 295: return 2; break;
      case 227: return 3; break;
      case 228: return 4; break;
      case 225: return 5; break;
      case 317: return 6; break;
      case 313: return 7; break;
      case 311: return 8; break;
      case 312: return 9; break;
      case 308: return 10; break;
      case 316: return 11; break;
      case 315: return 12; break;
      case 314: return 13; break;
      case 310: return 14; break;
      case 309: return 15; break;
      case 307: return 16; break;
      case 328: return 17; break;
      case 324: return 18; break;
      case 322: return 19; break;
      case 323: return 20; break;
      case 319: return 21; break;
      case 327: return 22; break;
      case 326: return 23; break;
      case 325: return 24; break;
      case 321: return 25; break;
      case 320: return 26; break;
      case 318: return 27; break;
      case 102: return 28; break;
      case 103: return 29; break;
      case 109: return 30; break;
      case 105: return 31; break;
      case 106: return 32; break;
      case 150: return 33; break;
      case 151: return 34; break;
      case 176: return 35; break;
      case 160: return 36; break;
      case 162: return 37; break;
      case 167: return 38; break;
      case 169: return 39; break;
      case 183: return 40; break;
      case 184: return 41; break;
      case 2: return 42; break;
      case 6: return 43; break;
      case 9: return 44; break;
      case 86: return 45; break;
      case 87: return 46; break;
      case 88: return 47; break;
      case 89: return 48; break;
      case 90: return 49; break;
      case 91: return 50; break;
      case 92: return 51; break;
      case 93: return 52; break;
      case 94: return 53; break;
      case 95: return 54; break;
      case 96: return 55; break;
      case 97: return 56; break;
      case 98: return 57; break;
      case 99: return 58; break;
      case 100: return 59; break;
      case 101: return 60; break;
      case 104: return 61; break;
      case 107: return 62; break;
      case 108: return 63; break;
      case 110: return 64; break;
      case 111: return 65; break;
      case 112: return 66; break;
      case 113: return 67; break;
      case 114: return 68; break;
      case 115: return 69; break;
      case 116: return 70; break;
      case 117: return 71; break;
      case 118: return 72; break;
      case 119: return 73; break;
      case 120: return 74; break;
      case 121: return 75; break;
      case 122: return 76; break;
      case 140: return 77; break;
      case 141: return 78; break;
      case 144: return 79; break;
      case 145: return 80; break;
      case 148: return 81; break;
      case 149: return 82; break;
      case 152: return 83; break;
      case 153: return 84; break;
      case 154: return 85; break;
      case 155: return 86; break;
      case 156: return 87; break;
      case 157: return 88; break;
      case 158: return 89; break;
      case 159: return 90; break;
      case 161: return 91; break;
      case 163: return 92; break;
      case 164: return 93; break;
      case 165: return 94; break;
      case 166: return 95; break;
      case 168: return 96; break;
      case 170: return 97; break;
      case 171: return 98; break;
      case 172: return 99; break;
      case 173: return 100; break;
      case 174: return 101; break;
      case 175: return 102; break;
      case 177: return 103; break;
      case 178: return 104; break;
      case 179: return 105; break;
      case 180: return 106; break;
      case 181: return 107; break;
      case 182: return 108; break;
      case 185: return 109; break;
      case 186: return 110; break;
      case 187: return 111; break;
      case 188: return 112; break;
      case 189: return 113; break;
      case 190: return 114; break;
      case 191: return 115; break;
      case 192: return 116; break;
      case 193: return 117; break;
      case 194: return 118; break;
      case 195: return 119; break;
      case 196: return 120; break;
      case 197: return 121; break;
      case 198: return 122; break;
      case 199: return 123; break;
      case 200: return 124; break;
      case 201: return 125; break;
      case 202: return 126; break;
      case 203: return 127; break;
      case 204: return 128; break;
      case 205: return 129; break;
      case 206: return 130; break;
      case 207: return 131; break;
      case 208: return 132; break;
      case 209: return 133; break;
      case 210: return 134; break;
      case 211: return 135; break;
      case 212: return 136; break;
      case 213: return 137; break;
      case 214: return 138; break;
      case 215: return 139; break;
      case 216: return 140; break;
      case 217: return 141; break;
      case 218: return 142; break;
      case 219: return 143; break;
      case 220: return 144; break;
      case 221: return 145; break;
      case 222: return 146; break;
      case 223: return 147; break;
      case 224: return 148; break;
      case 226: return 149; break;
      case 229: return 150; break;
      case 230: return 151; break;
      case 231: return 152; break;
      case 232: return 153; break;
      case 233: return 154; break;
      case 234: return 155; break;
      case 235: return 156; break;
      case 236: return 157; break;
      case 237: return 158; break;
      case 256: return 159; break;
      case 265: return 160; break;
      case 266: return 161; break;
      case 267: return 162; break;
      case 268: return 163; break;
      case 269: return 164; break;
      case 270: return 165; break;
      case 271: return 166; break;
      case 272: return 167; break;
      case 273: return 168; break;
      case 274: return 169; break;
      case 275: return 170; break;
      case 276: return 171; break;
      case 277: return 172; break;
      case 278: return 173; break;
      case 279: return 174; break;
      case 280: return 175; break;
      case 281: return 176; break;
      case 282: return 177; break;
      case 283: return 178; break;
      case 284: return 179; break;
      case 285: return 180; break;
      case 286: return 181; break;
      case 287: return 182; break;
      case 288: return 183; break;
      case 289: return 184; break;
      case 290: return 185; break;
      case 291: return 186; break;
      case 292: return 187; break;
      case 293: return 188; break;
      case 294: return 189; break;
      case 296: return 190; break;
      case 299: return 191; break;
      case 300: return 192; break;
      case 301: return 193; break;
      case 302: return 194; break;
      case 303: return 195; break;
      case 304: return 196; break;
      case 305: return 197; break;
      case 306: return 198; break;
      case 329: return 199; break;
      default:
        return -1;
    }
}
/* function maps initialUnknowns knownVars ValueReferences to an internal partial derivatives index */
fmi2ValueReference mapInitialUnknownsIndependentIndex(const fmi2ValueReference vr) {
    switch (vr) {
      case 0: return 0; break;
      case 1: return 1; break;
      case 4: return 2; break;
      case 5: return 3; break;
      case 7: return 4; break;
      case 67: return 5; break;
      default:
        return -1;
    }
}

#ifdef __cplusplus
}
#endif

