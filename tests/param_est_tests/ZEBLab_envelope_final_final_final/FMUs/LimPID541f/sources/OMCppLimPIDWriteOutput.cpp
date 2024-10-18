

LimPIDWriteOutput::LimPIDWriteOutput(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects)
    : LimPIDStateSelection(globalSettings, simObjects)
{



}

LimPIDWriteOutput::LimPIDWriteOutput(LimPIDWriteOutput& instance)
    : LimPIDStateSelection(instance.getGlobalSettings(), instance.getSimObjects())
{

}

LimPIDWriteOutput::~LimPIDWriteOutput()
{

}

IHistory* LimPIDWriteOutput::getHistory()
{
  return _writeOutput.get();
}

void LimPIDWriteOutput::initialize()
{
   if(getGlobalSettings()->getOutputPointType()!= OPT_NONE)
   {
     _writeOutput = getSimObjects()->LoadWriter(18+0+0+1 + 26+0+0 + 2*1).lock();
     _writeOutput->init();
     _writeOutput->clear();
   }
}



 void LimPIDWriteOutput::writeOutput(const IWriteOutput::OUTPUT command)
 {
 
   const output_int_vars_t& outputIntVars = _reader->getIntOutVars();
   const output_real_vars_t& outputRealVars = _reader->getRealOutVars();
   const output_bool_vars_t& outputBoolVars = _reader->getBoolOutVars();
   const output_der_vars_t& outputDerVars = _reader->getDerOutVars();
   const output_res_vars_t& outputResVars = _reader->getResOutVars();
 
  //Write head line
  if (command & IWriteOutput::HEAD_LINE)
  {
    const all_names_t outputVarNames = make_tuple(outputRealVars.outputVarNames,outputIntVars.outputVarNames,outputBoolVars.outputVarNames,outputDerVars.outputVarNames,outputResVars.outputVarNames);
    const all_description_t outputVarDescription = make_tuple(outputRealVars.outputVarDescription,outputIntVars.outputVarDescription,outputBoolVars.outputVarDescription,outputDerVars.outputVarDescription,outputResVars.outputVarDescription);
     const all_names_t parameterVarNames =  make_tuple(outputRealVars.parameterNames,outputIntVars.parameterNames,outputBoolVars.parameterNames,outputDerVars.outputVarNames,outputResVars.outputVarNames);
     const all_description_t parameterVarDescription =  make_tuple(outputRealVars.parameterDescription,outputIntVars.parameterDescription,outputBoolVars.parameterDescription,outputDerVars.outputVarDescription,outputResVars.outputVarDescription);
    _writeOutput->write(outputVarNames,outputVarDescription,parameterVarNames,parameterVarDescription);
    const all_vars_t params = make_tuple(outputRealVars.outputParams,outputIntVars.outputParams,outputBoolVars.outputParams,outputDerVars.outputParams,outputResVars.outputParams);
    _writeOutput->write(params,_global_settings->getStartTime(),_global_settings->getEndTime());
  }
  //Write the current values
   else
  {
      write_data_t& container = _writeOutput->getFreeContainer();
      all_vars_time_t all_vars = make_tuple(outputRealVars.outputVars,outputIntVars.outputVars,outputBoolVars.outputVars,_simTime,outputDerVars.outputVars,outputResVars.outputVars);
      neg_all_vars_t neg_all_vars =      make_tuple(outputRealVars.negateOutputVars,outputIntVars.negateOutputVars,outputBoolVars.negateOutputVars,outputDerVars.negateOutputVars,outputResVars.negateOutputVars);
     _writeOutput->addContainerToWriteQueue(make_tuple(all_vars,neg_all_vars));
  }
 }