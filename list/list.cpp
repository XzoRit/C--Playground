// list.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <list>
#include <map>
#include <iostream>

class A
{
public:
	~A()
	{
		std::cout << "dtor" << std::endl;
	}
private:
	int m_a;
	std::map<int, int*> m_map;
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::list<A>* list = new std::list<A>();

	A a;
	list->push_back(A());
	list->push_back(a);

	//list->clear();
	
	delete list;

	return 0;
}

