// VirtualVsAbstract.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>

struct A
{
	virtual void setVal(int i) = 0;

	void setChar(char c)
	{
		this->onSetChar(c);
	}
protected:
	virtual ~A() = 0;
private:
	virtual void onSetChar(char c) = 0;
};

A::~A()
{
	std::cout << "dtor A" << std::endl;
}

void A::setVal(int i)
{
	std::cout << i << std::endl;
}

struct B : public A
{
	virtual void setVal(int i)
	{
		A::setVal(i);
	}

private:
	virtual void onSetChar(char c)
	{
		std::cout << c << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	B b1;
	b1.setVal(239);
	b1.A::setVal(98);
	b1.setChar('t');
	A* a1 = &b1;
	a1->setVal(666);
	return 0;
}

