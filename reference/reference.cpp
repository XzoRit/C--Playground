// reference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Reference
{
public:
	Reference(const int cref1, const int cref2)
		: Cref1(cref1), Cref2(cref2)
	{}
	~Reference()
	{}

	const int& Cref1;
	const int& Cref2;
private:
	Reference(const Reference& other);
	Reference& operator=(const Reference& other);
};

int _tmain(int argc, _TCHAR* argv[])
{
	Reference ref(1, 2);

	std::cout << "Referenz1: " << ref.Cref1 << std::endl;
	std::cout << "Referenz2: " << ref.Cref2 << std::endl;

	return 0;
}

