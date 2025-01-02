
LimPIDInitialize::LimPIDInitialize(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects)
: LimPIDWriteOutput(globalSettings, simObjects)
, _constructedExternalObjects(false)
{
  InitializeDummyTypeElems();
}

LimPIDInitialize::LimPIDInitialize(LimPIDInitialize& instance)
: LimPIDWriteOutput(instance)
{
  InitializeDummyTypeElems();
}

LimPIDInitialize::~LimPIDInitialize()
{
  if (_constructedExternalObjects)
    destructExternalObjects();
}

void LimPIDInitialize::InitializeDummyTypeElems()
{
  //This is necessary to prevent linker errors that occur with GCC 4.4 if a complex type is not used in the code and contains arrays
}

IMixedSystem* LimPIDInitialize::clone()
{
  return new LimPIDInitialize(*this);
}

bool LimPIDInitialize::initial()
{
  return _initial;
}

void LimPIDInitialize::setInitial(bool status)
{
  _initial = status;
  if(_initial)
    _callType = IContinuous::DISCRETE;
  else
    _callType = IContinuous::CONTINUOUS;
}

// convenience function for full initialization
void LimPIDInitialize::initialize()
{
   initializeMemory();
   initializeFreeVariables();
   initializeBoundVariables();
   saveAll();
}

void LimPIDInitialize::initializeMemory()
{
   _discrete_events = _event_handling->initialize(this,getSimVars());

   //create and initialize Algloopsolvers


   LimPIDWriteOutput::initialize();
   LimPIDJacobian::initialize();
   LimPIDJacobian::initializeColoredJacobianA();
}


void LimPIDInitialize::initializeFreeVariables()
{
   #if !defined(FMU_BUILD)
     _reader  = shared_ptr<IPropertyReader>(new XmlPropertyReader(_global_settings, "LimPID_init.xml"));
     _reader->readInitialValues(*this, getSimVars());
   #endif

   _simTime = 0.0;
   _state_var_reinitialized = false;

   /*initialize parameter*/
   initializeParameterVars();
   initializeIntParameterVars();
   initializeBoolParameterVars();
   initializeStringParameterVars();
   initializeAlgVars();
   initializeDiscreteAlgVars();
   initializeIntAlgVars();
   initializeBoolAlgVars();
   initializeStateVars();
   initializeDerVars();

#if defined(__TRICORE__) || defined(__vxworks)
   //init inputs
   stepStarted(0.0);
#endif

   /* Start complex expressions */
   /* End complex expression */
   //checkParameters();
   //delete reader;
}

void LimPIDInitialize::initializeBoundVariables()
{
   //variable decls
   int tmp0;
   
   //destruct external objects if already constructed in a previous call
   if (_constructedExternalObjects)
     destructExternalObjects();
   
   initParameterEquations();
   
   //mark external objects constructed during initParameterEquations
   _constructedExternalObjects = true;
   
   //bound start values
   
   //init event handling
   tmp0 = 0;
   
   //init equations
   initEquations();
   
   for(int i = 0; i < _dimZeroFunc; i++)
   {
      getCondition(i);
   }
   
   //initialAnalyticJacobian();
   
    

   //checkVariables();
}

void LimPIDInitialize::initEquations()
{
   initEquations_0();
}
/*
*/
void LimPIDInitialize::initEquation_1()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_y_reset_internal_, 0.0, false);
}
/*
*/
void LimPIDInitialize::initEquation_2()
{
  SystemDefaultImplementation::setBoolStartValue(_PI_P_I_P_trigger_internal_, false, false);
}
/*
*/
void LimPIDInitialize::initEquation_3()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_y_reset_internal_, 0.0, false);
}
/*
*/
void LimPIDInitialize::initEquation_4()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_Dzero_P_y_, 0.0, false);
}
/*
*/
void LimPIDInitialize::initEquation_5()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addP_P_y_, ((_PI_P_addP_P_k1_ * _Tset_) + (_PI_P_addP_P_k2_ * _Tmeas_)), false);
}
/*
*/
void LimPIDInitialize::initEquation_6()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_P_P_y_, (_PI_P_P_P_k_ * _PI_P_addP_P_y_), false);
}
/*
*/
void LimPIDInitialize::initEquation_7()
{
  SystemDefaultImplementation::setRealStartValue(_kp_, _Kp_, false);
}
/*
*/
void LimPIDInitialize::initEquation_8()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_k_, _kp_, false);
}
/*
*/
void LimPIDInitialize::initEquation_9()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_gainTrack_P_k_, division(1.0,(_PI_P_Ni_ * _PI_P_k_),!_initial,"PI.Ni * PI.k"), false);
}
/*
*/
void LimPIDInitialize::initEquation_10()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_gainPID_P_k_, _PI_P_k_, false);
}
/*
*/
void LimPIDInitialize::initEquation_11()
{
  SystemDefaultImplementation::setRealStartValue(_ki_, _Ki_, false);
}
/*
*/
void LimPIDInitialize::initEquation_12()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_Ti_, _ki_, false);
}
/*
*/
void LimPIDInitialize::initEquation_13()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_k_, division(1.0,_PI_P_Ti_,!_initial,"PI.Ti"), false);
}
/*
*/
void LimPIDInitialize::initEquation_14()
{
  SystemDefaultImplementation::setRealStartValue(__z[0], 0.0, false);
}
/*
*/
void LimPIDInitialize::initEquation_15()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addPID_P_y_, (_PI_P_P_P_y_ + __z[0]), false);
}
/*
*/
void LimPIDInitialize::initEquation_16()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_gainPID_P_y_, (_PI_P_gainPID_P_k_ * _PI_P_addPID_P_y_), false);
}
/*
*/
void LimPIDInitialize::initEquation_17()
{
  double tmp1;
  double tmp2;
  if (_PI_P_gainPID_P_y_ > 1.0) {
    tmp2 = 1.0;
  } else {
    if (_PI_P_gainPID_P_y_ < 0.0) {
      tmp1 = 0.0;
    } else {
      tmp1 = _PI_P_gainPID_P_y_;
    }
    tmp2 = tmp1;
  }
  SystemDefaultImplementation::setRealStartValue(_u_val_, tmp2, false);
}
/*
*/
void LimPIDInitialize::initEquation_18()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addSat_P_y_, (_u_val_ - _PI_P_gainPID_P_y_), false);
}
/*
*/
void LimPIDInitialize::initEquation_19()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_gainTrack_P_y_, (_PI_P_gainTrack_P_k_ * _PI_P_addSat_P_y_), false);
}
/*
*/
void LimPIDInitialize::initEquation_20()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_u_, ((_PI_P_addI_P_k1_ * _Tset_) + ((_PI_P_addI_P_k2_ * _Tmeas_) + (_PI_P_addI_P_k3_ * _PI_P_gainTrack_P_y_))), false);
}
/*
*/
void LimPIDInitialize::initEquation_21()
{
  SystemDefaultImplementation::setRealStartValue(__zDot[0], (_PI_P_I_P_k_ * _PI_P_I_P_u_), false);
}
/*
*/
void LimPIDInitialize::initEquation_22()
{
  SystemDefaultImplementation::setRealStartValue(_u_val11_, (_gain1_P_k_ * _Kp_), false);
}
/*
*/
void LimPIDInitialize::initEquation_23()
{
  SystemDefaultImplementation::setRealStartValue(_u_val1_, (_gain_P_k_ * _Ki_), false);
}
/*
*/
void LimPIDInitialize::initEquation_24()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_controlError_, (_Tset_ - _Tmeas_), false);
}
void LimPIDInitialize::initParameterEquations()
{
   initParameterEquations_0();
}
/*
*/
void LimPIDInitialize::initParameterEquation_37()
{
  SystemDefaultImplementation::setBoolStartValue(_PI_P_limiter_P_limitsAtInit_, true, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_38()
{
  SystemDefaultImplementation::setBoolStartValue(_PI_P_limiter_P_strict_, true, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_39()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_limiter_P_uMin_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_40()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_limiter_P_uMax_, 1.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_41()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addSat_P_k2_, -1.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_42()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addSat_P_k1_, 1.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_43()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addI_P_k3_, 1.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_44()
{
  double tmp3;
  if (_PI_P_reverseActing_) {
    tmp3 = 1.0;
  } else {
    tmp3 = -1.0;
  }
  SystemDefaultImplementation::setRealStartValue(_PI_P_revAct_, tmp3, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_45()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addI_P_k2_, (-_PI_P_revAct_), true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_46()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addI_P_k1_, _PI_P_revAct_, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_47()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_Dzero_P_k_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_48()
{
  SystemDefaultImplementation::setBoolStartValue(_PI_P_with_D_, false, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_49()
{
  SystemDefaultImplementation::setBoolStartValue(_PI_P_with_I_, true, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_50()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addPID_P_k3_, 1.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_51()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addPID_P_k2_, 1.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_52()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addPID_P_k1_, 1.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_53()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_y_reset_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_54()
{
  SystemDefaultImplementation::setIntStartValue(_PI_P_I_P_reset_, 1, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_55()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_y_start_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_56()
{
  SystemDefaultImplementation::setIntStartValue(_PI_P_I_P_initType_, 3, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_57()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addP_P_k2_, (-_PI_P_revAct_), true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_58()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_addP_P_k1_, (_PI_P_revAct_ * _PI_P_wp_), true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_59()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_y_reset_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_60()
{
  SystemDefaultImplementation::setIntStartValue(_PI_P_reset_, 1, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_61()
{
  SystemDefaultImplementation::setBoolStartValue(_PI_P_strict_, true, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_62()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_y_start_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_63()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_xi_start_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_64()
{
  SystemDefaultImplementation::setIntStartValue(_PI_P_initType_, 5, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_65()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_yMin_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_66()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_yMax_, 1.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_67()
{
  SystemDefaultImplementation::setIntStartValue(_PI_P_controllerType_, 2, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_68()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_Dzero_P_y_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_69()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_y_reset_internal_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_70()
{
  SystemDefaultImplementation::setBoolStartValue(_PI_P_I_P_trigger_internal_, false, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_71()
{
  SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_y_reset_internal_, 0.0, true);
}
/*
*/
void LimPIDInitialize::initParameterEquation_72()
{
  string tmp4;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Controls/Continuous/LimPID.mo:26:3-29:92]*/

  if (!(_PI_P_Ni_ >= 1e-13))
  {
    string tmp4 = omcpp::to_string(_PI_P_Ni_);
    LOGGER_WRITE(("Variable violating min constraint: 1e-13 <= PI.Ni, has value: " + tmp4), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
/*
*/
void LimPIDInitialize::initParameterEquation_73()
{
  string tmp5;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Utilities/Math/IntegratorWithReset.mo:18:3-19:31]*/

  if (!((_PI_P_I_P_reset_ >= 1) && (_PI_P_I_P_reset_ <= 3)))
  {
    string tmp5 = omcpp::to_string(_PI_P_I_P_reset_);
    LOGGER_WRITE(("Variable violating min/max constraint: Buildings.Types.Reset.Disabled <= PI.I.reset <= Buildings.Types.Reset.Input, has value: " + tmp5), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
/*
*/
void LimPIDInitialize::initParameterEquation_74()
{
  string tmp6;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Utilities/Math/IntegratorWithReset.mo:10:3-13:38]*/

  if (!((_PI_P_I_P_initType_ >= 1) && (_PI_P_I_P_initType_ <= 4)))
  {
    string tmp6 = omcpp::to_string(_PI_P_I_P_initType_);
    LOGGER_WRITE(("Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= PI.I.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + tmp6), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
/*
*/
void LimPIDInitialize::initParameterEquation_75()
{
  string tmp7;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Controls/Continuous/LimPID.mo:22:3-22:80]*/

  if (!(_PI_P_wp_ >= 0.0))
  {
    string tmp7 = omcpp::to_string(_PI_P_wp_);
    LOGGER_WRITE(("Variable violating min constraint: 0.0 <= PI.wp, has value: " + tmp7), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
/*
*/
void LimPIDInitialize::initParameterEquation_76()
{
  string tmp8;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Controls/Continuous/LimPID.mo:61:3-63:64]*/

  if (!((_PI_P_reset_ >= 1) && (_PI_P_reset_ <= 3)))
  {
    string tmp8 = omcpp::to_string(_PI_P_reset_);
    LOGGER_WRITE(("Variable violating min/max constraint: Buildings.Types.Reset.Disabled <= PI.reset <= Buildings.Types.Reset.Input, has value: " + tmp8), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
/*
*/
void LimPIDInitialize::initParameterEquation_77()
{
  string tmp9;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Controls/Continuous/LimPID.mo:34:3-37:38]*/

  if (!((_PI_P_initType_ >= 1) && (_PI_P_initType_ <= 5)))
  {
    string tmp9 = omcpp::to_string(_PI_P_initType_);
    LOGGER_WRITE(("Variable violating min/max constraint: Modelica.Blocks.Types.InitPID.NoInit <= PI.initType <= Modelica.Blocks.Types.InitPID.DoNotUse_InitialIntegratorState, has value: " + tmp9), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
/*
*/
void LimPIDInitialize::initParameterEquation_78()
{
  string tmp10;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Controls/Continuous/LimPID.mo:30:3-33:94]*/

  if (!(_PI_P_Nd_ >= 1e-13))
  {
    string tmp10 = omcpp::to_string(_PI_P_Nd_);
    LOGGER_WRITE(("Variable violating min constraint: 1e-13 <= PI.Nd, has value: " + tmp10), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
/*
*/
void LimPIDInitialize::initParameterEquation_79()
{
  string tmp11;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Controls/Continuous/LimPID.mo:23:3-25:94]*/

  if (!(_PI_P_wd_ >= 0.0))
  {
    string tmp11 = omcpp::to_string(_PI_P_wd_);
    LOGGER_WRITE(("Variable violating min constraint: 0.0 <= PI.wd, has value: " + tmp11), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
/*
*/
void LimPIDInitialize::initParameterEquation_80()
{
  string tmp12;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Controls/Continuous/LimPID.mo:16:3-19:73]*/

  if (!(_PI_P_Td_ >= 0.0))
  {
    string tmp12 = omcpp::to_string(_PI_P_Td_);
    LOGGER_WRITE(("Variable violating min constraint: 0.0 <= PI.Td, has value: " + tmp12), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
/*
*/
void LimPIDInitialize::initParameterEquation_81()
{
  string tmp13;
  /*#modelicaLine [/home/marius/Desktop/modelica/modelica-buildings/Buildings 8.0.0/Controls/Continuous/LimPID.mo:9:3-10:72]*/

  if (!((_PI_P_controllerType_ >= 1) && (_PI_P_controllerType_ <= 4)))
  {
    string tmp13 = omcpp::to_string(_PI_P_controllerType_);
    LOGGER_WRITE(("Variable violating min/max constraint: Modelica.Blocks.Types.SimpleController.P <= PI.controllerType <= Modelica.Blocks.Types.SimpleController.PID, has value: " + tmp13), LC_MODEL, LL_WARNING);
  }
  /*#endModelicaLine*/
}
void LimPIDInitialize::initializeStateVars()
{
    SystemDefaultImplementation::setRealStartValue(__z[0], 0.0);
}
void LimPIDInitialize::initializeDerVars()
{
    SystemDefaultImplementation::setRealStartValue(__zDot[0], 0.0);
}

void LimPIDInitialize::destructExternalObjects()
{
}


void LimPIDInitialize::initEquations_0()
{
  initEquation_1();
  initEquation_2();
  initEquation_3();
  initEquation_4();
  initEquation_5();
  initEquation_6();
  initEquation_7();
  initEquation_8();
  initEquation_9();
  initEquation_10();
  initEquation_11();
  initEquation_12();
  initEquation_13();
  initEquation_14();
  initEquation_15();
  initEquation_16();
  initEquation_17();
  initEquation_18();
  initEquation_19();
  initEquation_20();
  initEquation_21();
  initEquation_22();
  initEquation_23();
  initEquation_24();
}
void LimPIDInitialize::initParameterEquations_0()
{
  initParameterEquation_37();
  initParameterEquation_38();
  initParameterEquation_39();
  initParameterEquation_40();
  initParameterEquation_41();
  initParameterEquation_42();
  initParameterEquation_43();
  initParameterEquation_44();
  initParameterEquation_45();
  initParameterEquation_46();
  initParameterEquation_47();
  initParameterEquation_48();
  initParameterEquation_49();
  initParameterEquation_50();
  initParameterEquation_51();
  initParameterEquation_52();
  initParameterEquation_53();
  initParameterEquation_54();
  initParameterEquation_55();
  initParameterEquation_56();
  initParameterEquation_57();
  initParameterEquation_58();
  initParameterEquation_59();
  initParameterEquation_60();
  initParameterEquation_61();
  initParameterEquation_62();
  initParameterEquation_63();
  initParameterEquation_64();
  initParameterEquation_65();
  initParameterEquation_66();
  initParameterEquation_67();
  initParameterEquation_68();
  initParameterEquation_69();
  initParameterEquation_70();
  initParameterEquation_71();
  initParameterEquation_72();
  initParameterEquation_73();
  initParameterEquation_74();
  initParameterEquation_75();
  initParameterEquation_76();
  initParameterEquation_77();
  initParameterEquation_78();
  initParameterEquation_79();
  initParameterEquation_80();
  initParameterEquation_81();
}