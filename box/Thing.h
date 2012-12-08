#ifndef THING_H
#define THING_H

#include "TypeIdBase.h"

template<typename TypeIdentifer>
class Thing
{
public:

	Thing()
		: m_content(0)
		, m_typeIdentifier()
	{
	}

    Thing(const Thing& other)
      : m_content(other.m_content ? other.m_content->clone() : 0)
	  , m_typeIdentifier(other.m_typeIdentifier)
    {
    }

	template<typename T>
	Thing(const T& value)
		: m_content(0)
		, m_typeIdentifier()
	{
		//m_content = new Holder<T>(value, TypeIdentifer::identifyType(value));
		m_content = new Holder<T>(value, m_typeIdentifier.getTypeId(value));
	}

	~Thing()
	{
		delete m_content;
		m_content = 0;
	}

    Thing& swap(Thing& rhs)
    {
        std::swap(m_content, rhs.m_content);
        return *this;
    }

    template<typename T>
    Thing& operator=(const T& rhs)
    {
        Thing(rhs).swap(*this);
        return *this;
    }

    Thing& operator=(Thing rhs)
    {
        rhs.swap(*this);
        return *this;
    }

	int type() const
	{
		if(m_content)
		{
			return m_content->type();
		}
		else
		{
			return TypeIdBase::TypeNotFound;
		}
	}

	template<typename T>
	T* get() const
	{
		//int typeId = TypeIdentifer::identifyType(T());
		int typeId = m_typeIdentifier.getTypeId(T());

		if(typeId == TypeIdentifer::TypeNotFound)
		{
			return 0;
		}
		else if(typeId == m_content->type())
		{
			return &((static_cast<Thing::Holder<T> *>(m_content))->m_held);
		}
		else
		{
			return 0;
		}
	}

private:

	class Placeholder
	{
	public:
		
		Placeholder()
		{
		}

		virtual ~Placeholder()
		{
		}

		virtual const int type() const = 0;
		virtual Placeholder* clone() const = 0;

	private:

		Placeholder(const Placeholder&);
		Placeholder& operator= (const Placeholder&);
	};

private:

	template<typename T>
	class Holder : public Placeholder
	{
	public:

		Holder(const T& value, int id)
			: Placeholder()
			, m_held(value)
			, Id(id)
		{
		}

		virtual const int type() const
		{
			return Id;
		}

		virtual Placeholder* clone() const
		{
			return new Holder(m_held, Id);
		}

	private:

		Holder();
		Holder(const Holder&);
		Holder& operator= (const Holder&);

		const int Id;

	public:

		T m_held;
	};

private:
	Placeholder* m_content;

private:

	TypeIdentifer m_typeIdentifier;
};

#endif