#if defined(__TRICORE__) || defined(__vxworks)
  #include <Core/DataExchange/SimDouble.h>
#endif

/* Constructor */
LimPID::LimPID(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects)
    : SystemDefaultImplementation(globalSettings, simObjects, "LimPID")
    , _algLoopSolverFactory(simObjects->getAlgLoopSolverFactory())
    , _pointerToRealVars(getSimVars()->getRealVarsVector())
    , _pointerToIntVars(getSimVars()->getIntVarsVector())
    , _pointerToBoolVars(getSimVars()->getBoolVarsVector())
    , _pointerToStringVars(getSimVars()->getStringVarsVector())
    ,_PI_P_I_P_y_(getSimVars()->initRealVar(0))
    ,__omcQ_24DER_P_PI_P_I_P_y_(getSimVars()->initRealVar(1))
    ,_Ki_(getSimVars()->initRealVar(2))
    ,_Kp_(getSimVars()->initRealVar(3))
    ,_PI_P_Dzero_P_y_(getSimVars()->initRealVar(4))
    ,_PI_P_I_P_u_(getSimVars()->initRealVar(5))
    ,_PI_P_I_P_y_reset_internal_(getSimVars()->initRealVar(6))
    ,_PI_P_P_P_y_(getSimVars()->initRealVar(7))
    ,_PI_P_addP_P_y_(getSimVars()->initRealVar(8))
    ,_PI_P_addPID_P_y_(getSimVars()->initRealVar(9))
    ,_PI_P_addSat_P_y_(getSimVars()->initRealVar(10))
    ,_PI_P_controlError_(getSimVars()->initRealVar(11))
    ,_PI_P_gainPID_P_y_(getSimVars()->initRealVar(12))
    ,_PI_P_gainTrack_P_y_(getSimVars()->initRealVar(13))
    ,_PI_P_y_reset_internal_(getSimVars()->initRealVar(14))
    ,_Tmeas_(getSimVars()->initRealVar(15))
    ,_Tset_(getSimVars()->initRealVar(16))
    ,_u_val_(getSimVars()->initRealVar(17))
    ,_u_val1_(getSimVars()->initRealVar(18))
    ,_u_val11_(getSimVars()->initRealVar(19))
    ,_PI_P_I_P_trigger_internal_(getSimVars()->initBoolVar(0))
    ,_PI_P_Dzero_P_k_(getSimVars()->initRealVar(20))
    ,_PI_P_I_P_k_(getSimVars()->initRealVar(21))
    ,_PI_P_I_P_y_reset_(getSimVars()->initRealVar(22))
    ,_PI_P_I_P_y_start_(getSimVars()->initRealVar(23))
    ,_PI_P_Nd_(getSimVars()->initRealVar(24))
    ,_PI_P_Ni_(getSimVars()->initRealVar(25))
    ,_PI_P_P_P_k_(getSimVars()->initRealVar(26))
    ,_PI_P_Td_(getSimVars()->initRealVar(27))
    ,_PI_P_Ti_(getSimVars()->initRealVar(28))
    ,_PI_P_addI_P_k1_(getSimVars()->initRealVar(29))
    ,_PI_P_addI_P_k2_(getSimVars()->initRealVar(30))
    ,_PI_P_addI_P_k3_(getSimVars()->initRealVar(31))
    ,_PI_P_addP_P_k1_(getSimVars()->initRealVar(32))
    ,_PI_P_addP_P_k2_(getSimVars()->initRealVar(33))
    ,_PI_P_addPID_P_k1_(getSimVars()->initRealVar(34))
    ,_PI_P_addPID_P_k2_(getSimVars()->initRealVar(35))
    ,_PI_P_addPID_P_k3_(getSimVars()->initRealVar(36))
    ,_PI_P_addSat_P_k1_(getSimVars()->initRealVar(37))
    ,_PI_P_addSat_P_k2_(getSimVars()->initRealVar(38))
    ,_PI_P_gainPID_P_k_(getSimVars()->initRealVar(39))
    ,_PI_P_gainTrack_P_k_(getSimVars()->initRealVar(40))
    ,_PI_P_k_(getSimVars()->initRealVar(41))
    ,_PI_P_limiter_P_uMax_(getSimVars()->initRealVar(42))
    ,_PI_P_limiter_P_uMin_(getSimVars()->initRealVar(43))
    ,_PI_P_revAct_(getSimVars()->initRealVar(44))
    ,_PI_P_wd_(getSimVars()->initRealVar(45))
    ,_PI_P_wp_(getSimVars()->initRealVar(46))
    ,_PI_P_xd_start_(getSimVars()->initRealVar(47))
    ,_PI_P_xi_start_(getSimVars()->initRealVar(48))
    ,_PI_P_yMax_(getSimVars()->initRealVar(49))
    ,_PI_P_yMin_(getSimVars()->initRealVar(50))
    ,_PI_P_y_reset_(getSimVars()->initRealVar(51))
    ,_PI_P_y_start_(getSimVars()->initRealVar(52))
    ,_gain_P_k_(getSimVars()->initRealVar(53))
    ,_gain1_P_k_(getSimVars()->initRealVar(54))
    ,_ki_(getSimVars()->initRealVar(55))
    ,_kp_(getSimVars()->initRealVar(56))
    ,_PI_P_I_P_initType_(getSimVars()->initIntVar(0))
    ,_PI_P_I_P_reset_(getSimVars()->initIntVar(1))
    ,_PI_P_controllerType_(getSimVars()->initIntVar(2))
    ,_PI_P_initType_(getSimVars()->initIntVar(3))
    ,_PI_P_reset_(getSimVars()->initIntVar(4))
    ,_PI_P_limiter_P_limitsAtInit_(getSimVars()->initBoolVar(1))
    ,_PI_P_limiter_P_strict_(getSimVars()->initBoolVar(2))
    ,_PI_P_reverseActing_(getSimVars()->initBoolVar(3))
    ,_PI_P_strict_(getSimVars()->initBoolVar(4))
    ,_PI_P_with_D_(getSimVars()->initBoolVar(5))
    ,_PI_P_with_I_(getSimVars()->initBoolVar(6))
    ,__omcQ_24outputAlias_5Fu_5Fval_(getSimVars()->initRealVar(17))
    ,__omcQ_24outputAlias_5Fu_5Fval1_(getSimVars()->initRealVar(18))
    ,__omcQ_24outputAlias_5Fu_5Fval11_(getSimVars()->initRealVar(19))
    ,_PI_P_P_P_u_(getSimVars()->initRealVar(8))
    ,_PI_P_addI_P_u1_(getSimVars()->initRealVar(16))
    ,_PI_P_addI_P_u2_(getSimVars()->initRealVar(15))
    ,_PI_P_addI_P_u3_(getSimVars()->initRealVar(13))
    ,_PI_P_addI_P_y_(getSimVars()->initRealVar(5))
    ,_PI_P_addP_P_u1_(getSimVars()->initRealVar(16))
    ,_PI_P_addP_P_u2_(getSimVars()->initRealVar(15))
    ,_PI_P_addPID_P_u1_(getSimVars()->initRealVar(7))
    ,_PI_P_addPID_P_u2_(getSimVars()->initRealVar(4))
    ,_PI_P_addPID_P_u3_(getSimVars()->initRealVar(0))
    ,_PI_P_addSat_P_u1_(getSimVars()->initRealVar(17))
    ,_PI_P_addSat_P_u2_(getSimVars()->initRealVar(12))
    ,_PI_P_gainPID_P_u_(getSimVars()->initRealVar(9))
    ,_PI_P_gainTrack_P_u_(getSimVars()->initRealVar(10))
    ,_PI_P_limiter_P_u_(getSimVars()->initRealVar(12))
    ,_PI_P_limiter_P_y_(getSimVars()->initRealVar(17))
    ,_PI_P_u_m_(getSimVars()->initRealVar(15))
    ,_PI_P_u_s_(getSimVars()->initRealVar(16))
    ,_PI_P_y_(getSimVars()->initRealVar(17))
    ,_gain_P_u_(getSimVars()->initRealVar(2))
    ,_gain_P_y_(getSimVars()->initRealVar(18))
    ,_gain1_P_u_(getSimVars()->initRealVar(3))
    ,_gain1_P_y_(getSimVars()->initRealVar(19))
{
    initConstVals();
    initStateVars();
    initDerivativeVars();
    initAlgVars();
    initDiscreteAlgVars();
    initIntAlgVars();
    initBoolAlgVars();
    initStringAlgVars();
    initParameterRealVars();
    initParameterIntVars();
    initParameterBoolVars();
    initParameterStringVars();
    initAliasRealVars();
    initAliasIntVars();
    initAliasBoolVars();
    initAliasStringVars();
    
    //Number of equations
    _dimContinuousStates = 1;
    _dimRHS =  1;
    _dimBoolean = 7;
    _dimInteger = 5;
    _dimString = 0;
    _dimReal = 57;
    _dimPartitions = -1;
    _dimZeroFunc = 0;
    _dimClock = 0;
    // simplified treatment of clocks in model as time events
    _dimTimeEvent = 0  + _dimClock;
    _timeEventData = (std::pair<double,double>*)calloc(_dimTimeEvent, sizeof(std::pair<double,double>));
    _currTimeEvents = (double*)malloc(_dimTimeEvent*sizeof(double));
    
    //Number of residues
     _event_handling= shared_ptr<EventHandling>(new EventHandling());

      
      //Initialize the state vector
      SystemDefaultImplementation::initialize();
      //Instantiate auxiliary object for event handling functionality
      //_event_handling.getCondition =  boost::bind(&LimPID::getCondition, this, _1);
      
      //Todo: reindex all arrays removed  // arrayReindex(modelInfo,useFlatArrayNotation)
      
      _functions = new Functions(_simTime, _initial, _terminate);
    
}

LimPID::LimPID(LimPID &instance) : SystemDefaultImplementation(instance)
    , _algLoopSolverFactory(instance.getAlgLoopSolverFactory())
    , _pointerToRealVars(getSimVars()->getRealVarsVector())
    , _pointerToIntVars(getSimVars()->getIntVarsVector())
    , _pointerToBoolVars(getSimVars()->getBoolVarsVector())
    , _pointerToStringVars(getSimVars()->getStringVarsVector())
    ,_PI_P_I_P_y_(getSimVars()->initRealVar(0))
    ,__omcQ_24DER_P_PI_P_I_P_y_(getSimVars()->initRealVar(1))
    ,_Ki_(getSimVars()->initRealVar(2))
    ,_Kp_(getSimVars()->initRealVar(3))
    ,_PI_P_Dzero_P_y_(getSimVars()->initRealVar(4))
    ,_PI_P_I_P_u_(getSimVars()->initRealVar(5))
    ,_PI_P_I_P_y_reset_internal_(getSimVars()->initRealVar(6))
    ,_PI_P_P_P_y_(getSimVars()->initRealVar(7))
    ,_PI_P_addP_P_y_(getSimVars()->initRealVar(8))
    ,_PI_P_addPID_P_y_(getSimVars()->initRealVar(9))
    ,_PI_P_addSat_P_y_(getSimVars()->initRealVar(10))
    ,_PI_P_controlError_(getSimVars()->initRealVar(11))
    ,_PI_P_gainPID_P_y_(getSimVars()->initRealVar(12))
    ,_PI_P_gainTrack_P_y_(getSimVars()->initRealVar(13))
    ,_PI_P_y_reset_internal_(getSimVars()->initRealVar(14))
    ,_Tmeas_(getSimVars()->initRealVar(15))
    ,_Tset_(getSimVars()->initRealVar(16))
    ,_u_val_(getSimVars()->initRealVar(17))
    ,_u_val1_(getSimVars()->initRealVar(18))
    ,_u_val11_(getSimVars()->initRealVar(19))
    ,_PI_P_I_P_trigger_internal_(getSimVars()->initBoolVar(0))
    ,_PI_P_Dzero_P_k_(getSimVars()->initRealVar(20))
    ,_PI_P_I_P_k_(getSimVars()->initRealVar(21))
    ,_PI_P_I_P_y_reset_(getSimVars()->initRealVar(22))
    ,_PI_P_I_P_y_start_(getSimVars()->initRealVar(23))
    ,_PI_P_Nd_(getSimVars()->initRealVar(24))
    ,_PI_P_Ni_(getSimVars()->initRealVar(25))
    ,_PI_P_P_P_k_(getSimVars()->initRealVar(26))
    ,_PI_P_Td_(getSimVars()->initRealVar(27))
    ,_PI_P_Ti_(getSimVars()->initRealVar(28))
    ,_PI_P_addI_P_k1_(getSimVars()->initRealVar(29))
    ,_PI_P_addI_P_k2_(getSimVars()->initRealVar(30))
    ,_PI_P_addI_P_k3_(getSimVars()->initRealVar(31))
    ,_PI_P_addP_P_k1_(getSimVars()->initRealVar(32))
    ,_PI_P_addP_P_k2_(getSimVars()->initRealVar(33))
    ,_PI_P_addPID_P_k1_(getSimVars()->initRealVar(34))
    ,_PI_P_addPID_P_k2_(getSimVars()->initRealVar(35))
    ,_PI_P_addPID_P_k3_(getSimVars()->initRealVar(36))
    ,_PI_P_addSat_P_k1_(getSimVars()->initRealVar(37))
    ,_PI_P_addSat_P_k2_(getSimVars()->initRealVar(38))
    ,_PI_P_gainPID_P_k_(getSimVars()->initRealVar(39))
    ,_PI_P_gainTrack_P_k_(getSimVars()->initRealVar(40))
    ,_PI_P_k_(getSimVars()->initRealVar(41))
    ,_PI_P_limiter_P_uMax_(getSimVars()->initRealVar(42))
    ,_PI_P_limiter_P_uMin_(getSimVars()->initRealVar(43))
    ,_PI_P_revAct_(getSimVars()->initRealVar(44))
    ,_PI_P_wd_(getSimVars()->initRealVar(45))
    ,_PI_P_wp_(getSimVars()->initRealVar(46))
    ,_PI_P_xd_start_(getSimVars()->initRealVar(47))
    ,_PI_P_xi_start_(getSimVars()->initRealVar(48))
    ,_PI_P_yMax_(getSimVars()->initRealVar(49))
    ,_PI_P_yMin_(getSimVars()->initRealVar(50))
    ,_PI_P_y_reset_(getSimVars()->initRealVar(51))
    ,_PI_P_y_start_(getSimVars()->initRealVar(52))
    ,_gain_P_k_(getSimVars()->initRealVar(53))
    ,_gain1_P_k_(getSimVars()->initRealVar(54))
    ,_ki_(getSimVars()->initRealVar(55))
    ,_kp_(getSimVars()->initRealVar(56))
    ,_PI_P_I_P_initType_(getSimVars()->initIntVar(0))
    ,_PI_P_I_P_reset_(getSimVars()->initIntVar(1))
    ,_PI_P_controllerType_(getSimVars()->initIntVar(2))
    ,_PI_P_initType_(getSimVars()->initIntVar(3))
    ,_PI_P_reset_(getSimVars()->initIntVar(4))
    ,_PI_P_limiter_P_limitsAtInit_(getSimVars()->initBoolVar(1))
    ,_PI_P_limiter_P_strict_(getSimVars()->initBoolVar(2))
    ,_PI_P_reverseActing_(getSimVars()->initBoolVar(3))
    ,_PI_P_strict_(getSimVars()->initBoolVar(4))
    ,_PI_P_with_D_(getSimVars()->initBoolVar(5))
    ,_PI_P_with_I_(getSimVars()->initBoolVar(6))
    ,__omcQ_24outputAlias_5Fu_5Fval_(getSimVars()->initRealVar(17))
    ,__omcQ_24outputAlias_5Fu_5Fval1_(getSimVars()->initRealVar(18))
    ,__omcQ_24outputAlias_5Fu_5Fval11_(getSimVars()->initRealVar(19))
    ,_PI_P_P_P_u_(getSimVars()->initRealVar(8))
    ,_PI_P_addI_P_u1_(getSimVars()->initRealVar(16))
    ,_PI_P_addI_P_u2_(getSimVars()->initRealVar(15))
    ,_PI_P_addI_P_u3_(getSimVars()->initRealVar(13))
    ,_PI_P_addI_P_y_(getSimVars()->initRealVar(5))
    ,_PI_P_addP_P_u1_(getSimVars()->initRealVar(16))
    ,_PI_P_addP_P_u2_(getSimVars()->initRealVar(15))
    ,_PI_P_addPID_P_u1_(getSimVars()->initRealVar(7))
    ,_PI_P_addPID_P_u2_(getSimVars()->initRealVar(4))
    ,_PI_P_addPID_P_u3_(getSimVars()->initRealVar(0))
    ,_PI_P_addSat_P_u1_(getSimVars()->initRealVar(17))
    ,_PI_P_addSat_P_u2_(getSimVars()->initRealVar(12))
    ,_PI_P_gainPID_P_u_(getSimVars()->initRealVar(9))
    ,_PI_P_gainTrack_P_u_(getSimVars()->initRealVar(10))
    ,_PI_P_limiter_P_u_(getSimVars()->initRealVar(12))
    ,_PI_P_limiter_P_y_(getSimVars()->initRealVar(17))
    ,_PI_P_u_m_(getSimVars()->initRealVar(15))
    ,_PI_P_u_s_(getSimVars()->initRealVar(16))
    ,_PI_P_y_(getSimVars()->initRealVar(17))
    ,_gain_P_u_(getSimVars()->initRealVar(2))
    ,_gain_P_y_(getSimVars()->initRealVar(18))
    ,_gain1_P_u_(getSimVars()->initRealVar(3))
    ,_gain1_P_y_(getSimVars()->initRealVar(19))
{
    initConstVals();
    initStateVars();
    initDerivativeVars();
    initAlgVars();
    initDiscreteAlgVars();
    initIntAlgVars();
    initBoolAlgVars();
    initStringAlgVars();
    initParameterRealVars();
    initParameterIntVars();
    initParameterBoolVars();
    initParameterStringVars();
    initAliasRealVars();
    initAliasIntVars();
    initAliasBoolVars();
    initAliasStringVars();
    
    //Number of equations
    _dimContinuousStates = 1;
    _dimRHS =  1;
    _dimBoolean = 7;
    _dimInteger = 5;
    _dimString = 0;
    _dimReal = 57;
    _dimPartitions = -1;
    _dimZeroFunc = 0;
    _dimClock = 0;
    // simplified treatment of clocks in model as time events
    _dimTimeEvent = 0  + _dimClock;
    _timeEventData = (std::pair<double,double>*)calloc(_dimTimeEvent, sizeof(std::pair<double,double>));
    _currTimeEvents = (double*)malloc(_dimTimeEvent*sizeof(double));
    
    //Number of residues
     _event_handling= shared_ptr<EventHandling>(new EventHandling());

      
      //Initialize the state vector
      SystemDefaultImplementation::initialize();
      //Instantiate auxiliary object for event handling functionality
      //_event_handling.getCondition =  boost::bind(&LimPID::getCondition, this, _1);
      
      //Todo: reindex all arrays removed  // arrayReindex(modelInfo,useFlatArrayNotation)
      
      _functions = new Functions(_simTime, _initial, _terminate);
    
}

/* Destructor */
LimPID::~LimPID()
{
  deleteObjects();
  
}

void LimPID::deleteObjects()
{

  if(_functions != NULL)
    delete _functions;


}

shared_ptr<IAlgLoopSolverFactory> LimPID::getAlgLoopSolverFactory()
{
    return _algLoopSolverFactory;
}

/*
*/
void LimPID::evaluate_25()
{
  _u_val11_ = (_gain1_P_k_ * _Kp_);
}
/*
*/
void LimPID::evaluate_26()
{
  _u_val1_ = (_gain_P_k_ * _Ki_);
}
/*
*/
void LimPID::evaluate_27()
{
  _PI_P_addP_P_y_ = ((_PI_P_addP_P_k1_ * _Tset_) + (_PI_P_addP_P_k2_ * _Tmeas_));
}
/*
*/
void LimPID::evaluate_28()
{
  _PI_P_P_P_y_ = (_PI_P_P_P_k_ * _PI_P_addP_P_y_);
}
/*
*/
void LimPID::evaluate_29()
{
  _PI_P_addPID_P_y_ = (_PI_P_P_P_y_ + __z[0]);
}
/*
*/
void LimPID::evaluate_30()
{
  _PI_P_gainPID_P_y_ = (_PI_P_gainPID_P_k_ * _PI_P_addPID_P_y_);
}
/*
*/
void LimPID::evaluate_31()
{
  double tmp16;
  double tmp17;
  if (_PI_P_gainPID_P_y_ > 1.0) {
    tmp17 = 1.0;
  } else {
    if (_PI_P_gainPID_P_y_ < 0.0) {
      tmp16 = 0.0;
    } else {
      tmp16 = _PI_P_gainPID_P_y_;
    }
    tmp17 = tmp16;
  }
  _u_val_ = tmp17;
}
/*
*/
void LimPID::evaluate_32()
{
  _PI_P_addSat_P_y_ = (_u_val_ - _PI_P_gainPID_P_y_);
}
/*
*/
void LimPID::evaluate_33()
{
  _PI_P_gainTrack_P_y_ = (_PI_P_gainTrack_P_k_ * _PI_P_addSat_P_y_);
}
/*
*/
void LimPID::evaluate_34()
{
  _PI_P_I_P_u_ = ((_PI_P_addI_P_k1_ * _Tset_) + ((_PI_P_addI_P_k2_ * _Tmeas_) + (_PI_P_addI_P_k3_ * _PI_P_gainTrack_P_y_)));
}
/*
*/
void LimPID::evaluate_35()
{
  __zDot[0] = (_PI_P_I_P_k_ * _PI_P_I_P_u_);
}
/*
*/
void LimPID::evaluate_36()
{
  _PI_P_controlError_ = (_Tset_ - _Tmeas_);
}



/* Clocked synchronous equations */
void LimPID::evaluateClocked(int index)
{
  switch (index) {
    default:
      throw ModelicaSimulationError(MODEL_EQ_SYSTEM, "Unknown partition");
      break;
  }
}

bool LimPID::evaluateAll(const UPDATETYPE command)
{
  // treatment of clocks in model as time events
  for (int i = 0; i < _dimTimeEvent; i++) {
    if (_time_conditions[i]) {
      evaluateClocked(i - 0 + 1);
      _time_conditions[i] = false; // reset clock after one evaluation
      _clockSubactive[i - 0] = false;
    }
  }
  
  // Evaluate Equations
  if (_dimAE > 0)
    evaluateDAE(command);
  evaluateAll_0(command);

  
  return _state_var_reinitialized;
}

void LimPID::evaluateODE(const UPDATETYPE command)
{
  // Evaluate Equations
  evaluateODE_0(command);
}

void LimPID::evaluateZeroFuncs(const UPDATETYPE command)
{
  // Evaluate Equations
}

bool LimPID::evaluateConditions(const UPDATETYPE command)
{
  return evaluateAll(command);
}

// Release instance
void LimPID::destroy()
{
  delete this;
}

// Computes the conditions of time event samplers for the current time
double LimPID::computeNextTimeEvents(double currTime)
{
  return SystemDefaultImplementation::computeNextTimeEvents(currTime, getTimeEventData());
}

// Provide number (dimension) of right hand sides (equations and/or residuals) according to the index
int LimPID::getDimRHS() const
{
 if(_callType & IContinuous::RANKING)
  {
  return 13;
  }
  else
  return(SystemDefaultImplementation::getDimRHS());
}

void LimPID::getNominalStates(double* z)
{
  z[0] = 1.0;
}

// Set variables with given index to the system
 void LimPID::setRealStartValue(double& var,double val)
 {
   SystemDefaultImplementation::setRealStartValue(var, val);
 }
 
 void LimPID::setBoolStartValue(bool& var,bool val)
 {
   SystemDefaultImplementation::setBoolStartValue(var, val);
 }
 
 void LimPID::setIntStartValue(int& var,int val)
 {
   SystemDefaultImplementation::setIntStartValue(var, val);
 }
 
 void LimPID::setStringStartValue(string& var,string val)
 {
   SystemDefaultImplementation::setStringStartValue(var, val);
 }
 
 void LimPID::setNumPartitions(int numPartitions)
 {
   _dimPartitions = numPartitions;
 }
 
 int LimPID::getNumPartitions()
 {
   return _dimPartitions;
 }
 void LimPID::setPartitionActivation(bool* partitions)
 {
   _partitionActivation = partitions;
 }
 
 void LimPID::getPartitionActivation(bool* partitions)
 {
   partitions = _partitionActivation;
 }
 
 int LimPID::getActivator(int state)
 {
   return (int)_stateActivator[state];
 }
// Provide the right hand side
void LimPID::getRHS(double* f)
{
    SystemDefaultImplementation::getRHS(f);
}

bool LimPID::isStepEvent()
{
 throw ModelicaSimulationError(MODEL_EQ_SYSTEM,"isStepEvent is not yet implemented");
}
void LimPID::setTerminal(bool terminal)
{
  _terminal=terminal;
}
bool LimPID::terminal()
{
  return _terminal;
}
bool LimPID::isAlgebraic()
{
  return false; // Indexreduction is enabled
}
bool LimPID::provideSymbolicJacobian()
{
  throw ModelicaSimulationError(MODEL_EQ_SYSTEM,"provideSymbolicJacobian is not yet implemented");
}
void LimPID::handleEvent(const bool* events)
{
}

bool LimPID::checkForDiscreteEvents()
{
  return false;
}
void LimPID::getZeroFunc(double* f)
{
  
  
}

void LimPID::setConditions(bool* c)
{
  SystemDefaultImplementation::setConditions(c);
}
void LimPID::getConditions(bool* c)
{
    SystemDefaultImplementation::getConditions(c);
}
void LimPID::getClockConditions(bool* c)
{
    SystemDefaultImplementation::getClockConditions(c);
}
bool LimPID::isConsistent()
{
  return SystemDefaultImplementation::isConsistent();
}

bool LimPID::stepCompleted(double time)
{


  storeTime(time);
#if defined(__TRICORE__) || defined(__vxworks)
    dynamic_cast<SimDouble*>( _simObjects->getSimData(_modelName)->Get("_u_val_"))->getValue() = _u_val_;
    dynamic_cast<SimDouble*>( _simObjects->getSimData(_modelName)->Get("_u_val1_"))->getValue() = _u_val1_;
    dynamic_cast<SimDouble*>( _simObjects->getSimData(_modelName)->Get("_u_val11_"))->getValue() = _u_val11_;
#endif

saveAll();
return _terminate;
}
bool LimPID::stepStarted(double time)
{
#if defined(__TRICORE__) || defined(__vxworks)
    _Ki_ = dynamic_cast<SimDouble*>(_simObjects->getSimData(_modelName)->Get("_Ki_"))->getValue();
    _Kp_ = dynamic_cast<SimDouble*>(_simObjects->getSimData(_modelName)->Get("_Kp_"))->getValue();
    _Tmeas_ = dynamic_cast<SimDouble*>(_simObjects->getSimData(_modelName)->Get("_Tmeas_"))->getValue();
    _Tset_ = dynamic_cast<SimDouble*>(_simObjects->getSimData(_modelName)->Get("_Tset_"))->getValue();
#endif

return true;
}

void LimPID::restoreOldValues()
{

}
void LimPID::restoreNewValues()
{

}

int LimPID::getDimTimeEvent() const
{
  return _dimTimeEvent;
}
std::pair<double,double>* LimPID::getTimeEventData() const
{
  return _timeEventData;
}
void LimPID::initTimeEventData()
{
   // simplified treatment of clocks in model as time events
  for (int i = 0; i < _dimClock; i++)
  {
    _timeEventData[_dimTimeEvent-_dimClock+i] = std::make_pair(_clockShift[i] * _clockInterval[i], _clockInterval[i]);
  }
}

bool LimPID::isODE()
{
  return 1>0 ;
}
int LimPID::getDimZeroFunc()
{
  return _dimZeroFunc;
}
int LimPID::getDimClock()
{
  return _dimClock;
}

bool LimPID::getCondition(unsigned int index)
{
  return false;
}

void LimPID::saveAll()
{
     getSimVars()->savePreVariables();
}


void LimPID::getReal(double* z)
{
  const double* real_vars = getSimVars()->getRealVarsVector();
  memcpy(z,real_vars,57*sizeof(double));
}

void LimPID::setReal(const double* z)
{
  getSimVars()->setRealVarsVector(z);
}

void LimPID::getInteger(int* z)
{
  const int* int_vars = getSimVars()->getIntVarsVector();
  memcpy(z,int_vars,5*sizeof(int));
}

void LimPID::getBoolean(bool* z)
{
  const bool* bool_vars = getSimVars()->getBoolVarsVector();
  memcpy(z,bool_vars,7*sizeof(bool));
}

void LimPID::getString(string* z)
{
}

void LimPID::setInteger(const int* z)
{
   getSimVars()->setIntVarsVector(z);
}

void LimPID::setBoolean(const bool* z)
{
  getSimVars()->setBoolVarsVector(z);
}

void LimPID::setString(const string* z)
{
}

//StateVars
void LimPID::initStateVars_0()
{
}

void LimPID::initStateVars()
{
    initStateVars_0();
}

//DerivativeVars
void LimPID::initDerivativeVars_0()
{
}

void LimPID::initDerivativeVars()
{
    initDerivativeVars_0();
}

//AlgVars
void LimPID::initAlgVars_0()
{
}

void LimPID::initAlgVars()
{
    initAlgVars_0();
}

//DiscreteAlgVars

void LimPID::initDiscreteAlgVars()
{
}

//IntAlgVars
void LimPID::initIntAlgVars()
{
}

//BoolAlgVars
void LimPID::initBoolAlgVars_0()
{
}
void LimPID::initBoolAlgVars()
{
    initBoolAlgVars_0();
}

//StringAlgVars
void LimPID::initStringAlgVars()
{
}

//ParameterRealVars
void LimPID::initParameterRealVars_0()
{
}
void LimPID::initParameterRealVars()
{
    initParameterRealVars_0();
}

//ParameterIntVars
void LimPID::initParameterIntVars_0()
{
}
void LimPID::initParameterIntVars()
{
    initParameterIntVars_0();
}

//ParameterBoolVars
void LimPID::initParameterBoolVars_0()
{
}
void LimPID::initParameterBoolVars()
{
    initParameterBoolVars_0();
}

//ParameterStringVars
void LimPID::initParameterStringVars()
{
}

//AliasRealVars
void LimPID::initAliasRealVars_0()
{
}
void LimPID::initAliasRealVars()
{
    initAliasRealVars_0();
}

//AliasIntVars
void LimPID::initAliasIntVars()
{
}

//AliasBoolVars
void LimPID::initAliasBoolVars()
{
}

//AliasStringVars
void LimPID::initAliasStringVars()
{
}

//String parameter 0

void LimPID::initConstVals()
{
}

void LimPID::evaluateAll_0(const UPDATETYPE command)
{
  evaluate_25();
  evaluate_26();
  evaluate_27();
  evaluate_28();
  evaluate_29();
  evaluate_30();
  evaluate_31();
  evaluate_32();
  evaluate_33();
  evaluate_34();
  evaluate_35();
  evaluate_36();
}
void LimPID::evaluateODE_0(const UPDATETYPE command)
{
  evaluate_27();
  evaluate_28();
  evaluate_29();
  evaluate_30();
  evaluate_31();
  evaluate_32();
  evaluate_33();
  evaluate_34();
  evaluate_35();
}