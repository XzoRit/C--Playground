// ctorImprovements.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

class SomeType
{
public:
	SomeType()
	{}
		
	SomeType(int i, int j) : m_i(i), m_j(j)
	{}
	 
private:
	int m_i;
	int m_j;
};	
	
class SomeType
{
public:
	SomeType(int i, int j) : m_i(i), m_j(j)
	{}

	SomeType(int i) : m_i(i), m_j(0)
	{}
		
	SomeType() : m_i(0), m_j(0)
	{}
};

class SomeType
{	 
public:
	SomeType(int i, int j) : m_i(i), m_j(j)
	{}

	SomeType(int i) : SomeType(i, 0)
	{}
		
	SomeType() : SomeType(0)
	{}
};

class BaseType
{
public:
	BaseType(int value);
};
	 
class DerivedType : public BaseType
{
public:
	using BaseType::BaseType;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

