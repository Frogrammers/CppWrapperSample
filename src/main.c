#include "../include/Wrapper.h"
#include <stdio.h>

#define GET_FUNCNAME(func) #func


int add(int i, int j)
{
	return i + j;
}

int sub(int i, int j)
{
	return i - j;
}


int main(int argc, char **argv)
{
    WSTestClass_t *wsTestClass = createTestClass();
    setTestClassData(wsTestClass, 100);

    printf("Get Data: %d\n", getTestClassData(wsTestClass));

	initTestClassCallback(wsTestClass, GET_FUNCNAME(add), (test_func_t)add);
	printf("Execute Func (%s): %d\n", getTestClassCallbackName(wsTestClass), executeTestClassFunc(wsTestClass, 20, 10));

	initTestClassCallback(wsTestClass, GET_FUNCNAME(sub), (test_func_t)sub);
	printf("Execute Func (%s): %d\n", getTestClassCallbackName(wsTestClass), executeTestClassFunc(wsTestClass, 20, 10));

    return 0;
}

