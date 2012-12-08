// CompileTimeChecker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using std::cout;

#define COMPILE_TIME_CHECK(expr, msg) \
{ char COMPILE_TIME_ERROR_##msg[(expr) ? 1 : 0]; }

template<int> struct CompileTimeChecker;
template<> struct CompileTimeChecker<true> {};

#define S14PIEXT_STATIC_ASSERT(expr, msg) \
{ CompileTimeChecker<(expr) != 0> COMPILE_TIME_ERROR_##msg; static_cast<void>(COMPILE_TIME_ERROR_##msg); }

typedef enum Constant_e
{
	Eleven = 11,
	Ten = 10
} Constant;

int _tmain(int argc, _TCHAR* argv[])
{
	S14PIEXT_STATIC_ASSERT(Ten < Eleven, TenIsGreaterThanEleven);
	COMPILE_TIME_CHECK(sizeof(int) == sizeof(long), IntUnequalToLong);

	return 0;
}

