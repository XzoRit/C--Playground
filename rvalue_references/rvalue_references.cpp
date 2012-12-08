// rvalue_references.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <boost/move/move.hpp>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <utility>
#include <memory>

using namespace std;

namespace std_ext
{
    template<typename T>
    typename remove_reference<T>::type&&
    move(T&& obj)
    {
        typedef typename remove_reference<T>::type&& ReturnType;
        return static_cast<ReturnType>(obj);
    }
}

struct NameImpl
{
    NameImpl()
    : fname("")
    , sname("")
    {
    }

    NameImpl(string fn, string sn)
    : fname(fn)
    , sname(sn)
    {
    }

    string fname;
    string sname;
};

class Name
{
public:
    ~Name()
    {
        delete m_impl;
        m_impl = nullptr;
    }

    Name()
    : m_impl(new NameImpl())
    {
    }

    Name(string fname, string sname)
    : m_impl(new NameImpl(fname, sname))
    {
    }

    // copy ctor
    Name(Name const& other)
    : m_impl(nullptr)
    {
        //cout << __FUNCTION__ << " Name const& ";
        if(other.m_impl)
            m_impl = new NameImpl(*other.m_impl);
    }
/*
    // copy assignment
    Name& operator=(Name const& other)
    {
        //cout << __FUNCTION__ << " Name const& ";
        Name(other).swap(*this);

        return (*this);
    }
*/
    // move ctor
    Name(Name&& other)
    : m_impl(other.m_impl)
    {
        //cout << __FUNCTION__ << " Name&& ";
        other.m_impl = nullptr;
    }
/*
    // move assignment
    Name& operator=(Name&& other)
    {
        //cout << __FUNCTION__ << " Name&& ";
        Name(move(other)).swap(*this);

        return (*this);
    }
*/

    // unified assignment operator
    Name& operator=(Name other)
    {
        //cout << __FUNCTION__ << " Name ";
        Name(other).swap(*this);

        return (*this);
    }

    void swap(Name& other)
    {
        std::swap(m_impl, other.m_impl);
    }

    string fname() const
    {
        return m_impl->fname;
    }

    string sname() const
    {
        return m_impl->sname;
    }

private:
    NameImpl* m_impl;
};

ostream& operator<<(ostream& os, Name const& n)
{
    //cout << __FUNCTION__ << " Name const& ";
    os << '{' << n.fname() << ", " << n.sname() << '}';
    return os;
}

class Names
{
public:
    typedef vector<Name> NamesCont;
    typedef NamesCont::value_type value_type;

    ~Names(){};

    Names()
    : m_names()
    {
    }

    // copy ctor
    Names(Names const& other)
    : m_names(other.m_names)
    {
        cout << __FUNCTION__ << " Names const& ";
    }

/*
    // copy assignment
    Names& operator=(Names const& other)
    {
        cout << __FUNCTION__ << " Names const& ";
        Names(other).swap(*this);

        return (*this);
    }
*/

    // move ctor
    Names(Names&& other)
    : m_names(move(other.m_names))
    {
        cout << __FUNCTION__ << " Names&& ";
    }

/*
    // move assignment
    Names& operator=(Names&& other)
    {
        cout << __FUNCTION__ << " Names&& ";
        Names(move(other)).swap(*this);

        return (*this);
    }
*/

    // unified assignment operator
    Names& operator=(Names other)
    {
        cout << __FUNCTION__ << " Names ";
        other.swap(*this);

        return (*this);
    }
/*
    // boost.move copy assignment
    Names& operator=(BOOST_COPY_ASSIGN_REF(Names) other)
    {
        cout << __FUNCTION__ << " BOOST_COPY_ASSIGN_REF ";
        Names(other).swap(*this);

        return (*this);
    }

    // boost.move move ctor
    Names(BOOST_RV_REF(Names) other)
    : m_names(boost::move(other.m_names))
    {
        cout << __FUNCTION__ << " BOOST_RV_REF ";
    }

    // boost.move move assignment
    Names& operator=(BOOST_RV_REF(Names) other)
    {
        cout << __FUNCTION__ << " BOOST_RV_REF ";
        Names(boost::move(other)).swap(*this);

        return (*this);
    }
*/
    void swap(Names& other)
    {
        m_names.swap(other.m_names);
    }

    NamesCont& cont()
    {
        return m_names;
    }

private:
    BOOST_COPYABLE_AND_MOVABLE(Names)
    NamesCont m_names;
};

ostream& operator<<(ostream& os, Names& n)
{
    //cout << __FUNCTION__ << " Names const& ";
    for_each(n.cont().begin(), n.cont().end(),
        [&os](Name const& name)
        {
            os << name;
        });

    return os;
}

void printNames(Names names)
{
    cout << __FUNCTION__ << " Names ";
    cout << names;
    cout << '\n';
}
/*
void printNames(Names&& names)
{
    cout << __FUNCTION__ << " Names&& ";
    cout << names;
    cout << '\n';
}

void printNames(Names const&& names)
{
    cout << __FUNCTION__ << " Names const&& ";
    cout << names;
    cout << '\n';
}

void printNames(Names const& names)
{
    cout << __FUNCTION__ << " Names const& ";
    cout << names;
    cout << '\n';
}

void printNames(Names& names)
{
    cout << __FUNCTION__ << " Names& ";
    cout << names;
    cout << '\n';
}
*/
Names getNames()
{
    cout << __FUNCTION__ << " ";
    Names names;
    names.cont().reserve(3);

    names.cont().push_back(Name("a", "b"));
    names.cont().push_back(Name("e", "f"));
    names.cont().push_back(Name("c", "d"));

    return names.cont().empty() ? Names() : names;
}

const Names getConstNames()
{
    return getNames();
}

auto nameComparer =
[](Name const& n1, Name const& n2)
{ return (n1.sname() < n2.sname()); };

Names sortedNames(Names names)
{
    cout << __FUNCTION__ << " Names ";
    cout << "sort starts ";
    sort(names.cont().begin(), names.cont().end(), nameComparer);
    cout << "sort ends ";

    return names;
}

const Names sortedConstNames(Names names)
{
    return sortedNames(names);
}

class Person
{
public:
    ~Person()
    {
    }

    Person()
    : m_name()
    {
    }

    Person(string fname, string sname)
    : m_name(fname, sname)
    {
    }

    Person(Person const& other)
    : m_name(other.m_name)
    {
        cout << __FUNCTION__ << " Person const& ";
    }

    Person& operator=(Person const& other)
    {
        cout << __FUNCTION__ << " Person const& ";
        Person(other).swap(*this);

        return *this;
    }

    Person(Person&& other)
    : m_name(move(other.m_name))
    {
        cout << __FUNCTION__ << " Person&& ";
    }

    Person& operator=(Person&& other)
    {
        cout << __FUNCTION__ << " Person&& ";
        Person(move(other)).swap(*this);

        return *this;
    }

    void swap(Person& other)
    {
        m_name.swap(other.m_name);
    }

    string fname() const
    {
        return m_name.fname();
    }

    string sname() const
    {
        return m_name.sname();
    }

private:
    Name m_name;
};

Name changeFnameTo(Name const& n, string newFname)
{
    return Name(newFname, n.sname());
}

Person changeFnameTo(Person const& p, string newFname)
{
    return Person(newFname, p.sname());
}

int main()
{
    cout << "RVO\n\n";

    Names const n1 = getNames();
    printNames(getNames());
    Names n2 = sortedNames(getNames());

    cout << "\n\n";

    cout << "Names\n\n";

    Names n3 = sortedNames(n1);
    printNames(n3);
    printNames(n2);
    printNames(n1);
    n3 = n2;
    n3 = getNames();

    cout << "\n\n";

    printNames(getNames());
    printNames(sortedNames(getNames()));

    cout << "\n\n";

    printNames(getConstNames());
    printNames(sortedConstNames(getNames()));

    cout << "\n\n";

    Names const n4 = getNames();
    printNames(n4);

    cout << "\n\n";

    Names const& n5 = getNames();
    //n5.push_back("d");
    getNames().cont().push_back(Name("a", "b"));

    cout << "\n\n";

    cout << "Name\n\n";

    Name na1;
    Name na2("John", "Doe");
    na1 = changeFnameTo(na2, "Jane");

    cout << "\n\n";

    cout << "Person\n\n";
    Person p1;
    Person p2("John", "Doe");
    p1 = changeFnameTo(p2, "Jane");

    cout << "\n\n";

    cout << "Names\n\n";
    vector<Names> allNames;
    allNames.reserve(10);
    Names nas1 = getNames();
    Names nas2 = getNames();
    allNames.push_back(move(nas1));
    allNames.push_back(move(nas2));

    cout << "\n\n";

    cout << "Perfect Forwarding\n\n";

    shared_ptr<Name> spn1 = shared_ptr<Name>(new Name("John", "Doe"));
    auto spn2 = make_shared<Name>("John", "Doe");

    cout.flush();

    return 0;
}