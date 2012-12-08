// queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <assert.h>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
    std::cout << "Start" << std::endl;

    std::queue<int> Q;
    Q.push(8);
    Q.push(7);
    Q.push(6);
    Q.push(2);

    assert(Q.size() == 4);
    assert(Q.back() == 2);

    assert(Q.front() == 8);
    Q.pop();
    assert(Q.size() == 3);

    assert(Q.front() == 7);
    Q.pop();
    assert(Q.size() == 2);

    assert(Q.front() == 6);
    Q.pop();
    assert(Q.size() == 1);

    assert(Q.front() == 2);
    Q.pop();
    assert(Q.size() == 0);
    assert(Q.empty());

    Q.pop();
    assert(Q.empty());
    assert(Q.size() == 0);

    std::cout << "End" << std::endl;

    return 0;
}