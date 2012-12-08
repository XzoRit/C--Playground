// copy_if.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "copy_if.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
struct TypeComperator
{
public:
  TypeComperator(T t)
    : m_t(t)
  {}

  bool operator()(const T& t) const
  {
    return t == m_t;
  }

private:
  T m_t;
};

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
  typedef std::vector<int> ContainerType;

  ContainerType ct1;
  ContainerType ct2;

  for(int i = 0; i < 10; ++i)
  {
    ct1.push_back(i);
    ct1.push_back(5);
  }

  copy_if(
    ct1.begin(),
    ct1.end(),
    std::inserter(
      ct2,
      ct2.begin()),
    TypeComperator<ContainerType::value_type>(5));

  std::for_each(ct2.begin(), ct2.end(), Print());

    return 0;
}