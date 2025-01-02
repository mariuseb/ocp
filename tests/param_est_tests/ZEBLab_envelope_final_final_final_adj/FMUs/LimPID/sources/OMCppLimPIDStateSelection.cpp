
LimPIDStateSelection::LimPIDStateSelection(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects)
    : LimPIDMixed(globalSettings, simObjects)
{
}

LimPIDStateSelection::~LimPIDStateSelection()
{
}

int LimPIDStateSelection::getDimStateSets() const
{
  return 0;
}

int LimPIDStateSelection::getDimStates(unsigned int index) const
{
  return 0;
}

int LimPIDStateSelection::getDimCanditates(unsigned int index) const
{
  return 0;
}

int LimPIDStateSelection::getDimDummyStates(unsigned int index) const
{
  return 0;
}
void LimPIDStateSelection::getStates(unsigned int index, double* z)
{
}

void LimPIDStateSelection::setStates(unsigned int index, const double* z)
{
}

void LimPIDStateSelection::getStateCanditates(unsigned int index, double* z)
{

}

bool LimPIDStateSelection::getAMatrix(unsigned int index, DynArrayDim2<int> & A)
{
  return false;
}

bool LimPIDStateSelection::getAMatrix(unsigned int index, DynArrayDim1<int> & A)
{
  return false;
}

void LimPIDStateSelection::setAMatrix(unsigned int index, DynArrayDim2<int>& A)
{
}

void LimPIDStateSelection::setAMatrix(unsigned int index, DynArrayDim1<int>& A)
{
}

void LimPIDStateSelection::initialize()
{
}