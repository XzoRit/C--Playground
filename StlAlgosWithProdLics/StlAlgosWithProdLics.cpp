// StlAlgosWithProdLics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include <boost/bind.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>

using namespace std;

class ProductLicense
{
public:
  unsigned short m_number;

  void print() const
  {
    cout << "ProdLic: " << m_number << endl;
  }
};

class ProductLicenseChecker
{
public:
  ProductLicenseChecker() : m_prodLicCache(10)
  {
    int i = m_prodLicCache.size();
    for(ProdLicContainer::iterator it = m_prodLicCache.begin();
      it < m_prodLicCache.end(); it++)
    {
        (*it).m_number = i--;
    }

    m_prodLicCache[7].m_number = 7;
  }

  static bool areProdLicsEqual(ProductLicense pl1, ProductLicense pl2)
  {
    return (pl1.m_number == pl2.m_number);
  }

  class ProdLicSorter
  {
  public:
    bool operator()(const ProductLicense& pl1, const ProductLicense& pl2)
    {
      return (pl1.m_number < pl2.m_number);
    }
  };

  class ProdLicComperator
  {
  public:
    ProdLicComperator(const ProductLicense& prodLic)
      : m_prodLic(prodLic)
    {}

    bool operator()(const ProductLicense& pl1)
    {
      return (pl1.m_number == m_prodLic.m_number);
    }
  private:
    const ProductLicense& m_prodLic;
  };

  class ProdLicPrinter
  {
  public:
    void operator() (const ProductLicense& prodLic)
    {
      prodLic.print();
    }
  };

  void printCache()
  {
    //for_each(m_prodLicCache.begin(), m_prodLicCache.end(), ProdLicPrinter());
    //for_each(m_prodLicCache.begin(), m_prodLicCache.end(),
    //  mem_fun_ref(&ProductLicense::print));
    //for_each(m_prodLicCache.begin(), m_prodLicCache.end(),
    //  boost::bind(&ProductLicense::print, _1));
    //for_each(m_prodLicCache.begin(), m_prodLicCache.end(),
    //    bind(&ProductLicense::print, placeholders::_1));
    boost::for_each(m_prodLicCache,
        bind(&ProductLicense::print, placeholders::_1));
  }

  void printCacheReversed()
  {
    boost::for_each(m_prodLicCache | boost::adaptors::reversed,
        bind(&ProductLicense::print, placeholders::_1));
  }

  void sortProdLics()
  {
    //sort(m_prodLicCache.begin(), m_prodLicCache.end(), ProdLicSorter());
    //sort(m_prodLicCache.begin(), m_prodLicCache.end(),
    //  boost::bind(&ProductLicense::m_number, _1) <
    //  boost::bind(&ProductLicense::m_number, _2));
    boost::sort(m_prodLicCache,
      boost::bind(&ProductLicense::m_number, _1) <
      boost::bind(&ProductLicense::m_number, _2));
    // this does not compile because
    // std::bind has not implemented any operators
    //sort(m_prodLicCache.begin(), m_prodLicCache.end(),
    //  bind(&ProductLicense::m_number, placeholders::_1) <
    //  bind(&ProductLicense::m_number, placeholders::_2));
  }

  bool isProdLicInCache(const ProductLicense& prodLic)
  {
    //return (m_prodLicCache.end() != find_if(m_prodLicCache.begin(), m_prodLicCache.end(),
    //  ProdLicComperator(prodLic)));
    //return (m_prodLicCache.end() != find_if(m_prodLicCache.begin(), m_prodLicCache.end(),
    //  bind1st(ptr_fun(areProdLicsEqual), prodLic)));
    //return (m_prodLicCache.end() != find_if(m_prodLicCache.begin(), m_prodLicCache.end(),
    //  boost::bind(areProdLicsEqual, _1, prodLic)));
    //return (m_prodLicCache.end() != find_if(m_prodLicCache.begin(), m_prodLicCache.end(),
    //  bind(areProdLicsEqual, placeholders::_1, prodLic)));
    return (m_prodLicCache.end() != boost::find_if(m_prodLicCache,
      bind(areProdLicsEqual, placeholders::_1, prodLic)));
  }

private:
  typedef vector<ProductLicense> ProdLicContainer;
  ProdLicContainer m_prodLicCache;
};

int _tmain(int argc, _TCHAR* argv[])
{
  ProductLicenseChecker c;
  ProductLicense p;
  p.m_number = 7;

  cout << "Print Cache\n";
  c.printCache();
  cout << "\n\n";

  cout << "Sort Cache\n";
  c.sortProdLics();
  c.printCache();
  cout << "\n\n";

  cout << "Find License in Cache\n";
  if(c.isProdLicInCache(p)) cout << "Match" << endl;
  else cout << "No Match";
  cout << "\n\n";

  cout << "Cache reversed\n";
  c.printCacheReversed();
  cout << "\n\n";

  cout.flush();
  return 0;
}