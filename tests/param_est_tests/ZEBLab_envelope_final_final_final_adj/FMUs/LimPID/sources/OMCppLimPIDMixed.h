#pragma once
/*****************************************************************************
*
* Simulation code
*
*****************************************************************************/
class LimPIDMixed:  public IMixedSystem, public LimPIDJacobian
{
public:
   LimPIDMixed(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects);
   LimPIDMixed(LimPIDMixed &instance);
  virtual ~ LimPIDMixed();
  
  /// Provide Jacobian
  virtual const matrix_t& getJacobian() ;
  virtual const matrix_t& getJacobian(unsigned int index) ;
  virtual sparsematrix_t& getSparseJacobian();
  virtual sparsematrix_t& getSparseJacobian(unsigned int index);
  
  virtual  const matrix_t& getStateSetJacobian(unsigned int index);
  virtual  sparsematrix_t& getStateSetSparseJacobian(unsigned int index);
  /// Called to handle all events occured at same time
  virtual bool handleSystemEvents(bool* events);
  //Saves all variables before an event is handled, is needed for the pre, edge and change operator
  virtual void saveAll();
  virtual void getAlgebraicDAEVars(double* y);
  virtual void setAlgebraicDAEVars(const double* y);
  virtual void getResidual(double* f);
  virtual void evaluateDAE(const UPDATETYPE command = UNDEF_UPDATE);
  
  /// Colored Jacobian
  /*deprecated*/ virtual void getAColorOfColumn(int* aSparsePatternColorCols, int size);
  virtual int  getAMaxColors();
  virtual const vector<int>& getAColumnsOfColor(int color);
  virtual const vector<int>& getADependenciesOfColumn(int idx);
  
  virtual string getModelName();
  virtual bool isJacobianSparse();//true if getSparseJacobian is implemented and getJacobian is not, false if getJacobian is implemented and getSparseJacobian is not.
  virtual bool isAnalyticJacobianGenerated();//true if the flag --generateSymbolicJacobian is true, false if not.
 private:
  // update residual methods
};