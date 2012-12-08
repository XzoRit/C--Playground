// VexingParseProblem.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

struct T
{
	T()
	: i(2)
	{}

	int i;
};

struct U
{
	U(T t)
	: i(t.i)
	{}

	int i;
};

int _tmain(int argc, _TCHAR* argv[])
{
	// U v(T()); // Funktionsdeklaration
	// U v( T(*)() ); // Funktionsdeklaration explizit
	// typedef T (*funcPtr)(); // Funktionsdeklaration explizit mit typedef
	// U v(funcPtr);
	U v( (T()) ); // Initialisierung mit temporärer Variablen
	U w = T(); // Initialisierung explizit

	std::cout << v.i << std::endl;
	std::cout << w.i << std::endl;

	return 0;
}

