#include "../include/Wrapper.h"
#include "../include/TestClass.h"
#include <stdlib.h>
#include <stdio.h>


WSTestClass_t* createTestClass()
{
    WSTestClass_t *wsTestClass;
    TestClass *testClass;

    wsTestClass = (WSTestClass_t*)malloc(sizeof(WSTestClass_t));
    testClass = new TestClass();
    wsTestClass->testClass = testClass;

    return wsTestClass;
}

void releaseTestClass(WSTestClass_t *wsTestClass)
{
    if (NULL != wsTestClass)
    {
        delete static_cast<TestClass*>(wsTestClass->testClass);
        free(wsTestClass);
    }
}

void setTestClassData(WSTestClass_t *wsTestClass, int i)
{
    if (NULL != wsTestClass)
    {
        TestClass *testClass;
        testClass = static_cast<TestClass*>(wsTestClass->testClass);
        testClass->SetData(i);
    }
}

int getTestClassData(WSTestClass_t *wsTestClass)
{
    int ret = 0;

    if (NULL != wsTestClass)
    {
        TestClass *testClass;
        testClass = static_cast<TestClass*>(wsTestClass->testClass);
        ret = testClass->GetData();
    }

    return ret;
}

void initTestClassCallback(WSTestClass_t *wsTestClass, char *name, test_func_t func)
{
	TestClass *testClass;
	testClass = static_cast<TestClass*>(wsTestClass->testClass);
	testClass->InitCallback(name, func);
}

int executeTestClassFunc(WSTestClass_t *wsTestClass, int i, int j)
{
	TestClass *testClass;
	testClass = static_cast<TestClass*>(wsTestClass->testClass);
	return testClass->Execute(i, j);
}

char* getTestClassCallbackName(WSTestClass_t *wsTestClass)
{
	TestClass *testClass;
	testClass = static_cast<TestClass*>(wsTestClass->testClass);
	return testClass->GetCallbackName();
}

