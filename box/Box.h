#ifndef BOX_H
#define BOX_H

#include "Any.h"
#include <vector>

class Box
{
public:

	typedef std::vector<Any> ContainerType;
	typedef ContainerType::iterator Iterator;

	Box()
		: m_container()
	{
	}

	~Box()
	{
	}

	Iterator begin()
	{
		return m_container.begin();
	}

	Iterator end()
	{
		return m_container.end();
	}

	template<typename T>
	T* get(unsigned int i)
	{
		if(m_container.empty())
		{
			return 0;
		}
		else if(i >= m_container.size())
		{
			return 0;
		}
		else
		{
			return any_cast<T>(&(m_container.at(i)));
		}
	}

	void push_back(Any value)
	{
		m_container.push_back(value);
	}

private:

	Box(const Box&);
	Box& operator=(const Box&);

	ContainerType m_container;
};

#endif