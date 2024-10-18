
void LimPIDInitialize::initializeAlgVars_0()
{
   SystemDefaultImplementation::setRealStartValue(_Ki_, 1800.0);
   SystemDefaultImplementation::setRealStartValue(_Kp_, 0.4);
   SystemDefaultImplementation::setRealStartValue(_PI_P_Dzero_P_y_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_u_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_I_P_y_reset_internal_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_P_P_y_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addP_P_y_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addPID_P_y_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_addSat_P_y_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_controlError_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_gainPID_P_y_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_gainTrack_P_y_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_PI_P_y_reset_internal_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_Tmeas_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_Tset_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_u_val_, 0.0);
   SystemDefaultImplementation::setRealStartValue(_u_val1_, 1800.0);
   SystemDefaultImplementation::setRealStartValue(_u_val11_, 0.4);
}

void LimPIDInitialize::initializeAlgVars()
{
  LimPIDInitialize::initializeAlgVars_0();
}

void LimPIDInitialize::initializeDiscreteAlgVars()
{
}


void LimPIDInitialize::initializeIntAlgVars()
{
}

void LimPIDInitialize::initializeBoolAlgVars()
{
    SystemDefaultImplementation::setBoolStartValue(_PI_P_I_P_trigger_internal_, false);
}


void LimPIDInitialize::initializeStringAlgVars()
{
}