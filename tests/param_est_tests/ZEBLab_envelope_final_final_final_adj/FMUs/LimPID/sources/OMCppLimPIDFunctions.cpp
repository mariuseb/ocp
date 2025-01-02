

//external functions
extern "C" {
}

Functions::Functions(double& simTime, bool& initial, bool& terminate)
  : _simTime(simTime)
  , _initial(initial)
  , _terminate(terminate)
{
}

Functions::~Functions()
{
}

void Functions::Assert(bool cond, string msg)
{
  if (!cond)
    throw ModelicaSimulationError(MODEL_EQ_SYSTEM, msg);
}

/*extraFuncs*/
