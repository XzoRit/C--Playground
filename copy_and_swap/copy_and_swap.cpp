// copy_and_swap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <algorithm>

struct Legacy
{
    ~Legacy() throw()
    {}

    Legacy() : i(0)
    {}

    Legacy(Legacy const& other)
    {
        this->i = other.i;
        this->v = other.v;
    }

    //Legacy & operator = (Legacy const& other)
    //{
    //    Legacy tmp(other);
    //    tmp.swap(*this);

    //    return (*this);
    //}

    Legacy & operator = (Legacy other)
    {
        this->swap(other);

        return (*this);
    }

    void swap(Legacy& other)
    {
        std::swap(this->i, other.i);
        v.swap(other.v);
    }

    int i;
    std::vector<int> v;
};

void swap(Legacy& l1, Legacy l2)
{
    l1.swap(l2);
}

namespace std
{
    template <>
    void swap(Legacy& l1, Legacy& l2)
    {
        l1.swap(l2);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    int a[] = {0,1,2,3,4,5,6};
    std::vector<Legacy> v = std::vector<Legacy>(10);

    std::partition(std::begin(v), std::end(v),
        [](Legacy const& l)
        {
            return l.i == 5;
        }
    );

    return 0;
}