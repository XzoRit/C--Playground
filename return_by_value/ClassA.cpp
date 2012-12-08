
#include "ClassA.h"
#include "ClassB.h"
#include "ClassC.h"

ClassA::ClassA(void)
{
}

ClassA::~ClassA(void)
{
}

ClassB ClassA::convertCToB(ClassC c)
{
	c;
	return ClassB();
}