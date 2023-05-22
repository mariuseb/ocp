/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_H 0
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_F 1
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_D 2
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_C 3
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_B 4
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_INDEX_JAC_A 5
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif

