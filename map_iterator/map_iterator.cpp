// map_iterator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MapDataIterator.h"
#include <map>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <algorithm>

struct Print
{
  template<typename T>
  void operator()(const T& t) const
  {
    std::cout << t << std::endl;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  typedef std::map<int, std::string> MapType;

  MapType m1;

  for(int i = 0; i < 10; ++i)
  {
    m1.insert(std::make_pair(i, boost::lexical_cast<std::string>(i)));
  }

  for(map_data_iterator_adapter<MapType::iterator> it = make_map_data_iterator_adaptor(m1.begin());
    it != make_map_data_iterator_adaptor(m1.end());
    ++it)
  {
    std::cout << (*it) << std::endl;
  }

  std::for_each(
    make_map_data_iterator_adaptor(m1.begin()),
    make_map_data_iterator_adaptor(m1.end()),
    Print());

	return 0;
}

