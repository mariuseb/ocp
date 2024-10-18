// define model identifier and unique id
#define MODEL_IDENTIFIER LimPID
#define MODEL_IDENTIFIER_SHORT LimPID
#define MODEL_CLASS LimPIDFMU
#define MODEL_GUID "{7b7d4199-63aa-41c1-9919-c81e6772f780}"

/* TODO: implement external functions in FMU wrapper for c++ target
*/
#define NUMBER_OF_EVENT_INDICATORS 0

#include "FMU2/FMU2Wrapper.cpp"
#include "FMU2/FMU2Interface.cpp"

// SimObjects for LimPIDFMU
shared_ptr<IAlgLoopSolverFactory> createStaticAlgLoopSolverFactory(IGlobalSettings*, PATH, PATH);

class LimPIDSimObjects : public ISimObjects {
 public:
  LimPIDSimObjects(IGlobalSettings *globalSettings) {
    _algLoopSolverFactory = shared_ptr<IAlgLoopSolverFactory>();
  }
  LimPIDSimObjects(LimPIDSimObjects& instance) {
    _algLoopSolverFactory = instance._algLoopSolverFactory;
  }
  weak_ptr<ISimData> LoadSimData(string modelKey) {
    return shared_ptr<ISimData>();
  }
  weak_ptr<ISimVars> LoadSimVars(string modelKey, size_t dim_real, size_t dim_int, size_t dim_bool, size_t dim_string, size_t dim_pre_vars, size_t dim_z, size_t z_i) {
    _simVars = shared_ptr<ISimVars>(new SimVars(dim_real, dim_int, dim_bool, dim_string, dim_pre_vars, dim_z, z_i));
    return _simVars;
  }
  weak_ptr<IHistory> LoadWriter(size_t) {
    return shared_ptr<IHistory>();
  }
  shared_ptr<ISimData> getSimData(string modelKey) {
    return shared_ptr<ISimData>();
  }
  shared_ptr<ISimVars> getSimVars(string modelKey) {
    return _simVars;
  }
  void eraseSimData(string modelKey) {}
  void eraseSimVars(string modelKey) {}
  shared_ptr<IAlgLoopSolverFactory> getAlgLoopSolverFactory() {
    return _algLoopSolverFactory;
  }
  
  ISimObjects* clone() {
    return new LimPIDSimObjects(*this);
  }
 protected:
  shared_ptr<ISimVars> _simVars;
  shared_ptr<IAlgLoopSolverFactory> _algLoopSolverFactory;
};

// create instance of LimPIDFMU
LimPIDFMU *createSystemFMU(IGlobalSettings *globalSettings) {
  shared_ptr<ISimObjects> simObjects(new LimPIDSimObjects(globalSettings));
  simObjects->LoadSimVars("LimPID", 57, 5, 7, 0, 69, 1, 0);
  simObjects->LoadSimData("LimPID");
  globalSettings->setOutputFormat(EMPTY);
  return new LimPIDFMU(globalSettings, simObjects);
}

// value references of real inputs
unsigned int LimPIDFMU::_inputRefs[] = {2, 3, 15, 16};
// value references of real discrete states and outputs
unsigned int LimPIDFMU::_outputRefs[] = {17, 18, 19};

// constructor
LimPIDFMU::LimPIDFMU(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects)
  : LimPIDInitialize(globalSettings, simObjects) {
}

// initialization
void LimPIDFMU::initialize() {
  LimPIDWriteOutput::initialize();
  LimPIDInitialize::initializeMemory();
  LimPIDInitialize::initializeFreeVariables();
  LimPIDJacobian::initialize();
}

// getters
void LimPIDFMU::getReal(const unsigned int vr[], size_t nvr,  double value[]) {
  for (size_t i = 0; i < nvr; i++, vr++, value++) {
    // access variables and aliases in SimVars memory
    if (*vr < _dimReal)
      *value = _pointerToRealVars[*vr];
    // convert negated aliases
    else switch (*vr) {
      default:
        throw std::invalid_argument("getReal with wrong value reference " + omcpp::to_string(*vr));
    }
  }
}
void LimPIDFMU::getInteger(const unsigned int vr[], size_t nvr,  int value[]) {
  for (size_t i = 0; i < nvr; i++, vr++, value++) {
    // access variables and aliases in SimVars memory
    if (*vr < _dimInteger)
      *value = _pointerToIntVars[*vr];
    // convert negated aliases
    else switch (*vr) {
      default:
        throw std::invalid_argument("getInteger with wrong value reference " + omcpp::to_string(*vr));
    }
  }
}
void LimPIDFMU::getBoolean(const unsigned int vr[], size_t nvr,  int value[]) {
  for (size_t i = 0; i < nvr; i++, vr++, value++) {
    // access variables and aliases in SimVars memory
    if (*vr < _dimBoolean)
      *value = _pointerToBoolVars[*vr];
    // convert negated aliases
    else switch (*vr) {
      default:
        throw std::invalid_argument("getBoolean with wrong value reference " + omcpp::to_string(*vr));
    }
  }
}
void LimPIDFMU::getString(const unsigned int vr[], size_t nvr,  string value[]) {
  for (size_t i = 0; i < nvr; i++, vr++, value++) {
    // access variables and aliases in SimVars memory
    if (*vr < _dimString)
      *value = _pointerToStringVars[*vr];
    // convert negated aliases
    else switch (*vr) {
      default:
        throw std::invalid_argument("getString with wrong value reference " + omcpp::to_string(*vr));
    }
  }
}

// setters
void LimPIDFMU::setReal(const unsigned int vr[], size_t nvr, const double value[]) {
  for (size_t i = 0; i < nvr; i++, vr++, value++) {
    // access variables and aliases in SimVars memory
    if (*vr < _dimReal)
      _pointerToRealVars[*vr] = *value;
    // convert negated aliases
    else switch (*vr) {
      default:
        throw std::invalid_argument("setReal with wrong value reference " + omcpp::to_string(*vr));
    }
  }
}
void LimPIDFMU::setInteger(const unsigned int vr[], size_t nvr, const int value[]) {
  for (size_t i = 0; i < nvr; i++, vr++, value++) {
    // access variables and aliases in SimVars memory
    if (*vr < _dimInteger)
      _pointerToIntVars[*vr] = *value;
    // convert negated aliases
    else switch (*vr) {
      default:
        throw std::invalid_argument("setInteger with wrong value reference " + omcpp::to_string(*vr));
    }
  }
}
void LimPIDFMU::setBoolean(const unsigned int vr[], size_t nvr, const int value[]) {
  for (size_t i = 0; i < nvr; i++, vr++, value++) {
    // access variables and aliases in SimVars memory
    if (*vr < _dimBoolean)
      _pointerToBoolVars[*vr] = *value;
    // convert negated aliases
    else switch (*vr) {
      default:
        throw std::invalid_argument("setBoolean with wrong value reference " + omcpp::to_string(*vr));
    }
  }
}
void LimPIDFMU::setString(const unsigned int vr[], size_t nvr, const string value[]) {
  for (size_t i = 0; i < nvr; i++, vr++, value++) {
    // access variables and aliases in SimVars memory
    if (*vr < _dimString)
      _pointerToStringVars[*vr] = *value;
    // convert negated aliases
    else switch (*vr) {
      default:
        throw std::invalid_argument("setString with wrong value reference " + omcpp::to_string(*vr));
    }
  }
}

// Jacobian
void LimPIDFMU::getDirectionalDerivative(
    const unsigned int vrUnknown[], size_t nUnknown,
    const unsigned int vrKnown[], size_t nKnown,
    const double dvKnown[], double dvUnknown[])
{
  unsigned int idx, *ref_p, ref_1;
  int dimStates = _dimContinuousStates + 0;
  
  _FMIDERjac_x.clear();
  ref_p = NULL;
  for (size_t j = 0; j < nKnown; j++) {
    idx = vrKnown[j];
    if (idx >= dimStates) {
      // find input reference
      if (ref_p == NULL || idx < ref_1)
        ref_p = _inputRefs; // reset ref_p if vrKnown decreases
      ref_p = std::find(ref_p, _inputRefs + sizeof(_inputRefs)/sizeof(unsigned int), vrKnown[j]);
      ref_1 = idx;
      idx = dimStates + (ref_p - _inputRefs);
    }
    if (idx >= _FMIDERjac_x.size())
      throw std::invalid_argument("getDirectionalDerivative with wrong value reference of known " + omcpp::to_string(vrKnown[j]));
    _FMIDERjac_x(idx) = dvKnown[j];
  }
  calcFMIDERJacobianColumn();
  ref_p = NULL;
  for (size_t i = 0; i < nUnknown; i++) {
    idx = vrUnknown[i] - _dimContinuousStates; // derivatives behind states
    if (idx >= _dimContinuousStates) {
      // find output reference
      if (ref_p == NULL || idx < ref_1)
        ref_p = _outputRefs; // reset ref_p if vrUnknown decreases
      ref_p = std::find(ref_p, _outputRefs + sizeof(_outputRefs)/sizeof(unsigned int), vrUnknown[i]);
      ref_1 = idx;
      idx = _dimContinuousStates + (ref_p - _outputRefs);
    }
    if (idx >= _FMIDERjac_y.size())
      throw std::invalid_argument("getDirectionalDerivative with wrong value reference of unknown " + omcpp::to_string(vrUnknown[i]));
    dvUnknown[i] = _FMIDERjac_y(idx);
  }
}

