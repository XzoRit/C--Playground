// MirrorCtors.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

struct A
{
	explicit A(int i)
	: i(i)
	, d(0.0f)
	{}

	explicit A(double d)
	: i(0)
	, d(d)
	{}

	int i;
	double d;
};

struct B : A
{
	explicit B(int i)
	: A(i)
	{}

	explicit B(double d)
	: A(d)
	{}
};

int _tmain(int argc, _TCHAR* argv[])
{
	B b(152);
	B c(1.52f);

	return 0;
}

