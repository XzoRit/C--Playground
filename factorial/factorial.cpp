// factorial.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

template <int N>
class facotrial
{
public:
	enum
	{
		value = N * facotrial<N - 1>::value
	};
};

template <>
class facotrial<0>
{
public:
	enum
	{
		value = 1
	};
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << facotrial<4>::value << std::endl;

	return 0;
}

