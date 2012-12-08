#pragma once

#include <boost/mpl/vector.hpp>
#include <boost/mpl/set_c.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/int.hpp>

#include "CompKeyHolder.h"
#include "Identifier.h"
#include "CommunicationIdentifier.h"
#include "NumericalMeasureIdentifier.h"

template<int id>
struct Group
{
	enum { Id = id };
};

template<typename T1, typename T2>
struct ElemKeys : boost::mpl::vector<T1, T2>
{
	
};

template<
      long C0 = LONG_MAX, long C1 = LONG_MAX, long C2 = LONG_MAX
    , long C3 = LONG_MAX, long C4 = LONG_MAX, long C5 = LONG_MAX
    , long C6 = LONG_MAX, long C7 = LONG_MAX, long C8 = LONG_MAX
    , long C9 = LONG_MAX, long C10 = LONG_MAX, long C11 = LONG_MAX
    , long C12 = LONG_MAX, long C13 = LONG_MAX, long C14 = LONG_MAX
    , long C15 = LONG_MAX, long C16 = LONG_MAX, long C17 = LONG_MAX
    , long C18 = LONG_MAX, long C19 = LONG_MAX
    >
struct NumMeas : boost::mpl::set_c<
	int, C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, C16, C17, C18, C19>
{};

template<
      long C0 = LONG_MAX, long C1 = LONG_MAX, long C2 = LONG_MAX
    , long C3 = LONG_MAX, long C4 = LONG_MAX, long C5 = LONG_MAX
    , long C6 = LONG_MAX, long C7 = LONG_MAX, long C8 = LONG_MAX
    , long C9 = LONG_MAX, long C10 = LONG_MAX, long C11 = LONG_MAX
    , long C12 = LONG_MAX, long C13 = LONG_MAX, long C14 = LONG_MAX
    , long C15 = LONG_MAX, long C16 = LONG_MAX, long C17 = LONG_MAX
    , long C18 = LONG_MAX, long C19 = LONG_MAX
    >
struct Com : boost::mpl::set_c<
	int, C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, C16, C17, C18, C19>
{};


template<typename Component, typename Group, typename ElemKeys>
struct DescriptorTable
	: CompKeyHolder<Component::Kind, Component::Instance>
{
	typedef typename boost::mpl::at_c<ElemKeys, 1>::type ComElemKeys;

	template<int key>
	static
/*		typename boost::mpl::if_<
			boost::mpl::contains<ComElemKeys, boost::mpl::int_<key> >,
*/			Core::CommunicationIdentifier/*,
			void>::type*/ getComId()
	{
		return getComId(key);
	}

	template<int key>
	static Core::NumericalMeasureIdentifier getNumMeasId()
	{
		return getNumMeasId(key);
	}

private:
	static Core::CommunicationIdentifier getComId(int key)
	{
		return Core::CommunicationIdentifier(
			CompKeyHolder::getKey(),
			Group::Id,
			key);
	}

	static Core::NumericalMeasureIdentifier getNumMeasId(int key)
	{
		return Core::NumericalMeasureIdentifier(
			CompKeyHolder::getKey(),
			Group::Id,
			key);
	}
};
