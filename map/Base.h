#ifndef BASE_H
#define BASE_H

#include <functional>

class Base
{
public:
	typedef enum Id_e
	{
		IdOne = 1,
		IdTwo = 23,
		IdThree = 17,
		IdFour = 93
	} Id;

	typedef std::map<Base::Id, Base*, std::less<Base::Id> > ClassContainer;

	virtual ~Base(){};

	virtual void doSomething() = 0;

	Base::Id getId() { return m_id; }

	class IdComperator : public std::unary_function<ClassContainer::value_type, bool>
	{
	public:
		~IdComperator(){};
		IdComperator(Base::Id id) : m_id(id){};
		IdComperator(const IdComperator& idc)
		{
			m_id = idc.m_id;
		}
		bool operator()(ClassContainer::value_type& b)
		{
			return (b.first == m_id);
		}
	private:
		IdComperator();
		IdComperator& operator=(const IdComperator&);
		Base::Id m_id;
	};
protected:
	Base(Base::Id id) : m_id(id)
	{}

	Base::Id m_id;
private:
	Base(const Base&);
	Base& operator=(const Base&);
};

#endif