#if defined(__TRICORE__) || defined(__vxworks)
#include <Core/System/FactoryExport.h>
#include <Core/DataExchange/SimData.h>
#include <Core/System/SimVars.h>
extern "C" IMixedSystem* createModelicaSystem(IGlobalSettings* globalSettings,shared_ptr<ISimObjects> simObjects)
{
    return new LimPIDInitialize(globalSettings, simObjects);
}

extern "C" ISimVars* createSimVars(size_t dim_real, size_t dim_int, size_t dim_bool, size_t dim_string, size_t dim_pre_vars, size_t dim_z, size_t z_i)
{
    return new SimVars(dim_real, dim_int, dim_bool, dim_string, dim_pre_vars, dim_z, z_i);
}

extern "C" ISimData* createSimData()
{
    return new SimData();
}

shared_ptr<ISimData> createSimDataFunction()
{
  shared_ptr<ISimData> data( new SimData() );
  return data;
}

shared_ptr<ISimVars> createSimVarsFunction(size_t dim_real, size_t dim_int, size_t dim_bool, size_t dim_string, size_t dim_pre_vars, size_t dim_z, size_t z_i)
{
  shared_ptr<ISimVars> var( new SimVars(dim_real, dim_int, dim_bool, dim_string, dim_pre_vars, dim_z, z_i) );
  return var;
}

#elif defined (RUNTIME_STATIC_LINKING)
#include <Core/System/FactoryExport.h>
#include <Core/DataExchange/SimData.h>
#include <Core/System/SimVars.h>
  shared_ptr<ISimData> createSimDataFunction()
  {
      shared_ptr<ISimData> data( new SimData() );
      return data;
  }

  shared_ptr<ISimVars> createSimVarsFunction(size_t dim_real, size_t dim_int, size_t dim_bool, size_t dim_string, size_t dim_pre_vars, size_t dim_z, size_t z_i)
  {
      shared_ptr<ISimVars> var( new SimVars(dim_real, dim_int, dim_bool, dim_string, dim_pre_vars, dim_z, z_i) );
      return var;
  }

  shared_ptr<IMixedSystem> createSystemFunction(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects)
  {
      shared_ptr<IMixedSystem> system( new LimPIDInitialize(globalSettings, simObjects) );
      return system;
  }

#else

BOOST_EXTENSION_TYPE_MAP_FUNCTION
{
  typedef boost::extensions::factory<IMixedSystem,IGlobalSettings*, shared_ptr<ISimObjects> > system_factory;
  types.get<std::map<std::string, system_factory> >()["LimPID"]
    .system_factory::set<LimPIDInitialize>();
}
#endif