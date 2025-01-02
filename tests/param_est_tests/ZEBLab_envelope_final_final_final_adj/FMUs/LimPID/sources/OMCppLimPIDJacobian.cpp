
LimPIDJacobian::LimPIDJacobian(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects)
    : LimPID(globalSettings,simObjects)
    , _AColorOfColumn(NULL)
    , _AMaxColors(0)
    , _AColumnsOfColor(NULL)
    , _ADependenciesOfColumn(NULL)
    , _FMIDERjacobian(ublas::zero_matrix<double>(2,5))
    , _FMIDERjac_y(ublas::zero_vector<double>(2))
    , _FMIDERjac_tmp(ublas::zero_vector<double>(10))
    , _FMIDERjac_x(ublas::zero_vector<double>(5))
    
    
    
    
    
    , _Ajacobian(ublas::zero_matrix<double>(1,1))
    , _Ajac_y(ublas::zero_vector<double>(1))
    , _Ajac_tmp(ublas::zero_vector<double>(0))
    , _Ajac_x(ublas::zero_vector<double>(1))
{
}

LimPIDJacobian::LimPIDJacobian(LimPIDJacobian& instance)
    : LimPID(instance)
    , _AColorOfColumn(NULL)
    , _AMaxColors(0)
    , _AColumnsOfColor(NULL)
    , _ADependenciesOfColumn(NULL)
    , _FMIDERjacobian(ublas::zero_matrix<double>(2,5))
    , _FMIDERjac_y(ublas::zero_vector<double>(2))
    , _FMIDERjac_tmp(ublas::zero_vector<double>(10))
    , _FMIDERjac_x(ublas::zero_vector<double>(5))
    
    
    
    
    
    , _Ajacobian(ublas::zero_matrix<double>(1,1))
    , _Ajac_y(ublas::zero_vector<double>(1))
    , _Ajac_tmp(ublas::zero_vector<double>(0))
    , _Ajac_x(ublas::zero_vector<double>(1))
{
}

LimPIDJacobian::~LimPIDJacobian()
{
  if (_AColorOfColumn)
    delete [] _AColorOfColumn;
  if (_AColumnsOfColor)
    delete [] _AColumnsOfColor;
  if (_ADependenciesOfColumn)
    delete [] _ADependenciesOfColumn;
}


void LimPIDJacobian::calcFMIDERJacobianColumn()
{
  double tmp16;
  double tmp17;
  _FMIDERjac_tmp(2) = ((_PI_P_addP_P_k1_ * _FMIDERjac_x(2)) + (_PI_P_addP_P_k2_ * _FMIDERjac_x(1)));
  _FMIDERjac_tmp(1) = (_PI_P_P_P_k_ * _FMIDERjac_tmp(2));
  _FMIDERjac_tmp(3) = (_FMIDERjac_tmp(1) + _FMIDERjac_x(0));
  _FMIDERjac_tmp(6) = (_PI_P_gainPID_P_k_ * _FMIDERjac_tmp(3));
  if (_PI_P_gainPID_P_y_ > 1.0) {
    tmp17 = 0.0;
  } else {
    if (_PI_P_gainPID_P_y_ < 0.0) {
      tmp16 = 0.0;
    } else {
      tmp16 = _FMIDERjac_tmp(6);
    }
    tmp17 = tmp16;
  }
  _FMIDERjac_y(1) = tmp17;
  _FMIDERjac_tmp(4) = (_FMIDERjac_y(1) - _FMIDERjac_tmp(6));
  _FMIDERjac_tmp(7) = (_PI_P_gainTrack_P_k_ * _FMIDERjac_tmp(4));
  _FMIDERjac_tmp(0) = ((_PI_P_addI_P_k1_ * _FMIDERjac_x(2)) + ((_PI_P_addI_P_k2_ * _FMIDERjac_x(1)) + (_PI_P_addI_P_k3_ * _FMIDERjac_tmp(7))));
  _FMIDERjac_y(0) = (_PI_P_I_P_k_ * _FMIDERjac_tmp(0));
}

matrix_t&  LimPIDJacobian::getFMIDERJacobian()
{
  /*Index 0*/
  _FMIDERjac_x(0) = 1;
  calcFMIDERJacobianColumn();
  _FMIDERjac_x.clear();
  _FMIDERjacobian(0,0) = _FMIDERjac_y(0);
  _FMIDERjacobian(1,0) = _FMIDERjac_y(1);
  SystemLockFreeVariables slfv(this);
  _FMIDERjac_x(1) = 1;
  calcFMIDERJacobianColumn();
  _FMIDERjac_x.clear();
  _FMIDERjacobian(0,1) = _FMIDERjac_y(0);
  _FMIDERjacobian(1,1) = _FMIDERjac_y(1);
  _FMIDERjac_x(2) = 1;
  calcFMIDERJacobianColumn();
  _FMIDERjac_x.clear();
  _FMIDERjacobian(0,2) = _FMIDERjac_y(0);
  _FMIDERjacobian(1,2) = _FMIDERjac_y(1);
  _FMIDERjac_x(3) = 1;
  calcFMIDERJacobianColumn();
  _FMIDERjac_x.clear();

  _FMIDERjac_x(4) = 1;
  calcFMIDERJacobianColumn();
  _FMIDERjac_x.clear();
  return _FMIDERjacobian;
}

void LimPIDJacobian::calcHJacobianColumn()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");

}

matrix_t&  LimPIDJacobian::getHJacobian()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");
}

void LimPIDJacobian::calcFJacobianColumn()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");

}

matrix_t&  LimPIDJacobian::getFJacobian()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");
}

void LimPIDJacobian::calcDJacobianColumn()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");

}

matrix_t&  LimPIDJacobian::getDJacobian()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");
}

void LimPIDJacobian::calcCJacobianColumn()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");

}

matrix_t&  LimPIDJacobian::getCJacobian()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");
}

void LimPIDJacobian::calcBJacobianColumn()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");

}

matrix_t&  LimPIDJacobian::getBJacobian()
{
  throw ModelicaSimulationError(MATH_FUNCTION, "Symbolic jacobians not is activated");
}

void LimPIDJacobian::calcAJacobianColumn()
{
}

matrix_t&  LimPIDJacobian::getAJacobian()
{
  /*Index 6*/
  return _Ajacobian;
}

void LimPIDJacobian::initialize()
{
  //create Algloopsolver for analytical Jacobians

  
}

//testmaessig aus der cruntime
/* Jacobians */


void LimPIDJacobian::initializeColoredJacobianA()
{
  if(_AColorOfColumn)
    delete [] _AColorOfColumn;
  _AColorOfColumn = new int[1];
  _AMaxColors = 1;
  if(_AColumnsOfColor)
    delete [] _AColumnsOfColor;
  _AColumnsOfColor = new std::vector<int>[1];
  if(_ADependenciesOfColumn)
    delete [] _ADependenciesOfColumn;
  _ADependenciesOfColumn = new std::vector<int>[1];
  
  /* write color array (deprecated) */
  _AColorOfColumn[0] = 1;
  
  /* write color to columns mapping */
  _AColumnsOfColor[0] = {0};
  
  /* write dependencies */
  _ADependenciesOfColumn[0] = {0};
}

