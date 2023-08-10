/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define Simple2R2CFMU_INDEX_JAC_FMIDERINIT 0
int Simple2R2CFMU_functionJacFMIDERINIT_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Simple2R2CFMU_initialAnalyticJacobianFMIDERINIT(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Simple2R2CFMU_INDEX_JAC_FMIDER 0
int Simple2R2CFMU_functionJacFMIDER_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Simple2R2CFMU_initialAnalyticJacobianFMIDER(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Simple2R2CFMU_INDEX_JAC_H 1
int Simple2R2CFMU_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Simple2R2CFMU_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Simple2R2CFMU_INDEX_JAC_F 2
int Simple2R2CFMU_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Simple2R2CFMU_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Simple2R2CFMU_INDEX_JAC_D 3
int Simple2R2CFMU_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Simple2R2CFMU_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Simple2R2CFMU_INDEX_JAC_C 4
int Simple2R2CFMU_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Simple2R2CFMU_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Simple2R2CFMU_INDEX_JAC_B 5
int Simple2R2CFMU_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Simple2R2CFMU_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define Simple2R2CFMU_INDEX_JAC_A 6
int Simple2R2CFMU_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int Simple2R2CFMU_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif

