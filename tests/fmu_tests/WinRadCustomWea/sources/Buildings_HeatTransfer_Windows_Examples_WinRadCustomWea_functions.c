#include "omc_simulation_settings.h"
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_includes.h"


DLLExport
modelica_real omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getAltitudeLocationTMY3(threadData_t *threadData, modelica_string _filNam)
{
  modelica_real _alt;
  modelica_integer _nexInd;
  modelica_string _element = NULL;
  _tailrecursive: OMC_LABEL_UNUSED
  // _alt has no default value.
  // _nexInd has no default value.
  // _element has no default value.
  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getAltitudeLocationTMY3.mo:13:3-17:25]*/
  _element = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLastHeaderElementTMY3(threadData, _filNam, _OMC_LIT2, _OMC_LIT3);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getAltitudeLocationTMY3.mo:18:4-21:20]*/
  _nexInd = omc_Modelica_Utilities_Strings_Advanced_scanReal(threadData, _element, ((modelica_integer) 1), 0 ,&_alt);
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _alt;
}
modelica_metatype boxptr_Buildings_BoundaryConditions_WeatherData_BaseClasses_getAltitudeLocationTMY3(threadData_t *threadData, modelica_metatype _filNam)
{
  modelica_real _alt;
  modelica_metatype out_alt;
  _alt = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getAltitudeLocationTMY3(threadData, _filNam);
  out_alt = mmc_mk_rcon(_alt);
  return out_alt;
}

DLLExport
modelica_string omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getHeaderElementTMY3(threadData_t *threadData, modelica_string _filNam, modelica_string _start, modelica_string _name, modelica_integer _position)
{
  modelica_string _element = NULL;
  modelica_string _lin = NULL;
  modelica_integer _iLin;
  modelica_integer _index;
  modelica_integer _staInd;
  modelica_integer _nexInd;
  modelica_boolean _found;
  modelica_boolean _EOF;
  modelica_string _fouDel = NULL;
  modelica_metatype tmpMeta1;
  modelica_metatype tmpMeta2;
  modelica_metatype tmpMeta3;
  static int tmp4 = 0;
  modelica_metatype tmpMeta5;
  modelica_metatype tmpMeta6;
  modelica_metatype tmpMeta7;
  modelica_metatype tmpMeta8;
  modelica_metatype tmpMeta9;
  modelica_metatype tmpMeta10;
  static int tmp11 = 0;
  modelica_integer tmp12;
  modelica_integer tmp13;
  modelica_integer tmp14;
  modelica_metatype tmpMeta15;
  modelica_metatype tmpMeta16;
  modelica_metatype tmpMeta17;
  modelica_metatype tmpMeta18;
  modelica_metatype tmpMeta19;
  modelica_metatype tmpMeta20;
  static int tmp21 = 0;
  _tailrecursive: OMC_LABEL_UNUSED
  // _element has no default value.
  // _lin has no default value.
  // _iLin has no default value.
  _index = ((modelica_integer) 0);
  // _staInd has no default value.
  // _nexInd has no default value.
  // _found has no default value.
  // _EOF has no default value.
  // _fouDel has no default value.
  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:26:3-26:11]*/
  _iLin = ((modelica_integer) 0);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:27:3-27:14]*/
  _EOF = 0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:28:3-37:12]*/
  while(1)
  {
    if(!((!_EOF) && (_index == ((modelica_integer) 0)))) break;
    /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:29:5-29:19]*/
    _iLin = _iLin + ((modelica_integer) 1);
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:30:5-31:23]*/
    _lin = omc_Modelica_Utilities_Streams_readLine(threadData, _filNam, _iLin ,&_EOF);
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:32:5-36:27]*/
    _index = omc_Modelica_Utilities_Strings_find(threadData, _lin, _start, ((modelica_integer) 1), 0);
    /*#endModelicaLine*/
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:38:3-39:71]*/
  {
    if(!(!_EOF))
    {
      tmpMeta1 = stringAppend(_OMC_LIT4,_start);
      tmpMeta2 = stringAppend(tmpMeta1,_OMC_LIT5);
      tmpMeta3 = stringAppend(tmpMeta2,_OMC_LIT6);
      {
        FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo",38,3,39,71,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta3));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:41:3-41:13]*/
  _nexInd = ((modelica_integer) 1);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:42:3-50:10]*/
  tmp12 = ((modelica_integer) 1); tmp13 = 1; tmp14 = _position - ((modelica_integer) 1);
  if(!(((tmp13 > 0) && (tmp12 > tmp14)) || ((tmp13 < 0) && (tmp12 < tmp14))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp12, tmp14); _i += tmp13)
    {
      /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:43:3-46:27]*/
      _nexInd = omc_Modelica_Utilities_Strings_find(threadData, _lin, _OMC_LIT7, _nexInd + ((modelica_integer) 1), 1);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:47:4-49:20]*/
      {
        if(!(_nexInd > ((modelica_integer) 0)))
        {
          tmpMeta5 = stringAppend(_OMC_LIT8,_name);
          tmpMeta6 = stringAppend(tmpMeta5,_OMC_LIT9);
          tmpMeta7 = stringAppend(tmpMeta6,_OMC_LIT10);
          tmpMeta8 = stringAppend(tmpMeta7,_OMC_LIT11);
          tmpMeta9 = stringAppend(tmpMeta8,_lin);
          tmpMeta10 = stringAppend(tmpMeta9,_OMC_LIT12);
          {
            FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo",47,4,49,20,0};
            omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta10));
          }
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:51:3-51:19]*/
  _staInd = _nexInd;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:53:3-56:27]*/
  _nexInd = omc_Modelica_Utilities_Strings_find(threadData, _lin, _OMC_LIT7, _nexInd + ((modelica_integer) 1), 1);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:57:3-59:21]*/
  {
    if(!(_nexInd > ((modelica_integer) 0)))
    {
      tmpMeta15 = stringAppend(_OMC_LIT8,_name);
      tmpMeta16 = stringAppend(tmpMeta15,_OMC_LIT9);
      tmpMeta17 = stringAppend(tmpMeta16,_OMC_LIT10);
      tmpMeta18 = stringAppend(tmpMeta17,_OMC_LIT11);
      tmpMeta19 = stringAppend(tmpMeta18,_lin);
      tmpMeta20 = stringAppend(tmpMeta19,_OMC_LIT12);
      {
        FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo",57,3,59,21,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta20));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getHeaderElementTMY3.mo:61:3-61:94]*/
  _element = omc_Modelica_Utilities_Strings_substring(threadData, _lin, _staInd + ((modelica_integer) 1), _nexInd - ((modelica_integer) 1));
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _element;
}
modelica_metatype boxptr_Buildings_BoundaryConditions_WeatherData_BaseClasses_getHeaderElementTMY3(threadData_t *threadData, modelica_metatype _filNam, modelica_metatype _start, modelica_metatype _name, modelica_metatype _position)
{
  modelica_integer tmp1;
  modelica_string _element = NULL;
  tmp1 = mmc_unbox_integer(_position);
  _element = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getHeaderElementTMY3(threadData, _filNam, _start, _name, tmp1);
  /* skip box _element; String */
  return _element;
}

DLLExport
modelica_string omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLastHeaderElementTMY3(threadData_t *threadData, modelica_string _filNam, modelica_string _start, modelica_string _name)
{
  modelica_string _element = NULL;
  modelica_string _lin = NULL;
  modelica_integer _iLin;
  modelica_integer _index;
  modelica_integer _staInd;
  modelica_integer _lasInd;
  modelica_boolean _EOF;
  modelica_metatype tmpMeta1;
  modelica_metatype tmpMeta2;
  modelica_metatype tmpMeta3;
  static int tmp4 = 0;
  _tailrecursive: OMC_LABEL_UNUSED
  // _element has no default value.
  // _lin has no default value.
  // _iLin has no default value.
  _index = ((modelica_integer) 0);
  // _staInd has no default value.
  // _lasInd has no default value.
  // _EOF has no default value.
  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:22:3-22:11]*/
  _iLin = ((modelica_integer) 0);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:23:3-23:14]*/
  _EOF = 0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:24:3-33:12]*/
  while(1)
  {
    if(!((!_EOF) && (_index == ((modelica_integer) 0)))) break;
    /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:25:5-25:19]*/
    _iLin = _iLin + ((modelica_integer) 1);
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:26:5-27:23]*/
    _lin = omc_Modelica_Utilities_Streams_readLine(threadData, _filNam, _iLin ,&_EOF);
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:28:5-32:27]*/
    _index = omc_Modelica_Utilities_Strings_find(threadData, _lin, _start, ((modelica_integer) 1), 0);
    /*#endModelicaLine*/
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:34:3-35:71]*/
  {
    if(!(!_EOF))
    {
      tmpMeta1 = stringAppend(_OMC_LIT4,_start);
      tmpMeta2 = stringAppend(tmpMeta1,_OMC_LIT5);
      tmpMeta3 = stringAppend(tmpMeta2,_OMC_LIT6);
      {
        FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo",34,3,35,71,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta3));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:37:5-40:22]*/
  _staInd = omc_Modelica_Utilities_Strings_findLast(threadData, _lin, _OMC_LIT7, ((modelica_integer) 0), 1);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:41:5-41:62]*/
  _lasInd = ((modelica_integer)floor(((modelica_real)omc_Modelica_Utilities_Strings_length(threadData, _lin))));
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLastHeaderElementTMY3.mo:43:3-43:92]*/
  _element = omc_Modelica_Utilities_Strings_substring(threadData, _lin, _staInd + ((modelica_integer) 1), _lasInd);
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _element;
}

DLLExport
modelica_real omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLatitudeTMY3(threadData_t *threadData, modelica_string _filNam)
{
  modelica_real _lat;
  modelica_integer _nexInd;
  modelica_string _element = NULL;
  modelica_metatype tmpMeta1;
  modelica_metatype tmpMeta2;
  static int tmp3 = 0;
  modelica_real tmp4;
  modelica_string tmp5;
  modelica_metatype tmpMeta6;
  modelica_metatype tmpMeta7;
  modelica_string tmp8;
  modelica_real tmp9;
  modelica_metatype tmpMeta10;
  modelica_metatype tmpMeta11;
  static int tmp12 = 0;
  _tailrecursive: OMC_LABEL_UNUSED
  // _lat has no default value.
  // _nexInd has no default value.
  // _element has no default value.
  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLatitudeTMY3.mo:13:3-18:18]*/
  _element = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getHeaderElementTMY3(threadData, _filNam, _OMC_LIT2, _OMC_LIT16, ((modelica_integer) 7));
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLatitudeTMY3.mo:19:4-22:20]*/
  _nexInd = omc_Modelica_Utilities_Strings_Advanced_scanReal(threadData, _element, ((modelica_integer) 1), 0 ,&_lat);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLatitudeTMY3.mo:23:4-24:62]*/
  {
    if(!(_nexInd > ((modelica_integer) 1)))
    {
      tmpMeta1 = stringAppend(_OMC_LIT17,_element);
      tmpMeta2 = stringAppend(tmpMeta1,_OMC_LIT18);
      {
        FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLatitudeTMY3.mo",23,4,24,62,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta2));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLatitudeTMY3.mo:26:4-26:39]*/
  tmp4 = 180.0;
  if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "lat * 3.141592653589793 / 180.0");}
  _lat = ((_lat) * (3.141592653589793)) / tmp4;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLatitudeTMY3.mo:28:4-30:84]*/
  {
    if(!(fabs(_lat) <= 3.141592653589793 + 1e-15))
    {
      tmp5 = modelica_real_to_modelica_string(_lat, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta6 = stringAppend(_OMC_LIT19,tmp5);
      tmpMeta7 = stringAppend(tmpMeta6,_OMC_LIT20);
      tmp9 = 3.141592653589793;
      if (tmp9 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "lat * 180.0 / 3.141592653589793");}
      tmp8 = modelica_real_to_modelica_string(((_lat) * (180.0)) / tmp9, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta10 = stringAppend(tmpMeta7,tmp8);
      tmpMeta11 = stringAppend(tmpMeta10,_OMC_LIT21);
      {
        FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLatitudeTMY3.mo",28,4,30,84,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta11));
      }
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _lat;
}
modelica_metatype boxptr_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLatitudeTMY3(threadData_t *threadData, modelica_metatype _filNam)
{
  modelica_real _lat;
  modelica_metatype out_lat;
  _lat = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLatitudeTMY3(threadData, _filNam);
  out_lat = mmc_mk_rcon(_lat);
  return out_lat;
}

DLLExport
modelica_real omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLongitudeTMY3(threadData_t *threadData, modelica_string _filNam)
{
  modelica_real _lon;
  modelica_integer _nexInd;
  modelica_string _element = NULL;
  modelica_metatype tmpMeta1;
  modelica_metatype tmpMeta2;
  static int tmp3 = 0;
  modelica_real tmp4;
  modelica_string tmp5;
  modelica_metatype tmpMeta6;
  modelica_metatype tmpMeta7;
  modelica_string tmp8;
  modelica_real tmp9;
  modelica_metatype tmpMeta10;
  modelica_metatype tmpMeta11;
  static int tmp12 = 0;
  _tailrecursive: OMC_LABEL_UNUSED
  // _lon has no default value.
  // _nexInd has no default value.
  // _element has no default value.
  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLongitudeTMY3.mo:13:3-18:18]*/
  _element = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getHeaderElementTMY3(threadData, _filNam, _OMC_LIT2, _OMC_LIT22, ((modelica_integer) 8));
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLongitudeTMY3.mo:19:4-22:20]*/
  _nexInd = omc_Modelica_Utilities_Strings_Advanced_scanReal(threadData, _element, ((modelica_integer) 1), 0 ,&_lon);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLongitudeTMY3.mo:23:4-24:62]*/
  {
    if(!(_nexInd > ((modelica_integer) 1)))
    {
      tmpMeta1 = stringAppend(_OMC_LIT23,_element);
      tmpMeta2 = stringAppend(tmpMeta1,_OMC_LIT18);
      {
        FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLongitudeTMY3.mo",23,4,24,62,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta2));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLongitudeTMY3.mo:26:4-26:39]*/
  tmp4 = 180.0;
  if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "lon * 3.141592653589793 / 180.0");}
  _lon = ((_lon) * (3.141592653589793)) / tmp4;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLongitudeTMY3.mo:28:4-30:84]*/
  {
    if(!(fabs(_lon) < (2.0) * (3.141592653589793)))
    {
      tmp5 = modelica_real_to_modelica_string(_lon, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta6 = stringAppend(_OMC_LIT24,tmp5);
      tmpMeta7 = stringAppend(tmpMeta6,_OMC_LIT20);
      tmp9 = 3.141592653589793;
      if (tmp9 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "lon * 180.0 / 3.141592653589793");}
      tmp8 = modelica_real_to_modelica_string(((_lon) * (180.0)) / tmp9, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta10 = stringAppend(tmpMeta7,tmp8);
      tmpMeta11 = stringAppend(tmpMeta10,_OMC_LIT21);
      {
        FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getLongitudeTMY3.mo",28,4,30,84,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta11));
      }
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _lon;
}
modelica_metatype boxptr_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLongitudeTMY3(threadData_t *threadData, modelica_metatype _filNam)
{
  modelica_real _lon;
  modelica_metatype out_lon;
  _lon = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLongitudeTMY3(threadData, _filNam);
  out_lon = mmc_mk_rcon(_lon);
  return out_lon;
}

real_array omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeSpanTMY3(threadData_t *threadData, modelica_string _filNam, modelica_string _tabNam)
{
  void *_timeSpan_c89;
  real_array _timeSpan;
  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getTimeSpanTMY3.mo:2:1-37:20]*/
  alloc_real_array(&(_timeSpan), 1, (_index_t)2); // _timeSpan has no default value.
  _timeSpan_c89 = (void*) data_of_real_c89_array(_timeSpan);
  getTimeSpan(MMC_STRINGDATA(_filNam), MMC_STRINGDATA(_tabNam), (double*) _timeSpan_c89);
  return _timeSpan;
}
modelica_metatype boxptr_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeSpanTMY3(threadData_t *threadData, modelica_metatype _filNam, modelica_metatype _tabNam)
{
  real_array _timeSpan;
  modelica_metatype out_timeSpan;
  _timeSpan = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeSpanTMY3(threadData, _filNam, _tabNam);
  out_timeSpan = mmc_mk_modelica_array(_timeSpan);
  return out_timeSpan;
}

DLLExport
modelica_real omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeZoneTMY3(threadData_t *threadData, modelica_string _filNam)
{
  modelica_real _timZon;
  modelica_integer _nexInd;
  modelica_string _element = NULL;
  modelica_metatype tmpMeta1;
  modelica_metatype tmpMeta2;
  static int tmp3 = 0;
  modelica_string tmp4;
  modelica_metatype tmpMeta5;
  modelica_metatype tmpMeta6;
  modelica_string tmp7;
  modelica_real tmp8;
  modelica_metatype tmpMeta9;
  modelica_metatype tmpMeta10;
  static int tmp11 = 0;
  _tailrecursive: OMC_LABEL_UNUSED
  // _timZon has no default value.
  // _nexInd has no default value.
  // _element has no default value.
  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getTimeZoneTMY3.mo:13:3-18:18]*/
  _element = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getHeaderElementTMY3(threadData, _filNam, _OMC_LIT2, _OMC_LIT22, ((modelica_integer) 9));
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getTimeZoneTMY3.mo:19:4-22:20]*/
  _nexInd = omc_Modelica_Utilities_Strings_Advanced_scanReal(threadData, _element, ((modelica_integer) 1), 0 ,&_timZon);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getTimeZoneTMY3.mo:23:4-24:62]*/
  {
    if(!(_nexInd > ((modelica_integer) 1)))
    {
      tmpMeta1 = stringAppend(_OMC_LIT29,_element);
      tmpMeta2 = stringAppend(tmpMeta1,_OMC_LIT18);
      {
        FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getTimeZoneTMY3.mo",23,4,24,62,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta2));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getTimeZoneTMY3.mo:25:4-25:24]*/
  _timZon = (_timZon) * (3600.0);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getTimeZoneTMY3.mo:27:4-29:67]*/
  {
    if(!(fabs(_timZon) < ((modelica_real)(((modelica_integer) 24)) * (((modelica_integer) 3600)))))
    {
      tmp4 = modelica_real_to_modelica_string(_timZon, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta5 = stringAppend(_OMC_LIT30,tmp4);
      tmpMeta6 = stringAppend(tmpMeta5,_OMC_LIT20);
      tmp8 = 3600.0;
      if (tmp8 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "timZon / 3600.0");}
      tmp7 = modelica_real_to_modelica_string((_timZon) / tmp8, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta9 = stringAppend(tmpMeta6,tmp7);
      tmpMeta10 = stringAppend(tmpMeta9,_OMC_LIT31);
      {
        FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/getTimeZoneTMY3.mo",27,4,29,67,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta10));
      }
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _timZon;
}
modelica_metatype boxptr_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeZoneTMY3(threadData_t *threadData, modelica_metatype _filNam)
{
  modelica_real _timZon;
  modelica_metatype out_timZon;
  _timZon = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeZoneTMY3(threadData, _filNam);
  out_timZon = mmc_mk_rcon(_timZon);
  return out_timZon;
}

DLLExport
modelica_real omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData_t *threadData, real_array _y, modelica_real _x)
{
  modelica_real _val;
  modelica_integer _k1;
  modelica_integer _k2;
  modelica_real _y1d;
  modelica_real _y2d;
  modelica_real tmp1;
  modelica_real tmp2;
  _tailrecursive: OMC_LABEL_UNUSED
  // _val has no default value.
  // _k1 has no default value.
  // _k2 has no default value.
  // _y1d has no default value.
  // _y2d has no default value.
  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/smoothInterpolation.mo:15:3-15:19]*/
  _k1 = ((modelica_integer)floor(_x));
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/smoothInterpolation.mo:16:3-16:15]*/
  _k2 = _k1 + ((modelica_integer) 1);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/smoothInterpolation.mo:18:3-18:31]*/
  tmp1 = 2.0;
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(y[k2] - y[k1 - 1]) / 2.0");}
  _y1d = (real_array_get(_y, 1, _k2) - real_array_get(_y, 1, _k1 - ((modelica_integer) 1))) / tmp1;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/smoothInterpolation.mo:19:3-19:31]*/
  tmp2 = 2.0;
  if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(y[k2 + 1] - y[k1]) / 2.0");}
  _y2d = (real_array_get(_y, 1, _k2 + ((modelica_integer) 1)) - real_array_get(_y, 1, _k1)) / tmp2;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/smoothInterpolation.mo:20:3-27:9]*/
  _val = omc_Modelica_Fluid_Utilities_cubicHermite(threadData, _x, ((modelica_real)_k1), ((modelica_real)_k2), real_array_get(_y, 1, _k1), real_array_get(_y, 1, _k2), _y1d, _y2d);
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _val;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData_t *threadData, modelica_metatype _y, modelica_metatype _x)
{
  modelica_real tmp1;
  modelica_real _val;
  modelica_metatype out_val;
  tmp1 = mmc_unbox_real(_x);
  _val = omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, *((base_array_t*)_y), tmp1);
  out_val = mmc_mk_rcon(_val);
  return out_val;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  double _uMax_ext;
  modelica_real _uMax;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo:1164:5-1171:31]*/
  // _uMax has no default value.
  _tableID_ext = (void *)_tableID;
  _uMax_ext = ModelicaStandardTables_CombiTable1D_maximumAbscissa(_tableID_ext);
  _uMax = (modelica_real)_uMax_ext;
  return _uMax;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData_t *threadData, modelica_metatype _tableID)
{
  modelica_real _uMax;
  modelica_metatype out_uMax;
  _uMax = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData, _tableID);
  out_uMax = mmc_mk_rcon(_uMax);
  return out_uMax;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  double _uMin_ext;
  modelica_real _uMin;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo:1155:5-1162:31]*/
  // _uMin has no default value.
  _tableID_ext = (void *)_tableID;
  _uMin_ext = ModelicaStandardTables_CombiTable1D_minimumAbscissa(_tableID_ext);
  _uMin = (modelica_real)_uMin_ext;
  return _uMin;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData_t *threadData, modelica_metatype _tableID)
{
  modelica_real _uMin;
  modelica_metatype out_uMin;
  _uMin = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData, _tableID);
  out_uMin = mmc_mk_rcon(_uMin);
  return out_uMin;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData_t *threadData, modelica_complex _tableID, modelica_integer _icol, modelica_real _u)
{
  void * _tableID_ext;
  int _icol_ext;
  double _u_ext;
  double _y_ext;
  modelica_real _y;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo:1083:5-1092:24]*/
  // _y has no default value.
  _tableID_ext = (void *)_tableID;
  _icol_ext = (int)_icol;
  _u_ext = (double)_u;
  _y_ext = ModelicaStandardTables_CombiTable1D_getValue(_tableID_ext, _icol_ext, _u_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _icol, modelica_metatype _u)
{
  modelica_integer tmp1;
  modelica_real tmp2;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_integer(_icol);
  tmp2 = mmc_unbox_real(_u);
  _y = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, _tableID, tmp1, tmp2);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

modelica_complex omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData_t *threadData, modelica_string _tableName, modelica_string _fileName, real_array _table, integer_array _columns, modelica_integer _smoothness, modelica_integer _extrapolation, modelica_boolean _verboseRead)
{
  integer_array _columns_packed;
  int _smoothness_ext;
  int _extrapolation_ext;
  int _verboseRead_ext;
  void *_table_c89;
  void *_columns_c89;
  void * _externalCombiTable1D_ext;
  modelica_complex _externalCombiTable1D;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Types.mo:147:5-168:20]*/
  // _externalCombiTable1D has no default value.
  pack_alloc_integer_array(&_columns, &_columns_packed);

  _smoothness_ext = (int)_smoothness;
  _extrapolation_ext = (int)_extrapolation;
  _verboseRead_ext = (int)_verboseRead;_table_c89 = (void*) data_of_real_c89_array(_table);
  _columns_c89 = (void*) data_of_integer_c89_array(_columns_packed);
  _externalCombiTable1D_ext = ModelicaStandardTables_CombiTable1D_init2(MMC_STRINGDATA(_fileName), MMC_STRINGDATA(_tableName), (const double*) _table_c89, size_of_dimension_base_array(_table, ((modelica_integer) 1)), size_of_dimension_base_array(_table, ((modelica_integer) 2)), (const int*) _columns_c89, size_of_dimension_base_array(_columns, ((modelica_integer) 1)), _smoothness_ext, _extrapolation_ext, _verboseRead_ext);
  _externalCombiTable1D = (modelica_complex)_externalCombiTable1D_ext;
  return _externalCombiTable1D;
}
modelica_metatype boxptr_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData_t *threadData, modelica_metatype _tableName, modelica_metatype _fileName, modelica_metatype _table, modelica_metatype _columns, modelica_metatype _smoothness, modelica_metatype _extrapolation, modelica_metatype _verboseRead)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_complex _externalCombiTable1D;
  tmp1 = mmc_unbox_integer(_smoothness);
  tmp2 = mmc_unbox_integer(_extrapolation);
  tmp3 = mmc_unbox_integer(_verboseRead);
  _externalCombiTable1D = omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData, _tableName, _fileName, *((base_array_t*)_table), *((base_array_t*)_columns), tmp1, tmp2, tmp3);
  /* skip box _externalCombiTable1D; ExternalObject Modelica.Blocks.Types.ExternalCombiTable1D */
  return _externalCombiTable1D;
}

void omc_Modelica_Blocks_Types_ExternalCombiTable1D_destructor(threadData_t *threadData, modelica_complex _externalCombiTable1D)
{
  void * _externalCombiTable1D_ext;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Types.mo:170:5-175:19]*/
  _externalCombiTable1D_ext = (void *)_externalCombiTable1D;
  ModelicaStandardTables_CombiTable1D_close(_externalCombiTable1D_ext);
  return;
}
void boxptr_Modelica_Blocks_Types_ExternalCombiTable1D_destructor(threadData_t *threadData, modelica_metatype _externalCombiTable1D)
{
  omc_Modelica_Blocks_Types_ExternalCombiTable1D_destructor(threadData, _externalCombiTable1D);
  return;
}

DLLExport
modelica_real omc_Modelica_Fluid_Utilities_cubicHermite(threadData_t *threadData, modelica_real _x, modelica_real _x1, modelica_real _x2, modelica_real _y1, modelica_real _y2, modelica_real _y1d, modelica_real _y2d)
{
  modelica_real _y;
  modelica_real _h;
  modelica_real _t;
  modelica_real _h00;
  modelica_real _h10;
  modelica_real _h01;
  modelica_real _h11;
  modelica_real _aux3;
  modelica_real _aux2;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  _tailrecursive: OMC_LABEL_UNUSED
  // _y has no default value.
  // _h has no default value.
  // _t has no default value.
  // _h00 has no default value.
  // _h10 has no default value.
  // _h01 has no default value.
  // _h11 has no default value.
  // _aux3 has no default value.
  // _aux2 has no default value.
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:807:5-807:17]*/
  _h = _x2 - _x1;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:808:5-823:11]*/
  if((fabs(_h) > 0.0))
  {
    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:810:7-810:22]*/
    tmp1 = _h;
    if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(x - x1) / h");}
    _t = (_x - _x1) / tmp1;
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:812:7-812:17]*/
    tmp2 = _t;
    _aux3 = (tmp2 * tmp2 * tmp2);
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:813:7-813:17]*/
    tmp3 = _t;
    _aux2 = (tmp3 * tmp3);
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:815:7-815:33]*/
    _h00 = (2.0) * (_aux3) - ((3.0) * (_aux2)) + 1.0;
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:816:7-816:31]*/
    _h10 = _aux3 - ((2.0) * (_aux2)) + _t;
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:817:7-817:30]*/
    _h01 = (-((2.0) * (_aux3))) + (3.0) * (_aux2);
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:818:7-818:25]*/
    _h11 = _aux3 - _aux2;
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:819:7-819:51]*/
    _y = (_y1) * (_h00) + ((_h) * (_y1d)) * (_h10) + (_y2) * (_h01) + ((_h) * (_y2d)) * (_h11);
    /*#endModelicaLine*/
  }
  else
  {
    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Utilities.mo:822:7-822:23]*/
    tmp4 = 2.0;
    if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(y1 + y2) / 2.0");}
    _y = (_y1 + _y2) / tmp4;
    /*#endModelicaLine*/
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_Modelica_Fluid_Utilities_cubicHermite(threadData_t *threadData, modelica_metatype _x, modelica_metatype _x1, modelica_metatype _x2, modelica_metatype _y1, modelica_metatype _y2, modelica_metatype _y1d, modelica_metatype _y2d)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_x);
  tmp2 = mmc_unbox_real(_x1);
  tmp3 = mmc_unbox_real(_x2);
  tmp4 = mmc_unbox_real(_y1);
  tmp5 = mmc_unbox_real(_y2);
  tmp6 = mmc_unbox_real(_y1d);
  tmp7 = mmc_unbox_real(_y2d);
  _y = omc_Modelica_Fluid_Utilities_cubicHermite(threadData, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

modelica_string omc_Modelica_Utilities_Streams_readLine(threadData_t *threadData, modelica_string _fileName, modelica_integer _lineNumber, modelica_boolean *out_endOfFile)
{
  int _lineNumber_ext;
  int _endOfFile_ext;
  const char* _string_ext;
  modelica_string _string = NULL;
  modelica_boolean _endOfFile;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Streams.mo:68:3-96:15]*/
  // _string has no default value.
  // _endOfFile has no default value.
  _lineNumber_ext = (int)_lineNumber;
  _string_ext = ModelicaInternal_readLine(MMC_STRINGDATA(_fileName), _lineNumber_ext, &_endOfFile_ext);
  _endOfFile = (modelica_boolean)_endOfFile_ext;
  _string = (modelica_string)mmc_mk_scon(_string_ext);
  if (out_endOfFile) { *out_endOfFile = _endOfFile; }
  return _string;
}
modelica_metatype boxptr_Modelica_Utilities_Streams_readLine(threadData_t *threadData, modelica_metatype _fileName, modelica_metatype _lineNumber, modelica_metatype *out_endOfFile)
{
  modelica_integer tmp1;
  modelica_boolean _endOfFile;
  modelica_string _string = NULL;
  tmp1 = mmc_unbox_integer(_lineNumber);
  _string = omc_Modelica_Utilities_Streams_readLine(threadData, _fileName, tmp1, &_endOfFile);
  /* skip box _string; String */
  if (out_endOfFile) { *out_endOfFile = mmc_mk_icon(_endOfFile); }
  return _string;
}

modelica_integer omc_Modelica_Utilities_Strings_compare(threadData_t *threadData, modelica_string _string1, modelica_string _string2, modelica_boolean _caseSensitive)
{
  int _caseSensitive_ext;
  int _result_ext;
  modelica_integer _result;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:82:3-111:14]*/
  // _result has no default value.
  _caseSensitive_ext = (int)_caseSensitive;
  _result_ext = ModelicaStrings_compare(MMC_STRINGDATA(_string1), MMC_STRINGDATA(_string2), _caseSensitive_ext);
  _result = (modelica_integer)_result_ext;
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_compare(threadData_t *threadData, modelica_metatype _string1, modelica_metatype _string2, modelica_metatype _caseSensitive)
{
  modelica_integer tmp1;
  modelica_integer _result;
  modelica_metatype out_result;
  tmp1 = mmc_unbox_integer(_caseSensitive);
  _result = omc_Modelica_Utilities_Strings_compare(threadData, _string1, _string2, tmp1);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

DLLExport
modelica_integer omc_Modelica_Utilities_Strings_find(threadData_t *threadData, modelica_string _string, modelica_string _searchString, modelica_integer _startIndex, modelica_boolean _caseSensitive)
{
  modelica_integer _index;
  modelica_integer _lengthSearchString;
  modelica_integer _i;
  modelica_integer _len;
  modelica_integer _i_max;
  _tailrecursive: OMC_LABEL_UNUSED
  // _index has no default value.
  _lengthSearchString = omc_Modelica_Utilities_Strings_length(threadData, _searchString);
  _i = _startIndex;
  _len = _lengthSearchString - ((modelica_integer) 1);
  _i_max = omc_Modelica_Utilities_Strings_length(threadData, _string) - _lengthSearchString + ((modelica_integer) 1);
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:229:5-229:15]*/
  _index = ((modelica_integer) 0);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:230:5-238:14]*/
  while(1)
  {
    if(!(_i <= _i_max)) break;
    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:231:8-237:14]*/
    if(omc_Modelica_Utilities_Strings_isEqual(threadData, omc_Modelica_Utilities_Strings_substring(threadData, _string, _i, _i + _len), _searchString, _caseSensitive))
    {
      /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:233:11-233:21]*/
      _index = _i;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:234:11-234:25]*/
      _i = _i_max + ((modelica_integer) 1);
      /*#endModelicaLine*/
    }
    else
    {
      /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:236:11-236:19]*/
      _i = _i + ((modelica_integer) 1);
      /*#endModelicaLine*/
    }
    /*#endModelicaLine*/
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _index;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_find(threadData_t *threadData, modelica_metatype _string, modelica_metatype _searchString, modelica_metatype _startIndex, modelica_metatype _caseSensitive)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer _index;
  modelica_metatype out_index;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_caseSensitive);
  _index = omc_Modelica_Utilities_Strings_find(threadData, _string, _searchString, tmp1, tmp2);
  out_index = mmc_mk_icon(_index);
  return out_index;
}

DLLExport
modelica_integer omc_Modelica_Utilities_Strings_findLast(threadData_t *threadData, modelica_string _string, modelica_string _searchString, modelica_integer _startIndex, modelica_boolean _caseSensitive)
{
  modelica_integer _index;
  modelica_integer _lenString;
  modelica_integer _lenSearchString;
  modelica_integer _i;
  modelica_integer _iMax;
  _tailrecursive: OMC_LABEL_UNUSED
  // _index has no default value.
  _lenString = omc_Modelica_Utilities_Strings_length(threadData, _string);
  _lenSearchString = omc_Modelica_Utilities_Strings_length(threadData, _searchString);
  // _i has no default value.
  _iMax = _lenString - _lenSearchString + ((modelica_integer) 1);
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:275:5-275:75]*/
  _i = (((_startIndex == ((modelica_integer) 0)) || (_startIndex > _iMax))?_iMax:_startIndex);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:276:5-276:15]*/
  _index = ((modelica_integer) 0);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:277:5-285:14]*/
  while(1)
  {
    if(!(_i >= ((modelica_integer) 1))) break;
    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:278:8-284:14]*/
    if(omc_Modelica_Utilities_Strings_isEqual(threadData, omc_Modelica_Utilities_Strings_substring(threadData, _string, _i, _i + _lenSearchString - ((modelica_integer) 1)), _searchString, _caseSensitive))
    {
      /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:280:11-280:21]*/
      _index = _i;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:281:11-281:17]*/
      _i = ((modelica_integer) 0);
      /*#endModelicaLine*/
    }
    else
    {
      /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:283:11-283:19]*/
      _i = _i - ((modelica_integer) 1);
      /*#endModelicaLine*/
    }
    /*#endModelicaLine*/
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _index;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_findLast(threadData_t *threadData, modelica_metatype _string, modelica_metatype _searchString, modelica_metatype _startIndex, modelica_metatype _caseSensitive)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer _index;
  modelica_metatype out_index;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_caseSensitive);
  _index = omc_Modelica_Utilities_Strings_findLast(threadData, _string, _searchString, tmp1, tmp2);
  out_index = mmc_mk_icon(_index);
  return out_index;
}

DLLExport
modelica_boolean omc_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_string _string)
{
  modelica_boolean _result;
  modelica_integer _nextIndex;
  modelica_integer _len;
  _tailrecursive: OMC_LABEL_UNUSED
  // _result has no default value.
  // _nextIndex has no default value.
  // _len has no default value.
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:146:5-146:57]*/
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, ((modelica_integer) 1));
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:147:5-147:34]*/
  _len = omc_Modelica_Utilities_Strings_length(threadData, _string);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:148:5-152:11]*/
  if(((_len < ((modelica_integer) 1)) || (_nextIndex > _len)))
  {
    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:149:7-149:21]*/
    _result = 1;
    /*#endModelicaLine*/
  }
  else
  {
    /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:151:7-151:22]*/
    _result = 0;
    /*#endModelicaLine*/
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_metatype _string)
{
  modelica_boolean _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Utilities_Strings_isEmpty(threadData, _string);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

DLLExport
modelica_boolean omc_Modelica_Utilities_Strings_isEqual(threadData_t *threadData, modelica_string _string1, modelica_string _string2, modelica_boolean _caseSensitive)
{
  modelica_boolean _identical;
  _tailrecursive: OMC_LABEL_UNUSED
  // _identical has no default value.
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:121:5-121:80]*/
  _identical = (omc_Modelica_Utilities_Strings_compare(threadData, _string1, _string2, _caseSensitive) == 2);
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _identical;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_isEqual(threadData_t *threadData, modelica_metatype _string1, modelica_metatype _string2, modelica_metatype _caseSensitive)
{
  modelica_integer tmp1;
  modelica_boolean _identical;
  modelica_metatype out_identical;
  tmp1 = mmc_unbox_integer(_caseSensitive);
  _identical = omc_Modelica_Utilities_Strings_isEqual(threadData, _string1, _string2, tmp1);
  out_identical = mmc_mk_icon(_identical);
  return out_identical;
}

modelica_integer omc_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_string _string)
{
  int _result_ext;
  modelica_integer _result;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:5:3-20:13]*/
  // _result has no default value.
  _result_ext = ModelicaStrings_length(MMC_STRINGDATA(_string));
  _result = (modelica_integer)_result_ext;
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_metatype _string)
{
  modelica_integer _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Utilities_Strings_length(threadData, _string);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

modelica_string omc_Modelica_Utilities_Strings_substring(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex, modelica_integer _endIndex)
{
  int _startIndex_ext;
  int _endIndex_ext;
  const char* _result_ext;
  modelica_string _result = NULL;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:22:3-52:16]*/
  // _result has no default value.
  _startIndex_ext = (int)_startIndex;
  _endIndex_ext = (int)_endIndex;
  _result_ext = ModelicaStrings_substring(MMC_STRINGDATA(_string), _startIndex_ext, _endIndex_ext);
  _result = (modelica_string)mmc_mk_scon(_result_ext);
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_substring(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex, modelica_metatype _endIndex)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_string _result = NULL;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_endIndex);
  _result = omc_Modelica_Utilities_Strings_substring(threadData, _string, tmp1, tmp2);
  /* skip box _result; String */
  return _result;
}

modelica_integer omc_Modelica_Utilities_Strings_Advanced_scanReal(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex, modelica_boolean _unsigned, modelica_real *out_number)
{
  int _startIndex_ext;
  int _unsigned_ext;
  int _nextIndex_ext;
  double _number_ext;
  modelica_integer _nextIndex;
  modelica_real _number;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:1024:5-1069:17]*/
  // _nextIndex has no default value.
  // _number has no default value.
  _startIndex_ext = (int)_startIndex;
  _unsigned_ext = (int)_unsigned;
  ModelicaStrings_scanReal(MMC_STRINGDATA(_string), _startIndex_ext, _unsigned_ext, &_nextIndex_ext, &_number_ext);
  _nextIndex = (modelica_integer)_nextIndex_ext;
  _number = (modelica_real)_number_ext;
  if (out_number) { *out_number = _number; }
  return _nextIndex;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_Advanced_scanReal(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex, modelica_metatype _unsigned, modelica_metatype *out_number)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_real _number;
  modelica_integer _nextIndex;
  modelica_metatype out_nextIndex;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_unsigned);
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_scanReal(threadData, _string, tmp1, tmp2, &_number);
  out_nextIndex = mmc_mk_icon(_nextIndex);
  if (out_number) { *out_number = mmc_mk_rcon(_number); }
  return out_nextIndex;
}

modelica_integer omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex)
{
  int _startIndex_ext;
  int _nextIndex_ext;
  modelica_integer _nextIndex;
  /*#modelicaLine [/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Utilities/Strings.mo:1187:5-1207:23]*/
  // _nextIndex has no default value.
  _startIndex_ext = (int)_startIndex;
  _nextIndex_ext = ModelicaStrings_skipWhiteSpace(MMC_STRINGDATA(_string), _startIndex_ext);
  _nextIndex = (modelica_integer)_nextIndex_ext;
  return _nextIndex;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex)
{
  modelica_integer tmp1;
  modelica_integer _nextIndex;
  modelica_metatype out_nextIndex;
  tmp1 = mmc_unbox_integer(_startIndex);
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, tmp1);
  out_nextIndex = mmc_mk_icon(_nextIndex);
  return out_nextIndex;
}

#ifdef __cplusplus
}
#endif
