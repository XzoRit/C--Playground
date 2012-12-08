#pragma once

#include "Address.h"

#include <vector>
#include <string>

class Addressbook
{
public:
    Addressbook(void);
    ~Addressbook(void);

    std::vector<std::string> get_names() const;

private:
    std::vector<Address> m_addresses;
};