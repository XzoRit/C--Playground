// pointer_ref_pointer.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>

class IBase
{
public:
	virtual ~IBase()
	{}

	virtual void doThis() = 0;
};

class IBase2 : public virtual IBase
{
public:
	virtual ~IBase2()
	{}

	virtual void doThis2() = 0;
};

class Sub : public virtual IBase
{
public:
	Sub(IBase& sub1, IBase& sub2, IBase*& current)
		: m_current(current)
		, m_sub1(sub1)
		, m_sub2(sub2)
	{
	}

	void setCurrent()
	{
		static int counter = 0;

		if(++counter % 2)
		{
			m_current = &m_sub1;
		}
		else
		{
			m_current = &m_sub2;
		}
	}

	virtual void doThis()
	{
		m_current->doThis();
	}

private:
	IBase* m_current;
	IBase& m_sub1;
	IBase& m_sub2;
};

class Sub1 : public IBase2
{
	virtual void doThis()
	{
		std::cout << "Sub1::doThis()" << std::endl;
	}

	virtual void doThis2()
	{
		std::cout << "Sub1::doThis2()" << std::endl;
	}
};

class Sub2 : public IBase2
{
	virtual void doThis()
	{
		std::cout << "Sub2::doThis()" << std::endl;
	}

	virtual void doThis2()
	{
		std::cout << "Sub2::doThis2()" << std::endl;
	}
};

class SubSub : public Sub, public IBase2
{
public:
	SubSub(Sub1& sub1, Sub2& sub2, IBase2*& curr)
		: IBase2()
		, m_current(curr)
		, Sub(sub1, sub2, reinterpret_cast<IBase*&>(curr))
	{}

	virtual void doThis2()
	{
		m_current->doThis2();
	}

private:
	IBase2*& m_current;
};

class Provider
{
public:
	Provider()
		: m_current(&m_sub1)
	{}

	void setCurrent()
	{
		static int counter = 0;

		if(++counter % 2)
		{
			m_current = &m_sub1;
		}
		else
		{
			m_current = &m_sub2;
		}
	}

	IBase* const & Sub()
	{
		return m_current;
	}

private:
	Sub1 m_sub1;
	Sub2 m_sub2;
	IBase* m_current;
};

class Client
{
public:
	Client(Provider& prov)
		: m_sub(prov.Sub())
	{}

	void doThat()
	{
		m_sub->doThis();
		//m_sub++;
	}

private:
	IBase* const & m_sub;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Provider provider;
	Client client(provider);

	for(int i = 0; i < 10; ++i)
	{
		provider.setCurrent();
		client.doThat();
	}
/*
	Sub1 s11;
	Sub2 s22;
	IBase2* current;
	SubSub ss(s11, s22, current);

	for(int i = 0; i < 10; ++i)
	{
		ss.setCurrent();
		ss.doThis();
		ss.doThis2();
	}
*/
	return 0;
}

