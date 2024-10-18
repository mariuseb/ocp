#pragma once

/*****************************************************************************
*
* Simulation code to initialize the Modelica system
*
*****************************************************************************/

class LimPIDInitialize : public ISystemInitialization, public LimPIDWriteOutput
{
 public:
  LimPIDInitialize(IGlobalSettings* globalSettings, shared_ptr<ISimObjects> simObjects);
  LimPIDInitialize(LimPIDInitialize& instance);
  virtual ~LimPIDInitialize();
  virtual bool initial();
  virtual void setInitial(bool);
  virtual void initialize();
  virtual void initializeMemory();
  virtual void initializeFreeVariables();
  virtual void initializeBoundVariables();
  virtual void initParameterEquations();
  virtual void initEquations();
  virtual IMixedSystem* clone();
private:
  FORCE_INLINE void initEquation_1();
  FORCE_INLINE void initEquation_2();
  FORCE_INLINE void initEquation_3();
  FORCE_INLINE void initEquation_4();
  FORCE_INLINE void initEquation_5();
  FORCE_INLINE void initEquation_6();
  FORCE_INLINE void initEquation_7();
  FORCE_INLINE void initEquation_8();
  FORCE_INLINE void initEquation_9();
  FORCE_INLINE void initEquation_10();
  FORCE_INLINE void initEquation_11();
  FORCE_INLINE void initEquation_12();
  FORCE_INLINE void initEquation_13();
  FORCE_INLINE void initEquation_14();
  FORCE_INLINE void initEquation_15();
  FORCE_INLINE void initParameterEquation_26();
  FORCE_INLINE void initParameterEquation_27();
  FORCE_INLINE void initParameterEquation_28();
  FORCE_INLINE void initParameterEquation_29();
  FORCE_INLINE void initParameterEquation_30();
  FORCE_INLINE void initParameterEquation_31();
  FORCE_INLINE void initParameterEquation_32();
  FORCE_INLINE void initParameterEquation_33();
  FORCE_INLINE void initParameterEquation_34();
  FORCE_INLINE void initParameterEquation_35();
  FORCE_INLINE void initParameterEquation_36();
  FORCE_INLINE void initParameterEquation_37();
  FORCE_INLINE void initParameterEquation_38();
  FORCE_INLINE void initParameterEquation_39();
  FORCE_INLINE void initParameterEquation_40();
  FORCE_INLINE void initParameterEquation_41();
  FORCE_INLINE void initParameterEquation_42();
  FORCE_INLINE void initParameterEquation_43();
  FORCE_INLINE void initParameterEquation_44();
  FORCE_INLINE void initParameterEquation_45();
  FORCE_INLINE void initParameterEquation_46();
  FORCE_INLINE void initParameterEquation_47();
  FORCE_INLINE void initParameterEquation_48();
  FORCE_INLINE void initParameterEquation_49();
  FORCE_INLINE void initParameterEquation_50();
  FORCE_INLINE void initParameterEquation_51();
  FORCE_INLINE void initParameterEquation_52();
  FORCE_INLINE void initParameterEquation_53();
  FORCE_INLINE void initParameterEquation_54();
  FORCE_INLINE void initParameterEquation_55();
  FORCE_INLINE void initParameterEquation_56();
  FORCE_INLINE void initParameterEquation_57();
  FORCE_INLINE void initParameterEquation_58();
  FORCE_INLINE void initParameterEquation_59();
  FORCE_INLINE void initParameterEquation_60();
  FORCE_INLINE void initParameterEquation_61();
  FORCE_INLINE void initParameterEquation_62();
  FORCE_INLINE void initParameterEquation_63();
  FORCE_INLINE void initParameterEquation_64();
  FORCE_INLINE void initParameterEquation_65();
  FORCE_INLINE void initParameterEquation_66();
  FORCE_INLINE void initParameterEquation_67();
  FORCE_INLINE void initParameterEquation_68();
  FORCE_INLINE void initParameterEquation_69();
  FORCE_INLINE void initParameterEquation_70();
  FORCE_INLINE void initParameterEquation_71();
  FORCE_INLINE void initParameterEquation_72();
  FORCE_INLINE void initParameterEquation_73();
  FORCE_INLINE void initParameterEquation_74();
  FORCE_INLINE void initParameterEquation_75();
  FORCE_INLINE void initParameterEquation_76();
  FORCE_INLINE void initParameterEquation_77();
  
  void destructExternalObjects();
  bool _constructedExternalObjects;
  void initEquations_0();
  void initParameterEquations_0();
  
  void InitializeDummyTypeElems();
  
  void initializeAlgVars_0();
  
  void initializeAlgVars();
  void initializeDiscreteAlgVars();
  
  
  void initializeIntAlgVars();
  void initializeBoolAlgVars();
  
  
  void initializeStringAlgVars();
  
  void initializeAliasVars_0();
  void initializeStringAliasVars();
  void initializeAliasVars();
  void initializeIntAliasVars();
  void initializeBoolAliasVars();
  
  void initializeParameterVars_0();
  void initializeIntParameterVars_0();
  void initializeBoolParameterVars_0();
  void initializeParameterVars();
  void initializeIntParameterVars();
  void initializeBoolParameterVars();
  void initializeStringParameterVars();
  void initializeStateVars();
  void initializeDerVars();
};