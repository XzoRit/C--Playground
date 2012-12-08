// interfaces.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "FunctionPointerInterface.h"
#include <iostream>
#include <functional>

void a()
{
	std::cout << "a()" << std::endl;
}

void b(int)
{
	std::cout << "b(int)" << std::endl;
}

class Provider
{
public:
	void a()
	{
		std::cout << "Provider::a()" << std::endl;
	}

	void b(int)
	{
		std::cout << "Provider::b()" << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	FunctionPointerInterface fpi;
	fpi.m_voidInt = &b;
	fpi.m_voidVoid = &a;
	fpi.doSomething();

	Provider provider;
	/*fpi.m_voidVoid = */std::bind1st(std::mem_fun_ref(&Provider::a), &provider);

	return 0;
}

