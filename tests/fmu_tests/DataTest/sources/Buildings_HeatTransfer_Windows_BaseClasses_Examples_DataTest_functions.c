#include "omc_simulation_settings.h"
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_includes.h"


DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData_t *threadData, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _absExtIrrIntShaDev;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_absExtIrrIntShaDev), 2, (_index_t)_HEM, (_index_t)_NSta); // _absExtIrrIntShaDev has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/devAbsExteriorIrradiationInteriorShading.mo:11:3-17:10]*/
  tmp5 = ((modelica_integer) 1); tmp6 = 1; tmp7 = _NSta;
  if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp5, tmp7); _iSta += tmp6)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/devAbsExteriorIrradiationInteriorShading.mo:12:5-16:12]*/
      tmp2 = ((modelica_integer) 1); tmp3 = 1; tmp4 = _HEM;
      if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
      {
        modelica_integer _iD;
        for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp2, tmp4); _iD += tmp3)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/devAbsExteriorIrradiationInteriorShading.mo:13:7-15:28]*/
          tmp1 = 1.0 - ((_refIntShaDev) * (real_array_get(_traRef, 5, _Rb, _N, ((modelica_integer) 1), _HEM, _iSta)));
          if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[TRA,1,N,iD,iSta] * (1.0 - traIntShaDev - refIntShaDev) / (1.0 - refIntShaDev * traRef[Rb,N,1,HEM,iSta])");}
          real_array_get(_absExtIrrIntShaDev, 2, _iD, _iSta) = ((real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _N, _iD, _iSta)) * (1.0 - _traIntShaDev - _refIntShaDev)) / tmp1;
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _absExtIrrIntShaDev;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData_t *threadData, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _absExtIrrIntShaDev;
  modelica_metatype out_absExtIrrIntShaDev;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _absExtIrrIntShaDev = omc_Buildings_HeatTransfer_Windows_Functions_devAbsExteriorIrradiationInteriorShading(threadData, *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_absExtIrrIntShaDev = mmc_mk_modelica_array(_absExtIrrIntShaDev);
  return out_absExtIrrIntShaDev;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_devAbsInteriorIrradiationInteriorShading(threadData_t *threadData, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _absIntIrrIntShaDev;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real _rRho;
  modelica_real _rTau;
  modelica_real _c;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_absIntIrrIntShaDev), 1, (_index_t)_NSta); // _absIntIrrIntShaDev has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  // _rRho has no default value.
  // _rTau has no default value.
  // _c has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/devAbsInteriorIrradiationInteriorShading.mo:15:3-22:10]*/
  tmp3 = ((modelica_integer) 1); tmp4 = 1; tmp5 = _NSta;
  if(!(((tmp4 > 0) && (tmp3 > tmp5)) || ((tmp4 < 0) && (tmp3 < tmp5))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp3, tmp5); _iSta += tmp4)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/devAbsInteriorIrradiationInteriorShading.mo:16:5-16:79]*/
      _rRho = (real_array_get(_traRef, 5, ((modelica_integer) 3), _N, ((modelica_integer) 1), _HEM, _iSta)) * (_refIntShaDev);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/devAbsInteriorIrradiationInteriorShading.mo:17:5-17:79]*/
      _rTau = (real_array_get(_traRef, 5, ((modelica_integer) 3), _N, ((modelica_integer) 1), _HEM, _iSta)) * (_traIntShaDev);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/devAbsInteriorIrradiationInteriorShading.mo:18:5-18:60]*/
      tmp1 = 1.0 - _rRho;
      if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "rRho / (1.0 - rRho)");}
      _c = (_traIntShaDev) * (1.0 - ((_rRho) / tmp1));
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/devAbsInteriorIrradiationInteriorShading.mo:20:5-21:25]*/
      tmp2 = 1.0 - _rRho;
      if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "rTau / (1.0 - rRho)");}
      real_array_get(_absIntIrrIntShaDev, 1, _iSta) = (1.0 - _traIntShaDev - _refIntShaDev) * (1.0 + (_rTau) / tmp2);
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _absIntIrrIntShaDev;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_devAbsInteriorIrradiationInteriorShading(threadData_t *threadData, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _absIntIrrIntShaDev;
  modelica_metatype out_absIntIrrIntShaDev;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _absIntIrrIntShaDev = omc_Buildings_HeatTransfer_Windows_Functions_devAbsInteriorIrradiationInteriorShading(threadData, *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_absIntIrrIntShaDev = mmc_mk_modelica_array(_absIntIrrIntShaDev);
  return out_absIntIrrIntShaDev;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData_t *threadData, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM, real_array _layer)
{
  real_array _traRef;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  real_array _traRefIntIrr;
  real_array tmp1;
  integer_array tmp2;
  modelica_integer tmp3;
  index_spec_t tmp4;
  integer_array tmp5;
  modelica_integer tmp6;
  index_spec_t tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
  modelica_integer tmp10;
  modelica_integer tmp11;
  modelica_integer tmp12;
  modelica_integer tmp13;
  modelica_integer tmp14;
  modelica_integer tmp15;
  modelica_integer tmp16;
  modelica_integer tmp17;
  modelica_integer tmp18;
  modelica_integer tmp19;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_traRef), 5, (_index_t)3, (_index_t)_N, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _traRef has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  alloc_real_array(&(_traRefIntIrr), 5, (_index_t)3, (_index_t)_N, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _traRefIntIrr has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/getGlassTR.mo:15:3-20:55]*/
  real_array_copy_data(omc_Buildings_HeatTransfer_Windows_Functions_glassTRExteriorIrradiationNoShading(threadData, _N, _NSta, _HEM, _layer), _traRef);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/getGlassTR.mo:21:3-26:55]*/
  real_array_copy_data(omc_Buildings_HeatTransfer_Windows_Functions_glassTRInteriorIrradiationNoShading(threadData, _N, _NSta, _HEM, _layer), _traRefIntIrr);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/getGlassTR.mo:29:3-38:10]*/
  tmp17 = _TRA; tmp18 = 1; tmp19 = _Rb;
  if(!(((tmp18 > 0) && (tmp17 > tmp19)) || ((tmp18 < 0) && (tmp17 < tmp19))))
  {
    modelica_integer _k;
    for(_k = _TRA; in_range_integer(_k, tmp17, tmp19); _k += tmp18)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/getGlassTR.mo:30:5-37:12]*/
      tmp14 = ((modelica_integer) 1); tmp15 = 1; tmp16 = _N - ((modelica_integer) 1);
      if(!(((tmp15 > 0) && (tmp14 > tmp16)) || ((tmp15 < 0) && (tmp14 < tmp16))))
      {
        modelica_integer _i;
        for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp14, tmp16); _i += tmp15)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/getGlassTR.mo:31:7-36:14]*/
          tmp11 = _i + ((modelica_integer) 1); tmp12 = 1; tmp13 = _N;
          if(!(((tmp12 > 0) && (tmp11 > tmp13)) || ((tmp12 < 0) && (tmp11 < tmp13))))
          {
            modelica_integer _j;
            for(_j = _i + ((modelica_integer) 1); in_range_integer(_j, tmp11, tmp13); _j += tmp12)
            {
              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/getGlassTR.mo:32:9-35:16]*/
              tmp8 = ((modelica_integer) 1); tmp9 = 1; tmp10 = _HEM;
              if(!(((tmp9 > 0) && (tmp8 > tmp10)) || ((tmp9 < 0) && (tmp8 < tmp10))))
              {
                modelica_integer _iD;
                for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp8, tmp10); _iD += tmp9)
                {
                  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/getGlassTR.mo:33:11-34:62]*/
                  create_integer_array_from_range(&tmp2, ((modelica_integer) 1), 1, _NSta);
                  tmp3 = size_of_dimension_base_array(tmp2, 1);
                  create_index_spec(&tmp4, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp3, integer_array_make_index_array(tmp2), 'A');
                  index_alloc_real_array(&_traRefIntIrr, &tmp4, &tmp1);
                  create_integer_array_from_range(&tmp5, ((modelica_integer) 1), 1, _NSta);
                  tmp6 = size_of_dimension_base_array(tmp5, 1);
                  create_index_spec(&tmp7, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp6, integer_array_make_index_array(tmp5), 'A');
                  indexed_assign_real_array(tmp1, &_traRef, &tmp7);
                  /*#endModelicaLine*/
                }
              }
              /*#endModelicaLine*/
            }
          }
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _traRef;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData_t *threadData, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM, modelica_metatype _layer)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _traRef;
  modelica_metatype out_traRef;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _traRef = omc_Buildings_HeatTransfer_Windows_Functions_getGlassTR(threadData, tmp1, tmp2, tmp3, *((base_array_t*)_layer));
  out_traRef = mmc_mk_modelica_array(_traRef);
  return out_traRef;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData_t *threadData, real_array _absExtIrrNoSha, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _absExtIrrExtSha;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real _c;
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
  modelica_integer tmp10;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_absExtIrrExtSha), 3, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _absExtIrrExtSha has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  // _c has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationExteriorShading.mo:16:3-24:10]*/
  tmp8 = ((modelica_integer) 1); tmp9 = 1; tmp10 = _NSta;
  if(!(((tmp9 > 0) && (tmp8 > tmp10)) || ((tmp9 < 0) && (tmp8 < tmp10))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp8, tmp10); _iSta += tmp9)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationExteriorShading.mo:17:5-23:12]*/
      tmp5 = ((modelica_integer) 1); tmp6 = 1; tmp7 = _HEM;
      if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
      {
        modelica_integer _iD;
        for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp5, tmp7); _iD += tmp6)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationExteriorShading.mo:18:7-19:56]*/
          tmp1 = 1.0 - ((real_array_get(_traRef, 5, _Ra, ((modelica_integer) 1), _N, _HEM, _iSta)) * (_refExtShaDev));
          if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[Ra,1,N,iD,iSta] * refExtShaDev / (1.0 - traRef[Ra,1,N,HEM,iSta] * refExtShaDev)");}
          _c = (_traExtShaDev) * (1.0 + ((real_array_get(_traRef, 5, _Ra, ((modelica_integer) 1), _N, _iD, _iSta)) * (_refExtShaDev)) / tmp1);
          /*#endModelicaLine*/

          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationExteriorShading.mo:20:7-22:15]*/
          tmp2 = ((modelica_integer) 1); tmp3 = 1; tmp4 = _N;
          if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
          {
            modelica_integer _i;
            for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp2, tmp4); _i += tmp3)
            {
              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationExteriorShading.mo:21:9-21:70]*/
              real_array_get(_absExtIrrExtSha, 3, _i, _iD, _iSta) = (_c) * (real_array_get(_absExtIrrNoSha, 3, _i, _iD, _iSta));
              /*#endModelicaLine*/
            }
          }
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _absExtIrrExtSha;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData_t *threadData, modelica_metatype _absExtIrrNoSha, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _absExtIrrExtSha;
  modelica_metatype out_absExtIrrExtSha;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _absExtIrrExtSha = omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationExteriorShading(threadData, *((base_array_t*)_absExtIrrNoSha), *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_absExtIrrExtSha = mmc_mk_modelica_array(_absExtIrrExtSha);
  return out_absExtIrrExtSha;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData_t *threadData, real_array _absExtIrrNoSha, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _absExtIrrNoShaIntSha;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real _fac;
  modelica_real _absFro;
  modelica_real _absBac;
  modelica_integer _i;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_real tmp6;
  modelica_integer tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
  modelica_integer tmp10;
  modelica_integer tmp11;
  modelica_integer tmp12;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_absExtIrrNoShaIntSha), 3, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _absExtIrrNoShaIntSha has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  // _fac has no default value.
  // _absFro has no default value.
  // _absBac has no default value.
  // _i has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:18:3-58:10]*/
  tmp10 = ((modelica_integer) 1); tmp11 = 1; tmp12 = _NSta;
  if(!(((tmp11 > 0) && (tmp10 > tmp12)) || ((tmp11 < 0) && (tmp10 < tmp12))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp10, tmp12); _iSta += tmp11)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:19:5-57:12]*/
      tmp7 = ((modelica_integer) 1); tmp8 = 1; tmp9 = _HEM;
      if(!(((tmp8 > 0) && (tmp7 > tmp9)) || ((tmp8 < 0) && (tmp7 < tmp9))))
      {
        modelica_integer _iD;
        for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp7, tmp9); _iD += tmp8)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:20:7-20:13]*/
          _i = ((modelica_integer) 1);
          /*#endModelicaLine*/

          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:21:7-22:42]*/
          tmp1 = 1.0 - ((real_array_get(_traRef, 5, _Rb, _N, ((modelica_integer) 1), _HEM, _iSta)) * (_refIntShaDev));
          if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[TRA,1,N,iD,iSta] * refIntShaDev / (1.0 - traRef[Rb,N,1,HEM,iSta] * refIntShaDev)");}
          _fac = ((real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _N, _iD, _iSta)) * (_refIntShaDev)) / tmp1;
          /*#endModelicaLine*/

          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:23:7-24:29]*/
          _absBac = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _iD, _iSta) - real_array_get(_traRef, 5, _Rb, _i, _i, _iD, _iSta);
          /*#endModelicaLine*/

          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:26:7-56:13]*/
          if((_N >= ((modelica_integer) 2)))
          {
            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:27:9-28:55]*/
            real_array_get(_absExtIrrNoShaIntSha, 3, _i, _iD, _iSta) = real_array_get(_absExtIrrNoSha, 3, _i, _iD, _iSta) + ((_fac) * (real_array_get(_traRef, 5, _TRA, _N, _i + ((modelica_integer) 1), _HEM, _iSta))) * (_absBac);
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:30:9-40:16]*/
            tmp3 = ((modelica_integer) 2); tmp4 = 1; tmp5 = _N - ((modelica_integer) 1);
            if(!(((tmp4 > 0) && (tmp3 > tmp5)) || ((tmp4 < 0) && (tmp3 < tmp5))))
            {
              modelica_integer _i;
              for(_i = ((modelica_integer) 2); in_range_integer(_i, tmp3, tmp5); _i += tmp4)
              {
                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:31:11-32:46]*/
                tmp2 = 1.0 - ((real_array_get(_traRef, 5, _Rb, _N, ((modelica_integer) 1), _HEM, _iSta)) * (_refIntShaDev));
                if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[TRA,1,N,iD,iSta] * refIntShaDev / (1.0 - traRef[Rb,N,1,HEM,iSta] * refIntShaDev)");}
                _fac = ((real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _N, _iD, _iSta)) * (_refIntShaDev)) / tmp2;
                /*#endModelicaLine*/

                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:33:11-34:33]*/
                _absFro = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _iD, _iSta) - real_array_get(_traRef, 5, _Ra, _i, _i, _iD, _iSta);
                /*#endModelicaLine*/

                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:35:11-36:33]*/
                _absBac = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _iD, _iSta) - real_array_get(_traRef, 5, _Rb, _i, _i, _iD, _iSta);
                /*#endModelicaLine*/

                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:37:11-39:51]*/
                real_array_get(_absExtIrrNoShaIntSha, 3, _i, _iD, _iSta) = real_array_get(_absExtIrrNoSha, 3, _i, _iD, _iSta) + (_fac) * (((real_array_get(_traRef, 5, _TRA, _N, _i, _HEM, _iSta)) * (real_array_get(_traRef, 5, _Rb, _i - ((modelica_integer) 1), ((modelica_integer) 1), _HEM, _iSta))) * (_absFro) + (real_array_get(_traRef, 5, _TRA, _N, _i + ((modelica_integer) 1), _HEM, _iSta)) * (_absBac));
                /*#endModelicaLine*/
              }
            }
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:42:9-42:15]*/
            _i = _N;
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:43:9-44:44]*/
            tmp6 = 1.0 - ((real_array_get(_traRef, 5, _Rb, _N, ((modelica_integer) 1), _HEM, _iSta)) * (_refIntShaDev));
            if (tmp6 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[TRA,1,N,iD,iSta] * refIntShaDev / (1.0 - traRef[Rb,N,1,HEM,iSta] * refIntShaDev)");}
            _fac = ((real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _N, _iD, _iSta)) * (_refIntShaDev)) / tmp6;
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:45:9-46:31]*/
            _absFro = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _iD, _iSta) - real_array_get(_traRef, 5, _Ra, _i, _i, _iD, _iSta);
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:47:9-48:31]*/
            _absBac = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _iD, _iSta) - real_array_get(_traRef, 5, _Rb, _i, _i, _iD, _iSta);
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:49:9-51:30]*/
            real_array_get(_absExtIrrNoShaIntSha, 3, _i, _iD, _iSta) = real_array_get(_absExtIrrNoSha, 3, _i, _iD, _iSta) + (_fac) * (((real_array_get(_traRef, 5, _TRA, _N, _i, _HEM, _iSta)) * (real_array_get(_traRef, 5, _Rb, _i - ((modelica_integer) 1), ((modelica_integer) 1), _HEM, _iSta))) * (_absFro) + _absBac);
            /*#endModelicaLine*/
          }
          else
          {
            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationInteriorShading.mo:54:9-55:30]*/
            real_array_get(_absExtIrrNoShaIntSha, 3, _i, _iD, _iSta) = real_array_get(_absExtIrrNoSha, 3, _i, _iD, _iSta) + (_fac) * (_absBac);
            /*#endModelicaLine*/
          }
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _absExtIrrNoShaIntSha;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData_t *threadData, modelica_metatype _absExtIrrNoSha, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _absExtIrrNoShaIntSha;
  modelica_metatype out_absExtIrrNoShaIntSha;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _absExtIrrNoShaIntSha = omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationInteriorShading(threadData, *((base_array_t*)_absExtIrrNoSha), *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_absExtIrrNoShaIntSha = mmc_mk_modelica_array(_absExtIrrNoShaIntSha);
  return out_absExtIrrNoShaIntSha;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData_t *threadData, real_array _traRef, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _abs;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _af;
  modelica_real _ab;
  modelica_real _deno1;
  modelica_real _deno2;
  modelica_integer _j;
  modelica_real _SMALL;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_integer tmp10;
  modelica_integer tmp11;
  modelica_integer tmp12;
  modelica_real tmp13;
  modelica_integer tmp14;
  modelica_integer tmp15;
  modelica_integer tmp16;
  modelica_integer tmp17;
  modelica_integer tmp18;
  modelica_integer tmp19;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_abs), 3, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _abs has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  // _af has no default value.
  // _ab has no default value.
  // _deno1 has no default value.
  // _deno2 has no default value.
  // _j has no default value.
  _SMALL = 1e-60;
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:19:3-70:9]*/
  if((_N == ((modelica_integer) 1)))
  {
    /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:20:5-20:11]*/
    _j = ((modelica_integer) 1);
    /*#endModelicaLine*/

    /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:21:5-26:12]*/
    tmp4 = ((modelica_integer) 1); tmp5 = 1; tmp6 = _NSta;
    if(!(((tmp5 > 0) && (tmp4 > tmp6)) || ((tmp5 < 0) && (tmp4 < tmp6))))
    {
      modelica_integer _iSta;
      for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp4, tmp6); _iSta += tmp5)
      {
        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:22:7-25:14]*/
        tmp1 = ((modelica_integer) 1); tmp2 = 1; tmp3 = _HEM;
        if(!(((tmp2 > 0) && (tmp1 > tmp3)) || ((tmp2 < 0) && (tmp1 < tmp3))))
        {
          modelica_integer _iD;
          for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp1, tmp3); _iD += tmp2)
          {
            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:23:9-24:30]*/
            real_array_get(_abs, 3, _j, _iD, _iSta) = 1.0 - real_array_get(_traRef, 5, _TRA, _j, _j, _iD, _iSta) - real_array_get(_traRef, 5, _Ra, _j, _j, _iD, _iSta);
            /*#endModelicaLine*/
          }
        }
        /*#endModelicaLine*/
      }
    }
    /*#endModelicaLine*/
  }
  else
  {
    /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:28:5-69:12]*/
    tmp17 = ((modelica_integer) 1); tmp18 = 1; tmp19 = _NSta;
    if(!(((tmp18 > 0) && (tmp17 > tmp19)) || ((tmp18 < 0) && (tmp17 < tmp19))))
    {
      modelica_integer _iSta;
      for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp17, tmp19); _iSta += tmp18)
      {
        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:29:7-68:14]*/
        tmp14 = ((modelica_integer) 1); tmp15 = 1; tmp16 = _HEM;
        if(!(((tmp15 > 0) && (tmp14 > tmp16)) || ((tmp15 < 0) && (tmp14 < tmp16))))
        {
          modelica_integer _iD;
          for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp14, tmp16); _iD += tmp15)
          {
            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:30:9-30:15]*/
            _j = ((modelica_integer) 1);
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:31:9-32:31]*/
            _af = 1.0 - real_array_get(_traRef, 5, _TRA, _j, _j, _iD, _iSta) - real_array_get(_traRef, 5, _Ra, _j, _j, _iD, _iSta);
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:33:9-34:31]*/
            _ab = 1.0 - real_array_get(_traRef, 5, _TRA, _j, _j, _iD, _iSta) - real_array_get(_traRef, 5, _Rb, _j, _j, _iD, _iSta);
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:35:9-35:79]*/
            _deno2 = 1.0 - ((real_array_get(_traRef, 5, _Rb, _j, ((modelica_integer) 1), _iD, _iSta)) * (real_array_get(_traRef, 5, _Ra, _j + ((modelica_integer) 1), _N, _iD, _iSta)));
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:36:9-41:15]*/
            if((_deno2 < _SMALL))
            {
              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:37:11-37:32]*/
              real_array_get(_abs, 3, _j, _iD, _iSta) = 0.0;
              /*#endModelicaLine*/
            }
            else
            {
              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:39:11-40:52]*/
              tmp7 = _deno2;
              if (tmp7 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "ab * traRef[TRA,1,j,iD,iSta] * traRef[Ra,j + 1,N,iD,iSta] / deno2");}
              real_array_get(_abs, 3, _j, _iD, _iSta) = _af + (((_ab) * (real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _j, _iD, _iSta))) * (real_array_get(_traRef, 5, _Ra, _j + ((modelica_integer) 1), _N, _iD, _iSta))) / tmp7;
              /*#endModelicaLine*/
            }
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:43:9-57:16]*/
            tmp10 = ((modelica_integer) 2); tmp11 = 1; tmp12 = _N - ((modelica_integer) 1);
            if(!(((tmp11 > 0) && (tmp10 > tmp12)) || ((tmp11 < 0) && (tmp10 < tmp12))))
            {
              modelica_integer _j;
              for(_j = ((modelica_integer) 2); in_range_integer(_j, tmp10, tmp12); _j += tmp11)
              {
                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:44:11-45:33]*/
                _af = 1.0 - real_array_get(_traRef, 5, _TRA, _j, _j, _iD, _iSta) - real_array_get(_traRef, 5, _Ra, _j, _j, _iD, _iSta);
                /*#endModelicaLine*/

                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:46:11-47:33]*/
                _ab = 1.0 - real_array_get(_traRef, 5, _TRA, _j, _j, _iD, _iSta) - real_array_get(_traRef, 5, _Rb, _j, _j, _iD, _iSta);
                /*#endModelicaLine*/

                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:48:11-48:81]*/
                _deno1 = 1.0 - ((real_array_get(_traRef, 5, _Ra, _j, _N, _iD, _iSta)) * (real_array_get(_traRef, 5, _Rb, _j - ((modelica_integer) 1), ((modelica_integer) 1), _iD, _iSta)));
                /*#endModelicaLine*/

                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:49:11-49:81]*/
                _deno2 = 1.0 - ((real_array_get(_traRef, 5, _Rb, _j, ((modelica_integer) 1), _iD, _iSta)) * (real_array_get(_traRef, 5, _Ra, _j + ((modelica_integer) 1), _N, _iD, _iSta)));
                /*#endModelicaLine*/

                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:50:11-56:17]*/
                if(((_deno1 < _SMALL) || (_deno2 < _SMALL)))
                {
                  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:51:13-51:34]*/
                  real_array_get(_abs, 3, _j, _iD, _iSta) = 0.0;
                  /*#endModelicaLine*/
                }
                else
                {
                  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:53:13-55:35]*/
                  tmp8 = _deno1;
                  if (tmp8 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "af * traRef[TRA,1,j - 1,iD,iSta] / deno1");}
                  tmp9 = _deno2;
                  if (tmp9 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "ab * traRef[TRA,1,j,iD,iSta] * traRef[Ra,j + 1,N,iD,iSta] / deno2");}
                  real_array_get(_abs, 3, _j, _iD, _iSta) = ((_af) * (real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _j - ((modelica_integer) 1), _iD, _iSta))) / tmp8 + (((_ab) * (real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _j, _iD, _iSta))) * (real_array_get(_traRef, 5, _Ra, _j + ((modelica_integer) 1), _N, _iD, _iSta))) / tmp9;
                  /*#endModelicaLine*/
                }
                /*#endModelicaLine*/
              }
            }
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:59:9-59:15]*/
            _j = _N;
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:60:9-61:31]*/
            _af = 1.0 - real_array_get(_traRef, 5, _TRA, _j, _j, _iD, _iSta) - real_array_get(_traRef, 5, _Ra, _j, _j, _iD, _iSta);
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:62:9-62:79]*/
            _deno1 = 1.0 - ((real_array_get(_traRef, 5, _Ra, _j, _N, _iD, _iSta)) * (real_array_get(_traRef, 5, _Rb, _j - ((modelica_integer) 1), ((modelica_integer) 1), _iD, _iSta)));
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:63:9-67:15]*/
            if((_deno1 < _SMALL))
            {
              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:64:11-64:32]*/
              real_array_get(_abs, 3, _j, _iD, _iSta) = 0.0;
              /*#endModelicaLine*/
            }
            else
            {
              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsExteriorIrradiationNoShading.mo:66:11-66:71]*/
              tmp13 = _deno1;
              if (tmp13 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "af * traRef[TRA,1,j - 1,iD,iSta] / deno1");}
              real_array_get(_abs, 3, _j, _iD, _iSta) = ((_af) * (real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _j - ((modelica_integer) 1), _iD, _iSta))) / tmp13;
              /*#endModelicaLine*/
            }
            /*#endModelicaLine*/
          }
        }
        /*#endModelicaLine*/
      }
    }
    /*#endModelicaLine*/
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _abs;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData_t *threadData, modelica_metatype _traRef, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _abs;
  modelica_metatype out_abs;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _abs = omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, *((base_array_t*)_traRef), tmp1, tmp2, tmp3);
  out_abs = mmc_mk_modelica_array(_abs);
  return out_abs;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationExteriorShading(threadData_t *threadData, real_array _absIntIrrNoSha, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _absIntIrrExtSha;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real _fac;
  modelica_real _absFro;
  modelica_real _absBac;
  modelica_integer _i;
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_absIntIrrExtSha), 2, (_index_t)_N, (_index_t)_NSta); // _absIntIrrExtSha has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  // _fac has no default value.
  // _absFro has no default value.
  // _absBac has no default value.
  // _i has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:19:3-52:10]*/
  tmp5 = ((modelica_integer) 1); tmp6 = 1; tmp7 = _NSta;
  if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp5, tmp7); _iSta += tmp6)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:20:5-21:20]*/
      tmp1 = 1.0 - ((real_array_get(_traRef, 5, _Ra, ((modelica_integer) 1), _N, _HEM, _iSta)) * (_refExtShaDev));
      if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[TRA,N,1,HEM,iSta] * refExtShaDev / (1.0 - traRef[Ra,1,N,HEM,iSta] * refExtShaDev)");}
      _fac = ((real_array_get(_traRef, 5, _TRA, _N, ((modelica_integer) 1), _HEM, _iSta)) * (_refExtShaDev)) / tmp1;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:23:5-23:11]*/
      _i = ((modelica_integer) 1);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:24:5-25:27]*/
      _absFro = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _HEM, _iSta) - real_array_get(_traRef, 5, _Ra, _i, _i, _HEM, _iSta);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:26:5-27:27]*/
      _absBac = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _HEM, _iSta) - real_array_get(_traRef, 5, _Rb, _i, _i, _HEM, _iSta);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:29:5-51:11]*/
      if((_N >= ((modelica_integer) 2)))
      {
        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:30:7-31:78]*/
        real_array_get(_absIntIrrExtSha, 2, _i, _iSta) = real_array_get(_absIntIrrNoSha, 2, _i, _iSta) + (_fac) * (_absFro) + (((_fac) * (real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _i, _HEM, _iSta))) * (real_array_get(_traRef, 5, _Ra, _i + ((modelica_integer) 1), _N, _HEM, _iSta))) * (_absBac);
        /*#endModelicaLine*/

        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:33:7-41:14]*/
        tmp2 = ((modelica_integer) 2); tmp3 = 1; tmp4 = _N - ((modelica_integer) 1);
        if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
        {
          modelica_integer _i;
          for(_i = ((modelica_integer) 2); in_range_integer(_i, tmp2, tmp4); _i += tmp3)
          {
            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:34:9-35:31]*/
            _absFro = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _HEM, _iSta) - real_array_get(_traRef, 5, _Ra, _i, _i, _HEM, _iSta);
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:36:9-37:31]*/
            _absBac = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _HEM, _iSta) - real_array_get(_traRef, 5, _Rb, _i, _i, _HEM, _iSta);
            /*#endModelicaLine*/

            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:38:9-40:30]*/
            real_array_get(_absIntIrrExtSha, 2, _i, _iSta) = real_array_get(_absIntIrrNoSha, 2, _i, _iSta) + ((_fac) * (real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _i - ((modelica_integer) 1), _HEM, _iSta))) * (_absFro) + (((_fac) * (real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _i, _HEM, _iSta))) * (real_array_get(_traRef, 5, _Ra, _i + ((modelica_integer) 1), _N, _HEM, _iSta))) * (_absBac);
            /*#endModelicaLine*/
          }
        }
        /*#endModelicaLine*/

        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:43:7-43:13]*/
        _i = _N;
        /*#endModelicaLine*/

        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:44:7-45:29]*/
        _absFro = 1.0 - real_array_get(_traRef, 5, _TRA, _i, _i, _HEM, _iSta) - real_array_get(_traRef, 5, _Ra, _i, _i, _HEM, _iSta);
        /*#endModelicaLine*/

        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:46:7-47:35]*/
        real_array_get(_absIntIrrExtSha, 2, _i, _iSta) = real_array_get(_absIntIrrNoSha, 2, _i, _iSta) + ((_fac) * (real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _i - ((modelica_integer) 1), _HEM, _iSta))) * (_absFro);
        /*#endModelicaLine*/
      }
      else
      {
        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationExteriorShading.mo:49:7-50:28]*/
        real_array_get(_absIntIrrExtSha, 2, _i, _iSta) = real_array_get(_absIntIrrNoSha, 2, _i, _iSta) + (_fac) * (_absFro);
        /*#endModelicaLine*/
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _absIntIrrExtSha;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationExteriorShading(threadData_t *threadData, modelica_metatype _absIntIrrNoSha, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _absIntIrrExtSha;
  modelica_metatype out_absIntIrrExtSha;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _absIntIrrExtSha = omc_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationExteriorShading(threadData, *((base_array_t*)_absIntIrrNoSha), *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_absIntIrrExtSha = mmc_mk_modelica_array(_absIntIrrExtSha);
  return out_absIntIrrExtSha;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationInteriorShading(threadData_t *threadData, real_array _absIntIrrNoSha, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _absIntIrrIntSha;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real _rRho;
  modelica_real _c;
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_absIntIrrIntSha), 2, (_index_t)_N, (_index_t)_NSta); // _absIntIrrIntSha has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  // _rRho has no default value.
  // _c has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationInteriorShading.mo:17:3-24:10]*/
  tmp5 = ((modelica_integer) 1); tmp6 = 1; tmp7 = _NSta;
  if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp5, tmp7); _iSta += tmp6)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationInteriorShading.mo:18:5-18:78]*/
      _rRho = (real_array_get(_traRef, 5, _Rb, _N, ((modelica_integer) 1), _HEM, _iSta)) * (_refIntShaDev);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationInteriorShading.mo:19:5-19:61]*/
      tmp1 = 1.0 - _rRho;
      if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "rRho / (1.0 - rRho)");}
      _c = (_traIntShaDev) * (1.0 + (_rRho) / tmp1);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationInteriorShading.mo:20:5-23:12]*/
      tmp2 = ((modelica_integer) 1); tmp3 = 1; tmp4 = _N;
      if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
      {
        modelica_integer _i;
        for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp2, tmp4); _i += tmp3)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationInteriorShading.mo:21:7-22:29]*/
          real_array_get(_absIntIrrIntSha, 2, _i, _iSta) = (_c) * (real_array_get(_absIntIrrNoSha, 2, _i, _iSta));
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _absIntIrrIntSha;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationInteriorShading(threadData_t *threadData, modelica_metatype _absIntIrrNoSha, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _absIntIrrIntSha;
  modelica_metatype out_absIntIrrIntSha;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _absIntIrrIntSha = omc_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationInteriorShading(threadData, *((base_array_t*)_absIntIrrNoSha), *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_absIntIrrIntSha = mmc_mk_modelica_array(_absIntIrrIntSha);
  return out_absIntIrrIntSha;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationNoShading(threadData_t *threadData, real_array _traRef, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _absIntIrrNoSha;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  real_array _dTraRef;
  real_array _dAbs;
  real_array tmp1;
  integer_array tmp2;
  modelica_integer tmp3;
  index_spec_t tmp4;
  integer_array tmp5;
  modelica_integer tmp6;
  index_spec_t tmp7;
  real_array tmp8;
  integer_array tmp9;
  modelica_integer tmp10;
  index_spec_t tmp11;
  integer_array tmp12;
  modelica_integer tmp13;
  index_spec_t tmp14;
  real_array tmp15;
  integer_array tmp16;
  modelica_integer tmp17;
  index_spec_t tmp18;
  integer_array tmp19;
  modelica_integer tmp20;
  index_spec_t tmp21;
  modelica_integer tmp22;
  modelica_integer tmp23;
  modelica_integer tmp24;
  modelica_integer tmp25;
  modelica_integer tmp26;
  modelica_integer tmp27;
  modelica_integer tmp28;
  modelica_integer tmp29;
  modelica_integer tmp30;
  real_array tmp31;
  integer_array tmp32;
  modelica_integer tmp33;
  index_spec_t tmp34;
  integer_array tmp35;
  modelica_integer tmp36;
  index_spec_t tmp37;
  modelica_integer tmp38;
  modelica_integer tmp39;
  modelica_integer tmp40;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_absIntIrrNoSha), 2, (_index_t)_N, (_index_t)_NSta); // _absIntIrrNoSha has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  alloc_real_array(&(_dTraRef), 5, (_index_t)3, (_index_t)_N, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _dTraRef has no default value.
  alloc_real_array(&(_dAbs), 3, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _dAbs has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationNoShading.mo:19:3-27:10]*/
  tmp28 = ((modelica_integer) 1); tmp29 = 1; tmp30 = _N;
  if(!(((tmp29 > 0) && (tmp28 > tmp30)) || ((tmp29 < 0) && (tmp28 < tmp30))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp28, tmp30); _i += tmp29)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationNoShading.mo:20:5-26:12]*/
      tmp25 = ((modelica_integer) 1); tmp26 = 1; tmp27 = _N;
      if(!(((tmp26 > 0) && (tmp25 > tmp27)) || ((tmp26 < 0) && (tmp25 < tmp27))))
      {
        modelica_integer _j;
        for(_j = ((modelica_integer) 1); in_range_integer(_j, tmp25, tmp27); _j += tmp26)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationNoShading.mo:21:7-25:14]*/
          tmp22 = ((modelica_integer) 1); tmp23 = 1; tmp24 = _HEM;
          if(!(((tmp23 > 0) && (tmp22 > tmp24)) || ((tmp23 < 0) && (tmp22 < tmp24))))
          {
            modelica_integer _iD;
            for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp22, tmp24); _iD += tmp23)
            {
              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationNoShading.mo:22:9-22:88]*/
              create_integer_array_from_range(&tmp2, ((modelica_integer) 1), 1, _NSta);
              tmp3 = size_of_dimension_base_array(tmp2, 1);
              create_index_spec(&tmp4, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _TRA), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp3, integer_array_make_index_array(tmp2), 'A');
              index_alloc_real_array(&_traRef, &tmp4, &tmp1);
              create_integer_array_from_range(&tmp5, ((modelica_integer) 1), 1, _NSta);
              tmp6 = size_of_dimension_base_array(tmp5, 1);
              create_index_spec(&tmp7, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _TRA), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp6, integer_array_make_index_array(tmp5), 'A');
              indexed_assign_real_array(tmp1, &_dTraRef, &tmp7);
              /*#endModelicaLine*/

              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationNoShading.mo:23:9-23:86]*/
              create_integer_array_from_range(&tmp9, ((modelica_integer) 1), 1, _NSta);
              tmp10 = size_of_dimension_base_array(tmp9, 1);
              create_index_spec(&tmp11, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Rb), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp10, integer_array_make_index_array(tmp9), 'A');
              index_alloc_real_array(&_traRef, &tmp11, &tmp8);
              create_integer_array_from_range(&tmp12, ((modelica_integer) 1), 1, _NSta);
              tmp13 = size_of_dimension_base_array(tmp12, 1);
              create_index_spec(&tmp14, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Ra), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp13, integer_array_make_index_array(tmp12), 'A');
              indexed_assign_real_array(tmp8, &_dTraRef, &tmp14);
              /*#endModelicaLine*/

              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationNoShading.mo:24:9-24:86]*/
              create_integer_array_from_range(&tmp16, ((modelica_integer) 1), 1, _NSta);
              tmp17 = size_of_dimension_base_array(tmp16, 1);
              create_index_spec(&tmp18, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Ra), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp17, integer_array_make_index_array(tmp16), 'A');
              index_alloc_real_array(&_traRef, &tmp18, &tmp15);
              create_integer_array_from_range(&tmp19, ((modelica_integer) 1), 1, _NSta);
              tmp20 = size_of_dimension_base_array(tmp19, 1);
              create_index_spec(&tmp21, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Rb), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp20, integer_array_make_index_array(tmp19), 'A');
              indexed_assign_real_array(tmp15, &_dTraRef, &tmp21);
              /*#endModelicaLine*/
            }
          }
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationNoShading.mo:29:3-34:60]*/
  real_array_copy_data(omc_Buildings_HeatTransfer_Windows_Functions_glassAbsExteriorIrradiationNoShading(threadData, _dTraRef, _N, _NSta, _HEM), _dAbs);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationNoShading.mo:37:3-39:10]*/
  tmp38 = ((modelica_integer) 1); tmp39 = 1; tmp40 = _N;
  if(!(((tmp39 > 0) && (tmp38 > tmp40)) || ((tmp39 < 0) && (tmp38 < tmp40))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp38, tmp40); _i += tmp39)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassAbsInteriorIrradiationNoShading.mo:38:5-38:62]*/
      create_integer_array_from_range(&tmp32, ((modelica_integer) 1), 1, _NSta);
      tmp33 = size_of_dimension_base_array(tmp32, 1);
      create_index_spec(&tmp34, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _HEM), 'S', tmp33, integer_array_make_index_array(tmp32), 'A');
      index_alloc_real_array(&_dAbs, &tmp34, &tmp31);
      create_integer_array_from_range(&tmp35, ((modelica_integer) 1), 1, _NSta);
      tmp36 = size_of_dimension_base_array(tmp35, 1);
      create_index_spec(&tmp37, 2, (modelica_integer)(0), make_index_array(1, (modelica_integer) _i), 'S', tmp36, integer_array_make_index_array(tmp35), 'A');
      indexed_assign_real_array(tmp31, &_absIntIrrNoSha, &tmp37);
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _absIntIrrNoSha;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationNoShading(threadData_t *threadData, modelica_metatype _traRef, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _absIntIrrNoSha;
  modelica_metatype out_absIntIrrNoSha;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _absIntIrrNoSha = omc_Buildings_HeatTransfer_Windows_Functions_glassAbsInteriorIrradiationNoShading(threadData, *((base_array_t*)_traRef), tmp1, tmp2, tmp3);
  out_absIntIrrNoSha = mmc_mk_modelica_array(_absIntIrrNoSha);
  return out_absIntIrrNoSha;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData_t *threadData, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM, real_array _glass, real_array _xGla, real_array _psi)
{
  real_array _layer;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _tol;
  real_array _oneLay;
  real_array _oneGla;
  real_array tmp1;
  integer_array tmp2;
  modelica_integer tmp3;
  index_spec_t tmp4;
  integer_array tmp5;
  modelica_integer tmp6;
  index_spec_t tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
  modelica_integer tmp10;
  real_array tmp11;
  index_spec_t tmp12;
  index_spec_t tmp13;
  real_array tmp14;
  index_spec_t tmp15;
  index_spec_t tmp16;
  modelica_integer tmp17;
  modelica_integer tmp18;
  modelica_integer tmp19;
  real_array tmp20;
  integer_array tmp21;
  modelica_integer tmp22;
  index_spec_t tmp23;
  integer_array tmp24;
  modelica_integer tmp25;
  index_spec_t tmp26;
  modelica_integer tmp27;
  modelica_integer tmp28;
  modelica_integer tmp29;
  modelica_integer tmp30;
  modelica_integer tmp31;
  modelica_integer tmp32;
  modelica_integer tmp33;
  modelica_integer tmp34;
  modelica_integer tmp35;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_layer), 4, (_index_t)3, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _layer has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _tol = 0.005;
  alloc_real_array(&(_oneLay), 3, (_index_t)3, (_index_t)_HEM, (_index_t)_NSta); // _oneLay has no default value.
  alloc_real_array(&(_oneGla), 2, (_index_t)3, (_index_t)_NSta); // _oneGla has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:21:3-50:10]*/
  tmp33 = ((modelica_integer) 1); tmp34 = 1; tmp35 = _N;
  if(!(((tmp34 > 0) && (tmp33 > tmp35)) || ((tmp34 < 0) && (tmp33 < tmp35))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp33, tmp35); _i += tmp34)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:23:5-25:12]*/
      tmp8 = ((modelica_integer) 1); tmp9 = 1; tmp10 = ((modelica_integer) 3);
      if(!(((tmp9 > 0) && (tmp8 > tmp10)) || ((tmp9 < 0) && (tmp8 < tmp10))))
      {
        modelica_integer _j;
        for(_j = ((modelica_integer) 1); in_range_integer(_j, tmp8, tmp10); _j += tmp9)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:24:7-24:47]*/
          create_integer_array_from_range(&tmp2, ((modelica_integer) 1), 1, _NSta);
          tmp3 = size_of_dimension_base_array(tmp2, 1);
          create_index_spec(&tmp4, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _i), 'S', tmp3, integer_array_make_index_array(tmp2), 'A');
          index_alloc_real_array(&_glass, &tmp4, &tmp1);
          create_integer_array_from_range(&tmp5, ((modelica_integer) 1), 1, _NSta);
          tmp6 = size_of_dimension_base_array(tmp5, 1);
          create_index_spec(&tmp7, 2, (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', tmp6, integer_array_make_index_array(tmp5), 'A');
          indexed_assign_real_array(tmp1, &_oneGla, &tmp7);
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:27:5-43:13]*/
      tmp17 = ((modelica_integer) 1); tmp18 = 1; tmp19 = _NSta;
      if(!(((tmp18 > 0) && (tmp17 > tmp19)) || ((tmp18 < 0) && (tmp17 < tmp19))))
      {
        modelica_integer _iSta;
        for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp17, tmp19); _iSta += tmp18)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:29:7-42:14]*/
          if((fabs(real_array_get(_glass, 3, _Ra, _i, _iSta) - real_array_get(_glass, 3, _Rb, _i, _iSta)) < _tol))
          {
            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:30:9-34:15]*/
            create_index_spec(&tmp12, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iSta), 'S');
            index_alloc_real_array(&_oneGla, &tmp12, &tmp11);
            create_index_spec(&tmp13, 3, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iSta), 'S');
            indexed_assign_real_array(omc_Buildings_HeatTransfer_Windows_Functions_glassPropertyUncoated(threadData, _HEM, tmp11, real_array_get(_xGla, 1, _i), _psi), &_oneLay, &tmp13);
            /*#endModelicaLine*/
          }
          else
          {
            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:38:9-41:15]*/
            create_index_spec(&tmp15, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iSta), 'S');
            index_alloc_real_array(&_oneGla, &tmp15, &tmp14);
            create_index_spec(&tmp16, 3, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iSta), 'S');
            indexed_assign_real_array(omc_Buildings_HeatTransfer_Windows_Functions_glassPropertyCoated(threadData, _HEM, tmp14, _psi), &_oneLay, &tmp16);
            /*#endModelicaLine*/
          }
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:45:5-49:12]*/
      tmp30 = ((modelica_integer) 1); tmp31 = 1; tmp32 = ((modelica_integer) 3);
      if(!(((tmp31 > 0) && (tmp30 > tmp32)) || ((tmp31 < 0) && (tmp30 < tmp32))))
      {
        modelica_integer _j;
        for(_j = ((modelica_integer) 1); in_range_integer(_j, tmp30, tmp32); _j += tmp31)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:46:7-48:14]*/
          tmp27 = ((modelica_integer) 1); tmp28 = 1; tmp29 = _HEM;
          if(!(((tmp28 > 0) && (tmp27 > tmp29)) || ((tmp28 < 0) && (tmp27 < tmp29))))
          {
            modelica_integer _k;
            for(_k = ((modelica_integer) 1); in_range_integer(_k, tmp27, tmp29); _k += tmp28)
            {
              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassProperty.mo:47:9-47:55]*/
              create_integer_array_from_range(&tmp21, ((modelica_integer) 1), 1, _NSta);
              tmp22 = size_of_dimension_base_array(tmp21, 1);
              create_index_spec(&tmp23, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', tmp22, integer_array_make_index_array(tmp21), 'A');
              index_alloc_real_array(&_oneLay, &tmp23, &tmp20);
              create_integer_array_from_range(&tmp24, ((modelica_integer) 1), 1, _NSta);
              tmp25 = size_of_dimension_base_array(tmp24, 1);
              create_index_spec(&tmp26, 4, (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', tmp25, integer_array_make_index_array(tmp24), 'A');
              indexed_assign_real_array(tmp20, &_layer, &tmp26);
              /*#endModelicaLine*/
            }
          }
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _layer;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData_t *threadData, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM, modelica_metatype _glass, modelica_metatype _xGla, modelica_metatype _psi)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _layer;
  modelica_metatype out_layer;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _layer = omc_Buildings_HeatTransfer_Windows_Functions_glassProperty(threadData, tmp1, tmp2, tmp3, *((base_array_t*)_glass), *((base_array_t*)_xGla), *((base_array_t*)_psi));
  out_layer = mmc_mk_modelica_array(_layer);
  return out_layer;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassPropertyCoated(threadData_t *threadData, modelica_integer _HEM, real_array _glass, real_array _psi)
{
  real_array _layer;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  real_array _a;
  modelica_integer _NDIR;
  modelica_real _psi_c;
  modelica_real _psi_cs;
  modelica_real _angT;
  modelica_real _angR;
  real_array _f;
  modelica_real _deltaX;
  modelica_integer _id1;
  modelica_integer _id2;
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
  modelica_integer tmp10;
  modelica_integer tmp11;
  modelica_integer tmp12;
  modelica_integer tmp13;
  real_array tmp14;
  index_spec_t tmp15;
  modelica_integer tmp16;
  modelica_integer tmp17;
  modelica_integer tmp18;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_layer), 2, (_index_t)3, (_index_t)_HEM); // _layer has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  alloc_real_array(&(_a), 2, (_index_t)4, (_index_t)5);
  real_array_copy_data(_OMC_LIT3, _a);
  
  // _NDIR has no default value.
  // _psi_c has no default value.
  // _psi_cs has no default value.
  // _angT has no default value.
  // _angR has no default value.
  alloc_real_array(&(_f), 2, (_index_t)3, (_index_t)_HEM - ((modelica_integer) 1)); // _f has no default value.
  // _deltaX has no default value.
  // _id1 has no default value.
  // _id2 has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:30:3-30:16]*/
  _NDIR = _HEM - ((modelica_integer) 1);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:31:3-31:49]*/
  tmp1 = ((modelica_real)_NDIR - ((modelica_integer) 1));
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "1.570796326794897 / /*Real*/(NDIR - 1)");}
  _deltaX = (1.570796326794897) / tmp1;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:33:5-35:12]*/
  tmp2 = _TRA; tmp3 = 1; tmp4 = _Rb;
  if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
  {
    modelica_integer _k;
    for(_k = _TRA; in_range_integer(_k, tmp2, tmp4); _k += tmp3)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:34:7-34:77]*/
      real_array_get(_layer, 2, _k, ((modelica_integer) 1)) = real_array_get(_glass, 1, _k);
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:37:5-54:12]*/
  tmp5 = ((modelica_integer) 2); tmp6 = 1; tmp7 = _HEM - ((modelica_integer) 2);
  if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer _j;
    for(_j = ((modelica_integer) 2); in_range_integer(_j, tmp5, tmp7); _j += tmp6)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:38:7-38:41]*/
      _psi_c = cos(real_array_get(_psi, 1, _j));
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:39:8-45:13]*/
      if((real_array_get(_layer, 2, _TRA, ((modelica_integer) 1)) > 0.645))
      {
        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:40:9-40:17]*/
        _id1 = ((modelica_integer) 1);
        /*#endModelicaLine*/

        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:41:9-41:17]*/
        _id2 = ((modelica_integer) 2);
        /*#endModelicaLine*/
      }
      else
      {
        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:43:9-43:17]*/
        _id1 = ((modelica_integer) 3);
        /*#endModelicaLine*/

        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:44:9-44:17]*/
        _id2 = ((modelica_integer) 4);
        /*#endModelicaLine*/
      }
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:46:7-47:51]*/
      _angT = real_array_get(_a, 2, _id1, ((modelica_integer) 1)) + (_psi_c) * (real_array_get(_a, 2, _id1, ((modelica_integer) 2)) + (_psi_c) * (real_array_get(_a, 2, _id1, ((modelica_integer) 3)) + (_psi_c) * (real_array_get(_a, 2, _id1, ((modelica_integer) 4)) + (_psi_c) * (real_array_get(_a, 2, _id1, ((modelica_integer) 5))))));
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:48:7-49:58]*/
      _angR = real_array_get(_a, 2, _id2, ((modelica_integer) 1)) + (_psi_c) * (real_array_get(_a, 2, _id2, ((modelica_integer) 2)) + (_psi_c) * (real_array_get(_a, 2, _id2, ((modelica_integer) 3)) + (_psi_c) * (real_array_get(_a, 2, _id2, ((modelica_integer) 4)) + (_psi_c) * (real_array_get(_a, 2, _id2, ((modelica_integer) 5)))))) - _angT;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:50:7-50:62]*/
      real_array_get(_layer, 2, _TRA, _j) = (real_array_get(_layer, 2, _TRA, ((modelica_integer) 1))) * (_angT);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:51:7-51:73]*/
      real_array_get(_layer, 2, _Ra, _j) = (real_array_get(_layer, 2, _Ra, ((modelica_integer) 1))) * (1.0 - _angR) + _angR;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:52:7-52:73]*/
      real_array_get(_layer, 2, _Rb, _j) = (real_array_get(_layer, 2, _Rb, ((modelica_integer) 1))) * (1.0 - _angR) + _angR;
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:56:5-56:26]*/
  real_array_get(_layer, 2, _TRA, _NDIR) = 0.0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:57:5-57:27]*/
  real_array_get(_layer, 2, _Ra, _NDIR) = 1.0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:58:5-58:27]*/
  real_array_get(_layer, 2, _Rb, _NDIR) = 1.0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:61:5-66:12]*/
  tmp11 = ((modelica_integer) 1); tmp12 = 1; tmp13 = _HEM - ((modelica_integer) 1);
  if(!(((tmp12 > 0) && (tmp11 > tmp13)) || ((tmp12 < 0) && (tmp11 < tmp13))))
  {
    modelica_integer _j;
    for(_j = ((modelica_integer) 1); in_range_integer(_j, tmp11, tmp13); _j += tmp12)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:62:7-62:68]*/
      _psi_cs = (cos(real_array_get(_psi, 1, _j))) * (sin(real_array_get(_psi, 1, _j)));
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:63:7-65:14]*/
      tmp8 = _TRA; tmp9 = 1; tmp10 = _Rb;
      if(!(((tmp9 > 0) && (tmp8 > tmp10)) || ((tmp9 < 0) && (tmp8 < tmp10))))
      {
        modelica_integer _k;
        for(_k = _TRA; in_range_integer(_k, tmp8, tmp10); _k += tmp9)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:64:9-64:40]*/
          real_array_get(_f, 2, _k, _j) = ((2.0) * (real_array_get(_layer, 2, _k, _j))) * (_psi_cs);
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:68:5-74:12]*/
  tmp16 = _TRA; tmp17 = 1; tmp18 = _Rb;
  if(!(((tmp17 > 0) && (tmp16 > tmp18)) || ((tmp17 < 0) && (tmp16 < tmp18))))
  {
    modelica_integer _k;
    for(_k = _TRA; in_range_integer(_k, tmp16, tmp18); _k += tmp17)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyCoated.mo:69:7-73:51]*/
      create_index_spec(&tmp15, 2, (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', (modelica_integer)(1), (int*)0, 'W');
      index_alloc_real_array(&_f, &tmp15, &tmp14);
      real_array_get(_layer, 2, _k, _HEM) = omc_Buildings_Utilities_Math_Functions_trapezoidalIntegration(threadData, _NDIR, tmp14, _deltaX);
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _layer;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassPropertyCoated(threadData_t *threadData, modelica_metatype _HEM, modelica_metatype _glass, modelica_metatype _psi)
{
  modelica_integer tmp1;
  real_array _layer;
  modelica_metatype out_layer;
  tmp1 = mmc_unbox_integer(_HEM);
  _layer = omc_Buildings_HeatTransfer_Windows_Functions_glassPropertyCoated(threadData, tmp1, *((base_array_t*)_glass), *((base_array_t*)_psi));
  out_layer = mmc_mk_modelica_array(_layer);
  return out_layer;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassPropertyUncoated(threadData_t *threadData, modelica_integer _HEM, real_array _glass, modelica_real _x, real_array _psi)
{
  real_array _layer;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_integer _NDIR;
  modelica_real _psi_c;
  modelica_real _psi1_c;
  modelica_real _angT;
  modelica_real _angR;
  real_array _f;
  modelica_real _beta;
  modelica_real _rho0;
  modelica_real _rho;
  modelica_real _rho1;
  modelica_real _rho2;
  modelica_real _tau;
  modelica_real _tau1;
  modelica_real _tau2;
  modelica_real _angT1;
  modelica_real _angT2;
  modelica_real _angR1;
  modelica_real _angR2;
  modelica_real _tmp;
  modelica_real _alpha;
  modelica_real _n;
  modelica_real _psi1;
  modelica_real _deltaX;
  static int tmp1 = 0;
  static int tmp2 = 0;
  static int tmp3 = 0;
  modelica_real tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  static int tmp11 = 0;
  modelica_real tmp12;
  modelica_real tmp13;
  static int tmp14 = 0;
  modelica_real tmp15;
  static int tmp16 = 0;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  static int tmp20 = 0;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_real tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_real tmp36;
  modelica_integer tmp37;
  modelica_integer tmp38;
  modelica_integer tmp39;
  modelica_integer tmp40;
  modelica_integer tmp41;
  modelica_integer tmp42;
  modelica_integer tmp43;
  modelica_integer tmp44;
  modelica_integer tmp45;
  real_array tmp46;
  index_spec_t tmp47;
  modelica_integer tmp48;
  modelica_integer tmp49;
  modelica_integer tmp50;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_layer), 2, (_index_t)3, (_index_t)_HEM); // _layer has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  // _NDIR has no default value.
  // _psi_c has no default value.
  // _psi1_c has no default value.
  // _angT has no default value.
  // _angR has no default value.
  alloc_real_array(&(_f), 2, (_index_t)3, (_index_t)_HEM - ((modelica_integer) 1)); // _f has no default value.
  // _beta has no default value.
  // _rho0 has no default value.
  // _rho has no default value.
  // _rho1 has no default value.
  // _rho2 has no default value.
  // _tau has no default value.
  // _tau1 has no default value.
  // _tau2 has no default value.
  // _angT1 has no default value.
  // _angT2 has no default value.
  // _angR1 has no default value.
  // _angR2 has no default value.
  // _tmp has no default value.
  // _alpha has no default value.
  // _n has no default value.
  // _psi1 has no default value.
  // _deltaX has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:42:3-43:74]*/
  {
    if(!(real_array_get(_glass, 1, _TRA) >= 0.0))
    {
      {
        FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo",42,3,43,74,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT6));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:44:3-45:72]*/
  {
    if(!(real_array_get(_glass, 1, _Ra) >= 0.0))
    {
      {
        FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo",44,3,45,72,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT7));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:46:3-47:113]*/
  {
    if(!(real_array_get(_glass, 1, _TRA) + real_array_get(_glass, 1, _Ra) <= 1.0))
    {
      {
        FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo",46,3,47,113,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT8));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:49:3-49:16]*/
  _NDIR = _HEM - ((modelica_integer) 1);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:50:3-50:47]*/
  tmp4 = ((modelica_real)_NDIR - ((modelica_integer) 1));
  if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "1.570796326794897 / /*Real*/(NDIR - 1)");}
  _deltaX = (1.570796326794897) / tmp4;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:52:3-54:10]*/
  tmp5 = _TRA; tmp6 = 1; tmp7 = _Rb;
  if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer _k;
    for(_k = _TRA; in_range_integer(_k, tmp5, tmp7); _k += tmp6)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:53:5-53:75]*/
      real_array_get(_layer, 2, _k, ((modelica_integer) 1)) = real_array_get(_glass, 1, _k);
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:56:3-56:61]*/
  tmp8 = real_array_get(_glass, 1, _TRA);
  tmp9 = real_array_get(_glass, 1, _Ra);
  _beta = (tmp8 * tmp8) - ((tmp9 * tmp9)) + (2.0) * (real_array_get(_glass, 1, _Ra)) + 1.0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:58:3-58:60]*/
  tmp10 = _beta;
  _tmp = (tmp10 * tmp10) - (((4.0) * (2.0 - real_array_get(_glass, 1, _Ra))) * (real_array_get(_glass, 1, _Ra)));
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:59:3-60:122]*/
  {
    if(!(_tmp >= 0.0))
    {
      {
        FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo",59,3,60,122,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT9));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:62:3-62:55]*/
  tmp12 = _tmp;
  if(!(tmp12 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(tmp) was %g should be >= 0", tmp12);
  }tmp13 = 2.0 - real_array_get(_glass, 1, _Ra);
  if (tmp13 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "0.5 * (beta - sqrt(tmp)) / (2.0 - glass[Ra])");}
  _rho0 = ((0.5) * (_beta - sqrt(tmp12))) / tmp13;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:63:3-64:108]*/
  {
    if(!(_rho0 >= 0.0))
    {
      {
        FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo",63,3,64,108,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT10));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:66:3-66:60]*/
  tmp15 = (_rho0) * (real_array_get(_glass, 1, _TRA));
  if (tmp15 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(glass[Ra] - rho0) / (rho0 * glass[TRA])");}
  _tmp = (real_array_get(_glass, 1, _Ra) - _rho0) / tmp15;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:67:3-68:120]*/
  {
    if(!(_tmp > 0.0))
    {
      {
        FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo",67,3,68,120,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT11));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:70:3-70:29]*/
  tmp17 = _tmp;
  if(!(tmp17 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of log(tmp) was %g should be > 0", tmp17);
  }tmp18 = _x;
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "log(tmp) / x");}
  _alpha = (-((log(tmp17)) / tmp18));
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:71:3-71:20]*/
  tmp19 = _rho0;
  if(!(tmp19 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(rho0) was %g should be >= 0", tmp19);
  }
  _tmp = sqrt(tmp19);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:72:3-73:117]*/
  {
    if(!(_tmp != 1.0))
    {
      {
        FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo",72,3,73,117,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT12));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:74:3-74:33]*/
  tmp21 = 1.0 - _tmp;
  if (tmp21 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(1.0 + tmp) / (1.0 - tmp)");}
  _n = (1.0 + _tmp) / tmp21;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:76:3-97:10]*/
  tmp37 = ((modelica_integer) 2); tmp38 = 1; tmp39 = _HEM - ((modelica_integer) 2);
  if(!(((tmp38 > 0) && (tmp37 > tmp39)) || ((tmp38 < 0) && (tmp37 < tmp39))))
  {
    modelica_integer _j;
    for(_j = ((modelica_integer) 2); in_range_integer(_j, tmp37, tmp39); _j += tmp38)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:77:5-77:38]*/
      tmp22 = _n;
      if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "sin(psi[j]) / n");}
      tmp23 = (sin(real_array_get(_psi, 1, _j))) / tmp22;
      if(!(tmp23 >= -1.0 && tmp23 <= 1.0))
      {
        FILE_INFO info = {"",0,0,0,0,0};
        omc_assert(threadData, info, "Model error: Argument of asin(sin(psi[j]) / n) outside the domain -1.0 <= %g <= 1.0", tmp23);
      }
      _psi1 = asin(tmp23);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:78:5-78:25]*/
      _psi_c = cos(real_array_get(_psi, 1, _j));
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:79:5-79:24]*/
      _psi1_c = cos(_psi1);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:81:5-81:60]*/
      tmp24 = (_n) * (_psi_c) + _psi1_c;
      if (tmp24 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(n * psi_c - psi1_c) / (n * psi_c + psi1_c)");}
      tmp25 = ((_n) * (_psi_c) - _psi1_c) / tmp24;
      _rho1 = (tmp25 * tmp25);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:82:5-82:60]*/
      tmp26 = (_n) * (_psi1_c) + _psi_c;
      if (tmp26 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "(n * psi1_c - psi_c) / (n * psi1_c + psi_c)");}
      tmp27 = ((_n) * (_psi1_c) - _psi_c) / tmp26;
      _rho2 = (tmp27 * tmp27);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:84:5-84:27]*/
      _tau1 = 1.0 - _rho1;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:85:5-85:27]*/
      _tau2 = 1.0 - _rho2;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:87:5-87:32]*/
      tmp28 = _psi1_c;
      if (tmp28 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "alpha * x / psi1_c");}
      _tmp = exp((-(((_alpha) * (_x)) / tmp28)));
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:89:5-89:50]*/
      tmp29 = _tau1;
      tmp30 = _rho1;
      tmp31 = _tmp;
      tmp32 = 1.0 - (((tmp30 * tmp30)) * ((tmp31 * tmp31)));
      if (tmp32 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "tau1 ^ 2.0 * tmp / (1.0 - rho1 ^ 2.0 * tmp ^ 2.0)");}
      _angT1 = (((tmp29 * tmp29)) * (_tmp)) / tmp32;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:90:5-90:41]*/
      _angR1 = (_rho1) * (1.0 + (_angT1) * (_tmp));
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:91:5-91:50]*/
      tmp33 = _tau2;
      tmp34 = _rho2;
      tmp35 = _tmp;
      tmp36 = 1.0 - (((tmp34 * tmp34)) * ((tmp35 * tmp35)));
      if (tmp36 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "tau2 ^ 2.0 * tmp / (1.0 - rho2 ^ 2.0 * tmp ^ 2.0)");}
      _angT2 = (((tmp33 * tmp33)) * (_tmp)) / tmp36;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:92:5-92:41]*/
      _angR2 = (_rho2) * (1.0 + (_angT2) * (_tmp));
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:94:5-94:64]*/
      real_array_get(_layer, 2, _TRA, _j) = (0.5) * (_angT1 + _angT2);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:95:5-95:65]*/
      real_array_get(_layer, 2, _Ra, _j) = (0.5) * (_angR1 + _angR2);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:96:5-96:60]*/
      real_array_get(_layer, 2, _Rb, _j) = real_array_get(_layer, 2, _Ra, _j);
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:100:3-100:31]*/
  real_array_get(_layer, 2, _TRA, _NDIR) = 0.0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:101:3-101:32]*/
  real_array_get(_layer, 2, _Ra, _NDIR) = 1.0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:102:3-102:32]*/
  real_array_get(_layer, 2, _Rb, _NDIR) = 1.0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:105:3-110:10]*/
  tmp43 = ((modelica_integer) 1); tmp44 = 1; tmp45 = _HEM - ((modelica_integer) 1);
  if(!(((tmp44 > 0) && (tmp43 > tmp45)) || ((tmp44 < 0) && (tmp43 < tmp45))))
  {
    modelica_integer _j;
    for(_j = ((modelica_integer) 1); in_range_integer(_j, tmp43, tmp45); _j += tmp44)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:106:5-109:12]*/
      tmp40 = _TRA; tmp41 = 1; tmp42 = _Rb;
      if(!(((tmp41 > 0) && (tmp40 > tmp42)) || ((tmp41 < 0) && (tmp40 < tmp42))))
      {
        modelica_integer _k;
        for(_k = _TRA; in_range_integer(_k, tmp40, tmp42); _k += tmp41)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:107:7-108:12]*/
          real_array_get(_f, 2, _k, _j) = (((2.0) * (real_array_get(_layer, 2, _k, _j))) * (cos(real_array_get(_psi, 1, _j)))) * (sin(real_array_get(_psi, 1, _j)));
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:112:3-300:11]*/
  tmp48 = _TRA; tmp49 = 1; tmp50 = _Rb;
  if(!(((tmp49 > 0) && (tmp48 > tmp50)) || ((tmp49 < 0) && (tmp48 < tmp50))))
  {
    modelica_integer _k;
    for(_k = _TRA; in_range_integer(_k, tmp48, tmp50); _k += tmp49)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassPropertyUncoated.mo:113:5-117:92]*/
      create_index_spec(&tmp47, 2, (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', (modelica_integer)(1), (int*)0, 'W');
      index_alloc_real_array(&_f, &tmp47, &tmp46);
      real_array_get(_layer, 2, _k, _HEM) = omc_Buildings_Utilities_Math_Functions_trapezoidalIntegration(threadData, _NDIR, tmp46, _deltaX);
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _layer;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassPropertyUncoated(threadData_t *threadData, modelica_metatype _HEM, modelica_metatype _glass, modelica_metatype _x, modelica_metatype _psi)
{
  modelica_integer tmp1;
  modelica_real tmp2;
  real_array _layer;
  modelica_metatype out_layer;
  tmp1 = mmc_unbox_integer(_HEM);
  tmp2 = mmc_unbox_real(_x);
  _layer = omc_Buildings_HeatTransfer_Windows_Functions_glassPropertyUncoated(threadData, tmp1, *((base_array_t*)_glass), tmp2, *((base_array_t*)_psi));
  out_layer = mmc_mk_modelica_array(_layer);
  return out_layer;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassTRExteriorIrradiationNoShading(threadData_t *threadData, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM, real_array _layer)
{
  real_array _traRef;
  modelica_real tmp1;
  real_array tmp2;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _aij;
  modelica_real _SMALL;
  real_array tmp3;
  integer_array tmp4;
  modelica_integer tmp5;
  index_spec_t tmp6;
  integer_array tmp7;
  modelica_integer tmp8;
  index_spec_t tmp9;
  modelica_integer tmp10;
  modelica_integer tmp11;
  modelica_integer tmp12;
  modelica_integer tmp13;
  modelica_integer tmp14;
  modelica_integer tmp15;
  real_array tmp16;
  integer_array tmp17;
  modelica_integer tmp18;
  index_spec_t tmp19;
  integer_array tmp20;
  modelica_integer tmp21;
  index_spec_t tmp22;
  modelica_integer tmp23;
  modelica_integer tmp24;
  modelica_integer tmp25;
  static int tmp26 = 0;
  modelica_real tmp27;
  modelica_integer tmp28;
  modelica_integer tmp29;
  modelica_integer tmp30;
  modelica_integer tmp31;
  modelica_integer tmp32;
  modelica_integer tmp33;
  modelica_integer tmp34;
  modelica_integer tmp35;
  modelica_integer tmp36;
  modelica_integer tmp37;
  modelica_integer tmp38;
  modelica_integer tmp39;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_traRef), 5, (_index_t)3, (_index_t)_N, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta);
  tmp1 = 0.0;
  fill_alloc_real_array(&tmp2, tmp1, 5, ((modelica_integer) 3), _N, _N, _HEM, _NSta);
  real_array_copy_data(tmp2, _traRef);
  
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  // _aij has no default value.
  _SMALL = 1e-60;
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:16:3-21:10]*/
  tmp13 = ((modelica_integer) 1); tmp14 = 1; tmp15 = _HEM;
  if(!(((tmp14 > 0) && (tmp13 > tmp15)) || ((tmp14 < 0) && (tmp13 < tmp15))))
  {
    modelica_integer _iD;
    for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp13, tmp15); _iD += tmp14)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:17:5-20:12]*/
      tmp10 = _TRA; tmp11 = 1; tmp12 = _Rb;
      if(!(((tmp11 > 0) && (tmp10 > tmp12)) || ((tmp11 < 0) && (tmp10 < tmp12))))
      {
        modelica_integer _k;
        for(_k = _TRA; in_range_integer(_k, tmp10, tmp12); _k += tmp11)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:18:7-19:28]*/
          create_integer_array_from_range(&tmp4, ((modelica_integer) 1), 1, _NSta);
          tmp5 = size_of_dimension_base_array(tmp4, 1);
          create_index_spec(&tmp6, 4, (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp5, integer_array_make_index_array(tmp4), 'A');
          index_alloc_real_array(&_layer, &tmp6, &tmp3);
          create_integer_array_from_range(&tmp7, ((modelica_integer) 1), 1, _NSta);
          tmp8 = size_of_dimension_base_array(tmp7, 1);
          create_index_spec(&tmp9, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp8, integer_array_make_index_array(tmp7), 'A');
          indexed_assign_real_array(tmp3, &_traRef, &tmp9);
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:24:3-56:9]*/
  if((_N > ((modelica_integer) 1)))
  {
    /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:25:5-55:12]*/
    tmp37 = ((modelica_integer) 1); tmp38 = 1; tmp39 = _HEM;
    if(!(((tmp38 > 0) && (tmp37 > tmp39)) || ((tmp38 < 0) && (tmp37 < tmp39))))
    {
      modelica_integer _iD;
      for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp37, tmp39); _iD += tmp38)
      {
        /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:26:7-54:14]*/
        tmp34 = ((modelica_integer) 1); tmp35 = 1; tmp36 = _N - ((modelica_integer) 1);
        if(!(((tmp35 > 0) && (tmp34 > tmp36)) || ((tmp35 < 0) && (tmp34 < tmp36))))
        {
          modelica_integer _i;
          for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp34, tmp36); _i += tmp35)
          {
            /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:27:9-53:16]*/
            tmp31 = _i + ((modelica_integer) 1); tmp32 = 1; tmp33 = _N;
            if(!(((tmp32 > 0) && (tmp31 > tmp33)) || ((tmp32 < 0) && (tmp31 < tmp33))))
            {
              modelica_integer _j;
              for(_j = _i + ((modelica_integer) 1); in_range_integer(_j, tmp31, tmp33); _j += tmp32)
              {
                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:28:11-30:18]*/
                tmp23 = _TRA; tmp24 = 1; tmp25 = _Rb;
                if(!(((tmp24 > 0) && (tmp23 > tmp25)) || ((tmp24 < 0) && (tmp23 < tmp25))))
                {
                  modelica_integer _k;
                  for(_k = _TRA; in_range_integer(_k, tmp23, tmp25); _k += tmp24)
                  {
                    /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:29:13-29:67]*/
                    create_integer_array_from_range(&tmp17, ((modelica_integer) 1), 1, _NSta);
                    tmp18 = size_of_dimension_base_array(tmp17, 1);
                    create_index_spec(&tmp19, 4, (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp18, integer_array_make_index_array(tmp17), 'A');
                    index_alloc_real_array(&_layer, &tmp19, &tmp16);
                    create_integer_array_from_range(&tmp20, ((modelica_integer) 1), 1, _NSta);
                    tmp21 = size_of_dimension_base_array(tmp20, 1);
                    create_index_spec(&tmp22, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _k), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp21, integer_array_make_index_array(tmp20), 'A');
                    indexed_assign_real_array(tmp16, &_traRef, &tmp22);
                    /*#endModelicaLine*/
                  }
                }
                /*#endModelicaLine*/

                /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:32:11-52:18]*/
                tmp28 = ((modelica_integer) 1); tmp29 = 1; tmp30 = _NSta;
                if(!(((tmp29 > 0) && (tmp28 > tmp30)) || ((tmp29 < 0) && (tmp28 < tmp30))))
                {
                  modelica_integer _iSta;
                  for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp28, tmp30); _iSta += tmp29)
                  {
                    /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:33:13-34:34]*/
                    _aij = 1.0 - ((real_array_get(_traRef, 5, _Ra, _j, _j, _iD, _iSta)) * (real_array_get(_traRef, 5, _Rb, _j - ((modelica_integer) 1), _i, _iD, _iSta)));
                    /*#endModelicaLine*/

                    /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:35:13-36:77]*/
                    {
                      if(!(_aij > (-_SMALL)))
                      {
                        {
                          FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo",35,13,36,77,0};
                          omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT13));
                        }
                      }
                    }
                    /*#endModelicaLine*/

                    /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:37:13-51:19]*/
                    if((_aij < _SMALL))
                    {
                      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:38:15-38:47]*/
                      real_array_get(_traRef, 5, _TRA, _i, _j, _iD, _iSta) = 0.0;
                      /*#endModelicaLine*/

                      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:39:15-39:46]*/
                      real_array_get(_traRef, 5, _Ra, _i, _j, _iD, _iSta) = 1.0;
                      /*#endModelicaLine*/

                      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:40:15-40:46]*/
                      real_array_get(_traRef, 5, _Rb, _j, _i, _iD, _iSta) = 1.0;
                      /*#endModelicaLine*/
                    }
                    else
                    {
                      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:42:15-42:27]*/
                      tmp27 = _aij;
                      if (tmp27 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "1.0 / aij");}
                      _aij = (1.0) / tmp27;
                      /*#endModelicaLine*/

                      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:43:15-44:53]*/
                      real_array_get(_traRef, 5, _TRA, _i, _j, _iD, _iSta) = ((_aij) * (real_array_get(_traRef, 5, _TRA, _i, _j - ((modelica_integer) 1), _iD, _iSta))) * (real_array_get(_traRef, 5, _TRA, _j, _j, _iD, _iSta));
                      /*#endModelicaLine*/

                      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:45:15-47:37]*/
                      real_array_get(_traRef, 5, _Ra, _i, _j, _iD, _iSta) = real_array_get(_traRef, 5, _Ra, _i, _j - ((modelica_integer) 1), _iD, _iSta) + (((_aij) * (real_array_get(_traRef, 5, _TRA, _i, _j - ((modelica_integer) 1), _iD, _iSta))) * (real_array_get(_traRef, 5, _TRA, _i, _j - ((modelica_integer) 1), _iD, _iSta))) * (real_array_get(_traRef, 5, _Ra, _j, _j, _iD, _iSta));
                      /*#endModelicaLine*/

                      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRExteriorIrradiationNoShading.mo:48:15-50:37]*/
                      real_array_get(_traRef, 5, _Rb, _j, _i, _iD, _iSta) = real_array_get(_traRef, 5, _Rb, _j, _j, _iD, _iSta) + (((_aij) * (real_array_get(_traRef, 5, _TRA, _j, _j, _iD, _iSta))) * (real_array_get(_traRef, 5, _TRA, _j, _j, _iD, _iSta))) * (real_array_get(_traRef, 5, _Rb, _j - ((modelica_integer) 1), _i, _iD, _iSta));
                      /*#endModelicaLine*/
                    }
                    /*#endModelicaLine*/
                  }
                }
                /*#endModelicaLine*/
              }
            }
            /*#endModelicaLine*/
          }
        }
        /*#endModelicaLine*/
      }
    }
    /*#endModelicaLine*/
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _traRef;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassTRExteriorIrradiationNoShading(threadData_t *threadData, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM, modelica_metatype _layer)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _traRef;
  modelica_real tmp4;
  real_array tmp5;
  modelica_metatype out_traRef;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _traRef = omc_Buildings_HeatTransfer_Windows_Functions_glassTRExteriorIrradiationNoShading(threadData, tmp1, tmp2, tmp3, *((base_array_t*)_layer));
  out_traRef = mmc_mk_modelica_array(_traRef);
  return out_traRef;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_glassTRInteriorIrradiationNoShading(threadData_t *threadData, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM, real_array _layer)
{
  real_array _traRef;
  modelica_real tmp1;
  real_array tmp2;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  real_array _dLayer;
  real_array _dTraRef;
  real_array tmp3;
  integer_array tmp4;
  modelica_integer tmp5;
  index_spec_t tmp6;
  integer_array tmp7;
  modelica_integer tmp8;
  index_spec_t tmp9;
  real_array tmp10;
  integer_array tmp11;
  modelica_integer tmp12;
  index_spec_t tmp13;
  integer_array tmp14;
  modelica_integer tmp15;
  index_spec_t tmp16;
  real_array tmp17;
  integer_array tmp18;
  modelica_integer tmp19;
  index_spec_t tmp20;
  integer_array tmp21;
  modelica_integer tmp22;
  index_spec_t tmp23;
  modelica_integer tmp24;
  modelica_integer tmp25;
  modelica_integer tmp26;
  modelica_integer tmp27;
  modelica_integer tmp28;
  modelica_integer tmp29;
  real_array tmp30;
  integer_array tmp31;
  modelica_integer tmp32;
  index_spec_t tmp33;
  integer_array tmp34;
  modelica_integer tmp35;
  index_spec_t tmp36;
  real_array tmp37;
  integer_array tmp38;
  modelica_integer tmp39;
  index_spec_t tmp40;
  integer_array tmp41;
  modelica_integer tmp42;
  index_spec_t tmp43;
  real_array tmp44;
  integer_array tmp45;
  modelica_integer tmp46;
  index_spec_t tmp47;
  integer_array tmp48;
  modelica_integer tmp49;
  index_spec_t tmp50;
  modelica_integer tmp51;
  modelica_integer tmp52;
  modelica_integer tmp53;
  modelica_integer tmp54;
  modelica_integer tmp55;
  modelica_integer tmp56;
  modelica_integer tmp57;
  modelica_integer tmp58;
  modelica_integer tmp59;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_traRef), 5, (_index_t)3, (_index_t)_N, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta);
  tmp1 = 0.0;
  fill_alloc_real_array(&tmp2, tmp1, 5, ((modelica_integer) 3), _N, _N, _HEM, _NSta);
  real_array_copy_data(tmp2, _traRef);
  
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  alloc_real_array(&(_dLayer), 4, (_index_t)3, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _dLayer has no default value.
  alloc_real_array(&(_dTraRef), 5, (_index_t)3, (_index_t)_N, (_index_t)_N, (_index_t)_HEM, (_index_t)_NSta); // _dTraRef has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:18:3-26:10]*/
  tmp27 = ((modelica_integer) 1); tmp28 = 1; tmp29 = _HEM;
  if(!(((tmp28 > 0) && (tmp27 > tmp29)) || ((tmp28 < 0) && (tmp27 < tmp29))))
  {
    modelica_integer _iD;
    for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp27, tmp29); _iD += tmp28)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:19:5-25:12]*/
      tmp24 = ((modelica_integer) 1); tmp25 = 1; tmp26 = _N;
      if(!(((tmp25 > 0) && (tmp24 > tmp26)) || ((tmp25 < 0) && (tmp24 < tmp26))))
      {
        modelica_integer _j;
        for(_j = ((modelica_integer) 1); in_range_integer(_j, tmp24, tmp26); _j += tmp25)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:20:7-20:70]*/
          create_integer_array_from_range(&tmp4, ((modelica_integer) 1), 1, _NSta);
          tmp5 = size_of_dimension_base_array(tmp4, 1);
          create_index_spec(&tmp6, 4, (modelica_integer)(0), make_index_array(1, (modelica_integer) _TRA), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp5, integer_array_make_index_array(tmp4), 'A');
          index_alloc_real_array(&_layer, &tmp6, &tmp3);
          create_integer_array_from_range(&tmp7, ((modelica_integer) 1), 1, _NSta);
          tmp8 = size_of_dimension_base_array(tmp7, 1);
          create_index_spec(&tmp9, 4, (modelica_integer)(0), make_index_array(1, (modelica_integer) _TRA), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp8, integer_array_make_index_array(tmp7), 'A');
          indexed_assign_real_array(tmp3, &_dLayer, &tmp9);
          /*#endModelicaLine*/

          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:21:7-22:46]*/
          create_integer_array_from_range(&tmp11, ((modelica_integer) 1), 1, _NSta);
          tmp12 = size_of_dimension_base_array(tmp11, 1);
          create_index_spec(&tmp13, 4, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Rb), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp12, integer_array_make_index_array(tmp11), 'A');
          index_alloc_real_array(&_layer, &tmp13, &tmp10);
          create_integer_array_from_range(&tmp14, ((modelica_integer) 1), 1, _NSta);
          tmp15 = size_of_dimension_base_array(tmp14, 1);
          create_index_spec(&tmp16, 4, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Ra), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp15, integer_array_make_index_array(tmp14), 'A');
          indexed_assign_real_array(tmp10, &_dLayer, &tmp16);
          /*#endModelicaLine*/

          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:23:7-24:46]*/
          create_integer_array_from_range(&tmp18, ((modelica_integer) 1), 1, _NSta);
          tmp19 = size_of_dimension_base_array(tmp18, 1);
          create_index_spec(&tmp20, 4, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Ra), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp19, integer_array_make_index_array(tmp18), 'A');
          index_alloc_real_array(&_layer, &tmp20, &tmp17);
          create_integer_array_from_range(&tmp21, ((modelica_integer) 1), 1, _NSta);
          tmp22 = size_of_dimension_base_array(tmp21, 1);
          create_index_spec(&tmp23, 4, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Rb), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp22, integer_array_make_index_array(tmp21), 'A');
          indexed_assign_real_array(tmp17, &_dLayer, &tmp23);
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:29:3-34:18]*/
  real_array_copy_data(omc_Buildings_HeatTransfer_Windows_Functions_glassTRExteriorIrradiationNoShading(threadData, _N, _NSta, _HEM, _dLayer), _dTraRef);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:37:3-47:10]*/
  tmp57 = ((modelica_integer) 1); tmp58 = 1; tmp59 = _HEM;
  if(!(((tmp58 > 0) && (tmp57 > tmp59)) || ((tmp58 < 0) && (tmp57 < tmp59))))
  {
    modelica_integer _iD;
    for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp57, tmp59); _iD += tmp58)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:38:5-46:12]*/
      tmp54 = ((modelica_integer) 1); tmp55 = 1; tmp56 = _N - ((modelica_integer) 1);
      if(!(((tmp55 > 0) && (tmp54 > tmp56)) || ((tmp55 < 0) && (tmp54 < tmp56))))
      {
        modelica_integer _i;
        for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp54, tmp56); _i += tmp55)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:39:7-45:14]*/
          tmp51 = _i + ((modelica_integer) 1); tmp52 = 1; tmp53 = _N;
          if(!(((tmp52 > 0) && (tmp51 > tmp53)) || ((tmp52 < 0) && (tmp51 < tmp53))))
          {
            modelica_integer _j;
            for(_j = _i + ((modelica_integer) 1); in_range_integer(_j, tmp51, tmp53); _j += tmp52)
            {
              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:40:9-40:88]*/
              create_integer_array_from_range(&tmp31, ((modelica_integer) 1), 1, _NSta);
              tmp32 = size_of_dimension_base_array(tmp31, 1);
              create_index_spec(&tmp33, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _TRA), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp32, integer_array_make_index_array(tmp31), 'A');
              index_alloc_real_array(&_dTraRef, &tmp33, &tmp30);
              create_integer_array_from_range(&tmp34, ((modelica_integer) 1), 1, _NSta);
              tmp35 = size_of_dimension_base_array(tmp34, 1);
              create_index_spec(&tmp36, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _TRA), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp35, integer_array_make_index_array(tmp34), 'A');
              indexed_assign_real_array(tmp30, &_traRef, &tmp36);
              /*#endModelicaLine*/

              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:41:9-42:48]*/
              create_integer_array_from_range(&tmp38, ((modelica_integer) 1), 1, _NSta);
              tmp39 = size_of_dimension_base_array(tmp38, 1);
              create_index_spec(&tmp40, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Rb), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp39, integer_array_make_index_array(tmp38), 'A');
              index_alloc_real_array(&_dTraRef, &tmp40, &tmp37);
              create_integer_array_from_range(&tmp41, ((modelica_integer) 1), 1, _NSta);
              tmp42 = size_of_dimension_base_array(tmp41, 1);
              create_index_spec(&tmp43, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Ra), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp42, integer_array_make_index_array(tmp41), 'A');
              indexed_assign_real_array(tmp37, &_traRef, &tmp43);
              /*#endModelicaLine*/

              /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/glassTRInteriorIrradiationNoShading.mo:43:9-44:48]*/
              create_integer_array_from_range(&tmp45, ((modelica_integer) 1), 1, _NSta);
              tmp46 = size_of_dimension_base_array(tmp45, 1);
              create_index_spec(&tmp47, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Ra), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp46, integer_array_make_index_array(tmp45), 'A');
              index_alloc_real_array(&_dTraRef, &tmp47, &tmp44);
              create_integer_array_from_range(&tmp48, ((modelica_integer) 1), 1, _NSta);
              tmp49 = size_of_dimension_base_array(tmp48, 1);
              create_index_spec(&tmp50, 5, (modelica_integer)(0), make_index_array(1, (modelica_integer) _Rb), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _i), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _N + ((modelica_integer) 1) - _j), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) _iD), 'S', tmp49, integer_array_make_index_array(tmp48), 'A');
              indexed_assign_real_array(tmp44, &_traRef, &tmp50);
              /*#endModelicaLine*/
            }
          }
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _traRef;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_glassTRInteriorIrradiationNoShading(threadData_t *threadData, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM, modelica_metatype _layer)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _traRef;
  modelica_real tmp4;
  real_array tmp5;
  modelica_metatype out_traRef;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _traRef = omc_Buildings_HeatTransfer_Windows_Functions_glassTRInteriorIrradiationNoShading(threadData, tmp1, tmp2, tmp3, *((base_array_t*)_layer));
  out_traRef = mmc_mk_modelica_array(_traRef);
  return out_traRef;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData_t *threadData, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _traExtIrrIntSha;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_traExtIrrIntSha), 2, (_index_t)_HEM, (_index_t)_NSta); // _traExtIrrIntSha has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTExteriorIrradiationInteriorShading.mo:11:3-16:10]*/
  tmp5 = ((modelica_integer) 1); tmp6 = 1; tmp7 = _NSta;
  if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp5, tmp7); _iSta += tmp6)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTExteriorIrradiationInteriorShading.mo:12:5-15:12]*/
      tmp2 = ((modelica_integer) 1); tmp3 = 1; tmp4 = _HEM;
      if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
      {
        modelica_integer _iD;
        for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp2, tmp4); _iD += tmp3)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTExteriorIrradiationInteriorShading.mo:13:7-14:58]*/
          tmp1 = 1.0 - ((_refIntShaDev) * (real_array_get(_traRef, 5, _Rb, _N, ((modelica_integer) 1), _HEM, _iSta)));
          if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[TRA,1,N,iD,iSta] * traIntShaDev / (1.0 - refIntShaDev * traRef[Rb,N,1,HEM,iSta])");}
          real_array_get(_traExtIrrIntSha, 2, _iD, _iSta) = ((real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _N, _iD, _iSta)) * (_traIntShaDev)) / tmp1;
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _traExtIrrIntSha;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData_t *threadData, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _traExtIrrIntSha;
  modelica_metatype out_traExtIrrIntSha;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _traExtIrrIntSha = omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiationInteriorShading(threadData, *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_traExtIrrIntSha = mmc_mk_modelica_array(_traExtIrrIntSha);
  return out_traExtIrrIntSha;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData_t *threadData, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _traExtIrrExtSha;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real _c;
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_traExtIrrExtSha), 2, (_index_t)_HEM, (_index_t)_NSta); // _traExtIrrExtSha has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  // _c has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTExteriorIrradiatrionExteriorShading.mo:13:3-20:10]*/
  tmp5 = ((modelica_integer) 1); tmp6 = 1; tmp7 = _NSta;
  if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp5, tmp7); _iSta += tmp6)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTExteriorIrradiatrionExteriorShading.mo:14:5-19:13]*/
      tmp2 = ((modelica_integer) 1); tmp3 = 1; tmp4 = _HEM;
      if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
      {
        modelica_integer _iD;
        for(_iD = ((modelica_integer) 1); in_range_integer(_iD, tmp2, tmp4); _iD += tmp3)
        {
          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTExteriorIrradiatrionExteriorShading.mo:15:7-16:80]*/
          tmp1 = 1.0 - ((real_array_get(_traRef, 5, _Ra, ((modelica_integer) 1), _N, _HEM, _iSta)) * (_refExtShaDev));
          if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[Ra,1,N,iD,iSta] * refExtShaDev / (1.0 - traRef[Ra,1,N,HEM,iSta] * refExtShaDev)");}
          _c = (_traExtShaDev) * (1.0 + ((real_array_get(_traRef, 5, _Ra, ((modelica_integer) 1), _N, _iD, _iSta)) * (_refExtShaDev)) / tmp1);
          /*#endModelicaLine*/

          /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTExteriorIrradiatrionExteriorShading.mo:17:7-18:29]*/
          real_array_get(_traExtIrrExtSha, 2, _iD, _iSta) = (_c) * (real_array_get(_traRef, 5, _TRA, ((modelica_integer) 1), _N, _iD, _iSta));
          /*#endModelicaLine*/
        }
      }
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _traExtIrrExtSha;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData_t *threadData, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _traExtIrrExtSha;
  modelica_metatype out_traExtIrrExtSha;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _traExtIrrExtSha = omc_Buildings_HeatTransfer_Windows_Functions_winTExteriorIrradiatrionExteriorShading(threadData, *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_traExtIrrExtSha = mmc_mk_modelica_array(_traExtIrrExtSha);
  return out_traExtIrrExtSha;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationExteriorShading(threadData_t *threadData, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _traRefIntIrrExtSha;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_traRefIntIrrExtSha), 2, (_index_t)3, (_index_t)_NSta); // _traRefIntIrrExtSha has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationExteriorShading.mo:9:3-16:10]*/
  tmp3 = ((modelica_integer) 1); tmp4 = 1; tmp5 = _NSta;
  if(!(((tmp4 > 0) && (tmp3 > tmp5)) || ((tmp4 < 0) && (tmp3 < tmp5))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp3, tmp5); _iSta += tmp4)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationExteriorShading.mo:10:5-11:68]*/
      tmp1 = 1.0 - ((_refExtShaDev) * (real_array_get(_traRef, 5, _Ra, ((modelica_integer) 1), _N, _HEM, _iSta)));
      if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[TRA,N,1,HEM,iSta] * traExtShaDev / (1.0 - refExtShaDev * traRef[Ra,1,N,HEM,iSta])");}
      real_array_get(_traRefIntIrrExtSha, 2, _TRA, _iSta) = ((real_array_get(_traRef, 5, _TRA, _N, ((modelica_integer) 1), _HEM, _iSta)) * (_traExtShaDev)) / tmp1;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationExteriorShading.mo:12:5-14:26]*/
      tmp2 = 1.0 - ((real_array_get(_traRef, 5, _Ra, ((modelica_integer) 1), _N, _HEM, _iSta)) * (_refExtShaDev));
      if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "traRef[TRA,N,1,HEM,iSta] * refExtShaDev * traRef[1,1,N,HEM,iSta] / (1.0 - traRef[Ra,1,N,HEM,iSta] * refExtShaDev)");}
      real_array_get(_traRefIntIrrExtSha, 2, _Rb, _iSta) = real_array_get(_traRef, 5, _Rb, _N, ((modelica_integer) 1), _HEM, _iSta) + (((real_array_get(_traRef, 5, _TRA, _N, ((modelica_integer) 1), _HEM, _iSta)) * (_refExtShaDev)) * (real_array_get(_traRef, 5, ((modelica_integer) 1), ((modelica_integer) 1), _N, _HEM, _iSta))) / tmp2;
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationExteriorShading.mo:15:5-15:52]*/
      real_array_get(_traRefIntIrrExtSha, 2, _Ra, _iSta) = 0.0;
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _traRefIntIrrExtSha;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationExteriorShading(threadData_t *threadData, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _traRefIntIrrExtSha;
  modelica_metatype out_traRefIntIrrExtSha;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _traRefIntIrrExtSha = omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationExteriorShading(threadData, *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_traRefIntIrrExtSha = mmc_mk_modelica_array(_traRefIntIrrExtSha);
  return out_traRefIntIrrExtSha;
}

DLLExport
real_array omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationInteriorShading(threadData_t *threadData, real_array _traRef, real_array _traRefShaDev, modelica_integer _N, modelica_integer _NSta, modelica_integer _HEM)
{
  real_array _traRefIntIrrIntSha;
  modelica_integer _TRA;
  modelica_integer _Ra;
  modelica_integer _Rb;
  modelica_real _traExtShaDev;
  modelica_real _refExtShaDev;
  modelica_real _traIntShaDev;
  modelica_real _refIntShaDev;
  modelica_real _rRho;
  modelica_real _rTau;
  modelica_real _c;
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&(_traRefIntIrrIntSha), 2, (_index_t)3, (_index_t)_NSta); // _traRefIntIrrIntSha has no default value.
  _TRA = ((modelica_integer) 1);
  _Ra = ((modelica_integer) 2);
  _Rb = ((modelica_integer) 3);
  _traExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 1));
  _refExtShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 1));
  _traIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 1), ((modelica_integer) 2));
  _refIntShaDev = real_array_get(_traRefShaDev, 2, ((modelica_integer) 2), ((modelica_integer) 2));
  // _rRho has no default value.
  // _rTau has no default value.
  // _c has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationInteriorShading.mo:16:3-25:10]*/
  tmp2 = ((modelica_integer) 1); tmp3 = 1; tmp4 = _NSta;
  if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
  {
    modelica_integer _iSta;
    for(_iSta = ((modelica_integer) 1); in_range_integer(_iSta, tmp2, tmp4); _iSta += tmp3)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationInteriorShading.mo:17:5-17:79]*/
      _rRho = (real_array_get(_traRef, 5, _Rb, _N, ((modelica_integer) 1), _HEM, _iSta)) * (_refIntShaDev);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationInteriorShading.mo:18:5-18:80]*/
      _rTau = (real_array_get(_traRef, 5, _Rb, _N, ((modelica_integer) 1), _HEM, _iSta)) * (_traIntShaDev);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationInteriorShading.mo:19:5-19:62]*/
      tmp1 = 1.0 - _rRho;
      if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "rRho / (1.0 - rRho)");}
      _c = (_traIntShaDev) * (1.0 + (_rRho) / tmp1);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationInteriorShading.mo:21:5-22:28]*/
      real_array_get(_traRefIntIrrIntSha, 2, _TRA, _iSta) = (_c) * (real_array_get(_traRef, 5, _TRA, _N, ((modelica_integer) 1), _HEM, _iSta));
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationInteriorShading.mo:23:5-23:79]*/
      real_array_get(_traRefIntIrrIntSha, 2, _Rb, _iSta) = _refIntShaDev + (_c) * (_rTau);
      /*#endModelicaLine*/

      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/HeatTransfer/Windows/Functions/winTRInteriorIrradiationInteriorShading.mo:24:5-24:52]*/
      real_array_get(_traRefIntIrrIntSha, 2, _Ra, _iSta) = 0.0;
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _traRefIntIrrIntSha;
}
modelica_metatype boxptr_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationInteriorShading(threadData_t *threadData, modelica_metatype _traRef, modelica_metatype _traRefShaDev, modelica_metatype _N, modelica_metatype _NSta, modelica_metatype _HEM)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  real_array _traRefIntIrrIntSha;
  modelica_metatype out_traRefIntIrrIntSha;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_integer(_NSta);
  tmp3 = mmc_unbox_integer(_HEM);
  _traRefIntIrrIntSha = omc_Buildings_HeatTransfer_Windows_Functions_winTRInteriorIrradiationInteriorShading(threadData, *((base_array_t*)_traRef), *((base_array_t*)_traRefShaDev), tmp1, tmp2, tmp3);
  out_traRefIntIrrIntSha = mmc_mk_modelica_array(_traRefIntIrrIntSha);
  return out_traRefIntIrrIntSha;
}

DLLExport
modelica_real omc_Buildings_Utilities_Math_Functions_trapezoidalIntegration(threadData_t *threadData, modelica_integer _N, real_array _f, modelica_real _deltaX)
{
  modelica_real _result;
  static int tmp1 = 0;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_real tmp5;
  _tailrecursive: OMC_LABEL_UNUSED
  // _result has no default value.
  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/Utilities/Math/Functions/trapezoidalIntegration.mo:9:3-9:46]*/
  {
    if(!(_N >= ((modelica_integer) 2)))
    {
      {
        FILE_INFO info = {"/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/Utilities/Math/Functions/trapezoidalIntegration.mo",9,3,9,46,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT14));
      }
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/Utilities/Math/Functions/trapezoidalIntegration.mo:10:3-10:14]*/
  _result = 0.0;
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/Utilities/Math/Functions/trapezoidalIntegration.mo:11:3-13:10]*/
  tmp2 = ((modelica_integer) 1); tmp3 = 1; tmp4 = _N;
  if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp2, tmp4); _i += tmp3)
    {
      /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/Utilities/Math/Functions/trapezoidalIntegration.mo:12:5-12:28]*/
      _result = _result + real_array_get(_f, 1, _i);
      /*#endModelicaLine*/
    }
  }
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/Utilities/Math/Functions/trapezoidalIntegration.mo:15:3-15:21]*/
  _result = (2.0) * (_result);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/Utilities/Math/Functions/trapezoidalIntegration.mo:16:3-16:33]*/
  _result = _result - real_array_get(_f, 1, ((modelica_integer) 1)) - real_array_get(_f, 1, _N);
  /*#endModelicaLine*/

  /*#modelicaLine [/home/marius/Desktop/docker/om_layered/modelica-buildings/Buildings/Utilities/Math/Functions/trapezoidalIntegration.mo:17:3-17:28]*/
  tmp5 = 2.0;
  if (tmp5 == 0) {throwStreamPrint(threadData, "Division by zero %s in function context", "result * deltaX / 2.0");}
  _result = ((_result) * (_deltaX)) / tmp5;
  /*#endModelicaLine*/
  _return: OMC_LABEL_UNUSED
  return _result;
}
modelica_metatype boxptr_Buildings_Utilities_Math_Functions_trapezoidalIntegration(threadData_t *threadData, modelica_metatype _N, modelica_metatype _f, modelica_metatype _deltaX)
{
  modelica_integer tmp1;
  modelica_real tmp2;
  modelica_real _result;
  modelica_metatype out_result;
  tmp1 = mmc_unbox_integer(_N);
  tmp2 = mmc_unbox_real(_deltaX);
  _result = omc_Buildings_Utilities_Math_Functions_trapezoidalIntegration(threadData, tmp1, *((base_array_t*)_f), tmp2);
  out_result = mmc_mk_rcon(_result);
  return out_result;
}

#ifdef __cplusplus
}
#endif
