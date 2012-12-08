#pragma once

class ClassC;
class ClassB;

class ClassA
{
public:
	ClassA(void);
	~ClassA(void);

	ClassB convertCToB(ClassC c);
};
