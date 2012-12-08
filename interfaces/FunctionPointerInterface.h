#pragma once

class FunctionPointerInterface
{
private:
	typedef void(*VoidVoid)();
	typedef void(*VoidInt)(int);

public:
	VoidVoid m_voidVoid;
	VoidInt m_voidInt;

	void doSomething()
	{
		m_voidVoid();
		m_voidInt(465);
	}
};
