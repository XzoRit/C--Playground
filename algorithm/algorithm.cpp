// algorithm.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <algorithm>
#include <set>
#include <iterator>
#include <iostream>
#include <ostream>

struct Finder
{
	bool operator()(int)
	{

	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	std::set<int> source;
	std::set<int> target;

	for(int i = 0; i < 10; ++i)
	{
		source.insert(i);
	}

	std::copy(
		source.begin(),
		source.end(),
		std::inserter(target, target.begin()));

	std::copy(
		target.begin(),
		target.end(),
		std::ostream_iterator<int>(std::cout, "\n"));

	//source.erase(source.find(243));
	source.erase(42);

	int nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   int* result;
   int start = 0;
   int end = 10;
 
   int targets[] = { 9, 4, 7 };
   result = std::find_first_of( nums + start, nums + end, targets + 0, targets + 3 );
   if( *result == nums[end] ) {
	   std::cout << "Did not find any of { 9, 4, 7 }" << std::endl;
   } else {
	   std::cout << "Found a matching target: " << *result << std::endl;
   }

	return 0;
}

