#pragma


//typedef int (*test_func_t)(int, int);	// It is NOT needed to declare typedef in this file. Why?

class TestClass {
private:
	int data;
	test_func_t callback;
	char *callback_name;
public:
    TestClass(){};
    ~TestClass(){};
    void SetData(int i)
    {
        data = i;
    };
    int GetData()
    {
        return data;
    };

	void InitCallback(char *name, test_func_t func);
	int Execute(int i, int j);
	char* GetCallbackName(void);
};


void TestClass::InitCallback(char *name, test_func_t func)
{
	callback_name = name;
	callback = func;
}

int TestClass::Execute(int i, int j)
{
	// TO DO

	return (*this->callback)(i, j);
}

char* TestClass::GetCallbackName(void)
{
	return callback_name;
}

