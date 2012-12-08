// vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <functional>

int _tmain(int argc, _TCHAR* argv[])
{
	typedef std::vector<int*> PtrContainer;
    typedef std::vector<int> ValContainer;
	typedef PtrContainer::iterator Iterator;
	typedef PtrContainer::reverse_iterator ReverseIterator;
	typedef PtrContainer::size_type SizeType;

	PtrContainer container;
	std::cout << "size()1" << std::endl;
	std::cout << container.size() << std::endl;
	std::cout << "capacity()1" << std::endl;
	std::cout << container.capacity() << std::endl;

	container.reserve(2);
	std::cout << "size()2" << std::endl;
	std::cout << container.size() << std::endl;
	std::cout << "capacity()2" << std::endl;
	std::cout << container.capacity() << std::endl;

	//container[0] = new int(1);
	//container[1] = new int(2);
	//std::cout << "size()3" << std::endl;
	//std::cout << container.size() << std::endl;

	//std::cout << "Iterator1" << std::endl;
	//for(Iterator it = container.begin();
	//	it != container.end();
	//	it++)
	//{
	//	std::cout << (*(*it)) << std::endl;
	//}

	//std::cout << "[]1" << std::endl;
	//for(SizeType i = 0; i < 2; i++)
	//{
	//	std::cout << (*container[i]) << std::endl;
	//}

	container.push_back(new int(3));
	container.push_back(new int(4));
	std::cout << "size()4" << std::endl;
	std::cout << container.size() << std::endl;

	std::cout << "Iterator2" << std::endl;
	for(Iterator it = container.begin();
		it != container.end();
		it++)
	{
		std::cout << (*(*it)) << std::endl;
	}

	std::cout << "[]2" << std::endl;
	for(SizeType i = 0; i < 2; i++)
	{
		std::cout << (*container[i]) << std::endl;
	}

	std::cout << "delete" << std::endl;
	for(Iterator it = container.begin();
		it != container.end();
		it++)
	{
		delete (*it);
	}
	container.clear();

	std::cout << "size()5" << std::endl;
	std::cout << container.size() << std::endl;
	std::cout << "capacity()6" << std::endl;
	std::cout << container.capacity() << std::endl;

  // shrink-to-fit (swap-trick)
  ValContainer big;
  big.reserve(1000);
  for(int i = 0; i < 1000; ++i)
  {
    big.push_back(i);
  }

  std::cout << "capacity() after fill" << std::endl;
	std::cout << big.capacity() << std::endl;

  big.erase(
    std::remove_if(
      big.begin(),
      big.end(),
      std::bind2nd(
        std::greater<int>(),
        10)),
      big.end());

  std::cout << "capacity() after erase" << std::endl;
	std::cout << big.capacity() << std::endl;

  ValContainer(big.begin(), big.end()).swap(big);

  std::cout << "capacity() after swap-trick" << std::endl;
	std::cout << big.capacity() << std::endl;

	return 0;
}

