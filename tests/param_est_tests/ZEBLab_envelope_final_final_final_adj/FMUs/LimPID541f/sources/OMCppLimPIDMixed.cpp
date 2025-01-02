LimPIDMixed::LimPIDMixed(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects)
    : LimPIDJacobian(globalSettings, simObjects)
{
}

LimPIDMixed::LimPIDMixed(LimPIDMixed& instance)
: LimPIDJacobian(instance)
{
}

LimPIDMixed::~LimPIDMixed()
{
}

bool LimPIDMixed::isJacobianSparse(){
 return false;
}

bool LimPIDMixed::isAnalyticJacobianGenerated(){
  return false;
}

const matrix_t& LimPIDMixed::getJacobian( )
{
      return getAJacobian();
}

const matrix_t& LimPIDMixed::getJacobian(unsigned int index)
{
  switch (index)
  {
        case 0:
        {
            return getFMIDERJacobian();
        }
      
      
      
      
      
      
      
      
      
      
      
        case 6:
        {
            return getAJacobian();
        }
      default:
      throw ModelicaSimulationError(MATH_FUNCTION,"Not supported jacobian matrix index");
  }
}
sparsematrix_t& LimPIDMixed::getSparseJacobian( )
{
  throw ModelicaSimulationError(MATH_FUNCTION,"Sparse matrix is not activated");
}

sparsematrix_t& LimPIDMixed::getSparseJacobian(unsigned int index)
{
  throw ModelicaSimulationError(MATH_FUNCTION,"Sparse matrix is not activated");
}

const matrix_t& LimPIDMixed::getStateSetJacobian(unsigned int index)
{
  switch (index)
  {
    default:
       throw ModelicaSimulationError(MATH_FUNCTION,"Not supported statset index");
  }
}
sparsematrix_t& LimPIDMixed::getStateSetSparseJacobian(unsigned int index)
{
  switch (index)
  {
    default:
       throw ModelicaSimulationError(MATH_FUNCTION,"Not supported statset index");
  }
}
bool LimPIDMixed::handleSystemEvents(bool* events)
{
  _callType = IContinuous::DISCRETE;

  bool restart = true;
  bool state_vars_reinitialized = false;
  bool clock_event_detected = false;

  int iter = 0;
  while(restart && !(iter++ > 100))
  {
      bool st_vars_reinit = false;
      //iterate and handle all events inside the eventqueue
      restart = _event_handling->startEventIteration(st_vars_reinit);
      state_vars_reinitialized = state_vars_reinitialized || st_vars_reinit;

      saveAll();
  }

  if (iter > 100 && restart) {
    string error = string("Number of event iteration steps exceeded at time: ") + to_string(_simTime);
    throw ModelicaSimulationError(EVENT_HANDLING, error);
  }
  _callType = IContinuous::CONTINUOUS;

  return state_vars_reinitialized;
}

void LimPIDMixed::saveAll()
{
  return LimPID::saveAll();
}

/*needed for colored jacobians*/

void LimPIDMixed::getAColorOfColumn(int* aSparsePatternColorCols, int size)
{
  memcpy(aSparsePatternColorCols, _AColorOfColumn, size * sizeof(int));
}

int LimPIDMixed::getAMaxColors()
{
  return _AMaxColors;
}

const std::vector<int>& LimPIDMixed::getAColumnsOfColor(int color)
{
  return _AColumnsOfColor[color - 1];
}

const std::vector<int>& LimPIDMixed::getADependenciesOfColumn(int idx)
{
  return _ADependenciesOfColumn[idx];
}

string LimPIDMixed::getModelName()
{
  return "LimPID";
}

/* DAE residuals is empty */
void LimPIDMixed::getResidual(double* f)
{
}
void LimPIDMixed::setAlgebraicDAEVars(const double* y)
{
}
/* get algebraic variables */
void LimPIDMixed::getAlgebraicDAEVars( double* y)
{
}
void LimPIDMixed::evaluateDAE(const UPDATETYPE command )
{
}

