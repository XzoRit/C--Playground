// ContPrinter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <type_traits>
#include <vector>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <map>
#include <forward_list>

using namespace std;

template<typename T>
struct is_container_helper
{
    template<typename U>
    static true_type f(typename U::const_iterator*);

    template<typename U>
    static false_type f(...);

    typedef decltype(f<T>(0)) type;
};

template<typename T>
struct is_container : is_container_helper<T>
{};

template<typename T, size_t N>
struct is_container<T[N]> : true_type
{};

template<typename Char, typename Trait, typename Alloc>
struct is_container<basic_string<Char, Trait, Alloc>> : false_type
{};

struct default_formater
{
    // standard
    template<typename Cont>
    void prefix(ostream& os, Cont const& c) const
    {
        os << "[";
    }

    template<typename Cont>
    void seperator(ostream& os, Cont const& c) const
    {
        os << ", ";
    }

    template<typename Cont>
    void suffix(ostream& os, Cont const& c) const
    {
        os << "]";
    }

    // set
    template<typename T, typename C, typename A>
    void prefix(ostream& os, set<T, C, A> const& c) const
    {
        os << "{";
    }

    template<typename T, typename C, typename A>
    void seperator(ostream& os, set<T, C, A> const& c) const
    {
        os << ", ";
    }

    template<typename T, typename C, typename A>
    void suffix(ostream& os, set<T, C, A> const& c) const
    {
        os << "}";
    }

    // pair
    template<typename T, typename U>
    void prefix(ostream& os, pair<T, U> const& c) const
    {
        os << "(";
    }

    template<typename T, typename U>
    void seperator(ostream& os, pair<T, U> const& c) const
    {
        os << ", ";
    }

    template<typename T, typename U>
    void suffix(ostream& os, pair<T, U> const& c) const
    {
        os << ")";
    }

    // standard
    template<typename Elem>
    void element(ostream& os, Elem const& e) const
    {
        os << e;
    }

    // string
    template<typename Char, typename Trait, typename Alloc>
    void element(ostream& os, basic_string<Char, Trait, Alloc> const& str) const
    {
        os << "\"" << str << "\"";
    }
};

template<typename T, typename Fmt>
void print_container_helper(ostream& os, T const& c, Fmt const& fmt, true_type)
{
    fmt.prefix(os, c);

    auto i = begin(c);
    auto e = end(c);

    if(i != e)
    {
        for(;;)
        {
            print(os, *i, fmt);
            if(++i != e)
            {
                fmt.seperator(os, c);
            }
            else
            {
                break;
            }
        }
    }
    fmt.suffix(os, c);
}

template<typename T, typename Fmt>
void print_container_helper(ostream& os, T const& t, Fmt const& fmt, false_type)
{
    fmt.element(os, t);
}

template<typename T, typename Fmt>
void print(ostream& os, T const& t, Fmt const& fmt)
{
    print_container_helper(os, t, fmt, typename is_container<T>::type());
}

template<typename T, typename U, typename Fmt>
void print(ostream& os, pair<T, U> const& t, Fmt const& fmt)
{
    fmt.prefix(os, t);
    print(os, t.first, fmt);
    fmt.seperator(os, t);
    print(os, t.second, fmt);
    fmt.suffix(os, t);
}

template<typename T>
void print_line(ostream& os, T const& t)
{
    print(os, t, default_formater());
    os << endl;
}

template<typename T, typename Fmt>
void print_line(ostream& os, T const& t, Fmt const& fmt)
{
    print(os, t, fmt);
    os << endl;
}

struct special_formatter
{
    template<typename Cont>
    void prefix(ostream& os, Cont const& c) const
    {
        os << "[" << c.size() << "]{";
    }

    template<typename Cont>
    void seperator(ostream& os, Cont const& c) const
    {
        os << " | ";
    }

    template<typename Cont>
    void suffix(ostream& os, Cont const& c) const
    {
        os << "}";
    }

    // forward_list
    template<typename T, typename Alloc>
    void prefix(ostream& os, forward_list<T, Alloc> const& c) const
    {
        os << '<';
    }

    template<typename T, typename Alloc>
    void seperator(ostream& os, forward_list<T, Alloc> const& c) const
    {
        os << " -> ";
    }

    template<typename T, typename Alloc>
    void suffix(ostream& os, forward_list<T, Alloc> const& c) const
    {
        os << '>';
    }

    // pair
    template<typename T, typename U>
    void prefix(ostream& os, pair<T, U> const& c) const
    {
        os << "(";
    }

    template<typename T, typename U>
    void seperator(ostream& os, pair<T, U> const& c) const
    {
        os << ", ";
    }

    template<typename T, typename U>
    void suffix(ostream& os, pair<T, U> const& c) const
    {
        os << ")";
    }

    // standard
    template<typename Elem>
    void element(ostream& os, Elem const& e) const
    {
        os << e;
    }
};

struct indent_formatter
{
    indent_formatter()
        : m_level(0)
    {}

    template<typename Cont>
    void prefix(ostream& os, Cont const& c) const
    {
        indent(os);
        os << "[\n";
        ++m_level;
    }

    template<typename Cont>
    void seperator(ostream& os, Cont const& c) const
    {
        os << "";
    }

    template<typename Cont>
    void suffix(ostream& os, Cont const& c) const
    {
        --m_level;
        indent(os);
        os << "]\n";
    }

    template<typename Elem>
    void element(ostream& os, Elem const& e) const
    {
        indent(os);
        os << e << "\n";
    }

private:
    mutable unsigned m_level;

    void indent(ostream& os) const
    {
        for(unsigned i = 0; i < m_level; ++i)
        {
            os << " ";
        }
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    cout << "Empty vector: ";
    print_line(cout, vector<int>());

    cout << "Empty    set: ";
    print_line(cout, set<int>());

    cout << "One-element vector: ";
    print_line(cout, vector<int>(1, 1701));

    {
        cout << "One-element    set: ";
        set<int> s;
        s.insert(1729);
        print_line(cout, s);
    }

    {
        cout << "One-element  array: ";
        const int a[] = { 2048 };
        print_line(cout, a);
    }

    {
        cout << "Multi-element vector: ";
        vector<int> v;
        v.push_back(11);
        v.push_back(22);
        v.push_back(33);
        print_line(cout, v);
    }

    {
        cout << "Multi-element    set: ";
        set<int> s;
        s.insert(111);
        s.insert(777);
        s.insert(222);
        s.insert(999);
        print_line(cout, s);
    }

    {
        cout << "Multi-element  array: ";
        const int a[] = { 100, 200, 300, 400, 500 };
        print_line(cout, a);
    }

    cout << "  Two-element   pair: ";
    print_line(cout, make_pair(123, 456));

    cout << "          Empty string: ";
    print_line(cout, string(""));

    cout << "  One-character string: ";
    print_line(cout, string("x"));

    cout << "Multi-character string: ";
    print_line(cout, string("meow"));

    cout << "--" << endl;
    {
        cout << "vector<string>: ";
        vector<string> v;
        v.push_back("cute");
        v.push_back("fluffy");
        v.push_back("kittens");
        print_line(cout, v);
    }

    {
        cout << "vector<vector<int>>: ";
        vector<vector<int>> v;
        for (int i = 0; i < 3; ++i) {
            vector<int> temp;
            for (int j = 0; j < 4; ++j) {
                temp.push_back((i + 1) * 10 + j);
            }
            v.push_back(temp);
        }
        print_line(cout, v);

        cout << "map<string, vector<int>>: ";
        map<string, vector<int>> m;
        m["abc"] = v[0];
        m["def"] = v[1];
        m["ghi"] = v[2];
        print_line(cout, m);
    }

    {
        cout << "Multi-dimensional array: ";
        const int aa[3][5] = {
            { 71, 72, 73, 74, 75 },
            { 81, 82, 83, 84, 85 },
            { 91, 92, 93, 94, 95 }
        };
        print_line(cout, aa);
    }

    cout << endl << "*** special_formatter: ***" << endl;
    {
        vector<set<string>> v(3);
        v[0].insert("the");
        v[0].insert("wrath");
        v[0].insert("of");
        v[0].insert("khan");
        v[1].insert("the");
        v[1].insert("voyage");
        v[1].insert("home");
        v[2].insert("the");
        v[2].insert("undiscovered");
        v[2].insert("country");
        print_line(cout, v, special_formatter());
    }

    {
        set<pair<int, int>> s;
        s.insert(make_pair(11, 22));
        s.insert(make_pair(33, 44));
        s.insert(make_pair(55, 66));
        print_line(cout, s, special_formatter());
    }

    {
        forward_list<int> fl;
        fl.push_front(123);
        fl.push_front(456);
        fl.push_front(789);
        print_line(cout, fl, special_formatter());
    }

    cout << "*** indent_formatter ***" << endl;
    {
        cout << "vector<string>:\n";
        vector<string> v;
        v.push_back("cute");
        v.push_back("fluffy");
        v.push_back("kittens");
        print_line(cout, v, indent_formatter());
    }

    {
        cout << "vector<vector<int>>:\n";
        vector<vector<int>> v;
        for (int i = 0; i < 3; ++i) {
            vector<int> temp;
            for (int j = 0; j < 4; ++j) {
                temp.push_back((i + 1) * 10 + j);
            }
            v.push_back(temp);
        }
        print_line(cout, v, indent_formatter());

        cout << "map<string, vector<int>>:\n";
        map<string, vector<int>> m;
        m["abc"] = v[0];
        m["def"] = v[1];
        m["ghi"] = v[2];
        print_line(cout, m, indent_formatter());
    }

    {
        cout << "Multi-dimensional array:\n";
        const int aa[3][5] = {
            { 71, 72, 73, 74, 75 },
            { 81, 82, 83, 84, 85 },
            { 91, 92, 93, 94, 95 }
        };
        print_line(cout, aa, indent_formatter());
    }

    return 0;
}