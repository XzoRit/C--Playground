#include "StdAfx.h"
#include "Address.h"

#include <iostream>

Address::Address(void)
{
}

Address::Address(std::string fname, std::string sname)
    : ForName(fname)
    , SurName(sname)
{
}

Address::Address(Address const& other)
    : ForName(other.ForName)
    , SurName(other.SurName)
{
    std::cout << __FUNCTION__ << '\n';
}

Address& Address::operator=(Address const& other)
{
    std::cout << __FUNCTION__ << '\n';

    Address temp(other);
    this->swap(temp);

    return *this;
}

Address::~Address(void)
{
}

void Address::swap(Address& other)
{
    ForName.swap(other.ForName);
    SurName.swap(other.SurName);
}