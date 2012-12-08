#ifndef ANY_H
#define ANY_H

#include <typeinfo>
#include <algorithm>

class Any
{
public:

    Any(const Any& other)
      : m_content(other.m_content ? other.m_content->clone() : 0)
    {
    }

	template<typename T>
	Any(const T& value)
		: m_content(new Holder<T>(value))
	{
	}

	~Any()
	{
		delete m_content;
		m_content = 0;
	}

    Any& swap(Any& rhs)
    {
        std::swap(m_content, rhs.m_content);
        return *this;
    }

    template<typename T>
    Any& operator=(const T& rhs)
    {
        Any(rhs).swap(*this);
        return *this;
    }

    Any& operator=(Any rhs)
    {
        rhs.swap(*this);
        return *this;
    }

	const std::type_info& type() const
	{
		return m_content ? m_content->type() : typeid(void);
	}

	public:

	class Placeholder
	{
	public:
		
		Placeholder()
		{
		}

		virtual ~Placeholder()
		{
		}

		virtual const std::type_info& type() const = 0;
		virtual Placeholder* clone() const = 0;

	private:

		Placeholder(const Placeholder&);
		Placeholder& operator= (const Placeholder&);
	};

	template<typename T>
	class Holder : public Placeholder
	{
	public:

		Holder(const T& value)
			: Placeholder()
			, m_held(value)
		{
		}

		virtual const std::type_info& type() const
		{
			return typeid(T);
		}

		virtual Placeholder* clone() const
		{
			return new Holder(m_held);
		}

	private:

		Holder();
		Holder(const Holder&);
		Holder& operator= (const Holder&);

	public:

		T m_held;
	};

private:

	Any();

public:

	Placeholder* m_content;
};

template<typename T>
T * any_cast(Any * operand)
{
    return operand && 
        operand->type() == typeid(T)
        ? &static_cast<Any::Holder<T> *>(operand->m_content)->m_held
        : 0;
}

template<typename T>
const T* any_cast(const Any* operand)
{
    return any_cast<T>(const_cast<Any*>(operand));
}

#endif