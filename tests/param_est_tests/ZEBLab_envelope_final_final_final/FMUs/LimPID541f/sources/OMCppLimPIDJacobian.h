#pragma once

/*****************************************************************************
*
* Simulation code to initialize the Modelica system
*
*****************************************************************************/

class LimPIDJacobian : public LimPID
{
public:
  LimPIDJacobian(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects);
  LimPIDJacobian(LimPIDJacobian& instance);
  virtual ~LimPIDJacobian();
  
protected:
  void initialize();
  
  void calcFMIDERJacobianColumn();
  matrix_t& getFMIDERJacobian();
  
  void calcHJacobianColumn();
  matrix_t& getHJacobian();
  
  void calcFJacobianColumn();
  matrix_t& getFJacobian();
  
  void calcDJacobianColumn();
  matrix_t& getDJacobian();
  
  void calcCJacobianColumn();
  matrix_t& getCJacobian();
  
  void calcBJacobianColumn();
  matrix_t& getBJacobian();
  
  void calcAJacobianColumn();
  matrix_t& getAJacobian();

  matrix_t _FMIDERjacobian;
  ublas::vector<double> _FMIDERjac_y;
  ublas::vector<double> _FMIDERjac_tmp;
  ublas::vector<double> _FMIDERjac_x;


  matrix_t _Hjacobian;
  ublas::vector<double> _Hjac_y;
  ublas::vector<double> _Hjac_tmp;
  ublas::vector<double> _Hjac_x;


  matrix_t _Fjacobian;
  ublas::vector<double> _Fjac_y;
  ublas::vector<double> _Fjac_tmp;
  ublas::vector<double> _Fjac_x;


  matrix_t _Djacobian;
  ublas::vector<double> _Djac_y;
  ublas::vector<double> _Djac_tmp;
  ublas::vector<double> _Djac_x;


  matrix_t _Cjacobian;
  ublas::vector<double> _Cjac_y;
  ublas::vector<double> _Cjac_tmp;
  ublas::vector<double> _Cjac_x;


  matrix_t _Bjacobian;
  ublas::vector<double> _Bjac_y;
  ublas::vector<double> _Bjac_tmp;
  ublas::vector<double> _Bjac_x;


  matrix_t _Ajacobian;
  ublas::vector<double> _Ajac_y;
  ublas::vector<double> _Ajac_tmp;
  ublas::vector<double> _Ajac_x;
  int* _AColorOfColumn;
  int  _AMaxColors;
  std::vector<int>* _AColumnsOfColor;
  std::vector<int>* _ADependenciesOfColumn;

  
  /*testmaessig aus der Cruntime*/
  void initializeColoredJacobianA();
  
};