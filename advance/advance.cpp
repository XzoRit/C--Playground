// advance.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iterator>
#include <vector>
#include <list>
#include <forward_list>
#include <iostream>

namespace stl_utils
{
    namespace details
    {
        template<typename Iter, typename Distance>
        void advance_impl(Iter& it, Distance n, std::random_access_iterator_tag)
        {
            it += n;
        }

        template<typename Iter, typename Distance>
        void advance_impl(Iter& it, Distance n, std::bidirectional_iterator_tag)
        {
            for (; 0 < n; --n)
                ++it;
            for (; n < 0; ++n)
                --it;
        }

        template<typename Iter, typename Distance>
        void advance_impl(Iter& it, Distance n, std::input_iterator_tag)
        {
            for (; 0 < n; --n)
                ++it;
        }
    }

    
    template<typename Iter, typename Distance>
    void advance(Iter& i, Distance n)
    {
        typedef typename std::iterator_traits<Iter>::iterator_category category;

        details::advance_impl(i, n, category());
    }
    
    
   /* template<typename Iter, typename Distance>
    void advance(Iter& i, Distance n)
    {
        i += n;
    }*/
    
}

int _tmain(int argc, _TCHAR* argv[])
{
    int a[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

    std::cout << "vector\n";
    std::vector<int> v;
    v.assign(a, a + 10);
    std::vector<int>::iterator vb = v.begin();
    std::vector<int>::iterator ve = v.end();
    stl_utils::advance(vb, 5);
    stl_utils::advance(ve, -5);
    std::cout << (*vb) << ' ' << (*ve) << '\n'; // 5 5

    
    std::cout << "list\n";
    std::list<int> l;
    l.assign(v.begin(), v.end());
    std::list<int>::iterator lb = l.begin();
    std::list<int>::iterator le = l.end();
    stl_utils::advance(lb, 5);
    stl_utils::advance(le, -5);
    std::cout << (*lb) << ' ' << (*le) << '\n'; // 5 5
    

	
    std::cout << "forward_list\n";
    std::forward_list<int> f;
    f.assign(v.begin(), v.end());
    std::forward_list<int>::iterator fb = f.begin();
    stl_utils::advance(fb, 5);
    std::cout << (*fb) << '\n'; // 4
    

    
    std::cout << "array\n";
    int* ab = a;
    int* ae = a + 10;
    stl_utils::advance(ab, 5);
    stl_utils::advance(ae, -5);
    std::cout << (*ab) << ' ' << (*ae) << '\n';
    

	
    std::cout << "std::advance with array\n";
    int* stdab = a;
    int* stdae = a + 10;
    std::advance(stdab, 5);
    std::advance(stdae, -5);
    std::cout << (*stdab) << ' ' << (*stdae) << '\n';
    

    std::cout << "vector copy\n";
    std::vector<int> vv(a + 9, a + 19);
    std::copy(v.begin(), v.end(), vv.begin());

    return 0;
}