#pragma once

// Dummy code for FMU that writes no output file
class LimPIDWriteOutput  : public IWriteOutput,public LimPIDStateSelection
{
 public:
  LimPIDWriteOutput(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects): LimPIDStateSelection(globalSettings, simObjects) {}
  virtual ~LimPIDWriteOutput() {}
  
  virtual void writeOutput(const IWriteOutput::OUTPUT command = IWriteOutput::UNDEF_OUTPUT) {}
  virtual IHistory* getHistory() {return NULL;}
  
 protected:
  void initialize() {}
};