// ImplicitConversion.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

struct AnyClass
{
	typedef enum
	{
		Val1,
		Val2
	} EnumType;

	struct Value
	{
		explicit Value(int val)
			: Val(val)
		{
		}

		int Val;
	};

	void anyMethod(short i)
	{
		std::cout << i << std::endl;
	}


	void anotherMethod(int i, float f)
	{
		std::cout << i << ' ' << f << std::endl;
	}

/*
	void anyMethod(Value v)
	{
		std::cout << v.Val << std::endl;
	}
*/
/*
	void anyMethod(short i)
	{
		std::cout << i << std::endl;
	}
*/
/*
	void anyMethod(float i)
	{
		std::cout << i << std::endl;
	}
*/
/*
	void anyMethod(EnumType i)
	{
		std::cout << i << std::endl;
	}
*/

	template<class T>
	void anyMethod(T t)
	{
		keine implizite Konvertierung erlaubt
	}

	template<class T, class U>
	void anotherMethod(T t, U u)
	{
		keine implizite Konvertierung erlaubt
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	AnyClass c1;

	short s = 234;

	c1.anyMethod(s);
	//c1.anyMethod(1);
	//c1.anyMethod(AnyClass::Value(2));
	//c1.anyMethod(AnyClass::Value(46.9f));
	//c1.anyMethod(46.9f);
	//c1.anyMethod(39u);
	//c1.anyMethod(AnyClass::Val1);
	//c1.anyMethod(true);

	c1.anotherMethod(2, 2.5f);
	//c1.anotherMethod(3.5f, 3);
	//c1.anotherMethod(3.5f, 3.0f);
	//c1.anotherMethod(3, 3);

	return 0;
}

