// declaration for Cpp FMU target

class LimPIDFMU: public LimPIDInitialize {
 public:
  // constructor
  LimPIDFMU(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects);
  
  // initialization
  virtual void initialize();
  
  // getters for given value references
  virtual void getReal(const unsigned int vr[], size_t nvr, double value[]);
  virtual void getInteger(const unsigned int vr[], size_t nvr, int value[]);
  virtual void getBoolean(const unsigned int vr[], size_t nvr, int value[]);
  virtual void getString(const unsigned int vr[], size_t nvr, string value[]);
  
  // setters for given value references
  virtual void setReal(const unsigned int vr[], size_t nvr, const double value[]);
  virtual void setInteger(const unsigned int vr[], size_t nvr, const int value[]);
  virtual void setBoolean(const unsigned int vr[], size_t nvr, const int value[]);
  virtual void setString(const unsigned int vr[], size_t nvr, const string value[]);
  
  // Jacobian
  void getDirectionalDerivative(const unsigned int vrUnknown[], size_t nUnknown,
                                const unsigned int vrKnown[], size_t nKnown,
                                const double dvKnown[], double dvUnknown[]);
  
 protected:
  static unsigned int _inputRefs[];  ///< Value references of input variables
  static unsigned int _outputRefs[]; ///< Value references of discrete states and outputs
};

/// create instance of LimPIDFMU
static LimPIDFMU *createSystemFMU(IGlobalSettings *globalSettings);