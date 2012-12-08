
#include "ClassA.h"
#include "ClassC.h"
#include "ClassB.h"

int main ()
{
	ClassA a;
	ClassC c;
	ClassB b;

	b = a.convertCToB(c);

	return 0;
}