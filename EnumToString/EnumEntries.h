#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>

template<typename T>
class enum_entry
{
public:
	typedef std::map<int, std::string> container;
	typedef typename container::const_iterator const_iterator;
	typedef typename container::value_type value_type;

	static const_iterator begin()
    {
        if(s_allEntries == NULL)
		{
            s_allEntries = new container();
		}

		return s_allEntries->begin();
    }

	static const_iterator end()
    {
        if(s_allEntries == NULL)
		{
            s_allEntries = new container();
		}

		return s_allEntries->end();
    }

	static int Value(const_iterator& it)
	{
		return it->first;
	}

	static std::string Name(const_iterator& it)
	{
		return it->second;
	}

    explicit enum_entry(std::string name, int value = s_start)
		: m_name(name)
		, m_value(value)
    {
        s_start = m_value + 1;

        if(s_allEntries == NULL)
		{
            s_allEntries = new container();
		}

		s_allEntries->insert(std::make_pair(m_value, m_name));
    }

	~enum_entry()
	{
	}

	int Value() const
	{
		return m_value;
	}

	const std::string& Name() const
	{
		return m_name;
	}

	operator int()
	{
		return this->Value();
	}

private:
    static int s_start;
    static container* s_allEntries;

	enum_entry();

    const std::string m_name;
    const int m_value;
};

template<typename T>
int enum_entry<T>::s_start = 0;

template<typename T>
typename enum_entry<T>::container* enum_entry<T>::s_allEntries(NULL);

template<typename T>
std::ostream& operator<<(std::ostream& os, const enum_entry<T>& e)
{
	os << e.Name();
	return os;
}

#define NAMED_ENUM(name) class name##_enum_impl {}; typedef enum_entry<name##_enum_impl> name; name

#define ENTRY(e) e(#e)
#define ENTRY_NAME(e, name) e(name)
#define ENTRY_VALUE(e, value) e(#e, value)
#define ENTRY_NAME_VALUE(e, name, value) e(name, value)

/*
#define NEW_ENTRY(typ, e) const typ e(#e);
#define NEW_ENTRY_NAME(typ, e, name) const typ e(name);
#define NEW_ENTRY_VALUE(typ, e, value) const typ e(#e, value);
#define NEW_ENTRY_NAME_VALUE(typ, e, name, value) const typ e(name, value);
*/