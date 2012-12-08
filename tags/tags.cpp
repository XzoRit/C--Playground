// tags.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

struct Tag
{
};

struct Hose : Tag
{
};

struct Absorber : Tag
{
};

struct Switch
{
	template<typename T>
	bool enabled(T)
	{
		return this->enabledImpl(T());
	}

private:
	bool enabledImpl(Hose)
	{
		std::cout << "Hose" << std::endl;
		return true;
	}

	bool enabledImpl(Absorber)
	{
		std::cout << "Absorber" << std::endl;
		return true;
	}

	bool enabledImpl(Tag)
	{
		std::cout << "Tag" << std::endl;
		return false;
	}
};

struct Client
{
	Client(Switch& sw)
		: m_switch(sw)
	{}

	void checkHose()
	{
		this->check(Hose());
	}

	void checkAbsorber()
	{
		this->check(Absorber());
	}

	template<typename T>
	void check(T)
	{
		if(m_switch.enabled(T()))
		{
			std::cout << "Enabled" << std::endl;
		}
	}

	Switch& m_switch;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Switch sw;
	Client cl(sw);

	cl.checkHose();
	cl.checkAbsorber();

	return 0;
}

