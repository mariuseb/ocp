#ifdef __cplusplus
extern "C" {
#endif

#define _OMC_LIT0_data "Pressure"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT0,8,_OMC_LIT0_data);
#define _OMC_LIT0 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT0)
#define _OMC_LIT1_data "Pa"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT1,2,_OMC_LIT1_data);
#define _OMC_LIT1 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT1)
#define _OMC_LIT2_data "bar"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT2,3,_OMC_LIT2_data);
#define _OMC_LIT2 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT2)
#define _OMC_LIT3_data "ThermodynamicTemperature"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT3,24,_OMC_LIT3_data);
#define _OMC_LIT3 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT3)
#define _OMC_LIT4_data "K"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT4,1,_OMC_LIT4_data);
#define _OMC_LIT4 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT4)
#define _OMC_LIT5_data "degC"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT5,4,_OMC_LIT5_data);
#define _OMC_LIT5 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT5)
static _index_t _OMC_LIT6_dims[1] = {1};
static const modelica_real _OMC_LIT6_data[] = {1.0};
static real_array const _OMC_LIT6 = {
  1, _OMC_LIT6_dims, (void*) _OMC_LIT6_data, (modelica_boolean) 0
};
#define _OMC_LIT7_data "MassFraction"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT7,12,_OMC_LIT7_data);
#define _OMC_LIT7 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT7)
#define _OMC_LIT8_data "kg/kg"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT8,5,_OMC_LIT8_data);
#define _OMC_LIT8 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT8)
#define _OMC_LIT9_data "SpecificEnergy"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT9,14,_OMC_LIT9_data);
#define _OMC_LIT9 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT9)
#define _OMC_LIT10_data "J/kg"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT10,4,_OMC_LIT10_data);
#define _OMC_LIT10 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT10)
#define _OMC_LIT11_data ""
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT11,0,_OMC_LIT11_data);
#define _OMC_LIT11 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT11)
#define _OMC_LIT12_data "MassFlowRate"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT12,12,_OMC_LIT12_data);
#define _OMC_LIT12 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT12)
#define _OMC_LIT13_data "kg/s"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT13,4,_OMC_LIT13_data);
#define _OMC_LIT13 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT13)
#define _OMC_LIT14_data "??? boundary ???"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT14,16,_OMC_LIT14_data);
#define _OMC_LIT14 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT14)
#define _OMC_LIT15_data "\nWrong value of parameter define_p (= false) in model \""
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT15,55,_OMC_LIT15_data);
#define _OMC_LIT15 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT15)
#define _OMC_LIT16_data "\":\nThe selected medium \""
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT16,24,_OMC_LIT16_data);
#define _OMC_LIT16 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT16)
#define _OMC_LIT17_data "\" has Medium.singleState=true.\nTherefore, an boundary density cannot be defined and\ndefine_p = true is required.\n"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT17,113,_OMC_LIT17_data);
#define _OMC_LIT17 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT17)
#define _OMC_LIT18_data "\nWrong boundary mass fractions in medium \""
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT18,42,_OMC_LIT18_data);
#define _OMC_LIT18 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT18)
#define _OMC_LIT19_data "\" in model \""
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT19,12,_OMC_LIT19_data);
#define _OMC_LIT19 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT19)
#define _OMC_LIT20_data "\":\nThe boundary value X_boundary("
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT20,33,_OMC_LIT20_data);
#define _OMC_LIT20 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT20)
#define _OMC_LIT21_data ") = "
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT21,4,_OMC_LIT21_data);
#define _OMC_LIT21 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT21)
#define _OMC_LIT22_data "\nis negative. It must be positive.\n"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT22,35,_OMC_LIT22_data);
#define _OMC_LIT22 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT22)
#define _OMC_LIT23_data "   X_boundary["
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT23,14,_OMC_LIT23_data);
#define _OMC_LIT23 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT23)
#define _OMC_LIT24_data "] = "
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT24,4,_OMC_LIT24_data);
#define _OMC_LIT24 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT24)
#define _OMC_LIT25_data " \""
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT25,2,_OMC_LIT25_data);
#define _OMC_LIT25 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT25)
#define _OMC_LIT26_data "\"\n"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT26,2,_OMC_LIT26_data);
#define _OMC_LIT26 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT26)
#define _OMC_LIT27_data "The boundary mass fractions in medium \""
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT27,39,_OMC_LIT27_data);
#define _OMC_LIT27 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT27)
#define _OMC_LIT28_data "do not sum up to 1. Instead, sum(X_boundary) = "
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT28,47,_OMC_LIT28_data);
#define _OMC_LIT28 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT28)
#define _OMC_LIT29_data ":\n"
static const MMC_DEFSTRINGLIT(_OMC_LIT_STRUCT29,2,_OMC_LIT29_data);
#define _OMC_LIT29 MMC_REFSTRINGLIT(_OMC_LIT_STRUCT29)

#ifdef __cplusplus
}
#endif
