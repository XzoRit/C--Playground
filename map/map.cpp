// map.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <algorithm>
#include <iterator>
#include "Base.h"
#include "Sub1.h"
#include "Sub2.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Base::ClassContainer myCont;
	if(!(myCont.insert(std::make_pair(Base::IdOne, new Sub1(Base::IdOne)))).second)
	{
		std::cout << Base::IdOne << " already inserted" << std::endl;
	}
	myCont[Base::IdTwo] = new Sub1(Base::IdTwo);
	myCont.insert(std::make_pair(Base::IdThree, new Sub2(Base::IdThree)));
	myCont.insert(std::make_pair(Base::IdFour, new Sub2(Base::IdFour)));
	if(!(myCont.insert(std::make_pair(Base::IdOne, new Sub2(Base::IdOne)))).second)
	{
		std::cout << Base::IdOne << " already inserted" << std::endl;
	}

	for(Base::ClassContainer::iterator it = myCont.begin();
		it != myCont.end();
		it++)
	{
		it->second->doSomething();
	}
	
	std::cout << std::endl;
	
	(std::find_if(myCont.begin(), myCont.end(), Base::IdComperator(Base::IdThree)))->second->doSomething();
	
	std::cout << std::endl;
	
	Base::ClassContainer myCont2;
	std::remove_copy_if(
		myCont.begin(),
		myCont.end(),
		std::inserter(myCont2, myCont2.begin()),
		Base::IdComperator(Base::IdThree));
	for(Base::ClassContainer::iterator it = myCont.begin();
		it != myCont.end();
		it++)
	{
		it->second->doSomething();
	}
	for(Base::ClassContainer::iterator it = myCont2.begin();
		it != myCont2.end();
		it++)
	{
		it->second->doSomething();
	}

	return 0;
}

