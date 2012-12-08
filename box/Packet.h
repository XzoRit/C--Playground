#ifndef PACKET_H
#define PACKET_H

#include <vector>
#include "Thing.h"

class PacketType
{
public:
	PacketType()
	{
	}

	virtual ~PacketType()
	{
	}
};

template<typename TypeIdentifier>
class Packet : public PacketType
{
public:

	typedef std::vector<Thing<TypeIdentifier> > ContainerType;
	typedef typename ContainerType::size_type size_type;
	typedef typename ContainerType::value_type value_type;
	typedef typename ContainerType::iterator iterator;
	typedef typename ContainerType::const_iterator const_iterator;

	Packet()
		: m_container()
	{
	}

	virtual ~Packet()
	{
	}

	iterator begin()
	{
		return m_container.begin();
	}

	iterator end()
	{
		return m_container.end();
	}

	const_iterator begin() const
	{
		return m_container.begin();
	}

	const_iterator end() const
	{
		return m_container.end();
	}

	template<typename T>
	T* get(size_type i)
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
			return (m_container.at(i)).get<T>();
		}
	}

	void push_back(Thing<TypeIdentifier> value)
	{
		m_container.push_back(value);
	}

private:

	Packet(const Packet&);
	Packet& operator=(const Packet&);

	ContainerType m_container;
};

#endif