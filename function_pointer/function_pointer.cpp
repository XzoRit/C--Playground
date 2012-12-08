// function_pointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

typedef void (*Fun)(const std::string&);

void print(const std::string& s)
{
	std::cout << "print: " << s << std::endl;
}

class Printer1
{
public:
	void print(const std::string& s)
	{
		std::cout << "Printer1::print: " << s << std::endl;
	}
};

typedef void (Printer1::*MemFun)(const std::string&);

class Printer2
{
public:
	void print(const std::string& s)
	{
		std::cout << "Printer2::print: " << s << std::endl;
	}

	void printingToo(const std::string& s)
	{
		std::cout << "Printer2::printingToo: " << s << std::endl;
	}
};

template<typename T> class TempMemFun
{
public:
	typedef void (T::*MemFun)(const std::string&);
};

int _tmain(int argc, _TCHAR* argv[])
{
	Fun f = print;
	std::string s("Hallo");
	const std::string& st = s;
	f(s);

	Printer1 p1;
	MemFun mf = Printer1::print;
	(p1.*mf)(s);

	TempMemFun<Printer1>::MemFun tmf1 = Printer1::print;
	(p1.*tmf1)(s);

	Printer2 p2;
	TempMemFun<Printer2>::MemFun tmf2 = Printer2::print;
	(p2.*tmf2)(s);
	tmf2 = Printer2::printingToo;
	(p2.*tmf2)(s);

	return 0;
}

