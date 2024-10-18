#pragma once

/*****************************************************************************
*
* Simulation code to initialize the Modelica system
*
*****************************************************************************/
class LimPIDStateSelection: public IStateSelection, public LimPIDMixed
{
public:
  LimPIDStateSelection(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects);
  virtual ~LimPIDStateSelection();
  int getDimStateSets() const;
  int getDimStates(unsigned int index) const;
  int getDimCanditates(unsigned int index) const;
  int getDimDummyStates(unsigned int index) const;
  void getStates(unsigned int index,double* z);
  void setStates(unsigned int index,const double* z);
  void getStateCanditates(unsigned int index,double* z);
  bool getAMatrix(unsigned int index, DynArrayDim2<int>& A);
  void setAMatrix(unsigned int index, DynArrayDim2<int>& A);
  bool getAMatrix(unsigned int index, DynArrayDim1<int>& A);
  void setAMatrix(unsigned int index, DynArrayDim1<int>& A);
  
protected:
  void initialize();
};