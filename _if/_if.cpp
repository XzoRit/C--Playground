// _if.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <string>
#include <iostream>

namespace __private
{
    template <typename T, typename U>
    class CompileIfValueTypesAreEqual
    {
        public: CompileIfValueTypesAreEqual(T t1, T t2){}
        private: CompileIfValueTypesAreEqual();
        private: CompileIfValueTypesAreEqual(const CompileIfValueTypesAreEqual&){}
        private: CompileIfValueTypesAreEqual operator=(const CompileIfValueTypesAreEqual&); };
}

template <typename T, typename U>
void is_same_value_type(T t1, U u1)
{
    __private::CompileIfValueTypesAreEqual<T,U> o(t1, u1);
}

#define if(a, op, b) is_same_value_type((a),(b)); if((a) op (b))
//#define ASSERT_SAME_TYPE(a, b) do{ if(0) is_same_value_type((a),(b)); }while(0)

typedef enum eE1
{
    A = 0,
    C
} tE1;

typedef enum eE2
{
    B = 0
} tE2;

tE2 returnB()
{
    return B;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int i = 0;
    int* pi = 0;
    unsigned int ui = 54u;
    bool b = false;
    float f = 1.2f;
    char r = 'R';
    char* c = "HAllo";
    std::string s;

    is_same_value_type(pi, &i);

    //ASSERT_SAME_TYPE(f,b);
    if(i, ==, ui)
    {
        std::cout << true << std::endl;
    }
    else
    {
        std::cout << false << std::endl;
    }
    if(i, ==, b)
    {
        std::cout << true << std::endl;
    }
    else
    {
        std::cout << false << std::endl;
    }
    if(i, ==, f)
    {
        std::cout << true << std::endl;
    }
    else
    {
        std::cout << false << std::endl;
    }
    if(i, ==, r)
    {
        std::cout << true << std::endl;
    }
    else
    {
        std::cout << false << std::endl;
    }
    if(C, ==, A)
    {
        std::cout << true << std::endl;
    }
    else
    {
        std::cout << false << std::endl;
    }
    if(C, !=, A)
    {
        std::cout << true << std::endl;
    }
    else
    {
        std::cout << false << std::endl;
    }
    if(C, >, A)
    {
        std::cout << true << std::endl;
    }
    else
    {
        std::cout << false << std::endl;
    }
    // todo:
    if(C == A, <, B != C)
    {
        std::cout << true << std::endl;
    }
    else
    {
        std::cout << false << std::endl;
    }

    // this block does not compile as it should
    //if(returnB(), ==, A){}
    //if(i, ==, c){}
    //if(i, ==, s){}
    //if(B, ==, A){}
    //if(A, ==, i){}
    //if(pi, ==, i)
    //if(int* pI, =, &i)

    return 0;
}