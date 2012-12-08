// ParamsOfSameType.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "MinMax.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	MinMax mm1(
		MinMax::Min(12.0f),
		MinMax::Max(20.0f));

	std::cout << std::endl;
	std::cout << mm1.getMin() << std::endl;
	std::cout << mm1.getMax() << std::endl;
	std::cout << std::endl;

	MinMax::InnerType mmit1 = {12.0f, 20.0f};

	MinMax::InnerType mmit2 = {};
	mmit2.Min = 12.0f;
	mmit2.Max = 20.0f;

	MinMax mm2(mmit2);

	std::cout << std::endl;
	std::cout << mm2.getMin() << std::endl;
	std::cout << mm2.getMax() << std::endl;
	std::cout << std::endl;

	// buggy: template-Funktionen können kein float nehmen
	MinMax mm3(createMinMax<12.5f, 20.0f>());

	std::cout << std::endl;
	std::cout << mm3.getMin() << std::endl;
	std::cout << mm3.getMax() << std::endl;
	std::cout << std::endl;

	return 0;
}

