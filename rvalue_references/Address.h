#pragma once

#include <string>

class Address
{
public:
    Address(void);

    Address(std::string fname, std::string sname);

    Address(Address const& other);

    Address& operator=(Address const& other);

    ~Address(void);

    void swap(Address& other);

    std::string ForName;
    std::string SurName;
};