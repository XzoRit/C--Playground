// EnumToString.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Number.h"
#include <iostream>

void printCypherByConstRef(const Number::Cypher& cypher)
{
	std::cout << cypher.Name() << std::endl;
}

void printCypherByValue(Number::Cypher cypher)
{
	if(cypher == Number::One)
	{
		std::cout << "detected one" << std::endl;
	}
	else if(cypher == Number::Two)
	{
		std::cout << "detected two" << std::endl;
	}
	else
	{
		std::cout << "Not parsed: " << cypher << std::endl;
	}
}

void printCypherAsInt(int cypher)
{
	std::cout << cypher << std::endl;
}

typedef enum e_Enum
{
	Val1,
	Val2
} t_Enum;

void printT_Enum(t_Enum e)
{
	std::cout << e << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Number::Cypher c1 = Number::One;
	Number::Cypher c2 = Number::Two;
	Number::Cypher c3 = Number::Three;
	Number::Cypher c5 = Number::Five;

    std::cout << c1.Value() << " " << c2.Value() << " " << c3.Value() << " " << c5.Value() << std::endl;
    std::cout << c1 << " " << c2 << " " << c3 << " " << c5 << std::endl;

	for(
		Number::Cypher::const_iterator i(Number::Cypher::begin());
		i != Number::Cypher::end();
		++i)
	{
		std::cout << Number::Cypher::Value(i) << ": " << Number::Cypher::Name(i) << std::endl;
	}

	printCypherByConstRef(Number::One);
	printCypherByConstRef(c1);

	printCypherByValue(Number::One);
	printCypherByValue(c1);
	printCypherByValue(c5);

	int i = Number::Five;
	std::cout << i << std::endl;

	printCypherAsInt(Number::Three);
	printCypherAsInt(c2);

	/* Dieser Block soll nicht kompilieren */
	//c1 = 987;
	//c1.Value() = 48;
	//c1.Name() = "sakshj";
	//printCypherByValue(8);
	//printCypherByConstRef(8);

	printT_Enum(Val1);
	int j = Val2;
	//printT_Enum(1);

	return 0;
}

