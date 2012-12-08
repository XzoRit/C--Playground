#include "StdAfx.h"
#include "Addressbook.h"

#include <algorithm>
#include <utility>

Addressbook::Addressbook(void)
    : m_addresses()
{
    Address a1("a", "aa");
    Address a2("c", "cc");
    Address a3("b", "bb");

    m_addresses.push_back(std::move(a1));
    m_addresses.push_back(std::move(a2));
    m_addresses.push_back(std::move(a3));
}

Addressbook::~Addressbook(void)
{
}

std::vector<std::string> Addressbook::get_names() const
{
    std::vector<std::string> names;

    std::for_each(std::begin(m_addresses), std::end(m_addresses),
        [&](Address const& a)
    {
        names.push_back(a.SurName + ", " + a.ForName);
    });

    return names;
}