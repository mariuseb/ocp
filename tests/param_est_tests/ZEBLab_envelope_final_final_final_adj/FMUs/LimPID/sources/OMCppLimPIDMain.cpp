#include <Core/ModelicaDefine.h>
#include <Core/Modelica.h>
#include <Core/SimController/ISimController.h>
#include <Core/System/FactoryExport.h>
#include <Core/Utils/extension/logger.hpp>

#ifdef RUNTIME_STATIC_LINKING
  #include "OMCppLimPIDCalcHelperMain.cpp"
  #include <SimCoreFactory/OMCFactory/StaticOMCFactory.h>
#endif

#ifdef USE_BOOST_THREAD
  #include <boost/thread.hpp>
  static long unsigned int getThreadNumber()
  {
     boost::hash<std::string> string_hash;
     return (long unsigned int)string_hash(boost::lexical_cast<std::string>(boost::this_thread::get_id()));
  }
#else
  static long unsigned int getThreadNumber()
  {
     return 0;
  }
#endif

#if defined(_MSC_VER) || defined(__MINGW32__)
#include <tchar.h>
int _tmain(int argc, const _TCHAR* argv[])
#else
int main(int argc, const char* argv[])
#endif
{
    // default program options
    std::map<std::string, std::string> opts;
    opts["-S"] = "0.0";
    opts["-E"] = "1.0";
    opts["-H"] = "0.002";
    opts["-G"] = "500";
    opts["-T"] = "1e-6";
    opts["-I"] = "dassl";
    opts["-P"] = "mat";
    opts["-R"] = "/home/marius/Documents/OpenModelica/build_cmake/install_cmake/bin/../lib/x86_64-linux-gnu/omc/cpp/";
    opts["-M"] = "/home/marius/Desktop/OM_wdir/LimPID541f/";
    opts["-F"] = "/home/marius/Desktop/OM_wdir/LimPID541f/LimPID_res.mat";
    opts["-B"] = ".*";
    opts["--solver-threads"] = "1";
    //no profiling used
    try
    {
          Logger::initialize();
          Logger::setEnabled(true);
          
          #ifdef RUNTIME_STATIC_LINKING
            shared_ptr<StaticOMCFactory>  _factory =  shared_ptr<StaticOMCFactory>(new StaticOMCFactory());
          #else
            shared_ptr<OMCFactory>  _factory =  shared_ptr<OMCFactory>(new OMCFactory());
          #endif //RUNTIME_STATIC_LINKING
          //SimController to start simulation
          
          std::pair<shared_ptr<ISimController>, SimSettings> simulation = _factory->createSimulation(argc, argv, opts);
          
          //create Modelica system
          shared_ptr<ISimObjects> simObjects= simulation.first->getSimObjects();
          weak_ptr<ISimData> simData = simObjects->LoadSimData("LimPID");
          weak_ptr<ISimVars> simVars = simObjects->LoadSimVars("LimPID",51,5,7,0,63,1,0);
          weak_ptr<IMixedSystem> system = simulation.first->LoadSystem("OMCppLimPID.so","LimPID");
          simulation.first->Start(simulation.second, "LimPID");
          
          Logger::finalize();
          return 0;
    }
    catch (ModelicaSimulationError& ex)
    {
        if (!ex.isSuppressed())
            std::cerr << "Simulation stopped with error in " << error_id_string(ex.getErrorID()) << ": "  << ex.what() << std::endl;
        Logger::finalize();
        return 1;
    }
}