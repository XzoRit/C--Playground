#ifndef TYPE_ID_BASE_H
#define TYPE_ID_BASE_H

#include <boost/mpl/find.hpp>
#include <boost/mpl/assert.hpp>

template<typename Derived>
struct TypeIdBase
{
	enum
	{
		TypeNotFound,
		UserTypeId
	};

	template<typename Value>
	static int identifyType(const Value& val)
	{
		typedef boost::mpl::end<Derived::SupportedTypes>::type end;
		typedef boost::mpl::find<Derived::SupportedTypes, Value>::type iterator;

		BOOST_MPL_ASSERT_NOT((boost::is_same<iterator, end>));

		return Derived::typeId(val);
	}
};

#endif
