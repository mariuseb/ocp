void LimPIDInitialize::initializeParameterVars_0()
{
   SystemDefaultImplementation::setRealStartValue(_PI_P_Dzero_P_k_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_k_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_y_reset_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_y_start_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_Nd_, 10.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_Ni_, 2.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_P_P_k_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_Td_, 0.1);
   SystemDefaultImplementation::setRealStartValue(_PI_P_Ti_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addI_P_k1_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addI_P_k2_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addI_P_k3_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addP_P_k1_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addP_P_k2_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addPID_P_k1_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addPID_P_k2_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addPID_P_k3_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addSat_P_k1_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addSat_P_k2_, -1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_gainPID_P_k_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_gainTrack_P_k_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_k_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_limiter_P_uMax_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_limiter_P_uMin_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_revAct_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_wd_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_wp_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_xd_start_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_xi_start_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_yMax_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_yMin_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_y_reset_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_y_start_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_gain_P_k_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_gain1_P_k_, 1.0);
   SystemDefaultImplementation::setRealStartValue(_ki_, 900.0);
   SystemDefaultImplementation::setRealStartValue(_kp_, 0.1);
}

void LimPIDInitialize::initializeParameterVars()
{
  LimPIDInitialize::initializeParameterVars_0();
}
void LimPIDInitialize::initializeIntParameterVars_0()
{
   SystemDefaultImplementation::setIntStartValue(_PI_P_I_P_initType_, 3);
   SystemDefaultImplementation::setIntStartValue(_PI_P_I_P_reset_, 1);
   SystemDefaultImplementation::setIntStartValue(_PI_P_controllerType_, 2);
   SystemDefaultImplementation::setIntStartValue(_PI_P_initType_, 5);
   SystemDefaultImplementation::setIntStartValue(_PI_P_reset_, 1);
}

void LimPIDInitialize::initializeIntParameterVars()
{
  LimPIDInitialize::initializeIntParameterVars_0();
}
void LimPIDInitialize::initializeBoolParameterVars_0()
{
   SystemDefaultImplementation::setBoolStartValue(_PI_P_limiter_P_limitsAtInit_, true);
   SystemDefaultImplementation::setBoolStartValue(_PI_P_limiter_P_strict_, true);
   SystemDefaultImplementation::setBoolStartValue(_PI_P_reverseActing_, true);
   SystemDefaultImplementation::setBoolStartValue(_PI_P_strict_, true);
   SystemDefaultImplementation::setBoolStartValue(_PI_P_with_D_, false);
   SystemDefaultImplementation::setBoolStartValue(_PI_P_with_I_, true);
}

void LimPIDInitialize::initializeBoolParameterVars()
{
  LimPIDInitialize::initializeBoolParameterVars_0();
}

void LimPIDInitialize::initializeStringParameterVars()
{
}