#pragma


typedef int (*test_func_t)(int, int);	// It is needed to declare typedef function in this file.

#ifdef __cplusplus
extern "C" {
#endif
	// c++ class wrapper for c
	struct WSTestClass { void *testClass; };
	typedef struct WSTestClass WSTestClass_t;
	// wrapper functions
	WSTestClass_t* createTestClass();
	void releaseTestClass(WSTestClass_t *wsTestClass);
	void setTestClassData(WSTestClass_t *wsTestClass, int i);
	int getTestClassData(WSTestClass_t *wsTestClass);
	void initTestClassCallback(WSTestClass_t *wsTestClass, char *name, test_func_t func);
	int executeTestClassFunc(WSTestClass_t *wsTestClass, int i, int j);
	char* getTestClassCallbackName(WSTestClass_t *wsTestClass);
#ifdef __cplusplus
}
#endif

